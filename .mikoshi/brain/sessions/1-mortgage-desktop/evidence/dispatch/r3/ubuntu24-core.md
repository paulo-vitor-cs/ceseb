---
id: 2273
revision: 1
type: document
tags: [mortgage, validation, ubuntu, core, runtime]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Execução real do núcleo 57 em Ubuntu 24.04 com GCC 13 sem Qt e preparação de runtime Ubuntu24 separado sem ferramentas de desenvolvimento para validação da aplicação.
use_when:
- Recuperar evidências Linux de 1221 e as precondições isoladas do pacote usado nas demonstrações de 1215, 1216, 1217 e 1225.
---
# Núcleo Ubuntu 24.04 e ambiente de uso do aplicativo

## Resultado

O script original de independência do núcleo configurou, compilou e executou os casos financeiros com **exit0**, na fonte **57ef26901d4381ead16c7347483d588ad9d92efe**: **21/21 testes, zero falhas, erros ou skips**. O ambiente realmente usado é **Ubuntu 24.04.5 LTS, GCC 13.3.0**, em um contêiner Docker com kernel WSL compartilhado. Não é uma máquina com kernel Ubuntu separado. Antes de adicionar qualquer runtime gráfico, a enumeração das árvores acessíveis encontrou **zero Qt6Config.cmake, qmake ou libQt*.so**. A ligação do executável de testes inclui somente as bibliotecas C/C++, libm e libgcc de sistema, sem Qt.

Este retorno cobre a execução Linux de [1221 r1](../../../requirements/1221/r1-build-contract.md), sem atribuir um resultado independente ao requisito inteiro ou alegar execução Windows. A interface pública, o target ceseb_core e o script original foram lidos; não houve alteração de fonte, requisito ou oráculo. Os **70 arquivos do export Git permaneceram byte a byte iguais** ao snapshot 57.

## Autoridade e ownership

Subtarefa de /root/linux_app_validation_r3, sob o pedido humano de usar o aplicativo e testar os seis requisitos por outro método, seguido de “FAZ A PORRA DESSE PUSH E TESTA ESSA MERDA LOGO”. A delegação autorizou bootstrap reversível em contêiner próprio, sem alteração global de host. ROOT /home/paulo/ceseb e sessão 1-mortgage-desktop. Head próprio ubuntu24-validation, role dev, instância /root/linux_app_validation_r3/ubuntu24_core_environment. Native_id desconhecido; nenhum carregamento nativo de role/plugin é alegado. Root faz a publicação; este head não executou operações remotas Git.

Foram usados somente os contêineres próprios ceseb-validation-r3-ubuntu24 e ceseb-validation-r3-runtime24, arquivos operacionais em out/validation-r3/ubuntu24, este report e memória própria. A imagem oficial ubuntu:24.04 observada tem identidade ubuntu@sha256:24737cef17f4e22b1977df7d9a05e77c4e28b7da5b8911f8d8ccda136bf3573c. Não foram modificados pacotes, rede ou segurança do host, outros contêineres, dados de usuário, fontes de produto/testes, shared state, requisitos ou memórias alheias.

## Execução do núcleo

1. Pull da imagem oficial Ubuntu 24.04 e criação de contêiner próprio, com o export Git 57 montado read-only e somente fontes Boost 1.86.0/GoogleTest 1.17.0 verificadas anteriormente como inputs de dependência. Nenhum Qt SDK foi montado.
2. Instalação local no contêiner de g++-13, CMake 3.28, Ninja e certificados; inventário do sistema, compilador e ausência física Qt antes de GUI preservados.
3. Build de GoogleTest 1.17 com GCC 13 em prefixo próprio. A primeira tentativa parou porque a imagem mínima não possui alias cc; foi corrigido somente o argumento de invocação CMAKE_C_COMPILER=/usr/bin/gcc-13. O log da tentativa falha permanece; não houve correção de fonte.
4. Execução literal do script tests/system/check_core_independence.cmake do snapshot 57 com GUIOFF, Qt6 discovery disabled, GCC 13 e GTest recém-compilado, seguida de CTest completo core, XML e ldd.
5. Comparação dos 70 arquivos do export com o manifesto de entrada: iguais. A fonte tem o mesmo commit das execuções Windows atribuídas ao outro actor, sem qualquer edição manual de núcleo.

A condição de ausência física de Qt foi observada **antes** de instalar qualquer runtime GUI no contêiner do núcleo. Depois do teste concluído, nele também foram adicionados o DEB e utilitários GUI, conforme a solicitação inicial da delegação. Isso não é retroativamente a condição do teste core. Para eliminar esse acoplamento no teste de usuário final, foi criado o segundo contêiner limpo abaixo.

## Runtime limpo para usar o aplicativo

O contêiner separado **ceseb-validation-r3-runtime24** parte da mesma imagem Ubuntu 24.04, instala o DEB real pelo APT padrão e somente dependências de execução/desktop: Xvfb, Openbox, Python, libXtst, xdg-utils, PCManFM, D-Bus e AT-SPI. Não recebe fontes do núcleo, Boost/GTest, build dirs, Qt SDK nem compiladores. command -v retornou null para gcc, gcc-13, gcc-14, g++, g++-13, cc, c++, cmake, ninja, qmake e qmake6; nenhuma Qt6Config.cmake foi localizada. O pacote instalado é ceseb 0.1.0; o launcher global está em /usr/share/applications/ceseb.desktop e ldd resolve bibliotecas do prefixo privado e do sistema, sem missing dependencies.

O pacote usado é o DEB original da correção, SHA256 **6827856d68ad39d35490a31dfdec90df9fdf63f8e45bc95dfd103b06fdceb4b4**. O contêiner não é uma reconstrução de produto. A árvore privada /opt/ceseb é a instalação padrão do DEB; não se usa LD_LIBRARY_PATH para apontar SDK. O GUI driver do parent está montado read-only em /work/ui-driver, com captura/estado em /work/ui-evidence read-write. Nenhum diretório de fontes/dependências de desenvolvimento foi montado no runtime.

Após APT terminar com exit0, somente esse contêiner foi desconectado da bridge Docker, também exit0. A observação posterior mostra somente lo e tabela IPv4 sem rotas. Isso permite abrir ajuda e licenças com rede realmente indisponível no próprio ambiente do app, sem mudar a rede do host. Ownership exclusivo de execução do runtime24 foi liberado ao parent após o preflight; este head não executou inputs ou capturas em paralelo com ele.

## Evidência recuperável

[Resultado core e preservação do export](../../../../../../../out/validation-r3/ubuntu24/core-result.json)

[Script literal executado](../../../../../../../out/validation-r3/ubuntu24/run-core.sh)

[Execução completa core](../../../../../../../out/validation-r3/ubuntu24/core-execution.log)

[Primeira tentativa GTest preservada](../../../../../../../out/validation-r3/ubuntu24/core-execution-attempt1.log)

[XML dos 21 testes](../../../../../../../out/validation-r3/ubuntu24/core-evidence/all-core-results.xml)

[Inventário antes de GUI](../../../../../../../out/validation-r3/ubuntu24/core-evidence/installed-packages-before-gui.tsv)

[Enumeração Qt antes de GUI](../../../../../../../out/validation-r3/ubuntu24/core-evidence/qt-files-before-gui.txt)

[Ligação runtime core](../../../../../../../out/validation-r3/ubuntu24/core-evidence/runtime-links.txt)

[Preflight do runtime limpo](../../../../../../../out/validation-r3/ubuntu24/runtime-preflight.json)

[APT do runtime limpo](../../../../../../../out/validation-r3/ubuntu24/bootstrap-runtime-clean.log)

[Rede offline observada](../../../../../../../out/validation-r3/ubuntu24/runtime-offline-network.txt)

## Limites e handoff

Este head realizou compilação e execução core, inspeção do pacote instalado e preparação do desktop Ubuntu24. As demonstrações visuais, foco, teclado, erro/correção, escalas 100/200, rolagem, ajuda e abertura do gerenciador de licenças pertencem ao parent, que recebeu o runtime24 pronto e offline. A prova core 21 não substitui esses cenários e não é uma revisão independente.

Foram lidos CMakeLists, Dependencies.cmake, script original check_core_independence, requisito1221, source/export e cache de dependências, contratos Dispatch/code-implement e cards Git/head-memory/artifact-check. Não houve consulta nova de bibliotecas externas, Qt SDK, alteração de fonte, commit, push, requisito pass/fail ou criação de resultado mecânico falso. Report document draft; memória própria retorna ao parent. Próximo responsável: parent Linux valida efetivamente o app no runtime24 e integra esta evidência com a execução Windows e a revisão aplicável.
