---
id: 2002
revision: 1
type: plan
tags:
- mortgage
- implementation
- requirement-coverage
- cross-platform
status: partial implemented
created: '2026-10-26'
updated: 2026-10-26
description: Plano de implementação de 25 requisitos da calculadora C++/Widgets, fronteiras
  numéricas exatas e pacotes Windows/Linux, posterior ao retorno de testes no base.
use_when:
- Autorizar e executar a implementação do produto após os testes de base, com arquivos, dependências
  e evidência nativa delimitados.
---
# Implementação do produto — 25 requisitos
## Context

Autor e executor pretendido: dev-implementation-planning, handle `/root/implementation_planning`, distinto de `/root/test_planning`. Workspace de autoria e execução canônica proposta: `/home/paulo/ceseb`. Autoridade de preparação: [1028 r1](../../documents/1028/r1-revisions-approval-and-planning-authority.md). Este plano permanece **draft**; aprovação do design não aprova esta execução. A regra normal autor-executor se aplica; não foi invocada a exceção Astra/Sol de outra reconciliação.

A baseline autoral observada é `0bbd2854703444a27ce04600f5e227e0351f61bc`, bootstrap documental. As fontes aprovadas estão locais e fora desse commit. Esse hash não é apresentado como BASE de execução futura. Antes de executar, registrar estado de Git e hashes das revisões aprovadas; ler os status efetivos e a autoridade, preservando todo dirty/untracked anterior. O ROOT permanece o checkout canônico. A preparação de planos não criou ramo, worktree, commit, código ou dependência.

A execução futura é sequencial: autor dos testes conclui assets e tentativa no base, registra o `TEST_ASSETS_HEAD` real e retorna; somente então este autor pode mudar produto. `BASE_IMPL=TEST_ASSETS_HEAD`. O plano de testes pode permanecer aberto para a segunda parte pós-produto, pois pacote, documentação e demonstrações nativas dependem dele. Não há dependência de que 2001 esteja implemented antes de iniciar 2002. Falta de código/header/target no base é indisponibilidade de coleta, nunca RED fabricado. Não se cria core falso, stub temporário ou um teste de ausência só para tornar o base vermelho.

## Goals

Entregar C++20 com conversões nominal/efetiva, Price/SAC e comparação exatos nos centavos; interface pt-BR/BRL Widgets/Fusion; núcleo independente de Qt; ZIP Windows e DEB Ubuntu com runtime privado e documentos rastreáveis. Cada uma das 25 tarefas abaixo possui um único requisito publicado, método e mapa completo de mudanças de fonte. A aprovação pretendida cobre essas mudanças e os efeitos locais explicitados; resultados só serão atribuídos a execuções reais.

## Non-Goals

Não acrescentar QML, framework genérico, threads, rede no app, persistência, exportação ou tabela mensal. Não mudar fórmulas, política monetária, domínio, fixtures ou textos normativos para acomodar implementação. Não editar testes recebidos, fontes de design ou cartões aprovados. Não comprar licença, criar conta/PAT, alterar credenciais, instalar agente/harness, usar serviço pago, fazer push/PR/merge/release ou disparar CI remoto. O workflow é criado como fonte com disparo manual e só roda sob autoridade de efeito posterior. Sem cache/build de Qt modificado ou troca silenciosa do pin.

## Reference-only Inputs

- [Pedido humano original 1001](../../documents/1001/r1-human-request.md), [imagem 1002](../../documents/1002/r1-image-evidence.md) e [aceite 1028](../../documents/1028/r1-revisions-approval-and-planning-authority.md).
- Specs publicadas [1008 r2](../../specs/1008/r2-annual-rate-conversion.md), [1012 r2](../../specs/1012/r2-amortization-comparison.md), [1013 r2](../../specs/1013/r2-widgets-interface.md), [1014 r2](../../specs/1014/r2-reproducible-delivery.md); [índice 1015 r3](../../documents/1015/r3-research-driven-design.md).
- Decisões [1025](../../decisions/1025/r1-exact-rounding-method.md), [1026](../../decisions/1026/r1-qt-baseline-choice.md), [1027](../../decisions/1027/r1-research-design-integration.md); análises [1023](../../documents/1023/r1-numerical-resolution.md) e [1024](../../documents/1024/r1-qt-baseline-review.md).
- [Contrato físico/fixtures 1030](../../documents/1030/r1-test-interface-and-fixtures.md), [plano de testes 2001](../2001/r1-requirement-test-plan.md) e, na execução, seus assets e retorno de base. São 25 requisitos exatos r1, referenciados em cada tarefa. Seus links históricos a specs r1 não substituem a seleção r2 aceita em 1028.
- Pins primários observados em [source-pins.json](../../evidence/implementation-planning/source-pins.json), [qt-acquisition-pins.json](../../evidence/implementation-planning/qt-acquisition-pins.json) e [ci-action-pins.json](../../evidence/implementation-planning/ci-action-pins.json). Foram lidos metadados/digests; nenhum payload foi obtido nesta autoria.

Nenhum destes inputs será modificado ou artificialmente commitado por 2002. Não há dependência de publicar arquivos de referência só para satisfazer o commit check.

## File Structure

Owner de todas as operações desta seção: dev implementação. O README.md atual fica intocado; docs/README.md será a entrada de documentação criada por esta tarefa, evitando capturar hunks anteriores do coordenador no commit de produto. Arquivos `tests/` são exclusivamente do autor de 2001 e ficam reference-only para este plano. Repetir create para um mesmo arquivo novo em mais de uma tarefa significa que diferentes obrigações compõem sua primeira versão; o arquivo é agregado uma vez no commit check, sem pares create/modify contraditórios. As tabelas enumeram mudanças de fonte versionáveis. Builds, exports, dependências baixadas, relatórios operacionais e pacotes são saídas derivadas identificadas nas seções de execução; não são mudanças ocultas de fonte nem commits artificiais de binários.

| Operation | Path | Destination |
|---|---|---|
| create | .github/workflows/ci.yml | - |
| create | CMakeLists.txt | - |
| create | CMakePresets.json | - |
| create | LICENSE | - |
| create | docs/README.md | - |
| create | THIRD_PARTY_NOTICES.md | - |
| create | cmake/AcquireDependencies.cmake | - |
| create | cmake/Dependencies.cmake | - |
| create | cmake/Packaging.cmake | - |
| create | cmake/ThirdPartyNotices.cmake | - |
| create | cmake/Version.hpp.in | - |
| create | cmake/WindowsDeploy.cmake | - |
| create | cmake/dependencies.lock.json | - |
| create | docs/build-and-test.md | - |
| create | docs/technical-report.md | - |
| create | docs/user-guide.md | - |
| create | include/ceseb/finance.hpp | - |
| create | packaging/ceseb.desktop | - |
| create | packaging/qt.conf | - |
| create | resources/application.qrc | - |
| create | resources/model-help.html | - |
| create | src/app/main.cpp | - |
| create | src/core/exact_math.cpp | - |
| create | src/core/exact_math.hpp | - |
| create | src/core/finance.cpp | - |
| create | src/ui/main_window.cpp | - |
| create | src/ui/main_window.hpp | - |
| create | src/ui/money_codec.cpp | - |
| create | src/ui/money_codec.hpp | - |
| create | src/ui/simulation_controller.cpp | - |
| create | src/ui/simulation_controller.hpp | - |

Todas as operações são create; não há modify/rename/delete. O plano não escreve session_state.yaml ou memória root; a manutenção continua com o orquestrador. Se uma criação já existir na baseline futura, comparar ownership/conteúdo e retornar o conflito antes de alterar; não converter silenciosamente create em modify.

## Tasks

A ordem dos blocos organiza a **autoria dos métodos e disponibilização dos arquivos/interfaces**. As referências Dependencies abaixo são dependências de material de fonte pronto para composição, não exigência de encerramento, verdict pass ou Completion evidence do predecessor antes de escrever o próximo bloco. As tarefas podem continuar em andamento enquanto suas partes são compostas nos arquivos compartilhados. Nenhum resultado positivo é atribuído por ter apenas escrito um arquivo.

Há três fases concretas: (1) preparar I-1221 e escrever os métodos de I-1101 a I-1207; (2) escrever adaptador/janela e materiais de I-1211 a I-1228; (3) depois de existirem as fontes e dependências reais, executar V-CORE/V-BUILD/V-DOMAIN, montar os pacotes e realizar os protocolos nativos/documentais, encerrando as Completion evidence aplicáveis. V-CORE de I-1221 é qualificação final desse contrato, não uma barreira que bloqueia a criação posterior de finance.hpp. Compilação ou coleta ainda impossíveis na composição são registradas como tais, sem stubs de sucesso e sem RED fabricado. Testes já viáveis podem rodar durante a autoria, mas a suíte completa exige todos os símbolos reais.

Todas as fases continuam dependentes do retorno inicial de 2001 e da aprovação concreta deste corpo/efeitos. Relatórios e consultas de frontier deverão refletir essa ordem real de fases e manter as tarefas incompletas até sua verificação final. Não declarar conclusão antecipada para liberar a sequência.

### Task I-1221

Requirement: [1221 r1](../../requirements/1221/r1-build-contract.md)

Kind: implementation

Method: Construir o núcleo independente e o suporte de engenharia. Após o retorno inicial de 2001, criar o projeto C++20 versão 0.1.0 com targets `ceseb_core`, `ceseb_ui` e `ceseb`, mais a integração opt-in dos targets de teste já entregues. Implementar opções `CESEB_BUILD_GUI`, `CESEB_BUILD_TESTS` e `CESEB_ENABLE_COVERAGE`. Fazer `find_package(Qt6 6.12.0 EXACT COMPONENTS Core Gui Widgets)` somente quando GUI estiver ON, acrescentando Test somente para GUI+testes. `ceseb_core` não inclui nem liga Qt. Boost 1.86 é header-only; validar BOOST_VERSION=108600 em CESEB_BOOST_ROOT. GTest 1.17 é localizado no prefixo preparado e só entra com testes. Fixar saída executável em bin e paths de install por plataforma. Ativar AUTOMOC/AUTORCC somente nos targets Qt que consomem QObject/recursos, sem transformar o core em target Qt; o harness dos testes define sua própria automação Qt.

Acrescentar acquisition script CMake e lockfile com os pins da seção Dependencies. Downloads são separados do configure normal: nenhum fetch silencioso ao configurar o núcleo. Exigir TLS_VERIFY ON, NETRC IGNORED, EXPECTED_HASH SHA256 e status bem-sucedido antes de extrair cada arquivo em cache próprio; manifesto operacional registra origem, digest, versão, destino e reutilização. Qt usa os subconjuntos oficiais identificados; não instala Qt Creator/QML nem aceita termos/contas por inferência. GTest usa o commit fixo, sem branch flutuante; o script compila e instala a dependência no prefixo local, com o runtime correspondente. Reutilizar o ambiente preparado pelo autor dos testes antes de obter uma segunda instalação. Depois de extrair Qt, observar qtpaths/qmake query de prefixo, Qt6_DIR e imported targets CMake: todos devem apontar ao prefixo selecionado; confirmar windeployqt --version/presença no Windows. Se o SDK exigir qt.conf para um Prefix relativo, gerar somente configuração própria no cache/build e registrá-la no acquisition-manifest, sem patch de Qt. Falha de relocação é indisponibilidade do kit; não autoriza trocar pin ou compilar framework por conta própria.

Criar workflow somente `workflow_dispatch`, com Ubuntu 24.04/GCC 13 e windows-2022/MSVC 2022 v143, usando os mesmos comandos e acquisition script; registrar SO/compilador reais. Actions fixadas por SHA, permissões contents:read, sem secrets próprios, push ou release. Não disparar o workflow por esta tarefa. Uma rota sem GUI configura e testa core sem Qt instalado. Presets linux-release, windows-release e core-only expressam os mesmos flags; CESEB_SOURCE_REVISION explicita o SHA no export sem .git. O arquivo Version.hpp.in gera os identificadores no build.

Dependencies: Retorno inicial de 2001; aprovação concreta; ambiente identificado.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | CMakeLists.txt | - |
| create | CMakePresets.json | - |
| create | cmake/Dependencies.cmake | - |
| create | cmake/AcquireDependencies.cmake | - |
| create | cmake/dependencies.lock.json | - |
| create | cmake/Version.hpp.in | - |
| create | .github/workflows/ci.yml | - |

Completion evidence: Executar V-CORE nas duas toolchains sem Qt disponível para a rota isolada; inspecionar interfaces/links e CMake configure para confirmar que não procura Qt. Executar V-BUILD com GUI na mesma fonte. Rodar o caso 1221 de 2001, com os testes entregues antes do produto. Cobertura GCC é diagnóstico opcional separado, sem limiar numérico. Um runner CI diferente de Windows 11 não satisfaz 1226.

### Task I-1101

Requirement: [1101 r1](../../requirements/1101/r1-explicit-rate-kind.md)

Kind: implementation

Method: Exigir a convenção explícita da taxa. Criar os tipos públicos e `Result<T>=std::variant<T,Error>` conforme o contrato 1030, com `AnnualRate{optional<RateKind>, string percent}`. `normalize` rejeita tipo ausente/desconhecido antes de aplicar fórmulas. Conservar todas as unidades nos nomes e não inferir convenção pelo percentual. Registrar a separação entre percentual anual de origem e fator mensal.

Dependencies: I-1221

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | include/ceseb/finance.hpp | - |
| create | src/core/finance.cpp | - |

Completion evidence: V-DOMAIN com Req1101.*: nominal e efetiva 12% produzem os valores distintos; ausente/desconhecido retorna InvalidRateKind sem sucesso. Inspecionar API pública sem Qt.

### Task I-1105

Requirement: [1105 r1](../../requirements/1105/r1-invalid-rate-input.md)

Kind: implementation

Method: Validar o percentual antes de construir um racional. Implementar o construtor lógico de valor decimal canônico e a validação de `normalize`, preservando sinal/valor finito exato. Rejeitar NaN, Infinity e -Infinity com NonFiniteRate antes da criação do racional; rejeitar valores finitos fora de 0..100 com RateOutOfRange. Não recuperar valor pretendido perdido antes da API e não truncar a origem para decimal 50. Formatos locais malformados pertencem a MoneyCodec; o core recebe o texto canônico definido em 1030. Exceção aritmética/recursos não retorna sucesso parcial.

Dependencies: I-1101

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | include/ceseb/finance.hpp | - |
| create | src/core/finance.cpp | - |
| create | src/core/exact_math.hpp | - |
| create | src/core/exact_math.cpp | - |

Completion evidence: Req1105.* para as duas convenções: não finitos, -0.01, 0, 100 e 100.01; fronteiras inclusivas passam sem limitar equivalentes derivados. Igualdade de ErrorCode e ausência de NormalizedRate no erro.

### Task I-1102

Requirement: [1102 r1](../../requirements/1102/r1-nominal-monthly.md)

Kind: implementation

Method: Normalizar nominal como fração exata. Representar percentual canônico finito como `cpp_rational` reduzido e calcular x=1+p/1200 diretamente. Conservar a origem e o RationalGrowth. Implementar projeção mensal decimal somente para os critérios de taxa; ela não alimenta decisões de centavos. Helpers específicos fazem operações inteiras e conversão verificada, sem framework numérico genérico.

Dependencies: I-1105

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | include/ceseb/finance.hpp | - |
| create | src/core/finance.cpp | - |
| create | src/core/exact_math.hpp | - |
| create | src/core/exact_math.cpp | - |

Completion evidence: Req1102.* usa 0,4.5,12,100 e referências 0,0.00375,0.01,1/12, erro mensal máximo 1e-12; zero exato. O caso 6 centavos/100% é também verificado por 1106/1205 sem tolerância monetária.

### Task I-1103

Requirement: [1103 r1](../../requirements/1103/r1-effective-monthly.md)

Kind: implementation

Method: Conservar a raiz efetiva e classificar o ramo racional. Calcular g=1+p/100 como racional reduzido. Testar potências inteiras de grau 12 no numerador e denominador por bisseção de inteiro e comparação exata; não fatorar. Conservar RationalGrowth quando ambas forem perfeitas, senão TwelfthRootGrowth{g}. Comparar x com fronteira racional y por g versus y^12, com multiplicação cruzada inteira. Para projeção mensal usar limites racionais que certifiquem o erro de 1e-12, sem cancelamento numérico como fundamento de centavos. A origem pequena positiva não vira zero por piso da GUI.

Dependencies: I-1102

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | include/ceseb/finance.hpp | - |
| create | src/core/finance.cpp | - |
| create | src/core/exact_math.hpp | - |
| create | src/core/exact_math.cpp | - |

Completion evidence: Req1103.* com 0,4.5,12 efetivos e referências independentes. Acrescentar no resultado do plano os casos tipados p=0.000000000001 e a raiz racional de 1205; registrar tempo/memória por toolchain, sem inferir um limite de desempenho não aprovado.

### Task I-1104

Requirement: [1104 r1](../../requirements/1104/r1-annual-equivalents.md)

Kind: implementation

Method: Produzir equivalentes anuais da mesma origem. Implementar `project_rates` sem alterar o descritor: N=1200(x-1), E=100(x^12-1). No ramo efetivo E é a entrada racional p; no nominal ambos são racionais. Converter projeções somente após construir limites suficientes para as tolerâncias de taxa. Não cortar E derivado acima de 100%. A API de projeções é separada da quantização textual e da decisão de juros.

Dependencies: I-1103

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | include/ceseb/finance.hpp | - |
| create | src/core/finance.cpp | - |
| create | src/core/exact_math.hpp | - |
| create | src/core/exact_math.cpp | - |

Completion evidence: Req1104.* com nominal 12, efetiva 12, zeros e nominal 100. Conferir N/E por tolerância de 1e-9 ponto percentual e zero exato; p nominal 100 permite E>100. Não converter referências para double.

### Task I-1106

Requirement: [1106 r1](../../requirements/1106/r1-unrounded-consumer-rate.md)

Kind: implementation

Method: Transportar a origem exata ao consumidor financeiro. Implementar a composição interna de compare a partir de uma única normalização e passar const NormalizedRate aos dois livros. Não ler nem reconstruir taxa de um rótulo ou de RateProjection. Manter percent/kind/growth observáveis segundo 1030, com ownership por valor que não dependa do lifetime do texto da GUI. O caminho de apresentação não modifica o descritor.

Dependencies: I-1104

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | include/ceseb/finance.hpp | - |
| create | src/core/finance.cpp | - |

Completion evidence: Req1106.*: comparar origem e projeções de efetiva 12 antes/depois de formatação e nominal 100 com principal 6/prazo 1. Inspecionar uma chamada a normalize e o mesmo descritor passado a ambos os cálculos; juros=1 nos dois, qualquer precisão de rótulo.

### Task I-1201

Requirement: [1201 r1](../../requirements/1201/r1-loan-domain.md)

Kind: implementation

Method: Validar entrada e ordenar erros. Definir LoanInput e a fronteira compare: principal 1..10000000000 centavos, prazo 1..600 inteiro. Validar principal, taxa/tipo, prazo e depois admissibilidade de centavos. Rejeitar sem construir Comparison parcial. Os cálculos isolados também protegem seu domínio público de 1030; a comparação normaliza somente uma vez. Nunca lançar fora da API um erro de domínio esperado.

Dependencies: I-1106

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | include/ceseb/finance.hpp | - |
| create | src/core/finance.cpp | - |

Completion evidence: Req1201.*: principal 0/10000000001, prazo 0/601, limites inclusivos 1 e 10000000000, n=1/600, e combinações de erros. Conferir o primeiro ErrorCode e ausência de sucesso.

### Task I-1202

Requirement: [1202 r1](../../requirements/1202/r1-price-ledger.md)

Kind: implementation

Method: Calcular Price e decidir a prestação ordinária exatamente. Implementar calculate_price com dinheiro int64 e intermediários `cpp_int/cpp_rational`. Para x racional avaliar a anuidade exata C*x^n/(1+...+x^(n-1)); usar R(u/v)=(2u+v) div(2v). Para x irracional, refinar [1,2] por comparações de potência 12 e avaliar F dos extremos como frações; aceitar o inteiro somente quando ambos arredondam igual. O argumento de terminação aprovado em 1023 não substitui medição nativa. Não usar epsilon, escala mensal fixa ou limite arbitrário de dígitos para escolher o centavo.

Cada mês calcula juro half-up sobre saldo de abertura por comparação exata; parcela anterior ao limite é min(a,B+I), última B+I. Amortização=pagamento-juro; encerrar assim que saldo zero, sem linha posterior nem cobrança negativa. Preencher ordinary_payment, actual_payments e early_payoff com a semântica aprovada.

Dependencies: I-1201

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | include/ceseb/finance.hpp | - |
| create | src/core/finance.cpp | - |
| create | src/core/exact_math.hpp | - |
| create | src/core/exact_math.cpp | - |

Completion evidence: Req1202.*: vetores de 1000/12% nominal/3 e 1000/0/600, 3 centavos/0/2, efetiva 12%/1000/3. Igualdade inteira de cada linha/resumo. Medir um conjunto com C máximo, n600, efetiva 100 e percentual tipado pequeno nas duas toolchains; anexar números observados sem anunciar latência aprovada inexistente.

### Task I-1203

Requirement: [1203 r1](../../requirements/1203/r1-sac-ledger.md)

Kind: implementation

Method: Calcular SAC com resto no início. Implementar calculate_sac com q=C div n e r=C mod n; amortizar q+1 nos primeiros r meses e q depois. Juros sobre saldo de abertura usam o mesmo comparador exato do Price; somas em int64 verificadas. Produzir exatamente n linhas admissíveis; pagamentos não crescentes admitem empates. Nunca reaproveitar o JSON exploratório com resto final como oráculo.

Dependencies: I-1202

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | include/ceseb/finance.hpp | - |
| create | src/core/finance.cpp | - |
| create | src/core/exact_math.hpp | - |
| create | src/core/exact_math.cpp | - |

Completion evidence: Req1203.* confere amortizações [33334,33333,33333], juros [1000,667,333], pagamentos [34334,34000,33666] e saldo final zero; casos de 6 centavos/100% e vizinhanças 5.999999/6/6.000001 não podem depender da aproximação decimal.

### Task I-1204

Requirement: [1204 r1](../../requirements/1204/r1-money-invariants.md)

Kind: implementation

Method: Reconciliar linhas e totais em centavos. Calcular os resumos a partir das linhas, com adição/subtração verificada e conversão int64 controlada. Manter opening-closing=principal_paid, payment=principal_paid+interest, amortização positiva, saldo não negativo, soma principal=C e total=C+soma juros. Em erro aritmético descartar ambos os resultados da comparação. Não criar uma segunda implementação financeira no produto para validar a primeira.

Dependencies: I-1202, I-1203

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | include/ceseb/finance.hpp | - |
| create | src/core/finance.cpp | - |

Completion evidence: Req1204.* aplica identidades exatas a todos os vetores e fronteiras admissíveis de 1201, verificando 1..n linhas Price/n linhas SAC e ausência pós-quitação. A conformidade desses casos não é prova de todo o domínio.

### Task I-1205

Requirement: [1205 r1](../../requirements/1205/r1-zero-and-single-period.md)

Kind: implementation

Method: Tratar zero e cobrança única. Tratar x=1 sem singularidade, com anuidade C/n exata e juros zero. Para n=1 liquidar em um único pagamento B+I e preencher o resumo sem segunda cobrança. Conservar os caminhos de raiz racional efetiva e fração nominal recorrente; a classificação exata antecede qualquer decisão de arredondamento.

Dependencies: I-1204

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | include/ceseb/finance.hpp | - |
| create | src/core/finance.cpp | - |
| create | src/core/exact_math.hpp | - |
| create | src/core/exact_math.cpp | - |

Completion evidence: Req1205.* inclui 1200/0/12,100 centavos/6% nominal/1,6 centavos/100%/1, vizinhanças 6% e p=100*((201/200)^12-1) efetiva exata com mais de 6 casas. Juros do empate=1, pagamento 101 ou 7 conforme principal; sem tolerância de centavos.

### Task I-1206

Requirement: [1206 r1](../../requirements/1206/r1-cent-precision-errors.md)

Kind: implementation

Method: Recusar o domínio inviável em centavos. Antes de entregar a comparação, recusar C<n ou a prestação Price ordinária a<=R(C*m) com UnsupportedCentPrecision. Usar os mesmos cálculos exatos que o livro emprega, sem um piso monetário adicional. Não expor SAC ou Price isolado como Comparison parcial quando o outro ramo falha.

Dependencies: I-1205

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | include/ceseb/finance.hpp | - |
| create | src/core/finance.cpp | - |

Completion evidence: Req1206.*: C=1/n=600/taxa 0 e C=1200/n=600/nominal 100 recusados; no segundo a e primeiro juro são 100. Conferir erro exclusivo e nenhum livro/resumo de sucesso.

### Task I-1207

Requirement: [1207 r1](../../requirements/1207/r1-comparable-results.md)

Kind: implementation

Method: Compor a comparação sob entradas idênticas. Construir Comparison somente depois de obter ambos os livros com a mesma NormalizedRate e LoanInput. Devolver interest_difference=Price.interest_total-SAC.interest_total em centavos com sinal. Não incluir recomendação de melhor sistema nem encargos/CET. A apresentação recebe os resultados da mesma chamada atômica.

Dependencies: I-1206

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | include/ceseb/finance.hpp | - |
| create | src/core/finance.cpp | - |

Completion evidence: Req1207.*: nominal 12%/1000/3 => juros 2007/2000 e diferença+7; efetiva equivalente 12.682503013196972066120100% preserva os vetores desse caso. Efetiva 12% permanece distinta e alteração apenas de rótulo não muda o resultado.

### Task I-1211

Requirement: [1211 r1](../../requirements/1211/r1-localized-input.md)

Kind: implementation

Method: Converter estritamente os campos pt-BR. Criar MoneyCodec com o contrato 1030. Implementar validação explícita da gramática de principal/grupos de 3 dígitos/duas casas, taxa vírgula/até 6 casas sem grupos/sinal/expoente, e prazo inteiro. Remover só espaços externos. Converter centavos com operações inteiras e a taxa para texto decimal canônico, sem double nem truncamento. A configuração padrão de QDoubleValidator/QLocale não substitui essa gramática. Erros preservam a identificação de campo esperada pelo controlador.

Dependencies: I-1207

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | src/ui/money_codec.hpp | - |
| create | src/ui/money_codec.cpp | - |

Completion evidence: Executar o slot `GuiContractTests::req1211_localized_input`. Aceitar `100.000,00` e `100000,00` como 10.000.000 centavos; recusar os principais `1,000`, `1,234.56`, `1e3` e vazio. Taxas `4,5` e `4,123456` são válidas; `4.5` e `4,1234567` são inválidas. Prazo `360` é válido; `0` e `3,5` são inválidos. Conferir ambas as convenções e a remoção exclusiva dos espaços externos.

### Task I-1214

Requirement: [1214 r1](../../requirements/1214/r1-ui-state-recovery.md)

Kind: implementation

Method: Ligar eventos e recuperação atômica. Criar SimulationController e a ligação QObject/MainWindow conforme 1030. Estado inicial Editing sem resultado automático; edição de qualquer campo/tipo apaga todos os resultados. Calcular coleta/valida na ordem aprovada, chama uma vez CompareFunction e atualiza ambos os cartões juntos. Erro preserva campos, limpa resultados, mostra mensagem e foca o campo aprovado; ArithmeticError é geral e foca Calcular. Limpar apaga campos/resultados, restaura nominal e foco principal. CompareFunction injetável existe somente para o erro controlado de 1214; o app usa compare real. Sem thread, timer, rede ou persistência.

Dependencies: I-1211

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | src/ui/simulation_controller.hpp | - |
| create | src/ui/simulation_controller.cpp | - |
| create | src/ui/main_window.hpp | - |
| create | src/ui/main_window.cpp | - |

Completion evidence: GuiContractTests `req1214_state_recovery`: editar cada campo e tipo depois de sucesso, erros isolados/combinados, UnsupportedCentPrecision, resposta controlada ArithmeticError, correção/recalcular/Limpar. Validar foco e ausência de valores antigos; mensagens sem traceback/caminho interno.

### Task I-1212

Requirement: [1212 r1](../../requirements/1212/r1-rate-presentation.md)

Kind: implementation

Method: Formatar percentuais já quantizados half-up. Implementar quantize_rates/quantize_percent usando inteiros de milionésimo de ponto percentual e comparações exatas da spec 1008 r2. O formatter de MoneyCodec apenas insere vírgula e seis dígitos; não usa ties-to-even genérico nem recalcula a taxa financeira. Ligar os três rótulos com tipo/período explícitos e permitir E>100. Resultados de dinheiro usam int64 em duas casas e agrupamento BRL.

Dependencies: I-1214

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | include/ceseb/finance.hpp | - |
| create | src/core/finance.cpp | - |
| create | src/core/exact_math.hpp | - |
| create | src/core/exact_math.cpp | - |
| create | src/ui/money_codec.hpp | - |
| create | src/ui/money_codec.cpp | - |
| create | src/ui/main_window.hpp | - |
| create | src/ui/main_window.cpp | - |

Completion evidence: Executar `GuiContractTests::req1212_rate_presentation` e a fixture isolada exata. Nominal anual 12% mostra 1,000000% mensal, 12,000000% nominal anual e 12,682503% efetiva anual. Efetiva anual 12% mostra 0,948879%, 11,386552% e 12,000000%, respectivamente. Nominais 0,000005% / 0,000006% / 0,000007% mostram mensal 0,000000% / 0,000001% / 0,000001%. A fixture percentual racional 0,0000005% produz 0,000001%; o texto não retorna ao cálculo.

### Task I-1213

Requirement: [1213 r1](../../requirements/1213/r1-comparison-presentation.md)

Kind: implementation

Method: Apresentar os cartões e prazos reais. Criar a janela principal e main.cpp, inicializar QApplication/estilo Fusion/paleta clara e carregar o controlador. Os objectNames de 1030 permanecem estáveis. Mostrar cartões Price/SAC lado a lado quando couber, com parcela ordinária/primeira, última, contagem efetiva, total/juros, prazo informado e diferença assinada. Identificar última ajustada e quitação antes do prazo. n=1 é única cobrança final. Entradas iniciais 250000,00/4,5/360 e combo nominal; resultados vazios até Calcular.

Dependencies: I-1212

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | src/ui/main_window.hpp | - |
| create | src/ui/main_window.cpp | - |
| create | src/app/main.cpp | - |

Completion evidence: GuiContractTests `req1213_comparison_presentation`: nominal 12%/1000/3 valores literais 1213, diferença R$ 0,07 e 3 pagamentos; zero/1000/600=>Price 599/última 1,34 e SAC 600/última 1,66; n=1 não sugere duas cobranças.

### Task I-1215

Requirement: [1215 r1](../../requirements/1215/r1-keyboard-navigation.md)

Kind: implementation

Method: Permitir o fluxo completo por teclado. Definir buddies, nomes acessíveis, foco visível e ordem Tab principal,taxa,tipo,prazo,Calcular,Limpar,Sobre; Shift+Tab inverso. Enter no formulário calcula; Escape na janela principal fecha. Fazer ajuda/erros acessíveis sem mouse e sem depender só de cor. Preservar edição/copiar textos de resultado.

Dependencies: I-1213

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | src/ui/main_window.hpp | - |
| create | src/ui/main_window.cpp | - |
| create | src/app/main.cpp | - |

Completion evidence: Aplicar protocolo nativo 2001/1215 nos dois desktops: preencher/calcular, provocar/corrigir erro, limpar, abrir ajuda e fechar só com teclado. QtTest adicional não substitui demonstração nativa.

### Task I-1216

Requirement: [1216 r1](../../requirements/1216/r1-resize-access.md)

Kind: implementation

Method: Organizar os layouts e a rolagem. Usar layouts Qt e área de rolagem para campos/cartões; sem posições absolutas nem fontes externas. Inicial 1040x760 lógico. Em 800x600 e escalas 100/200%, reorganizar conteúdo ou permitir rolagem vertical mantendo todo controle/texto alcançável e sem rolagem horizontal do formulário. Não acrescentar framework CSS, animação ou preferência persistida.

Dependencies: I-1215

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | src/ui/main_window.hpp | - |
| create | src/ui/main_window.cpp | - |

Completion evidence: Protocolo 2001/1216: quatro combinações Win 11/Ubuntu 24 x100/200%, caso 1000/0/600 com aviso de quitação. Capturas e navegação comprovam texto completo/ausência de sobreposição impeditiva; nenhuma extrapolação para outras resoluções.

### Task I-1217

Requirement: [1217 r1](../../requirements/1217/r1-model-help.md)

Kind: implementation

Method: Disponibilizar ajuda e licenças locais. Criar resources/model-help.html e resources/application.qrc, exibir Sobre e modelo com versão 0.1.0/revisão de fonte e links locais de licenças. Texto pt-BR cobre nominal/efetiva, Price/SAC, postecipação, centavos, parcela final/prazo efetivo e exclusões de seguros/tarifas/impostos/indexadores/CET. Compilar ajuda no recurso Qt; abrir não exige rede. Licenças instaladas são abertas localmente, sem navegar automaticamente para web.

Dependencies: I-1216

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | src/ui/main_window.hpp | - |
| create | src/ui/main_window.cpp | - |
| create | resources/application.qrc | - |
| create | resources/model-help.html | - |

Completion evidence: Protocolo 2001/1217 inspeciona cada tópico offline e acessa licenças locais no pacote. Não considerar aprovação subjetiva de modernidade como critério.

### Task I-1228

Requirement: [1228 r1](../../requirements/1228/r1-distribution-notices.md)

Kind: implementation

Method: Identificar originais e inventariar materiais reais. Criar LICENSE MIT dos originais, copyright 2026 paulo-vitor-cs, sem relicenciar terceiros. Acrescentar avisos SPDX/copyright aos arquivos de produto do plano durante sua criação; os testes mantêm avisos do seu próprio autor e não são editados aqui. Criar THIRD_PARTY_NOTICES.md e cmake/ThirdPartyNotices.cmake para conservar textos aplicáveis, inventário por componente, versão/forma distribuída e fontes recuperáveis exatas. Para Qt selecionar os componentes realmente copiados, QtBase 6.12.0 build especificado, GPLv3/LGPLv3 e avisos de terceiros efetivos (inclusive ICU/fonte interna vendorizada conforme inventário), sem copiar cegamente todo SDK. Obter a fonte correspondente exata de Qt/suas modificações e instruções necessárias de substituição/reconstrução; um link móvel latest não basta. Não emitir pacote completo se esses materiais faltarem.

Inspecionar edição MSVC 2022 efetiva, termos/lista REDIST aplicáveis e dependências que o pacote usa, antes de copiar CRT app-local; Community não substitui automaticamente BuildTools. Preservar avisos Boost quando fontes/headers forem distribuídos e GoogleTest BSD nos materiais de build que os incluem. QtTest/GTest não entram no runtime. Confrontar CVE-2026-105924 com APIs/caminhos realmente usados, sem afirmar ausência global de vulnerabilidades ou aplicar patches próprios; se houver caminho afetado, retornar escolha antes da entrega.

Dependencies: I-1217

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | LICENSE | - |
| create | THIRD_PARTY_NOTICES.md | - |
| create | cmake/ThirdPartyNotices.cmake | - |
| create | CMakeLists.txt | - |
| create | CMakePresets.json | - |
| create | cmake/Dependencies.cmake | - |
| create | cmake/AcquireDependencies.cmake | - |
| create | cmake/dependencies.lock.json | - |
| create | cmake/Version.hpp.in | - |
| create | .github/workflows/ci.yml | - |
| create | include/ceseb/finance.hpp | - |
| create | src/core/finance.cpp | - |
| create | src/core/exact_math.hpp | - |
| create | src/core/exact_math.cpp | - |
| create | src/ui/money_codec.hpp | - |
| create | src/ui/money_codec.cpp | - |
| create | src/ui/main_window.hpp | - |
| create | src/ui/main_window.cpp | - |
| create | src/ui/simulation_controller.hpp | - |
| create | src/ui/simulation_controller.cpp | - |
| create | src/app/main.cpp | - |
| create | resources/application.qrc | - |
| create | resources/model-help.html | - |

Completion evidence: Protocolo 2001/1228 compara inventário com staging dos dois alvos, textos/avisos/fontes exatas e substituição de Qt dinâmica. Inspeção no conteúdo efetivo, não checklist abstrato. Registrar componentes ausentes/sobras e manter 1228 sem resultado positivo se licenças/fontes/CRT não qualificados.

### Task I-1225

Requirement: [1225 r1](../../requirements/1225/r1-runtime-packages.md)

Kind: implementation

Method: Montar ZIP e DEB com runtime privado. Criar cmake/Packaging.cmake, cmake/WindowsDeploy.cmake, packaging/ceseb.desktop e packaging/qt.conf; integrar install/CPack no CMake raiz. Windows: stage/bin/ceseb.exe, Qt DLL/QPA necessários em árvore local e CRT app-local permitido. Usar windeployqt do kit exato com runtime do compilador tratado explicitamente; não considerar um vc_redist.exe coletado como garantia do ZIP portátil. CMake InstallRequiredSystemLibraries pode coletar a lista qualificada de CRT Release, sem runtime Debug/UCRT do SO nem cópia arbitrária. Auditar dependências reais antes de empacotar.

Linux: DEB amd64 instala em /opt/ceseb, bin/ceseb, Qt privado em lib e plugins com RPATH=$ORIGIN/../lib e qt.conf local, launcher desktop com Exec=/opt/ceseb/bin/ceseb e dependências Ubuntu runtime. Qt CMake deployment e CPack SHLIBDEPS ajudam a coleta, mas não provam fechamento. Não copiar glibc ou substituir Qt global. Pacotes finais em out/packages/ceseb-0.1.0-windows-x86_64.zip e ceseb_0.1.0_amd64.deb identificam versão, plataforma e SHA real de origem, acompanhados do inventário/avisos; fonte correspondente é acessível conforme 1228. Mesma revisão do core nas duas rotas.

Dependencies: I-1228

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | cmake/Packaging.cmake | - |
| create | cmake/WindowsDeploy.cmake | - |
| create | packaging/ceseb.desktop | - |
| create | packaging/qt.conf | - |
| create | CMakeLists.txt | - |

Completion evidence: V-PACKAGE monta/inspeciona os dois artefatos e usa o protocolo 2001/1225 para extração/instalação padrão em ambientes limpos sem Qt de desenvolvimento/compilador. Biblioteca/plugin ausente é falha; nome de arquivo não prova identidade. Metadados DEB com Architecture amd64, dependências reais e nenhum Qt global substituído.

### Task I-1226

Requirement: [1226 r1](../../requirements/1226/r1-native-smoke.md)

Kind: implementation

Method: Conferir a operação do pacote nas duas plataformas. Tarefa de inspeção/demonstração sem alteração planejada de arquivo de produto. Usar como inputs reference-only o pacote ZIP, pacote DEB,app instalado e protocolo a tarefa T1226 e seu protocolo no plano 2001. Acompanhar o autor dos testes no cenário completo contra o mesmo IMPLEMENTATION_HEAD e registrar logs/capturas no report separado; não substituir sua autoria nem alterar testes. Falha descoberta retorna ao requisito/arquivo proprietário sob a mesma tarefa aplicável ou exige reconciliação de escopo, sem reescrever o oráculo. O relatório deste plano não marca requisito pass: julgamento independente vem em Synapses.

Dependencies: I-1225

#### Files

| Operation | Path | Destination |
|---|---|---|

Nenhuma alteração de fonte planejada; tabela vazia intencional. Inputs reference-only estão descritos no método.

Completion evidence: V-NATIVE em Windows 11 e Ubuntu 24.04 desktop limpos. Calcular R$ 1.000,00/12% nominal/3 meses; trocar para efetiva, conferir a invalidação e recalcular. Na efetiva: Price ordinária/última R$ 339,68, total R$ 1.019,04, juros R$ 19,04; SAC primeira R$ 342,83, última R$ 336,49, total R$ 1.018,98, juros R$ 18,98; diferença R$ 0,06. Executar erro/correção/Limpar/teclado/escala/fechar, identificando pacote/SHA/ambiente. WSL, offscreen e Server CI não constituem a qualificação nativa.

### Task I-1227

Requirement: [1227 r1](../../requirements/1227/r1-technical-documentation.md)

Kind: implementation

Method: Documentar uso, reprodução e resultados reais. Criar docs/user-guide.md, docs/build-and-test.md, docs/technical-report.md e docs/README.md como entrada do conjunto, preservando o README.md preexistente e suas alterações de coordenação. Documentar instalação/uso pt-BR, aquisição/pins, builds/testes em cada plataforma, fórmulas/half-up/exclusions, casos Price/SAC e dependências/licenças. O relatório técnico mapeia 25 requisitos aos planos/tarefas/arquivos e aos resultados das mesmas revisões/plataformas, com falhas e não executados explícitos. Cada comando chamado de verificado tem log recuperável, SHA do alvo e ambiente; dados esperados não são calculados pelo app. Fontes aprovadas read-only permanecem citadas, sem histórico Git artificial.

Separar build_source_commit do reviewed_result_commit: conteúdo derivado/relatório final não pode inventar o hash do próprio commit. O report de execução final associa BASE/HEAD reais e identifica quais mudanças documentais ocorreram após build, demonstrando a semântica do core/pacote equivalente ou reconstruindo o necessário. Entregar os links locais de evidência recuperáveis sem alegar que o report/artefatos foram enviados ao GitHub.

Dependencies: I-1226

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | docs/README.md | - |
| create | docs/user-guide.md | - |
| create | docs/build-and-test.md | - |
| create | docs/technical-report.md | - |

Completion evidence: Protocolo 2001/1227 confere cada tópico e cada alegação marcada como verificada; tabela de 25 requisitos com alvo real, planos/tarefas/arquivos, resultado e evidência. Links resolvem no recorte identificado; lacuna não vira sucesso. Não afirmar CI remoto executado ou release publicada.

## Verification

Os comandos abaixo são procedimentos futuros, não operações executadas nesta autoria. Comparações financeiras usam os casos e resultados de 2001/1030, originados dos requisitos; nunca preenchem o esperado com outputs do app. Não alterar asserts, fixtures ou tolerâncias para obter verde. Entregar ao autor dos testes logs e o snapshot exato, permitindo que ele execute a segunda parte independente de seu plano. O reviewer de Synapses julgará requisitos; concluir tarefas/commits não atribui pass.

### V-PREFLIGHT — acesso, sequência e fontes

Antes de qualquer mudança de produto, recuperar o retorno de base e o TEST_ASSETS_HEAD real. Conferir `git status --short`, `git rev-parse HEAD` e `git diff --name-only`; comparar com a lista de dirty/untracked preservada pelo orquestrador. A aprovação poderá permitir criar/reusar o ramo local `codex/mortgage-desktop` no mesmo checkout, com `git switch -c codex/mortgage-desktop` somente quando não existir e a inspeção confirmar o ponto correto; não sobrescrever ramo existente. Ler os 25 requisitos e quatro specs aprovadas, com hashes registrados no report. O plano e as fontes read-only estão sob o ROOT e podem continuar untracked sem serem incluídos no commit de produto.

Um preparador único, coordenado pelo orquestrador e pelo autor dos testes, observa/reutiliza toolchains e dependências antes de instalar outra cópia. Ubuntu alvo: 24.04 x64/GCC 13; Windows alvo: Windows 11 x64, prompt nativo MSVC 2022/v143. Comandos de observação: `cmake --version`, `ninja --version`, `g++-13 --version` em Ubuntu, `cl` no prompt MSVC, e o identificador do SO/arquitetura. Ausência de ambiente/dependência é lacuna, não falha comportamental. Não tentar qualificar o desktop Ubuntu com o GCC 15/WSL observado anteriormente.

A observação atual do ROOT é Ubuntu 26.04/WSL; esse ambiente não qualifica Ubuntu 24.04. Depois da autoria, commit e retorno dos assets reais, exportar o build_source_commit revisado para um alvo Ubuntu 24.04 x64/GCC 13 disponível e autorizado, em `/tmp/ceseb-native-1/source`. CWD nativo Linux é `/tmp/ceseb-native-1`; preservar fontes extraídas e conferir manifesto/hash/commit. Esse alvo não é outro checkout de autoria e não recebe commits. Provisionar VM/host ou instalar toolchain global continua fora do plano: sua ausência mantém a execução dependente indisponível. Após existir o script da tarefa I-1221 e o snapshot exportado, aquisição explícita no alvo Ubuntu:

```sh
cmake -DCESEB_DEPS_ROOT=/tmp/ceseb-native-1/build/dependencies -DCESEB_DEPS_PLATFORM=linux -DCESEB_ACQUIRE_QT=OFF -P source/cmake/AcquireDependencies.cmake
```

A tentativa de base de 2001 precede esse código de produto. Se o ambiente já foi preparado para 2001, o script valida e reusa os mesmos pins; não duplica instalações. A origem/manifesto de cada reutilização permanece explícita. O script não depende de login para a rota pública de arquivos documentada e não é um instalador que aceita termos pelo usuário. Compiler/CMake/Ninja, sessão desktop, acesso autorizado aos termos do toolchain e ferramentas de sistema são precondições; provisionar máquina ou instalação privilegiada não é inferido.

### V-SNAPSHOT — fonte comum dos alvos nativos

Depois da autoria dos arquivos e de seu commit real, capturar o build_source_commit revisado no ROOT, criar a saída própria out/ e exportar uma vez esse commit com `git archive --format=zip --output=out/native-source.zip HEAD`. Registrar o SHA do commit e o SHA256 do arquivo. Transferir apenas esse arquivo aos alvos autorizados; conferir os hashes antes/depois e o manifesto das fontes extraídas. Linux: `/tmp/ceseb-native-1/source`; Windows: `C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/source`. Não criar outro Git/checkout de autoria nesses destinos. Registrar o transporte efetivamente disponível; ausência de alvo ou canal autorizado é lacuna, sem criar VM ou destino remoto por inferência.

Os comandos de aquisição do V-PREFLIGHT são executados depois dessa materialização. Build, dependências e outputs ficam nas árvores irmãs da fonte. Definir CESEB_SOURCE_REVISION com o SHA real do manifesto em cada shell nativo. Toda alegação final identifica o mesmo snapshot/pacote e qualquer mudança documental posterior, conforme Commit Evidence; não exportar dirty/untracked como se fossem o commit.

### V-CORE e V-BUILD — Ubuntu

No alvo Ubuntu 24.04 identificado, CWD `/tmp/ceseb-native-1`, fonte imutável em source e `CESEB_SOURCE_REVISION` definido pelo SHA do manifesto:

```sh
cmake -S source -B build/core-only -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=g++-13 -DCESEB_SOURCE_REVISION="$CESEB_SOURCE_REVISION" -DCESEB_BUILD_GUI=OFF -DCESEB_BUILD_TESTS=ON -DCMAKE_DISABLE_FIND_PACKAGE_Qt6=TRUE -DCESEB_BOOST_ROOT=/tmp/ceseb-native-1/build/dependencies/boost_1_86_0 -DCMAKE_PREFIX_PATH=/tmp/ceseb-native-1/build/dependencies/install
cmake --build build/core-only --parallel
ctest --test-dir build/core-only -C Release --output-on-failure --no-tests=error --output-junit /tmp/ceseb-native-1/out/implementation/core-linux.xml
cmake -DCESEB_DEPS_ROOT=/tmp/ceseb-native-1/build/dependencies -DCESEB_DEPS_PLATFORM=linux -DCESEB_ACQUIRE_QT=ON -P source/cmake/AcquireDependencies.cmake
cmake -S source -B build/linux-release -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=g++-13 -DCESEB_SOURCE_REVISION="$CESEB_SOURCE_REVISION" -DCESEB_BUILD_GUI=ON -DCESEB_BUILD_TESTS=ON -DCESEB_BOOST_ROOT=/tmp/ceseb-native-1/build/dependencies/boost_1_86_0 '-DCMAKE_PREFIX_PATH=/tmp/ceseb-native-1/build/dependencies/Qt/6.12.0/gcc_64;/tmp/ceseb-native-1/build/dependencies/install'
cmake --build build/linux-release --parallel
ctest --test-dir build/linux-release -C Release --output-on-failure --no-tests=error --output-junit /tmp/ceseb-native-1/out/implementation/linux-release.xml
```

Criar previamente `out/implementation` como saída operacional própria. A aquisição inicial usa CESEB_ACQUIRE_QT=OFF e a primeira rota core-only é exercida antes de instalar/configurar o SDK Qt nesse ambiente. Conservar o log e permitir ao autor de 2001 confirmar/rodar os casos financeiros nessa fase. Somente depois obter Qt com CESEB_ACQUIRE_QT=ON e compor GUI. A rota core-only deve ser exercida em ambiente sem Qt, além da inspeção do grafo de link; desligar GUI num ambiente que contém Qt não prova sozinho ausência de dependência. Um backend gráfico compatível é necessário para testes GUI; headless/offscreen tem rótulo explícito e não substitui a demonstração nativa.

### V-DOMAIN — seleção e oráculo

Os runners acordados são `build/linux-release/bin/ceseb_domain_tests` e `build/linux-release/bin/ceseb_gui_tests`; no Windows, mesmos nomes com .exe no build nativo. Conferir `--gtest_list_tests` e `-functions` antes da seleção. Usar as seleções do plano 2001 e registrar nomes/contagem; filtro vazio ou skip de um caso obrigatório não demonstra sucesso. Rodar todos os casos depois de mudanças no core, e as seleções afetadas durante as tarefas. Para falha: preservar comando/saída/caso/alvo e reparar a implementação; um defeito nos testes retorna ao seu autor sem editar unilateralmente.

O núcleo exato precisa ser exercido nos casos racionais e irracionais, nos limites C=10000000000/n=600 e nos percentuais tipados pequenos. Registrar duração e recursos disponíveis por caso/toolchain no report; não criar timeout financeiro que escolha centavo arbitrário nem declarar um orçamento de latência não aprovado. Cobertura diagnóstica opcional: build separado `build/coverage`, GCC 13, `CESEB_ENABLE_COVERAGE=ON` e flags de compile e link `--coverage` somente em GCC/GNU e por opt-in, sem alterar a rota Release normal; o autor de 2001 define universo/exclusões e recolhe gcov 13 quando disponível, sem limiar percentual inventado.

### V-WINDOWS — snapshot nativo sem edição

A autoria/commits continuam em MAIN. Reusar o ZIP e SHA do V-SNAPSHOT, conferindo o manifesto de fonte antes da extração. Não exportar dirty/untracked como se fossem aquele commit. O mesmo procedimento de exportação serve ao alvo Linux declarado, com diretório /tmp/ceseb-native-1 e manifesto antes de usar as fontes. O staging Windows é saída operacional de verificação: `C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/source`; build e dependências ficam fora dessa fonte, em `C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build`. Não sobrescrever uma árvore sem manifesto de ownership correspondente. Conferir o export antes de uso e manter fontes extraídas imutáveis. Não é outra implementação, worktree Git ou autoria fora do ROOT.

A cópia controlada do ZIP para o host e `Expand-Archive` são realizadas somente no staging declarado. O report registra o comando de transporte e o hash antes/depois; um transporte perdido exige consultar o estado antes de repetir. No x64 Native Tools Command Prompt 2022, após `cd` para a fonte nativa:

```text
cmake -DCESEB_DEPS_ROOT=C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/dependencies -DCESEB_DEPS_PLATFORM=windows -DCESEB_ACQUIRE_QT=OFF -P cmake/AcquireDependencies.cmake
cmake -S . -B C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/core-only -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=cl -DCESEB_BUILD_GUI=OFF -DCESEB_BUILD_TESTS=ON -DCMAKE_DISABLE_FIND_PACKAGE_Qt6=TRUE -DCESEB_BOOST_ROOT=C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/dependencies/boost_1_86_0 -DCMAKE_PREFIX_PATH=C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/dependencies/install -DCESEB_SOURCE_REVISION=%CESEB_SOURCE_REVISION%
cmake --build C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/core-only --parallel
ctest --test-dir C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/core-only -C Release --output-on-failure --no-tests=error --output-junit C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/core-only/results.xml
cmake -DCESEB_DEPS_ROOT=C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/dependencies -DCESEB_DEPS_PLATFORM=windows -DCESEB_ACQUIRE_QT=ON -P cmake/AcquireDependencies.cmake
cmake -S . -B C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/windows-release -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=cl -DCESEB_BUILD_GUI=ON -DCESEB_BUILD_TESTS=ON -DCESEB_BOOST_ROOT=C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/dependencies/boost_1_86_0 "-DCMAKE_PREFIX_PATH=C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/dependencies/Qt/6.12.0/msvc2022_64;C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/dependencies/install" -DCESEB_SOURCE_REVISION=%CESEB_SOURCE_REVISION%
cmake --build C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/windows-release --parallel
ctest --test-dir C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/windows-release -C Release --output-on-failure --no-tests=error --output-junit C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/windows-release/results.xml
```

CESEB_SOURCE_REVISION recebe o SHA literal do manifesto antes do configure e não aceita valor vazio/unknown. A variável é input observado, não placeholder de commit inventado. A rota inicial core-only acima precede a aquisição Qt; registrar a ausência de Qt configurado e preservar o resultado. Se houver Qt preexistente no ambiente, não alegar que esse cenário comprova ausência de instalação; usar o alvo sem Qt requerido ou registrar a lacuna. Se MSVC ou Windows 11 não estiverem acessíveis, registrar a lacuna; runner Server 2022 não substitui esse alvo.

### V-PACKAGE e V-NATIVE

Ubuntu, no alvo qualificado e CWD `/tmp/ceseb-native-1`: `cmake --install build/linux-release --prefix /tmp/ceseb-native-1/out/stage/linux`; depois `cpack --config build/linux-release/CPackConfig.cmake -G DEB -B /tmp/ceseb-native-1/out/packages`. O staging configurado não deve substituir caminhos globais. O gerador DEB usa prefixo final /opt/ceseb e Architecture amd64; conferir metadata e dependências antes da instalação limpa. O artefato é `/tmp/ceseb-native-1/out/packages/ceseb_0.1.0_amd64.deb`; retornar a cópia verificada ao cut MAIN `out/packages/ceseb_0.1.0_amd64.deb` sem alterar conteúdo.

Windows: CMake install para `C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/out/stage/windows`; a regra WindowsDeploy usa windeployqt exato do prefixo qualificado, valida Qt/runtime/avisos e CPack ZIP gera `C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/out/packages/ceseb-0.1.0-windows-x86_64.zip`. Registrar hash, origem do SHA e inventário; transferir pacote/relatório para o cut de entrega MAIN sem mudar o conteúdo. O usuário extrai e abre `bin/ceseb.exe`.

O autor de testes executa os protocolos de 2001 no mesmo snapshot/pacote: Windows 11 e Ubuntu 24.04 desktop limpos, sem Qt/compilador de desenvolvimento ou PATH que mascare faltas. Dependências runtime Ubuntu declaradas podem ser instaladas pelo gerenciador padrão, com autorização/privilégios reais do ambiente; nenhum comando deste plano instala pacote privilegiado por inferência. Instalação DEB/execução de GUI nas máquinas-alvo é efeito da aprovação concreta de execução, não da preparação atual. Capturar telas, versão do SO, arquitetura, escala/backend, SHA do pacote e cada resultado. Não encerrar 1225/1226/1215/1216 se um dos alvos estiver ausente.

## Commit Evidence

Antes da execução registrar `BASE_IMPL=TEST_ASSETS_HEAD` como SHA real existente e ancestral. Registrar commits intermediários por tarefas e `IMPLEMENTATION_HEAD` real depois das mudanças de fonte; o revisor relaciona esse alvo aos builds/exports/pacotes. O autor dos testes usa seu próprio range de assets: `BASE_TEST..TEST_ASSETS_HEAD`, distinto do alvo runtime pós-produto. Nenhum HEAD literal é inventado agora.

Staging e commits futuros usam somente a lista exata de fontes da seção File Structure, por pathspec explícito: não usar `git add .`/`git add -A`. Os arquivos read-only de design/plano, o dirty/untracked anterior e assets de testes já commitados não entram no commit de produto. Preservar a lista inicial. Comparar `git diff --name-status BASE_IMPL..IMPLEMENTATION_HEAD`, inspecionar qualquer caminho inesperado e executar o card de commit coverage com os SHAs reais:

```text
mikoshi plan check-commits --root /home/paulo/ceseb --plan .mikoshi/brain/sessions/1-mortgage-desktop/plans/2002/r1-product-implementation-plan.md --base "$CESEB_BASE_IMPL" --head "$CESEB_IMPLEMENTATION_HEAD" --json
```

CESEB_BASE_IMPL e CESEB_IMPLEMENTATION_HEAD recebem os SHAs reais registrados no report antes desta chamada; nenhum deles pode estar vazio. A chamada efetiva terá os commits existentes. Cobertura de cada create/modify e ausência de dirty nos caminhos planejados são necessárias para implemented; um arquivo staged/untracked ou revertido não atende. Se o comando estiver indisponível, o plano não recebe implemented. O commit check não julga correção dos 25 requisitos. Push não é requerido nem autorizado por este critério.

## Risks and Recovery

- Preservar fontes/artefatos aprovados e testes. Um conflito de interface 1030 volta aos autores/root; não mudar o contrato aceito silenciosamente. Falha de teste conserva oracle e retorna o defeito ao owner.
- Interrupção: guardar último comando, alvo e saída; observar processos/arquivos reais antes de repetir. Downloads parciais não são extraídos; conferir hash novamente. Reutilizar somente cache com pin/manifesto válidos.
- Exports/staging/builds são próprios e podem ser refeitos só depois de registrar a evidência; nunca apagar cópia alheia, cache compartilhado, fonte, credenciais ou instalação global. Sem `git reset --hard`/limpeza ampla.
- O método exato pode custar mais nas fronteiras; registrar desempenho e eventual falha de recurso sem fabricar centavo. Se a operação não atender o produto, apresentar a evidência para revisão de design, sem introduzir thread, piso de taxa, epsilon ou precisão fixa por conveniência.
- Kit/ABI ou inventário CRT/fonte correspondente inadequados impedem a entrega daquele pacote. Não trocar pin, licença ou patchset automaticamente. Aviso conhecido não prova exposição; ausência observada de caminho não é garantia de segurança global.
- CI remoto não será disparado, e falta de Windows 11/Ubuntu 24 nativo não será preenchida por outro ambiente. Enquanto a qualificação faltar, reportar o requisito sem evidência de execução; continuar somente trabalho independente autorizado.

## Dependencies

Os tools são meios dos planos. Cards de projeto: [2301 CMake/CTest](../../tools/2301/r1-cmake-ctest-build.md), [2302 Google Test](../../tools/2302/r1-googletest-runner.md), [2303 Qt Test](../../tools/2303/r1-qttest-runner.md), [2304 CI/GitHub](../../tools/2304/r1-github-actions.md), [2305 compiladores](../../tools/2305/r1-native-compilers.md) e [2306 r2 aquisição/deploy](../../tools/2306/r2-qt-dependency-acquisition-and-deployment.md). O r2 de 2306 é draft e precisa ser aprovado junto do plano; o r1 permanece preservado. Ele descreve as operações que serão executadas sem presumir instalação por metadata.

| Dependência | Seleção e acesso | Efeito/configuração |
|---|---|---|
| CMake/CTest/CPack e Ninja | CMake>=3.28, Ninja, versões efetivas registradas | Configure/build/staging/download por chamadas explícitas; reusar ambiente qualificado ou retornar falta. Não instalar globalmente por este texto. |
| Boost | 1.86.0, arquivo público boost_1_86_0.tar.bz2, SHA256 1bed88e40401b2cb7a1f76d4bab499e352fa4d0c5f31c0dbae64e24d34d7513b | Header-only, CESEB_BOOST_ROOT=build/dependencies/boost_1_86_0; cpp_int/cpp_rational e decimal 50 só para projeções. |
| Google Test | 1.17.0, commit 52eb8108c5bdec04579160ae17225d66034bd723 de https://github.com/google/googletest.git | Obter checkout exato no cache sem prompt/credencial nova; compilar no mesmo runtime em googletest-build e instalar em build/dependencies/install; testar tag/commit antes do uso. |
| Qt SDK | 6.12.0-0-202609280346, pacotes oficiais Windows MSVC 2022 x64 e Linux GCC 64 | Aquisição pública HTTPS por arquivos/digests oficiais, sem aqtinstall/novo instalador/conta; somente os subconjuntos da tabela abaixo. Prefixos `Qt/6.12.0/msvc2022_64` ou `Qt/6.12.0/gcc_64`. Qualificação nativa ainda obrigatória. |
| Compiladores/SDK | MSVC 2022/v143 no prompt nativo; GCC 13 Ubuntu 24.04 | Observar edição/versão/SDK e reutilizar. Provisão de máquina/toolchain privilegiada depende do ambiente e sua autoridade. Não adquirir licença paga. |
| Ações CI | checkout v7.0.1 SHA 3d3c42e5aac5ba805825da76410c181273ba90b1; upload-artifact v7.0.2 SHA cf430e030ddbb5b0abf93d22962f4752f3646cd9 | action.yml dos dois pins usa node 24; jobs hosted windows-2022/ubuntu-24.04. Somente arquivo de workflow; disparo remoto é efeito separado. |

SDK archives a registrar integralmente no lockfile, com URL e SHA256 vindos de metadata/digest oficiais lidos em 26/10/2026:

| Alvo | Arquivo após o prefixo de versão 6.12.0-0-202609280346 | SHA256 |
|---|---|---|
| Windows | `qtbase-Windows-Windows_11_24H2-MSVC2022-Windows-Windows_11_24H2-X86_64.7z` | `219d1b86def3be418e31d704572bc4acc91b2ec373c65595c9fb12b42bf098dc` |
| Linux | `qtbase-Linux-RHEL_9_6-GCC-Linux-RHEL_9_6-X86_64.7z` | `943023b929d0c08eafe7341700b5ed7601284410b7afd6093f950be291d1d7cd` |
| Linux | `icu-linux-Rhel8.6-x86_64.7z` | `1fdbcd67b1760f3a3f031c64637a9f19992aed2f35aa615e12a468f8c655d4da` |

URLs completas e unidades de leitura estão em qt-acquisition-pins.json. A ferramenta windeployqt pertence a QtBase na tag v6.12.0; QtTools não é selecionado. A localização e o CMakeLists do tool estão registrados em deployment-tool-source-location.json e windeployqt-tagged-build.txt. QtBase traz os módulos Core/Gui/Widgets/Test selecionados; a inspeção das dependências do executável/tooling verifica a necessidade real antes de ampliar o subconjunto. Se faltar componente necessário, registrar a condição e reconciliar explicitamente o inventário, sem baixar a coleção inteira por conveniência. Não foi lido/executado o payload do kit nesta preparação.

CLI proposta de aquisição: `cmake -DCESEB_DEPS_ROOT=build/dependencies -DCESEB_DEPS_PLATFORM=linux -DCESEB_ACQUIRE_QT=ON -P cmake/AcquireDependencies.cmake`; platform também aceita windows, outros valores falham. Downloads em build/dependencies/downloads; origens, hashes e extrações em acquisition-manifest.json. O lockfile é lido pelo script em CMAKE_CURRENT_LIST_DIR. Builds nativos exportados usam um CESEB_DEPS_ROOT absoluto fora da fonte imutável. O script não assume que SHA calculado depois do download, sozinho, autentica origem: compara o esperado do lock antes de extrair. Requisições HTTPS sempre TLS_VERIFY ON e NETRC IGNORED; falha de rede/hash interrompe a etapa. Nenhum pacote global, conta ou termo é configurado automaticamente.

Cards mecânicos locais do Mikoshi lidos para esta preparação: plan 4189 r2 (`/mnt/c/Users/paulo/.codex/plugins/cache/exalor-labs/mikoshi/3.0.0/resources/brain/tools/4189/r2-plan-tool.md`), trace 4196 r3 (`/mnt/c/Users/paulo/.codex/plugins/cache/exalor-labs/mikoshi/3.0.0/resources/brain/tools/4196/r3-trace-tool.md`), commit-check 4188 r2 (`/mnt/c/Users/paulo/.codex/plugins/cache/exalor-labs/mikoshi/3.0.0/resources/brain/tools/4188/r2-plan-commit-check-tool.md`), Git 2570 r8 (`/mnt/c/Users/paulo/.codex/plugins/cache/exalor-labs/mikoshi/3.0.0/resources/brain/tools/2570/r8-git-tool.md`) e artifact-check 2521 r9 (`/mnt/c/Users/paulo/.codex/plugins/cache/exalor-labs/mikoshi/3.0.0/resources/brain/tools/2521/r9-artifact-check-tool.md`). Os links apontam o cache desta sessão, não arquivos fictícios versionados no produto. Instalação/update do plugin, DVC remoto e GitHub sync não fazem parte de 2002.

## Execution Record

Retornar a execução em `.mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/execution.md`, report separado que cita este plano 2002 r1, autoridade exata e ROOT. Usar a declaração mikoshi-result-v1 aplicável com BASE_IMPL, IMPLEMENTATION_HEAD reais, tarefas, comandos, observações, operações de arquivo, resultados e gaps. Registrar também TEST_ASSETS_HEAD, SHA/hash dos exports e pacotes, ambiente por plataforma e caminho das evidências. Não escrever resultados nesta revisão depois de publicada.

Antes do gate, a preparação retorna em [1031](../../documents/1031/r1-implementation-planning-return.md). A avaliação estrutural do plano não é execução, commit coverage ou verdict de requisito. A aprovação posterior deverá cobrir este corpo, contrato 1030 e card 2306 r2 e os efeitos locais declarados. Aprovação de fontes do design não é aprovação de um plano ainda draft. O próximo papel é o orquestrador para integrar o plano 2001 e apresentar os dois planos concretos ao humano.
