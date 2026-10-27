---
id: 3146
revision: 1
type: knowledge
tags: [mortgage, research, delivery, tools]
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: CRT MSVC app-local é uma rota documentada condicionada à edição licenciada, REDIST e manutenção dos arquivos permitidos.
use_when:
- Planejar um ZIP Windows com CRT app-local sem copiar DLLs arbitrárias ou presumir termos da edição MSVC ainda não selecionada.
---
# CRT MSVC app-local: acesso e redistribuição condicionados

A Microsoft documenta instalação de DLLs redistribuíveis na pasta do executável, mas prefere implantação central por manutenção. [Redistribute Visual C++ files](https://learn.microsoft.com/en-us/cpp/windows/redistributing-visual-cpp-files?view=msvc-170), atualizado 2026-04-15, seções Licensing/Individual files, condiciona redistribuição à licença Visual Studio e seus termos. A atualização de cópias privadas torna-se responsabilidade do distribuidor.

A [lista REDIST VS 2022](https://learn.microsoft.com/en-us/visualstudio/releases/2022/redistribution), Distributable Code/Visual C++ Runtime Files, permite arquivos indicados sob termos da edição e exclui `debug_nonredist`. Sua existência não permite copiar qualquer DLL do compilador, de System32 ou de um kit Qt. Versão, x64, procedência e conjunto efetivo precisam ser registrados no plano.

Os [termos Community 2022](https://visualstudio.microsoft.com/wp-content/uploads/2021/11/Visual-Studio-2022-Community-License-EN.docx), §4, lidos nos parágrafos OOXML 37–48, dão direitos sobre a lista e exigem funcionalidade primária e termos protetivos para código Microsoft; restringem previews, marcas e sujeição do código distribuível aos termos excluídos ali definidos. Inferência: limitar MIT aos originais e separar avisos/termos Microsoft, preservando também os direitos LGPL de Qt. Não se propõe EULA que impeça substituição das bibliotecas Qt.

Contraevidência a “windeployqt resolve o ZIP”: a [documentação Qt](https://doc.qt.io/qt-6.8/windows-deployment.html), Windows Deployment Tool, descreve que o Release MSVC pode coletar o instalador redistribuível destinado a instalação recursiva, não necessariamente as DLLs app-local necessárias ao ZIP portátil.

Limites: a edição realmente usada ainda é desconhecida. O [DOCX Build Tools de março2024](https://visualstudio.microsoft.com/wp-content/uploads/2024/03/Visual-Studio-2022-Diagnostic-Build-Tools-Agent-License_Update-March-2024_EN.docx) retornou 403 e o wrapper [CRT2015–2022](https://visualstudio.microsoft.com/license-terms/vs2022-cruntime/) não ofereceu corpo legível nesta rota. Community é fonte de condições dessa edição, não substituto dos termos Build Tools. Não foi ativada licença ou inspecionada instalação MSVC. A viabilidade é documental, pendente da edição, do payload e do teste limpo, conforme [3003](../../documents/3003/r1-distribution-research-compilation.md).
