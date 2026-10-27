---
id: 2291
revision: 1
type: document
tags: [mortgage, synapses, reconciliation, validation, publication]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Aplicação dos cinco resultados da revisão 2281 no snapshot 57, com 1217 e 1221 pass, 1225 fail atual, specs parciais e publicação da branch explicitamente autorizada.
use_when:
- Recuperar os resultados aplicados e a preservação antes da publicação documental pelo syncer e da retomada dos três protocolos Windows interrompidos.
---
# Reconciliação da validação real

Apliquei **cinco operações nativas, todas exit 0**, a partir da [revisão independente 2281 r1](dev-review.md). Os requisitos **1217 r1 e 1221 r1 passaram de published para pass**. **1225 r1 permaneceu fail**, agora com evidência explícita no snapshot **57ef26901d4381ead16c7347483d588ad9d92efe**. As specs **1013 r2 e 1014 r3** permaneceram partial implemented. Foram duas mudanças literais de status e três reafirmações sustentadas; o corpo dos cinco alvos foi preservado.

Instância fresca `/root/validation_analyst_r3`, mesmo head lógico `design-project-1/synapses-analyst`, mesma [memória própria](../../../session_memory/design/synapses-analyst.yaml), entrada r3 e retorno r4. ROOT/MAIN/workspace de implementação `/home/paulo/ceseb`, sessão `1-mortgage-desktop`, branch `codex/mortgage-desktop`. Provider codex, native_id desconhecido; leitura manual do contrato não demonstra carregamento nativo do plugin no App. CLI observada `mikoshi`; as respostas completas das operações estão conservadas abaixo.

## Fontes e autoridade

Recebi todos os retornos requeridos antes da aplicação: [2271 Windows parcial por sessão bloqueada](../../dispatch/r3/windows-validation.md), [2272 uso real do aplicativo Linux](../../dispatch/r3/linux-validation.md), [2273 núcleo Ubuntu 24 e ambiente de pacote](../../dispatch/r3/ubuntu24-core.md) e 2281. Li seus textos, os corpos exatos dos cinco alvos, minha memória, a autoridade de publicação original [1028](../../../documents/1028/r1-revisions-approval-and-planning-authority.md), a execução [1034](../../../documents/1034/r1-engineering-execution-approval.md) e a ordem atual [1040](../../../documents/1040/r1-alternative-validation-and-branch-push.md). Os alvos já estavam publicados ou em estado de resultado antes desta validação; não converti execução histórica de draft em execução publicada.

1040 autoriza **testar por outros meios e fazer o push**. O [recibo do push inicial desta rodada](../../dispatch/r3/push-result.json) registra a branch no remoto em 57, confirmado pelo root. A limitação anterior de somente local não é retomada: o próximo syncer deve executar a publicação documental preparada sob a autoridade atual e conferir o resultado remoto real. Publicar no Git não equivale a promover notas de conhecimento, fazer merge, criar PR/release ou encerrar a sessão.

O analyst aplica o parecer sem repetir os testes, a revisão semântica, os cálculos, a auditoria de licenças ou a inspeção de imagens. Os ensaios e valores de 2271/2272/2273 permanecem atribuídos aos respectivos autores; os julgamentos são os de 2281.

## Operações aplicadas

| Alvo exato | Antes | Depois | Evidência e implementação |
|---|---|---|---|
| 1217 r1 | published | pass | 2281, Req 1217; snapshot 57 |
| 1221 r1 | published | pass | 2281, Req 1221; snapshot 57 |
| 1225 r1 | fail | fail | 2281, Req 1225; snapshot 57 |
| 1013 r2 | partial implemented | partial implemented | 2281; conjunto completo de sete requisitos, cinco resultados e dois protocolos Windows interrompidos |
| 1014 r3 | partial implemented | partial implemented | 2281; conjunto completo de cinco requisitos, quatro resultados e um protocolo Windows interrompido |

[Comandos literais e respostas](analyst/assets/transitions.json), [estados antes](analyst/assets/before-targets.json), [preservação depois](analyst/assets/preservation.json) e [conclusão mecânica](analyst/assets/completion.json). O CLI alterou somente os campos permitidos status/updated, preservando ID, revisão, corpo e os demais metadados. Os cinco retornos foram ok e nenhuma declaração faltante foi inventada.

**1225 tem agora fail atual no 57**, por AC1 e pelo mesmo F3 de materiais específicos DXC/DXIL ausentes no ZIP. O fail antigo ce5 por launcher e a ausência de julgamento integral na rodada 2 continuam nos reports históricos. A nova evidência não reescreve aqueles fatos: há um novo resultado explícito no mesmo ID/revisão, com snapshot e motivo próprios. A aplicação não declara infração jurídica geral nem apaga o sucesso Linux do pacote.

1217 pass é o julgamento do recurso de ajuda e acesso local às licenças: o clique abriu o PCManFM offline. 1221 pass é o julgamento da independência do componente nos dois sistemas. A interpretação do reviewer não exige desinstalar um SDK alheio de todo o host Windows; seu parecer confronta a interface, build e consumo real do núcleo sem Qt. O analyst não criou uma obrigação nova nem alterou os critérios.

## Inventário e protocolos Windows

O inventário atual atribuído aos reports 2241/2281 no mesmo snapshot é **20 requisitos pass, dois fail (1225 e 1228) e três protocolos Windows interrompidos (1215, 1216 e 1226 r2)**. Os outros 19 requisitos não receberam uma nova operação individual nesta rodada. As specs numéricas 1008 r2/1012 r2 permanecem implemented; UI 1013 r2 e entrega 1014 r3 continuam parciais. Planos 2001/2002/2003/2004 não receberam transição nova.

1215, 1216 e 1226 r2 preservam seus headers published: 2281 não emitiu novo pass/fail global para esses alvos. Os cenários Linux foram executados, inclusive duas escalas, teclado, resultados e fechamento. O protocolo Windows parou antes da primeira entrada porque a sessão real está bloqueada: **WTS SessionId 1, SessionFlags LOCK=0**, na mesma sessão do aplicativo. Não é a falha antiga de URI do Computer Use e não é uma falha observada do aplicativo. O usuário já recebeu o pedido de desbloqueio; não houve input, autenticação ou tentativa de contornar a tela de bloqueio.

A retomada deve observar o estado desbloqueado e continuar o app/driver Windows existente. Não atribuí resultado por silêncio ou pela presença do processo. O app e os scripts estão disponíveis conforme 2271.

## Corpos, fontes, conhecimento e relações

**47/47 corpos aprovados** continuam iguais aos hashes existentes da reconciliação 2251. **55/55 paths de produto/testes** continuam iguais ao registro recebido do reviewer e aos blobs Git do snapshot 57. Isso inclui os dois scripts de regressão e os assets anteriores; a comparação é mecânica, sem novo julgamento de código. A aplicação não fez staging, commit, checkout, push ou limpeza. README raiz e os arquivos dos outros owners permaneceram fora da minha escrita.

As **19 notas de conhecimento continuam draft** e byte a byte iguais aos hashes da leitura anterior deste mesmo head. Reusei as disposições atribuídas, sem nova leitura técnica das pesquisas; [disposições atuais](analyst/assets/knowledge-dispositions.json). A publicação Git autorizada do projeto não lhes atribui maturidade publicada nem promoção para um corpus permanente. Nenhum novo candidato, revisão de conhecimento ou retirement foi criado.

As alterações são somente de status: identidades, corpos e declarações incidentes anteriores foram retidos. O [mapa de 704 registros incidentes da rodada anterior](../r2/analyst/assets/edge-dispositions-final.json) é uma fonte histórica atribuída, não uma contagem nova deste corpus expandido. As referências novas de 2281/2291 identificam seus alvos e o snapshot sem rebases automáticos. Não criei parent, enum de substituição ou relação por tags. A seleção efetiva 1226 r2/1014 r3 permanece explícita; o retirement recusado de 1226 r1/1014 r2 não foi repetido nem contornado com edição de corpos aprovados.

A [consulta scoped de 14 diretórios](analyst/assets/retrieval.json) retornou partial, exit 0, com **index_incompatible**: a seleção inclui dispatch/r3 e synapses/r3 além dos 12 diretórios anteriores. Não houve rebuild neste head. O refresh final da mesma seleção atual pertence ao root após todos os reports; a aplicação nativa dos cinco alvos não dependeu de inventar cobertura de grafo. Nenhum outro repositório ou pacote foi incluído.

## Leitura e handoff

[Manifesto de leitura](analyst/assets/source-read-manifest.json). Li os corpos dos cinco alvos e os textos completos de 2271/2272/2273, a prosa material de 2281 e suas cinco declarações mecânicas, as autoridades citadas e a própria memória. Os anexos de identidade/preservação e as 19 notas foram comparados pelos registros existentes. Não reli XML, logs de build, binários, capturas ou todo Brain; não executei qualquer suíte ou UI.

O próximo responsável é o **syncer de publicação**, sob 1040: preservar o snapshot de código executado, publicar o recorte documental preparado e confirmar a branch remota. O root integra o retorno, registra os resultados e o refresh final; os três protocolos Windows continuam prontos para retomar após desbloqueio. Sem correção automática de F3, promoção de conhecimento, merge, release, aceite de produto ou fechamento da sessão. [Check de schema/links deste report](analyst/assets/report-check.json).
