---
id: 2440
revision: 1
type: document
tags: [mortgage, synapses, corrections, publication]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Rodada independente das correções F3/F4 no código 3f4dc69, após execução completa dos planos 2005 e 2006.
use_when:
- Recuperar o corte, os relatórios exigidos e a publicação autorizada das correções F3/F4.
---
# Correções F3/F4 — Synapses

A ordem humana [1041](../../../documents/1041/r1-f3-f4-correction-authority.md) autoriza o dispatch corretivo, com procedimento concreto [1042](../../../documents/1042/r1-f3-f4-concrete-procedure-release.md). A ordem de uso real alternativo e push [1040](../../../documents/1040/r1-alternative-validation-and-branch-push.md) permanece vigente até o syncer final. Destino: repositório público pessoal paulo-vitor-cs/ceseb, branch codex/mortgage-desktop. Não há autorização inferida para merge, release, tag ou fechamento da sessão; DVC não está configurado neste projeto.

Código alvo: **3f4dc69ec84230b4035572fc62af3d13db451d2a**. O último corte público é b5bb61c7a9a73f3a9174044621a7497dc274d0f3. Testes têm cobertura separada b5bb61c..98af104b0f38160aaf04ee2915f4d60e949d13aa, quatro operações; produto tem cobertura 98af104..3f4dc69, duas operações. O erro inicial de preparo no commit 35cdf93 foi preservado, corrigido somente no preparo e não contado como regressão comportamental.

Retornos completos recebidos e lidos pelo root: [2401 autoria dos testes](../../dispatch/r4/tests/planning.md), [2402 autoria do produto](../../dispatch/r4/implementation/planning.md), [2411 BASE](../../dispatch/r4/tests/base-result.md), [2412 execução final própria dos testes](../../dispatch/r4/tests/final-result.md) e [2421 execução do produto](../../dispatch/r4/implementation/result.md). BASE reproduziu os quatro campos sem glifos com paleta escura e a presença indevida de duas DLLs. Os mesmos testes passam após a correção, sem mudança dos oráculos. Execução de cada executor: 27/27 GUI offscreen e nativa, 21/21 core, em Ubuntu 24.04/GCC 13 e Windows 11/MSVC Community 2022. Uso real em 100%/200% foi executado nos dois sistemas, com capturas de regiões efetivamente visíveis, sem mudar o tema Windows.

ZIP final SHA256 f5071e93d3c99afd4b5fae395322897c8d074f928f66952366eb0b05ad762d20; DEB final SHA256 8dd414362fc06456a7aadaf44acb5a80264514497433d0ba24f240d129628336. O ZIP tem 188 arquivos/187 hashes, sem DXC/DXIL; o DEB tem 184 arquivos/182 hashes. Os 21 registros históricos entregues por pacote permanecem atribuídos aos seus cortes antigos.

A revisão independente exigida é 2441, no head independent-review, distinto dos dois autores/executores. Escopo: todos os 25 requisitos efetivos e quatro specs no novo código, planos, fontes e evidência real; os três fail anteriores não são alterados antes do julgamento. Após o retorno completo, analyst 2451 aplica somente as declarações recebidas e conclusões de execução com cobertura, preservando os 49 corpos aprovados. Syncer 2461 publica o recorte documental concreto e os commits de código na branch autorizada, com leitura direta do remoto. Nenhum retorno de execução constitui aprovação humana ou aceitação automática de requisito.

## Revisão recebida

[2441 revisão independente](dev-review.md) concluiu **25 requisitos pass e quatro specs com todos os membros pass**, no código 3f4dc69. As suites próprias do revisor passaram 27/27 offscreen e 27/27 nativas, mais 21/21 core, em cada plataforma, sem falhas ou skips. As 29 declarações passaram validação somente leitura. F3 e F4 estão resolvidos no novo código e nos pacotes identificados; os resultados negativos anteriores permanecem históricos. Os 49 corpos aprovados foram preservados. As demonstrações reais são atribuídas aos executores e foram confrontadas com pixels, logs e a execução própria do revisor.

## Reconciliação concluída

[2451 analyst](analyst.md) aplicou 31 operações nativas: 25 requisitos pass, quatro specs implemented e planos 2005/2006 implemented. Foram sete mudanças literais e 24 reafirmações no mesmo código 3f4. Preservação: 49 corpos aprovados, 57 paths atuais, 38 arquivos históricos e 19 notas draft. Nenhum corpo aprovado foi reescrito.

## Publicação efetiva

[2461 syncer](syncer.md) registra commit e push reais em **183fabed75334f8d51412a72c77914ada02c531b**, com confirmação direta da branch remota. Foram selecionados 216 paths, com 56 alterados no commit documental; os três commits anteriores de testes/produto também chegaram ao remoto. O código testado continua 3f4dc69. Preservação pós-push: 49 corpos, 57 paths atuais, 38 arquivos históricos e 19 notas draft; índice vazio e fontes alheias preservadas. A branch é pública e pessoal, [codex/mortgage-desktop](https://github.com/paulo-vitor-cs/ceseb/tree/codex/mortgage-desktop).

O root recebeu e leu integralmente 2461 antes de liberar o segundo recorte estrito: somente este fechamento, o relatório do primeiro push e seis recibos já produzidos. Esse segundo recorte documenta um push que efetivamente aconteceu; não atribui o próprio recibo ao commit anterior. O readback nativo final permanece separado do snapshot que descreve, sem terceiro commit automático. Não houve PR, merge, tag ou release; DVC é N/A. A sessão permanece aberta para acompanhamento humano, com F3/F4 resolvidos e nenhum dos 25 requisitos sem resultado. Telemetria opcional não foi usada nesta rodada.
