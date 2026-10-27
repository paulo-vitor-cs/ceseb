---
id: 1030
revision: 1
type: document
tags:
- mortgage
- test-plan
- interface
- fixtures
status: versioned
created: '2026-10-26'
updated: '2026-10-26'
description: Contrato físico proposto entre autores dos testes e implementação, com interfaces,
  alvos, ownership e oráculos independentes.
use_when:
- Combinar os arquivos e interfaces consumidos pelos planos 2001 e 2002 sem derivar os resultados
  esperados da implementação.
---
# Interface e fixtures para os dois planos

Autor: dev-test-planning, handle nativo `/root/test_planning`. Workspace de autoria: `/home/paulo/ceseb`. A [aprovação 1028](../1028/r1-revisions-approval-and-planning-authority.md) aceita as quatro specs r2 e autoriza preparar planos. Este documento é input draft dos planos; não cria headers, testes ou código. A narrativa da implementação não define os resultados esperados. Fontes: [1008 r2](../../specs/1008/r2-annual-rate-conversion.md), [1012 r2](../../specs/1012/r2-amortization-comparison.md), [1013 r2](../../specs/1013/r2-widgets-interface.md), [1014 r2](../../specs/1014/r2-reproducible-delivery.md) e os 25 requisitos publicados.

## Arquivos, alvos e ownership

| Responsável futuro | Arquivos e alvos |
|---|---|
| Dev implementação | `include/ceseb/finance.hpp`; `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`; `src/ui/money_codec.hpp/.cpp`, `src/ui/simulation_controller.hpp/.cpp`, `src/ui/main_window.hpp/.cpp`; `src/app/main.cpp`; CMake raiz/presets/dependências e empacotamento |
| Dev testes | `tests/CMakeLists.txt`, `tests/support/financial_fixtures.hpp`, `tests/domain` e `tests/gui` com os arquivos enumerados no plano 2001 e `tests/system/check_core_independence.cmake` |
| Alvos acordados | `ceseb_core` sem Qt; `ceseb_ui` Qt; `ceseb`; `ceseb_domain_tests`; `ceseb_gui_tests` |

As notações de diretório e `.hpp/.cpp` desta tabela resumem ownership; não são operações de plano. Cada plano enumera os endpoints completos, sem globs. O dev implementação não modifica arquivos `tests/` para fazer um caso passar. Defeito de teste volta ao autor com evidência e preservação do oráculo aprovado.

## API C++ proposta

Namespace `ceseb`; header público único `include/ceseb/finance.hpp`. Tipos auxiliares concretos de precisão arbitrária são aliases de Boost 1.86, sem Qt. `Result<T>` é `std::variant<T, Error>`; `Error` contém `ErrorCode code`. Códigos: `InvalidRateKind`, `RateOutOfRange`, `NonFiniteRate`, `PrincipalOutOfRange`, `TermOutOfRange`, `UnsupportedCentPrecision`, `ArithmeticError`. Não existe sucesso parcial na variante de erro.

- `RateKind`: `NominalAnnualMonthlyCapitalization`, `EffectiveAnnual`.
- `AnnualRate { std::optional<RateKind> kind; std::string percent; }`. O texto no core conserva decimal finito canônico com ponto e pode ter sinal para a validação do domínio; não é texto pt-BR. Fixtures especiais `NaN`, `Infinity`, `-Infinity` recebem `NonFiniteRate` antes da criação do racional. A GUI fornece texto válido já convertido, sem sétima casa. Nenhum caminho passa por double.
- `Rational` é o alias de `boost::multiprecision::cpp_rational`; `Decimal` é `cpp_dec_float_50` somente para projeções. `RationalGrowth { Rational factor; }`; `TwelfthRootGrowth { Rational annual_factor; }`.
- `NormalizedRate { AnnualRate original; std::variant<RationalGrowth, TwelfthRootGrowth> growth; }`. O valor exato e a convenção ficam observáveis; não se guarda somente um m aproximado.
- `RateProjection { Decimal effective_monthly_decimal; Decimal nominal_annual_percent; Decimal effective_annual_percent; }`.
- `QuantizedRates { int64_t monthly_percent_millionths; int64_t nominal_annual_percent_millionths; int64_t effective_annual_percent_millionths; }`.
- `LoanInput { int64_t principal_cents; int term_months; AnnualRate rate; }`.
- `ScheduleRow { int period; int64_t opening_balance; int64_t interest; int64_t principal_paid; int64_t payment; int64_t closing_balance; }`.
- `ScheduleSummary { int requested_months; int actual_payments; int64_t first_payment; int64_t last_payment; int64_t ordinary_payment; int64_t principal_total; int64_t interest_total; int64_t payment_total; bool early_payoff; }`. Todos os valores monetários são centavos. `ordinary_payment` pertence à interpretação Price; a UI não o trata como parcela SAC fixa.
- `Schedule { std::vector<ScheduleRow> rows; ScheduleSummary summary; }`.
- `Comparison { NormalizedRate rate; Schedule price; Schedule sac; int64_t interest_difference; }`.

Assinaturas:

```text
Result<NormalizedRate> normalize(const AnnualRate&);
Result<RateProjection> project_rates(const NormalizedRate&);
Result<QuantizedRates> quantize_rates(const NormalizedRate&);
Result<int64_t> quantize_percent(const Rational& percent);
Result<Schedule> calculate_price(int64_t principal_cents, int term_months, const NormalizedRate&);
Result<Schedule> calculate_sac(int64_t principal_cents, int term_months, const NormalizedRate&);
Result<Comparison> compare(const LoanInput&);
```

As funções de livros permitem verificar o módulo isolado com taxa já normalizada. `compare` valida na ordem aprovada e normaliza uma vez. A observação de que a mesma origem segue aos dois modelos combina inspeção da chamada com casos monetários independentes, sem colocar spy no backend financeiro de produção. `quantize_percent` permite a fixture racional isolada do requisito 1212; ela não define política nova.

## Fronteira Qt e observabilidade

Namespace `ceseb::ui`. `MoneyCodec` oferece métodos estáticos `parse_principal(QString) -> Result<int64_t>`, `parse_rate(QString, optional<RateKind>) -> Result<AnnualRate>`, `parse_term(QString) -> Result<int>`, `format_money(int64_t) -> QString` e `format_percent(int64_t millionths) -> QString`.

`CompareFunction` é `std::function<Result<Comparison>(const LoanInput&)>`. `MainWindow(CompareFunction = ceseb::compare)` é o único ponto de substituição para a resposta controlada `ArithmeticError` prevista em 1214. `SimulationController(MainWindow&, CompareFunction)` liga eventos e chama a função selecionada. A execução normal usa o core real. A substituição é exclusiva do teste da fronteira de erro; não substitui o core nos testes financeiros nem fabrica um RED de base.

Object names fixos para `findChild` e observação QtTest:

| Elemento | objectName |
|---|---|
| Principal, taxa, tipo, prazo | `principalInput`, `rateInput`, `rateKindInput`, `termInput` |
| Ações | `calculateButton`, `clearButton`, `aboutButton` |
| Equivalências | `monthlyRateValue`, `nominalAnnualRateValue`, `effectiveAnnualRateValue` |
| Prazo informado | `requestedTermValue` |
| Price | `priceOrdinaryValue`, `priceLastValue`, `pricePaymentsValue`, `priceTotalValue`, `priceInterestValue`, `priceAdjustmentNotice` |
| SAC | `sacFirstValue`, `sacLastValue`, `sacPaymentsValue`, `sacTotalValue`, `sacInterestValue` |
| Diferença e erro | `interestDifferenceValue`, `validationMessage` |
| Rolagem e ajuda | `resultScrollArea`, `aboutDialog`, `modelText`, `versionValue`, `licenseLinks` |
| Labels com buddy | `principalLabel`, `rateLabel`, `rateKindLabel`, `termLabel` |

O teste GUI usa uma classe `GuiContractTests` declarada em `tests/gui/gui_tests.hpp`, com slots `req1211_localized_input`, `req1212_rate_presentation`, `req1213_comparison_presentation` e `req1214_state_recovery`. `tests/gui/gui_test_main.cpp` declara o QTEST_MAIN. Métodos são definidos nos quatro `.cpp` correspondentes. Teclado, escalas e pacote têm demonstrações nativas próprias, mesmo que a automação tenha passado.

## Bootstrap honesto de projeto sem código

O harness `tests/CMakeLists.txt` funciona como subdiretório do projeto e como raiz standalone. No segundo caso recebe `CESEB_SOURCE_ROOT`; inclui o projeto real somente se o CMake raiz/API existirem, com `CESEB_BUILD_TESTS=OFF` para evitar recursão e `CESEB_BUILD_GUI` de acordo com a execução. Ele nunca cria uma biblioteca financeira fictícia. Se faltarem fonte, header ou dependência, retorna diagnóstico e resultado de coleta/ambiente indisponível.

No primeiro retorno de 2001, os arquivos de teste e a tentativa no base são entregues antes de 2002 alterar produto. Ausência de produto no base impede obter RED comportamental e deve ser declarada; não transforma falha de compilação em teste funcional. Após esse retorno, o dev de implementação cria os alvos reais, usa os testes já entregues e devolve o resultado. O dev de testes executa a segunda parte do mesmo plano contra o HEAD de implementação, sem mudar o corpo aprovado nem recalcular fixtures pelo produto.

A autoria e os commits futuros são sequenciais no checkout `/home/paulo/ceseb`, preservando os documentos locais fora de Git. Pode ser criado o ramo local `codex/mortgage-desktop` sob a aprovação do plano. O HEAD observado na autoria é 0bbd2854703444a27ce04600f5e227e0351f61bc; esse hash não é inventado como BASE de execução. Capturar TEST_BASE antes do primeiro arquivo de teste; TEST_ASSETS_HEAD é o commit dos testes antes de produto; IMPLEMENTATION_BASE é o HEAD posterior ao retorno dos testes; IMPLEMENTATION_HEAD é o snapshot observado na verificação final. O commit check de 2001 usa TEST_BASE..TEST_ASSETS_HEAD, sem incluir commits de produto indevidamente. A evidência final relaciona separadamente os testes a IMPLEMENTATION_HEAD.

Para MSVC, o orquestrador aceitou exportar o Git HEAD real para staging em `C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/source`, sem edição autoral ou Git nessa cópia. Registrar SHA de origem, manifesto/hash e `CESEB_SOURCE_REVISION`; nunca derivar uma identidade de commit inexistente no staging. Fontes, planos e commit checks permanecem em MAIN. Apenas build/staging de execução ocorre na área Windows.

Versão de pacote proposta 0.1.0; alvos bin em `/home/paulo/ceseb/build/linux-release/bin` e `C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/windows-release/bin`; saídas `out/packages/ceseb-0.1.0-windows-x86_64.zip` e `out/packages/ceseb_0.1.0_amd64.deb`. ZIP usa `bin/ceseb.exe`; DEB instala `/opt/ceseb/bin/ceseb` com Qt privado. Os procedimentos nativos e inspeções ficam no plano aprovado, sem arquivos de teste artificiais para justificar commits. Seus logs/capturas são evidência operacional separada.

## Oráculos independentes e limites

Os valores esperados vêm dos requisitos publicados e das deduções das specs. A tabela de fixture futura conserva texto decimal, centavos e vetores literais; não usa outputs de `compare` para preencher o esperado. Nominal 12%/100.000 centavos/3, efetiva 12%/mesmos dados, 6 centavos/100%/1, vizinhanças de 6%, Price 3 centavos/zero/2, raiz racional efetiva p=100*((201/200)^12−1) e o empate de percentual são casos discriminantes. O JSON histórico amortization-reference-candidate não é oráculo, pois descreve outro resto SAC.

Segurança no escopo: parsing estrito e limites; ausência de rede/credenciais do produto; inventário das dependências e confronto do aviso CBOR/JSON com APIs reais antes de distribuir. Não se promete auditoria geral. Nenhum teste, benchmark, instalação, pacote ou avaliação nativa foi executado por este documento. Desempenho medido será registrado com alvo, caso e toolchain; não se cria um limiar de aprovação inventado.

Preparação conciliada: o autor de testes tenta o base com o ambiente disponível e retorna os assets mesmo quando a coleta não puder ocorrer por ausência de produto/dependências. Só depois desse retorno I-1221 cria `cmake/AcquireDependencies.cmake`; a aquisição futura usa [2306 r2 proposta](../../tools/2306/r2-qt-dependency-acquisition-and-deployment.md), sem duplicar código de produto nos testes. Os pins/hashes específicos ficam no lock e na evidência de 2002. Os casos finais reutilizam a mesma preparação autorizada.

O staging Windows conserva `/source` imutável; dependências, build e saídas ficam em `C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build` e `/out`. O script de aquisição seleciona Windows qtbase e Linux qtbase+ICU, conforme lock e cartão 2306 r2; qttools foi uma alternativa pesquisada, sem payload selecionado para o projeto.

## Integração de ambientes observados

Após os retornos autorais, o orquestrador observou Ubuntu 26.04 no ROOT e Windows 11 Pro no host. Autoria/Git continuam no ROOT. Verificação Ubuntu 24.04 usa snapshot em `/tmp/ceseb-native-1/source`, com CWD `/tmp/ceseb-native-1`; Windows usa `C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/source`. Build, dependências e outputs ficam nas árvores irmãs, com manifesto e SHA reais. Os planos conciliam os comandos concretos desses alvos; falta de alvo/toolchain é lacuna, sem inferir VM, máquina paga ou qualificação por WSL. Essa integração não altera API, fórmulas, fixtures nem os arquivos autorais dos taskmaps.
