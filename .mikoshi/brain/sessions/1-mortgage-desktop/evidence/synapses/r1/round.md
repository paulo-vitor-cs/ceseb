---
id: 2100
revision: 1
type: document
tags: [mortgage, synapses, review-cut]
status: draft
created: '2026-10-26'
updated: '2026-10-27'
description: Recorte local da primeira rodada Synapses após execução parcial dos planos aprovados.
use_when:
- Recuperar o alvo exato, relatórios obrigatórios, autoridade e limites da rodada.
---
# Synapses — rodada 1

Autoridade: [1034](../../../documents/1034/r1-engineering-execution-approval.md) e [1035](../../../documents/1035/r1-wsl-execution-direction.md). Execução parcial de fase 5 devolvida pelos dois autores; inicia fase 6, sem autorização adicional para produto, promoção ou operação remota.

ROOT /home/paulo/ceseb; sessão explícita 1-mortgage-desktop; ramo local codex/mortgage-desktop. Snapshot revisado: ce5db2e9d7489e0b6258b449358d620a0c390b1e. Produto congelado: 76b9fe2ff8b6a034c9880daa315a7875f3d9bcdf. Binário/stage/DEB auxiliar: 2b16879dfe1eb6ec55ea8d9310b2ae575cb1c7cf. Preservar essas identidades distintas.

Corpus: quatro specs r2 atuais, 25 requisitos r1 ativos, planos 2001/2002 r1, decisões e tools vigentes, autoridade humana e 19 notas de pesquisa atribuídas; fontes e testes no snapshot, documentos e evidências da sessão. O inventário aprovado está em [snapshot](../../engineering-approved-inputs-snapshot.json), com [43 corpos preservados](../../execution-input-body-preservation.json). Histórico permanece preservado; isso não é revisão global de outros projetos.

Recebidos integralmente: [fase A 2011](../../test-execution/2001/r1-base-result.md), [fase B 2012](../../test-execution/2001/r1-final-result.md), [produto 2021](../../implementation-planning/execution.md) e relatórios do syncer de ferramentas locais em evidence/environment/local-build-tools. A diferença dos cinco assets finais corrige somente preparo de ativação; oráculos permanecem, assim como a falha original XCB. O range completo de testes inclui 31 paths de produto com disposição explícita; não é range exclusivo de assets.

Relatório requerido: dev independente 2101, separado dos dois autores. Revisão inclui suíte aplicável, obrigações determinísticas, escopo de segurança e dependências/licenças. Não há hipótese científica que exija julgamento de especialista nesta rodada. Após retorno completo, um analyst 2102 aplica os veredictos sem repetir verificação. Depois um syncer 2103 confere preservação local autorizada. A autoria de produto e testes está congelada; achados não iniciam correção automática.

Telemetria mecânica opcional: [consulta com caminho explícito](../../synapses-telemetry-series-path.json) retornou ok com series vazio. A primeira consulta com seletor curto foi invalid e está preservada em evidence/synapses-telemetry-series.json. Não há contadores medidos ou inferência de custo; não se abre etapa de auditoria.

Gaps de entrada: Windows/MSVC e Ubuntu 24/GCC 13, smoke limpo e CRT Windows sem execução. WSL 26/GCC 15 é o ambiente observado. Computer Use/Sky indisponível antes de binding; captura inicial observada por X11 apenas. Ausência de ambiente não é fail de comportamento.

Marco antes da reconciliação: dev independente [2101](dev-review.md) retornou integralmente: 17 pass, 2 fail (1225/1227), 6 sem resultado. Suite própria 26/26 offscreen/XCB e 21/21 core; novo DEB ce5 reproduziu dois defeitos. 23 declarações validadas e check de links ok. Analyst iniciado após todos os retornos obrigatórios; aplicação de estados pendente naquele momento. Promoção de notas, push, PR, merge, CI remoto, release e fechamento de sessão não autorizados por este recorte.

Analyst [2102](analyst.md) retornou: 25 transições aplicadas pelo CLI, 43 corpos preservados; 17 pass, 2 fail, 6 published; specs numéricas implemented, interface/entrega e planos partial implemented. 19 notas draft. Índice scoped geração 7 com 101 nós/1.003 arestas e 162 fronteiras, sem alegação de cobertura global sem lacunas. Syncer de conferência local liberado após este retorno; sem operações remotas autorizadas.

## Resultado final e parada

O [syncer 2103](syncer.md) retornou integralmente em 27 de outubro. Conferiu 53 paths commitados e limpos, 43 corpos aprovados preservados e os estados aplicados por [2102](analyst.md). Foram observados 17 pass, 2 fail e 6 requisitos sem resultado; duas specs numéricas implemented, duas specs e ambos os planos partial implemented. Os dois P2 confirmados em [2101](dev-review.md) permanecem sem reparo nesta rodada.

O repositório pessoal público está confirmado. O remoto contém somente main em 0bbd2854703444a27ce04600f5e227e0351f61bc; nove commits posteriores até ce5db2e9d7489e0b6258b449358d620a0c390b1e permanecem locais. As fontes documentais aprovadas, metadados atuais e relatórios estão no filesystem, fora desses commits. DVC não está configurado no projeto selecionado, portanto N/A. Não houve push, CI remoto, PR, merge, release ou promoção.

O refresh final da mesma seleção, após este texto e 2103, está registrado em `final-graph-build.json`, com lint em `final-graph-lint.json` e conferência estrutural em `root-final-checks.json`. Compatibilidade/current do índice não elimina fronteiras fora da seleção, nem prova execução de produto.

A rodada termina na fase 7. A sessão permanece aberta. Próximos recortes possíveis exigem direção humana: corrigir o lançador e os links instalados, concluir protocolos nativos ou selecionar publicação. Não se inicia outro ciclo a partir destes achados.
