---
id: 1105
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
description: Rejeitar percentuais anuais não finitos ou fora do intervalo de 0% a 100% sem saída
  normalizada.
use_when:
- Verificar valores não finitos e fronteiras do domínio percentual em ambas as convenções anuais.
---
# Rejeição de percentual anual inválido

## Requirement

Quando receber uma convenção válida, o normalizador deve rejeitar percentual não finito ou fora de 0% a 100%, inclusive, sem produzir NormalizedRate de sucesso.

## Origin and Boundary

**Nível:** Unidade. **Classificação de verificação:** Teste. A validação do percentual pertence à interface tipada do normalizador.

**Origem:** [inclusão de nominal e efetiva em 1005 r1](../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de [1007 r1](../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md).

**Fronteira:** [1008 r1](../../specs/1008/r1-annual-rate-conversion.md).

### Rationale

Uma taxa não finita ou fora do domínio torna as fórmulas e a apresentação indefinidas. A rejeição deve ser observável antes de qualquer sucesso numérico.

## Verification

**Method:** Teste.

**Inputs and target:** Para cada convenção: NaN, infinito positivo, infinito negativo, -0,01%; 0%; 100%; 100,01%. Alvo lógico: a implementação desta obrigação na spec 1008 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. NaN e os dois infinitos retornam NonFiniteRate sem saída de sucesso.
2. -0,01% e 100,01% retornam RateOutOfRange sem saída de sucesso.
3. 0% e 100% retornam sucesso com todas as saídas finitas; resultados derivados podem ultrapassar 100%.

### Procedure

1. Executar a mesma tabela de percentuais com cada uma das duas convenções válidas.
2. Conferir o código de erro e ausência de sucesso, ou a finitude das saídas nas fronteiras inclusivas.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** O intervalo é um limite do simulador aprovado no design, não um teto legal ou de mercado. A validação textual fica no requisito 1211. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1008 r1](../../specs/1008/r1-annual-rate-conversion.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
