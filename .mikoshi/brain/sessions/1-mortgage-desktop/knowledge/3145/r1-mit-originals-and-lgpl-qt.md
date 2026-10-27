---
id: 3145
revision: 1
type: knowledge
tags: [mortgage, research, qt, delivery]
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: MIT dos originais e opção LGPLv3 de Qt exigem avisos, fonte correspondente e substituição sob os termos exatos.
use_when:
- Preparar o inventário e os materiais de uma entrega dinâmica Qt sem atribuir MIT aos componentes de terceiros.
---
# MIT dos originais e Qt dinâmico sob LGPLv3

A [MIT](https://opensource.org/license/mit), texto OSI lido em 2026-10-26, permite reutilização conservando copyright e permissão; não altera a licença de Qt. Nas unidades v6.8.3 [QObject](https://raw.githubusercontent.com/qt/qtbase/v6.8.3/src/corelib/kernel/qobject.h), [QGuiApplication](https://raw.githubusercontent.com/qt/qtbase/v6.8.3/src/gui/kernel/qguiapplication.h), [QWidget](https://raw.githubusercontent.com/qt/qtbase/v6.8.3/src/widgets/kernel/qwidget.h), [Fusion](https://raw.githubusercontent.com/qt/qtbase/v6.8.3/src/widgets/styles/qfusionstyle.cpp), [Windows QPA](https://raw.githubusercontent.com/qt/qtbase/v6.8.3/src/plugins/platforms/windows/qwindowsintegration.cpp) e [xcb QPA](https://raw.githubusercontent.com/qt/qtbase/v6.8.3/src/plugins/platforms/xcb/qxcbmain.cpp), os cabeçalhos oferecem LGPL-3.0-only como alternativa a licenças comercial/GPL. Isso apoia a seleção LGPL do design, sem constituir varredura de todos os arquivos.

O texto exato [LGPLv3 da tag](https://raw.githubusercontent.com/qt/qtbase/v6.8.3/LICENSES/LGPL-3.0-only.txt), §§3–4, exige avisos de uso, cópias GPL/LGPL e respeito à modificação/engenharia reversa para depuração da biblioteca. §4d permite mecanismo compartilhado adequado, que opere com biblioteca modificada compatível, ou materiais para recombinar/relinkar. §4e condiciona informações de instalação ao caso aplicável. Link dinâmico, isoladamente, não satisfaz essas condições.

A distribuição dos próprios binários Qt precisa de modalidade válida de fonte correspondente. [GPLv3 da tag](https://raw.githubusercontent.com/qt/qtbase/v6.8.3/LICENSES/GPL-3.0-only.txt), §1 e §6d, inclui scripts necessários e admite servidor terceiro com direções claras junto ao binário; a responsabilidade de disponibilidade permanece. Inferência para a entrega: identificar fonte exata, modificações e configuração, sem apontar apenas para a página inicial de Qt.

Contraevidência: [Qt Licensing 6.8](https://doc.qt.io/qt-6.8/licensing.html), módulos GPL, mostra que a mesma alternativa não vale para todo módulo. Adicionar Charts ou Wayland Compositor pode mudar o exame. Textos GPL acompanhantes não significam, por si, que os originais MIT mudaram de licença. Condições de EULA devem preservar direitos aplicáveis de cada componente.

Leitura: cabeçalhos específicos, LGPL integral e unidades GPL indicadas, não todo Qt. Não há inventário/pacote existente para certificar. Nota documental para implementação futura de [1228](../../requirements/1228/r1-distribution-notices.md), com limites em [3003](../../documents/3003/r1-distribution-research-compilation.md); não é conclusão jurídica individual.
