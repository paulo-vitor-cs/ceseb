---
id: 1205
revision: 1
type: requirement
tags:
- mortgage
- amortization
- level-unit
- verification-test
status: pass
created: '2026-10-26'
updated: 2026-10-27
description: Calcular os casos singulares de juros zero e vencimento único sem singularidade
  ou cobrança adicional.
use_when:
- Verificar o caminho de juros zero e o pagamento único, inclusive empate de meio centavo.
---
# Cálculo nos casos de juros zero e prazo único

## Requirement

Quando receber uma entrada admissível com juros zero ou prazo de um mês, o módulo financeiro deve calcular os pagamentos definidos sem erro matemático nem prestação adicional.

## Origin and Boundary

**Nível:** Unidade. **Classificação de verificação:** Teste. A obrigação trata os caminhos matemáticos singulares dentro do cálculo isolado.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1012 r2 candidata](../../specs/1012/r2-amortization-comparison.md).

**Delta em avaliação:** [decisão 1025 r1 aberta](../../decisions/1025/r1-exact-rounding-method.md) e [análise 1023](../../documents/1023/r1-numerical-resolution.md). Os critérios acrescentados são draft; a aprovação anterior não é atribuída ao sucessor proposto.

### Rationale

A fórmula da anuidade exige um caminho específico em juros zero. O prazo de um mês também deve produzir uma única cobrança, respeitando o mesmo arredondamento monetário.

## Verification

**Method:** Teste.

**Inputs and target:** R$ 1.200,00, taxa zero, 12 meses; R$ 1,00, nominal anual 6%, prazo de 1 mês; principal 6 centavos, nominal anual 100%, prazo de 1 mês; e as vizinhanças e a taxa efetiva racional especificadas abaixo. Alvo lógico: a implementação desta obrigação na spec 1012 r2 candidata; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. No caso de juros zero, cada sistema produz 12 pagamentos de 10.000 centavos, total de 120.000 centavos e juros totais zero.
2. No caso de prazo único, cada sistema produz exatamente um pagamento de 101 centavos, com 1 centavo de juros; 0,5 centavo é arredondado half-up.
3. O pagamento de prazo único já é a quitação final; não há segunda cobrança ordinária ou residual.
4. Com principal 6 centavos, nominal anual 100% e prazo 1, ambos os sistemas produzem juros 1 centavo e pagamento 7 centavos, embora m=1/12 tenha expansão decimal recorrente.
5. Com principal 100 centavos e prazo 1, nominal anual 5,999999% / 6% / 6,000001% dá juros 0 / 1 / 1 centavo e pagamentos 100 / 101 / 101 centavos.
6. No domínio tipado, a taxa efetiva anual p=100*((201/200)^12−1), construída exatamente como decimal finito, dá crescimento mensal 201/200; principal 100 centavos e prazo 1 produz juros 1 centavo e pagamento 101 centavos. A fixture não é truncada para as seis casas da GUI.

### Procedure

1. Calcular ambos os sistemas para todos os casos, conservando exata a representação de origem.
2. Conferir quantidade de linhas, pagamentos, juros e saldo final contra os valores exatos.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** Os casos confirmam os ramos singulares declarados. Não substituem os demais vetores de taxa, prazo ou erro de centavos. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1012 r2 candidata](../../specs/1012/r2-amortization-comparison.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
