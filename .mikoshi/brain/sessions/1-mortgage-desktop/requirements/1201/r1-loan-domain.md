---
id: 1201
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
description: Validar principal e prazo tipados antes de produzir uma comparação de financiamento.
use_when:
- Verificar limites de principal e prazo, prioridade de validação e ausência de comparação em
  entradas inválidas.
---
# Validação do domínio do financiamento

## Requirement

Quando receber LoanInput, a operação de comparação deve rejeitar principal ou prazo fora do domínio definido, sem produzir uma Comparison.

## Origin and Boundary

**Nível:** Unidade. **Classificação de verificação:** Teste. O alvo é a validação isolada da operação de comparação, antes de produzir livros.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1012 r1](../../specs/1012/r1-amortization-comparison.md).

### Rationale

Limites explícitos evitam aceitação silenciosa de valores não representáveis. O código de erro deve distinguir valor financiado, taxa e prazo para permitir correção da entrada.

## Verification

**Method:** Teste.

**Inputs and target:** Principal de 1 a 10.000.000.000 centavos; prazo inteiro de 1 a 600 meses; taxa válida zero, exceto nos casos de prioridade de erro. Alvo lógico: a implementação desta obrigação na spec 1012 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. Principal 0 e 10.000.000.001 centavos retornam PrincipalOutOfRange; não há Comparison.
2. Com principal válido, prazos inteiros 0 e 601 retornam TermOutOfRange; não há Comparison.
3. Principal 1 centavo com prazo 1, e principal 10.000.000.000 centavos com prazos 1 e 600, prosseguem pelas validações inclusivas do domínio.
4. Entradas com múltiplos defeitos seguem a ordem principal, taxa/tipo, prazo e admissibilidade de centavos. As fronteiras não dispensam a admissibilidade do requisito 1206.

### Procedure

1. Executar cada caso inválido isolado e os casos de fronteira com taxa zero.
2. Executar combinações com principal inválido, taxa inválida e prazo inválido para conferir a prioridade e ausência de resultado parcial.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** O prazo já é inteiro na interface tipada; frações textuais são tratadas por 1211, sem conversão implícita para um inteiro. A aceitação de domínio não comprova todos os cálculos monetários. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1012 r1](../../specs/1012/r1-amortization-comparison.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
