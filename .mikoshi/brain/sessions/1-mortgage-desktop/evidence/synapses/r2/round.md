---
id: 2240
revision: 1
type: document
tags: [mortgage, synapses, dispatch, correction-review]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Resultado final da Synapses 2 no commit 57, com F1/F2 corrigidos, Community instalada, 18 pass, 1228 fail e seis requisitos sem julgamento integral.
use_when:
- Recuperar o resultado aplicado, preservação, autoridade e pendências da rodada de correção antes de escolher trabalho posterior.
---
# Synapses 2 — resultado da rodada

A rodada chegou ao resumo da fase 7, após os retornos completos de dev independente, analyst e syncer. O snapshot único revisado é **57ef26901d4381ead16c7347483d588ad9d92efe**, branch `codex/mortgage-desktop`. ROOT/MAIN e workspace de implementação: `/home/paulo/ceseb`, sessão `1-mortgage-desktop`. A sessão permanece aberta; esta rodada termina sem outro ciclo automático.

Autoridade: [1036](../../../documents/1036/r1-bounded-corrections-and-validation-authority.md) para corrigir F1/1225 e F2/1227 e aceitar WSL na parte Linux de 1226; [1039](../../../documents/1039/r1-windows-tools-installation-authority.md) para instalar as ferramentas Windows. Foram usadas novas instâncias dos mesmos heads lógicos, com suas mesmas memórias. O recorte local aprovado em [1034](../../../documents/1034/r1-engineering-execution-approval.md) não autoriza push, PR, merge, CI remoto ou release.

## Execução e revisão recebidas

Os dois scripts de regressão do commit **4eb022d0e4a8e4f0c832c475e67ee0ac216fa9ed** falharam de fato no DEB ce5, conforme [2211 base](../../dispatch/r2/tests/2211-r1-base-result.md). O produto posterior 57 modificou somente `cmake/Packaging.cmake` e quatro documentos do plano 2003. As regressões passaram no DEB corrigido: launcher XDG presente e links de licenças/evidências recuperáveis. O histórico RED e as execuções anteriores permanecem preservados.

Recebidos integralmente: [2212 testes finais e demonstração WSL](../../dispatch/r2/tests/2212-r1-final-result.md), [2221 implementação](../../dispatch/r2/implementation/2221-r1-implementation-result.md), [2231 r1 ambiente](../../dispatch/r2/windows-tools/2231r1-installation.md), [2231 r2 tentativa inicial e receita elevada](../../dispatch/r2/windows-tools/2231r2-community-installation.md), [2231 r3 instalação confirmada](../../dispatch/r2/windows-tools/2231r3-community-readback.md) e [2222 complemento Windows](../../dispatch/r2/implementation/2222-r1-qualified-windows-result.md). O transporte de resultado faltante em 2221 foi completado pelo mesmo head autor, sem nova execução ou alteração dos fatos.

Após a resposta humana “Executei o comando”, o readback confirmou **Visual Studio Community 2022 17.14.43** instalada/completa, sem reboot, e probe C++20 exit0. No mesmo código 57, configure/build/install/CPack ZIP Windows retornaram 0 com CRT guard ON e fontes Community qualificadas. Linux e Windows passaram **26/26 por backend**, e a configuração somente de núcleo passou **21/21**; estes são conjuntos separados. A revisão independente também executou sua própria suíte. O reviewer observou processo/janela Windows, PATH sem SDK e Qt privado do pacote; isso não demonstra a interação financeira manual.

Os pacotes locais existem: DEB `out/dispatch-r2/implementation/packages/ceseb_0.1.0_amd64.deb`, SHA256 `6827856d68ad39d35490a31dfdec90df9fdf63f8e45bc95dfd103b06fdceb4b4`; ZIP `C:/Users/paulo/AppData/Local/CESEB/r2/community-packages/ceseb-0.1.0-windows-x86_64.zip`, SHA256 `c71634da99c2efe7774db55e011883b2c12f001db7a972404093f7c05968da4b`. A presença não representa qualificação integral ou publicação. A falha inicial UAC, CRT guard OFF e ausência inicial de ZIP são fatos históricos dos reports anteriores, resolvidos pelo complemento quanto à instalação e geração.

## Resultados aplicados e pendências

[2241 revisão independente](dev-review.md) julgou o corte 57: **18 requisitos pass, 1228 r1 fail e seis sem julgamento integral**. Os pass são 1101–1106, 1201–1207, 1211–1214 e 1227. As 23 declarações mecânicas foram validadas somente leitura; o mesmo head corrigiu dez linhas de representação numérica na prosa, preservando integralmente os blocos de resultado.

**F3/P2, 1228 AC2:** o ZIP contém `dxcompiler.dll` e `dxil.dll` sem avisos/licenças específicos recuperáveis nos materiais entregues. É uma falha do critério de inventário/avisos, sem conclusão jurídica geral. Nenhuma fonte, opção do deploy ou composição foi alterada a partir deste finding.

| Requisito sem julgamento integral no 57 | Evidência ainda necessária |
|---|---|
| 1215 r1 | Protocolo completo de teclado nos dois desktops exigidos. |
| 1216 r1 | Matriz Windows/Ubuntu 24.04 ×100%/200%, incluindo cenário completo em 800×600. |
| 1217 r1 | Abrir pela aplicação o handler externo dos arquivos de licença; ajuda offline Linux já observada. |
| 1221 r1 | Ubuntu 24.04/GCC 13 e condição sem SDK Qt fisicamente instalado. |
| 1225 r1 | Uso integral pelo caminho publicado em ambientes limpos, preservando a lacuna de composição F3. |
| 1226 r2 | Demonstração financeira, interação e capturas Windows; parte Linux WSL aceita e observada. |

**1225 conserva seu header fail histórico do ce5**, sem novo fail julgado no 57 e sem reset artificial para published. A contagem atual é qualificada por snapshot. F1/F2 estão corrigidos; 1227 recebeu pass explícito no 57. Computer Use continua indisponível antes de JS por `sandboxCwd file:///home/paulo/ceseb`; a instalação concluída não resolve esse contexto. A demonstração Linux foi observada em cliente X11 próprio, com ajuda em namespace sem rede; não é evidência de UI Windows.

A seleção efetiva explícita é [1226 r2](../../../requirements/1226/r2-wsl-linux-and-windows-smoke.md) e [1014 r3](../../../specs/1014/r3-wsl-validation-delivery.md), sob [1037](../../../decisions/1037/r1-wsl-linux-validation-choice.md) e [1038](../../../documents/1038/r1-wsl-amendment-application.md). Só a parte Linux de 1226 aceita WSL. Os predecessores 1226 r1/1014 r2 mantêm seus corpos e estados: o retirement nativo foi recusado por exigir Related à sucessora no corpo antigo. [Diagnóstico](../../dispatch/r2/impact/amendment-status.json) preservado, sem repetir a operação nem forçar edição aprovada. Nenhum resultado foi herdado por recência.

[2251 reconciliação](analyst.md) aplicou 25 operações nativas: 19 requisitos, quatro specs e dois planos, com cinco mudanças literais e 20 reafirmações. Specs 1008 r2/1012 r2 estão implemented; 1013 r2/1014 r3, partial implemented. Planos 2003/2004 estão partial implemented; seus autores distinguem tarefa limitada concluída e procedimento integral incompleto. Os planos antigos 2001/2002 e os resultados ce5 permanecem históricos. Os três drafts 2231 receberam somente correção de frontmatter para schema document; corpos, ID e revisão preservados.

## Preservação e encerramento desta rodada

[2261 syncer final](syncer.md) confirmou **47/47 corpos aprovados, 55/55 paths de produto/testes, 31 estados exatos e 19 notas de conhecimento draft**, índice Git vazio e HEAD 57. README e dirty/untracked de outros owners foram preservados. Os corpos aprovados e reports atuais estão locais no filesystem, sem alegação de que pertencem ao commit 57.

O [repositório pessoal público](https://github.com/paulo-vitor-cs/ceseb) contém no remoto somente main bootstrap `0bbd2854703444a27ce04600f5e227e0351f61bc`; **11 commits posteriores permanecem locais**. Nenhum push, PR, merge, CI remoto, release ou promoção foi realizado. DVC não está configurado neste projeto e é N/A no recorte; não houve upload.

O refresh final usa os mesmos 12 diretórios de corpus desta sessão, após todos os reports e esta integração: [build final](final-graph-build.json), [lint final](final-graph-lint.json). As fronteiras de links operacionais e as sobreposições históricas de planos são diagnósticos preservados; grafo não é novo julgamento de requisitos. [Validação da sessão](final-session-validation.json) e [check deste relatório](final-round-check.json) registram os resultados mecânicos. Telemetria opcional sem série disponível; nenhuma etapa adicional foi criada.

Todos os participantes retornaram e liberaram ownership. F3 e as seis lacunas são devolvidos para escolha do próximo trabalho, sem reparo automático, aceite de produto, promoção de conhecimento ou encerramento da sessão.
