---
id: 1101
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
description: Exigir a convenção nominal anual com capitalização mensal ou efetiva anual antes
  da normalização.
use_when:
- Verificar a identificação da convenção e rejeição de tipos ausentes ou desconhecidos no normalizador.
---
# Convenção explícita da taxa anual

## Requirement

Quando receber uma taxa anual, o normalizador deve exigir uma das duas convenções explícitas e rejeitar qualquer tipo ausente ou desconhecido.

## Origin and Boundary

**Nível:** Unidade. **Classificação de verificação:** Teste. O objeto verificado é o normalizador isolado de taxas.

**Origem:** [inclusão de nominal e efetiva em 1005 r1](../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de [1007 r1](../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md).

**Fronteira:** [1008 r1](../../specs/1008/r1-annual-rate-conversion.md).

### Rationale

O mesmo número anual representa taxas mensais diferentes conforme a convenção. Inferir o tipo pode produzir uma simulação coerente numericamente e errada para a entrada pretendida.

## Verification

**Method:** Teste.

**Inputs and target:** Tipos NominalAnnualMonthlyCapitalization, EffectiveAnnual, ausente e desconhecido; percentual anual 12. Alvo lógico: a implementação desta obrigação na spec 1008 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. Com NominalAnnualMonthlyCapitalization e 12%, a taxa mensal é 0,01, com erro absoluto máximo de 1e-12.
2. Com EffectiveAnnual e 12%, a taxa mensal é 0,009488792934582974126355069193493956, com erro absoluto máximo de 1e-12.
3. Com tipo ausente ou desconhecido, retorna InvalidRateKind sem NormalizedRate de sucesso; o percentual não determina um tipo implícito.

### Procedure

1. Chamar o normalizador com cada tipo e o mesmo percentual 12.
2. Comparar cada sucesso com sua referência numérica; inspecionar o código de erro e a ausência de saída nas duas entradas de tipo inválido.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** O teste do tipo não verifica parsing textual, interface, amortização ou encargos de um contrato real. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1008 r1](../../specs/1008/r1-annual-rate-conversion.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
