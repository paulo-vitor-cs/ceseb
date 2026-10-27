---
id: 1104
revision: 1
type: requirement
tags:
- mortgage
- interest-rates
- level-unit
- verification-test
status: pass
created: '2026-10-26'
updated: 2026-10-27
description: Retornar os equivalentes nominal e efetivo anuais em percentual para a mesma taxa
  mensal.
use_when:
- Conferir os equivalentes anuais e a diferença entre teto da entrada e valor derivado.
---
# Equivalentes anuais da taxa normalizada

## Requirement

Quando normalizar uma taxa válida com fração mensal m, o normalizador deve retornar os percentuais anuais N = 1200 * m e E = 100 * ((1 + m)^12 - 1).

## Origin and Boundary

**Nível:** Unidade. **Classificação de verificação:** Teste. Os equivalentes são saídas de uma operação isolada de normalização.

**Origem:** [inclusão de nominal e efetiva em 1005 r1](../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de [1007 r1](../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md).

**Fronteira:** [1008 r1](../../specs/1008/r1-annual-rate-conversion.md).

### Rationale

Apresentar duas taxas anuais que não representam o mesmo fator mensal induz comparação incorreta. O teto da entrada não pode limitar um resultado derivado válido.

## Verification

**Method:** Teste.

**Inputs and target:** Entradas anuais nominal 12%, efetiva 12%, zero nas duas convenções e nominal 100%. Alvo lógico: a implementação desta obrigação na spec 1008 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. Nominal 12% retorna N = 12 e E = 12,682503013196972066120100.
2. Efetiva 12% retorna N = 11,386551521499568951626083032192747 e E = 12.
3. Os equivalentes anuais dos dois casos de entrada zero são zero numérico exato.
4. Cada equivalente não zero tem erro absoluto máximo de 1e-9 ponto percentual; nominal 100% retorna o E calculado pela fórmula, mesmo sendo maior que 100%.

### Procedure

1. Normalizar as entradas e coletar m, N e E como valores numéricos.
2. Comparar N e E com as referências e a fórmula do caso nominal 100%, sem limitar o valor derivado ao domínio da entrada.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** A tolerância anual está em ponto percentual. Não é uma tolerância de centavos nem verificação do CET. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1008 r1](../../specs/1008/r1-annual-rate-conversion.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
