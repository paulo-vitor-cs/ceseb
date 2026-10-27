---
id: 2293
revision: 1
type: document
tags: [mortgage, synapses, publication, git, preservation]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Publicação documental confirmada na branch codex/mortgage-desktop em bd56676, preservando as 55 fontes do código testado 57 e os 47 corpos aprovados.
use_when:
- Recuperar o commit e o push efetivamente publicados e os limites do recorte após a validação real do aplicativo.
---
# Publicação confirmada após a validação real

**Commit e push concluídos:** `bd56676ff02816205825b4f7209f793e4064acb2` na branch **codex/mortgage-desktop**, no [repositório pessoal público](https://github.com/paulo-vitor-cs/ceseb/tree/codex/mortgage-desktop). O push retornou **exit 0** e `git ls-remote --heads origin refs/heads/codex/mortgage-desktop` confirmou diretamente o mesmo SHA. [Commit publicado](https://github.com/paulo-vitor-cs/ceseb/commit/bd56676ff02816205825b4f7209f793e4064acb2).

O commit é documental, filho direto de **57ef26901d4381ead16c7347483d588ad9d92efe**, que continua sendo a revisão executada pelos pacotes e pelos testes. Comparei os **55/55 paths de produto/testes** no filesystem, no commit testado e no novo commit: bytes iguais. Não anuncio uma execução nova do código sob outro identificador.

## Identidade e autoridade

Instância fresca `/root/publication_syncer_r3`, mesmo head lógico `design-project-1/preservation-syncer`, mesma [memória própria](../../../session_memory/design/preservation-syncer.yaml), entrada r3 e retorno r4. ROOT/MAIN/workspace associado: `/home/paulo/ceseb`, sessão `1-mortgage-desktop`, checkout existente em `codex/mortgage-desktop`. Não criei worktree, não troquei branch e não fiz merge. Provider codex, native_id desconhecido; leitura manual de contratos não prova carregamento nativo do plugin no App.

Autoridade atual: [1040](../../../documents/1040/r1-alternative-validation-and-branch-push.md), ordem explícita de testar por outros meios e fazer o push. A memória anterior descrevia somente o recorte BOOT local da rodada 2; esse limite não foi reaplicado à ordem atual. Recebi o retorno do [analyst 2291](analyst.md) após os reports requeridos e o julgamento de [2281](dev-review.md). O [push imediato anterior do código 57](../../dispatch/r3/push-result.json) já estava confirmado pelo root; esta operação publica os documentos preparados depois da reconciliação.

## Recorte congelado e efeitos

Usei somente os **148 paths explícitos** do [manifesto preparado pelo root](../../dispatch/r3/publication-candidate.json), sem ampliar ou regenerar a seleção. São README atual, specs, requisitos, planos, decisões, ferramentas, documentos, notas de pesquisa com seus estados preservados, reports selecionados, duas capturas originais, cinco recibos mecânicos e os **21 registros históricos exatos** exigidos por Packaging.cmake.

O índice estava vazio, HEAD e remoto em 57, na branch correta. Fiz staging por listas de argumentos e pathspecs exatos. Sete registros históricos em out/review-wsl são ignorados por padrão e receberam `git add -f` **somente nos sete nomes autorizados**; nenhuma árvore out foi adicionada em bloco. A conferência do índice confirmou os bytes atuais dos 148 paths e **145 mudanças efetivamente staged**, sem path inesperado. Três paths selecionados já estavam rastreados e iguais, portanto não geraram diff.

Em seguida executei `git commit -m "docs: publish project design and observed app validation"`, exit 0; `git push origin codex/mortgage-desktop`, exit 0; e o readback direto acima. A pós-conferência confirmou os 148 paths no commit iguais aos fontes congelados, nenhum selected path dirty e índice novamente vazio. Permanecem dirty/untracked fora do recorte, incluindo estado/memórias de coordenação e outputs de outros owners; não foram limpos, staged ou sobrescritos.

Evidências próprias: [preflight](syncer/preflight.json), [seleção no índice](syncer/staged-selection.json), [commit](syncer/commit-result.json), [push](syncer/push-result.json), [readback](syncer/remote-readback.json) e [pós-publicação](syncer/post-publication.json). São observações da operação, sem novo ledger de hashes; as comparações de corpos reutilizam os hashes já existentes do analyst, e Git fornece as identidades nativas do recorte.

## Preservação e validação atribuída

**47/47 corpos aprovados preservados**, comparados com o registro existente de 2291. As **19 notas de conhecimento continuam draft**; seu compartilhamento no Git não altera maturidade nem promove conhecimento a outro corpus. Não houve operação nova de status, edição de requisito, fonte de produto, critério ou teste.

Os resultados são atribuídos a 2281/2291: **20 requisitos pass, dois fail (1225/1228) e três protocolos Windows interrompidos (1215/1216/1226)**. O aplicativo real em Ubuntu 24 foi usado nos cenários de teclado, cálculo, erro/correção, limpeza, escalas, ajuda e licenças offline; core Ubuntu 24/GCC 13 passou 21/21 e consumidor Windows passou 20/20. Não repeti testes, inspeção de imagens ou auditoria jurídica. F3 de avisos DXC/DXIL continua no ZIP e não foi corrigido para publicar.

Na seleção congelada de 2271 r1/2281 r1/2291 r1, a sessão Windows estava confirmada bloqueada por WTS LOCK=0. Após esta publicação, o root informou novo readback WTS UNLOCK=1 e retomada da tarefa Windows interrompida, com novo report 2271 r2 separado. Essa continuação posterior não altera o recorte publicado nem recebe novo julgamento deste syncer. Não enviei input, capturei tela, matei processo ou tentei contornar o bloqueio.

DVC não está configurado na seleção do projeto: sem .dvc/config, .dvcignore ou pointers/pipeline encontrados, portanto **N/A**. Nenhuma CLI DVC, instalação, configuração de armazenamento ou upload foi executado. Não houve PR, merge, tag, release ou disparo manual de CI; nenhuma conclusão sobre uma execução remota de CI é inferida apenas do push.

## Leitura, limites e retorno

Li a própria memória r3, autoridade 1040 integral, analyst 2291 integral, resultado/corte e trechos materiais de 2281, round 2280, manifesto exato e os registros de preservação/identidade usados nas comparações. Li skill sync, role syncer, referências publicação/head-memory e cards Git/DVC/check aplicáveis. Git observado 2.53.0. As comparações mecânicas não são uma releitura técnica das 148 fontes, do produto ou de toda a pesquisa.

O primeiro comparador de corpo usou separador `---` seguido de newline, enquanto o hash existente inclui esse newline na cauda após `---`. A conferência foi corrigida para o formato real dos registros e os 47 corpos coincidiram; nenhum staging ou mudança de fonte precedeu essa correção do observador. Não houve erro de Git, efeito remoto desconhecido ou retry de push.

**Este report 2293, seus anexos e a memória própria são posteriores ao freeze e não integram o commit que descrevem.** O root recebe o retorno completo, atualiza somente sua coordenação e faz o refresh final dos 14 diretórios de corpus. Nenhum novo commit é iniciado para incluir recursivamente o próprio recibo. A sessão permanece aberta e os três protocolos Windows foram retomados pelo respectivo actor após o desbloqueio informado pelo root; publicação não significa aceite de produto ou encerramento da sessão.
