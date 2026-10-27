---
id: 1204
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
description: Conservar o principal e reconciliar os totais de cada livro de amortização em centavos
  exatos.
use_when:
- Conferir integridade de saldos, amortizações, pagamentos e juros nos livros Price e SAC.
---
# Conservação dos saldos e totais

## Requirement

Quando produzir um livro válido, o módulo financeiro deve conservar o principal e reconciliar pagamentos e juros conforme as identidades monetárias definidas.

## Origin and Boundary

**Nível:** Unidade. **Classificação de verificação:** Teste. As invariantes são avaliadas nos livros produzidos pelo módulo financeiro isolado.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1012 r1](../../specs/1012/r1-amortization-comparison.md).

### Rationale

Um total visualmente plausível pode esconder saldo negativo, cobrança duplicada ou principal não quitado. As identidades em centavos tornam essas falhas detectáveis em cada linha e no agregado.

## Verification

**Method:** Teste.

**Inputs and target:** Todos os livros normativos da spec 1012 r1 e as fronteiras admissíveis de 1201; valores em centavos inteiros. Alvo lógico: a implementação desta obrigação na spec 1012 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. Para cada linha: opening_balance - closing_balance = principal_paid; payment = principal_paid + interest; principal_paid > 0; closing_balance >= 0.
2. A soma das amortizações é igual ao principal inicial e o último saldo é zero.
3. O total pago é simultaneamente a soma de todos os pagamentos e principal inicial + soma dos juros.
4. Price contém de 1 a n pagamentos e SAC contém exatamente n; não há linhas após a quitação.

### Procedure

1. Obter os livros dos casos normativos e das fronteiras admissíveis.
2. Aplicar as identidades a cada linha e às somas, usando igualdade exata em centavos; registrar qualquer linha ou agregado divergente.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** Uma execução futura comprova as entradas efetivamente avaliadas, não todas as combinações do domínio. Esta obrigação não prescreve gerador de casos ou executor de testes. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1012 r1](../../specs/1012/r1-amortization-comparison.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
