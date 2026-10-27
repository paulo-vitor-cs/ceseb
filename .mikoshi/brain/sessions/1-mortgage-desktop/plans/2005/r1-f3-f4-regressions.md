---
id: 2005
revision: 1
type: plan
tags:
- mortgage
- dispatch
- test-plan
- bounded-correction
status: implemented
created: '2026-10-27'
updated: 2026-10-27
description: Regressões de pixels da janela sob paleta escura e composição real do ZIP para F4/F3, antes
  da correção do produto.
use_when:
- Executar o recorte autorizado por 1041 nos requisitos 1216, 1225 e 1228.
---
# Regressões F3/F4

## Context and authority

Kind: tests. ROOT/MAIN `/home/paulo/ceseb`; sessão `.mikoshi/brain/sessions/1-mortgage-desktop`; flow `design-project-1`; head `test-planning`, owner `dev-test-planning`, memória `session_memory/design/test-planning.yaml`. Autor Astra `/root/f3_f4_test_author`; executor Sol 6.1 em instância fresca do mesmo head, conforme exceção explícita em [1041](../../documents/1041/r1-f3-f4-correction-authority.md). Produto pertence a outro head/plano2006. O root confere este corpo concreto antes de liberar os testes. Este draft não autoriza sua própria execução.

Fontes: [pedido1001](../../documents/1001/r1-human-request.md), [1013r2](../../specs/1013/r2-widgets-interface.md), [1014r3](../../specs/1014/r3-wsl-validation-delivery.md), [review2281r2](../../evidence/synapses/r3/dev-review-r2.md), [F3 original](../../evidence/synapses/r2/dev-review.md#f3--materiais-de-licença-e-avisos-dxc-ausentes), [Windows2271r2](../../evidence/dispatch/r3/windows-validation-r2.md) e [Linux2272](../../evidence/dispatch/r3/linux-validation.md). Preservar corpos2001/2004, requisitos/specs e todos os reports históricos.

Base conhecida `b5bb61c7a9a73f3a9174044621a7497dc274d0f3`; fonte do ZIP antigo `57ef26901d4381ead16c7347483d588ad9d92efe`. Capturar BASE real antes da primeira edição de teste e verificar a identidade dos paths produto/testes entre57 e BASE. ZIP antigo: `/mnt/c/Users/paulo/AppData/Local/CESEB/r2/community-packages/ceseb-0.1.0-windows-x86_64.zip`, SHA256 `c71634da99c2efe7774db55e011883b2c12f001db7a972404093f7c05968da4b`. Não recompilar nem adulterar esse ZIP para fabricar RED. Produto só muda após retorno dos testes-base e commit TEST_HEAD.

## File Structure

| Operation | Path | Owner |
|---|---|---|
| modify | tests/CMakeLists.txt | dev-test-planning |
| modify | tests/gui/gui_tests.hpp | dev-test-planning |
| create | tests/gui/req1216_inherited_palette_test.cpp | dev-test-planning |
| create | tests/system/check_windows_component_notices.cmake | dev-test-planning |

Não alterar gui_test_main.cpp, testes financeiros, produto, README ou CI. CMake adiciona somente fonte/slot1216 e inventário correspondente. Não registrar pacote em CTest: pacote é input posterior ao build. Cada novo arquivo conserva SPDX MIT/copyright. Saídas operacionais em `out/test-evidence/dispatch-r4/`; reports em `evidence/dispatch/r4/tests/`; quatro paths acima são o universo de cobertura de commit, não esses logs.

## Tasks

### Task T1216

Requirement: [1216 r1](../../requirements/1216/r1-resize-access.md)
Kind: test
Method: Regressão QtTest com renderização real de MainWindow e demonstração dos pacotes nas quatro combinações.

#### Files

| Operation | Path | Destination |
|---|---|---|
| modify | tests/CMakeLists.txt | - |
| modify | tests/gui/gui_tests.hpp | - |
| create | tests/gui/req1216_inherited_palette_test.cpp | - |

Adicionar slot `req1216_inherited_palette`; reutilizar classe GuiContractTests, gui_fixture::Form e MainWindow existentes. Nenhuma API de produto nova. Salvar/restaurar paleta e estilo QApplication por guarda RAII; executar Fusion em duas condições locais: paleta clara de controle e paleta escura hostil (Window/Button cinza escuro, Base escura, Text/WindowText/ButtonText branco; grupos Active/Inactive/Disabled explicitados). Aplicar cada paleta ANTES de construir a janela real. A correção acordada com autor2006 entra no construtor MainWindow e é portanto exercitada sem replicar a correção no teste.

Janela800x600; preencher1000/0/600 e calcular pela fixture; confirmar os quatro valores não vazios, resultado Price599 e SAC600 pelos rótulos existentes. Tirar foco das entradas, remover seleção e estabilizar eventos antes de capturar. Para cada QLineEdit capturar via grab/render sua região interior de texto, salvar texto e bloquear sinais, trocar somente texto por vazio, capturar de novo com mesma geometria/paleta/foco, restaurar; no QComboBox não editável trocar temporariamente apenas itemText selecionado por vazio com sinais bloqueados e restaurar. Excluir bordas/cursor/seta do recorte, manter tamanho fixo durante o par, verificar tamanho e devicePixelRatio iguais. Exigir diferença de pixels no interior atribuível aos glifos para CADA um dos quatro controles, acumulando falhas e salvando pares de imagens/contagem. Branco sobre branco produz zero pixels diferentes; borda azul ou seta não podem suprir texto ausente. Não substituir o oráculo por QColor esperado, valor de palette(), string QSS ou inspeção de código. A paleta hostil é fixture; não é um limiar novo de contraste. Diferença de pixels demonstra presença, não legibilidade suficiente; a leitura nativa abaixo é obrigatória.

Executar o slot com QT_SCALE_FACTOR1 e2 em processos separados (escala precisa existir antes de QApplication), backend offscreen e posteriormente windows/XCB. Não enfraquecer o oráculo após observar base; erro de construção/coleção/foco/render indisponível não é RED. Se houver ruído de cursor/geometria, corrigir exclusivamente preparação e preservar tentativa original; o par sem texto tem de permanecer idêntico fora dos glifos.

Depois do produto: repetir pacote real em Windows11 e Ubuntu24.04 nos cenários de2271r2/2272, com cliente800x600 lógicos e escalas de processo1/2. Windows conserva AppsUseLightTheme0/SystemUsesLightTheme0 observados read-only; nenhuma mudança global. Registrar teclado/rolagem, conteúdo completo de campos/cartões/aviso599/600, cabeçalho, prazo, diferença, rodapé e versão/ajuda. Capturas reais devem permitir ler textos; UIA/AT-SPI não substituem pixels. Em200% Windows, monitor1920x1080 não cobre cliente1600x1200 inteiro: mover somente janela própria para trazer cada região relevante ao monitor, capturar áreas realmente visíveis e registrar geometria; não dar pass por pixels PrintWindow fora da tela. Registrar qualquer região não demonstrada como lacuna. Ubuntu reutiliza X11 privado2300x1900. Não criar preferências de tema ou novo critérioWCAG.

### Task T1225

Requirement: [1225 r1](../../requirements/1225/r1-runtime-packages.md)
Kind: test
Method: Inspeção automática do ZIP real e abertura do pacote final com runtime privado.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/system/check_windows_component_notices.cmake | - |

Input `CESEB_PACKAGE_ROOT`: raiz de ZIP extraído novo, identificado por hash/revisão, sem symlink para checkout. Exigir bin/ceseb.exe, Qt6Core.dll, Qt6Gui.dll, Qt6Widgets.dll, plugins/platforms/qwindows.dll e LICENSE/THIRD_PARTY_NOTICES.md não vazios. Fazer glob recursivo e normalizar nomes para minúsculas: acumular e reprovar qualquer dxcompiler.dll ou dxil.dll em qualquer subpasta. Esta é a composição mínima Widgets acordada com2006: não distribuir compilador/validadorDXC opcional, conforme fonte Qt exata já lida pelo autor2006. O teste examina entregável, nunca flags de WindowsDeploy. Um ZIP que omite tudo não passa pelas precondições de runtime. Se a implementação retiver DXC, o teste falha; uma rota alternativa com avisos requer revisão explícita do plano, não heurística que aceite menções inventadas.

Verificar os materiais acompanhantes já declarados, confirmados na extração antiga: `licenses/boost-LICENSE_1_0.txt`, `licenses/googletest-LICENSE.txt`, `licenses/qtbase/LICENSES/GPL-3.0-only.txt`, `licenses/qtbase/LICENSES/LGPL-3.0-only.txt`, `licenses/qtbase/sbom/qtbase-6.12.0.spdx.json`, `licenses/qtbase/config_qtbase.opt`, `licenses/qtbase/config_qtbase.summary`, `licenses/source/qtbase-025bdad181de241e81bf853c8a2d7bf3d19261a9.tar.gz`, `licenses/msvc/edition.txt` e `licenses/msvc/Visual-Studio-2022-Community-License-EN.docx`, todos não vazios. Não impor arquivo novo de licença. Falta de arquivo declarado é falha de conteúdo; diretório/ZIP inexistente, extração falha ou hash não correspondente é indisponibilidade. Não confundir o sucesso desse recorte com todos os ACs1225.

Comando depois de extrair com Python3 zipfile/CMake em diretório próprio: `cmake -DCESEB_PACKAGE_ROOT=/home/paulo/ceseb/out/test-evidence/dispatch-r4/base/windows-extracted -P tests/system/check_windows_component_notices.cmake`; repetir sem mudar script em `final/windows-extracted`. ZIPc716 deve falhar por duas DLLs efetivamente presentes antes de qualquer patch. Preservar inventário/diagnósticos completos.

Final: ler auditoria PE/imports do produtor, verificar hashes/revisão do novo ZIP, abrir seu EXE com PATH Windows/System32, observar módulos Qt/plugins/CRT privados e concluir cenário real acima. Não alegar máquina Windows sem SDK instalado: é execução sem caminhos de desenvolvimento. No Ubuntu instalar novoDEB na área privada runtime24 preservando pacote anterior, conferir launcher/bibliotecas/metadados e abertura. O produtor fornece ZIP/DEB final e source commit; testes não reempacotam fonte diferente.

### Task T1228

Requirement: [1228 r1](../../requirements/1228/r1-distribution-notices.md)
Kind: test
Method: Inspeção independente de inventário e materiais realmente entregues, sem alterar fontes.

#### Files

| Operation | Path | Destination |
|---|---|---|

Sem alteração de arquivo autoral. Reusar checker deT1225 como instrumento, atribuir separadamente seu resultado ao recorteF3/AC2. Listar DLLs/plugins/CRT efetivos do ZIP e bibliotecas doDEB, conferir contra manifesto de hashes e THIRD_PARTY_NOTICES entregue. Verificar textos originais, SBOM, fonte Qt025bdad incluída, ausência de modificações declarada, licençaMIT restrita a originais e termosMSVC previamente qualificados; comparar materiais inalterados ao pacote anterior, preservar proveniência. O desaparecimento deDXC exige inventário sem alegar que ele continua entregue. Confirmar zero dependênciaPE obrigatória sem resolução, inclusive DXC/DXIL; um pacote sem avisosQt/CRT não passa por simplesmente removerDXC. Não certificar juridicamente, baixar nova licença ou reconstruirQt. A substituibilidadeQt é inspeção de ligação dinâmica/configuração existente; não alegar ensaioABI não executado. Reportar resultadoAC2/F3 e limites dos outrosACs ao reviewer.

## Exact execution sequence and environments

1. Root libera corpo; executor verifica HEAD/índice, hashes dos antigos testes, paths de produto inalterados e versões. Escreve quatro assets, roda GUI base real e checker sobre ZIPc716. Registra comportamentoRED ou indisponibilidade distintamente. Commit somente quatropaths, cobertura nativa BASE..TEST_HEAD e retorno base ao root/produtor. Nenhum patch de produto antes desse retorno.
2. Produtor2006 recebe tests e preserva oráculo. Executor espera PRODUCT_HEAD commitado e pacotes com hashes/source. Reexecuta scripts e suíte inteira existente acrescida de um slot. A suíte atual observada em tests/CMakeLists é20casos domínio +4slotsGUI +2inventários=26; passa a27. Core-only continua21 (20+inventário); check_core_independence é procedimento separado, não entrada extra da suíteGUI. Registrar contagem real, nunca inferir27 só de exit0.
3. Rodar CTest `--output-on-failure --no-tests=error --output-junit` offscreen e backend nativo, inventário `ceseb_gui_tests -functions`, `ceseb_domain_tests --gtest_list_tests`. Rodar o novo slot isolado a escala2 além de suíte a escala1. Não mudar os20oráculos financeiros nem quatroGUI anteriores.

Windows: reutilizar literalmente a seleção de ferramentas e flags de `evidence/dispatch/r2/implementation/qualified-windows-run.py` como referência, sem executar esse driver histórico que escreve r2. Export imutável novo `C:/Users/paulo/AppData/Local/CESEB/r4/tests/base/source` (ou `final/source`), build irmão `build`; nenhum build dentro de source. `vcvars64.bat` em `C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/Build`; CMake/Ninja em `Common7/IDE/CommonExtensions/Microsoft/CMake/{CMake/bin,Ninja}` da mesma Community. Dependências read-only `C:/Users/paulo/AppData/Local/CESEB/r2/source/build/dependencies`: Qt/6.12.0/msvc2022_64, install(GTest1.17), boost_1_86_0. Configurar Ninja Release, CXX_COMPILER=cl, CESEB_BUILD_GUI/TESTS=ON, CESEB_BOOST_ROOT e CMAKE_PREFIX_PATH acima, CESEB_SOURCE_REVISION=SHA real exportado; build parallel2. Tests não fazem install/CPack e não alteram guardCRT. PATH Qt SDK apenas no processo de testes, separado do app empacotado.

WSL auxiliar para base/final: CMake `.mikoshi/cache/toolchains/cmake-3.28.6-linux-x86_64/bin/cmake`, Ninja `.mikoshi/cache/toolchains/ninja-1.13.1/ninja`; Qt `build/dependencies/Qt/6.12.0/gcc_64`, GTest `build/dependencies/install`, Boost `build/dependencies/boost_1_86_0`, runtime `.mikoshi/cache/toolchains/wsl-dev/sdk/usr`. Configurar `build/dispatch-r4-tests-base` e `build/dispatch-r4-tests-final`, Ninja Release, GUI/TESTS ON, SOURCE_REVISION real; build parallel2. Conferir locais antes da execução; ajustes de mount/process PATH preservam ferramentas/pins e ficam registrados, sem instalação global. WSLG/GCC15 são evidência auxiliar, não Ubuntu24/GCC13.

Ubuntu24: produtor devolve build/pacote GCC13 e sua suíte na fonte final. Reutilizar contêineres existentes `ceseb-validation-r3-ubuntu24` e `ceseb-validation-r3-runtime24` apenas com ownership liberado pelo root. Método e dependências existentes em `out/validation-r3/ubuntu24/run-core.sh`; não executar novamente script histórico sobre fonte57. Para core final usar mesmos argumentos `/usr/bin/g++-13`, `/boost`, `/work/gtest-install`, fonte exportada final e novo binaryroot próprio. Para demonstração, adaptar driver externo existente `out/validation-r3/ubuntu24/ui-driver` para novoDEB e saídasr4. Nenhuma instalação de dependência nova exigida nesta autoria; falta de SDK/mount/display fica explícita e retorna ao root para meio local autorizado.

## Verification and handoff

Cards lidos/consumidos:2301CMake,2303QtTest,4189plan,2521artifact-check,2523memory; executor lê4188commit-check/2570Git antes do commit. CLI selecionada `/mnt/c/Users/paulo/.codex/plugins/cache/exalor-labs/mikoshi/3.0.0/bin/mikoshi`. `plan check PLAN --root /home/paulo/ceseb --json`; `check --root /home/paulo/ceseb --file PLAN --links --profile current --json`. Ausência de Context7/Serena na descoberta é lacuna declarada, não chamada fictícia. APIs QtTest existentes são reutilizadas; nenhuma dependência nova.

Reports separados:2401planejamento;2411 base;2412 final, com cada tarefa/método/exits/logs/hash/revisão/plataforma, leitura real, completo/parcial e próximo responsável. Native role não foi configurável no dispatch; devr15 lido manualmente, native_id desconhecido, handle não é identidade comprovada. Autor retorna agora após checks e memória; não executa teste nem commit. ExecutorSol6.1 recebe mesmo head/memória com ownership liberado. Plano só pode receber implemented após procedimento declarado e cobertura de commit; reviewer independente em Synapses decide requisitos. Standingpush1040 pertence ao root/syncer; nenhum merge/PR/release neste plano.
