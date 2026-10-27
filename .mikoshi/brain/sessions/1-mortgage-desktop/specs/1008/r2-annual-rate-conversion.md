---
id: 1008
revision: 2
type: spec
tags:
- mortgage
- interest-rates
- financial-core
status: implemented
created: '2026-10-26'
updated: 2026-10-27
description: Preservar taxa anual de origem exata e descritor de crescimento para conversões
  e desempates sem quantização financeira.
use_when:
- Normalizar e transportar taxas anuais com origem exata, separando projeções aproximadas das
  decisões de fronteira.
---
# Conversão de taxas com origem exata

Revisão candidata da [1008 r1 aceita](r1-annual-rate-conversion.md), preservada. Autoridade do recorte e escolhas: [1025 r1](../../decisions/1025/r1-exact-rounding-method.md). A inclusão de ambas as convenções vem de [1005 r1](../../documents/1005/r1-human-scope-approval.md). Esta proposta precisa ser apreciada no gate concreto; não implementa nem publica o sucessor.

## Fronteira, domínio e dados

Operação pura `normalize(AnnualRate) -> NormalizedRate | RateError`. Entrada lógica `AnnualRate { kind, percent }`, com `NominalAnnualMonthlyCapitalization` ou `EffectiveAnnual`; percent=12 significa 12% anual. Domínio anual finito 0..100 inclusive, sem limitar os equivalentes derivados a 100%. Taxa nominal capitaliza em 12 períodos mensais iguais. Os erros `InvalidRateKind`, `RateOutOfRange` e `NonFiniteRate` permanecem. Não aceitar NaN/infinito como racional nem transformá-los em zero.

`percent` conserva o valor decimal finito original como fração exata reduzida de inteiros, sem passagem por double e sem truncamento para decimal 50. O adaptador GUI já valida até seis casas; essa gramática não impõe um piso novo ao core. Um consumidor tipado deve construir a taxa a partir da representação decimal exata, ou de numerador/denominador equivalentes; uma conveniência que receba decimal finito deve preservar exatamente seu valor fornecido, sem inventar dígitos do valor pretendido antes de sua construção. O plano definirá nomes físicos e overloads. Percentuais não finitos são rejeitados na fronteira de construção, antes de materializar a fração. Strings localizadas vazias ou malformadas continuam responsabilidade da UI.

Saída lógica `NormalizedRate` contém a convenção, o percentual de origem exato e o descritor do crescimento mensal x=1+m: `RationalGrowth{x}` para nominal e efetiva com raiz racional, ou `TwelfthRootGrowth{g}` para efetiva irracional, onde g é racional exato. Consumidores financeiros recebem esse descritor completo. Projeções `effective_monthly_decimal`, `nominal_annual_percent`, `effective_annual_percent` podem continuar disponíveis para critérios numéricos de taxa; não substituem o descritor no cálculo ou no formatter de fronteira. Não há Qt, relógio, rede ou estado mutável no core.

## Modelo preservado

Para percentual anual p e taxa mensal fracionária m:

- Nominal: m=p/1200; x=1+p/1200, racional exato.
- Efetiva: g=1+p/100; x é a única raiz positiva de x^12=g; m=x−1.
- Nominal anual equivalente N=1200m, em pontos percentuais.
- Efetiva anual equivalente E=100(x^12−1), em pontos percentuais.

Zero tem x=1 e todas as taxas zero. Não existe quantização mensal convencional nova. Para efetiva, reduzir g=a/b e testar se a e b são potências 12 inteiras exatas; o teste usa raiz inteira por comparação de potências, sem fatoração. Se ambos forem, x=raiz 12(a)/raiz 12(b), exato. Caso contrário conservar a raiz implicitamente; não aproximá-la para decidir dinheiro. Esta classificação é uma vez por simulação.

## Fronteiras e apresentação exatas

Para racional positivo y, comparar x com y usando somente inteiros: no ramo efetivo, `x >= y` se e somente se `g >= y^12`; igualdade é igualdade inteira após multiplicação cruzada. No ramo nominal, usar comparação racional direta. Isso resolve a comparação da taxa com qualquer fronteira racional sem epsilon.

Uma projeção percentual seis casas é o inteiro `J=R(10^6 * percentual)`, com `R(z)=floor(z+1/2)`. Para percentual racional calcular a divisão inteira half-up. Para os percentuais efetivos derivados de raiz, mensal=100(x−1) e nominal anual=1200(x−1), decidir `J>=j` por `x >= 1+(2j−1)/(2*10^6*K)`, K=100 ou 1200, para j>=1; a busca inteira é limitada pelo domínio de taxas. Após obter J, formatar os dígitos inteiros em seis casas. O caminho não delega o desempate a conversão genérica de ponto flutuante para string. E=p no ramo efetivo; no nominal E=100(x^12−1) é racional. N=p no nominal.

## Projeções aproximadas e tolerâncias

Os requisitos de projeção permanecem: erro absoluto máximo de 1e-12 na fração mensal e 1e-9 ponto percentual nos equivalentes anuais, nos vetores declarados. Uma projeção pode ser obtida de limites racionais refinados e convertida no tipo decimal desejado até satisfazer esse limite; Boost decimal 50 continua um meio disponível. Esses limites não autorizam erro monetário ou texto do lado errado de um empate. A taxa exibida não retorna ao core. Valores positivos menores que o piso textual da GUI não são convertidos silenciosamente em taxa zero.

## Integração, falhas e rastreamento

[1012 r2](../1012/r2-amortization-comparison.md) consome a origem exata e decide juros/prestação; [1013 r2](../1013/r2-widgets-interface.md) consome os inteiros percentuais quantizados. A normalização é síncrona e atômica; erro não produz sucesso parcial. Falhas aritméticas ou conversão fora da representação de destino retornam erro explícito, sem aceitar resultado aproximado como se fosse exato. Não há concorrência interna ou trabalho externo a cancelar.

Aplicam-se [1101](../../requirements/1101/r1-explicit-rate-kind.md), [1102](../../requirements/1102/r1-nominal-monthly.md), [1103](../../requirements/1103/r1-effective-monthly.md), [1104](../../requirements/1104/r1-annual-equivalents.md), [1105](../../requirements/1105/r1-invalid-rate-input.md) e [1106 refinado](../../requirements/1106/r1-unrounded-consumer-rate.md). O domínio de negócio, fórmulas e tolerâncias preservados não recebem nova aprovação por inferência; o delta de representação está explícito em 1025. Fontes, dedução de terminação e incidências: [1023](../../documents/1023/r1-numerical-resolution.md). Ainda não há plano aprovado, arquivo de produto, execução de validação ou verdict de requisito.
