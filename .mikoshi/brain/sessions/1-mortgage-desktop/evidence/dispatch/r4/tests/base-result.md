---
id: 2411
revision: 1
type: document
tags: [mortgage, dispatch, tests, base-result]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Base real das regressões F3/F4 no produto inalterado, com cobertura dos quatro assets e execução final pendente.
use_when:
- Receber TEST_HEAD antes da correção de produto e retomar o mesmo head para o ensaio final.
---
# Resultado BASE F3/F4

## Identidade e autoridade

Executor `/root/f3_f4_test_executor`, head `design-project-1/test-planning`, dev, instância Sol6.1 recebida pelo dispatch do root; native_id e carregamento nativo do papel não observáveis. Devr15 lido manualmente. Memória própria de entrada r12; não houve full boot. [1041](../../../../documents/1041/r1-f3-f4-correction-authority.md), [1042](../../../../documents/1042/r1-f3-f4-concrete-procedure-release.md) e [1040](../../../../documents/1040/r1-alternative-validation-and-branch-push.md) foram lidos diretamente. Corpo [2005r1](../../../../plans/2005/r1-f3-f4-regressions.md) publicado lido integralmente antes dos efeitos, com report BASE2411/final2412 prevalecendo sobre IDs futuros históricos da memória. Produto pertence ao head separado2006 e permanece inalterado nesta base.

ROOT `/home/paulo/ceseb`; BASE `b5bb61c7a9a73f3a9174044621a7497dc274d0f3`; TEST_HEAD `98af104b0f38160aaf04ee2915f4d60e949d13aa`. `35cdf93adc67f58933059737d549f1e94786bd40` criou/modificou somente os quatro assets; `98af104b0f38160aaf04ee2915f4d60e949d13aa` corrige exclusivamente uso da sobrecarga void de QApplication::setStyle no preparo. Nenhum oráculo foi relaxado. Índice vazio antes da primeira edição; dois modifies antigos hash-identificados e dois creates ausentes. Os43 paths rastreados selecionados em src/include/cmake/tests/CMakeLists eram idênticos à fonte57; este denominador explícito não substitui o inventário55 do root. Produto permanece byte-identical. Evidência operacional: `out/test-evidence/dispatch-r4/base/preconditions.json` e `preservation.json` em ROOT.

## BASE T1216

MainWindow real existente, Fusion, paletas herdadas clara e escura antes de construir cada janela800x600. Entradas1000/0/600 calculadas; assertivas Price599/SAC600/aviso não vazio e quatro textos existentes. Capturas interiores excluem moldura/seta, foco no botão e seleção removida; sinais bloqueados para par cheio/vazio, texto restaurado, geometria/DPR iguais. Guarda RAII restaura paleta e estilo pelo nome. Cada um dos quatro controles exige pixels diferentes por glifos, sem QColor/QSS como oráculo.

WSL Ubuntu26/GCC15.2 auxiliar: configure0, primeira build1 de preparação (void não conversível para bool), corrigida em commit próprio; configure2/build2 ambos0. Logs originais preservados; build1 não é RED. Qt6.12.0/GTest1.17/Boost1.86 privados existentes, CMake3.28.6/Ninja1.13.1; comandos completos/exits/env em `out/test-evidence/dispatch-r4/base/wsl-*.json` e versions.json. LD_LIBRARY_PATH somente no processo usa cache SDK privado e kit Qt; nenhum install global.

Base comportamental RED em offscreen e XCB/WSLg, processos separados QT_SCALE_FACTOR1 e2, todos com exit1 do slot. Controles claros principal/taxa/prazo/combo:345/35/155/1337 pixels diferentes em DPR1;1014/101/463/3937 em DPR2. Paleta escura: **zero nos quatro controles**, em ambos backends/escalas. Pares PNG e XML preservados nas pastas `wsl-pixels-BACKEND-ESCALA`; contagens em pixel-counts.json. Observei diretamente o par principal claro preenchido e escuro preenchido: texto legível versus fundo branco sem glifos. Isto demonstra o defeito do recorte, não toda leitura nativa do requisito.

CTest BASE offscreen e XCB: **27 entradas reais,26 pass/1 fail,0 skips**, exit8; única falha1216 nova. Os20 testes de domínio, quatro slotsGUI anteriores e dois inventários passaram. Logs/XML `wsl-ctest-offscreen`/`wsl-ctest-xcb` em ROOT/out/test-evidence/dispatch-r4/base. Core21 aqui é subconjunto domínio+inventário; core-only separado/final ainda será executado quando previsto.

Windows nativo Community2022/MSVC19.44: export imutável35 em C:/Users/paulo/AppData/Local/CESEB/r4/tests/base/source, build irmão, confirmou mesma preparação void/build1; ambos preservados. Nova exportação imutável `98af104b0f38160aaf04ee2915f4d60e949d13aa` em `C:/Users/paulo/AppData/Local/CESEB/r4/tests/base/attempt2/source`, build irmão. Configuração/build nativos2 e quatro processos pixels1/2 offscreen/windows têm comandos/exits em `out/test-evidence/dispatch-r4/base/windows-attempt2/windows-execution.json`; wrappers copiados, sem executar driver histórico r2 nem sobrepor fonte antiga. SDKs usados read-only de r2; PATH Qt é apenas do teste. Resultado nativo: configure0/build0; slot exit1 em offscreen1/2 e windows1/2, exclusivamente ABSENT GLYPHS dark nos quatro controles. Offscreen claro212/16/72/970(DPR1),856/72/296/3904(DPR2); windows claro232/20/97/942(DPR1),725/66/307/2598(DPR2); escuro0/0/0/0 em todos. ParesPNG/XML copiados para windows-attempt2; source-integrity.json comprova233 arquivos exportados sem diferença. Este ensaioQtTest não é a demonstração de pacote final Windows/Ubuntu24.

## BASE T1225 e T1228

ZIP antigo real fonte `57ef26901d4381ead16c7347483d588ad9d92efe`, `/mnt/c/Users/paulo/AppData/Local/CESEB/r2/community-packages/ceseb-0.1.0-windows-x86_64.zip`, SHA256 **c71634da99c2efe7774db55e011883b2c12f001db7a972404093f7c05968da4b** conferido antes de extraçãoPython zipfile em ROOT/out/test-evidence/dispatch-r4/base/windows-extracted; sem links para checkout. Inventário integral zip-inventory.json.

Comando `.mikoshi/cache/toolchains/cmake-3.28.6-linux-x86_64/bin/cmake -DCESEB_PACKAGE_ROOT=/home/paulo/ceseb/out/test-evidence/dispatch-r4/base/windows-extracted -P tests/system/check_windows_component_notices.cmake`, exit1. **RED de conteúdo exclusivamente por bin/dxcompiler.dll e bin/dxil.dll realmente presentes**; executável, QtCore/Gui/Widgets, plugins/platforms/qwindows, LICENSE/THIRD_PARTY_NOTICES e todos10 materiais declarados não vazios foram encontrados. Log package-check.log. Não é inspeção de flag, ZIP vazio, falta de runtime, extração falha ou hash divergente. Nenhum arquivo do ZIP antigo foi refeito ou alterado. A identidade do produto57 em BASE permite usar o entregável retido sem alegar novo build BASE.

T1228 reutiliza esse instrumento para F3/AC2, mantendo atribuição própria. Inspeção completa de inventário novo, resoluçãoPE/imports, comparaçãohash dos materiais/DEB e abertura com runtime privado ainda depende dos pacotes de produto. Não alego ensaioABI, máquina sem SDK instalado, auditoria jurídica ou pass integral1225/1228.

## Cobertura e preservação

`mikoshi plan check-commits --root /home/paulo/ceseb --plan .../plans/2005/r1-f3-f4-regressions.md --base b5bb61c7a9a73f3a9174044621a7497dc274d0f3 --head 98af104b0f38160aaf04ee2915f4d60e949d13aa --json`: exit0/resultok,4/4 operações cobertas, unexpected_paths vazio, dirty_planned_paths vazio. `commit-check.json` preserva resultado completo incluindo sujeira Brain de outros owners. Plan check/artifact links também exit0/ok. Somente quatro paths de teste foram staged/commitados por argumentos explícitos; teste financeiro, gui_test_main, produto, README, CI, planos publicados, shared state e reports anteriores preservados.

Leitura direta: memória própria integralr12; plano2005 integral;1040/1041/1042; report2401; devr15; dispatchr13/code-implementr9/delegated-context/nativebrief; contratos authority/revisions, verification/status, review-boundaries e result-transition; cards4188/4189/2521/2523/2570 e projeto2301/2303; necessidade1001, specs1013r2/1014r3, requisitos1216/1225/1228; testes CMake/guiheader/gui_main/1214 e construção/estilos de MainWindow pertinentes; driver qualified-windows-run.py e run_linux.py como referência de meios. Descoberta native ALL_TOOLS sem Context7/Serena; nenhuma chamada/instalação alegada. Não li todoBrain nem transformei evidência antiga em observação nova.

## Continuação

Procedimento2005 **partial**, todas três tarefas **incomplete** porque BASE precede produto e a parte final obrigatória ainda não ocorreu. Root recebe BASE+TEST_HEAD e pode liberar autor produto2006. Este mesmo head permanece trabalho inacabado: aguardar PRODUCT_HEAD commitado, novos ZIP/DEB/hash/source e ownership do runtimeUbuntu24/desktopWindows; executar scripts inalterados, suítes27/core21, leitura real de pacote Windows/Ubuntu100/200 e inspeção1228; retornar2412. Não houve mudança de status/resultado de requisito, remoto, PR, merge ou promoção.

```mikoshi-result-v1
- kind: plan
  artifact:
    path: ../../../../plans/2005/r1-f3-f4-regressions.md
    id: 2005
    revision: 1
  range:
    base: b5bb61c7a9a73f3a9174044621a7497dc274d0f3
    head: 98af104b0f38160aaf04ee2915f4d60e949d13aa
  procedure: partial
  tasks:
  - id: T1216
    result: incomplete
    evidence: '#base-t1216'
  - id: T1225
    result: incomplete
    evidence: '#base-t1225-e-t1228'
  - id: T1228
    result: incomplete
    evidence: '#base-t1225-e-t1228'
```
