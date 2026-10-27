---
id: 2291
revision: 2
type: document
tags:
- mortgage
- synapses
- reconciliation
- windows
- validation
- publication
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: 'Aplicação final dos protocolos Windows retomados: 1215 e 1226 pass, 1216 fail; 22 requisitos
  pass e três fail no mesmo código 57, sem protocolo interrompido.'
use_when:
- Recuperar os cinco resultados aplicados após o desbloqueio e a preservação antes de publicar os artefatos
  atualizados.
---
# Reconciliação após uso real do aplicativo Windows

Apliquei **cinco operações nativas, todas exit 0**, a partir de [2281 r2](dev-review-r2.md). **1215 r1 e 1226 r2 passaram para pass; 1216 r1 passou para fail.** As specs **1013 r2 e 1014 r3** permaneceram partial implemented, agora com todos os membros julgados no mesmo código. Foram **três mudanças literais e duas reafirmações**, sem alteração do corpo de qualquer alvo.

O inventário do código executado é **22 requisitos pass e três fail: 1216, 1225 e 1228**. Os seis solicitados tiveram os cenários executados: **quatro pass — 1215, 1217, 1221 e 1226 — e dois fail — 1216 e 1225**. Nenhum dos três protocolos Windows continua interrompido. Os resultados anteriores das outras obrigações são atribuídos a 2241/2281 r1 no mesmo snapshot, sem nova operação individual.

Instância fresca /root/windows_validation_analyst_r3r2, mesmo head lógico design-project-1/synapses-analyst, mesma [memória própria](../../../session_memory/design/synapses-analyst.yaml), entrada r4 e retorno r5. ROOT/MAIN e workspace de implementação /home/paulo/ceseb, sessão 1-mortgage-desktop, branch codex/mortgage-desktop. Provider codex; native_id desconhecido. Leitura manual não comprova carregamento nativo do plugin.

## Fontes e autoridade

Recebi o [retorno final Windows 2271 r2](../../dispatch/r3/windows-validation-r2.md) e o parecer independente 2281 r2 completos, depois do desbloqueio humano. A autoridade atual é [1040 r1](../../../documents/1040/r1-alternative-validation-and-branch-push.md), que ordena testar por outro meio e fazer o push. A resposta “Desbloqueei a sessão” e a observação WTS UNLOCK=1 precedem a retomada segundo esses reports. As fontes Linux [2272](../../dispatch/r3/linux-validation.md) e [2273](../../dispatch/r3/ubuntu24-core.md) são reutilizadas da leitura anterior deste mesmo head, por identidade integral com o commit documental bd56676.

O código executado continua **57ef26901d4381ead16c7347483d588ad9d92efe**. O HEAD observado **bd56676ff02816205825b4f7209f793e4064acb2** é documental; não rebaseei o resultado para outro identificador de código. Os três alvos de requisito tinham status published antes destas operações. A aprovação dos corpos permanece nas fontes anteriores preservadas; a aplicação atual não retrodata execução histórica nem cria nova aceitação.

## Operações aplicadas

| Alvo exato | Antes | Depois | Fonte e target |
|---|---|---|---|
| 1215 r1 | published | pass | 2281 r2, Req 1215; código 57 |
| 1216 r1 | published | fail | 2281 r2, Req 1216/F4; código 57 |
| 1226 r2 | published | pass | 2281 r2, Req 1226; código 57 |
| 1013 r2 | partial implemented | partial implemented | Sete requisitos julgados: seis pass e 1216 fail; código 57 |
| 1014 r3 | partial implemented | partial implemented | Cinco requisitos julgados: três pass e 1225/1228 fail; código 57 |

[Comandos literais e respostas](analyst-r2/assets/transitions.json), [alvos antes](analyst-r2/assets/before-targets.json), [preservação](analyst-r2/assets/preservation.json) e [inventário dos 25 requisitos selecionados](analyst-r2/assets/current-requirements.json). O CLI validou a declaração exata e alterou somente status/updated, preservando ID, revisão, corpo e demais valores de metadados. Não apliquei novamente os outros requisitos nem qualquer plano.

1215 pass representa a ordem de foco, associações, teclas e fluxo completo nos dois sistemas. 1226 pass representa os cálculos e transições funcionais efetivamente executados, sem apagar a falha de apresentação. **1216 fail é o F4/P2 do reviewer:** no Windows escuro, campos preenchidos têm texto branco sobre fundo branco. A falha está comprovada em 100% e na área visível a 200%; não depende de inferir fidelidade aos pixels fora do monitor. Não criei limiar WCAG ou critério de preferência estética.

1217/1221 continuam pass pelos reports anteriores do mesmo código. **1225 e 1228 continuam fail pelo F3**, materiais específicos de avisos DXC/DXIL ausentes no ZIP. O analyst não reinterpretou esses julgamentos, não repetiu as demonstrações e não converteu UIAutomation em prova de visibilidade. A distinção entre ações que funcionaram e texto invisível pertence ao parecer independente recebido.

## Preservação e relações

**47/47 corpos aprovados e 55/55 paths de produto/testes preservados**, por comparação com os registros existentes do analyst e os blobs Git do código 57. Os valores de ID/revisão e os demais metadados dos cinco alvos coincidem fora status/updated. Os reports r1 publicados — 2271, 2281, 2291 e 2280 — e os retornos Linux publicados continuam byte a byte iguais ao commit documental bd56676. Esta revisão 2 não altera [2291 r1](analyst.md) nem transforma seu estado LOCK histórico em erro.

As **19 notas de conhecimento permanecem draft**, com bytes iguais à fonte documental publicada e [disposições atribuídas preservadas](analyst-r2/assets/knowledge-dispositions.json). Publicação Git não lhes atribui maturidade nem promoção para um corpus permanente. Não houve novo candidato, revisão de conhecimento, source patch ou retirement.

As alterações são somente de resultado: corpos, identidades e declarações incidentes anteriores ficam retidos. As citações novas identificam a continuação e seus alvos exatos; não criam parent, relações por tags ou enum novo. A seleção efetiva de 1226 r2/1014 r3 continua explícita. O retirement anteriormente recusado de 1226 r1/1014 r2 não foi repetido nem contornado. O refresh final dos mesmos 14 diretórios de corpus pertence ao root após todos os reports; este head não fez rebuild nem alegou índice current.

## Leitura, efeitos e handoff

[Manifesto de leitura](analyst-r2/assets/source-read-manifest.json). Li os reports novos, autoridade 1040 e própria memória; os cinco alvos foram carregados para identidade/preservação e as cinco declarações foram processadas. Reusei as leituras anteriores de Linux/Ubuntu 24 e pesquisas por identidade, sem novo exame técnico de logs, XML, imagens, binários ou bibliotecas. Não executei suíte, UI ou pesquisa externa; não fiz staging, commit, push, instalação, limpeza, alteração de README ou coordenação de outro owner.

O próximo responsável é o **syncer de publicação**, sob a ordem 1040: publicar o recorte atualizado de metadados, reports, README e evidência do Windows, e confirmar a branch remota. A limitação antiga de somente local não é retomada. O código executado deve continuar identificado como 57; o commit documental posterior não é nova execução do app. Não há novo pedido de desbloqueio: os testes Windows terminaram e os processos próprios foram fechados segundo 2271 r2.

O root recebe este retorno completo e conclui o refresh final e o resumo. **F3 e F4 são os trabalhos concretos restantes de produto; nenhum protocolo de validação deste recorte continua aguardando execução.** Não iniciei reparo automático, promoção, merge, release, aceite de produto ou encerramento da sessão.

[Conclusão mecânica](analyst-r2/assets/completion.json) · [Check de schema/links](analyst-r2/assets/report-check.json).

Related: [2291 r1](analyst.md); [2281 r2](dev-review-r2.md); [2271 r2](../../dispatch/r3/windows-validation-r2.md).
