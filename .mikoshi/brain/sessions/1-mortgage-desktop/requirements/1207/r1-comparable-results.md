---
id: 1207
revision: 1
type: requirement
tags:
- mortgage
- amortization
- level-integration
- verification-test
status: pass
created: '2026-10-26'
updated: 2026-10-27
description: Comparar Price e SAC com o mesmo principal, prazo e taxa mensal normalizada.
use_when:
- Verificar o caminho de dados comum aos dois sistemas e a diferença assinada de juros.
---
# Comparação sob as mesmas condições financeiras

## Requirement

Quando receber uma entrada válida, a operação de comparação deve fornecer as mesmas condições normalizadas a Price e SAC e retornar a diferença de juros Price menos SAC.

## Origin and Boundary

**Nível:** Integração. **Classificação de verificação:** Teste. A verificação cruza normalização, cálculo dos dois sistemas e composição do resumo.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1012 r1](../../specs/1012/r1-amortization-comparison.md).

### Rationale

Alterar taxa ou prazo entre sistemas torna a comparação inválida mesmo que cada cálculo isolado esteja correto. A diferença deve conservar sinal e unidade para permitir interpretação direta.

## Verification

**Method:** Teste.

**Inputs and target:** R$ 1.000,00 por 3 meses; nominal anual 12%; e efetiva anual equivalente 12,682503013196972066120100%. Alvo lógico: a implementação desta obrigação na spec 1012 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. A entrada é normalizada uma vez e o mesmo principal, prazo e valor mensal integral são entregues aos dois sistemas.
2. Com nominal anual 12%, os totais de juros são 2.007 e 2.000 centavos; a diferença assinada é +7 centavos.
3. Com a efetiva anual equivalente indicada, os mesmos vetores monetários são preservados neste caso, afastado de fronteiras de meio centavo.
4. Alterar somente a formatação da taxa não muda os valores de cálculo; nominal 12% e efetiva 12% continuam convenções distintas.

### Procedure

1. Observar os parâmetros entregues aos dois cálculos após a normalização.
2. Executar as duas entradas equivalentes e comparar livros, resumos e diferença; repetir a apresentação sem alterar os dados financeiros.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** A entrada efetiva equivalente é uma fixture da interface numérica, não um novo formato de GUI além de seis casas. A equivalência monetária não é afirmada para valores em fronteira de arredondamento. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1012 r1](../../specs/1012/r1-amortization-comparison.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
