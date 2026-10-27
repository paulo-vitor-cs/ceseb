---
id: 1226
revision: 2
type: requirement
tags:
- mortgage
- delivery
- level-system
- verification-demonstration
status: pass
created: '2026-10-27'
updated: 2026-10-27
description: Executar os cenários essenciais no pacote Windows 11 e em Linux com WSL
  aceito explicitamente pelo usuário.
use_when:
- Qualificar a operação dos pacotes em sessões desktop reais nas duas plataformas
  declaradas.
---
# Operação completa em Windows e Linux com WSL aceito

## Requirement

Quando o pacote for aberto em cada plataforma declarada, o aplicativo deve permitir concluir os cenários essenciais de simulação e correção no ambiente desktop.

## Origin and Boundary

**Nível:** Sistema. **Classificação de verificação:** Demonstração. A evidência abrange a aplicação distribuída e seus recursos em execução no sistema operacional alvo.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1014 r3](../../specs/1014/r3-wsl-validation-delivery.md).

**Emenda humana:** [1036 r1](../../documents/1036/r1-bounded-corrections-and-validation-authority.md) aceita WSL como validação Linux deste requisito; [decisão 1037](../../decisions/1037/r1-wsl-linux-validation-choice.md). A revisão [r1](r1-native-smoke.md) e sua evidência histórica permanecem preservadas. Os cenários e valores de aceite são os mesmos.

### Rationale

Build bem-sucedido ou simulação de eventos não demonstra que o pacote abre e permite usar a interface no sistema final. A operação real é o resultado solicitado para Windows e Linux.

## Verification

**Method:** Demonstração.

**Inputs and target:** Windows 11 x86_64 e Linux x86_64 em WSL com display, identificando distribuição e versão reais, sem ambiente de desenvolvimento configurado para a execução do pacote; principal R$ 1.000,00, taxa anual 12%, prazo 3 meses. Alvo lógico: a implementação desta obrigação na spec 1014 r3; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. Em cada sistema, o pacote abre e calcula a entrada nominal, mostrando os valores de 1213 e as equivalências de 1212.
2. Alterar o tipo para efetiva invalida o resultado antigo. Ao recalcular com os mesmos R$ 1.000,00 e 3 meses, a taxa mensal mostrada é 0,948879%; Price mostra parcela ordinária e última de R$ 339,68, total R$ 1.019,04 e juros R$ 19,04; SAC mostra primeira R$ 342,83, última R$ 336,49, total R$ 1.018,98 e juros R$ 18,98; a diferença de juros é R$ 0,06.
3. O usuário consegue provocar uma entrada inválida, receber o erro, corrigir, recalcular, limpar, navegar por teclado, redimensionar e fechar sem falha do aplicativo.
4. A evidência identifica sistema, arquitetura, pacote, revisão de fonte, sequência executada, resultados e captura visual nas duas plataformas.

### Procedure

1. Abrir o pacote e executar a sequência completa no desktop de cada sistema.
2. Conferir valores e transições pelos requisitos referenciados e registrar o resultado por plataforma, sem extrapolar de um sistema ao outro.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** WSL com display e interação observada é evidência aceita para a parte Linux por escolha humana. Não constitui evidência Windows: executar o binário Linux integrado ao host Windows 11 não substitui o pacote Windows. Offscreen, compilação isolada e presença do sistema operacional não completam a demonstração. Registrar as condições reais e a configuração runtime; ambiente indisponível permanece lacuna. A mudança do critério não atribui pass nem relaxa 1215, 1216, 1221, 1225 ou 1228.

## Trace

Related: [predecessor 1226 r1](r1-native-smoke.md); [spec 1014 r3](../../specs/1014/r3-wsl-validation-delivery.md); [decisão 1037](../../decisions/1037/r1-wsl-linux-validation-choice.md); [autoridade humana 1036](../../documents/1036/r1-bounded-corrections-and-validation-authority.md).

O plano de verificação [2004 r1](../../plans/2004/r1-distribution-regression-and-validation.md) declara a tarefa V1226 e seus inputs; o novo corpo não transfere resultado histórico nem altera os planos 2001/2002 publicados.
