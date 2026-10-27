---
id: 2302
revision: 1
type: tool
tags:
- mortgage
- tools
- unit-testing
status: mandatory
created: '2026-10-26'
updated: '2026-10-26'
description: Contrato do runner Google Test usado pelos planos para verificar requisitos do
  núcleo financeiro.
use_when:
- Selecionar ou executar testes de domínio sem converter a ferramenta em requisito de produto.
---
# Google Test para verificação do núcleo

## Purpose and Boundary

Google Test 1.17.0 é o meio selecionado no design para verificar comportamento financeiro. A prescrição antes colocada em [1222](../../requirements/1222/r1-core-test-suite.md) migra para este cartão e para referências dos futuros planos; os critérios financeiros permanecem nos requisitos de produto. Fontes: [spec 1014](../../specs/1014/r1-reproducible-delivery.md) e [1017](../../documents/1017/r1-design-approval-and-quality-correction.md).

## Usage Contract

CLI do executável que o plano ainda vai criar; `<domain-tests>` não nomeia um binário existente:

```text
<domain-tests> --gtest_list_tests
<domain-tests> --gtest_filter=<suite.case> --gtest_output=xml:<absolute-report.xml>
```

O plano deve fornecer o caminho e a invocação apropriada ao shell. A rota normal pode agregar esses testes por [CTest](../2301/r1-cmake-ctest-build.md). Capturar seleção, casos executados, falhas, skips, saída e código de retorno. XML não substitui a leitura dos resultados nem a associação de cada caso ao requisito e revisão. Filtro sem casos é lacuna. Comparar centavos, textos quantizados, quocientes/restos e decisões de fronteira por igualdade exata; não converter o oráculo para double. `EXPECT_NEAR` com double não verifica as fronteiras exatas propostas. Para projeções aproximadas da taxa, usar comparação no domínio decimal e tolerância declarada no requisito, separada da decisão de centavos. A origem deste cuidado é [3123](../../knowledge/3123/r1-test-runner-evidence-semantics.md); o plano selecionará as fixtures de fronteira da revisão concreta aprovada. Falha de ambiente ou coleta não é RED comportamental; preservar a causa e repetir só o caso autorizado após correção.

## Access and Authentication

Executar o runner local não exige conta ou chave. Download público dos fontes não requer credencial para repositório privado; rede é necessária apenas se a fonte aprovada ainda não estiver disponível. Fontes e avisos BSD do Google Test mantêm sua própria licença.

## Installation and Configuration

Declarar Google Test 1.17.0 com origem e commit/checksum imutável no futuro mecanismo de dependências; compilar com o mesmo runtime/toolchain do projeto. Integrar descoberta de testes e relatórios no build. O plano de testes escolhe casos, alvos e cobertura; o cartão não cria testes ou escolhe novos oráculos. Não houve obtenção ou compilação desses fontes nesta autoria.

## Contextual Obligations

Proposta para aprovação: obrigatório quando o plano verificar os requisitos de unidade/domínio pela suíte selecionada no design. O plano referencia este cartão e os requisitos reais; não cria tarefa para satisfazer a existência da ferramenta. Primeiro registrar o comportamento no base, respeitando a autoridade concreta do plano.

## Availability and Evidence

Google Test não foi encontrado nas verificações de pacotes anteriores; nenhum runner existe no projeto. Estado instalado e configurado para a baseline: não comprovado. Fonte primária consultada em 2026-10-26: [Google Test — advanced topics](https://google.github.io/googletest/advanced.html), seções de filtros e relatórios. A página é documentação corrente; flags devem ser conferidas também no binário 1.17.0 quando ele existir.

## Dependencies and Reuse

Reutiliza [CMake/CTest 2301](../2301/r1-cmake-ctest-build.md) e [compiladores 2305](../2305/r1-native-compilers.md). Consumidor pendente: plano de testes do núcleo e seu executor; nenhum plano ainda existe. O mapeamento histórico 1222→2302 preserva a escolha de método sem declarar pass de qualquer requisito.

## Removal

Preservar casos, oráculos, relatórios e correspondência com revisões antes de trocar o runner. Remover somente dependência/artefatos do ambiente dedicado e autorizado; não apagar uma instalação compartilhada nem retirar teste para ocultar falha.
