---
id: 2421
revision: 1
type: document
tags: [mortgage, dispatch, implementation, correction, result]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Execução de2006 no produto3f4dc69 com paleta clara, ZIP sem DXC e demonstrações reais nos quatro recortes.
use_when:
- Receber a execução F3/F4, seus pacotes, cobertura e limites antes dos testes finais e Synapses independentes.
---
# Execução F3/F4

## Autoridade e corte

Executor `/root/f3_f4_product_executor`, Sol6.1, mesmo head `design-project-1/implementation-planning`, memória própria de entrada r15. Papel devr15 lido manualmente; native_id e carregamento nativo não observáveis. [1041](../../../../documents/1041/r1-f3-f4-correction-authority.md), [1042](../../../../documents/1042/r1-f3-f4-concrete-procedure-release.md) e [1040](../../../../documents/1040/r1-alternative-validation-and-branch-push.md) sustentam o recorte. [2006r1 publicado](../../../../plans/2006/r1-f3-f4-corrections.md) foi lido integralmente. Autoria Astra e execução Sol são a exceção expressa recebida. Nenhum efeito de produto ocorreu antes de `PRODUCT_RELEASE` do root após a leitura de [2411BASE](../tests/base-result.md).

ROOT/MAIN `/home/paulo/ceseb`; branch `codex/mortgage-desktop`. BASE_PRODUCT **98af104b0f38160aaf04ee2915f4d60e949d13aa**. PRODUCT_HEAD **3f4dc69ec84230b4035572fc62af3d13db451d2a**, commit `fix: keep Widgets light and omit optional DXC deployment`. Somente `src/ui/main_window.cpp` e `cmake/WindowsDeploy.cmake` foram staged/commitados por pathspec explícito. [Entrada e hashes](product-entry.json), [preservação dos quatro testes e exports](source-test-preservation.json), [commit coverage](product-commit-check.json). A comparação nativa BASE..PRODUCT é ok, dois modifies cobertos, unexpected_paths e dirty_planned_paths vazios. Sujeira Brain de outros owners foi preservada; não há claim de checkout global limpo.

O BASE recebido é genuíno: quatro controles escuros sem glifos, controles claros positivos, WSLaux e Windows em ambos backends/escalas; ZIP antigo c716 falha apenas pelas duas DLLs DXC presentes. O erro inicial de preparo setStyle do test executor não foi tratado como RED. Nenhum teste, oráculo financeiro, pin, README, spec/REQ ou plano publicado foi alterado aqui.

## D-1216

O construtor existente MainWindow aplica QApplication::setPalette antes de criar filhos. Paleta explícita cobre todos os pares/roles e grupos Active/Inactive/Disabled declarados em2006; QSS completa texto/seleção dos campos, combo/popup e QTextBrowser. Página nomeada simulationPage recebe o fundo neutro; diálogos e versão herdam a mesma composição clara. Sem helper/API pública, opção de tema, refactor financeiro, dependência nova ou configuração global do desktop.

Regressão recebida passou. [Contagens reais das suítes](suite-counts.json): **27/27 offscreen e27/27 XCB em Ubuntu24;27/27 offscreen e27/27 windows nativo; core-only21/21 em cada plataforma**, sem falhas/skips.27 significa20 casos de domínio, cinco slots GUI e dois inventários;21 significa20 domínio e inventário. Inventários não vazios nos logs. O novo slot1216 passou nos processos XCB escala1/2 e Windows offscreen/windows escala1/2; cada slot exercita as duas paletas. [Linux commands/exits](linux-execution.json), [Windows commands/exits](qualified-windows-execution.json), [Windows pixels1/2](windows-pixels.json), [Linux driver completo](linux-build.py). Os XMLs Linux ficam em ROOT/out/dispatch-r4/implementation/linux e os XMLs Windows acompanham este report. Pixels1/2 são renderização QtTest, separados da demonstração do aplicativo empacotado.

As quatro combinações reais800x600 lógicos foram executadas, com1000/0/600, Price599/SAC600, totalR$1.000,00 e aviso completo. [Geometria/identidades](actual-ui-four-combinations.json). Ubuntu24 usa X11/Xvfb2300x1900/Openbox no container runtime offline, janela800x600/1600x1200 físicos. Windows11 usa escala de processo1/2, DPI96 observado e cliente800x600/1600x1200. AppsUseLightTheme=0 e SystemUsesLightTheme=0 foram apenas lidos. Campos, botões, cartões, mensagens, totais e aviso foram vistos ou alcançados por teclado/rolagem vertical, sem scrollbar horizontal do formulário ou sobreposição impeditiva observada. Os cartões reorganizam verticalmente em800 lógicos. Texto preenchido, fundo da página, foco/seleção, popup, ajuda e revisão permaneceram legíveis.

Capturas conferidas diretamente incluem [Windows nominal100%](windows-ui/01-nominal-top.png), [Windows zero600100% rodapé](windows-ui/13-scale100-scroll-3.png), [Windows200% formulário real](windows-ui/22-zero600-visible-top.png), [Windows200% rodapé real](windows-ui/24-scroll-4-visible-bottom.png), [popup claro/seleção](windows-ui/20-popup-visible-top.png), [ajuda/versão200%](windows-ui/26-help-end-version-visible-bottom.png), [Ubuntu100% zero600](linux-ui/scale-1/08-zero600-top.png), [Ubuntu200% aviso/rodapé](linux-ui/scale-2/09-zero600-scroll-6.png) e [Ubuntu200% ajuda/versão](linux-ui/scale-2/11-help-top.png).

Windows200% excede a altura física1080 do monitor. O driver próprio move somente a janela foreground cujo PID/EXE foi conferido, entre Y0 eY-220. Cada captura é CopyFromScreen da interseção REAL visível com o monitor, com rects/horário em seus `.capture.json`; não usa PrintWindow nem transforma pixels fora da tela em prova. O desktop tem um mascote externo visível sobre parte de áreas em algumas capturas; ele não foi operado nem removido. As sequências de rolagem/posições dão acesso às áreas necessárias. Não alterei a escala/tema global.

Fluxos reais: nominal1000/12/3 produziu PriceR$1.020,07/SACR$1.020,00/diferença+0,07; efetiva produziu R$1.019,04/R$1.018,98/+0,06, equivalentes1,000000% nominal e0,948879% efetiva mensal. Tab/ShiftTab, erro principal0 e correção, invalidação de resultado, Limpar por Space, ajuda, versão literalPRODUCT_HEAD, licença local e Escape foram observados. [Windows valores](flow-results.json), [clearSpace](clear-space.json), [resultado200%/fechamento](scale200-final-result.json); logs/JSON operacionais completos em ROOT/out/dispatch-r4/implementation/windows. Ubuntu fluxos e capturas completos em ROOT/out/dispatch-r4/implementation/linux/ui-evidence-final/scale-1 e scale-2, com exit0 e nenhuma janela própria restante. Os dois novos file managers de licenças foram identificados por PID/path/alvo; janelas anteriores existentes permaneceram preservadas.

Um driver Windows tentou AltDown após foco UIA não efetivado num campo fora do viewport; o Escape fechou a própria aplicação. Essa tentativa ficou preservada em scale100-driver.log; o ensaio800x600 foi retomado num processo novo e scale100-final-driver.log terminou0. No roteiro200%, todas capturas/valores/abertura de licença ocorreram, depois Escape no main encerrou o app. O driver tentou ativá-lo de novo e terminou1 por PID ausente. [Consulta nativa final](final-close-query.json) terminou0 e confirmou o fechamento esperado. Não apresento esse exit1 operacional como teste de produto verde nem como falha do aplicativo. A demonstração concluída apoia-se nas ações anteriores e no fechamento diretamente confirmado.

## D-1225

A receita recebe somente `--no-system-dxc-compiler`, preservando as opções anteriores. Comentário explica Widgets raster e distinção da opçãoD3D. [Help do binário real](preflight-windeployqt-help.json) exit0 confirmou a opção antes do patch; fonteQtBase025bdad main.cpp472/1793..1801 foi aberta no archive existente. Sem filtragem de ZIP depois do deploy; stages de sucesso novos, sem resíduos antigos.

[Export imutável](source-export.json): **233 arquivos**, tar SHA256 **fc8fc1cc86910d3a1e8a5eb27e934847e7a19c4304894d71acf366dd3682224a**. Windows export em C:/Users/paulo/AppData/Local/CESEB/r4/implementation/source; Linux export privado no container /work/r4/implementation/source. SourceRevision literalPRODUCT_HEAD foi passado aos builds e recuperado nos EXE/manifestos. Não se reutilizou a alegação histórica de70 arquivos. Todos21 inputs históricos agora rastreados existem no export e foram comparados byte a byte com os novos pacotes; a atribuição histórica não foi reescrita.

| Entregável | SHA256 | Bytes | Inventário |
|---|---|---:|---|
| WindowsZIP | f5071e93d3c99afd4b5fae395322897c8d074f928f66952366eb0b05ad762d20 | 84400666 |188 arquivos/187 hashes/21 registros|
| UbuntuDEB |8dd414362fc06456a7aadaf44acb5a80264514497433d0ba24f240d129628336|97400034|184 arquivos/182 hashes/21 registros|

ZIP: `C:/Users/paulo/AppData/Local/CESEB/r4/implementation/packages-final/ceseb-0.1.0-windows-x86_64.zip`; [audit completo](windows-package-audit.json). DEB: `/home/paulo/ceseb/out/dispatch-r4/implementation/linux/packages-qualified/ceseb_0.1.0_amd64.deb`; [audit completo](linux-package-audit.json). SHA/source, todos hashes de manifesto, MIT/notices/source, histórico e inventário foram conferidos. O DEB tem mais dois arquivos fora do manifesto da árvore app: manifesto e atalho/usr. [RegressãoWindows recebida e links](windows-regression-checks.json) ambas0; launcher/linksDEB0 no [log de empacotamento final](linux-package-final-execution.json).

[PE closure](qualified-windows-pe-closure.json):22 AMD64 EXE/DLLs, import e delay-import, zero unresolved, resolvidos somente pacote/System32/API-set. [Ldd runtimeUbuntu](linux-runtime-ldd.json) cobre todos ELF reais com somente /opt/ceseb/lib no LD_LIBRARY_PATH da inspeção; nenhum notfound ou resoluçãoSDK. App real inicia sem esse LD_LIBRARY_PATH. [Mapas reais Linux](linux-runtime-modules.txt) identificam o EXE e Qt privados instalados. [Módulos Windows](windows-runtime-modules-check.json) identifica processo90 módulos, QtCore/Gui/Widgets apenas no pacote, nenhum dxcompiler.dll/dxil.dll. O lançamento de produção usou PATH=System32;Windows, removendo variáveis de pluginsSDK; PATHQt foi usado só nos processos separados dos testes. Não se observou recuperação dinâmica de DXC por SDK/System32 nos fluxos exercitados.

Builds privados reutilizados: Ubuntu24.04.5/GCC13.3.0/CMake3.28.3/Ninja1.11.1 e WindowsCommunity17.14.43/cl19.44.35229/SDK10.0.26100.0/CMake3.31.6-msvc6/Ninja1.12.1. [PreflightUbuntu](preflight-ubuntu24.json), [Windows](preflight-windows-tools.json). Qt6.12, Boost1.86 e GTest1.17 existentes; nenhum download, instalação global ou versão nova. Os oito CRTCommunity e termos originais foram comparados antes de guardON, e a lista gerada foi novamente conferida antes de install: [qualificação](preconfigure-crt-qualification.json), [lista efetiva](qualified-windows-crt-preinstall.json). Não se aplicaram termosCommunity a BuildTools.

Falhas operacionais preservadas: primeiroCPackUbuntu1 por falta concreta de file; reuso privado de file/libmagic/magic do runtime24 e Perl/dpkg-shlibdeps já instalados no host, executados sobre o banco Ubuntu24, resolveu sem instalar/adquirir. A primeira invocação privada tinha basename `.pl`, causando warning de detecção da versão; corrigido o nome do driver e gerado stage/pacote novo qualified, sem warning e com dependênciasUbuntu24. [Reuso](package-tools-reuse.json), drivers/logs linux-package*. A primeira instalaçãoWindows1 apontava a área histórica inexistente do wrapper; configure de evidência foi corrigido para o export233 e stage-final vazio, install0/CPack0 em [retorno final](windows-package-final-execution.json). Erros de cópia de XML core eram paths do wrapper; core-only havia terminado0. Nenhum patch de produto adicional foi necessário. Um WSLvsock110 anterior aos pixelsWindows foi preservado; repetição idêntica depois executou os quatro processos0.

## D-1228

[Mapeamento por componente](notices-component-mapping.json) confere127 hashes de materiais originais por pacote, componentes efetivamente presentes e seus avisos recuperáveis. MIT aplica-se ao app; QtBase e plugins mantêm textosGPL/LGPL, SBOMs, terceiros transitivos, archive exato025bdad e nenhuma modificação Qt. ICU acompanha seu aviso no Linux; Boost e avisoGoogleTest de materiais de build são preservados; CRTWindows mantém edição/termos originais e oito DLLs qualificadas. A substituição das bibliotecas dinâmicas continua possível; não há QtTest/compilador/ferramenta de build no pacote do usuário.

[Delta real do ZIP](windows-inventory-delta.json): somente dxcompiler.dll/dxil.dll removidas; cinco imagens/XML/JSON docs/validation/r3 adicionados porque já pertencem ao source export atual. Nenhuma DLL nova. Avisos/fontes dos demais componentes foram preservados e seus hashes conferidos. ArchivesQtBase por plataforma podem ter bytes gzip distintos; ambos identificam o mesmo commit exato e são recuperáveis no inventário. Não se inventou licençaDXC nem reescreveu o fail antigo c716. Esta inspeção é do conjunto entregue, sem certificação jurídica geral.

## Limites e encaminhamento

Os builds/testes/pacotes e demonstrações acima são autovalidação do executor. Não constituem Synapses independente nem veredito integral de REQ/spec. Windows contém SDK fisicamente instalado; PATH/closure/módulos privados não provam máquina Windows limpa. RuntimeUbuntu24 é o container offline existente, atualizado pelo novo DEB; não alego uma nova instalação de SO limpa. Linux X11/Xvfb é desktop virtual Ubuntu24, não monitor físicoLinux; Windows é desktop real com capturas visíveis. Não houve alteração de metadata normativa/status, push, PR, merge, release, tag, CI manual ou promoção. O syncer conserva a autoridade de push1040 após as etapas independentes.

Ownership Ubuntu compiler/runtime e Windows UI foi devolvido explicitamente ao root depois do fim dos processos próprios, permitindo o test executor original concluir2412. Próximos responsáveis: testFINAL do head separado, Synapses independente, analyst e syncer. Artefatos operacionais r2/r3, snapshots57 e pacotes antigos permanecem preservados.

Leitura efetiva: memória própria r15;2006 completo;2402;1040/1041/1042;2411 completo;need1001/1005;1216/1225/1228 íntegros;1013r2/1014r3; dev15/Dispatch13/code-implement9; contratos authority/revisions, verification/status, reviewboundaries/logicalmemory;cards2301/2302/2303/2305/2306r2/4188/4189/2521/2523/2570;2231r3 e listaCRT, com comparação byte a byte dos termos originais atribuídos a2231r3; sourceMainWindow/WindowsDeploy/CMake/tests/QtBase025bdad e drivers anteriores copiados para r4 antes de adaptar. Context7/Serena não foram expostos; nenhuma chamada/instalação alegada. Leitura manual de fonte é fallback, sem claim de carregamento nativo de papel ou boot completo.

Checks finais: [plan check](executed-plan-check.json), [commit check final](product-commit-check-final.json) e [artifact/links](result-check.json), todos exit0/resultok. [Ordem e consulta de fechamentoWindows](windows-close-order.json) conserva a sequência, erros e horários de gravação/captura sem inventar timestamp do processo. Memória própria session_memory/design/implementation-planning.yaml atualizada para r18, execução concluída e ownership liberado.

```mikoshi-result-v1
- kind: plan
  artifact:
    path: ../../../../plans/2006/r1-f3-f4-corrections.md
    id: 2006
    revision: 1
  range:
    base: 98af104b0f38160aaf04ee2915f4d60e949d13aa
    head: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  procedure: complete
  tasks:
  - id: D-1216
    result: complete
    evidence: '#d-1216'
  - id: D-1225
    result: complete
    evidence: '#d-1225'
  - id: D-1228
    result: complete
    evidence: '#d-1228'
```
