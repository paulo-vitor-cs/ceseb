---
id: 2103
revision: 1
type: document
tags: [mortgage, synapses, preservation, git, wsl]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Conferência final de preservação local do snapshot ce5, dos corpos e estados da sessão e do remoto público limitado ao bootstrap.
use_when:
- Recuperar o que foi preservado em commits locais, o que permanece somente no filesystem e os limites de publicação desta rodada.
---
# Preservação local — Synapses 1

A conferência BOOT está concluída no escopo delegado. **53 paths de produto/testes estão nos commits locais e limpos; 43 corpos aprovados conferem com o snapshot existente.** Os estados reconciliados e os relatórios estão presentes no filesystem. O GitHub contém somente o bootstrap documental em main; esta rodada não publicou os nove commits posteriores. Nenhum resultado de teste ou julgamento técnico foi repetido.

Responsável: syncer-preservation, logical head `design-project-1/preservation-syncer`, handle `/root/preservation_syncer`. ROOT e MAIN da sessão: `/home/paulo/ceseb`; sessão explícita `1-mortgage-desktop`. Memória própria: `session_memory/design/preservation-syncer.yaml`. Este head escreveu somente este relatório, anexos em `syncer/` e sua memória. Estado/memória raiz e round 2100 continuam sob ownership do orquestrador.

## Autoridade e associação

Li integralmente [1034 r1](../../../documents/1034/r1-engineering-execution-approval.md), [1035 r1](../../../documents/1035/r1-wsl-execution-direction.md), [decisão 1032 r1](../../../decisions/1032/r1-engineering-execution-arrangement.md), [round 2100 r1](round.md) e [analyst 2102 r1](analyst.md). A aprovação de 26 de outubro cobre os efeitos locais e commits dos filemaps. Exclui push, PR, merge, release, CI remoto e provisão não descrita. A data desta conferência é 27 de outubro; isso não muda a origem nem amplia a autorização.

O workspace sequencial ROOT é o arranjo aceito. O estado registrado aponta session.workspace e flow.implementation_workspace para ROOT. Git confirma um único worktree, em ROOT, no branch `codex/mortgage-desktop`. MAIN é a associação da sessão neste checkout; isso não significa que o checkout atual deva estar no branch main. Não fiz checkout para satisfazer uma interpretação genérica da skill. O branch main local permanece no bootstrap.

Ambiente observado: WSL2, kernel `6.18.33.2-microsoft-standard-WSL2`, Ubuntu 26.04, Git 2.53.0, gh 2.94.0 e Mikoshi 3.0.0 disponíveis. Usei os executáveis existentes; não instalei nem alterei configuração, credencial, remote ou trust. Os cards Git 2570 r8, DVC 2571 r13 e GH 2572 r8 foram lidos antes das operações dependentes.

## Git local e cobertura preservada

[Observação Git](syncer/git-local.json) conserva comandos, respostas, status, refs, lista completa de arquivos e história nativa, sem novo digest. Índice vazio. ROOT tem HEAD `ce5db2e9d7489e0b6258b449358d620a0c390b1e`; o delta bootstrap..ce5 contém exatamente 53 creates finais. A conferência contra os hashes já existentes do reviewer deu 53 correspondências, sem dirty nos paths revisados. Não fiz staging, commit, amend, fetch, checkout, stash, reset, cleanup ou push.

| Identidade preservada | Revisão Git |
|---|---|
| TEST_BASE / bootstrap público | 0bbd2854703444a27ce04600f5e227e0351f61bc |
| Assets originais / BASE_IMPL | 4e7e1842efe188c889dd9d5235f131f1502779b2 |
| Produto congelado / IMPLEMENTATION_HEAD | 76b9fe2ff8b6a034c9880daa315a7875f3d9bcdf |
| Binário, stage e DEB auxiliares do autor | 2b16879dfe1eb6ec55ea8d9310b2ae575cb1c7cf |
| Snapshot revisado / assets finais / novo pacote do reviewer | ce5db2e9d7489e0b6258b449358d620a0c390b1e |

A história nativa mostra nove commits locais posteriores ao bootstrap: um dos 22 assets originais, sete do produto/documentação e um dos cinco ajustes GUI. O último delta `76b9..ce5` contém somente cinco arquivos GUI, 10 inserções e 6 remoções. `2b..76b9` atualiza somente o relatório técnico. O pacote 2b não é reidentificado como ce5; o novo pacote ce5 é o do reviewer. Ambos permanecem outputs auxiliares WSL, sem alegação de entrega nativa ou remota.

Reutilizei os checks existentes de [2101](dev-review.md), [2011](../../test-execution/2001/r1-base-result.md), [2012](../../test-execution/2001/r1-final-result.md) e [2021](../../implementation-planning/execution.md), sem executá-los novamente:

| Range | Evidência recebida e preservada |
|---|---|
| 2001 original, 0bbd..4e7 | 22 creates; check histórico ok/limpo em 2011. O check posterior de 2101 é partial e tem cinco paths GUI posteriores; isso não altera o resultado histórico. |
| Correção 2001, 76b9..ce5 | Partial: plano declara creates e delta tem cinco modifies. |
| 2001 completo, 0bbd..ce5 | Ok, 22 creates cobertos, zero dirty planned; 31 unexpected paths de produto. |
| 2002, 4e7..76b9 | Ok, 31 creates cobertos, zero unexpected e zero dirty planned. |

Os 31 paths intercalados são exatamente os do filemap 2002: disposição retain, owner de produto; não são autoria dos testes. O conjunto completo está na observação e nos JSONs existentes [test-full](dev/test-full.json) e [product-final](dev/product-final.json). Cobertura de commits não transforma os procedimentos parciais em completos, nem atribui pass a requisito.

## Inventário de corpos, metadados e filesystem

[Preservation-observation.json](syncer/preservation-observation.json) registra os 43 alvos, estados atuais, comparação com o snapshot aprovado, 53 fontes, reports e membership Git. Ele reutiliza os identificadores/hashes existentes e guarda somente resultados de comparação, sem novo ledger de hashes. Os 43 corpos conferem; não houve alteração de corpo ou revisão por este head.

| Seleção atual | Preservação observada |
|---|---|
| 25 requisitos ativos r1 | 17 pass, 2 fail (1225/1227) e 6 published (1215/1216/1217/1221/1226/1228). |
| Specs 1008/1012 r2 | implemented. |
| Specs 1013/1014 r2 | partial implemented. |
| Planos 2001/2002 r1 | partial implemented. |
| 19 KNW r1 | Todos draft; sem promoção ou movimentação. |
| 2011, 2012, 2021 e 2101 | Presentes e idênticos aos registros de leitura já existentes de 2102. |
| README raiz | Bytes iguais à entrada já registrada pelo analyst; continua modificado em relação ao Git. |
| 2100 e 2102 | Presentes e lidos integralmente nas revisões r1; mantidos no filesystem. |

Os **43 documentos aprovados atuais e os reports acima não são arquivos versionados no Git deste corte**. Specs, requisitos, planos e demais fontes aceitas permanecem locais; status aplicado não significa commit ou publicação. Os 53 paths de código/testes são a seleção commitada. O bootstrap já contém 15 arquivos documentais/de configuração, mas as versões atuais de README raiz, decisão 1004, session_state.yaml e session_memory.yaml têm alterações locais preservadas. Não foram incorporadas artificialmente ao snapshot. O status capturado enumerou quatro paths tracked modificados e 428 untracked, incluindo a memória/anexos próprios já criados naquela observação; o inventário completo está no anexo Git, sem promessa de contagem imutável após a emissão deste relatório.

Os outputs `build/`, `out/` e `.mikoshi/cache/` foram confirmados ignorados pelo Git. Seus bytes e os arquivos históricos permanecem locais e não foram limpos. Não confrontei integralmente cada binário, dependência ou cache ignorado, nem tratei presença local como backup remoto. Preservo os resultados anteriores UNAVAILABLE no base, aborts por runtime e XCB 25/26, sem substituí-los pelos resultados posteriores. F1/F2 e as seis ausências continuam como recebidos de 2101/2102; não houve reparo ou novo julgamento.

## GitHub e DVC

[Readback remoto](syncer/remote-readback.json), por `gh repo view` e `git ls-remote --heads`, retornou exit 0. Identidade confirmada: [paulo-vitor-cs/ceseb](https://github.com/paulo-vitor-cs/ceseb), node ID `R_kgDOVX_-iQ`, owner pessoal `paulo-vitor-cs` (`U_kgDOBzkRjw`), visibilidade PUBLIC, isPrivate false e default branch main. Origin corresponde ao mesmo repositório público; nenhum valor de credencial foi exportado.

A lista remota de heads contém **somente** `refs/heads/main` em `0bbd2854703444a27ce04600f5e227e0351f61bc`. `refs/heads/codex/mortgage-desktop` está ausente. A comparação local bootstrap..ce5 é 0 commits remotos exclusivos e 9 locais exclusivos. Portanto GitHub não foi confirmado como detentor do código ce5 por esta conferência. Não procurei PR/issues como se houvesse uma seleção autorizada desses recursos, nem disparei CI.

[DVC-selection.json](syncer/dvc-selection.json) registra a inspeção restrita ao projeto selecionado: não há `.dvc/`, pointers `*.dvc`, dvc.yaml, dvc.lock ou .dvcignore nas fontes/sessão selecionadas. Build/out, cache, scratch e árvores vendor foram excluídos da busca. Não foi selecionado dataset, storage ou destino de upload. DVC **N/A** nesta rodada: não invoquei CLI DVC, não instalei, não fiz add, checkout, fetch, pull, push, GC ou configuração. Nenhuma sincronização DVC remota é alegada.

## Leitura, ferramentas e limites

A leitura própria integral cobre as autoridades, 1032, 2100 e 2102. A leitura de 2101 foi dirigida às seções de corte, execução, preservação, achados, pacote e cobertura (linhas 1–240, além da declaração final 960–1026); 2011 linhas 1–145, 2012 linhas 1–145 e 2021 linhas 1–178 cobrem seus efeitos/identidades pertinentes. As declarações/anexos mecânicos foram processados para suas identidades, arquivos, cobertura e preservação. Não afirmo releitura semântica integral de código, todos os critérios, logs, transcrições ou fontes externas. Julgamentos e execução continuam atribuídos aos respectivos autores/reviewer.

Apliquei agente syncer, skills sync/search, delegated-context, logical-head-memory, regras de autoridade/ownership/preservação e os cards pertinentes. [Retrieval próprio](syncer/retrieval.json) usou exatamente os dez diretórios da seleção scoped do analyst, com sessão/root explícitos: retornou exit 0, partial, index_state **stale**, recuperando as referências exatas por busca lexical. Não reconstruí outro grafo. O refresh da mesma seleção foi reservado explicitamente ao orquestrador para depois deste retorno. Assim, a geração 7/current de 2102 é uma observação histórica, e não o estado atual que alego. As fronteiras já conhecidas continuam limites; leitura direta sustenta esta conferência documental. Sem novas consultas de pesquisa, ferramentas de código ou testes.

## Próximo responsável e parada

O orquestrador recebe 2103 e a memória própria, atualiza seus registros e round, e faz o refresh final **da mesma seleção** conforme o despacho. Pode então entregar o resumo final com os limites reais: produto local preservado, dois defeitos confirmados, seis requisitos sem resultado, procedimentos parciais, nenhuma promoção e nenhuma publicação desta execução. Correções, novas plataformas, armazenamento DVC e publicação futura dependem de autoridade aplicável sobre efeitos e destino; este relatório não abre novo plano ou ciclo.

Não houve commit novo, operação remota mutante, instalação, provisão, mudança de produto/testes/normativos, escrita em state/memory raiz, promoção, merge, release ou fechamento de sessão. A conferência estrutural e de links deste relatório está em [report-check.json](syncer/report-check.json). Escopo local finito concluído. **STOP.**
