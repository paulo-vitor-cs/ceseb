---
id: 3125
revision: 1
type: knowledge
tags:
- mortgage
- research
- technology
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Operações log1p e expm1 do Boost 1.86 e a diferença entre domínio textual da GUI e domínio tipado.
use_when:
- Escolher a avaliação de conversão e anuidade quando taxas positivas pequenas podem causar cancelamento.
---
# Estabilidade de avaliação para taxas pequenas

## Claim

As formas estáveis com log1p/expm1 são meios documentados para reduzir cancelamento em valores pequenos. Não estabelecem, sozinhas, a igualdade de centavos ou a cobertura de todo o domínio tipado.

## Fontes e condições

[Boost.Math log1p 1.86](https://www.boost.org/doc/libs/1_86_0/libs/math/doc/html/math_toolkit/powers/log1p.html) e [expm1 1.86](https://www.boost.org/doc/libs/1_86_0/libs/math/doc/html/math_toolkit/powers/expm1.html), páginas integrais lidas em 2026-10-26: APIs templadas, políticas e mecanismos para evitar cancelamento de log(1+x) e exp(x)-1 quando x é pequeno. As tabelas empíricas publicadas usam tipos/compiladores próprios, não são reprodução de decimal50 em MSVC 2022/GCC 13.

Dedução algébrica para m>0: a anuidade pode ser avaliada como P*m / -expm1(-n*log1p(m)). Para entrada efetiva anual a conversão é expm1(log1p(p/100)/12). Zero tem ramo próprio. Essas expressões preservam o modelo [1008](../../specs/1008/r1-annual-rate-conversion.md)/[1012](../../specs/1012/r1-amortization-comparison.md); seleção final de algoritmo e overloads pertence ao método/plano autorizado. Argumentos intermediários devem permanecer no tipo decimal pretendido.

A GUI aceita até seis casas anuais e seu menor positivo é 0,000001%. A interface tipada não estabelece esse piso: um percentual decimal representável muito menor continua na faixa positiva de 0..100. Um teste da menor entrada da GUI não cobre automaticamente esse domínio; em precisão finita, 1+x pode se tornar 1. Essa conclusão é analítica, sem ensaio do backend.

## Contraevidência e limites

A expressão direta pode ser suficientemente precisa em muitos valores usuais, especialmente com 50 dígitos. Isso não certifica todos os extremos. A forma estável reduz uma fonte de erro, mas não resolve automaticamente empates half-up discutidos em [3121](../3121/r1-decimal-backend-rounding-boundary.md). Nem as fontes nem a limitação de 600 meses medem tempo de resposta ou latência da aplicação.

## Consumidor e validação futura

Specialist numérico e autor do plano: confrontar formas candidatas com referência independente, incluindo zero, menor positivo da GUI, pequenos positivos tipados,100% nos dois tipos, n=1/600 e limites monetários admissíveis. Preservar erro de avaliação, underflow, admissibilidade e arredondamento como resultados distintos. Nenhum benchmark, programa ou teste foi executado. [Compilação 3002](../../documents/3002/r1-technology-research-compilation.md), T3. Nota draft, sem alteração de domínio.

