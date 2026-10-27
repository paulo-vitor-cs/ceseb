---
id: 1106
revision: 1
type: requirement
tags:
- mortgage
- interest-rates
- level-integration
- verification-test
status: pass
created: '2026-10-26'
updated: 2026-10-27
description: Entregar ao cálculo a taxa mensal numérica normalizada sem reconstruí-la a partir
  da apresentação.
use_when:
- Verificar o contrato entre o normalizador e os consumidores de cálculo ao formatar taxas para
  exibição.
---
# Preservação da taxa entre normalização e cálculo

## Requirement

Quando fornecer uma taxa normalizada ao cálculo, o aplicativo deve transmitir o descritor da taxa e da origem exatas, independentemente das projeções aproximadas e do arredondamento de apresentação.

## Origin and Boundary

**Nível:** Integração. **Classificação de verificação:** Teste. A evidência cruza a fronteira entre o normalizador e o consumidor de cálculo.

**Origem:** [inclusão de nominal e efetiva em 1005 r1](../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de [1007 r1](../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md).

**Fronteira:** [1008 r2 candidata](../../specs/1008/r2-annual-rate-conversion.md).

**Delta em avaliação:** [decisão 1025 r1 aberta](../../decisions/1025/r1-exact-rounding-method.md) e [análise 1023](../../documents/1023/r1-numerical-resolution.md). Os critérios acrescentados são draft; a aprovação anterior não é atribuída ao sucessor proposto.

### Rationale

Arredondar a taxa mostrada e depois reutilizar esse texto pode mudar as prestações. Mesmo uma aproximação muito próxima não decide todo empate; a origem exata conserva a semântica financeira. Projeções aproximadas atendem às tolerâncias declaradas; a apresentação recebe sua quantização half-up exata separadamente.

## Verification

**Method:** Teste.

**Inputs and target:** Entrada efetiva anual 12%; consumidor de cálculo observável; representações de apoio com quatro e seis casas percentuais; caso nominal anual 100%, principal 6 centavos e prazo 1. Alvo lógico: a implementação desta obrigação na spec 1008 r2 candidata; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. A projeção mensal recebida é 0,009488792934582974126355069193493956 com erro absoluto máximo de 1e-12; o consumidor financeiro também recebe a convenção efetiva e o percentual original exato 12%, que determinam x^12=1,12.
2. Formatar a mesma taxa para 0,9489% ou 0,948879% ao mês não altera o valor entregue ao consumidor dentro da tolerância anterior.
3. O caminho de dados não obtém a taxa de cálculo por parsing de um rótulo de apresentação nem usa a projeção aproximada para decidir um centavo.
4. No caso nominal anual 100%, principal 6 centavos e prazo 1, o consumidor conserva m=1/12 exatamente no descritor; ambos os livros cobram 1 centavo de juros. Formatar projeções não altera esse resultado.

### Procedure

1. Normalizar as entradas efetiva e nominal dos critérios e observar o descritor e a projeção recebidos pelo consumidor antes e depois da formatação.
2. Comparar as capturas numéricas com a referência e inspecionar a ligação entre os componentes.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** As duas precisões são fixtures de verificação da fronteira, não um novo seletor de precisão da GUI. Este requisito não comprova os totais dos modelos de amortização. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1008 r2 candidata](../../specs/1008/r2-annual-rate-conversion.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
