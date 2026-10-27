---
id: 1213
revision: 1
type: requirement
tags:
- mortgage
- desktop-ui
- level-system
- verification-test
status: pass
created: '2026-10-26'
updated: 2026-10-27
description: Exibir os resumos Price e SAC com pagamentos finais, juros e contagem efetiva identificados.
use_when:
- Conferir os cartões comparativos, o ajuste final e a distinção entre prazo informado e pagamentos
  efetivos.
---
# Apresentação da comparação e do prazo efetivo

## Requirement

Quando a simulação for válida, o aplicativo deve apresentar os resumos Price e SAC com valores e contagens correspondentes à comparação financeira.

## Origin and Boundary

**Nível:** Sistema. **Classificação de verificação:** Teste. O comportamento observado é o resultado apresentado pelo aplicativo completo ao usuário.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1013 r1](../../specs/1013/r1-widgets-interface.md).

### Rationale

A comparação fica enganosa se esconder o ajuste de quitação ou apresentar prazo solicitado como quantidade efetiva. Os dois sistemas devem ser lidos sob as mesmas condições de entrada.

## Verification

**Method:** Teste.

**Inputs and target:** R$ 1.000,00, nominal anual 12%, 3 meses; e R$ 1.000,00, taxa zero, 600 meses. Alvo lógico: a implementação desta obrigação na spec 1013 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. No primeiro caso, Price mostra parcela ordinária R$ 340,02, última R$ 340,03, total R$ 1.020,07 e juros R$ 20,07; SAC mostra primeira R$ 343,34, última R$ 336,66, total R$ 1.020,00 e juros R$ 20,00.
2. Os dois cartões mostram 3 pagamentos efetivos e a diferença de juros Price menos SAC é R$ 0,07, com sinal preservado.
3. No segundo caso, o prazo informado é 600 meses; Price mostra 599 pagamentos e última parcela R$ 1,34 com aviso de quitação por ajuste de centavos; SAC mostra 600 pagamentos e última R$ 1,66.
4. A última parcela diferente da ordinária é identificada como ajustada; um prazo de 1 mês identifica uma única cobrança final, sem sugerir uma parcela ordinária adicional.

### Procedure

1. Preencher e calcular os dois casos no aplicativo.
2. Ler os rótulos e valores completos de cada cartão e o aviso de quitação; conferir o caso de prazo único para a identificação de cobrança.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** O cenário confirma a apresentação nas entradas observadas. A integridade de todos os livros pertence aos requisitos financeiros; a GUI não deve ser usada para substituir esse oráculo. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1013 r1](../../specs/1013/r1-widgets-interface.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
