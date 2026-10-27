---
id: 2006
revision: 1
type: plan
tags:
- mortgage
- dispatch
- implementation
- correction
- windows
status: implemented
created: '2026-10-27'
updated: 2026-10-27
description: Corrigir a aparência clara sob paleta Windows escura e omitir DXC opcional do ZIP Widgets,
  verificando a composição e execução reais.
use_when:
- Executar somente as correções F3/F4 autorizadas após o retorno dos testes de base e liberação do corpo
  concreto.
---
# Correções F3 e F4

## Context

Kind: implementation. Autoridade: [1041 r1](../../documents/1041/r1-f3-f4-correction-authority.md), que registra o pedido humano literal `$mikoshi:mikoshi-dispatch dev para corrigir esses erros`; [1040 r1](../../documents/1040/r1-alternative-validation-and-branch-push.md) mantém validação alternativa e push pela etapa syncer. Fontes: [2281 r2](../../evidence/synapses/r3/dev-review-r2.md), [2281 r1](../../evidence/synapses/r3/dev-review.md), [2222 r1](../../evidence/dispatch/r2/implementation/2222-r1-qualified-windows-result.md), [1013 r2](../../specs/1013/r2-widgets-interface.md), [1014 r3](../../specs/1014/r3-wsl-validation-delivery.md). Os planos 2002/2003 e todos os resultados anteriores permanecem preservados.

ROOT/MAIN/workspace=/home/paulo/ceseb; sessão 1-mortgage-desktop; branch codex/mortgage-desktop. Entrada documental b5bb61c7a9a73f3a9174044621a7497dc274d0f3; produto previamente executado 57ef26901d4381ead16c7347483d588ad9d92efe. BASE_PRODUCT será o commit real após o autor separado concluir e commitar os testes, antes de qualquer modificação de produto; registrar o SHA no report, não alterar este corpo publicado.

Autoria Astra: /root/f3_f4_product_author. Execução exclusivamente pelo sucessor Sol 6.1 designado pelo root, mesmo head design-project-1/implementation-planning e mesma memória session_memory/design/implementation-planning.yaml. Esta é a exceção escopada expressa no Dispatch r13 recebido. Leitura manual de dev r15 observada; native_id e readback do carregamento nativo não disponíveis. A autoria termina antes da execução. O autor/test executor separado possui os testes; produto não os edita.

## Decisões técnicas dentro da correção

A spec 1013 r2 já pede Fusion com paleta clara. A seleção Fusion em appmain não define todas as cores herdadas; o código fixa fundos brancos de entrada sem texto e deixa o QWidget da página herdar fundo escuro. Aplicar a política clara na construção já existente MainWindow cobre o entry point e permite o teste de regressão chamar o mesmo código sob paleta hostil. Não criar API/helper público, tema selecionável, biblioteca ou mudança global do Windows. Completar cores explícitas da própria aplicação, incluindo seleção, popup e diálogo. Alternativas descartadas: corrigir apenas appmain deixaria o teste da MainWindow sem exercitar a política; pintar apenas texto deixaria página/versão escuras e baixo contraste.

O QtBase exato 025bdad181de241e81bf853c8a2d7bf3d19261a9, fonte já distribuída, define em src/tools/windeployqt/main.cpp:472 a opção --no-system-dxc-compiler e em 1793..1801 explica sua necessidade apenas para Direct3D12 e certos recursos. CMake e UI atuais usam Widgets/Core/Gui e desenho raster de controles, sem QtQuick/QML/D3D12. Omitir estes componentes opcionais é o menor remédio; não inventar seus termos nem apagar DLLs depois de empacotar. A escolha depende de fechamento PE e execução real sem carregamento DXC. Se a execução revelar dependência, interromper o efeito dependente e devolver a evidência ao root; não substituir esta escolha por licença presumida. Estas decisões são técnicas do autor sob1041, não escolhas humanas novas.

## Procedure and Effects

1. Ler o corpo efetivamente liberado, registrar BASE_PRODUCT, status Git, hashes dos dois paths e dos testes recebidos. Receber do test executor o RED comportamental de aparência sob paleta escura e o RED de composição no ZIP antigo c71634da99c2efe7774db55e011883b2c12f001db7a972404093f7c05968da4b; falha de ambiente/API ausente não vale como RED. Receber também controles de base e os comandos dos testes. Nenhum produto muda antes desse retorno e da liberação do root.
2. Aplicar D-1216 e D-1225 somente nos dois paths declarados. Preservar cálculos, oráculos, testes, pins, README raiz, fontes e evidência anteriores. Nenhuma instalação global, mudança de tema Windows, novo SDK, refactor ou alteração normativa.
3. Rodar a regressão recebida durante o ajuste; não enfraquecê-la. Commitar somente os dois paths de produto por pathspec explícito. Registrar HEAD_PRODUCT real e exportar esse commit imutável com hashes. Builds/pacotes recebem CESEB_SOURCE_REVISION=HEAD_PRODUCT; nunca anunciar57 ou b5 como revisão de binário novo. Evidência documental externa permanece allowlist de21 registros históricos, com sua atribuição antiga.
4. Reusar toolchains privados já preparados. Linux: Ubuntu24/GCC13 no contêiner existente out/validation-r3/ubuntu24, Qt6.12/Boost1.86/GTest1.17 e CMake/Ninja efetivamente inventariados. Windows: VSCommunity2022 v14319.44, SDK10.0.26100.0, CMake3.31.6-msvc6/Ninja1.12.1, kitQt6.12 msvc2022_64 e dependências/notices de C:/Users/paulo/AppData/Local/CESEB/r2/source/build/dependencies; conferir versões/cache antes de reuso. Usar novos builds, stages, exports e packages próprios r4, sem sobrescrever r2/r3. Sem aquisição ou instalação nova.
5. Configurar/build Release Linux e Windows. Rodar suíte completa CTest GUI nos backends offscreen e XCB/windows respectivos, inventário não vazio, regressão nova e core-only GUIOFF. Guardar logs/JUnit, contagens reais e falhas. Reusar drivers anteriores somente após copiar para área própria e ajustar todos os destinos e SourceRevision. A presença física do SDK não é prova de sua ausência.
6. Gerar DEB por CPack/DESTDIR e ZIP por install/CPack, em stages vazios próprios. Conferir CRTCommunity e termos/readback2231r3 antes de CESEB_MSVC_REDIST_QUALIFIED=ON. A nova opção windeployqt deve estar disponível no --help do binário observado. Confirmar ausências DXC/DXIL na árvore final, todos os hashes do manifesto, versão/plataforma/revisão, notices/fontes exatas e21registros. Reusar regressões de launcher/documentação do2003. Fazer fechamento de imports/delay-imports PE para todos os EXE/DLL do ZIP e ldd/RPATH/plugins do DEB, sem resolver Qt via SDK.
7. Executar aplicativo extraído do novo ZIP e novo DEB, com PATH de runtime sem ferramentas/QtSDK e identificação de EXE/PID/hash. No Windows registrar tema existente AppsUseLightTheme/SystemUsesLightTheme somente leitura e executar no estado escuro real. Observar módulos carregados para comprovar que DXC/DXIL não foram recuperados de SDK/System32 por acaso. Executar entradas, cálculo nominal/efetivo, popup de tipo, seleção/foco, erro/correção, Limpar, Sobre/modelo/versão/licenças e fechar. Conferir os oráculos financeiros existentes sem alterá-los.
8. Demonstrar1216 nas quatro combinações: Ubuntu24 e Windows11,100%/200%,800x600 lógicos, cenário1000/0/600, todos os campos/rótulos/cartões/mensagens e aviso alcançáveis por teclado/rolagem, sem sobreposição impeditiva/rolagem horizontal. Capturas devem mostrar texto preenchido, página, versão e diálogo legíveis. Linux usa X11/XTest/Xvfb/Openbox existente; Windows usa UIAutomation/SendKeys com guard EXE/PID/foreground/WTS desbloqueado autorizado1040, sem operar apps alheios. Registrar geometria, DPI físico e escala de processo; não converter pixels fora do monitor em prova visível. Havendo tela bloqueada real, devolver ao root necessidade de desbloqueio; erro ComputerUse não impede os meios alternativos já autorizados. Se ambiente não for uma instalação limpa, registrar esse limite literal.
9. Executar D-1228. Salvar resultado completo em evidence/dispatch/r4/implementation/result.md e assets próprios, com BASE/HEAD, arquivos, comandos/saídas, identidade dos pacotes, screenshots, critérios e gaps. Executar mikoshi plan check e plan check-commits no range BASE_PRODUCT..HEAD_PRODUCT; exigir cobertura dos dois modifies e nenhuma mudança planejada suja/inesperada. Validar report/links. Entregar ao root para Synapses independente e syncer/push já autorizados; não emitir status de REQ/spec ou alegar revisão independente. Retorno parcial preserva toda evidência e o próximo responsável.

Outputs operacionais próprios: build/dispatch-r4/implementation e out/dispatch-r4/implementation no Linux; C:/Users/paulo/AppData/Local/CESEB/r4/implementation no Windows. São outputs de build, não novos paths de fonte. O executor pode criar drivers/logs somente dentro da sua evidence/dispatch/r4/implementation e áreas operacionais. Não sobrescrever fontes congeladas nem pacotes antigos.

## Tasks

### Task D-1216

Requirement: [1216 r1](../../requirements/1216/r1-resize-access.md)

Kind: implementation

Method: No início de MainWindow, antes de criar filhos, definir paleta clara explícita da aplicação via QApplication::setPalette. Fixar os pares Window/WindowText, Base/Text, AlternateBase, Button/ButtonText, ToolTipBase/ToolTipText, Highlight/HighlightedText, PlaceholderText, Link/LinkVisited com cores coerentes com a composição clara atual, incluindo estados Active/Inactive/Disabled. Completar QSS de entradas/combo com texto escuro e seleção azul/texto branco; atribuir objectName à página e fundo neutro explícito, preservando fundo branco dos cartões e borda azul de foco. Cobrir QTextBrowser e diálogo herdado/versão com a mesma paleta clara. Não depender da paleta atual do sistema nem somente de Fusion::standardPalette. Preservar layout e comportamento. A regressão constrói a MainWindow existente sob paleta escura e verifica renderização real; demonstração externa usa o EXE de produção.

Dependencies: retorno dos testes de base e liberação deste corpo pelo root.

#### Files

| Operation | Path | Destination |
|---|---|---|
| modify | src/ui/main_window.cpp | - |

Completion evidence: Regressão recebida passa e falha antiga fica preservada; nas quatro combinações de1216 os valores dos campos e conteúdos são visíveis/alcançáveis, incluindo página, popup e versão. Capturas e identidades recuperáveis; limites reais de plataforma separados do resultado.

### Task D-1225

Requirement: [1225 r1](../../requirements/1225/r1-runtime-packages.md)

Kind: implementation

Method: Acrescentar --no-system-dxc-compiler à chamada windeployqt existente, mantendo --no-system-d3d-compiler e demais opções. Acrescentar comentário curto explicando Widgets raster e a opção DXC separada. Não remover outros componentes, alterar CRT/notices, filtrar ZIP pronto ou suprimir auditoria. Empacotar stage novo para que resíduos antigos não permaneçam. Auditar a composição real e abrir pacote fechado após PE closure, incluindo observação de módulos dinâmicos.

Dependencies: testes base; fonte Qt exata e --help observado; commit de D-1216 e deste patch para pacote conjunto.

#### Files

| Operation | Path | Destination |
|---|---|---|
| modify | cmake/WindowsDeploy.cmake | - |

Completion evidence: ZIP novo sem dxcompiler.dll/dxil.dll, regressão de composição passa, dependências estáticas e carregadas resolvidas sem DXC, startup e fluxos reais funcionam; manifesto/revisão e DEB de regressão auditados. Esta correção do AC1 não inventa ambiente limpo para o AC3.

### Task D-1228

Requirement: [1228 r1](../../requirements/1228/r1-distribution-notices.md)

Kind: implementation

Method: Inspecionar o efeito de D-1225 sobre os componentes efetivamente entregues e preservar os avisos MIT/Qt/Boost/CRT existentes e fonte Qt exata. Comparar inventário/manifesto com todos os materiais presentes, inclusive componentes transitivos. A retirada declarada dos dois componentes opcionais elimina a obrigação de distribuí-los com avisos no novo ZIP; não reescreve o fail do ZIP antigo. Confirmar que nenhum outro componente sem materiais foi introduzido. Não há arquivo de produto adicional: o único patch necessário é propriedade de D-1225 e esta tarefa verifica o efeito compartilhado no AC2/4.

Dependencies: D-1225 e pacote final com hashes.

#### Files

| Operation | Path | Destination |
|---|---|---|

No changed files. Reference-only: cmake/WindowsDeploy.cmake, cmake/ThirdPartyNotices.cmake, THIRD_PARTY_NOTICES.md, LICENSE, inventário/notices/fontes reais nos novos ZIP/DEB. O commit-check não exige alteração artificial; reportar separadamente a inspeção.

Completion evidence: Inventário completo mapeia cada componente distribuído aos avisos/fontes recuperáveis; DXC/DXIL ausentes. Regressão e auditoria rastreáveis do novo pacote, sem inferir licença a partir de assinatura Microsoft ou de um nome genérico Qt.

## Tools and limits

Cards locais2301r1/2302r1/2303r1/2305r1/2306r2; cards de plugin plan4189r2, commit4188r2, artifact2521r9 e memory2523r17. Context7/Serena não expostos nesta instância; leitura da fonte exata instalada é fallback com limite explícito. Não há novo material choice identificado. Independência de revisão, vereditos integrais e sincronização remota pertencem às etapas posteriores. Não há PR, merge, tag, release ou alteração de versão autorizada por este plano.
