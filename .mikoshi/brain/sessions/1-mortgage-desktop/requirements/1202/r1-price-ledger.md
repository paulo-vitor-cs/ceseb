---
id: 1202
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
description: Calcular o livro Price com parcela ordinária, limite de quitação e ajuste do pagamento
  final.
use_when:
- Verificar prestações Price, quitação antecipada por centavos e contagem efetiva de pagamentos.
---
# Pagamentos Price em centavos

## Requirement

Quando a entrada for admissível, o cálculo Price deve produzir o livro em centavos definido pela anuidade e pela política de quitação da spec 1012 r2 candidata.

## Origin and Boundary

**Nível:** Unidade. **Classificação de verificação:** Teste. Um cálculo Price é verificado isoladamente a partir de uma taxa mensal normalizada.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1012 r2 candidata](../../specs/1012/r2-amortization-comparison.md).

**Delta em avaliação:** [decisão 1025 r1 aberta](../../decisions/1025/r1-exact-rounding-method.md) e [análise 1023](../../documents/1023/r1-numerical-resolution.md). Os critérios acrescentados são draft; a aprovação anterior não é atribuída ao sucessor proposto.

### Rationale

A fórmula real não basta para um livro em centavos. Arredondar cada pagamento exige ajustar a quitação e encerrar o livro quando o saldo chega a zero.

## Verification

**Method:** Teste.

**Inputs and target:** Casos normativos: R$ 1.000,00, nominal anual 12%, 3 meses; R$ 1.000,00, taxa zero, 600 meses; principal 3 centavos, taxa zero, 2 meses; e R$ 1.000,00, efetiva anual 12%, 3 meses. Alvo lógico: a implementação desta obrigação na spec 1012 r2 candidata; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. No caso de 3 meses, os pagamentos são [34.002; 34.002; 34.003] centavos, os juros [1.000; 670; 337] e os saldos finais [66.998; 33.666; 0].
2. Esse resumo informa parcela ordinária 34.002 centavos, total 102.007 centavos, juros 2.007 centavos e 3 pagamentos efetivos.
3. No caso de 600 meses a juros zero, a parcela ordinária é 167 centavos, a última é 134 centavos, há 599 pagamentos efetivos e o total é 100.000 centavos.
4. A parcela ordinária é a anuidade matemática arredondada half-up; antes do mês-limite, o pagamento é min(parcela ordinária, saldo + juros); no mês-limite é saldo + juros. Após o saldo zero não existe outra linha.
5. Para principal 3 centavos, taxa zero e prazo 2, a anuidade de 1,5 centavo produz parcela ordinária de 2 centavos e pagamentos [2; 1].
6. Para efetiva anual positiva cuja raiz mensal é irracional, a parcela ordinária coincide com o half-up da anuidade matemática; a verificação compara centavos inteiros sem tolerância monetária. O plano deverá incluir efetiva anual 12%, principal 100.000 centavos, prazo 3: parcela ordinária 33.968 centavos e pagamentos [33.968; 33.968; 33.968].

### Procedure

1. Calcular todos os casos dos critérios e coletar todas as linhas, o resumo e a quantidade efetiva.
2. Conferir os vetores e a regra de quitação com os valores exatos em centavos, sem tolerância monetária.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** Este requisito julga a política Price deste simulador, não fidelidade a qualquer contrato bancário. A apresentação dos resumos é verificada separadamente em 1213. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1012 r2 candidata](../../specs/1012/r2-amortization-comparison.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
