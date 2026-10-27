---
id: 2001
revision: 1
type: plan
tags:
- mortgage
- test-plan
- verification
- cross-platform
status: partial implemented
created: '2026-10-26'
updated: 2026-10-26
description: Plano de testes dos 25 requisitos, com fixtures independentes, tentativa no base
  greenfield e verificação final Windows/Linux após a implementação.
use_when:
- Preparar e executar, após aprovação, os testes financeiros, de interface e de entrega da calculadora,
  preservando oráculos e autoria distinta da implementação.
---
# Plano de testes dos requisitos do Projeto 1

## Context

Autor e executor previsto: **dev-test-planning**, handle nativo `/root/test_planning`; qualquer reassignment exige a autoridade aplicável. Dev de implementação distinto: `/root/implementation_planning`, plano 2002. Autoria e Git em `/home/paulo/ceseb`, na sessão explícita 1-mortgage-desktop. A [aprovação 1028](../../documents/1028/r1-revisions-approval-and-planning-authority.md) aceita as specs r2 e autoriza preparar este corpo. **Este plano permanece draft e não foi executado.** Os termos históricos “proposta/open/draft” dos corpos de design são reconciliados pela aprovação 1028, sem reescrever suas fontes.

Baseline observada de autoria: `0bbd2854703444a27ce04600f5e227e0351f61bc`. Os inputs aprovados locais ainda não pertencem a esse commit. A execução futura captura TEST_BASE imediatamente antes do primeiro arquivo do plano; TEST_ASSETS_HEAD é o commit real desses arquivos antes de implementação; IMPLEMENTATION_HEAD é o snapshot real de produto usado na verificação final. O primeiro hash não é tratado como BASE/resultado futuro por suposição. Os hashes dos inputs são preservados no [manifesto de leitura](../../evidence/test-planning/source-read-manifest.json).

## Goals

Criar os testes independentes dos 25 requisitos e entregar seus arquivos e tentativa no base antes de qualquer mudança de produto. Depois do retorno da implementação, executar os mesmos testes, demonstrações e inspeções no alvo certo, com fixtures determinísticas e resultados por requisito/plataforma. Distinguir erro de ambiente/coleta, falha comportamental e caso já passando; não atribuir requirement pass por autoria do teste ou sucesso de check documental.

## Non-Goals

Não alterar modelo, oráculos, specs/requisitos publicados ou código de produto. Não fabricar core/stub para produzir RED. Não instalar dependências nesta preparação; a aprovação futura deste plano deve nomear os efeitos de preparação da seção Dependencies. Não criar conta, adquirir licença, mudar configuração global, provisionar máquina paga, disparar CI, fazer push/PR/merge/release ou promover conhecimento. Instalação dos pacotes nos ambientes limpos é parte do teste futuro, somente nas áreas/máquinas designadas. Desktop indisponível é lacuna, sem substituir a plataforma por CI/WSL/offscreen.

## Reference-only Inputs

- [Necessidade original 1001](../../documents/1001/r1-human-request.md) e [aceite 1028](../../documents/1028/r1-revisions-approval-and-planning-authority.md).
- Specs [1008 r2](../../specs/1008/r2-annual-rate-conversion.md), [1012 r2](../../specs/1012/r2-amortization-comparison.md), [1013 r2](../../specs/1013/r2-widgets-interface.md), [1014 r2](../../specs/1014/r2-reproducible-delivery.md).
- Os 25 requisitos r1 são linkados individualmente em suas tarefas. [1023](../../documents/1023/r1-numerical-resolution.md) justifica o método exato e seu limite de desempenho; [1024](../../documents/1024/r1-qt-baseline-review.md) conserva versão, acesso, avisos e limites do Qt.
- Decisões [1025](../../decisions/1025/r1-exact-rounding-method.md), [1026](../../decisions/1026/r1-qt-baseline-choice.md), [1027](../../decisions/1027/r1-research-design-integration.md).
- [Contrato conjunto 1030](../../documents/1030/r1-test-interface-and-fixtures.md), acordado com o dev de implementação; [plano 2002](../2002/r1-product-implementation-plan.md), input para sequência e outputs, não para derivar os valores esperados.
- Headers/livros/controlador e todos os arquivos de produto previstos em 2002 são somente consumidos pelo plano 2001. O dev de testes não os corrige. Fontes de tool/dependência e outputs gerados de build/staging também não se tornam arquivos autorais artificiais do taskmap.

## File Structure

Todos os arquivos a seguir serão **create** pelo dev-test-planning na execução aprovada. Cada asset autoral recebe `SPDX-License-Identifier: MIT` e o copyright aplicável de 2026 paulo-vitor-cs, sem atribuir MIT às dependências. A tarefa I-1228 cria o texto de licença original; o dev de implementação não altera os testes posteriormente. Repetições de um arquivo novo entre tarefas significam coautoria incremental no mesmo conjunto antes do commit, não transições create/modify contraditórias. Nenhum arquivo será renomeado ou apagado. Se já existir arquivo não previsto na execução, comparar ownership/bytes antes de qualquer gravação; reconciliar o plano em vez de sobrescrever trabalho alheio.

| Operation | Path | Owner |
|---|---|---|
| create | `tests/CMakeLists.txt` | dev-test-planning |
| create | `tests/domain/req1101_rate_kind_test.cpp` | dev-test-planning |
| create | `tests/domain/req1102_nominal_monthly_test.cpp` | dev-test-planning |
| create | `tests/domain/req1103_effective_monthly_test.cpp` | dev-test-planning |
| create | `tests/domain/req1104_annual_equivalents_test.cpp` | dev-test-planning |
| create | `tests/domain/req1105_invalid_rate_test.cpp` | dev-test-planning |
| create | `tests/domain/req1106_exact_rate_transport_test.cpp` | dev-test-planning |
| create | `tests/domain/req1201_loan_domain_test.cpp` | dev-test-planning |
| create | `tests/domain/req1202_price_ledger_test.cpp` | dev-test-planning |
| create | `tests/domain/req1203_sac_ledger_test.cpp` | dev-test-planning |
| create | `tests/domain/req1204_money_invariants_test.cpp` | dev-test-planning |
| create | `tests/domain/req1205_zero_single_ties_test.cpp` | dev-test-planning |
| create | `tests/domain/req1206_cent_admissibility_test.cpp` | dev-test-planning |
| create | `tests/domain/req1207_comparison_test.cpp` | dev-test-planning |
| create | `tests/gui/gui_test_main.cpp` | dev-test-planning |
| create | `tests/gui/gui_tests.hpp` | dev-test-planning |
| create | `tests/gui/req1211_localized_input_test.cpp` | dev-test-planning |
| create | `tests/gui/req1212_rate_presentation_test.cpp` | dev-test-planning |
| create | `tests/gui/req1213_comparison_presentation_test.cpp` | dev-test-planning |
| create | `tests/gui/req1214_state_recovery_test.cpp` | dev-test-planning |
| create | `tests/support/financial_fixtures.hpp` | dev-test-planning |
| create | `tests/system/check_core_independence.cmake` | dev-test-planning |

Tarefas de demonstração/inspeção têm tabelas Files vazias porque não alteram fontes versionáveis. Capturas, XML, logs, extração, instalação e relatórios de execução são saídas operacionais declaradas na verificação; não justificam commits de arquivos artificiais.

## Tasks

Cada tarefa tem exatamente um requisito r1. Sua obrigação usa a spec r2 aprovada mesmo quando o texto histórico do requisito mantém um link r1. A fase A escreve os assets de todas as tarefas com arquivos, então tenta o base e os entrega. A fase B verifica os casos contra o produto/pacote real. Não há dependência circular que exija `implemented` de 2001 antes de 2002: somente o **retorno da fase A** precede qualquer mudança de produto. As tarefas de inspeção/nativas dependem do pacote e das evidências retornados por 2002. O relatório identifica qual parte de cada tarefa foi efetivamente cumprida.

### Task T1221

**Assunto:** Preparar harness e verificar o núcleo sem Qt.

Requirement: [1221 r1](../../requirements/1221/r1-build-contract.md)
Kind: test
Method: Teste de integração e inspeção das interfaces/dependências; CMake standalone ou como subdiretório real.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/CMakeLists.txt | - |
| create | tests/system/check_core_independence.cmake | - |

**Preparação e fixtures:** Mesma revisão em Ubuntu 24.04/GCC 13 e Windows 11/MSVC 2022; Qt indisponível para descoberta; C++20 e Boost/GTest qualificados.

**Estímulo/procedimento:** Criar somente o harness e o script de inspeção. Na fase A, tentar a configuração standalone antes de qualquer produto. Na fase B, configurar outro build com CESEB_BUILD_GUI=OFF, CESEB_BUILD_TESTS=ON e CMAKE_DISABLE_FIND_PACKAGE_Qt6=TRUE; compilar e consumir o núcleo com os testes de conversão/amortização. Ler as interfaces e ligação para confirmar ausência de QString/QObject/QWidget e dependências Qt.

**Observável e oráculo:** Sem Qt instalado ou inicializado, o core e casos financeiros compilam e executam nos dois ambientes sobre a mesma revisão. Falta de produto no primeiro base é UNAVAILABLE de configuração/coleta. Scanner textual apoia a inspeção e não substitui o build/consumo.

**Implementação incorreta discriminada:** Um CMake que chama find_package(Qt6) antes da condição de GUI ou um header financeiro que inclui QObject.

**Comando ou interação:** `cmake -DCESEB_SOURCE_ROOT=/home/paulo/ceseb -DCESEB_BINARY_ROOT=/home/paulo/ceseb/build/core-isolation -DCESEB_BOOST_ROOT=/home/paulo/ceseb/build/dependencies/boost_1_86_0 -DCESEB_GTEST_PREFIX=/home/paulo/ceseb/build/dependencies/install -DCESEB_CXX_COMPILER=g++-13 -P tests/system/check_core_independence.cmake`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1101

**Assunto:** Distinguir convenção anual explícita.

Requirement: [1101 r1](../../requirements/1101/r1-explicit-rate-kind.md)
Kind: test
Method: Teste unitário do normalizador.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/domain/req1101_rate_kind_test.cpp | - |
| create | tests/support/financial_fixtures.hpp | - |

**Preparação e fixtures:** 12% com os dois enums; std::nullopt; valor de enum desconhecido por static_cast.

**Estímulo/procedimento:** Chamar normalize e project_rates para os tipos válidos; chamar normalize com tipos inválidos.

**Observável e oráculo:** Nominal mensal 0,01 e efetiva mensal 0,009488792934582974126355069193493956, erro absoluto <=1e-12. Tipo ausente/desconhecido: somente InvalidRateKind.

**Implementação incorreta discriminada:** Ignorar o enum e usar sempre percent/1200.

**Comando ou interação:** `build/linux-release/bin/ceseb_domain_tests --gtest_filter='Req1101.*' --gtest_output=xml:out/test-evidence/linux/req1101.xml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1102

**Assunto:** Converter nominal proporcional.

Requirement: [1102 r1](../../requirements/1102/r1-nominal-monthly.md)
Kind: test
Method: Teste unitário com referências fracionárias independentes.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/domain/req1102_nominal_monthly_test.cpp | - |
| create | tests/support/financial_fixtures.hpp | - |

**Preparação e fixtures:** Nominais 0; 4,5; 12; 100, escritos no core como 0, 4.5, 12, 100.

**Estímulo/procedimento:** Normalizar e ler a projeção mensal, sem passar pelo formatter da UI; observar também RationalGrowth.

**Observável e oráculo:** 0 exato; 0,00375; 0,01; 1/12, tolerância absoluta de projeção <=1e-12. Crescimento nominal conserva a fração exata; nenhuma tolerância monetária é aplicada.

**Implementação incorreta discriminada:** Dividir por 12 sem converter percentual ou dividir por 100 duas vezes.

**Comando ou interação:** `build/linux-release/bin/ceseb_domain_tests --gtest_filter='Req1102.*' --gtest_output=xml:out/test-evidence/linux/req1102.xml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1103

**Assunto:** Converter efetiva composta.

Requirement: [1103 r1](../../requirements/1103/r1-effective-monthly.md)
Kind: test
Method: Teste unitário da conversão composta.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/domain/req1103_effective_monthly_test.cpp | - |
| create | tests/support/financial_fixtures.hpp | - |

**Preparação e fixtures:** Efetivas anuais 0; 4,5; 12; acrescentar p=0,000000000000000000000001 no domínio tipado como exercício de taxa pequena, sem impor resultado textual da GUI.

**Estímulo/procedimento:** Normalizar e projetar; para o caso pequeno conservar a origem exata positiva e registrar seu comportamento, sem arredondar entrada para zero.

**Observável e oráculo:** 0 exato; 4,5% -> 0,003674809400436766676274626791736065 e 12% -> 0,009488792934582974126355069193493956, erro <=1e-12. A recomposição é apoio, não o único oráculo.

**Implementação incorreta discriminada:** Usar p/1200 para a entrada efetiva e depois validar apenas uma recomposição aproximada de sua própria saída.

**Comando ou interação:** `build/linux-release/bin/ceseb_domain_tests --gtest_filter='Req1103.*' --gtest_output=xml:out/test-evidence/linux/req1103.xml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1104

**Assunto:** Conferir equivalentes anuais.

Requirement: [1104 r1](../../requirements/1104/r1-annual-equivalents.md)
Kind: test
Method: Teste unitário de N/E com escala e tolerância explícitas.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/domain/req1104_annual_equivalents_test.cpp | - |
| create | tests/support/financial_fixtures.hpp | - |

**Preparação e fixtures:** Nominal 12%, efetiva 12%, zero em ambos os tipos e nominal 100%.

**Estímulo/procedimento:** Obter project_rates após normalize e comparar N e E com constantes literais ou referência racional independente no caso do teto.

**Observável e oráculo:** Nominal 12: N=12, E=12,682503013196972066120100. Efetiva 12: N=11,386551521499568951626083032192747, E=12. Zero exato; erro anual <=1e-9 ponto percentual. E de nominal 100 segue 100*((13/12)^12-1), acima de 100, sem cap.

**Implementação incorreta discriminada:** Confundir fração e percentual ou limitar uma saída anual válida a 100.

**Comando ou interação:** `build/linux-release/bin/ceseb_domain_tests --gtest_filter='Req1104.*' --gtest_output=xml:out/test-evidence/linux/req1104.xml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1105

**Assunto:** Rejeitar taxa inválida.

Requirement: [1105 r1](../../requirements/1105/r1-invalid-rate-input.md)
Kind: test
Method: Teste unitário da fronteira de construção/normalização.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/domain/req1105_invalid_rate_test.cpp | - |
| create | tests/support/financial_fixtures.hpp | - |

**Preparação e fixtures:** Para cada tipo: NaN, Infinity, -Infinity, -0.01, 0, 100 e 100.01 no percent canônico.

**Estímulo/procedimento:** Solicitar normalize e inspecionar a alternativa de Result antes de ler qualquer valor.

**Observável e oráculo:** Não finitos -> NonFiniteRate; negativos e >100 -> RateOutOfRange; 0 e 100 têm sucesso finito. Nunca coexistem erro e NormalizedRate.

**Implementação incorreta discriminada:** Converter falha de parse em zero ou rejeitar indevidamente as fronteiras inclusivas.

**Comando ou interação:** `build/linux-release/bin/ceseb_domain_tests --gtest_filter='Req1105.*' --gtest_output=xml:out/test-evidence/linux/req1105.xml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1106

**Assunto:** Conservar descritor exato entre módulos.

Requirement: [1106 r1](../../requirements/1106/r1-unrounded-consumer-rate.md)
Kind: test
Method: Teste de integração normalizador/consumidor e inspeção dirigida do caminho de dados.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/domain/req1106_exact_rate_transport_test.cpp | - |
| create | tests/support/financial_fixtures.hpp | - |

**Preparação e fixtures:** Efetiva 12% com projeções formatadas em 0,9489% e 0,948879%; nominal 100%, principal 6 centavos e n=1.

**Estímulo/procedimento:** Guardar o descritor original, criar apresentações de apoio com quatro/seis casas e calcular com o mesmo descritor. Inspecionar que compare fornece a origem exata aos dois livros e não reconstrói m de string da UI/projeção.

**Observável e oráculo:** Efetiva conserva kind/p=12 e g=1,12; projeção mensal dentro de 1e-12. Formatação não altera os inteiros dos livros. Nominal 100 conserva m=1/12 e cobra 1 centavo de juros em ambos os livros.

**Implementação incorreta discriminada:** Usar um double de projeção ou fazer parsing do label mensal antes do cálculo.

**Comando ou interação:** `build/linux-release/bin/ceseb_domain_tests --gtest_filter='Req1106.*' --gtest_output=xml:out/test-evidence/linux/req1106.xml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1201

**Assunto:** Validar domínio e prioridade.

Requirement: [1201 r1](../../requirements/1201/r1-loan-domain.md)
Kind: test
Method: Teste unitário da validação de compare.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/domain/req1201_loan_domain_test.cpp | - |
| create | tests/support/financial_fixtures.hpp | - |

**Preparação e fixtures:** C=0/1/10.000.000.000/10.000.000.001 centavos; n=0/1/600/601; taxa zero e múltiplos erros combinados.

**Estímulo/procedimento:** Chamar compare para fronteiras e combinações; conferir que a validação não expõe livros parciais.

**Observável e oráculo:** Principal inválido -> PrincipalOutOfRange; principal válido e taxa inválida precede TermOutOfRange; prazo inválido -> TermOutOfRange; só então admissibilidade de centavos. C=1,n=1 e C=max,n=1/600 passam as fronteiras de domínio.

**Implementação incorreta discriminada:** Validar prazo antes de taxa ou aceitar C=0.

**Comando ou interação:** `build/linux-release/bin/ceseb_domain_tests --gtest_filter='Req1201.*' --gtest_output=xml:out/test-evidence/linux/req1201.xml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1202

**Assunto:** Verificar livro Price e raiz irracional.

Requirement: [1202 r1](../../requirements/1202/r1-price-ledger.md)
Kind: test
Method: Teste unitário do livro Price com m já normalizado; casos completos e fronteiras de anuidade.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/domain/req1202_price_ledger_test.cpp | - |
| create | tests/support/financial_fixtures.hpp | - |

**Preparação e fixtures:** C=100.000, nominal 12%, n=3; C=100.000, zero, n=600; C=3, zero, n=2; C=100.000, efetiva 12%, n=3.

**Estímulo/procedimento:** Chamar calculate_price; comparar cada linha e resumo. Medir e registrar duração/memória disponível dos vetores de fronteira e GUI n=600 nas duas toolchains, sem inventar limiar de aprovação.

**Observável e oráculo:** Nominal: pagamentos [34002, 34002, 34003], juros [1000, 670, 337], saldos [66998, 33666, 0], total 102007 e juros 2007. Zero/600: parcela ordinária 167, última 134, quantidade 599 e total 100000. C=3/0/2: parcela ordinária 2 e pagamentos [2, 1]. Efetiva 12/3: parcela ordinária 33968 e pagamentos [33968, 33968, 33968]. Antes do limite usar min(a, B+I); ao final, B+I; não há linha após quitação.

**Implementação incorreta discriminada:** Forçar n linhas, repetir a parcela ordinária no último mês ou usar precisão fixa para aceitar um centavo Price ambíguo.

**Comando ou interação:** `build/linux-release/bin/ceseb_domain_tests --gtest_filter='Req1202.*' --gtest_output=xml:out/test-evidence/linux/req1202.xml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1203

**Assunto:** Verificar SAC e distribuição inicial.

Requirement: [1203 r1](../../requirements/1203/r1-sac-ledger.md)
Kind: test
Method: Teste unitário do livro SAC e juros exatos.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/domain/req1203_sac_ledger_test.cpp | - |
| create | tests/support/financial_fixtures.hpp | - |

**Preparação e fixtures:** C=100.000 centavos, nominal 12%, n=3; C=6, nominal 100%, n=1; C=100, n=1, nominais 5,999999% / 6% / 6,000001%; grade admissível definida na seção de cobertura.

**Estímulo/procedimento:** Chamar calculate_sac, comparar linhas normativas e depois q/r, quantidade e monotonicidade na grade.

**Observável e oráculo:** Amortizações [33334, 33333, 33333], juros [1000, 667, 333], pagamentos [34334, 34000, 33666], saldos [66666, 33333, 0], total 102000. C=6/100%/1: juros 1 e pagamento 7. Vizinhança de 6%: juros [0, 1, 1]. SAC tem n linhas, amortização q+(k<=r) e prestações não crescentes.

**Implementação incorreta discriminada:** Concentrar o resto no último mês ou aplicar ties-to-even ao juro.

**Comando ou interação:** `build/linux-release/bin/ceseb_domain_tests --gtest_filter='Req1203.*' --gtest_output=xml:out/test-evidence/linux/req1203.xml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1204

**Assunto:** Aplicar invariantes de conservação.

Requirement: [1204 r1](../../requirements/1204/r1-money-invariants.md)
Kind: test
Method: Teste unitário determinístico das identidades dos dois livros.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/domain/req1204_money_invariants_test.cpp | - |
| create | tests/support/financial_fixtures.hpp | - |

**Preparação e fixtures:** Todos os vetores normativos de 1012 r2, limites admissíveis e grade fixa de C/n/taxa. Casos rejeitados são contabilizados separadamente.

**Estímulo/procedimento:** Gerar a grade fixa sem semente aleatória, chamar os livros e somar com int64 verificado. Não usar as invariantes como substitutas dos oráculos literais de 1202/1203.

**Observável e oráculo:** Por linha: opening-closing=principal_paid; payment=principal_paid+interest; principal_paid>0; closing>=0. A soma das amortizações é C; o último saldo é zero; total=sum(payment)=C+sum(interest). Price tem de 1 a n pagamentos e SAC tem n, sem linhas depois da quitação.

**Implementação incorreta discriminada:** Produzir livros reconciliados mas cobrar juros errados; os vetores literais de 1202/1203 impedem que somente a conservação esconda esse erro.

**Comando ou interação:** `build/linux-release/bin/ceseb_domain_tests --gtest_filter='Req1204.*' --gtest_output=xml:out/test-evidence/linux/req1204.xml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1205

**Assunto:** Resolver zero, prazo único e empates.

Requirement: [1205 r1](../../requirements/1205/r1-zero-and-single-period.md)
Kind: test
Method: Teste unitário de singularidades com oráculos exatos.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/domain/req1205_zero_single_ties_test.cpp | - |
| create | tests/support/financial_fixtures.hpp | - |

**Preparação e fixtures:** C=120.000 centavos / taxa zero / 12 meses; C=100 / nominal 6% / 1 mês; C=6 / nominal 100% / 1 mês; C=100, n=1 com nominais 5,999999% / 6% / 6,000001%; efetiva p=100*((201/200)^12-1), construída como decimal finito exato por aritmética inteira na fixture.

**Estímulo/procedimento:** Executar os dois livros; construir a fixture da raiz racional sem double, preservando todas as casas do domínio tipado.

**Observável e oráculo:** Juros zero: 12 pagamentos de 10000, total 120000 e juros zero. C=100/6%/1: uma cobrança de 101 e juros 1. C=6/100%/1: uma cobrança de 7 e juros 1. Vizinhança: juros [0, 1, 1] e pagamentos [100, 101, 101]. Efetiva com raiz 201/200: juros 1 e pagamento 101, sem segunda cobrança.

**Implementação incorreta discriminada:** Resolver apenas a divisão terminante de 6%, mas errar o nominal recorrente 1/12 ou classificar uma raiz racional como irracional.

**Comando ou interação:** `build/linux-release/bin/ceseb_domain_tests --gtest_filter='Req1205.*' --gtest_output=xml:out/test-evidence/linux/req1205.xml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1206

**Assunto:** Rejeitar centavos inviáveis.

Requirement: [1206 r1](../../requirements/1206/r1-cent-precision-errors.md)
Kind: test
Method: Teste unitário de condições independentes de admissibilidade.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/domain/req1206_cent_admissibility_test.cpp | - |
| create | tests/support/financial_fixtures.hpp | - |

**Preparação e fixtures:** C=1 centavo, taxa zero, n=600; C=1200 centavos, nominal 100%, n=600.

**Estímulo/procedimento:** Executar compare e conferir a alternativa de erro e a ausência de qualquer Schedule/Comparison de sucesso.

**Observável e oráculo:** Ambos retornam UnsupportedCentPrecision. O primeiro isola C<n; o segundo tem parcela ordinária Price 100 e primeiro juro 100, apesar de C>=n.

**Implementação incorreta discriminada:** Verificar somente C<n ou entregar SAC válido quando Price falhou.

**Comando ou interação:** `build/linux-release/bin/ceseb_domain_tests --gtest_filter='Req1206.*' --gtest_output=xml:out/test-evidence/linux/req1206.xml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1207

**Assunto:** Comparar os dois sistemas com a mesma taxa.

Requirement: [1207 r1](../../requirements/1207/r1-comparable-results.md)
Kind: test
Method: Teste de integração e inspeção da chamada única de normalização.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/domain/req1207_comparison_test.cpp | - |
| create | tests/support/financial_fixtures.hpp | - |

**Preparação e fixtures:** C=100.000 centavos, n=3, nominal 12%; efetiva equivalente 12,682503013196972066120100%; efetiva 12% para distinguir convenções.

**Estímulo/procedimento:** Chamar compare, ler Comparison.rate e os livros, repetir somente a formatação. Inspecionar compare para confirmar uma normalização e o mesmo descritor a ambos os cálculos.

**Observável e oráculo:** Nominal 12%: juros Price 2007 e SAC 2000, diferença +7. A efetiva equivalente preserva esses livros neste vetor afastado de fronteiras. Efetiva 12% é distinta de nominal 12%. Formatar não muda os cálculos nem o sinal/unidade da diferença.

**Implementação incorreta discriminada:** Normalizar separadamente com convenções divergentes ou usar abs(Price-SAC).

**Comando ou interação:** `build/linux-release/bin/ceseb_domain_tests --gtest_filter='Req1207.*' --gtest_output=xml:out/test-evidence/linux/req1207.xml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1211

**Assunto:** Verificar parsing pt-BR.

Requirement: [1211 r1](../../requirements/1211/r1-localized-input.md)
Kind: test
Method: Teste de integração QtTest entre texto, MoneyCodec/controlador e LoanInput.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/gui/req1211_localized_input_test.cpp | - |
| create | tests/gui/gui_tests.hpp | - |
| create | tests/gui/gui_test_main.cpp | - |

**Preparação e fixtures:** Principal 100.000,00 e 100000,00; inválidos 1,000 / 1,234.56 / 1e3 / vazio / agrupamento 12.34,56; taxa 4,5 / 4.5 / 4,123456 / 4,1234567; prazo 360 / 0 / 3,5; espaços externos e ambos os tipos.

**Estímulo/procedimento:** Verificar diretamente os resultados tipados de MoneyCodec, preencher MainWindow e calcular com o core real. Inspecionar a montagem de LoanInput no controlador para confirmar principal, prazo, percentual exato e convenção, sem adicionar spy ou substituir a função financeira neste caso. Testar falhas sem truncamento.

**Observável e oráculo:** Os principais válidos geram 10000000 centavos; formatos inválidos são rejeitados. Taxa 4,5 gera percent canônico 4.5; 4.5 é inválida no formulário. Seis casas são aceitas e a sétima é recusada. Prazo 360 é inteiro; zero e fração são inválidos. A convenção é mantida e somente espaços externos são removidos.

**Implementação incorreta discriminada:** Aceitar gramática permissiva QDoubleValidator, agrupamento mal colocado ou interpretar ponto inglês como outro valor.

**Comando ou interação:** `build/linux-release/bin/ceseb_gui_tests req1211_localized_input -o out/test-evidence/linux/req1211.xml,junitxml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1212

**Assunto:** Verificar labels e empate half-up.

Requirement: [1212 r1](../../requirements/1212/r1-rate-presentation.md)
Kind: test
Method: Teste de integração dos inteiros quantizados e labels reais; fixture racional isolada.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/gui/req1212_rate_presentation_test.cpp | - |
| create | tests/gui/gui_tests.hpp | - |

**Preparação e fixtures:** C=100.000 centavos, n=3, nominal 12% / efetiva 12% / nominal 100%; nominais 0,000005% / 0,000006% / 0,000007%; percentual isolado 0,0000005%.

**Estímulo/procedimento:** Usar core real na janela, calcular, ler os três labels; comparar quantize_rates com inteiros esperados. Chamar quantize_percent para a fixture isolada, depois format_percent.

**Observável e oráculo:** Nominal 12%: labels 1,000000%; 12,000000%; 12,682503%. Efetiva 12%: 0,948879%; 11,386552%; 12,000000%. Nominal 100% mostra E acima de 100%. A vizinhança mensal mostra 0,000000% / 0,000001% / 0,000001%; a fixture isolada mostra 0,000001%. Tipo e período são explícitos, sem retorno do label ao cálculo.

**Implementação incorreta discriminada:** Usar empate para par do formatter ou limitar a saída anual derivada a 100%.

**Comando ou interação:** `build/linux-release/bin/ceseb_gui_tests req1212_rate_presentation -o out/test-evidence/linux/req1212.xml,junitxml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1213

**Assunto:** Verificar cartões, quitação e contagens.

Requirement: [1213 r1](../../requirements/1213/r1-comparison-presentation.md)
Kind: test
Method: Teste de sistema pela janela real vinculada ao core e confirmação visual no pacote final.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/gui/req1213_comparison_presentation_test.cpp | - |
| create | tests/gui/gui_tests.hpp | - |

**Preparação e fixtures:** R$ 1.000,00 / nominal 12% / 3 meses; R$ 1.000,00 / taxa zero / 600 meses; prazo de 1 mês.

**Estímulo/procedimento:** Preencher os controles, clicar Calcular e ler todos os labels; após pacote repetir visualmente as entradas.

**Observável e oráculo:** Primeiro caso: Price mostra R$ 340,02 / 340,03 / 1.020,07 / 20,07 e SAC mostra R$ 343,34 / 336,66 / 1.020,00 / 20,00. Ambos mostram 3 pagamentos e diferença +R$ 0,07. Zero/600: Price mostra 599 pagamentos, última R$ 1,34 e aviso de quitação em 599 de 600; SAC mostra 600 e última R$ 1,66. Parcela final ajustada é identificada; prazo 1 identifica uma única cobrança.

**Implementação incorreta discriminada:** Reutilizar prazo solicitado como contagem efetiva ou esconder ajuste final.

**Comando ou interação:** `build/linux-release/bin/ceseb_gui_tests req1213_comparison_presentation -o out/test-evidence/linux/req1213.xml,junitxml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1214

**Assunto:** Verificar edição, erros e recuperação.

Requirement: [1214 r1](../../requirements/1214/r1-ui-state-recovery.md)
Kind: test
Method: Teste de integração QtTest com core real e resposta controlada só para ArithmeticError.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/gui/req1214_state_recovery_test.cpp | - |
| create | tests/gui/gui_tests.hpp | - |

**Preparação e fixtures:** Resultado R$ 1.000,00 / nominal 12% / 3 meses; edição separada de cada campo e tipo; múltiplos erros; R$ 0,01 / zero / 600; callback que retorna ArithmeticError.

**Estímulo/procedimento:** Gerar resultado, editar, observar limpeza imediata. Calcular entradas inválidas, conferir prioridade, texto e foco. Corrigir/recalcular/Limpar. Uma janela separada injeta somente Error{ArithmeticError} no seam documentado.

**Observável e oráculo:** Editar apaga todos os cartões, equivalências e diferença. O erro preserva entradas e apaga resultados. Foco em principal/taxa/tipo/prazo conforme o código; admissibilidade foca principal; ArithmeticError aparece na área geral e foca Calcular. Corrigir recupera o cálculo. Limpar esvazia campos e resultados, restaura nominal e foca principal. A mensagem não exibe traceback ou caminho interno.

**Implementação incorreta discriminada:** Manter resultado antigo visível, deixar metade da comparação ou mascarar erro como zero.

**Comando ou interação:** `build/linux-release/bin/ceseb_gui_tests req1214_state_recovery -o out/test-evidence/linux/req1214.xml,junitxml`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1215

**Assunto:** Demonstrar teclado nos desktops.

Requirement: [1215 r1](../../requirements/1215/r1-keyboard-navigation.md)
Kind: test
Method: Demonstração nativa, sem mudança de fonte ou arquivo versionável.

#### Files

| Operation | Path | Destination |
|---|---|---|

Sem mudança de arquivo de fonte versionável planejada. A tabela vazia não autoriza editar entregáveis; outputs de teste são registrados separadamente.

**Preparação e fixtures:** Pacote 0.1.0 em Windows 11 x64 e Ubuntu 24.04 desktop; cenário R$ 1.000,00 / nominal 12% / 3 meses, incluindo erro e recuperação.

**Estímulo/procedimento:** Usar somente teclado: Tab principal→taxa→tipo→prazo→Calcular→Limpar→Sobre; Shift+Tab na ordem inversa; preencher, Enter, erro/correção, limpar, abrir/fechar ajuda e Escape na janela principal. Registrar foco e associações acessíveis.

**Observável e oráculo:** Todas as ações são realizadas sem mouse; foco visível; labels com buddy e nome acessível; Enter calcula e Escape fecha. Cada SO possui sua própria evidência.

**Implementação incorreta discriminada:** Passar eventos offscreen ou a ordem default do Qt como prova da demonstração nativa.

**Comando ou interação:** `Executar o lançamento N-WIN ou N-LINUX e a sequência descrita; capturas e log vinculam pacote/SHA/SO.`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1216

**Assunto:** Demonstrar layout nas quatro combinações.

Requirement: [1216 r1](../../requirements/1216/r1-resize-access.md)
Kind: test
Method: Demonstração nativa da janela renderizada, sem mudança de fonte ou arquivo versionável.

#### Files

| Operation | Path | Destination |
|---|---|---|

Sem mudança de arquivo de fonte versionável planejada. A tabela vazia não autoriza editar entregáveis; outputs de teste são registrados separadamente.

**Preparação e fixtures:** Windows 11 e Ubuntu 24.04; escalas 100% e 200%; janela 800x600 pixels lógicos; R$ 1.000,00 / zero / 600 meses, com aviso 599 de 600.

**Estímulo/procedimento:** Em cada combinação ajustar tamanho lógico, calcular e percorrer formulário/cartões/mensagens por teclado e rolagem. Registrar escala/DPR/tamanho lógico e captura do conteúdo longo.

**Observável e oráculo:** Todos os conteúdos são alcançáveis por rolagem vertical e teclado. O formulário não exige rolagem horizontal. Não há sobreposição bloqueante e os valores/avisos permitem ler o texto completo.

**Implementação incorreta discriminada:** Testar somente 1040x760, usar uma janela offscreen para provar a escala nativa ou capturar apenas o topo do formulário.

**Comando ou interação:** `Executar N-WIN/N-LINUX em sessões com as duas escalas registradas; redimensionar e demonstrar os critérios.`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1217

**Assunto:** Inspecionar ajuda offline.

Requirement: [1217 r1](../../requirements/1217/r1-model-help.md)
Kind: test
Method: Inspeção do pacote final, sem mudança de fonte ou arquivo versionável.

#### Files

| Operation | Path | Destination |
|---|---|---|

Sem mudança de arquivo de fonte versionável planejada. A tabela vazia não autoriza editar entregáveis; outputs de teste são registrados separadamente.

**Preparação e fixtures:** Rede já indisponível no ambiente limpo; conteúdo Sobre e modelo e arquivos locais de licenças.

**Estímulo/procedimento:** Abrir Sobre e modelo pelo teclado; ler todos os tópicos e seguir os links locais de licença. Usar uma sessão já offline, sem alterar firewall ou configuração global de rede.

**Observável e oráculo:** O conteúdo explica nominal/efetiva, Price/SAC, pagamentos postecipados e primeiro vencimento após um mês, centavos, ajuste final e contagem efetiva. Exclui seguros, tarifas, impostos e indexadores e explica que o total não é CET. Versão e licenças são acessíveis sem resposta remota.

**Implementação incorreta discriminada:** Abrir URL remota para ajuda/licença ou omitir as exclusões financeiras.

**Comando ou interação:** `Usar N-WIN/N-LINUX no ambiente offline e inspecionar Sobre e modelo; registrar cada tópico e caminho local recuperado.`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1225

**Assunto:** Verificar completude dos dois pacotes.

Requirement: [1225 r1](../../requirements/1225/r1-runtime-packages.md)
Kind: test
Method: Teste de sistema e inspeção dos pacotes em instalações limpas; nenhum arquivo de fonte versionável é alterado.

#### Files

| Operation | Path | Destination |
|---|---|---|

Sem mudança de arquivo de fonte versionável planejada. A tabela vazia não autoriza editar entregáveis; outputs de teste são registrados separadamente.

**Preparação e fixtures:** ZIP out/packages/ceseb-0.1.0-windows-x86_64.zip; DEB out/packages/ceseb_0.1.0_amd64.deb; ambientes sem Qt ou compilador de desenvolvimento configurados e com PATH limpo.

**Estímulo/procedimento:** Conferir pacote, manifesto, arquitetura e SHA; extrair ou instalar conforme N-WIN/N-LINUX e abrir. Conferir Qt privado, plugins, CRT, RPATH, dependências declaradas e atalho. As cópias/instalações são efeitos operacionais declarados, não arquivos autorais do taskmap.

**Observável e oráculo:** O ZIP traz aplicativo, DLLs, plugin de plataforma, CRT permitido e avisos. O DEB traz aplicativo, Qt privado, atalho e dependências declaradas, sem substituir Qt global. Ambos abrem sem toolchain de desenvolvimento e identificam versão, revisão e plataforma. Ausência de plugin ou biblioteca impede considerar o pacote utilizável.

**Implementação incorreta discriminada:** Deixar o PATH do desenvolvedor fornecer DLL faltante ou considerar windeployqt suficiente sem ensaio limpo.

**Comando ou interação:** `N-WIN/N-LINUX e comandos de inspeção I-PACKAGE; preservar hash e inventário, sem publicar artefato remoto.`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1226

**Assunto:** Demonstrar operação final em cada plataforma.

Requirement: [1226 r1](../../requirements/1226/r1-native-smoke.md)
Kind: test
Method: Demonstração nativa completa; sem mudança de fonte ou arquivo versionável.

#### Files

| Operation | Path | Destination |
|---|---|---|

Sem mudança de arquivo de fonte versionável planejada. A tabela vazia não autoriza editar entregáveis; outputs de teste são registrados separadamente.

**Preparação e fixtures:** Pacotes em Windows 11 x64 e Ubuntu 24.04 x64 limpos; R$ 1.000,00 / taxa anual 12% / 3 meses, usando nominal e efetiva.

**Estímulo/procedimento:** Abrir, calcular nominal, mudar para efetiva e observar a limpeza, recalcular, provocar erro/corrigir, limpar, navegar, redimensionar e fechar. Conservar captura visual e contexto.

**Observável e oráculo:** Nominal cumpre 1212/1213. Efetiva: mensal 0,948879%; Price ordinária e última R$ 339,68, total R$ 1.019,04 e juros R$ 19,04; SAC primeira R$ 342,83, última R$ 336,49, total R$ 1.018,98 e juros R$ 18,98; diferença R$ 0,06. Sem falha do aplicativo. O registro identifica SO, arquitetura, pacote, SHA, sequência, resultados e captura.

**Implementação incorreta discriminada:** Usar WindowsServerCI, WSL ou offscreen como se fossem os desktops declarados.

**Comando ou interação:** `Executar N-WIN e N-LINUX e a sequência completa; ausência de qualquer desktop permanece NOT EXECUTED/UNAVAILABLE para essa plataforma.`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1227

**Assunto:** Inspecionar documentação e rastreabilidade.

Requirement: [1227 r1](../../requirements/1227/r1-technical-documentation.md)
Kind: test
Method: Inspeção de entregáveis e evidência, sem mudança de fonte ou arquivo versionável.

#### Files

| Operation | Path | Destination |
|---|---|---|

Sem mudança de arquivo de fonte versionável planejada. A tabela vazia não autoriza editar entregáveis; outputs de teste são registrados separadamente.

**Preparação e fixtures:** README, manual, instruções de build, descrição do modelo, relatório técnico e evidências da revisão final dos mesmos pacotes; os 25 requisitos e os planos 2001/2002.

**Estímulo/procedimento:** Percorrer os tópicos, recuperar cada link e cada comando marcado verificado; confrontar seu SHA/ambiente/log. Checar que resultados negativos e casos não executados estão descritos.

**Observável e oráculo:** A documentação em português cobre instalação, uso, compilação e verificação nas duas plataformas, fórmulas, centavos, limites, exclusões, comparação, dependências e licenças. Cada requisito possui rota exata e resultado observado. Comandos verificados possuem registro e links recuperam o alvo. Uma lacuna permanece declarada.

**Implementação incorreta discriminada:** Documentar saída esperada como se fosse observada ou citar um log de outro commit/plataforma.

**Comando ou interação:** `I-DOC: ler os entregáveis enumerados no filemap de 2002 e confrontar cada alegação com os relatórios e evidências da mesma revisão/plataforma.`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

### Task T1228

**Assunto:** Inspecionar licenças, avisos e fontes.

Requirement: [1228 r1](../../requirements/1228/r1-distribution-notices.md)
Kind: test
Method: Inspeção do conteúdo efetivamente entregue, sem alteração de fonte ou arquivo versionável.

#### Files

| Operation | Path | Destination |
|---|---|---|

Sem mudança de arquivo de fonte versionável planejada. A tabela vazia não autoriza editar entregáveis; outputs de teste são registrados separadamente.

**Preparação e fixtures:** Pacotes e fontes reais; manifestos por componente; originais MIT, Qt 6.12.0, plugins e terceiros, CRT, Boost e GoogleTest conforme o conteúdo efetivamente distribuído.

**Estímulo/procedimento:** Comparar cada arquivo/material com o inventário. Recuperar textos, avisos e fonte correspondente exata, verificando identidade e patches. Conferir a possibilidade de substituição das bibliotecas dinâmicas com ABI compatível. Registrar edição/termos reais de MSVC e lista REDIST.

**Observável e oráculo:** MIT identifica somente os originais. Cada componente distribuído possui avisos e termos recuperáveis. Materiais Qt incluem textos GPLv3/LGPLv3 aplicáveis, fonte exata e modificações pertinentes, com substituição possível. Termos dos demais runtimes/terceiros são preservados. QtTest/GoogleTest não são alegados como conteúdo do aplicativo se não estiverem distribuídos.

**Implementação incorreta discriminada:** Rotular tudo MIT, listar fontes latest, copiar qualquer CRT ou omitir terceiros embutidos no Qt por não serem DLL separada.

**Comando ou interação:** `I-LICENSE: inspecionar LICENSE, THIRD_PARTY_NOTICES e manifesto/licenças/fontes do pacote previstos em 2002; registrar ausência sem declarar uma certificação jurídica geral.`

**Dependências e conclusão:** autoria dos assets depende do aceite deste plano e dos inputs preservados. A execução automática usa o harness e o ambiente da fase A/B. A confirmação final exige o alvo real e todas as observações desta tarefa. Guardar estímulo, seleção, resultado, retorno, revisão e plataforma; falha de coleta/ambiente permanece ausência de evidência comportamental.

## Verification

### Sequência de execução e preservação do base

**A0 — Autoridade e inventário.** Confirmar aprovação deste plano e de seus efeitos concretos. Registrar `git status --short`, `git rev-parse HEAD`, SO/arquitetura/toolchain e hashmanifest dos inputs. Preservar os arquivos locais existentes e o índice Git. O trabalho futuro pode usar o ramo local `codex/mortgage-desktop`; não criar outro checkout de autoria. Preparar/reutilizar o ambiente uma vez, conforme Dependencies. Ausência de acesso, kit, conta já autorizada ou desktop é registrada, sem instalação substituta silenciosa.

**A1 — Assets e tentativa real no base.** Capturar TEST_BASE antes da primeira criação. Escrever os arquivos exatamente do File Structure. Executar o harness standalone sobre a revisão existente antes de 2002 criar qualquer produto. Em um projeto sem CMake/header/core, o resultado esperado da tentativa é diagnóstico de configuração/coleta indisponível; **isso não é RED**. Não declarar comportamento inexistente como falha observada. Se algum teste já executar e passar no base, registrar esse fato. Entregar assets, seleção, resultados e TEST_ASSETS_HEAD ao orquestrador e ao dev implementação. Somente após esse retorno o dev produto altera seus arquivos.

**B1 — Produto e testes originais.** O plano 2002 parte do HEAD posterior ao retorno A1 e usa esses testes. Quando o dev implementação devolver IMPLEMENTATION_HEAD, confirmar que os assets têm os mesmos bytes do TEST_ASSETS_HEAD e que o input/oráculo não mudou. Coordenar a confirmação inicial de domínio/isolamento com a rota core-only de 2002 antes da aquisição Qt. Depois da aquisição e build GUI, reexecutar os casos pertinentes sobre a revisão de produto nas duas toolchains. Se o ambiente já tiver Qt, não declarar a condição sem Qt como observada. Erro em código de teste volta ao autor com evidência; qualquer mudança de corpo/oráculo aprovado exige a reconciliação aplicável. Capturar duração dos casos de fronteira e n=600 por ambiente; não se presume desempenho suficiente pela prova de terminação.

**B2 — Entrega nativa e inspeções.** Usar os pacotes identificados e executar T1215/T1216/T1217/T1225/T1226/T1227/T1228 nos ambientes declarados. A fase final não altera os assets já commitados. Não encerrar como procedimento completo quando a plataforma requerida estiver indisponível; registrar a parte cumprida e a lacuna. Resultados observados não equivalem ao verdict independente de requisito em Synapses.

### Comandos automáticos e seus efeitos

Os comandos a seguir são o procedimento futuro, não observações desta autoria. CWD Linux de autoria/teste: `/home/paulo/ceseb`; CWD Windows para invocação, em PowerShell herdando o ambiente x64 Native Tools 2022: `C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/source`, snapshot do Git HEAD real, não uma nova área de edição. Preencher variáveis CESEB com os prefixos qualificados na preparação, registrando seus valores sem credenciais. Diretórios `build/` e `out/` já são ignorados. Criar `out/test-evidence/linux` e `out/test-evidence/base` sob ROOT, e `C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/out/test-evidence/windows` no staging nativo, com `cmake -E make_directory` antes dos relatórios. No Windows, build, dependências, logs e staging ficam fora de `/source`; a fonte exportada permanece imutável.

A-BASE, após assets e antes de produto, no ROOT:

```text
cmake -S tests -B build/tests-base -G Ninja -DCMAKE_BUILD_TYPE=Release -DCESEB_SOURCE_ROOT=/home/paulo/ceseb -DCESEB_BUILD_GUI=OFF -DCESEB_BUILD_TESTS=ON -DCESEB_BOOST_ROOT=/home/paulo/ceseb/build/dependencies/boost_1_86_0 -DCMAKE_PREFIX_PATH=/home/paulo/ceseb/build/dependencies/install
cmake --build build/tests-base --parallel
ctest --test-dir build/tests-base -C Release --output-on-failure --no-tests=error --output-junit /home/paulo/ceseb/out/test-evidence/base/ctest.xml
```

Executar configure primeiro; só executar build/test se o estágio anterior permitir. Preservar o diagnóstico do estágio que falhou, sem chamar ausência de executável de teste funcional. No base inicial sem produto, não há promessa de executar os três comandos com sucesso.

B-LINUX, Ubuntu 24.04 x64 e GCC 13, CWD `/tmp/ceseb-native-1`, fonte do mesmo SHA exportado e prefixos autorizados. `CESEB_SOURCE_REVISION` recebe o SHA do manifesto; não fica vazio/unknown:

```text
cmake -S source -B build/linux-release -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=g++-13 -DCESEB_BUILD_GUI=ON -DCESEB_BUILD_TESTS=ON -DCESEB_BOOST_ROOT=/tmp/ceseb-native-1/build/dependencies/boost_1_86_0 '-DCMAKE_PREFIX_PATH=/tmp/ceseb-native-1/build/dependencies/Qt/6.12.0/gcc_64;/tmp/ceseb-native-1/build/dependencies/install' -DCESEB_SOURCE_REVISION="$CESEB_SOURCE_REVISION"
cmake --build build/linux-release --parallel
build/linux-release/bin/ceseb_domain_tests --gtest_list_tests
build/linux-release/bin/ceseb_gui_tests -functions
ctest --test-dir build/linux-release -C Release --output-on-failure --no-tests=error --output-junit /tmp/ceseb-native-1/out/test-evidence/linux/ctest.xml
```

As chamadas por tarefa selecionam `ReqNNNN.*` ou o slot Qt exato, nunca uma seleção vazia. O harness compara a lista esperada e a contagem observada; `--no-tests=error` do CTest não detecta sozinho um binário que internamente rodou zero casos. XML/JUnit guarda revisão/ambiente no relatório associado. Centavos, strings e inteiros quantizados usam igualdade; projeções de taxa usam comparações no domínio decimal com tolerâncias 1e-12/1e-9 e nunca EXPECT_NEAR convertido a double.

B-WINDOWS, x64 Native Tools Prompt 2022, mesmo snapshot exportado e PowerShell:

```text
cmake -S . -B C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/windows-release -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=cl -DCESEB_BUILD_GUI=ON -DCESEB_BUILD_TESTS=ON -DCESEB_SOURCE_REVISION="$env:CESEB_SOURCE_REVISION" -DCESEB_BOOST_ROOT="$env:CESEB_BOOST_ROOT" -DCMAKE_PREFIX_PATH="$env:CESEB_CMAKE_PREFIX_PATH"
cmake --build C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/windows-release --parallel
& C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/windows-release/bin/ceseb_domain_tests.exe --gtest_list_tests
& C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/windows-release/bin/ceseb_gui_tests.exe -functions
ctest --test-dir C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/windows-release -C Release --output-on-failure --no-tests=error --output-junit C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/out/test-evidence/windows/ctest.xml
```

Para cada tarefa, substituir somente o prefixo Linux do comando por `& C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/windows-release/bin/` e a extensão por `.exe`, conservar o filtro/oráculo e salvar em `out/test-evidence/windows/reqNNNN.xml`. Essa tradução é de comando por plataforma, não de fórmula/resultado. Registrar o caminho do staging, SHA de origem, manifesto e ferramentas efetivos. Os logs retornam à sessão principal com identidade da cópia; nenhum commit check usa um Git fictício no staging.

Q-CORE, no alvo Ubuntu 24.04, CWD `/tmp/ceseb-native-1`, e equivalente em staging Windows com seus prefixos:

```text
cmake -DCESEB_SOURCE_ROOT=/tmp/ceseb-native-1/source -DCESEB_BINARY_ROOT=/tmp/ceseb-native-1/build/core-isolation -DCESEB_BOOST_ROOT=/tmp/ceseb-native-1/build/dependencies/boost_1_86_0 -DCESEB_GTEST_PREFIX=/tmp/ceseb-native-1/build/dependencies/install -DCESEB_CXX_COMPILER=g++-13 -DCESEB_SOURCE_REVISION="$CESEB_SOURCE_REVISION" -P source/tests/system/check_core_independence.cmake
```

O script configura o projeto real com GUI OFF, testes ON, o compilador explícito recebido em CESEB_CXX_COMPILER, a revisão recebida em CESEB_SOURCE_REVISION e CMAKE_DISABLE_FIND_PACKAGE_Qt6 TRUE, compila `ceseb_domain_tests`, executa os casos financeiros e captura o resultado; não chama somente um scanner de texto. Confirma também includes/dependências do núcleo. No staging Windows, usar os caminhos concretos e o compilador nativo:

```text
cmake -DCESEB_SOURCE_ROOT=C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/source -DCESEB_BINARY_ROOT=C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/core-isolation -DCESEB_BOOST_ROOT=C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/dependencies/boost_1_86_0 -DCESEB_GTEST_PREFIX=C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/build/dependencies/install -DCESEB_CXX_COMPILER=cl -DCESEB_SOURCE_REVISION="$env:CESEB_SOURCE_REVISION" -P tests/system/check_core_independence.cmake
```

### Cobertura e discriminação

Universo de cobertura de requisitos: **25 requisitos r1**, todos os acceptance criteria numerados e as combinações de plataforma explicitamente exigidas. O relatório lista para cada critério a fixture, o método, a revisão, o ambiente e observado/falhou/não executado; não calcula “100%” a partir da existência de 25 tarefas. Invariantes adicionais usam grade determinística: C em {1,3,6,100,1200,100000,10000000,10000000000}; n em {1,2,3,12,360,600}; tipos nominal/efetiva; taxas {0,0.000001,4.5,12,100}. Filtrar apenas pelas regras aprovadas e registrar separadamente cada erro esperado. Não fazer amostragem aleatória ou alegar que a grade esgota o domínio.

Cobertura de código é diagnóstico separado. Ubuntu/GCC 13 usa build `build/coverage` com `CESEB_ENABLE_COVERAGE=ON`, testes em Debug e gcov 13 do mesmo compilador quando disponível. Universo: fontes próprias `src/core/`, `src/ui/`, `src/app/`; excluir Boost, GoogleTest, Qt, código moc/autogerado, testes e build/staging. Guardar arquivos/counters/fontes efetivamente medidos e exclusões. Windows sem um instrumento já autorizado não recebe percentual de cobertura inventado; a matriz de casos permanece obrigatória. Não há limiar percentual criado por este plano, nem uso do número de linhas como oráculo financeiro. Medidas de cobertura não substituem as demonstrações nativas.

### Procedimentos nativos e outputs

O plano 2002 produz `out/packages/ceseb-0.1.0-windows-x86_64.zip` e `out/packages/ceseb_0.1.0_amd64.deb`. A origem pode ser o staging Windows; sua evidência identifica o mesmo SHA exportado. Pacotes, logs e capturas são saídas operacionais, fora do taskmap autoral e sem publicação remota. Qualificar o SO/arquitetura e ausência de ambiente de desenvolvimento antes de cada caso.

**N-WIN:** em Windows 11 x64 limpo, usar o pacote identificado, conferir hash e extrair com `Expand-Archive` para `C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/out/package-check/windows`, preservando preexistentes; executar `C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/out/package-check/windows/bin/ceseb.exe`. O pacote de origem é `C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/out/packages/ceseb-0.1.0-windows-x86_64.zip`. A conta do operador usa a sessão desktop autorizada; não criar usuário/VM nem alterar PATH global. Conferir DLLs, `platforms/qwindows.dll`, CRT permitido, avisos e identidade do pacote. Não deixar prefixos de Qt/MSVC no ambiente mascararem falta de dependência.

**N-LINUX:** em Ubuntu 24.04 x64 desktop limpo, receber e verificar o artefato em `/tmp/ceseb-native-1/out/packages/ceseb_0.1.0_amd64.deb`, inspecionar e instalar esse pacote com o gerenciador padrão autorizado e iniciar `/opt/ceseb/bin/ceseb` ou o atalho desktop. Instalação é efeito de teste nesse alvo, com permissão do operador; não substituir Qt global. A falta de privilégio ou dependência é registrada. Remover depois somente o pacote/área de teste que pertença ao ensaio.

**I-PACKAGE:** no Ubuntu, `dpkg-deb --info` e `dpkg-deb --contents` sobre o DEB; `readelf -d /opt/ceseb/bin/ceseb` e `ldd /opt/ceseb/bin/ceseb` sobre o binário confiável do próprio projeto identificam RPATH/dependências. Em Windows, listar o ZIP/staging e usar o `dumpbin /DEPENDENTS` do ambiente autorizado, além do lançamento limpo. Confirmação de dependência não substitui o uso do pacote. Os utilitários de inspeção nativa são meios do SO/toolchain, descritos nos cartões 2305/2306 e qualificados antes de uso; indisponibilidade é lacuna.

**I-DOC e I-LICENSE:** inspecionar os arquivos/documentos e inventários exatos declarados em 2002. As tarefas T1227/T1228 dão as listas determinísticas de critérios. Recuperar todo link/registro necessário, sem alegar que HEAD de um índice prova correspondência do payload. A substituição de Qt é testada somente com bibliotecas compatíveis e identidade registrada; não usar a instalação de desenvolvimento para satisfazer o pacote final.

Evidência operacional: `out/test-evidence/base`, `out/test-evidence/linux`, `out/test-evidence/windows`, capturas por requisito/plataforma/escala e relatório separado na sessão. Não criar placeholder de resultado ou imagem nesta preparação. O relatório final nomeia cada arquivo efetivamente gerado e seu hash; caminhos de log previstos não significam que foram produzidos.

### Segurança no recorte real

Os testes de texto e faixa atacam entradas ambíguas, excesso de casas, expoentes/sinais indevidos na GUI e limites monetários. A inspeção de superfície verifica ausência de rede/persistência/credenciais no produto e examina APIs Qt efetivamente chamadas, incluindo qualquer caminho CBOR/JSON diante do aviso registrado em 1024. Não se adiciona parser ou patchset para testar um caminho inexistente.

Distinguir: análise estática das fontes próprias e fluxos; inspeção de dependências/pins/avisos do conteúdo real; inspeção de segredos apenas nos arquivos selecionados para commit, sem imprimir valores. Não introduzir scanner, serviço pago, upload ou campanha remota por este plano. Se um aviso for aplicável ou um segredo aparecer, preservar o achado e interromper a entrega afetada para decisão/correção autorizada, sem publicar artefato ou ampliar escopo silenciosamente.

## Commit Evidence

Após autorização, a fase A captura TEST_BASE real, cria os assets, tenta o base e os commita por pathspec exato do File Structure. Não usar `git add .`. O orquestrador pode criar o ramo local mencionado sem push. TEST_ASSETS_HEAD é o commit real posterior à criação dos testes, antes de qualquer commit de produto; preservar a lista de commits e o diff TEST_BASE..TEST_ASSETS_HEAD. Os documentos/inputs locais anteriores permanecem fora desse delta, sem commit artificial. Se houver staged alheio, preservar e reconciliar antes de qualquer commit.

O check obrigatório de cobertura usa o intervalo **TEST_BASE..TEST_ASSETS_HEAD**. Os valores concretos são capturados pelo relatório; o comando real será `mikoshi plan check-commits --root /home/paulo/ceseb --plan .mikoshi/brain/sessions/1-mortgage-desktop/plans/2001/r1-requirement-test-plan.md --base "$CESEB_TEST_BASE" --head "$CESEB_TEST_ASSETS_HEAD" --json`. As variáveis guardam hashes Git reais obtidos na ocasião, não placeholders aceitos como evidência. Guardar seu resultado. Não usar TEST_BASE..IMPLEMENTATION_HEAD, que incluiria arquivos de produto fora do taskmap deste plano.

A fase B lê os mesmos assets em IMPLEMENTATION_HEAD e relaciona a evidência funcional a esse alvo. Exigir que `git diff TEST_ASSETS_HEAD IMPLEMENTATION_HEAD -- tests` esteja vazio; alteração inesperada exige disposição e preservação do oráculo. As tarefas sem arquivo não precisam de commit artificial, mas precisam executar suas inspeções/demonstrações. Plano de testes implemented exige procedimento completo e cobertura de commit válida; execução parcial permanece partial implemented quando aplicável. Um teste que falha pode concluir o procedimento de teste, mas não torna o requisito pass. A revisão independente de requisitos é posterior.

## Risks and Recovery

Preservar toda alteração alheia em MAIN, inclusive artefatos aprovados locais fora de Git. Interrupção de configure/build conserva cache/log; repetir somente o estágio cuja causa foi resolvida, em diretório owned. Download interrompido ou checksum divergente não é executado/extrato válido. Recuperar o estado real de instalação/staging antes de repetir; não apagar diretório existente de outro trabalho. Um resultado sem captura/log/revisão permanece desconhecido. Não diminuir precisão, relaxar tolerância, recortar prazo ou alterar oráculo para terminar um caso.

Ausência de ambiente nativo, acesso/termos do kit Qt, edição MSVC/CRT ou instrumento de cobertura é limitação explícita. Os resultados dos ambientes disponíveis continuam úteis em seu recorte. Não declarar entrega Windows/Linux completa enquanto faltar o ensaio exigido. A manutenção numérica pode exigir análise caso a medição revele custo operacional impraticável; o teste registra a evidência antes de propor outro método ou worker thread.

## Dependencies

Cartões de projeto obrigatórios sob seus gatilhos: [2301 CMake/CTest/Ninja](../../tools/2301/r1-cmake-ctest-build.md), [2302 GoogleTest](../../tools/2302/r1-googletest-runner.md), [2303 QtTest](../../tools/2303/r1-qttest-runner.md), [2304 CI/gh](../../tools/2304/r1-github-actions.md), [2305 toolchains](../../tools/2305/r1-native-compilers.md), [2306 r2 aquisição/deploy proposta](../../tools/2306/r2-qt-dependency-acquisition-and-deployment.md). CI é referência à rota futura; 2001 não dispara workflow, faz push nem consulta uma execução remota inexistente.

CMake >= 3.28, Ninja, GCC 13/Ubuntu 24.04 ou MSVC 2022 v143/Windows 11, Qt 6.12.0 com kit 6.12.0-0-202609280346, Boost 1.86.0 e GoogleTest 1.17.0. Preservar versão/arquitetura/configuração efetivas. Usar prefixos já disponíveis e autorizados; nenhuma instalação foi feita nesta autoria. A primeira obtenção usa rede pública e fontes imutáveis. Boost archive SHA256 `1bed88e40401b2cb7a1f76d4bab499e352fa4d0c5f31c0dbae64e24d34d7513b`; GoogleTest commit `52eb8108c5bdec04579160ae17225d66034bd723`, metadados confirmados pelo dev de implementação e conservados no seu evidence/implementation-planning/source-pins.json. Esse input não comprova download/instalação.

Na fase A, o dev de testes verifica e reutiliza Git, toolchains e dependências já qualificados. Se faltarem ferramentas, produto ou dependências, preserva a tentativa real como indisponível e retorna os assets; não depende de um script de produto ainda inexistente. Após esse retorno, a tarefa I-1221 do plano 2002 cria a infraestrutura e o script de aquisição, e a preparação autorizada usa o cartão 2306 r2. Não se duplica esse script em tests/. Boost fica em `build/dependencies/boost_1_86_0`; fontes e instalação GoogleTest ficam em `build/dependencies/googletest-src` e `build/dependencies/install`; Qt fica em `build/dependencies/Qt/6.12.0/gcc_64` ou `msvc2022_64`. A fase B de 2001 reutiliza essa preparação. Os downloads específicos são públicos, com pins/hashes/TLS explícitos no novo cartão e no lock de 2002; conta Qt e assinatura não são fallback autorizado. Falha de acesso mantém a parte dependente indisponível.

Ferramentas mecânicas do plugin lidas nesta autoria: plan 4189 r2 — `/mnt/c/Users/paulo/.codex/plugins/cache/exalor-labs/mikoshi/3.0.0/resources/brain/tools/4189/r2-plan-tool.md`, trace 4196 r3 — `/mnt/c/Users/paulo/.codex/plugins/cache/exalor-labs/mikoshi/3.0.0/resources/brain/tools/4196/r3-trace-tool.md`, commit check 4188 r2 — `/mnt/c/Users/paulo/.codex/plugins/cache/exalor-labs/mikoshi/3.0.0/resources/brain/tools/4188/r2-plan-commit-check-tool.md`, Git 2570 r8 — `/mnt/c/Users/paulo/.codex/plugins/cache/exalor-labs/mikoshi/3.0.0/resources/brain/tools/2570/r8-git-tool.md`, artifact check 2521 r9 — `/mnt/c/Users/paulo/.codex/plugins/cache/exalor-labs/mikoshi/3.0.0/resources/brain/tools/2521/r9-artifact-check-tool.md`. São referências provider-local exatas e lidas nesta autoria; ficam fora do corpus permitido pelo checker de links do projeto. Por isso são locators textuais, sem arestas Markdown que aleguem acesso fora de ROOT. Não são arquivos redistribuídos nem evidência de execução. Verificar disponibilidade real antes da operação. O drafting usa somente IO de documentos e checks estruturais; DVC, credenciais/contas e remote CI não são acionados.

## Execution Record

O executor retorna a fase A em `evidence/test-execution/2001/r1-base-result.md` e o resultado final em `evidence/test-execution/2001/r1-final-result.md`, relativos à sessão. São arquivos de evidência de execução, separados dos assets versionáveis do taskmap, ainda inexistentes. O relatório final contém uma declaração mikoshi-result-v1 do plano com range TEST_BASE..TEST_ASSETS_HEAD, procedure e as 25 tarefas, conforme o contrato exato de resultados — `/mnt/c/Users/paulo/.codex/plugins/cache/exalor-labs/mikoshi/3.0.0/skills/mikoshi-core/references/contracts/result-transition.md`. A prosa e as observações associadas identificam separadamente IMPLEMENTATION_HEAD, ROOT, arquivos, comandos, ambiente, resultados observados, skips, erros, lacunas, cobertura medida e caminhos/hashes das saídas. Não inserir chaves não previstas na declaração do plano nem resultados pass/fail de requisito inferidos pelo autor do teste. Logs gerados em out/ não alteram o corpo publicado.

Após aprovação/publicação, este corpo fica imutável. O estado pode receber status de resultado com evidência exata, sem transformar o plano em diário. Mudança de design, oracle ou procedimento material requer nova revisão e autoridade aplicável. Este retorno de preparação não publica o plano, não inicia Synapses e não executa produto.
