---
id: 1206
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
description: Recusar simulações que não conseguem amortizar o mínimo de um centavo definido
  pelo modelo.
use_when:
- Verificar erros de admissibilidade monetária sem expor uma comparação parcial.
---
# Rejeição de combinações inviáveis em centavos

## Requirement

Quando principal_cents < term_months ou a parcela ordinária Price arredondada não superar o primeiro juro arredondado, a comparação deve retornar UnsupportedCentPrecision sem resultado parcial.

## Origin and Boundary

**Nível:** Unidade. **Classificação de verificação:** Teste. A admissibilidade é avaliada dentro da operação financeira antes de retornar uma comparação.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1012 r1](../../specs/1012/r1-amortization-comparison.md).

### Rationale

Forçar uma parcela zero ou só de juros contradiz a amortização mínima adotada. Uma recusa explícita permite corrigir a simulação sem apresentar livros parciais como válidos.

## Verification

**Method:** Teste.

**Inputs and target:** Principal de 1 centavo, taxa zero e 600 meses; principal de 1.200 centavos, nominal anual 100% e 600 meses. Alvo lógico: a implementação desta obrigação na spec 1012 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. O primeiro caso retorna UnsupportedCentPrecision, pois não há principal suficiente para amortizar ao menos 1 centavo em cada mês SAC.
2. O segundo caso retorna UnsupportedCentPrecision: a parcela Price ordinária e o primeiro juro são ambos 100 centavos.
3. Em qualquer uma das duas condições de recusa, não há Comparison nem livro parcial exposto como sucesso.

### Procedure

1. Executar as duas entradas que isolam as condições de recusa.
2. Conferir o código de erro e a ausência de resultado de sucesso ou resumo parcial.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** A recusa decorre da precisão e política deste simulador, não de uma impossibilidade financeira universal. A mensagem e o foco da GUI pertencem ao requisito 1214. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1012 r1](../../specs/1012/r1-amortization-comparison.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
