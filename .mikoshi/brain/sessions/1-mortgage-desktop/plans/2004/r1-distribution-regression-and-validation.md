---
id: 2004
revision: 1
type: plan
tags: [mortgage, dispatch, test-plan, distribution, bounded-correction]
status: partial implemented
created: '2026-10-27'
updated: 2026-10-27
description: Regressões limitadas de desktop e links do pacote com procedimentos explícitos para as seis validações ainda pendentes.
use_when:
- Executar o recorte de testes autorizado em 1036 antes e depois das correções de distribuição.
---
# Regressões de distribuição e validação pendente

## Context

Autor e executor: dev-test-planning, nova instância `/root/test_correction`, mesmo head lógico `design-project-1/test-planning` e memória `session_memory/design/test-planning.yaml`. ROOT e autoria: `/home/paulo/ceseb`, ramo `codex/mortgage-desktop`; sessão MAIN explícita `.mikoshi/brain/sessions/1-mortgage-desktop`. Produto pertence a instância distinta. Autoridade: [pedido 1036 r1](../../documents/1036/r1-bounded-corrections-and-validation-authority.md), limitado aos achados F1/F2 de [2101 r1](../../evidence/synapses/r1/dev-review.md) e às validações pendentes de [2102 r1](../../evidence/synapses/r1/analyst.md). Origem: [1001 r1](../../documents/1001/r1-human-request.md). Este corpo precisa da conferência do orquestrador sobre procedimento e efeitos antes da execução; drafting não é execução.

Base de produto disponível: `ce5db2e9d7489e0b6258b449358d620a0c390b1e`; DEB real `out/review-wsl/packages/ceseb_0.1.0_amd64.deb`, SHA256 esperado `6692adb56379f62e1412ec4b5fe9df5b0d23385c914119f301fbbc08698d2079`. Capturar TEST_CORRECTION_BASE real antes dos assets. Produto só começa depois do retorno base com TEST_CORRECTION_HEAD commitado. A verificação final usa PRODUCT_CORRECTION_HEAD explicitamente informado pelo autor, preservando ambos os snapshots e falhas originais.

## Goals and Boundary

Criar duas regressões de conteúdo do entregável, executar sobre o DEB base e sobre o DEB corrigido, então repetir a suíte automática existente no snapshot final. Preparar e consumir somente evidência real dos seis procedimentos pendentes. O plano não reinicia TDD de toda a feature, não altera os 22 assets existentes, não altera produto, README raiz, requisitos, specs, estado ou memória raiz. Não instala dependências, modifica segurança/rede, baixa fontes, provisiona máquina, envia mensagens externas, nem executa efeito remoto. Não cria testes de agentes ou workflows. Não transforma testes WSL em Windows.

## File Structure

| Operation | Path | Owner |
|---|---|---|
| create | tests/system/check_deb_desktop.cmake | dev-test-planning |
| create | tests/system/check_distribution_links.cmake | dev-test-planning |

Sem rename/delete/modify. Scripts executáveis via `cmake -P`, com SPDX MIT e copyright original aplicável. Não integrar ao CTest porque exigem um pacote já produzido, evitando dependência circular de build/package. Cada script recebe somente uma árvore extraída real; não consulta o código de empacotamento para construir seu oráculo. Logs/relatórios/extração em `out/test-evidence/dispatch-r2/` são saídas operacionais. Relatórios 2211/2212 ficam em `evidence/dispatch/r2/tests/`, separados do mapa de fontes.

## Reference-only Inputs

- [Spec vigente 1014 r3](../../specs/1014/r3-wsl-validation-delivery.md) e [predecessora 1014 r2](../../specs/1014/r2-reproducible-delivery.md), [spec 1013 r2](../../specs/1013/r2-widgets-interface.md), [plano 2001 r1](../2001/r1-requirement-test-plan.md) e [2012 r1](../../evidence/test-execution/2001/r1-final-result.md).
- `tests/` existentes, CMake e bibliotecas do produto; `docs/`, `LICENSE`, `THIRD_PARTY_NOTICES.md`, `packaging/ceseb.desktop`, `cmake/Packaging.cmake`; fontes, manifests, pacotes e logs recebidos.
- Cartões de projeto [2301 r1](../../tools/2301/r1-cmake-ctest-build.md), [2305 r1](../../tools/2305/r1-native-compilers.md) e [2306 r2](../../tools/2306/r2-qt-dependency-acquisition-and-deployment.md). Reusar CMake 3.28.6/Ninja 1.13.1 locais e dependências já preparadas; não obter novos materiais.

## Tasks

### Task D1225

Requirement: [1225 r1](../../requirements/1225/r1-runtime-packages.md)
Kind: test
Method: Inspeção determinística do pacote extraído e procedimento completo de pacote por plataforma quando disponível.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/system/check_deb_desktop.cmake | - |

Preparação: verificar SHA256 do DEB real; extrair em diretório novo owned com `dpkg-deb --extract`. Passar a raiz de extração em CESEB_PACKAGE_ROOT. Estímulo: procurar `ceseb.desktop` em `usr/share/applications` ou `usr/local/share/applications`, diretórios da busca XDG padrão; conferir seção Desktop Entry, Type=Application e Exec absoluto cujo executável existe dentro da mesma extração. Oráculo: um lançador utilizável na busca publicada, sem ajustar XDG_DATA_DIRS. Falta do arquivo ou destino é falha observada de conteúdo, não ausência de ambiente; falta de entrada/extração válida é indisponibilidade. Um DEB contendo somente `/opt/ceseb/share/applications` deve falhar. A inspeção não comprova lançamento do menu real.

Comando: `cmake -DCESEB_PACKAGE_ROOT=/home/paulo/ceseb/out/test-evidence/dispatch-r2/base/extracted -P tests/system/check_deb_desktop.cmake`, repetido com `final/extracted` no DEB corrigido. Complemento AC 1/3/4: inventariar ZIP Windows e DEB (bibliotecas/plugins/runtimes/avisos/metadados), instalar/extrair pelo uso publicado em ambientes limpos, abrir sem PATH de desenvolvimento, registrar versão/revisão/plataforma. Falta de ZIP/toolchain/ambiente limpo mantém esse complemento incompleto e não impede a regressão F1.

### Task D1227

Requirement: [1227 r1](../../requirements/1227/r1-technical-documentation.md)
Kind: test
Method: Inspeção determinística de links locais e leitura das alegações técnicas entregues.

#### Files

| Operation | Path | Destination |
|---|---|---|
| create | tests/system/check_distribution_links.cmake | - |

Preparação: mesma extração validada; CESEB_APP_ROOT aponta para seu `opt/ceseb` (ou raiz do ZIP). Ler docs/README.md e docs/technical-report.md e os demais Markdown sob docs. Estímulo: resolver cada link Markdown local relativamente ao documento, desconsiderando âncora e URL remota; conferir existência dentro da árvore recebida. Exigir índice com pelo menos os três documentos e os dois links de licença recuperáveis, e ao menos um link local de evidência no relatório técnico cujo destino não seja o próprio relatório. Falhas são acumuladas para não esconder o segundo defeito. Nenhum serviço remoto é consultado. Não fazer parser Markdown geral: o formato suportado é o link inline simples já utilizado pelos documentos entregues, sem espaço no destino.

Oráculo: links do índice e referências de evidência recuperam arquivos efetivamente entregues; nenhuma alegação verificada depende somente de caminho não entregue em outra sessão. A leitura humana confronta cada alegação de sucesso/falha/não executado, SHA, plataforma, comando e registro efetivo pelos AC 1..4; um arquivo existente não comprova a veracidade de seu conteúdo. Implementações incorretas discriminadas: links de licença que só funcionam no checkout; relatório com resultados positivos e somente paths locais externos ao pacote; links que apontam a arquivos ausentes. O script não impõe uma estratégia de cópia ou layout de produto.

Comando: `cmake -DCESEB_APP_ROOT=/home/paulo/ceseb/out/test-evidence/dispatch-r2/base/extracted/opt/ceseb -P tests/system/check_distribution_links.cmake`, repetido em `final/extracted/opt/ceseb`. Ler integralmente os quatro documentos e as evidências ligadas na versão final; verificar tópicos de instalação/uso/build/teste Windows/Linux, fórmulas/centavos/limites/exclusões/exemplo/dependências. Conservar resultados negativos originais e a diferença entre revisão do pacote e revisão das fontes documentais. Não marcar 1227 pass pela regressão automática isolada.

### Task V1215

Requirement: [1215 r1](../../requirements/1215/r1-keyboard-navigation.md)
Kind: test
Method: Demonstração; Sem alteração de fonte.

#### Files

| Operation | Path | Destination |
|---|---|---|

Em Windows 11 x64 e Ubuntu 24.04 x64 desktop reais, pacote identificado, preencher 1.000,00/12% nominal/3 meses só por teclado; registrar Tab principal→taxa→tipo→prazo→Calcular→Limpar→Sobre e Shift+Tab inverso, Enter calcular, nomes/rótulos/foco visíveis; provocar erro e corrigir; Limpar; ajuda; Escape fechar. Conferir valores normativos pela fonte aprovada. Capturar sequência/observáveis por plataforma. QtTest/offscreen/WSLg não substituem os dois alvos deste requisito. Nenhum arquivo autoral alterado.

### Task V1216

Requirement: [1216 r1](../../requirements/1216/r1-resize-access.md)
Kind: test
Method: Demonstração; Sem alteração de fonte.

#### Files

| Operation | Path | Destination |
|---|---|---|

Windows 11 e Ubuntu 24.04, cada um a 100% e 200%, janela 800×600 pixels lógicos. Calcular 1.000,00/0%/600; percorrer campos, botões, cartões, avisos, valores completos e quitação por teclado/rolagem. AC: acesso a todo conteúdo, sem rolagem horizontal no formulário e sem sobreposição impeditiva. Capturas e escala/tamanho observados nas quatro combinações. Não alterar configuração global de escala por inferência; se indisponível, registrar a combinação ausente. Nenhum arquivo autoral alterado.

### Task V1217

Requirement: [1217 r1](../../requirements/1217/r1-model-help.md)
Kind: test
Method: Inspeção de aplicação distribuída; Sem alteração de fonte.

#### Files

| Operation | Path | Destination |
|---|---|---|

Pacote instalado/extracto identificado, ambiente já sem rede disponível sem modificar segurança/rede global. Abrir Sobre e modelo, ler nominal/efetiva, Price/SAC, primeiro vencimento após um mês, postecipados, centavos/ajuste final/contagem, exclusões seguros/tarifas/impostos/indexadores, total não CET, versão e licenças locais. Abrir os destinos locais. Fonte embutida ou ausência de URL apoia inspeção, mas não prova abertura offline. Se não houver condição offline observável, manter AC correspondente desconhecido. Nenhum arquivo autoral alterado.

### Task V1221

Requirement: [1221 r1](../../requirements/1221/r1-build-contract.md)
Kind: test
Method: Teste e inspeção; Sem alteração de fonte.

#### Files

| Operation | Path | Destination |
|---|---|---|

Executar o script existente `tests/system/check_core_independence.cmake` e os casos financeiros da mesma fonte sem GUI, em Windows 11/MSVC 2022 e Ubuntu 24.04/GCC 13. Conferir interfaces e dependências sem Qt, condição sem componentes gráficos instalados/inicializados e SHA igual. O WSL atual com Qt discovery desabilitado é observação auxiliar; SDK existente não prova ausência física. Não instalar compiladores/SDKs. A suíte final WSL continua útil sem concluir os AC dos dois ambientes. Nenhum arquivo autoral alterado.

### Task V1226

Requirement: [1226 r2](../../requirements/1226/r2-wsl-linux-and-windows-smoke.md)
Kind: test
Method: Demonstração; Sem alteração de fonte.

#### Files

| Operation | Path | Destination |
|---|---|---|

Alvos normativos lidos: 1226 r2 e 1014 r3, publicados por escolha humana1036/1037. Retém-se 1226 r1 histórica; nenhum resultado é herdado. Aplicar 1036 somente à aceitação de WSL como Linux em 1226; não relaxar 1215/1216/1221/1225/1228. Windows11 continua obrigatório. Registrar distro/toolchain/display reais, pacote/SHA/revisão, sequência e captura. A execução do pacote deve usar somente runtimes distribuídos e de sistema, sem prefixo de SDK Qt mascarando dependência.

No pacote identificado em cada sistema: 1.000,00/12% nominal/3; mensal 1,000000%, nominal anual 12,000000%, efetiva anual 12,682503%; Price primeira 340,02, última 340,03, total 1.020,07, juros 20,07; SAC primeira 343,34, última 336,66, total 1.020,00, juros 20,00, diferença 0,07. Trocar para efetiva invalida resultado; recalcular: mensal 0,948879%, Price ordinária/última 339,68, total 1.019,04, juros 19,04; SAC primeira 342,83, última 336,49, total 1.018,98, juros 18,98; diferença 0,06. Provocar erro, corrigir/recalcular/limpar/teclado/redimensionar/fechar. Esses valores foram confrontados com 1226r2, 1212r1 e 1213r1; prevalecem os corpos normativos exatos. Intenção do root de usar Computer Use não é resultado; falha do helper antes do JS é indisponibilidade. Nenhum arquivo autoral alterado.

### Task V1228

Requirement: [1228 r1](../../requirements/1228/r1-distribution-notices.md)
Kind: test
Method: Inspeção; Sem alteração de fonte.

#### Files

| Operation | Path | Destination |
|---|---|---|

Comparar conteúdo real/inventário, MIT e copyright dos originais separados de terceiros, textos e avisos de cada componente, GPLv3/LGPLv3, fonte correspondente Qt exata e modificações, possibilidade real de substituição das bibliotecas; confrontar demais termos/runtimes efetivos, inclusive CRT Windows permitido. Recuperar fontes e hashes já entregues; não baixar/reconstruir Qt nem substituir ABI sem input compatível disponível. Ausência desses procedimentos mantém a tarefa incompleta. Nenhum arquivo autoral alterado.

## Verification and Evidence

Primeiro: root confere este corpo concreto, autoridade/efeitos e alvos normativos explícitos e libera execução. Autor cria os dois scripts e executa ambos contra DEB base extraído novo, preservando stdout/stderr/exit e ambiente/hash/HEAD. Somente falha de conteúdo real é RED; erro de extração/ferramenta é indisponibilidade. Commitar somente os dois paths e executar check nativo no range real TEST_CORRECTION_BASE..TEST_CORRECTION_HEAD. Retornar 2211 antes de qualquer edição do produto. Depois aguardar produto commitado, extrair seu DEB identificado em nova área e repetir os mesmos scripts/oráculos. Guardar base sem sobrescrever.

Suíte automática aplicável: configurar `build/dispatch-r2-tests` com GUI/testes ON, Release, GCC15.2 WSL, Qt6.12.0, Boost1.86.0 e GTest1.17.0 já preparados; CESEB_SOURCE_REVISION=PRODUCT_CORRECTION_HEAD. Prefixos próprios já existentes: `.mikoshi/cache/toolchains/cmake-3.28.6-linux-x86_64/bin`, `.mikoshi/cache/toolchains/ninja-1.13.1`, `build/dependencies/Qt/6.12.0/gcc_64`, `build/dependencies/install`, `.mikoshi/cache/toolchains/wsl-dev/sdk/usr`. Build paralelo2. Executar inventários e CTest `--output-on-failure --no-tests=error --output-junit` em offscreen e XCB/WSLg separadamente, com runtimes privados já preparados. Esperado inventário existente: 20 casos domínio, quatro slots GUI e dois inventários, 26 entradas CTest por backend, zero seleção vazia. Conferir hashes fontes/testes antes/depois, diff dos 22 assets contra ce5 vazio. Não adicionar cobertura/diagnósticos sem necessidade; este recorte não reabre o diagnóstico gcov do plano antigo.

A autorização humana1039 para instalação Windows pertence ao syncer; este autor não instala. Quando chegar handoff Windows qualificado, executar o mesmo snapshot, suíte/filtros e script core-only pelos comandos B-WINDOWS/Q-CORE de2001, em export imutável C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/source, com build/out fora de source, prefixos/toolchain reais retornados e CESEB_SOURCE_REVISION=PRODUCT_CORRECTION_HEAD. Rodar os dois scripts CMake sobre staging/extração quando aplicáveis (D1225 é específicoDEB), conservar revisão/inventário e logs; não duplicar assets nem trocar oráculos. Indisponibilidade mantém lacuna. A instalação e o próprio handoff não são execução deste plano.

Root executa a tentativa de Computer Use e devolve evidência real; o autor dos testes consome essa evidência, com tarefa/AC/ambiente e resultado/ausência explícitos. Não alegar execução Windows por WSLg, helper presente ou intenção. O relato final 2212 lista cada uma das oito tarefas, snapshots, comandos, exits, logs, hashes e lacunas. Se qualquer demonstração/inspeção integral permanecer indisponível, procedure partial e tarefa incomplete; o plano não recebe implemented por dois scripts verdes. Sem verdict independente aqui: a próxima revisão formal pertence a Synapses.

Ferramentas mecânicas: 4189r2 plan, 4188r2 commit-check, 4196r3 trace, 2570r8 Git e 2523r17 memory, lidas do plugin local Mikoshi3.0.0. CLI `/mnt/c/Users/paulo/.codex/plugins/cache/exalor-labs/mikoshi/3.0.0/bin/mikoshi`; registrar disponibilidade/retorno reais. Context7/Serena não foram expostos na descoberta nativa desta instância; não foram instalados nem alegados chamados. Um check estrutural não quita procedimento nativo.

## Risks and Recovery

Preservar corpos/estados/resultados históricos, README raiz e dirty/untracked de outros owners. Capturar índice antes de commit; se houver staged alheio, reconciliar em vez de incluí-lo. Extração grava só diretório novo owned. Falta de pacote/hashes/revisão segura bloqueia somente a execução dependente. Não criar fixture sintética de pacote para alegar RED. Não alterar oráculo após ver produto. Todas as escolhas de meio acima são limitadas aos efeitos locais já autorizados em 1036; nenhuma mudança material de requisito está delegada ao autor. Fontes da emenda: [1037](../../decisions/1037/r1-wsl-linux-validation-choice.md); instalação Windows separada: [1039](../../documents/1039/r1-windows-tools-installation-authority.md).
