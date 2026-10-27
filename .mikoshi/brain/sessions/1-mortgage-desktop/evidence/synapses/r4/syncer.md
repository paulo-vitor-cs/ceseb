---
id: 2461
revision: 1
type: document
tags: [mortgage, synapses, publication, preservation]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Primeiro commit e push das correções F3/F4 e dos resultados reconciliados, com confirmação direta do remoto e preservação do código testado.
use_when:
- Recuperar a publicação efetiva da correção F3/F4 e distinguir este recibo posterior do snapshot publicado.
---
# Publicação das correções F3/F4

**Commit e push concluídos em `183fabed75334f8d51412a72c77914ada02c531b`**, com leitura direta do mesmo SHA na branch [codex/mortgage-desktop](https://github.com/paulo-vitor-cs/ceseb/tree/codex/mortgage-desktop). O repositório pessoal `paulo-vitor-cs/ceseb` foi observado como PUBLIC. O código testado permanece **3f4dc69ec84230b4035572fc62af3d13db451d2a**; o novo commit é documental, filho direto desse código, e publica também seus três commits anteriores de testes e produto.

## Autoridade e identidade

ROOT/MAIN `/home/paulo/ceseb`, sessão `1-mortgage-desktop`, flow `design-project-1`, mesmo head `preservation-syncer`, instância fresca `/root/f3_f4_final_publication`, memória de entrada r5. Papel syncer r8 lido manualmente; native_id e carregamento nativo não observáveis. Handle não comprova identidade nativa.

[1040](../../../documents/1040/r1-alternative-validation-and-branch-push.md) ordena o push; [1041](../../../documents/1041/r1-f3-f4-correction-authority.md) autoriza a correção atual e preserva essa publicação; [1042](../../../documents/1042/r1-f3-f4-concrete-procedure-release.md) registra os procedimentos liberados. A reconciliação [2451](analyst.md) foi recebida integralmente antes da publicação: 25 requisitos pass, quatro specs implemented e planos 2005/2006 implemented. Os resultados técnicos de [2441](dev-review.md) continuam atribuídos ao revisor e ao código identificado. Não executei testes ou novo julgamento técnico.

O preflight observou branch correta, HEAD 3f4, remoto b5bb61c e índice vazio. Git 2.53.0, remoto SSH `git@github.com:paulo-vitor-cs/ceseb.git`; credenciais existentes foram reutilizadas sem leitura ou alteração de segredos. DVC não está configurado e não há pointers DVC rastreados neste projeto: N/A. Nenhuma operação de PR, merge, tag, release, instalação ou CI manual foi executada.

## Recorte e operações observadas

A seleção explícita preparada pelo root continha **216 paths**, dos quais **56 alterados** entraram neste commit. Inclui corpos e headers reconciliados, planos 2005/2006, autoridades e retornos r4, README e cópias originais de evidência Windows/Linux. Os sete nomes históricos de out/review-wsl foram tratados somente pelos seus paths exatos; nenhuma árvore out, cache, instalador, vendor bruto, coordenação ou memória de head foi adicionada em bloco.

[Staging e seleção](syncer/staged-selection.json), [commit](syncer/commit-result.json), [push](syncer/push-result.json) e [readback direto](syncer/remote-readback.json) registram as operações reais. O push retornou exit 0 e atualizou a branch de b5bb61c para 183fabed75334f8d51412a72c77914ada02c531b. Os 216 pares fonte/índice foram comparados antes do commit e os mesmos bytes foram conferidos no commit. Não houve path staged fora da seleção.

A pós-conferência [preservação](syncer/post-publication.json) confirmou **49 corpos aprovados, 57 paths atuais iguais ao código 3f4, 38 arquivos históricos e 19 notas draft preservados**. O índice ficou vazio; dirty/untracked fora da seleção permaneceram intocados. As comparações reutilizam os valores de preservação existentes do analyst e os identificadores nativos Git, sem novo ledger de hashes. Commits documentais não são apresentados como novas execuções do aplicativo.

Duas observações de preparo foram preservadas em [preparação](syncer/preparation-observations.json): um guard inicial excluía por engano evidências históricas de syncer já presentes na seleção e parou antes de staging; depois git add retornou 1 pelo diretório out ignorado, deixando 56 paths selecionados no índice. Antes de continuar, confirmei HEAD inalterado e staging contido na seleção, preservei esse índice e usei git add -f somente nos sete nomes históricos autorizados. A conferência dos 216 pares então passou antes do commit. Não houve rollback, limpeza, alteração de fonte ou repetição cega de push.

## Leitura e continuação delimitada

Li a memória própria r5, autoridades 1040/1041/1042 integrais, 2451 integral, corte/resultado/limites materiais de 2441, o manifesto exato, os registros existentes de preservação e os bytes selecionados para comparação. Li skill sync, role syncer, publicação, logical-head-memory e cards Git/DVC/GitHub/retrieval/head-memory/check aplicáveis. A busca dirigida retornou lexical parcial e index_incompatible; não fiz rebuild concorrente. A descoberta por arquivos exatos sustentou esta publicação. Não reli tecnicamente todo Brain ou todos os outputs de teste.

**Este relatório foi escrito depois do primeiro push e está fora do commit que descreve.** A tarefa recebida inclui um segundo recorte documental explícito para publicar este relatório, recibos selecionados e o encerramento da rodada. O root deve ler este relatório completo e liberar essa lista exata antes do segundo efeito. Até lá, esta instância continua com a tarefa inacabada; não há retorno final nem encerramento da sessão. O recibo nativo do segundo push ficará separado do seu próprio snapshot, sem terceiro commit automático.
