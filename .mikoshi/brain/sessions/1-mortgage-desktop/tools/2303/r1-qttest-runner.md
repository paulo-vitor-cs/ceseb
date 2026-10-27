---
id: 2303
revision: 1
type: tool
tags:
- mortgage
- tools
- interface-testing
status: mandatory
created: '2026-10-26'
updated: '2026-10-26'
description: Contrato do runner Qt Test para verificar parsing, eventos, foco e recuperação
  da janela Widgets.
use_when:
- Preparar ou executar a verificação automatizada da interface definida no design.
---
# Qt Test para eventos e estado da interface

## Purpose and Boundary

Qt Test 6.12.0 é o pin proposto para acompanhar a revisão de Qt, preservando o meio escolhido para os testes de interface, distinto dos oráculos de produto. A prescrição histórica [1223](../../requirements/1223/r1-gui-test-suite.md) é realocada para este cartão e para futuros planos. A [spec 1014](../../specs/1014/r1-reproducible-delivery.md) mantém o design aprovado; [1017](../../documents/1017/r1-design-approval-and-quality-correction.md) exige a correção de classificação.

## Usage Contract

Interfaces de um runner futuro, ainda inexistente:

```text
<gui-tests> -functions
<gui-tests> <test-function> -o <absolute-report.xml>,junitxml
ctest --test-dir <build-dir> -C Release --output-on-failure --no-tests=error
```

O plano substitui caminhos e seleciona funções/cenários ligados aos requisitos reais. O runner recebe eventos e pode abrir janelas; registrar backend gráfico, escala, logs e código de retorno. Automação offscreen ou em display virtual precisa ser identificada como tal; não comprova sozinha os cenários nativos de uso e acessibilidade. Sem plugin/display compatível, retornar a falha de ambiente e preservar evidência, sem mascarar a suíte como concluída.

## Access and Authentication

Execução local não requer login ou token. Testes nativos precisam de sessão gráfica e permissão de interação na sessão selecionada. Usar Qt sob a licença aplicável à instalação; não distribuir componentes de teste no pacote final por conveniência.

## Installation and Configuration

Após aprovação da [revisão Qt](../../documents/1024/r1-qt-baseline-review.md), obter Qt 6.12.0 compatível com compilador/arquitetura através de [2306](../2306/r1-qt-deployment.md); configurar o módulo Test somente nos alvos de teste. Mesma versão de Qt para build e execução. O plano define fixtures, inicialização de QApplication, isolamento da janela e flags de backend. Nenhuma dessas integrações existe no código ainda.

## Contextual Obligations

Proposta para aprovação: obrigatório quando o plano de testes verificar parsing, estados, ações e foco da interface por automação Qt. A existência de Qt Test não vira critério funcional da calculadora. Testes financeiros permanecem em [2302](../2302/r1-googletest-runner.md); o plano de GUI consome resultados de referência em vez de duplicar o cálculo como oráculo.

## Availability and Evidence

Qt e um runner de GUI não foram encontrados nas verificações disponíveis. Nenhum teste de evento, janela ou backend foi executado nesta autoria. [Qt Test overview 6.12.0](https://doc.qt.io/qt-6.12/qtest-overview.html), unidades Command Line Arguments/Logging Options/Testing Options, foi consultado em 2026-10-26: documenta seleção por função, `-functions` e `-o filename,junitxml`. Essa leitura confirma o contrato das flags, sem execução do runner. O pin 6.8.3 permanece no corpo da spec aprovada; o novo pin é candidato na [spec 1014 r2](../../specs/1014/r2-reproducible-delivery.md).

## Dependencies and Reuse

Depende de [2301](../2301/r1-cmake-ctest-build.md), [2305](../2305/r1-native-compilers.md) e [2306](../2306/r1-qt-deployment.md). Consumidor pendente: autor e executor do plano de testes da interface. Mapeamento 1223→2303 preserva o método escolhido; o comportamento público é coberto pelos requisitos de interface e uso nativo, sem resultado herdado.

## Removal

Preservar fixtures, casos, capturas, logs e os critérios de produto antes de alterar o meio de teste. Remover apenas alvos/dependências dedicados com autoridade; manter instalações Qt compartilhadas e evidência de falhas.
