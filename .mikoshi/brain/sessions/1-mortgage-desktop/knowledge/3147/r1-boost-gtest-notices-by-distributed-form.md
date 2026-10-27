---
id: 3147
revision: 1
type: knowledge
tags: [mortgage, research, delivery]
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Licenças Boost 1.86.0 e GoogleTest 1.17.0 diferenciam fontes e binários efetivamente entregues.
use_when:
- Separar dependências de desenvolvimento dos avisos necessários nos arquivos de fonte ou binários realmente distribuídos.
---
# Avisos de Boost e GoogleTest dependem do conteúdo entregue

O [texto Boost Software License na tag1.86.0](https://raw.githubusercontent.com/boostorg/boost/boost-1.86.0/LICENSE_1_0.txt), lido integralmente em 2026-10-26, exige copyright e texto da licença em cópias e derivados, com exceção expressa para conteúdo exclusivamente em objeto executável gerado por processador de linguagem. Portanto, ser header-only não elimina avisos quando headers/fontes forem distribuídos. A decisão de incluir aviso Boost também no ZIP/DEB pode ser política conservadora do projeto, distinguida do alcance literal dessa exceção.

O [LICENSE GoogleTest v1.17.0](https://raw.githubusercontent.com/google/googletest/v1.17.0/LICENSE), lido integralmente, exige preservação de copyright, condições e disclaimer em fontes e sua reprodução em documentação/materiais de distribuições binárias; restringe uso de nomes para endosso. Não transforma GoogleTest em conteúdo do aplicativo final quando ele não é entregue.

No design [1014](../../specs/1014/r1-reproducible-delivery.md), GoogleTest e QtTest são de desenvolvimento. A unidade [qtestcase.h v6.8.3](https://raw.githubusercontent.com/qt/qtbase/v6.8.3/src/testlib/qtestcase.h), cabeçalho SPDX, oferece LGPLv3 entre alternativas; não há base para chamar todo QtTest de GPL-only. Isso não classifica todos os testes, exemplos ou ferramentas de Qt.

Contraevidência a um aviso genérico “tudo é MIT”: esses textos conservam regimes próprios mesmo no repositório de aplicativo MIT. Contraevidência a “dependência não runtime nunca exige avisos”: arquivos vendorizados, testes binários e materiais de build podem ser distribuídos separadamente.

Inferência de engenharia: inventariar separadamente o que sai em ZIP/DEB, árvore de fontes e artefatos de CI; manter os textos exatos dos arquivos realmente entregues. Não foram construídos pacotes ou inspecionadas fontes vendorizadas, que ainda não existem neste recorte. Nota sem parecer de conformidade, com proveniência completa em [3003](../../documents/3003/r1-distribution-research-compilation.md).
