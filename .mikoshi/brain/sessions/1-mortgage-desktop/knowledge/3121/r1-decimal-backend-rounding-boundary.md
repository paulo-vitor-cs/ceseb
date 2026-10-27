---
id: 3121
revision: 1
type: knowledge
tags:
- mortgage
- research
- technology
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Garantias documentais de cpp_dec_float_50 1.86 e a lacuna de prova em arredondamentos monetários exatos.
use_when:
- Escolher ou revisar o método que converte resultados decimais em centavos half-up.
---
# Limite entre precisão decimal e empate monetário

## Claim

O tipo cpp_dec_float_50 do Boost 1.86 não fornece, por ter 50 dígitos, uma garantia de que juros calculados a partir de qualquer taxa mensal aproximada cairão no lado matematicamente correto de todo empate half-up.

## Evidência e condições

[Manual 1.86](https://www.boost.org/doc/libs/1_86_0/libs/multiprecision/doc/html/boost_multiprecision/tut/floats/cpp_dec_float.html), página cpp_dec_float, lida integralmente em 2026-10-26: ponto flutuante decimal, operações truncantes e guard digits. [Fonte boost-1.86.0](https://github.com/boostorg/multiprecision/blob/boost-1.86.0/include/boost/multiprecision/cpp_dec_float.hpp), trechos de divisão/inversa e floor: aritmética finita, seguida de arredondamento do valor representado. Essa é evidência documental/estática, sem execução.

Inferência analítica: principal 6 centavos, nominal anual 100%, n=1 dá m=1/12 e juros exatos=0,5 centavo; a política [1012 r1](../../specs/1012/r1-amortization-comparison.md) exige 1 centavo. Um erro pequeno pode cruzar a fronteira. Operações seguintes podem arredondar novamente; esta nota não afirma o resultado efetivo de qualquer expressão C++ específica. A taxa sem arredondamento de apresentação continua uma aproximação finita quando a fração é recorrente.

A tolerância de taxa 1e-12 em [1102](../../requirements/1102/r1-nominal-monthly.md) admite até 0,01 centavo de erro no produto por saldo de 10^10 centavos. Esse limite não implica igualdade monetária exata no empate. O exemplo com m=0,005 terminante não testa a mesma dificuldade. Isto é dedução da tolerância e das unidades, coordenada com FIN, não medida de erro da biblioteca.

## Contraevidência e limites

[Issue 368](https://github.com/boostorg/multiprecision/issues/368), respostas de mantenedores de 2021/2022/18-01-2024, confirma problemas históricos de divisão seguida de floor/ceil e diferenças entre versões. Não demonstra o caso acima no pin 1.86 ou nos compiladores escolhidos. Muitos valores distantes da fronteira podem produzir os centavos corretos; não se conclui inadequação universal de Boost. Guard digits ajudam a precisão, mas não fornecem prova do domínio inteiro.

A implementação da inversa usa estimativa inicial double e refinamento decimal; entrada textual sem double não significa ausência de double em todo detalhe interno. Não há aqui garantia de identidade bit a bit entre plataformas.

## Uso e validação pendente

O specialist deve justificar o método de decisão de fronteiras, considerando caminhos exatos para valores racionais ou certificação adequada quando necessária, sem adoção implícita nesta nota. Propor ensaio isolado do pin nos dois toolchains com oráculo racional independente, expressão/otimização e dígitos registrados. Um caso aprovado não substitui argumento de cobertura. Consumidores: autor do método numérico e futuros planos de testes 1102/1106/1202..1206. Ver [compilação 3002](../../documents/3002/r1-technology-research-compilation.md), T2 e validação futura. Draft; não altera o design ou o oráculo.

