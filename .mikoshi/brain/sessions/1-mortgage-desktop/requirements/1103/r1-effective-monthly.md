---
id: 1103
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
description: Converter o percentual efetivo anual para a taxa mensal composta equivalente.
use_when:
- Verificar a raiz de ordem 12 da taxa efetiva anual e sua distinção da taxa proporcional.
---
# Conversão efetiva anual para efetiva mensal

## Requirement

Quando a convenção for efetiva anual e o percentual for válido, o normalizador deve retornar effective_monthly_decimal igual a (1 + percent / 100)^(1/12) - 1.

## Origin and Boundary

**Nível:** Unidade. **Classificação de verificação:** Teste. A equivalência composta é verificada no normalizador isolado.

**Origem:** [inclusão de nominal e efetiva em 1005 r1](../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de [1007 r1](../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md).

**Fronteira:** [1008 r1](../../specs/1008/r1-annual-rate-conversion.md).

### Rationale

Dividir uma taxa efetiva anual por 12 muda o significado da entrada. A raiz do fator anual preserva a equivalência de 12 períodos mensais iguais.

## Verification

**Method:** Teste.

**Inputs and target:** Percentuais efetivos anuais 0; 4,5; 12; referências matemáticas da spec 1008 r1. Alvo lógico: a implementação desta obrigação na spec 1008 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. Para 0%, a taxa mensal é zero numérico exato.
2. Para 4,5%, a taxa mensal é 0,003674809400436766676274626791736065, com erro absoluto máximo de 1e-12.
3. Para 12%, a taxa mensal é 0,009488792934582974126355069193493956, com erro absoluto máximo de 1e-12.

### Procedure

1. Normalizar cada entrada como efetiva anual.
2. Comparar com as referências pela tolerância declarada e conferir a recomposição (1 + m)^12 do fator anual como apoio à análise.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** A recomposição é apoio matemático; a saída deve cumprir as referências independentes. O teste não comprova comportamento da GUI. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1008 r1](../../specs/1008/r1-annual-rate-conversion.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
