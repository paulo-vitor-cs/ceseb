---
id: 3122
revision: 1
type: knowledge
tags:
- mortgage
- research
- technology
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Semântica de QDoubleValidator e QLocale 6.8.3 frente a parsing estrito pt-BR e centavos inteiros.
use_when:
- Implementar ou revisar parsing e formatação monetária sem passar valores financeiros por double.
---
# Gramática de entrada e fronteira monetária Qt

## Claim

No Qt 6.8.3, um QDoubleValidator padrão e uma conversão QLocale para double não realizam sozinhos a gramática estrita nem a representação monetária em centavos do projeto.

## Evidência e condições

[qvalidator.cpp v6.8.3](https://github.com/qt/qtbase/blob/v6.8.3/src/gui/util/qvalidator.cpp), unidade QDoubleValidator 471..677, lida em 2026-10-26: notação científica padrão; separadores de grupo dependem do locale e sua posição não é verificada pelo validator; conversão numérica usa double. fixup pode alterar casas textuais. Esta é a fonte fixada, não conclusão transferida de documentação latest.

[qlocale.h](https://github.com/qt/qtbase/blob/v6.8.3/src/corelib/text/qlocale.h) e [qlocale.cpp](https://github.com/qt/qtbase/blob/v6.8.3/src/corelib/text/qlocale.cpp), overloads e corpos currency 4332..4412: inteiros são formatados em unidades monetárias inteiras; o overload fracionário usa double. Não há overload decimal50/centavos tipados. Apenas passar 100 centavos ao overload integral não o transforma em R$ 1,00.

A gramática [1211 r1](../../requirements/1211/r1-localized-input.md) recusa sinal/expoente, formato inglês e sétima casa, aceita agrupamento brasileiro correto e limita casas. [1013 r1](../../specs/1013/r1-widgets-interface.md) exige MoneyCodec sem conversão monetária por double. São escolhas do produto aceito, não regras atribuídas a Qt.

## Consequência inferida

O adaptador deve verificar sintaxe e limites antes de produzir centavos inteiros e texto decimal canônico da taxa. Formatação monetária pode decompor inteiro em parte inteira e resto de dois dígitos, preservando o sinal da diferença. É uma inferência de arquitetura compatível com MoneyCodec, não um código ou algoritmo aprovado nesta nota. O locale pode fornecer símbolos/separadores sem ser o oráculo financeiro. A apresentação percentual tem política distinta, registrada em [3126](../3126/r1-explicit-percentage-rounding.md).

## Contraevidência e limites

Qt oferece validators personalizados e expressão regular; não existe impedimento ao contrato escolhido. Configurar StandardNotation/RejectGroupSeparator pode resolver partes da gramática, mas não demonstra agrupamento correto, centavos exatos ou recusa sem fixup. Esta nota não afirma que todo uso de Qt com double dá centavos errados, nem que seria obrigatório trocar a biblioteca. Não foi executado nenhum widget ou teste de parsing.

## Consumidor e pendência

Autores de controlador, MoneyCodec e plano de 1211/1213/1214 devem conferir formatos positivos/negativos e overflow antes de conversão. Validar fixtures exatas e grupos mal posicionados nos dois ambientes. A escolha concreta do parser permanece do plano/método autorizado. [Compilação 3002](../../documents/3002/r1-technology-research-compilation.md), T4. Draft, sem resultado de requisito.

