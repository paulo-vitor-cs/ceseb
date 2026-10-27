---
id: 2280
revision: 2
type: document
tags:
- mortgage
- synapses
- validation
- windows
- publication
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: 'Seis requisitos exercitados no app real e julgados: quatro pass e dois fail; inventário
  completo de 22 pass e três fail, com defeito visual Windows e avisos DXC ausentes.'
use_when:
- Recuperar os resultados finais dos seis requisitos e suas evidências reais após o desbloqueio Windows.
---
# Seis requisitos testados pelo uso real

**Os seis requisitos solicitados foram exercitados: quatro pass e dois fail.** Os três protocolos antes interrompidos foram concluídos após o desbloqueio Windows. No código testado, os **25 requisitos efetivos têm resultado: 22 pass e três fail**, sem protocolo destes seis aguardando execução.

| Requisito | Resultado final | Evidência principal |
|---|---|---|
| 1215 — teclado | **pass** | Fluxo inteiro por teclado nos dois sistemas, com ordem e inversa, foco, Enter, Space, ajuda, erro/correção, limpeza e Escape. |
| 1216 — visibilidade e escalas | **fail, F4/P2** | No Windows escuro, os campos preenchidos exibem texto branco sobre fundo branco. Falha inequívoca em 100% e na região visível de 200%. |
| 1217 — ajuda e licenças | **pass** | Ajuda local completa; clique do app abriu PCManFM offline no Linux e Explorer na pasta local Windows. |
| 1221 — núcleo independente | **pass** | Ubuntu 24/GCC 13 sem Qt durante o teste, 21/21; consumidor Windows isolado, 20/20, sem Qt na ligação ou módulos. |
| 1225 — pacotes | **fail, F3/P2** | O ZIP contém dxcompiler.dll/dxil.dll sem materiais específicos de avisos recuperáveis. |
| 1226 r2 — uso real | **pass** | Nominal/efetiva, valores normativos, invalidação, erro/correção, limpeza, teclado, redimensionamento e fechamento nas duas plataformas. |

O terceiro requisito reprovado no inventário geral é **1228**, pelo mesmo F3 do ZIP. Há **duas falhas concretas**, sem confundir os três fail com três causas independentes. Os cálculos e as ações efetivamente observados não eliminam a falha de visibilidade ou a falta de avisos.

## Autoridade, continuidade e fonte

[1040](../../../documents/1040/r1-alternative-validation-and-branch-push.md) registra a ordem de usar o aplicativo por outro meio e fazer o push. O usuário depois respondeu **“Desbloqueei a sessão”**. O root conferiu WTS **UNLOCK=1** na sessão do aplicativo antes de retomar; [resposta e observação](../../dispatch/r3/windows-unlock-observation.json). Não houve tentativa de desbloquear, automatizar credenciais ou contornar segurança.

O código executado permanece **57ef26901d4381ead16c7347483d588ad9d92efe**. O [primeiro push do código](../../dispatch/r3/push-result.json) e o [push documental em bd56676](syncer.md) já foram confirmados diretamente no remoto [codex/mortgage-desktop](https://github.com/paulo-vitor-cs/ceseb/tree/codex/mortgage-desktop). Os 55 paths de produto/testes continuam iguais ao código testado. Commits documentais posteriores não são apresentados como novas execuções do aplicativo.

Foram preservados os corpos publicados de 2271 r1, 2281 r1, 2291 r1 e 2280 r1. O LOCK descrito por eles era real naquele corte; os novos reports usam revisões separadas. ROOT/MAIN/workspace continuam /home/paulo/ceseb, sessão 1-mortgage-desktop. A limitação antiga de somente local, introduzida pelo orquestrador, não foi reaplicada à ordem explícita de publicação.

## Execução recebida

[2272 Linux](../../dispatch/r3/linux-validation.md) e [2273 núcleo/ambiente](../../dispatch/r3/ubuntu24-core.md) registram Ubuntu 24.04.5 em userspace de contêiner, kernel WSL compartilhado, GCC 13.3 para o núcleo e runtime separado sem ferramentas de desenvolvimento para o DEB. O aplicativo foi usado numa sessão X11/Xvfb/Openbox privada. Os casos financeiros, teclado, erro/correção, limpeza, ajuda offline, pasta de licenças, launcher e reabertura foram executados. Nas duas escalas, todos os 47 controles/textos necessários foram alcançados por foco/rolagem e capturas de 800×600 e 1600×1200. Isso não é uma alegação de kernel Ubuntu físico separado ou de QtTest.

[2271 r2 Windows](../../dispatch/r3/windows-validation-r2.md) registra o ZIP real em Windows 11 Pro x86_64 10.0.26200, com PATH apenas Windows/System32 e Qt privado. UIAutomation observou nomes, valores, rótulos, foco e geometria; SendKeys e mouse nativos atuaram somente no aplicativo identificado por EXE/PID/foreground e sessão desbloqueada. O fluxo completo por teclado percorreu os sete controles e a inversa, calculou nominal/efetiva por Enter, provocou erro com zero, corrigiu, limpou com Space, abriu ajuda e fechou por Escape. Reabrir restaurou os padrões e nenhum resultado persistido. O link de licenças abriu a pasta real no Explorer.

Os três PIDs próprios usados no Windows foram fechados por Escape, com estado observado exited=true. Isso não foi convertido em um exit code do app não coletado. A ajuda foi percorrida por PageDown e seus parágrafos ficaram legíveis. A versão e textos periféricos têm baixo contraste, registrado no finding; não foi inventado um novo limiar para reprovar o conteúdo de 1217.

| Entrada | Valores observados no Windows e Linux |
|---|---|
| R$ 1.000,00; nominal 12%; 3 meses | Price 340,02 / última 340,03 / total 1.020,07 / juros 20,07; SAC 343,34 / última 336,66 / total 1.020,00 / juros 20,00; diferença +0,07. |
| R$ 1.000,00; efetiva 12%; 3 meses | Mensal 0,948879%; Price 339,68 / última 339,68 / total 1.019,04 / juros 19,04; SAC 342,83 / última 336,49 / total 1.018,98 / juros 18,98; diferença +0,06. |
| R$ 1.000,00; 0%; 600 meses | Price 599 pagamentos, ordinária 1,67, última 1,34 e aviso completo de quitação 599/600; SAC 600 pagamentos, primeira 1,67, última 1,66; total 1.000,00 e juros zero em ambos. |

No Windows, a escala de processo 2 manteve DPI do sistema em 96; não houve alteração global de tema ou display. O cliente exato 1600×1200 foi confirmado antes e depois do PrintWindow. O monitor físico 1920×1080 limita a fidelidade da região inferior fora da tela; essa região não foi usada como aprovação visual. O fail de 1216 já é inequívoco na captura real de 100% e nos campos dentro da área visível a 200%, independentemente desse limite.

## Falhas confirmadas

**F4/P2, 1216 AC1:** com AppsUseLightTheme=0 e SystemUsesLightTheme=0, os quatro campos têm valores corretos na árvore acessível e produzem os cálculos esperados, mas parecem vazios. [Captura original da janela](../../../../../../../docs/validation/r3/windows-dark-inputs.png), [resumo nativo da execução](../../../../../../../docs/validation/r3/windows-validation-summary.json). O impacto é não conseguir confirmar visualmente os dados digitados. O código fixa fundos brancos sem resolver a cor de texto/paleta herdada; cabeçalho, prazo, diferença, rodapé e versão também têm baixo contraste. Não houve mudança de tema ou source patch para mascarar o defeito.

**F3/P2, 1225 AC1 e 1228:** o ZIP c71634da99c2efe7774db55e011883b2c12f001db7a972404093f7c05968da4b continua incluindo duas DLLs DXC sem seus materiais específicos. O pacote abriu e os cálculos funcionaram; isso não satisfaz o critério de composição/avisos. É uma falha de requisito, sem conclusão jurídica geral.

## Revisão e aplicação

[2281 r2](dev-review-r2.md) recebeu o retorno completo, inspecionou dados, driver e capturas, e julgou **1215 pass, 1216 fail e 1226 r2 pass**. Cinco declarações foram validadas somente leitura: três requisitos e os agregados completos de 1013 r2/1014 r3, ambos parciais. Os resultados 1217/1221 pass e 1225/1228 fail são preservados do mesmo código. O reviewer não repetiu uma suíte inteira sem mudança de código: sua execução anterior 26/26 por backend e 21/21 core foi reutilizada com identidade comprovada, sem nova alegação de execução.

A reconciliação [2291 r2](analyst-r2.md) aplica os cinco resultados sem reexecutar ou reinterpretar o teste. A evidência identifica os métodos reais e o snapshot de código. Os 47 corpos aprovados permanecem preservados; as 19 notas continuam draft. As specs numéricas seguem implemented; UI e entrega continuam parciais pelos fail, agora com todos os requisitos membros julgados. Nenhum plano recebe implemented por contagem automática de testes.

O recorte documental selecionado compreende o README e as cópias originais de evidência, com destino à mesma branch solicitada. O código não foi alterado nesta validação. Recibos escritos depois do congelamento não são incluídos retroativamente no commit que descrevem. DVC permanece N/A no projeto. Não houve PR, merge, release, promoção de conhecimento ou reparo automático dos findings. A sessão permanece aberta com os dois defeitos claramente identificados; nenhum protocolo destes seis aguarda desbloqueio ou execução. Telemetria opcional não foi usada nesta rodada.
