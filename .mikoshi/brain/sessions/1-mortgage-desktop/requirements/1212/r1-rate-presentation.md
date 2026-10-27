---
id: 1212
revision: 1
type: requirement
tags:
- mortgage
- desktop-ui
- level-integration
- verification-test
status: pass
created: '2026-10-26'
updated: 2026-10-27
description: Exibir os equivalentes mensal e anuais com seis casas decimais e unidades inequívocas.
use_when:
- Verificar a ligação entre saída de normalização e rótulos percentuais mostrados na interface.
---
# Apresentação das taxas com tipo e período

## Requirement

Quando uma simulação válida for apresentada, a interface deve mostrar a taxa efetiva mensal e os equivalentes anuais nominal e efetivo com tipo, período e seis casas decimais.

## Origin and Boundary

**Nível:** Integração. **Classificação de verificação:** Teste. O alvo é a transformação da saída numérica do núcleo em rótulos da interface.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1013 r2 candidata](../../specs/1013/r2-widgets-interface.md).

**Delta em avaliação:** [decisão 1025 r1 aberta](../../decisions/1025/r1-exact-rounding-method.md) e [análise 1023](../../documents/1023/r1-numerical-resolution.md). Os critérios acrescentados são draft; a aprovação anterior não é atribuída ao sucessor proposto.

### Rationale

O usuário precisa reconhecer tipo e período para comparar as duas convenções anuais. Arredondar a exibição não pode limitar uma taxa derivada nem alimentar de volta o cálculo.

## Verification

**Method:** Teste.

**Inputs and target:** Simulações válidas com principal R$ 1.000,00 e 3 meses; taxas anuais nominal 12%, efetiva 12% e nominal 100%; nominais anuais 0,000005% / 0,000006% / 0,000007%; e fixture isolada exata de percentual 0,0000005%. Alvo lógico: a implementação desta obrigação na spec 1013 r2 candidata; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. Nominal anual 12% mostra efetiva mensal 1,000000%, nominal anual 12,000000% e efetiva anual 12,682503%.
2. Efetiva anual 12% mostra efetiva mensal 0,948879%, nominal anual 11,386552% e efetiva anual 12,000000%.
3. A apresentação usa half-up nas seis casas e identifica o tipo e o período de cada valor.
4. O equivalente anual derivado da entrada nominal 100% é apresentado acima de 100%, segundo a fórmula de 1104; o teto da entrada não corta a saída. O descritor exato de cálculo continua sujeito a 1106.
5. No pipeline completo, nominal anual 0,000005% / 0,000006% / 0,000007% mostra respectivamente efetiva mensal 0,000000% / 0,000001% / 0,000001%. A fixture central é empate half-up, sem retorno do texto ao cálculo.
6. Uma fixture isolada exata de percentual 0,0000005% gera texto 0,000001% em seis casas, independentemente do default do formatter numérico.

### Procedure

1. Calcular cada simulação e ler os três rótulos completos.
2. Conferir os dois vetores textuais exatos, a formatação do valor derivado acima de 100% e os três casos em torno do empate mensal; comparar com os inteiros quantizados recebidos pela apresentação.
3. Verificar também a fixture isolada exata para distinguir a política de formatação da conversão anual anterior.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** Os critérios são da apresentação percentual; não demonstram exatidão monetária de prestações nem qualificam a interface nativa em todas as escalas. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1013 r2 candidata](../../specs/1013/r2-widgets-interface.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
