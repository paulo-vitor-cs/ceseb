---
id: 3123
revision: 1
type: knowledge
tags:
- mortgage
- research
- technology
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Flags confirmadas de QtTest/GoogleTest e condições de seleção vazia, precisão de asserção e relatórios CTest.
use_when:
- Planejar execução de testes sem confundir relatório ou código zero com cobertura e precisão do produto.
---
# Runners fixados e interpretação de evidência

## Claim

As flags declaradas para GoogleTest 1.17 e QtTest 6.8.3 têm suporte na versão fixada, mas a execução agregada precisa conferir seleção, skips, precisão das asserções e destino de relatórios para sustentar os requisitos reais.

## Evidência e condições

[GoogleTest advanced v1.17.0](https://github.com/google/googletest/blob/v1.17.0/docs/advanced.md), unidades de listagem/filtro/disabled/no-test-linked e XML, lidas em 2026-10-26: flags --gtest_list_tests, --gtest_filter e --gtest_output=xml:path são documentadas. --gtest_fail_if_no_test_linked acusa ausência de testes ligados, sem provar seleção não vazia por filtro.

[Qt qtestcase.cpp v6.8.3](https://github.com/qt/qtbase/blob/v6.8.3/src/testlib/qtestcase.cpp), 675..751/1819..1883: -functions, função selecionada, -o arquivo,junitxml e falha por função desconhecida estão implementados; retorno falho é limitado a 127. CLI suportada não demonstra GUI executada.

[CTest 3.28](https://cmake.org/cmake/help/v3.28/manual/ctest.1.html), opções --output-junit/--no-tests: JUnit é suportado; em invocação normal, zero testes não gera necessariamente código de erro. --no-tests=error torna esse caso erro. [Módulo GoogleTest 3.28](https://cmake.org/cmake/help/v3.28/module/GoogleTest.html), seções de descoberta e XML, leitura parcial: descoberta consulta binário; XML_OUTPUT_DIR evita colisão de arquivos na execução paralela.

[gtest.h v1.17.0](https://github.com/google/googletest/blob/v1.17.0/googletest/include/gtest/gtest.h), DoubleNearPredFormat 1470..1477 e EXPECT_NEAR 1834..1839: comparação recebe double. A comparação decimal deve permanecer decimal em predicado; valores monetários finais devem ser inteiros exatos. Essa recomendação é inferência para preservar os oráculos, não uma asserção executada.

## Contraevidência e limites

As ferramentas permitem registrar falhas e resultados, portanto não há incompatibilidade documental com o design. Um arquivo XML bem formado ou contagem de testes não vincula automaticamente requisito, revisão e ambiente. Um caso skip não é aprovação. Falha de descoberta/display não é RED comportamental. Offscreen não prova teclado/foco nativo. GoogleTest e CTest reportam unidades diferentes conforme integração.

## Consumidor e pendência

Os planos consumidores dos cartões [2301](../../tools/2301/r1-cmake-ctest-build.md), [2302](../../tools/2302/r1-googletest-runner.md), [2303](../../tools/2303/r1-qttest-runner.md) devem definir seleção esperada, interpretação e caminhos exclusivos. Propor validação futura da propagação de falha e de seleção vazia; não foi criado runner/teste nesta pesquisa. Nenhum dos antigos requisitos obsolete 1222..1224 é reativado. [Compilação 3002](../../documents/3002/r1-technology-research-compilation.md), T7. Draft, sem evidência de execução.

