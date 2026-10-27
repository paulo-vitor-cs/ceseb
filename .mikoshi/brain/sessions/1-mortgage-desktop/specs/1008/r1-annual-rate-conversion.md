---
id: 1008
revision: 1
type: spec
tags:
- mortgage
- interest-rates
- financial-core
status: superseded
created: '2026-10-26'
updated: '2026-10-26'
description: Contrato candidato de entrada anual nominal ou efetiva e conversão pura para taxa
  efetiva mensal no núcleo financeiro.
use_when:
- Definir ou verificar a conversão de taxas anuais nominal e efetiva antes do cálculo das prestações.
---
# Conversão de taxa anual nominal e efetiva

Rascunho independente de uma funcionalidade: converter uma taxa anual identificada para uma taxa efetiva mensal. A inclusão de ambos os tipos vem da [escolha humana1005](../../documents/1005/r1-human-scope-approval.md). As escolhas técnicas abaixo são candidatas do specialist, registradas antes deste corpo na [decisão1007](../../decisions/1007/r1-rate-design-basis.md). Este rascunho não aprova implementação.

## Fronteira e interfaces

O núcleo financeiro oferece uma operação pura. Entrada lógica: `AnnualRate { kind, percent }`. `kind` deve ser explicitamente `NominalAnnualMonthlyCapitalization` ou `EffectiveAnnual`; `percent=12` significa12% ao ano. Um `kind` ausente ou desconhecido é erro. O período nominal de capitalização é sempre mensal neste recorte, com 12 períodos iguais por ano.

Saída lógica de sucesso: `NormalizedRate { effective_monthly_decimal, nominal_annual_percent, effective_annual_percent }`. O contrato de saída distingue fração decimal de percentual no nome e na documentação. Consumidores recebem a taxa mensal integral, e não o texto arredondado mostrado na interface. A proposta de tipo numérico é Boost.Multiprecision cpp_dec_float_50, construído de texto decimal sem passagem por double, conforme decisão1011. Os nomes físicos de arquivos serão definidos no plano após aprovação; nenhuma dependência de Qt é exigida neste módulo.

A validação local candidata aceita apenas percentual anual finito em0..100 inclusive para ambos os tipos. Esse teto aplica-se à entrada: uma taxa efetiva anual derivada pode ultrapassar100%. A política é uma proposta de produto, não regra bancária ou limite legal. A operação retorna `InvalidRateKind`, `RateOutOfRange` ou `NonFiniteRate` em vez de produzir um resultado numérico inválido. Texto vazio ou separador local pertence ao formulário futuro, antes desta interface tipada.

## Modelo matemático

Seja `p` o percentual anual de entrada e `m` a taxa efetiva mensal em fração decimal.

- Entrada nominal anual capitalizada mensalmente: `m = (p / 100) / 12`.
- Entrada efetiva anual: `m = (1 + p / 100)^(1/12) - 1`.
- Equivalente nominal anual percentual: `N = 100 * 12 * m`.
- Equivalente efetivo anual percentual: `E = 100 * ((1 + m)^12 - 1)`.

Com entrada zero, todas as saídas são zero. Métodos numericamente estáveis, como `expm1(log1p(p/100)/12)`, são meios locais propostos para a segunda fórmula, não outro modelo financeiro. A proposta de biblioteca está na decisão1011; nenhuma biblioteca foi instalada ou código implementado.

O [CRECISP](https://crecisp.gov.br/comunicacao/glossario/t) sustenta a distinção nominal/efetiva e o exemplo12% nominal→1% mensal→12,68% efetiva anual. As equações exatas são derivadas da composição de 12 períodos iguais; a referência arredondada do glossário não define tolerância. [Aritmética Decimal exploratória](../../evidence/rate-conversion-reference.json) contém valores de apoio para0%,4,5% e 12%, sem alegação de teste de produto.

## Precisão candidata e apresentação

Para os vetores declarados nos requisitos, erro absoluto máximo proposto:1e-12 na taxa mensal decimal;1e-9 ponto percentual nos equivalentes anuais. Os critérios são propostas verificáveis do specialist; precisam compor a aceitação do design concreto. A aplicação não arredonda a taxa mensal para a precisão de exibição antes de passá-la ao cálculo. O formato e número de casas apresentados pela GUI são design dependente ainda pendente. Este contrato não decide arredondamento monetário das prestações.

## Estados, efeitos e falhas

A operação é síncrona, sem estado mutável, persistência, rede ou credencial. Uma chamada válida resulta em uma saída normalizada; uma chamada inválida resulta somente em erro. Não há efeito parcial a recuperar. Repetições com a mesma entrada sob o mesmo contrato numérico geram resultados dentro dos mesmos critérios. Não há concorrência interna, cancelamento ou timeout de rede. A GUI poderá executar novamente após correção, sem reutilizar um resultado calculado a partir de entrada inválida.

## Rastreamento e prontidão

Requisitos candidatos: [1101 tipo explícito](../../requirements/1101/r1-explicit-rate-kind.md), [1102 nominal mensal](../../requirements/1102/r1-nominal-monthly.md), [1103 efetiva mensal](../../requirements/1103/r1-effective-monthly.md), [1104 equivalentes anuais](../../requirements/1104/r1-annual-equivalents.md), [1105 entrada inválida](../../requirements/1105/r1-invalid-rate-input.md), [1106 taxa integral ao consumidor](../../requirements/1106/r1-unrounded-consumer-rate.md).

Ainda não existe plano nem arquivo de produto. O percurso requirement→plano→arquivo será preenchido pelos planos aprovados; nomes de tipos acima são interfaces lógicas, não arquivos existentes. Não há revisão predecessora ou aresta antiga afetada. Arestas novas ligam este corpo às fontes e aos requisitos exatos.

O humano selecionou Price e SAC em resposta posterior registrada em1005. A formulação dos dois sistemas é outra funcionalidade e consumirá a taxa mensal deste contrato. GUI, idioma/moeda e formato de distribuição não são escolhidos por esta funcionalidade; as opções ainda abertas são tratadas no [esclarecimento1006](../../documents/1006/r1-clarification.md). O design completo precisa também reconciliar a política numérica candidata antes da entrada em planejamento. Não há resultado pass, implemented ou validação Windows/Linux.

## Integração r1 no design completo

[Decisão1011](../../decisions/1011/r1-complete-design-basis.md) registra antes desta integração a proposta decimal50. A saída integral alimenta [Price/SAC1012](../1012/r1-amortization-comparison.md); [UI1013](../1013/r1-widgets-interface.md) mostra equivalentes com seis casas sem alterar a taxa de cálculo. Qt Widgets já foi escolhido pelo humano; locale e políticas concretas seguem propostas. Os requisitos1101..1106 e seus oráculos ficam inalterados. As novas ligações acrescentam consumidores exatos, sem retirar fontes ou mudar revisões aprovadas; este corpo continua draft.
