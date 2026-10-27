---
id: 1203
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
description: Calcular o livro SAC distribuindo os centavos indivisíveis nas primeiras amortizações.
use_when:
- Verificar amortização SAC, distribuição de resto e prestações não crescentes.
---
# Amortização SAC com distribuição do resto

## Requirement

Quando a entrada for admissível, o cálculo SAC deve amortizar q + 1 centavos nos primeiros r meses e q nos demais, onde q = principal_cents div n e r = principal_cents mod n.

## Origin and Boundary

**Nível:** Unidade. **Classificação de verificação:** Teste. O alvo é o cálculo SAC isolado, com principal, prazo e taxa já validados.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1012 r2 candidata](../../specs/1012/r2-amortization-comparison.md).

**Delta em avaliação:** [decisão 1025 r1 aberta](../../decisions/1025/r1-exact-rounding-method.md) e [análise 1023](../../documents/1023/r1-numerical-resolution.md). Os critérios acrescentados são draft; a aprovação anterior não é atribuída ao sucessor proposto.

### Rationale

Concentrar o resto dos centavos no fim pode elevar a última prestação. A distribuição inicial torna o ajuste determinístico e preserva o comportamento não crescente aprovado.

## Verification

**Method:** Teste.

**Inputs and target:** R$ 1.000,00, nominal anual 12%, 3 meses; e os casos admissíveis de principal e prazo da spec 1012 r2 candidata. Alvo lógico: a implementação desta obrigação na spec 1012 r2 candidata; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. No caso de 3 meses, as amortizações são [33.334; 33.333; 33.333] centavos, juros [1.000; 667; 333], pagamentos [34.334; 34.000; 33.666] e saldos [66.666; 33.333; 0].
2. O total desse caso é 102.000 centavos, com juros totais de 2.000 centavos e exatamente 3 pagamentos.
3. Em cada entrada admissível, o livro tem n linhas, as amortizações diferem no máximo em 1 centavo e seguem q + (k <= r).
4. Os juros usam o saldo de abertura e half-up em centavos; as prestações são não crescentes ao longo do livro.
5. Principal 6 centavos, nominal anual 100%, prazo 1 produz juros 1 centavo e pagamento 7 centavos. Taxas anuais nominais 5,999999% / 6% / 6,000001%, principal 100 centavos e prazo 1, produzem juros 0 / 1 / 1 centavo. A aproximação da taxa não muda esses inteiros.

### Procedure

1. Calcular o livro normativo e conferir cada linha.
2. Conferir, nos demais casos admissíveis, a distribuição do resto, a quantidade de linhas e a relação entre pagamentos consecutivos.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** Prestação não crescente permite valores iguais por arredondamento. Não afirma decréscimo estrito nem compara o mérito financeiro dos sistemas. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1012 r2 candidata](../../specs/1012/r2-amortization-comparison.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
