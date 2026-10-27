---
id: 2021
revision: 1
type: document
tags: [mortgage, implementation, execution, partial, wsl]
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Retorno do executor de 2002 com 31 fontes commitadas, testes e DEB auxiliares no WSL, cobertura mecânica e qualificações nativas pendentes.
use_when:
- Recuperar o intervalo real do produto, identidade dos builds e pacotes, comandos, resultados e lacunas antes da revisão independente.
---
# Execução do plano 2002 r1

Autor/executor: dev-implementation-planning, handle `/root/implementation_planning`.
ROOT: `/home/paulo/ceseb`. Autoridade: [1034](../../documents/1034/r1-engineering-execution-approval.md), complementada pela [direção humana para usar WSL, 1035](../../documents/1035/r1-wsl-execution-direction.md). Alvo: [2002 r1 publicado](../../plans/2002/r1-product-implementation-plan.md), [API 1030 r1](../../documents/1030/r1-test-interface-and-fixtures.md) e 25 requisitos r1 publicados. A execução começou apenas após o retorno do autor de testes [2011](../test-execution/2001/r1-base-result.md) e liberação explícita do orquestrador.

Foram criados e commitados exatamente os **31 paths** do plano. O procedimento permanece **parcial**: WSL não qualifica Windows 11/MSVC 2022 ou Ubuntu 24.04/GCC 13; faltam seus protocolos nativos, pacote Windows/CRT e fechamento independente. Este retorno não atribui pass/fail a requisito nem implemented a plano/spec.

## Identidades e preservação

| Identidade | Valor observado |
|---|---|
| TEST_BASE | `0bbd2854703444a27ce04600f5e227e0351f61bc` |
| TEST_ASSETS_HEAD = BASE_IMPL | `4e7e1842efe188c889dd9d5235f131f1502779b2` |
| Ramo local reutilizado | `codex/mortgage-desktop` |
| IMPLEMENTATION_HEAD congelado | `76b9fe2ff8b6a034c9880daa315a7875f3d9bcdf` |
| build_source_commit do binário/stage/DEB inspecionados | `2b16879dfe1eb6ec55ea8d9310b2ae575cb1c7cf` |
| Delta depois do build | Somente `docs/technical-report.md`, atualização editorial dos resultados já observados |
| Produto no baseline dos testes | Ausente: configure UNAVAILABLE, sem RED comportamental |
| CI remoto, push, PR, release | Não executados |

Antes da autoria, [execution-readiness.json](execution-readiness.json) registrou dirty/untracked alheio, hashes das fontes aprovadas, inexistência dos 31 paths e dos 22 assets de teste entregues. O corpo do plano confere com a aprovação exata (`badbe3cdfa856ca436a0fd3fc5c43c4fb58715064a51fd776b61900ba64edb9d`). O orquestrador confirmou 43/43 corpos aprovados preservados em [execution-input-body-preservation.json](../execution-input-body-preservation.json). Não editei README raiz, testes, requisitos, specs, planos, decisões, cards ou estado/memória raiz.

O [final-source-integrity.json](final-source-integrity.json) prova 31 arquivos de produto limpos e os 22 assets **commitados no IMPLEMENTATION_HEAD** iguais aos hashes originais. No momento dessa observação, cinco arquivos GUI no working tree já tinham alterações do autor de testes para a precondição de ativação, após a disposição do orquestrador; não os editei nem os inclui no commit. Essa autoria posterior é contabilizada separadamente por 2001. O intervalo de 2002 termina antes dela e não usa working tree como se fosse snapshot.

Commits de autoria, todos com pathspec explícito e índice vazio antes do próprio staging:

| Commit | Escopo |
|---|---|
| `1d87900e2d0ced86177e97b832ef1e92311f589c` | Núcleo exato, API/CMake e aquisição, 10 paths novos |
| `5968c317df338126be3b7236ece84d636022575c` | Nove paths GUI/recursos e correção de destino da extração Qt |
| `6eb4c28b2f7be47bcacf81fcd88c2551656ce9a8` | Doze paths de packaging, licenças, workflow e documentação |
| `c86d33d785e67ed01f0ddf95bda4a0bc24f39ffc` | Descrição SAC, SPDX nos JSON e dependências runtime do workflow |
| `249fa80262a7c4dd850ffcdf02931ba479f5979a` | Seleção mínima do runtime Qt/XCB no Linux |
| `2b16879dfe1eb6ec55ea8d9310b2ae575cb1c7cf` | Fechamento QtXcbQpa e dependências DEB explícitas |
| `76b9fe2ff8b6a034c9880daa315a7875f3d9bcdf` | Somente relatório técnico, conforme disposição editorial final do root |

Não houve worktree, checkout paralelo de autoria, commit artificial de design ou alteração de remote. O freeze final permite ao autor de testes continuar a revisão de seus assets sem contaminar o intervalo de produto.

## Ambiente e aquisição

Ambiente real: **WSL Ubuntu 26.04/GNU 15.2.0**, x86_64, com WSLg. O kit Qt foi compilado pelo fornecedor em RHEL/GCC 11.5; isso não é o compilador do aplicativo. Alvos aprovados permanecem Ubuntu 24.04/GCC 13 e Windows 11/MSVC 2022; nenhum está qualificado por este retorno.

CMake 3.28.6 e Ninja 1.13.1 foram preparados pelo syncer, com arquivos oficiais e hashes verificados. Usei PATH somente por invocação, com os prefixos `.mikoshi/cache/toolchains/cmake-3.28.6-linux-x86_64/bin` e `.mikoshi/cache/toolchains/ninja-1.13.1`. Não houve perfil global, sudo ou apt install pelo executor. Uma tentativa inicial de `env PATH=...:$PATH` sem aspas encontrou o PATH Windows com espaços e não executou aquisição; a chamada foi corrigida usando um dicionário de ambiente Python.

A aquisição aprovada **OFF antes de ON** executou o script real de produto:

```text
cmake -DCESEB_DEPS_ROOT=/home/paulo/ceseb/build/dependencies -DCESEB_DEPS_PLATFORM=linux -DCESEB_ACQUIRE_QT=OFF -P cmake/AcquireDependencies.cmake
```

Boost 1.86.0 teve o SHA256 oficial do lock conferido antes da extração. GoogleTest foi obtido do Git público no commit `52eb8108c5bdec04579160ae17225d66034bd723`, conferido, compilado e instalado no prefixo próprio. [acquire-off.log](acquire-off.log) e [acquire-off.log.json](acquire-off.log.json) registram exit 0. O primeiro build core-only ocorreu antes de obter/configurar o SDK Qt.

Depois, ON obteve QtBase 6.12.0-0-202609280346 e ICU com os dois hashes aprovados. O primeiro script extraiu os arquivos flat em `Qt/` e falhou ao verificar o prefixo esperado. Corrigi o produto para QtBase no kit selecionado e ICU em `kit/lib`, sem mudar pins. A extração anterior própria foi preservada. [acquire-on.log](acquire-on.log) conserva a falha; [acquire-on-corrected.log](acquire-on-corrected.log) e seu [JSON](acquire-on-corrected.log.json) conservam exit 0 e `qtpaths` conferindo o prefixo real. Manifesto operacional: `build/dependencies/acquisition-manifest.json`.

O configure GUI inicialmente falhou por WrapOpenGL. [aux-gui-configure-1.log](aux-gui-configure-1.log) conserva o diagnóstico. O syncer preparou headers/dev libraries oficiais em cache privado, sem scripts de mantenedor ou instalação global. O configure seguinte recebeu caminhos reais explícitos, em [aux-gui-configure-2.json](aux-gui-configure-2.json): prefixo `.mikoshi/cache/toolchains/wsl-dev/sdk/usr`, `OPENGL_opengl_LIBRARY`, `OPENGL_glx_LIBRARY` e `OPENGL_INCLUDE_DIR`. Configure e build passaram; `WrapVulkanHeaders` ausente foi opcional, sem caminho falso. O primeiro CTest XCB ainda encontrou seis runtimes ausentes; o syncer os preparou no mesmo cache. Fontes/validação atribuídas: [dev SDK](../environment/local-build-tools/wsl-dev-validation.json), [XCB](../environment/local-build-tools/wsl-xcb-validation.json), [ferramentas](../environment/local-build-tools/installation-observation.json).

Qt, Boost e GoogleTest são meios do plano por cards 2301..2306; não foram criados requisitos de ferramenta. A rota não introduziu aqtinstall, conta paga, segredo, aceitação de instalador ou dependência gráfica no núcleo.

## Núcleo e casos financeiros

O núcleo usa racionais/inteiros arbitrários. Empates e quantização usam comparação inteira, incluindo potência 12; Decimal de 50 dígitos é apenas projeção. A API preserva a taxa original. Price usa limite racional exato da anuidade para raiz irracional; SAC distribui o resto pelas primeiras amortizações. Compare normaliza uma vez e entrega o mesmo descritor a ambos, com erro atômico. O SAC isolado permanece verificável quando só Price é inadmissível. Não há epsilon financeiro, arredondamento pelo texto da tela, rede, persistência, QML ou threads de trabalho.

No snapshot `1d87900`, configure GUI=OFF/TESTS=ON com Qt discovery desabilitado, build e CTest passaram **21/21** (20 casos de domínio e um inventário). Logs/comandos exatos: [aux-core-results.json](aux-core-results.json), [configure](aux-core-1.log), [build](aux-core-2.log), [CTest](aux-core-3.log). JUnit: `out/implementation/aux-core.xml`. O autor de testes confirmou depois o isolamento por seu próprio script, distinguindo que o SDK já estava presente naquele segundo momento.

Os casos incluem conversões nominal/efetiva, rejeições/precedência, raízes racionais e irracionais, zero, um mês, vizinhanças de empate, quitação antecipada, SAC com resto, invariantes do livro e grade determinística. As fixtures esperadas são as entregues antes do produto, sem alteração de assert/tolerância pelo executor.

No snapshot runtime 2b16879, a seleção `Req1103.*:Req1202.*:Req1205.*` passou sete casos; 14 ms no conjunto Price irracional/limite de efetiva 12%, pico de RSS de 5.664 KiB para o processo selecionado. [core-resource.json](core-resource.json), [saída](core-resource-cases.log) e [recursos](core-resource.log) limitam essa medida; não é desempenho aprovado nem métrica Windows/GCC 13.

O observador operacional [core-diagnostic-3.json](core-diagnostic-3.json) contém fonte, compilação e chamada contra o core real; [saída](core-diagnostic-3.log) e [recursos](core-diagnostic-3-resource.log) registram p=0,000000000001%, projeções mensais positivas (~8,333e-16), C máximo/n=600 e ambas as convenções. A taxa pequena admite 600 linhas nos dois livros; 100% nesse prazo retorna UnsupportedCentPrecision porque a parcela Price arredondada coincide com o primeiro juro. A observação não produz oráculo. Duas tentativas diagnósticas anteriores foram preservadas: uma falha de compilação por nome de campo digitado incorretamente (`core-diagnostic.json`), outra tratava genericamente a recusa tipada como `calculation_error` (`core-diagnostic-2.json`); não são falhas do produto e não houve correção financeira para elas.

## GUI e foco

GUI configure/build passaram no snapshot `6eb4c28` com Qt 6.12.0 e o SDK OpenGL privado. [aux-gui-build-1.json](aux-gui-build-1.json) e [log](aux-gui-build-1.log) registram o build real. O app usa Widgets/Fusion com pt-BR/BRL, entradas/ações contratadas, invalidação imediata, mensagens com foco, cartões responsivos, ajuda embutida e licenças locais.

Resultados sobre os assets originais:

| Backend | Resultado | Evidência |
|---|---|---|
| XCB antes dos runtimes | 21 domínio verdes, cinco processos GUI abortados antes dos casos por libs ausentes | [log](aux-gui-ctest-1.log), [JSON](aux-gui-ctest-1.json) |
| Offscreen | **26/26 passaram**, incluindo quatro slots GUI e dois inventários | [log](aux-gui-ctest-offscreen.log), [JSON](aux-gui-ctest-offscreen.json) |
| XCB/WSLg após runtimes | **25/26**, falha `principal->hasFocus()` em req1214, linha 17 | [log](aux-gui-ctest-xcb.log), [JSON](aux-gui-ctest-xcb.json) |

A falha XCB é um assert observado e não foi apagada como erro de ambiente. O autor de testes investigou o mesmo binário sem modificar produto/oráculo e observou o slot isolado passar, junto da ativação assíncrona do window manager; o helper original `show/activateWindow/processEvents` não espera janela ativa. A revisão mínima dessa precondição, disposta pelo root, é autoria posterior dos testes e deve retornar seu próprio snapshot/range. Não forcei ativação/foco no aplicativo nem editei os testes. Este relatório conserva I-1214 incompleto até a resolução e retorno independente correspondente.

O orquestrador abriu o staging runtime 2b16879 e capturou somente a janela inicial real de 1040×760, sem clique ou cálculo manual. Arquivos: `out/implementation/visual-wsl-default.png` e `visual-wsl-observation.json`. Observação visual inicial sem defeito não comprova teclado/escala nem outro desktop. Computer Use/Sky falhou antes de executar JavaScript por `sandboxCwd ... file:///home/paulo/ceseb`; [diagnóstico](../environment/computer-use-observation.json). A captura efetiva foi X11/XGetImage no WSL, não uma ação do provedor indisponível.

## Pacote, fonte correspondente e inventário

O SDK traz SBOM real: QtBase fonte `025bdad181de241e81bf853c8a2d7bf3d19261a9`. O script [ThirdPartyNotices.cmake](../../../../../../cmake/ThirdPartyNotices.cmake) compara essa correspondência, obtém o Git oficial exato e prepara arquivo completo de fonte, LICENSES, atribuições/textos de terceiros, SBOM e configuração original do fornecedor. Sem modificação de Qt. Boost/GTest mantêm textos originais; ICU 73.2 conserva o texto oficial com SHA256 `f3005e195ff74d8812cc1f182a1c446fab678d70a10e3dada497585befee5416`. [prepare-notices.json](prepare-notices.json), [log](prepare-notices.log), [obtenção Qt](qt-corresponding-source.json) e [log](qt-corresponding-source.log) conservam a execução. Saídas em `build/dependencies/notices`, com SHA256SUMS e fonte completa; incorporadas no pacote.

O primeiro deploy mostrou que INCLUDE_PLUGINS do Qt é aditivo: trazia módulos/plugins desnecessários e bibliotecas do cache dev. A inspeção seguinte encontrou perda de QtXcbQpa pelo filtro excessivamente canônico, pois CMake conserva `plugins/platforms/../../lib`. Corrigi somente Packaging.cmake dentro do escopo: seleção QPA mínima, cópia apenas do prefixo Qt/ICU, gate das cinco libs Qt necessárias e seis dependências XCB nominais no DEB. Os estágios/artefatos anteriores foram preservados como diagnóstico, não entrega completa.

No snapshot 2b16879, configure/build/install/CPack passaram: [aux-package-closed-results.json](aux-package-closed-results.json) e logs `aux-package-closed-{1,2,3,4}.log`. Staging próprio: `out/stage/aux-linux-closed`. Pacote **auxiliar**, sem instalação global/limpa:

| Campo | Observação |
|---|---|
| Arquivo | `out/packages/aux-wsl-closed/ceseb_0.1.0_amd64.deb` |
| SHA256 | `d04f97d5cdc89f886bad6be46159d4d821eaf1e2374775eb1092ba0d643b31a6` |
| Tamanho | 97.183.012 bytes |
| Fonte incorporada no binário | `2b16879dfe1eb6ec55ea8d9310b2ae575cb1c7cf` |
| Metadata | Architecture amd64, versão 0.1.0, dependências XCB explícitas + SHLIBDEPS |
| Manifesto staging | 154/154 hashes conferem |
| Runtime Qt | Core, DBus, Gui, Widgets, XcbQpa; ICU 73.2; só plugin platforms/qxcb |
| Materiais não copiados | glibc, SDK dev/headers, QtNetwork, QtTest, GTest runtime |

[aux-package-audit.json](aux-package-audit.json) conserva `readelf`, `ldd`, metadata, arquivos e hashes. `ldd` do app e qxcb resolveu todas as dependências usando apenas o cache dos runtimes de sistema em LD_LIBRARY_PATH, **sem** Qt SDK no LD_LIBRARY_PATH; Qt veio de `stage/lib`. RPATH do app é `$ORIGIN/../lib`, do plugin `$ORIGIN/../../lib`, com qt.conf local. As dependências de sistema não viraram runtime privado acidental.

O projeto inclui MIT dos originais e inventário real dos materiais. A opção LGPLv3/Qt é dinâmica e tem instruções de substituição/reconstrução; não foi selecionada licença comercial. Confronto do CVE-2026-105924: app não chama QCborValue/fromCbor/toJsonValue ou APIs JSON/CBOR nem lê documentos externos. Isso limita o caminho conhecido, sem certificação global de segurança ou patch não autorizado.

O pacote Windows não foi produzido: faltam MSVC 2022 qualificado, sua edição/termos/lista REDIST e o host de teste. WindowsDeploy exige qualificação explícita e DLLs Release permitidas; vc_redist.exe não é tratado como DLL portátil. A instalação e teste limpos no Ubuntu 24 também não ocorreram. O DEB WSL não fecha I-1225/I-1226/I-1228.

## Workflow e documentação

O workflow criado tem somente workflow_dispatch, actions fixadas nos SHAs aprovados, jobs Ubuntu 24.04 e Windows Server 2022, núcleo antes de Qt, testes e artefatos de evidência. Não foi enviado/disparado. Server/headless não prova Windows 11 desktop. Sintaxe YAML/JSON foi lida localmente; a semântica real do provedor aguarda execução autorizada.

Os quatro arquivos docs cobrem instalação/uso, taxas/Price/SAC, half-up, exclusões, aquisição/pins, builds/testes, licenças e o mapa dos 25 requisitos a tarefas/arquivos/evidência. O último commit muda somente docs/technical-report.md para registrar os resultados reais acima e a distinção entre build_source_commit e reviewed_result_commit. O pacote 2b16879 conserva sua documentação do momento do build; a atualização editorial final é entregue no checkout 76b9fe2 e neste retorno, sem fingir que o pacote foi reconstruído. A conferência final de 1227 pelo autor de testes continua pendente.

## Cobertura mecânica e export

Comando real: `mikoshi plan check-commits --root /home/paulo/ceseb --plan .mikoshi/brain/sessions/1-mortgage-desktop/plans/2002/r1-product-implementation-plan.md --base 4e7e1842efe188c889dd9d5235f131f1502779b2 --head 76b9fe2ff8b6a034c9880daa315a7875f3d9bcdf --json`.

Retorno **0/ok**, 31 operações cobertas, unexpected_paths=[] e dirty_planned_paths=[]: [resultado](implementation-commit-check-final.json). Dirty_scope_paths contém os documentos/estado alheios preservados e o trabalho posterior do autor de testes; não é uma fonte oculta do snapshot. O check não julga correção financeira, qualificação de SO ou requisito.

Export real `git archive` do IMPLEMENTATION_HEAD para `out/native-source.zip`: SHA256 `e6df5840d49321677756dff374aeaafa00ac1053ccb82ea9fa93be5eed3e8783`, 94.870 bytes. [native-source-export.json](native-source-export.json) contém comando e manifesto; não exporta dirty/untracked. Nenhum transporte ou execução nos targets nativos foi feito, por ausência dos ambientes/toolchains. Fonte aprovada read-only permanece no ROOT com hashes; não criei commits artificiais para ela.

## Arquivos efetivamente criados

As 31 operações create abaixo pertencem ao intervalo BASE_IMPL..IMPLEMENTATION_HEAD. Não houve delete/rename nem alteração de arquivo preexistente nesse intervalo. Os hashes de cada arquivo estão no manifesto final.

| Operação | Path relativo ao ROOT |
|---|---|
| create | `.github/workflows/ci.yml` |
| create | `CMakeLists.txt` |
| create | `CMakePresets.json` |
| create | `LICENSE` |
| create | `THIRD_PARTY_NOTICES.md` |
| create | `cmake/AcquireDependencies.cmake` |
| create | `cmake/Dependencies.cmake` |
| create | `cmake/Packaging.cmake` |
| create | `cmake/ThirdPartyNotices.cmake` |
| create | `cmake/Version.hpp.in` |
| create | `cmake/WindowsDeploy.cmake` |
| create | `cmake/dependencies.lock.json` |
| create | `docs/README.md` |
| create | `docs/build-and-test.md` |
| create | `docs/technical-report.md` |
| create | `docs/user-guide.md` |
| create | `include/ceseb/finance.hpp` |
| create | `packaging/ceseb.desktop` |
| create | `packaging/qt.conf` |
| create | `resources/application.qrc` |
| create | `resources/model-help.html` |
| create | `src/app/main.cpp` |
| create | `src/core/exact_math.cpp` |
| create | `src/core/exact_math.hpp` |
| create | `src/core/finance.cpp` |
| create | `src/ui/main_window.cpp` |
| create | `src/ui/main_window.hpp` |
| create | `src/ui/money_codec.cpp` |
| create | `src/ui/money_codec.hpp` |
| create | `src/ui/simulation_controller.cpp` |
| create | `src/ui/simulation_controller.hpp` |

## Tarefas e lacunas

Complete abaixo significa que o método/caso indicado foi executado no escopo auxiliar declarado, não pass de requisito ou suporte nativo final. Tarefas que exigem ambas as toolchains, protocolos nativos, pacote Windows/CRT ou revisão independente permanecem incompletas. A falha de foco e os gaps são preservados, sem transformar ausência em sucesso.

<!-- Generated exact task matrix and result declaration follow. -->

### I-1221

Resultado de tarefa: **incomplete**. 31 paths de infraestrutura/API materializados, core-first e GUI locais verdes; duas toolchains alvo e cenário sem Qt de ambas as plataformas indisponíveis.

### I-1101

Resultado de tarefa: **complete**. Casos Req1101.* executados com oráculos originais e resultado verde no núcleo auxiliar; ver logs 21/21 e fonte do IMPLEMENTATION_HEAD.

### I-1105

Resultado de tarefa: **complete**. Casos Req1105.* executados com oráculos originais e resultado verde no núcleo auxiliar; ver logs 21/21 e fonte do IMPLEMENTATION_HEAD.

### I-1102

Resultado de tarefa: **complete**. Casos Req1102.* executados com oráculos originais e resultado verde no núcleo auxiliar; ver logs 21/21 e fonte do IMPLEMENTATION_HEAD.

### I-1103

Resultado de tarefa: **incomplete**. Casos independentes e percentual tipado pequeno executados; medidas WSL registradas. A medição por ambas as toolchains pedida pelo plano permanece indisponível.

### I-1104

Resultado de tarefa: **complete**. Casos Req1104.* executados com oráculos originais e resultado verde no núcleo auxiliar; ver logs 21/21 e fonte do IMPLEMENTATION_HEAD.

### I-1106

Resultado de tarefa: **complete**. Casos Req1106.* executados com oráculos originais e resultado verde no núcleo auxiliar; ver logs 21/21 e fonte do IMPLEMENTATION_HEAD.

### I-1201

Resultado de tarefa: **complete**. Casos Req1201.* executados com oráculos originais e resultado verde no núcleo auxiliar; ver logs 21/21 e fonte do IMPLEMENTATION_HEAD.

### I-1202

Resultado de tarefa: **incomplete**. Vetores e limite Price efetiva 12% passaram; cenário 100% e prazo 600 corretamente recusado em observador. Faltam medidas da segunda toolchain qualificada.

### I-1203

Resultado de tarefa: **complete**. Casos Req1203.* executados com oráculos originais e resultado verde no núcleo auxiliar; ver logs 21/21 e fonte do IMPLEMENTATION_HEAD.

### I-1204

Resultado de tarefa: **complete**. Casos Req1204.* executados com oráculos originais e resultado verde no núcleo auxiliar; ver logs 21/21 e fonte do IMPLEMENTATION_HEAD.

### I-1205

Resultado de tarefa: **complete**. Casos Req1205.* executados com oráculos originais e resultado verde no núcleo auxiliar; ver logs 21/21 e fonte do IMPLEMENTATION_HEAD.

### I-1206

Resultado de tarefa: **complete**. Casos Req1206.* executados com oráculos originais e resultado verde no núcleo auxiliar; ver logs 21/21 e fonte do IMPLEMENTATION_HEAD.

### I-1207

Resultado de tarefa: **complete**. Casos Req1207.* executados com oráculos originais e resultado verde no núcleo auxiliar; ver logs 21/21 e fonte do IMPLEMENTATION_HEAD.

### I-1211

Resultado de tarefa: **complete**. Slot GUI correspondente passou offscreen e XCB nos assets originais; ver resultados auxiliares e alvos nativos pendentes.

### I-1214

Resultado de tarefa: **incomplete**. Offscreen passou; assert de foco XCB original falhou. Diagnóstico e correção posterior do helper pertencem a 2001, sem herança de resultado para a execução original.

### I-1212

Resultado de tarefa: **complete**. Slot GUI correspondente passou offscreen e XCB nos assets originais; ver resultados auxiliares e alvos nativos pendentes.

### I-1213

Resultado de tarefa: **complete**. Slot GUI correspondente passou offscreen e XCB nos assets originais; ver resultados auxiliares e alvos nativos pendentes.

### I-1215

Resultado de tarefa: **incomplete**. Ordem de Tab, Enter/Escape e buddies implementados; protocolo de teclado nos dois desktops não executado.

### I-1216

Resultado de tarefa: **incomplete**. Layout responsivo/rolagem implementados; captura inicial 1040×760 não demonstra quatro combinações de SO/escala.

### I-1217

Resultado de tarefa: **incomplete**. Ajuda HTML compilada e links locais implementados; abertura/conferência completa offline nos pacotes dos dois alvos permanece pendente.

### I-1228

Resultado de tarefa: **incomplete**. MIT, fontes Qt exatas, textos e inventário Linux preparados e incluídos; faltam CRT/termos/inventário e fechamento Windows.

### I-1225

Resultado de tarefa: **incomplete**. DEB auxiliar gerado e auditado; nenhum ZIP Windows ou ensaio de instalação limpa nos alvos.

### I-1226

Resultado de tarefa: **incomplete**. Nenhuma demonstração nativa Windows 11/Ubuntu 24; visual inicial WSL não substitui o protocolo.

### I-1227

Resultado de tarefa: **incomplete**. Quatro documentos e mapa dos 25 entregues, último commit somente editorial; revisão de documentação/pacotes pelo autor de testes e completude dos alvos pendentes.

## Continuação responsável

O orquestrador informou `TEST_FINAL_HEAD=ce5db2e9d7489e0b6258b449358d620a0c390b1e`, posterior ao freeze de produto, com cinco assets GUI ajustados apenas na precondição de ativação e assertions financeiras preservadas. O autor de testes executou suas suítes finais 26/26 em offscreen e XCB. Esse retorno é **execução independente de 2001 com outro snapshot de testes**, não execução própria de 2002 no 76b9fe2; sua evidência e intervalo devem ser consumidos separadamente em Synapses. Não reexecutei ou alterei o produto após o freeze para incorporar esse resultado.

Próximos responsáveis: autor de testes entrega seu retorno completo com identidade dos assets/runtime; orquestrador encaminha 2001/2002 e evidências para revisão/Synapses. O reviewer determina resultados de requisitos nas revisões/snapshots exatos; o analyst aplica somente os resultados admissíveis. Nenhuma publicação, promoção, CI ou release é inferida. Ausência de Windows/Ubuntu alvo, CRT e demonstrações nativas permanece explícita.

## Declaração de resultado

```mikoshi-result-v1
- kind: plan
  artifact:
    path: ../../plans/2002/r1-product-implementation-plan.md
    id: 2002
    revision: 1
  range:
    base: 4e7e1842efe188c889dd9d5235f131f1502779b2
    head: 76b9fe2ff8b6a034c9880daa315a7875f3d9bcdf
  procedure: partial
  tasks:
  - id: I-1221
    result: incomplete
    evidence: '#i-1221'
  - id: I-1101
    result: complete
    evidence: '#i-1101'
  - id: I-1105
    result: complete
    evidence: '#i-1105'
  - id: I-1102
    result: complete
    evidence: '#i-1102'
  - id: I-1103
    result: incomplete
    evidence: '#i-1103'
  - id: I-1104
    result: complete
    evidence: '#i-1104'
  - id: I-1106
    result: complete
    evidence: '#i-1106'
  - id: I-1201
    result: complete
    evidence: '#i-1201'
  - id: I-1202
    result: incomplete
    evidence: '#i-1202'
  - id: I-1203
    result: complete
    evidence: '#i-1203'
  - id: I-1204
    result: complete
    evidence: '#i-1204'
  - id: I-1205
    result: complete
    evidence: '#i-1205'
  - id: I-1206
    result: complete
    evidence: '#i-1206'
  - id: I-1207
    result: complete
    evidence: '#i-1207'
  - id: I-1211
    result: complete
    evidence: '#i-1211'
  - id: I-1214
    result: incomplete
    evidence: '#i-1214'
  - id: I-1212
    result: complete
    evidence: '#i-1212'
  - id: I-1213
    result: complete
    evidence: '#i-1213'
  - id: I-1215
    result: incomplete
    evidence: '#i-1215'
  - id: I-1216
    result: incomplete
    evidence: '#i-1216'
  - id: I-1217
    result: incomplete
    evidence: '#i-1217'
  - id: I-1228
    result: incomplete
    evidence: '#i-1228'
  - id: I-1225
    result: incomplete
    evidence: '#i-1225'
  - id: I-1226
    result: incomplete
    evidence: '#i-1226'
  - id: I-1227
    result: incomplete
    evidence: '#i-1227'
```
