---
id: 2271
revision: 1
type: document
tags: [mortgage, validation, windows, desktop]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Pacote Windows iniciado e núcleo executado sem Qt; input aguardando desbloqueio humano porque foreground é LockApp.
use_when:
- Recuperar as execuções Windows e continuar os cenários após desbloqueio humano do desktop.
---
# Validação Windows por método alternativo

Fonte executada: **57ef26901d4381ead16c7347483d588ad9d92efe**. Pacote real extraído em `C:/Users/paulo/AppData/Local/CESEB/r2/community-extracted`. Autoridade humana atual: usar o aplicativo e testar os seis requisitos por outros meios, registrada em [1040](../../../documents/1040/r1-alternative-validation-and-branch-push.md). Não foi chamado Computer Use neste turno.

## Operações realmente executadas

| Operação | Resultado observado |
|---|---|
| Abrir o EXE extraído do ZIP com PATH apenas Windows/System32 | Janela e processo próprios presentes, PID 24464. |
| Observar UIAutomation do aplicativo | 58 elementos, janela cliente 1040×760, DPI 96 e display 1920×1080. |
| Conferir nomes acessíveis e associação de rótulos | Os quatro campos têm Name e LabeledBy corretos, habilitados e focalizáveis; principal tem foco. |
| Inspecionar módulos do app em execução | Qt6Core/Gui/Widgets e qwindows carregados somente da árvore privada do ZIP. |
| Identificar fonte no EXE | A revisão 57 está literalmente presente nos bytes do executável. |
| Executar o consumidor de núcleo isolado | 20 casos em 13 suites passaram, exit 0, em pasta com apenas o EXE e PATH Windows/System32. |
| Inspecionar dependências PE do consumidor | dumpbin exit 0; somente KERNEL32, MSVCP/VCRUNTIME e UCRT, nenhum Qt. |
| Amostrar módulos reais durante execução do núcleo | 15 amostras, nenhum Qt; somente EXE próprio e DLLs Windows/CRT em System32. |
| Primeiro pedido de ativação da janela | Recusado pelo guard: foreground pertence a LockApp.exe, desktop bloqueado. Nenhum input enviado. |

As provas locais ficam em `out/validation-r3/windows/`: `observed-accessibility.json`, `gui-live-modules.json`, `core-runtime-check-qualified.json`, `core-live-modules.json`, `init.json` e `step-000-activate.json`. O scratch Windows correspondente está em `C:/Users/paulo/AppData/Local/CESEB/validation-r3`. As capturas e os cenários financeiros ainda não foram executados: dependem do desbloqueio humano solicitado pelo root.

Os controles observados têm os pares acessíveis Name=LabeledBy: “Valor financiado (R$)”, “Taxa anual (%)”, “Tipo de taxa” e “Prazo (meses)”. A primeira coleta stdout tinha codificação de console incompatível; o driver foi corrigido para UTF-8, e a nova coleta mostra os textos corretos. Isso não era defeito do produto.

## Núcleo Windows realmente consumido

O consumidor `community-core-build/bin/ceseb_domain_tests.exe`, construído da mesma revisão, foi copiado sozinho para o scratch `core-runtime`. Executou conversão e amortização com sucesso, sem Qt nessa pasta e sem SDK/Qt no PATH. A inspeção PE e os módulos efetivamente carregados não contêm Qt. O SDK existente em outro diretório do host não foi removido nem configurado para esse consumo. Esta execução comprova o isolamento do processo e seu uso real, sem transformar a presença física de um SDK alheio em dependência do componente.

Uma operação posterior executou três repetições completas dos 20 casos para permitir amostragem de módulos. O log registra três conjuntos pass; o wrapper Start-Process não recuperou ExitCode (null). Por isso o exit 0 acima pertence à execução direta anterior, não foi inferido do wrapper. As amostras posteriores são usadas somente como evidência dos módulos carregados. O primeiro wrapper de CLI também foi preservado: PATHEXT ausente impediu obter retorno nativo; ajustá-lo somente no processo permitiu a operação útil observada.

## Condição concreta da sessão desktop

A primeira tentativa de ativação observou foreground PID **25640**, diferente do PID próprio. O guard recusou input. A leitura somente de metadata identificou esse processo como **LockApp.exe**, em `C:/Windows/SystemApps/Microsoft.LockApp_cw5n1h2txyewy/LockApp.exe`: **desktop Windows bloqueado**. Nenhuma tecla, clique, mudança de segurança ou tentativa de desbloqueio foi executada.

A consulta somente leitura WTSQuerySessionInformationW confirmou que app, PowerShell e LockApp pertencem à mesma SessionId 1; WTSINFOEX Level 1 retornou SessionState WTSActive (0) e SessionFlags LOCK (0). Os valores e alinhamento da estrutura foram conferidos no WtsApi32.h do Windows SDK instalado; não é apenas um LockApp residual em outra sessão. Evidências `wts-session-status.json` e `wts-session-status-2.json`.

O app 24464 permanece aberto aguardando o desbloqueio humano solicitado pelo root. Não tentei contornar a tela de bloqueio, recuperar foco mediante entrada global ou automatizar credenciais. A condição atual é separada da falha de URI do Computer Use.

## Continuação e ownership

Os scripts operacionais `driver.ps1`, `run.py`, `core-check.ps1` e `core-modules.ps1` estão no output próprio e no scratch correspondente. A seleção UIAutomation usa AutomationId previamente observado; toda entrada exige EXE/PID e foreground do aplicativo. Capturas previstas são somente da janela própria. Após o usuário desbloquear, observar novamente o foreground e continuar `run.py`, preenchendo nominal/efetiva, erro/correção, limpeza, teclado, ajuda, licenças e escalas 100%/200%.

Não atribuí novo estado de requisito: execução e parecer formal são fatos separados. Nenhum source patch, commit, push, requisito ou arquivo de outro owner foi alterado por este head. Leitura própria: requisitos 1215/1216/1217/1221/1225 r1 e 1226 r2, mikoshi-code-implement r9, computer-use guidance, fontes runtime anteriores, consumidor real MainWindow, controles runtime e logs originais desta execução. A evidência Windows é atribuída ao Windows 11 deste host, sem extrapolar para Linux.
