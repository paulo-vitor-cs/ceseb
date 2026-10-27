---
id: 2281
revision: 2
type: document
tags: [mortgage, synapses, independent-review, windows, validation]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: "Continuação Windows concluída: 1215 e 1226 pass; 1216 fail por texto invisível nos campos preenchidos, com código e reports anteriores preservados."
use_when:
- Aplicar os resultados dos três protocolos Windows retomados e recuperar o defeito visual confirmado sem alterar os critérios.
---
# Revisão independente após o desbloqueio Windows

## Resultado

No código **57ef26901d4381ead16c7347483d588ad9d92efe**, os três protocolos antes interrompidos agora têm resultado: **1215 r1 pass, 1216 r1 fail e 1226 r2 pass**. O requisito 1216 falhou por um defeito real de visibilidade no Windows usado: os campos possuem os valores digitados, mas parecem vazios porque o texto é branco sobre fundo branco. Os cálculos e as transições funcionais foram executados; não há mais protocolo destes três interrompido por bloqueio da sessão.

O inventário técnico resultante é **22 requisitos pass e três fail: 1216, 1225 e 1228**. Os dois últimos continuam vinculados ao mesmo F3 de avisos DXC/DXIL ausentes no ZIP. O novo **F4/P2** é a apresentação invisível dos campos. Os demais resultados do mesmo snapshot são reutilizados com atribuição, sem nova operação individual ou nova alegação de execução.

Esta revisão 2 preserva integralmente [2281 r1](dev-review.md), publicada antes do desbloqueio. O relatório anterior descreve corretamente o bloqueio naquele momento; não foi reescrito. Instância fresca `/root/windows_validation_review_r3r2`, mesmo head lógico `design-project-1/independent-review`, mesma [memória](../../../session_memory/design/independent-review.yaml), entrada r8. ROOT/MAIN/workspace de implementação `/home/paulo/ceseb`; sessão `1-mortgage-desktop`; branch `codex/mortgage-desktop`. Provider codex, native_id desconhecido; leitura manual não comprova carregamento nativo de role/plugin.

## Corte, autoridade e evidência recebida

A autoridade é [1040 r1](../../../documents/1040/r1-alternative-validation-and-branch-push.md), com a resposta posterior do usuário “Desbloqueei a sessão”. O root e o executor observaram WTS UNLOCK=1 antes da retomada. Recebi e li integralmente o retorno final [2271 r2](../../dispatch/r3/windows-validation-r2.md), e o root confirmou sua recepção completa. Também reli [2272 Linux](../../dispatch/r3/linux-validation.md) para os critérios das duas plataformas e reutilizei as inspeções próprias registradas em 2281 r1. Nenhum input meu concorreu com o executor Windows.

O HEAD observado **bd56676ff02816205825b4f7209f793e4064acb2** é um commit documental posterior ao código executado. [55/55 fontes de produto/testes](dev-r2/source-identity.json) continuam iguais aos hashes da minha própria revisão 2241; os reports r1 publicados permanecem sem diff. [O ZIP e o EXE efetivamente aberto](dev-r2/package-current-identity.json) foram conferidos: ZIP SHA256 **c71634da99c2efe7774db55e011883b2c12f001db7a972404093f7c05968da4b**, EXE runtime byte a byte igual à entrada do ZIP e literal da revisão 57 presente. O resultado não foi rebaseado automaticamente para o commit documental.

A suíte própria anterior do mesmo código — Linux e Windows, 26/26 por backend e 21/21 core — é reutilizada por essa identidade. Não foi repetida sem alteração de código ou uma nova pergunta coberta por aquela suíte. O novo dado é o uso real do app em Windows 11 Pro x86_64, versão 10.0.26200, com backend windows e Qt privado do ZIP. A demonstração Linux é Ubuntu 24.04.5 em userspace de contêiner, kernel WSL compartilhado e sessão X11/Xvfb/Openbox, conforme 2272; suas condições não são ocultadas nem convertidas em uma máquina física distinta.

## Inspeção dos ensaios

Li o driver e o fluxo operacionais: a entrada usa **WinForms SendKeys**, com guards de EXE/PID, sessão desbloqueada e foreground; UIAutomation observa nomes, valores, foco e geometria. Não há escrita de resultado por API interna do aplicativo ou substituição por QtTest. Conferi os dados recebidos, o fluxo keyboard-only e as capturas originais; a execução é atribuída ao executor, e a inspeção/julgamento são próprios. [Confronto dos registros](dev-r2/received-windows-evidence.json).

| Cenário Windows | Observação conferida |
|---|---|
| Nominal 12%; R$ 1.000,00; 3 meses | Taxas 1,000000% / 12,000000% / 12,682503%; Price 340,02 / 340,03 / total 1.020,07 / juros 20,07; SAC 343,34 / 336,66 / total 1.020,00 / juros 20,00; diferença +0,07. |
| Efetiva 12%; R$ 1.000,00; 3 meses | Taxas 0,948879% / 11,386552% / 12,000000%; Price 339,68 / 339,68 / total 1.019,04 / juros 19,04; SAC 342,83 / 336,49 / total 1.018,98 / juros 18,98; diferença +0,06. |
| Alterar tipo, erro e recuperação | Resultados antigos vazios após mudar o tipo; principal zero gera erro e foco no valor; corrigir para 1000 recupera o conjunto efetivo esperado. |
| Limpar por Space | Campos vazios, tipo nominal, resultados vazios e foco no principal. O Enter anterior no botão não foi contado como limpeza. |
| Reabrir | Padrões 250.000,00 / 4,5 / 360 / nominal, sem resultado persistido. |
| 0%; R$ 1.000,00; 600 meses | Price ordinária 1,67, última 1,34, 599 pagamentos; SAC primeira 1,67, última 1,66, 600 pagamentos; total 1.000,00 e juros zero em ambos; aviso completo de quitação 599/600. |

As capturas nominais/efetivas mostram as taxas e os cartões renderizados; os estados externos da instância confirmam todos os valores exatos da tabela. O baixo contraste periférico é registrado no F4, junto da perda inequívoca de texto nas entradas. Não trato uma árvore acessível como prova de que o texto invisível foi mostrado visualmente.

## Req 1215

**Resultado: pass — demonstration.** Os quatro ACs foram atendidos pelas execuções Linux já recebidas e pela sequência Windows real. Tab percorreu principal→taxa→tipo→prazo→Calcular→Limpar→Sobre→principal; Shift+Tab fez a inversa. [Ordem observada](../../../../../../../out/validation-r3/windows/keyboard-order.json). As quatro entradas têm Name=LabeledBy correto; a borda azul de foco é observável nas capturas, inclusive no combo e após o erro.

A sequência completa Windows foi por teclado após a preparação inicial: digitação com Tab, Enter no formulário, troca do tipo por Down/Enter, erro/correção, Space em Limpar, Shift+Tab/Space em Sobre, Tab para Fechar, Escape no diálogo e Escape na janela principal. A UIAutomation.SetFocus de preparação não substituiu as transições Tab desse fluxo. [Limpeza efetiva por Space](../../../../../../../out/validation-r3/windows/clear-space.json), [Escape](../../../../../../../out/validation-r3/windows/main-escape.json) e 2271 r2. Os três processos usados encerraram por Escape, `exited=true`; não transformo esse booleano em um código de saída do aplicativo não coletado.

O texto das entradas invisível é uma falha de visibilidade julgada em 1216. Ele não apaga a observação das teclas, associações e foco que compõem o oráculo de 1215.

## Req 1216

**Resultado: fail — demonstration; F4/P2, AC1.** Em Windows 11/100%, cliente **800×600**, o cenário 1000/0/600 está calculado e os campos expõem os valores corretos na UIA; na [captura real de tela](../../../../../../../out/validation-r3/windows/native-artifacts/11-scale100-top.png), principal/taxa/tipo/prazo aparecem vazios. O mesmo ocorre na região visível da [captura a 200%](../../../../../../../out/validation-r3/windows/native-artifacts/21-scale200-exact-before-after.png). O retângulo do campo é alcançável, mas o seu conteúdo preenchido não está visualmente disponível. Isso viola a obrigação de manter o conteúdo necessário visível/alcançável nas combinações declaradas, sem criar um limiar WCAG ou um requisito de preferência estética.

As duas combinações Linux passaram, com 47/47 textos/controles alcançados e capturas de 800×600 e 1600×1200. No Windows, a reorganização vertical, o PageDown e o aviso de quitação foram observados em 100%; [aviso e SAC](../../../../../../../out/validation-r3/windows/native-artifacts/13-scale100-scroll-0.png). Esses sucessos não tornam verdadeiro o AC1 que falhou.

Em 200%, somente o processo usou QT_SCALE_FACTOR=2; o DPI Windows permaneceu 96. A confirmação exata [antes/depois do PrintWindow](../../../../../../../out/validation-r3/windows/native-artifacts/21-scale200-exact-before-after.capture.json) é cliente **1600×1200**, equivalente a 800×600 lógicos. O monitor reportado para essa inspeção é 1920×1080; não atribuo fidelidade aos pixels inferiores fora do monitor nem uma aprovação da apresentação completa baseada no backing store. O fail já está comprovado em 100% e na área de campos efetivamente visível a 200%, de modo que não depende dessa região incerta.

## Finding F4

**P2 — campos preenchidos visualmente vazios na aparência Windows escura usada.** Trigger: abrir o ZIP neste Windows, com AppsUseLightTheme=0 e SystemUsesLightTheme=0, preencher e calcular, inclusive em 800×600 nas escalas de processo 1/2. Esperado: ler os dados dos campos e o conteúdo necessário. Observado: valores presentes na UIA e cálculo correto, mas nenhum texto visível sobre o fundo branco dos quatro controles. [Tema somente leitura](../../../../../../../out/validation-r3/windows/theme-readback.json), [nominal](../../../../../../../out/validation-r3/windows/native-artifacts/03-nominal-screen.png) e [100%](../../../../../../../out/validation-r3/windows/native-artifacts/11-scale100-top.png).

Impacto: o usuário não consegue confirmar visualmente os dados digitados. Cabeçalho, prazo, diferença, rodapé e versão também têm baixo contraste no fundo escuro. O corpo da ajuda permanece legível. A base normativa é **1216 r1 AC1** e a composição clara descrita em **1013 r2**, não um novo critério quantitativo de contraste.

Localização: `src/ui/main_window.cpp:36` fixa fundo branco de QLineEdit/QComboBox sem definir sua cor de texto; `src/app/main.cpp:15` seleciona Fusion sem fixar uma paleta clara. O QWidget do conteúdo não recebe a mesma cor explícita da página. A herança da paleta escura é a causa provável sustentada pelo código e pelo tema observado; o defeito de pixels é confirmado independentemente dessa hipótese causal. Nenhuma configuração de tema ou fonte foi alterada para mascará-lo, e não houve source patch.

## Req 1226

**Resultado: pass — demonstration.** O protocolo funcional dos quatro ACs foi concluído nas duas plataformas: abertura do pacote, nominal com equivalências/resultados normativos, efetiva com invalidação e valores exatos, erro/correção, limpeza, teclado, redimensionamento e fechamento. Sistema, arquitetura, pacote, revisão, ações, valores e capturas estão identificados em 2271 r2 e 2272. Os resultados exatos foram confrontados com a instância em execução; amostras visuais das taxas e cartões foram inspecionadas diretamente, inclusive [efetiva Windows](../../../../../../../out/validation-r3/windows/native-artifacts/04-effective-screen.png).

A falha visual F4 permanece explícita e reprova a obrigação de acesso/visibilidade de 1216. Os eventos do protocolo e os resultados financeiros de 1226 efetivamente funcionaram; o seu oráculo não exige um limiar quantitativo de contraste que permitisse reprovar por baixa legibilidade periférica. O texto ausente nas entradas não foi usado para fingir que o protocolo não foi executado. O pass de 1226 não completa a spec de entrega, que ainda contém os fail 1225/1228, nem apaga o finding visual.

## Resultados preservados, agregados e leitura

1217 e 1221 continuam pass pelos resultados de [2281 r1](dev-review.md); 1225 e 1228 continuam fail pelo F3. A ajuda Windows adicional contém os tópicos exigidos, o link abriu Explorer na pasta local e a versão tem identidade acessível; isso não cria uma nova prova de host Windows offline nem apaga a prova offline Linux já recebida. A versão de baixo contraste foi registrada no F4; não inventei um novo limiar nem reprovei 1217 automaticamente.

O conjunto completo da spec 1013 r2 permanece **1211–1217 r1**: seis pass e 1216 fail. O conjunto de 1014 r3 permanece **1221/1225/1227/1228 r1 e 1226 r2**: três pass e dois fail. Ambas continuam **partial implemented**, agora com todos os membros julgados no mesmo código 57. Os resultados anteriores dos agregados são atribuições explícitas ao próprio 2241/2281 r1; não são novas execuções. Os planos e seus ranges/filemaps permanecem como antes: nenhum arquivo do produto/teste mudou nesta continuação operacional.

Leitura nova: 2271 r2 e 2272 integrais; 1215/1216/1226 r2, obrigações/ACs/limites; autoridade 1040; MainWindow/appmain; driver/fluxo Windows e dados selecionados de UIA/teclas, tema e geometria; imagens nominal, efetiva, ajuda, layout 100%/200% e aviso. Reuso: fontes/suítes próprias 2241, Linux inspecionado em 2281 r1, demais requisitos dos agregados e contratos/pins inalterados. [Manifesto](dev-r2/source-read-manifest.json). Context7/Serena não estão expostos no catálogo consultado; não houve instalação, pesquisa externa ou alegação de chamada. Não reli todo Brain nem bibliotecas de terceiros. Não executei novos testes de produto ou input Windows.

As cinco declarações abaixo são validadas somente leitura; [transporte](dev-r2/declaration-validation.json) e [schema/links](dev-r2/report-check.json). Isso valida identidade/membership/referências, sem substituir o julgamento acima. O próximo responsável é o analyst: aplicar somente os três resultados e os dois agregados, preservando corpos e história. O syncer deve manter a publicação explicitamente ordenada, com confirmação remota. Nenhum status, produto, Git, remoto, promoção ou decisão de aceite foi alterado por este reviewer. A rodada não inicia um reparo automático de F4.

Related: [2281 r1](dev-review.md); [2271 r2](../../dispatch/r3/windows-validation-r2.md).

## Declaração mecânica exata

```mikoshi-result-v1
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1215/r1-keyboard-navigation.md
    id: 1215
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1215/r1-keyboard-navigation.md
      id: 1215
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: demonstration
    evidence: '#req-1215'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1216/r1-resize-access.md
    id: 1216
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1216/r1-resize-access.md
      id: 1216
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: fail
    method: demonstration
    evidence: '#req-1216'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1226/r2-wsl-linux-and-windows-smoke.md
    id: 1226
    revision: 2
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1226/r2-wsl-linux-and-windows-smoke.md
      id: 1226
      revision: 2
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: demonstration
    evidence: '#req-1226'
- kind: spec
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/specs/1013/r2-widgets-interface.md
    id: 1013
    revision: 2
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  applicability:
    mode: engineering
    declared_by: dev
    requirements:
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1211/r1-localized-input.md
      id: 1211
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1212/r1-rate-presentation.md
      id: 1212
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1213/r1-comparison-presentation.md
      id: 1213
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1214/r1-ui-state-recovery.md
      id: 1214
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1215/r1-keyboard-navigation.md
      id: 1215
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1216/r1-resize-access.md
      id: 1216
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1217/r1-model-help.md
      id: 1217
      revision: 1
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1211/r1-localized-input.md
      id: 1211
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: ../r2/dev-review.md#req-1211
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1212/r1-rate-presentation.md
      id: 1212
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: ../r2/dev-review.md#req-1212
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1213/r1-comparison-presentation.md
      id: 1213
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: ../r2/dev-review.md#req-1213
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1214/r1-ui-state-recovery.md
      id: 1214
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: ../r2/dev-review.md#req-1214
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1215/r1-keyboard-navigation.md
      id: 1215
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: demonstration
    evidence: '#req-1215'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1216/r1-resize-access.md
      id: 1216
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: fail
    method: demonstration
    evidence: '#req-1216'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1217/r1-model-help.md
      id: 1217
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: inspection
    evidence: dev-review.md#req-1217
- kind: spec
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/specs/1014/r3-wsl-validation-delivery.md
    id: 1014
    revision: 3
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  applicability:
    mode: engineering
    declared_by: dev
    requirements:
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1221/r1-build-contract.md
      id: 1221
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1225/r1-runtime-packages.md
      id: 1225
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1226/r2-wsl-linux-and-windows-smoke.md
      id: 1226
      revision: 2
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1227/r1-technical-documentation.md
      id: 1227
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1228/r1-distribution-notices.md
      id: 1228
      revision: 1
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1221/r1-build-contract.md
      id: 1221
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: dev-review.md#req-1221
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1225/r1-runtime-packages.md
      id: 1225
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: fail
    method: inspection
    evidence: dev-review.md#req-1225
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1226/r2-wsl-linux-and-windows-smoke.md
      id: 1226
      revision: 2
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: demonstration
    evidence: '#req-1226'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1227/r1-technical-documentation.md
      id: 1227
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: inspection
    evidence: ../r2/dev-review.md#req-1227
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1228/r1-distribution-notices.md
      id: 1228
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: fail
    method: inspection
    evidence: ../r2/dev-review.md#req-1228
```
