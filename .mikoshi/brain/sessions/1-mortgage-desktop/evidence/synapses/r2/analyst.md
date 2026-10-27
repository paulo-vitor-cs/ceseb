---
id: 2251
revision: 1
type: document
tags: [mortgage, synapses, reconciliation, status, preservation]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Reconciliação da Synapses 2 no snapshot 57 com 18 pass, 1228 fail, seis requisitos sem julgamento integral, planos parciais e três correções de metadados com corpos preservados.
use_when:
- Recuperar as aplicações de resultados, revisões efetivas, preservação e lacunas da Synapses 2 antes da conferência local pelo syncer.
---
# Reconciliação da Synapses 2

Apliquei 25 operações nativas de resultado, todas exit 0: 19 requisitos (18 pass e 1228 fail), quatro specs e dois planos. Cinco estados literais mudaram; 20 aplicações confirmaram estados já existentes com evidência atual. Corrigi somente o frontmatter dos três reports draft 2231. **47/47 corpos aprovados e 55/55 paths de produto/testes estão preservados**, iguais ao snapshot recebido e ao commit atual. Nenhuma suíte, build, pacote ou revisão técnica foi repetida pelo analyst.

Instância fresca `/root/synapses_analyst_r2`, mesmo head lógico `design-project-1/synapses-analyst`, mesma [memória própria](../../../session_memory/design/synapses-analyst.yaml), entrada r2 e retorno r3. ROOT/workspace de implementação/MAIN: `/home/paulo/ceseb`; sessão `1-mortgage-desktop`; branch `codex/mortgage-desktop`; HEAD **57ef26901d4381ead16c7347483d588ad9d92efe**. Role analyst e contratos do plugin Mikoshi 3.0.0 foram lidos manualmente. Provider codex, native_id desconhecido; handle não comprova identidade ou carregamento nativo. CLI observado `/home/paulo/.local/bin/mikoshi`, resolução `/home/paulo/.claude/plugins/data/mikoshi-exalor-labs/bin/mikoshi`, versão 3.0.0. Isso identifica o executável efetivamente chamado, sem afirmar carga nativa do plugin no App.

## Fontes recebidas e precondições

Recebi os retornos completos antes de aplicar resultados: [2241 r1](dev-review.md), [2211 r1 base](../../dispatch/r2/tests/2211-r1-base-result.md), [2212 r1 final](../../dispatch/r2/tests/2212-r1-final-result.md), [2221 r1 produto](../../dispatch/r2/implementation/2221-r1-implementation-result.md), [2222 r1 complemento Windows](../../dispatch/r2/implementation/2222-r1-qualified-windows-result.md), [2231 r1](../../dispatch/r2/windows-tools/2231r1-installation.md), [2231 r2](../../dispatch/r2/windows-tools/2231r2-community-installation.md) e [2231 r3](../../dispatch/r2/windows-tools/2231r3-community-readback.md). O retorno fail permite esta reconciliação; nenhum reviewer estava sendo aguardado. Não há hipótese científica neste recorte.

Li os alvos exatos, seus estados literais e corpos, as fontes de publicação/execução [1028](../../../documents/1028/r1-revisions-approval-and-planning-authority.md), [1034](../../../documents/1034/r1-engineering-execution-approval.md), [1036](../../../documents/1036/r1-bounded-corrections-and-validation-authority.md), [1037](../../../decisions/1037/r1-wsl-linux-validation-choice.md), [1038](../../../documents/1038/r1-wsl-amendment-application.md), [1039](../../../documents/1039/r1-windows-tools-installation-authority.md) e [round 2240](round.md). A publicação precedeu as execuções declaradas de 2003/2004 segundo os autores e suas fontes explícitas; publicação atual não retrodata execução de draft. Prosa de proposta dentro dos corpos antigos permanece histórica conforme 1028. Não houve nova publicação de corpo por este head.

Seleção operacional por autoridade, sem regra latest: 1008 r2, 1012 r2, 1013 r2, **1014 r3** e **1226 r2**; demais requisitos efetivos r1. Somente 1226 aceita WSL como Linux. Os outros oráculos e a exigência Windows de 1226 permanecem. Os predecessores 1226 r1/1014 r2 continuam preservados em published/partial implemented: o retirement nativo já foi recusado por exigir declaração Related à sucessora no corpo antigo. [Recusa existente](../../dispatch/r2/impact/amendment-status.json) mantida, sem repetir a mesma operação, editar corpo aprovado ou contornar o CLI. 1037 permanece decided. As novas revisões não herdam resultado.

## Aplicações antes e depois

O CLI alterou somente status/updated, preservando ID, revisão, corpo e demais metadados. [Comandos e respostas completos](analyst/assets/transitions.json), [entrada dos 31 alvos](analyst/assets/before-targets.json) e [conferência depois](analyst/assets/preservation.json).

| Alvo exato | Antes | Depois | Fonte de resultado |
|---|---|---|---|
| 1101 r1 | pass | pass | dev-review.md |
| 1102 r1 | pass | pass | dev-review.md |
| 1103 r1 | pass | pass | dev-review.md |
| 1104 r1 | pass | pass | dev-review.md |
| 1105 r1 | pass | pass | dev-review.md |
| 1106 r1 | pass | pass | dev-review.md |
| 1201 r1 | pass | pass | dev-review.md |
| 1202 r1 | pass | pass | dev-review.md |
| 1203 r1 | pass | pass | dev-review.md |
| 1204 r1 | pass | pass | dev-review.md |
| 1205 r1 | pass | pass | dev-review.md |
| 1206 r1 | pass | pass | dev-review.md |
| 1207 r1 | pass | pass | dev-review.md |
| 1211 r1 | pass | pass | dev-review.md |
| 1212 r1 | pass | pass | dev-review.md |
| 1213 r1 | pass | pass | dev-review.md |
| 1214 r1 | pass | pass | dev-review.md |
| 1227 r1 | fail | pass | dev-review.md |
| 1228 r1 | published | fail | dev-review.md |
| 1008 r2 | implemented | implemented | dev-review.md |
| 1012 r2 | implemented | implemented | dev-review.md |
| 1013 r2 | partial implemented | partial implemented | dev-review.md |
| 1014 r3 | published | partial implemented | dev-review.md |
| 2003 r1 | published | partial implemented | 2222-r1-qualified-windows-result.md |
| 2004 r1 | published | partial implemented | 2212-r1-final-result.md |

Todos os 19 resultados de requisito e as quatro declarações de spec pertencem ao **mesmo commit 57ef26901d4381ead16c7347483d588ad9d92efe**. A completude semântica é declarada pelo dev 2241; o analyst e o CLI não a reinventaram. O bloco fenced completo de 2241, incluindo newline final, mantém SHA256 `6c8ad7bef32e7baf2867b759db1efce382c827340b9dbd243365a00862698bf8`; [identidade](analyst/assets/review-block-identity.json). Os dez ajustes pt-BR da prosa já haviam sido feitos por nova instância do mesmo head autor, sem mudar resultado.

| Spec | Aplicabilidade completa declarada por 2241 | Resultados atuais | Estado |
|---|---|---|---|
| 1008 r2 | 1101..1106 r1 | seis pass | implemented |
| 1012 r2 | 1201..1207 r1 | sete pass | implemented |
| 1013 r2 | 1211..1217 r1 | quatro pass; três sem julgamento | partial implemented |
| 1014 r3 | 1221/1225/1227/1228 r1 e 1226 r2 | 1227 pass; 1228 fail; três sem julgamento | partial implemented |

1222..1224 permanecem obsolete, excluídos. Nenhuma contagem de teste, link ou tarefa completa substitui o conjunto de requisitos. Não atribuí implemented a specs incompletas.

## Resultados históricos e seis requisitos sem julgamento no 57

**1225 r1 conserva o header literal fail da execução ce5; isso é histórico, não um novo fail no 57.** 2241 omite 1225 das result rows atuais porque o oráculo integral ainda está incompleto. Não existe transição nativa de “unjudged” e eu não resetei para published nem atribuí pass. A consulta trace recupera esse fail ce5 com snapshot e applicability_unknown; é necessário ler o alvo e o report, não agregar os headers como resultados do 57. O inventário atual é 18 pass, um fail e seis sem julgamento integral, embora um destes seis tenha header histórico fail. 1227 muda fail ce5→pass 57 por julgamento novo explícito, sem apagar 2101/2102.

| Alvo sem resultado integral no 57 | Header preservado | Lacuna atribuída a 2241 |
|---|---|---|
| 1215 r1 | published | Protocolo completo de teclado nos dois desktops exigidos. |
| 1216 r1 | published | Windows/Ubuntu 24.04 ×100%/200%, cenário completo em 800×600. |
| 1217 r1 | published | Handler externo dos arquivos de licença não aberto pela aplicação; restante da ajuda offline observado em Linux. |
| 1221 r1 | published | Ubuntu 24.04/GCC 13 e condição sem SDK Qt fisicamente instalado. |
| 1225 r1 | fail histórico ce5 | Uso integral pelo caminho publicado em ambientes limpos; nova composição ZIP com F3. Não há novo resultado integral 57. |
| 1226 r2 | published | Parte Linux WSL aceita e observada; demonstração financeira/interação/capturas Windows ausentes. |

F1, launcher XDG, foi corrigido no conteúdo dos DEBs observados; F2, recuperação de links/licenças/evidências, foi corrigido e 1227 recebeu pass. F3 é o finding P2 novo de 2241: `dxcompiler.dll` e `dxil.dll` no ZIP não possuem licença/avisos específicos recuperáveis nos materiais entregues; **1228 r1 fail pelo AC2**. Não é uma conclusão jurídica geral. Não corrigi fontes, flags, pacote ou licenças e nenhum finding abriu outro ciclo.

Community 2022 17.14.43 está instalada e teve probe C++20 útil exit 0 segundo 2231 r3. O ZIP `c71634da99c2efe7774db55e011883b2c12f001db7a972404093f7c05968da4b` existe segundo 2222/2241. A abertura técnica CLI independente de 2241 observou processo/janela e Qt privado com PATH só Windows. Ela não é Computer Use nem demonstração manual/financeira de 1226. A falha inicial UAC, Build Tools anterior, install CRT OFF exit 1 e ausência de ZIP em 2221 continuam históricos; o novo complemento não reescreve esses fatos. Computer Use indisponível antes de JS permanece lacuna própria.

## Planos e ranges reais

| Plano exato | BASE..HEAD aplicado | Declaração autoral | Check interno atual |
|---|---|---|---|
| 2003 r1 | 4eb022d0e4a8e4f0c832c475e67ee0ac216fa9ed..57ef26901d4381ead16c7347483d588ad9d92efe | 2222 r1: procedure partial, D-1225/D-1227 complete | exit 0; cinco modifies cobertos; unexpected/dirty planned vazios |
| 2004 r1 | ce5db2e9d7489e0b6258b449358d620a0c390b1e..4eb022d0e4a8e4f0c832c475e67ee0ac216fa9ed | 2212 r1: procedure partial, D1227 complete, outras sete incomplete | exit 0; dois creates cobertos; unexpected/dirty planned vazios |

Usei 2222 como retorno posterior do mesmo autor/range de 2003; 2221 conserva a declaração partial histórica e as duas tarefas completas, sem substituição de corpo. 2004 não recebe tarefa completa a partir de observação posterior que seu autor não declarou. Os checks provam cobertura de arquivos/commits, não pass de requisitos ou procedimento integral. 2001/2002 e suas execuções/ranges antigos não foram reaplicados, completados ou reescritos. D1225 incomplete no plano de verificação e D-1225 complete na correção limitada são escopos distintos explicitados pelos autores.

## Três correções de metadados autorizadas

Recebi ownership somente destes campos nos três drafts liberados pelo syncer. [Diagnóstico anterior do root](environment-artifact-checks.json), [preimages integrais e hashes](analyst/assets/metadata-repairs.json) e checks depois: [r1](analyst/assets/metadata-check-2231r1.json), [r2](analyst/assets/metadata-check-2231r2.json), [r3](analyst/assets/metadata-check-2231r3.json), todos ok/exit 0 com links.

| Report | Antes | Depois | SHA256 do corpo antes=depois |
|---|---|---|---|
| 2231 r1 | report; sem tags/updated/use_when | document; tags mortgage/windows/installation; updated 2026-10-27; condição factual específica | b5d0dc1cd85f2929149a614fb7a6331592c56b33551a7d0e6117562f51f34499 |
| 2231 r2 | report; sem tags/updated/use_when | document; tags mortgage/windows/installation; updated 2026-10-27; condição factual específica | 1b56ca2117e398dc250bb62445fa4e9a2f5aa87610ac222c37e8159c3e190e4e |
| 2231 r3 | report; sem tags/updated/use_when | document; tags mortgage/windows/installation; updated 2026-10-27; condição factual específica | 4c44dcf48fd24e2f4d66a90e7526a399ca222986589a2f425a4b77a4ca5218b4 |

Cada `use_when` descreve seu fato: inventário Build Tools e limites históricos; tentativa Community cancelada; readback instalado/probe/CRT. ID/revisão/description/created/status draft e **todos os bytes do corpo inglês** foram preservados. Os preimages usam extensão `.md.preimage` para guardar bytes sem acrescentar artefatos antigos ao índice. O erro de schema documental não virou requisito ou falha de produto. Nenhum dos sete arquivos legados metadata-free recebeu campos inventados.

## Grafo, relações e trace

Seleção exata: `specs`, `requirements`, `plans`, `decisions`, `tools`, `knowledge`, `documents`, `evidence/test-execution`, `evidence/implementation-planning`, `evidence/synapses/r1`, `evidence/dispatch/r2` e `evidence/synapses/r2`, todas dentro desta sessão. [Seleção persistida](analyst/assets/corpus-selection.json). Não inclui outros projetos, provider/plugin ou campanha N×N.

A busca inicial retornou partial/index_incompatible. O rebuild separado já estava explicitamente autorizado; não tratei incompatible como stale com recuperação implícita. Depois dos três reparos e das aplicações, o [build geração 11](analyst/assets/graph-build.json) retornou ok: **119 nós, 1167 arestas (977 citation/190 related, nenhum parent)**. [Retrieval depois](analyst/assets/retrieval-after-build.json): index_state current, discovery/exact/obligations completos dentro do corpus, graph/body_context partial. [Lint](analyst/assets/graph-lint.json): ok com **250 unresolved_link e cinco overlapping_plan**, não zero lacunas.

As cinco sobreposições são Packaging.cmake e os quatro docs declarados por 2002/2003: retain, criação histórica versus correção posterior autorizada em range próprio; não são prova de conflito de escrita atual ou motivo para reescrever os planos. Os 250 links unresolved retêm endpoint/locator e restrição da seleção, incluindo fontes operacionais/históricas fora do índice; não foram apagados para zerar o lint. A geração final, incluindo este relatório, e suas contagens/fronteiras ficam em [final-scope-summary.json](analyst/assets/final-scope-summary.json) e [build final](analyst/assets/graph-build-final.json). Esses números finais podem crescer pelas citações deste próprio report; o baseline 11 acima é identificado separadamente.

[704 registros de aresta incidentes](analyst/assets/edge-dispositions.json) nos 31 alvos/sem resultado e nos dois predecessores foram preservados com endpoints, revisão, direção, significado e locator. Disposição retain: nenhum corpo ou identidade mudou; links antigos não foram rebaseados por recência. A sucessão nova permanece registrada nas fontes 1037/1038 e nos corpos sucessores; retirement continua inaplicado pelo diagnóstico nativo. Tags classificam, não criam relações. Não criei enum novo, parent ou ledger de manutenção paralelo.

Trace nativo: [2003](analyst/assets/trace-2003.json) recuperou duas rotas; [2004](analyst/assets/trace-2004.json), oito; [1225](analyst/assets/trace-1225.json), quatro históricas/atuais; zero findings, index current geração 11 e complete_within_declared_corpus. [Neighbors 1014 r3](analyst/assets/neighbors-1014-r3.json) retornou 37 arestas. Esses retornos conservam evidence_candidates/applicability_unknown quando falta seleção de implementação ativa: citação de report não prova resultado. [Join atribuído dos 25 requisitos](analyst/assets/requirement-plan-file-result.json) reusa a matriz de 2241 com snapshots e tarefas; não é nova verificação nem afirmação de que todo candidato foi julgado aplicável. Fontes antigas 2001/T1226 e 2002/I-1226 continuam r1; somente 2004/V1226 usa r2.

## Conhecimento e preservação

Reusei as disposições de 2102 para as 19 notas draft, conferindo **identidade integral atual com os hashes da leitura anterior do mesmo head**. Não alego releitura técnica nova das pesquisas. [Inventário exato](analyst/assets/candidate-dispositions.json). Reuso atribuído é permitido; criação/revisão/retirement/promoção ficam deferidos, sem novo candidato permanente solicitado. Reabrir exige autoridade para revisão/destino exatos e leitura/revisão atual se houver mudança proposta; notas Qt 6.8.3/6.8 continuam históricas, sem qualificação automática do pin 6.12.0.

| Candidato | Estado preservado | Disposição |
|---|---|---|
| 3101 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. |
| 3102 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. |
| 3103 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. |
| 3104 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. A seleção exata de 1025/1028 e os resultados ce5 não reescrevem a pesquisa nem validam todos os inputs/toolchains. |
| 3105 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. |
| 3121 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. A seleção exata de 1025/1028 e os resultados ce5 não reescrevem a pesquisa nem validam todos os inputs/toolchains. |
| 3122 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. Unidades Qt 6.8.3/6.8 permanecem históricas e não qualificam automaticamente Qt 6.12.0. |
| 3123 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. Unidades Qt 6.8.3/6.8 permanecem históricas e não qualificam automaticamente Qt 6.12.0. |
| 3124 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. Unidades Qt 6.8.3/6.8 permanecem históricas e não qualificam automaticamente Qt 6.12.0. |
| 3125 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. A seleção exata de 1025/1028 e os resultados ce5 não reescrevem a pesquisa nem validam todos os inputs/toolchains. |
| 3126 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. A seleção exata de 1025/1028 e os resultados ce5 não reescrevem a pesquisa nem validam todos os inputs/toolchains. |
| 3141 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. Unidades Qt 6.8.3/6.8 permanecem históricas e não qualificam automaticamente Qt 6.12.0. |
| 3142 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. Unidades Qt 6.8.3/6.8 permanecem históricas e não qualificam automaticamente Qt 6.12.0. |
| 3143 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. Unidades Qt 6.8.3/6.8 permanecem históricas e não qualificam automaticamente Qt 6.12.0. |
| 3144 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. |
| 3145 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. Unidades Qt 6.8.3/6.8 permanecem históricas e não qualificam automaticamente Qt 6.12.0. |
| 3146 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. |
| 3147 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. Unidades Qt 6.8.3/6.8 permanecem históricas e não qualificam automaticamente Qt 6.12.0. |
| 3148 r1 | draft | Reuso como fonte draft atribuído; sem autoridade de promoção/publicação. Unidades Qt 6.8.3/6.8 permanecem históricas e não qualificam automaticamente Qt 6.12.0. |

[Preservação](analyst/assets/preservation.json) confrontou os 43 corpos do snapshot aprovado anterior mais os quatro inputs atuais 1226 r2/1014 r3/2003/2004: **47/47 iguais**. Conferiu os **55/55 paths atuais** contra hashes de entrada do reviewer e blobs Git do 57, com zero dirty selecionado. Isso inclui os dois scripts novos de regressão e preserva os 22 assets anteriores. Não foi criado commit artificial, staging ou limpeza; README raiz e dirty/untracked de outros owners permanecem alheios à minha escrita. Fontes aprovadas locais não são alegadas como conteúdo Git do 57.

## Leitura, limites e handoff

[Manifesto próprio](analyst/assets/source-read-manifest.json) registra fontes/revisões/hashes e seções. Li os 31 alvos exatos, autoridades/round, oito reports recebidos, memória própria e continuação/pending das quatro memórias atribuídas (implementação r14, testes r9, independente r6, ambiente r9), cards e contratos aplicáveis. Reusei leitura anterior das KNW por identidade. Inspeção de hashes, evidência transportada, grafos e ranges é mecânica; não reli todos os logs/XML/binários, Qt/Boost, todo Brain ou código de produto. Nenhuma pesquisa externa, instalação, recálculo financeiro, suíte técnica ou julgamento jurídico/científico novo.

Dois erros de observador ocorreram antes dos efeitos respectivos: serialização JSON de data YAML exigiu `default=str`; comparação inicial usou apenas payload do bloco em vez de fence+newline. Foram corrigidos nos coletores, registrando o formato real; nenhum corpo, resultado ou comando de status foi contornado. Os checks nativos efetivos tiveram sucesso. Não houve tentativa adicional de retirement já recusado.

**Próximo responsável: syncer de preservação local**, após este retorno completo. Recebe o corte 57 e este relatório 2251 r1, memória própria r3, 25 aplicações, três reparos draft e evidência de preservação; deve conferir o estado real e os limites locais. DVC não está configurado segundo a rodada; sem autorização de push/PR/CI/merge/release/promoção ou aceitação de produto/sessão. Não inferir entrega remota a partir destes arquivos locais.

Propostas ao orquestrador, sem editar seu state/memory/round: registrar analyst returned e fontes, cinco mudanças literais/20 reafirmações, resultado atual 18 pass/1228 fail/seis sem julgamento, header 1225 histórico, retirement inaplicado, cache scoped com fronteiras e liberação do syncer. Manter fase 6/sessão aberta. F3 e novas ações materiais, protocolos Windows, matriz Ubuntu 24/escalas/máquinas limpas e condições de distribuição permanecem com root/humano sob autoridade própria; nenhum ciclo novo decorre deste relatório. As evidências estão localmente preservadas, sem alegação de publicação ou encerramento.
