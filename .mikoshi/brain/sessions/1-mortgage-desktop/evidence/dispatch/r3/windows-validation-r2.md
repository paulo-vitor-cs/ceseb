---
id: 2271
revision: 2
type: document
tags: [mortgage, validation, windows, desktop, keyboard, scaling]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Uso real do ZIP Windows após desbloqueio, com teclado completo, cenários financeiros, ajuda/licenças, escalas 100/200 e defeito visual reproduzido no tema escuro.
use_when:
- Julgar os critérios Windows dos seis requisitos com as execuções e capturas reais, preservando a tentativa anterior bloqueada.
---
# Uso real do aplicativo Windows — continuação

**Executei o aplicativo real e todos os cenários atribuídos.** Conversões, Price/SAC, invalidação, erro/correção, limpeza, sequência de teclado, ajuda, abertura do diretório de licenças e fechamento funcionaram. **Há um defeito visual reproduzido:** os campos possuem valores no runtime, mas seu texto não aparece sobre o fundo branco no tema escuro atual. O prazo, a diferença de juros, o rodapé e a versão na ajuda também têm baixo contraste sobre o fundo escuro. Não alterei tema, código, pacote ou critério para esconder esse resultado.

Este documento é a sucessora de [2271 r1](windows-validation.md), cujo corpo publicado permanece intacto. A tentativa anterior parou corretamente no Windows bloqueado. O usuário depois informou “Desbloqueei a sessão”; o root confirmou WTS UNLOCK=1 e liberou a continuação da tarefa interrompida. Autoridade: [1040 r1](../../../documents/1040/r1-alternative-validation-and-branch-push.md). A revisão de fonte executada continua **57ef26901d4381ead16c7347483d588ad9d92efe**; o HEAD documental posterior não é uma nova versão do aplicativo.

## Alvo e método observado

Windows 11 Pro x86_64, versão 10.0.26200, mesmo host real; ZIP Community `c71634da99c2efe7774db55e011883b2c12f001db7a972404093f7c05968da4b`, extraído em `C:/Users/paulo/AppData/Local/CESEB/r2/community-extracted`. A execução recebeu PATH somente Windows/System32, sem SDK ou compilador. O EXE contém a revisão 57; Qt6Core/Gui/Widgets e qwindows carregados são os arquivos privados desse pacote, conforme a evidência do retorno anterior e [módulos observados](../../../../../../../out/validation-r3/windows/gui-live-modules.json).

Usei UIAutomation para observar nomes, rótulos, valores, foco e geometria; SendKeys para entrada real de teclado na janela Windows; mouse wheel/click nativos somente no ponto derivado do controle observado e com WindowFromPoint pertencente ao PID próprio. Não usei QtTest, offscreen, API interna do app ou Computer Use para simular um resultado de interface. Cada entrada verifica EXE, PID, WTS UNLOCK=1 e foreground do aplicativo. Janela principal e diálogo pertencem ao mesmo PID; o acesso à pasta de licenças é observado separadamente como resultado da ação explícita no aplicativo.

Os PIDs usados foram **24464**, depois **7304** e **28484**. Todos foram fechados pela tecla Escape no aplicativo, sem crash; o estado retornou `exited=true`. O segundo início restaurou os valores padrão 250.000,00 / 4,5 / 360 / nominal e resultados vazios, conforme [reabertura](../../../../../../../out/validation-r3/windows/reopened.json).

## 1215 — sequência inteira por teclado

Após a condição inicial de foco no principal, a operação completa foi por teclado. UIAutomation.SetFocus foi usado para preparar o início e para casos de escala posteriores; não foi usado para substituir as transições Tab do fluxo abaixo.

- **Tab:** principal → taxa → tipo → prazo → Calcular → Limpar → Sobre → principal.
- **Shift+Tab:** principal → Sobre → Limpar → Calcular → prazo → tipo → taxa → principal.
- A partir do principal: digitar 1000, Tab, digitar 12, Tab, Home para nominal, Tab, digitar 3 e Enter. O cálculo aconteceu.
- Shift+Tab até tipo, Down para efetiva: os resultados antigos foram apagados; Enter recalculou os resultados efetivos.
- Shift+Tab duas vezes até principal, digitar 0 e Enter: mensagem de erro e foco no principal. Digitar1000 e Enter recuperou o cálculo.
- Tab até Limpar, **Space**: campos e resultados vazios, tipo nominal e foco no principal. Shift+Tab até Sobre, Space abriu a ajuda; Tab chegou a Fechar; Escape fechou o diálogo e outro Escape fechou o aplicativo.

[Ordem e inversa registradas](../../../../../../../out/validation-r3/windows/keyboard-order.json); [fluxo e valores](../../../../../../../out/validation-r3/windows/flow-results.json); [limpeza por Space](../../../../../../../out/validation-r3/windows/clear-space.json); [fechamento por Escape](../../../../../../../out/validation-r3/windows/main-escape.json). Enter no botão Limpar foi uma tentativa operacional que não o ativa; esse não é o atalho exigido para botões pelo requisito. Seu resultado original permanece no log, e o sucesso de limpeza pertence ao Space posterior. Não troquei o significado do Enter exigido no formulário.

Os quatro campos expõem **Name=LabeledBy** corretos: “Valor financiado (R$)”, “Taxa anual (%)”, “Tipo de taxa” e “Prazo (meses)”. Os focos têm borda azul observável, inclusive após erro. Veja [associações acessíveis](../../../../../../../out/validation-r3/windows/observed-accessibility.json) e as capturas. A visibilidade do texto digitado é o defeito separado abaixo, não foi inferida dos nomes acessíveis.

## 1226 — valores e transições realmente calculados

| Resultado | Nominal 12% | Efetiva 12% |
|---|---|---|
| Taxa mensal | 1,000000% | 0,948879% |
| Nominal anual equivalente | 12,000000% | 11,386552% |
| Efetiva anual equivalente | 12,682503% | 12,000000% |
| Price ordinária / última | R$ 340,02 / R$ 340,03 | R$ 339,68 / R$ 339,68 |
| Price total / juros | R$ 1.020,07 / R$ 20,07 | R$ 1.019,04 / R$ 19,04 |
| SAC primeira / última | R$ 343,34 / R$ 336,66 | R$ 342,83 / R$ 336,49 |
| SAC total / juros | R$ 1.020,00 / R$ 20,00 | R$ 1.018,98 / R$ 18,98 |
| Diferença Price − SAC | R$ +0,07 | R$ +0,06 |

Entradas: principal 1000 e 3 meses em ambos os casos. Todos esses valores foram lidos da instância em execução após Enter e confrontados por asserts no driver operacional. A troca para efetiva limpou todos os resultados antes de recalcular, conforme [invalidação observada](../../../../../../../out/validation-r3/windows/effective-invalidated.json). O principal 0 produziu a mensagem “Informe um valor válido entre R$ 0,01 e R$ 100.000.000,00, com até duas casas decimais.”; corrigir para 1000 recuperou os valores sem reiniciar.

Capturas do aplicativo: [nominal real](../../../../../../../out/validation-r3/windows/native-artifacts/03-nominal-screen.png), [efetiva](../../../../../../../out/validation-r3/windows/native-artifacts/04-effective-screen.png), [erro](../../../../../../../out/validation-r3/windows/native-artifacts/05-error-screen.png), [recuperação](../../../../../../../out/validation-r3/windows/native-artifacts/06-recovered-screen.png) e [limpeza](../../../../../../../out/validation-r3/windows/native-artifacts/08-clear-space.png). UIAutomation confirma o estado interno acessível, mas não transforma texto invisível em texto visualmente mostrado. Assim, os cálculos e ações funcionaram; o reviewer deve considerar também a falha visual ao julgar o requisito completo.

## 1216 — 800×600 e escalas 100%/200%

O cenário 1000 /0% /600 meses produziu em ambas as escalas: Price ordinária R$ 1,67, última R$ 1,34, **599 pagamentos**, total R$ 1.000,00, juros R$ 0,00 e aviso **“Quitado em 599 de 600 meses por ajuste de centavos.”**; SAC primeira R$ 1,67, última R$ 1,66, 600 pagamentos, mesmo total e juros; diferença R$ 0,00. Os textos originais têm espaços corretos, preservados nos JSON/capturas.

Em 100%, a janela cliente foi medida em **800×600 pixels físicos e lógicos**, DPI 96. Formulário em duas colunas e cartões reorganizados verticalmente. Tab até Calcular e PageDown produziram rolagem real por teclado; o aviso Price completo e todos os valores SAC ficaram acessíveis. A roda do mouse chegou ao rodapé; só existe barra vertical, sem rolagem horizontal do formulário ou sobreposição impeditiva observada. Evidências: [topo100%](../../../../../../../out/validation-r3/windows/native-artifacts/11-scale100-top.png), [PageDown100%](../../../../../../../out/validation-r3/windows/native-artifacts/12-scale100-page-down.png), [aviso/SAC/rodapé100%](../../../../../../../out/validation-r3/windows/native-artifacts/13-scale100-scroll-0.png) e [estado calculado100%](../../../../../../../out/validation-r3/windows/scale100-top.json).

Em 200%, configurei **somente o processo** com QT_SCALE_FACTOR=2; o DPI nativo Windows continuou 96 e as alturas de campos/fontes dobraram (campo de 40 para 80 pixels físicos). Não alterei escala ou tema global. O monitor físico é 1920×1080. MoveWindow comum inicialmente limitou a altura a 1061; outro estado durante a execução tinha 1000 pixels de cliente. Esses estados reais foram preservados e **não são apresentados como 800×600 lógicos**.

Para a inspeção exata, SetWindowPos próprio com SWP_NOSENDCHANGING permitiu cliente **1600×1200**, equivalente a 800×600 lógicos nessa escala. Isso atua apenas na geometria da própria janela; referência da operação: [Microsoft SetWindowPos](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowpos). As capturas 18/19/20 registram a geometria no momento da captura. A confirmação final bounded registra **GetClientRect antes e depois do PrintWindow: 1600×1200**, PrintWindow=true, conforme [metadados200%](../../../../../../../out/validation-r3/windows/native-artifacts/21-scale200-exact-before-after.capture.json) e [captura200%](../../../../../../../out/validation-r3/windows/native-artifacts/21-scale200-exact-before-after.png).

A região fora dos 1080 pixels do monitor pode conter backing store não atualizado no PrintWindow; não extrapolo a fidelidade visual dos pixels inferiores. A parte visível confirma os campos vazios visualmente apesar dos valores acessíveis e os textos de baixo contraste, o mesmo defeito já inequívoco na captura real de tela em 100%. PageDown e wheel foram executados em 200%, e um ciclo completo Tab alcançou os sete controles, registrado em [ciclo200%](../../../../../../../out/validation-r3/windows/scale200-keyboard-cycle.json). A captura exata não muda a observação de que a visibilidade exigida falhou: o texto dos campos não aparece sobre o fundo branco.

## 1217 — ajuda e licenças acessadas no aplicativo

A ajuda foi aberta por Space no botão Sobre e modelo. Seus parágrafos renderizados explicam nominal/efetiva, Price/SAC, primeiro pagamento após um mês, postecipação, arredondamento half-up, ajuste de centavos e prazo efetivo. PageDown mostrou limites/exclusões e a indicação de que o total não é CET. [Ajuda superior](../../../../../../../out/validation-r3/windows/native-artifacts/09-help-screen.png); [ajuda inferior após PageDown](../../../../../../../out/validation-r3/windows/native-artifacts/14-help-page-down.png). Ctrl+End anterior não rolou esse QTextBrowser; essa tentativa permaneceu no log. A rolagem bem-sucedida pertence ao PageDown posterior.

A versão acessível observada foi **CESEB 0.1.0 · revisão 57ef26901d4381ead16c7347483d588ad9d92efe**. Visualmente, esse rótulo tem baixo contraste no tema atual; os parágrafos em branco sobre cinza são legíveis. O link “Licenças e avisos locais” foi clicado no retângulo observado e abriu Explorer na pasta real **C:/Users/paulo/AppData/Local/CESEB/r2/community-extracted/licenses**, HWND 4262296, URL file:/// correspondente, conforme [resultado real do link](../../../../../../../out/validation-r3/windows/license-explorer.json). Isso é um efeito observado do botão/link do app, não apenas inspeção da existência da pasta.

Não desativei a rede global do Windows nem afirmei que o host estava offline. A execução offline Linux em namespace pertence ao retorno Linux, que deve ser combinado com esta inspeção. O acesso Windows foi inteiramente local; não houve navegação remota solicitada pelo fluxo. O Explorer aberto permaneceu como janela da pasta de licenças; não fechei janelas de terceiros por nome de processo.

## 1221 e 1225 — consumo e abertura do pacote

A evidência de núcleo Windows do retorno anterior permanece válida na mesma fonte: consumidor executado sozinho em uma pasta própria, 20 casos em 13 suites passaram exit 0, PE e 15 amostras de módulos sem Qt. Não repeti a suíte após o desbloqueio; a continuação foi de interface, sem mudança de fonte. O SDK instalado em outro diretório não participou desse processo, conforme [execução direta do núcleo](../../../../../../../out/validation-r3/windows/core-runtime-check-qualified.json) e [módulos do consumidor em execução](../../../../../../../out/validation-r3/windows/core-live-modules.json).

O ZIP abre pelo EXE documentado sem configurar desenvolvimento e carrega Qt privado. Todos os cenários acima ocorreram no executável extraído, não em um build tree. As lacunas de avisos das DLLs DXC/DXIL, já encontradas na revisão anterior, não foram corrigidas ou escondidas por esta execução: funcionamento do runtime não garante o critério de inventário/avisos de 1225/1228. O defeito de contraste também é novo dado de uso real do pacote.

## Defeito visual, tentativas preservadas e retorno

A leitura somente do registro do usuário confirmou **AppsUseLightTheme=0 e SystemUsesLightTheme=0**, em [tema observado](../../../../../../../out/validation-r3/windows/theme-readback.json). Não houve alteração desses valores. No runtime, principal/taxa/tipo/prazo têm texto correto via UIA; em ambas as capturas PrintWindow e cópia real dos pixels da própria janela foreground, seus valores parecem em branco. O prazo, diferença e rodapé escuros sobre página escura e a versão da ajuda têm baixo contraste. O código atual fixa fundos brancos dos inputs e cores escuras de QLabel, sem resolver a paleta herdada do tema escuro. Esse é um achado concreto de visibilidade, não uma falha de Computer Use, rede ou compilação.

Todos os JSON por ação, parâmetros, exit/stderr, observações e tempos estão em `out/validation-r3/windows/step-*.json`, com scripts e fotos em `native-artifacts/`. Foram preservados o guard inicial sob LockApp, a codificação inicial de console corrigida, Enter ignorado no botão Limpar, Ctrl+End sem rolagem e a recusa SetForegroundWindow após abrir Explorer. Nesta última, nenhuma tecla foi enviada fora do app; uma ativação limitada com UIAutomation.SetFocus na própria janela restaurou o alvo e o guard confirmou o PID antes de continuar.

[Resumo mecânico desta execução](../../../../../../../out/validation-r3/windows/validation-summary.json). Fiz inspeção visual das capturas nominais, ajuda superior/inferior, janela100%, PageDown/aviso/rodapé100% e captura200%. Não fiz source patch, alteração de requisito, commit, push ou escrita em memória/estado de outro owner. O report r1 publicado permanece intacto. Este retorno é execução autoral: o reviewer independente julga os critérios exatos, e o analyst aplica apenas seu resultado. Não atribuí pass ao conjunto apenas porque os asserts numéricos passaram.

Related: [2271 r1](windows-validation.md); [1215 r1](../../../requirements/1215/r1-keyboard-navigation.md); [1216 r1](../../../requirements/1216/r1-resize-access.md); [1217 r1](../../../requirements/1217/r1-model-help.md); [1221 r1](../../../requirements/1221/r1-build-contract.md); [1225 r1](../../../requirements/1225/r1-runtime-packages.md); [1226 r2](../../../requirements/1226/r2-wsl-linux-and-windows-smoke.md).
