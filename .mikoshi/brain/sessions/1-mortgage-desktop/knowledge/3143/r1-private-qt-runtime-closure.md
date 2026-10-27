---
id: 3143
revision: 1
type: knowledge
tags: [mortgage, research, qt, delivery, cross-platform]
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Qt privado exige fechamento de bibliotecas, plugins e dependências de sistema no pacote e ambiente exatos.
use_when:
- Planejar ou inspecionar ZIP Windows e DEB Ubuntu com Qt dinâmico privado e validação em ambiente limpo.
---
# Qt privado não elimina dependências transitivas

No [deployment Windows Qt 6.8](https://doc.qt.io/qt-6.8/windows-deployment.html), The Windows Deployment Tool, windeployqt coleta Qt e plugins, mas não resolve todos os terceiros. O runtime MSVC Release pode ser coletado como instalador redistribuível; presença desse instalador não entrega automaticamente DLLs app-local para um ZIP extraível.

No [deployment Linux Qt 6.8](https://doc.qt.io/qt-6.8/linux-deployment.html), Shared Libraries/Application Dependencies, linker e busca de plugins precisam ser configurados. O plugin X11 é `platforms/libqxcb.so`; bibliotecas Qt privadas não substituem X11/fontes/drivers do sistema. Os [requisitos X11](https://doc.qt.io/qt-6.8/linux-requirements.html), tabela Platform Plugin Dependencies, incluem xcb-cursor, xkbcommon-x11, Fontconfig e FreeType. Pacotes `-dev` dessa página destinam-se a compilar Qt; não são a lista runtime do DEB.

O [CPack DEB 3.28](https://cmake.org/cmake/help/v3.28/cpack_gen/deb.html), PACKAGE_ARCHITECTURE/DEPENDS/SHLIBDEPS/PRIVATE_DIRS, documenta `amd64`, geração com dpkg-shlibdeps opcional e caminhos de bibliotecas privadas. Inferência: executar cpack sem regras install, RPATH e dependências corretas não prova completude.

Contraevidência a “qualquer Qt 6 funciona”: [Deploying Plugins](https://doc.qt.io/qt-6.8/deployment-plugins.html), Loading/Verifying, impõe limites de major/minor e configuração; [compatibilidade Qt](https://doc.qt.io/qt-6.8/qt-releases.html#binary-compatibility) depende de toolchain, ambiente e configuração. Não misturar MSVC/MinGW, debug/Release ou plugins de outro kit.

Condições e limites: fechar imports e plugins carregados dinamicamente no artefato final, limpar ambiente de desenvolvimento e testar na distribuição alvo. Não foi feito levantamento ELF/PE nem teste limpo. XWayland ainda exige servidor X disponível; Wayland nativo não é implicitamente qualificado por essa baseline. Material de pesquisa em [3003](../../documents/3003/r1-distribution-research-compilation.md); nenhum pacote foi construído.
