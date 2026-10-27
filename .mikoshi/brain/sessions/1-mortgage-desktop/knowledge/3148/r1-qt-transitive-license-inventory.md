---
id: 3148
revision: 1
type: knowledge
tags: [mortgage, research, qt, delivery]
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Licenças das bibliotecas transitivas de Qt dependem da configuração e do conteúdo efetivo, incluindo componentes embutidos sem DLL própria.
use_when:
- Fechar inventário de terceiros do Qt distribuído sem deduzir licenças apenas dos nomes das DLLs ou módulos públicos.
---
# Inventário de terceiros inclui código embutido em Qt

A [documentação Qt 6.8 de licenças](https://doc.qt.io/qt-6.8/licensing.html), Third-Party Code/SBOM, distingue terceiros e informa SBOM desde 6.8. Um SBOM do fornecedor é insumo para conferir o build, não prova de que todos seus componentes entraram no pacote do aplicativo.

Na tag QtBase v6.8.3, a [attribution HarfBuzz](https://raw.githubusercontent.com/qt/qtbase/v6.8.3/src/3rdparty/harfbuzz-ng/qt_attribution.json) registra versão 10.4.0, uso opcional por QtGui, alternativa system/bundled e MIT. O [COPYING](https://raw.githubusercontent.com/qt/qtbase/v6.8.3/src/3rdparty/harfbuzz-ng/COPYING), integralmente lido, exige avisos/disclaimers e remete a licenças particulares em subdiretórios. A configuração bundled pode incorporar código sem arquivo `.dll` separado.

A [attribution FreeType](https://raw.githubusercontent.com/qt/qtbase/v6.8.3/src/3rdparty/freetype/qt_attribution.json) registra 2.13.3 e uso opcional em Gui/plataformas. [LICENSE](https://raw.githubusercontent.com/qt/qtbase/v6.8.3/src/3rdparty/freetype/LICENSE.txt), seleção de licença, e [FTL.TXT](https://raw.githubusercontent.com/qt/qtbase/v6.8.3/src/3rdparty/freetype/docs/FTL.TXT), §2, distinguem opções e exigem preservação de arquivo/alterações em fonte e crédito ao FreeType em documentação de binários sob FTL. Não se seleciona GPLv2 apenas porque aparece como alternativa.

Contraevidência a “Core/Gui/Widgets significa só LGPL”: as unidades acima têm textos próprios. Contraevidência a “todo item da árvore3rdparty é distribuído”: ambos são condicionais, e system libs podem ser dependências do SO em vez de payload privado.

Inferência: fechar inventário por build/configuração e arquivos, conferir licenças e avisos do que entrou direta ou estaticamente, e identificar plugins desnecessários que a coleta tenha trazido. Esta pesquisa leu exemplos materiais, não toda a árvore thirdparty nem o payload binário. Não se certifica o pacote inexistente. A evidência e o futuro responsável estão em [3003](../../documents/3003/r1-distribution-research-compilation.md).
