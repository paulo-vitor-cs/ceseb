---
id: 1102
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
description: Converter o percentual nominal anual com capitalização mensal para sua fração efetiva
  mensal.
use_when:
- Verificar a divisão por 1200 e os extremos da conversão nominal anual.
---
# Conversão nominal anual para efetiva mensal

## Requirement

Quando a convenção for nominal anual com capitalização mensal e o percentual for válido, o normalizador deve retornar effective_monthly_decimal igual a percent / 1200.

## Origin and Boundary

**Nível:** Unidade. **Classificação de verificação:** Teste. A conversão é uma operação numérica isolada do normalizador.

**Origem:** [inclusão de nominal e efetiva em 1005 r1](../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de [1007 r1](../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md).

**Fronteira:** [1008 r1](../../specs/1008/r1-annual-rate-conversion.md).

### Rationale

Uma divisão incorreta por 12 ou por 100 altera a unidade da taxa. A normalização deve produzir uma fração mensal utilizável pelos dois modelos de amortização.

## Verification

**Method:** Teste.

**Inputs and target:** Percentuais anuais 0; 4,5; 12; 100 na convenção nominal. Alvo lógico: a implementação desta obrigação na spec 1008 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. Os resultados mensais para 0%, 4,5%, 12% e 100% são, respectivamente, 0; 0,00375; 0,01; 1/12.
2. Cada resultado não zero difere da fração matemática indicada em no máximo 1e-12 absoluto.
3. A entrada zero produz zero numérico exato.

### Procedure

1. Normalizar separadamente os quatro percentuais.
2. Comparar a saída mensal com as frações de referência, sem usar o texto formatado da interface.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** A tolerância mede a conversão mensal nos casos executados; não decide o arredondamento de prestações. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1008 r1](../../specs/1008/r1-annual-rate-conversion.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
