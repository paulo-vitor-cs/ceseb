---
id: 3126
revision: 1
type: knowledge
tags:
- mortgage
- research
- technology
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Diferença entre o formatter de precisão cpp_dec_float 1.86 e a apresentação percentual half-up do projeto.
use_when:
- Implementar ou revisar exibição percentual de seis casas sem herdar desempate para par do formatter genérico.
---
# Half-up percentual exige política explícita

## Claim

A formatação de precisão genérica do cpp_dec_float em Boost 1.86 usa desempate para par em seu caminho de string. Isso não é a regra half-up de seis casas exigida por [1212 r1](../../requirements/1212/r1-rate-presentation.md).

## Fonte e unidade

[cpp_dec_float.hpp boost-1.86.0](https://github.com/boostorg/multiprecision/blob/boost-1.86.0/include/boost/multiprecision/cpp_dec_float.hpp), método str, especialmente 1830..1853, lido em 2026-10-26: verifica próximo dígito 5, paridade e resto zero para manter o dígito par. É leitura estática do pin; nenhum formatter foi executado.

## Caso discriminante analítico

Percentual anual nominal 0,000006% está dentro das seis casas aceitas pela GUI. O percentual mensal exato é 0,0000005%. O contrato half-up exige 0,000001%. Para uma fixture que represente exatamente o percentual 0.0000005, desempate para par em seis casas produz 0,000000%. O exemplo foi sugerido pelo orquestrador e reconciliado com a semântica da fonte.

Há duas verificações diferentes: formatter com fixture decimal exata; e pipeline anual→mensal→percentual→texto. No segundo, divisões anteriores também podem aproximar a fronteira. Esta nota não afirma o texto que um programa ainda inexistente produziu. A divergência é entre políticas, não um bug observado da aplicação.

## Uso, contraevidência e limites

A maioria dos valores afastados de empate pode coincidir nas duas políticas. Os exemplos usuais 12% não distinguem necessariamente o formatter. Implementar quantização explícita antes de converter para texto pode cumprir o requisito sem substituir Boost; isso é proposta de meio, não decisão automática. Não mudar o oráculo para imitar o default. A taxa integral continua independente da apresentação conforme 1106.

Consumidores: autor da apresentação e plano de 1212. Validar os dois caminhos nos toolchains fixados e conservar o texto esperado por política. A nota trata formatação percentual; garantias de juros exatos e recorrência ficam em [3121](../3121/r1-decimal-backend-rounding-boundary.md). [Compilação 3002](../../documents/3002/r1-technology-research-compilation.md), T5. Draft, sem pass/fail de produto.

