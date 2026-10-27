---
id: 1033
revision: 1
type: document
tags:
- mortgage
- plan-review
- coverage
- execution-gate
status: versioned
created: '2026-10-26'
updated: '2026-10-26'
description: Conjunto concreto dos planos de testes e implementação com cobertura dos 25 requisitos,
  sequência, efeitos e pré-requisitos nativos.
use_when:
- Revisar e aprovar os planos 2001 e 2002 e sua receita de dependências antes da execução.
---
# Planos concretos para revisão

Fase 5 — preparação concluída, antes da execução. O [aceite 1028](../1028/r1-revisions-approval-and-planning-authority.md) aprovou as revisões de design e autorizou esta autoria. As quatro specs r2 e os 25 requisitos estão **published**; as decisões técnicas aceitas estão decided, os seis cartões r1 mandatory e as quatro specs r1 superseded. Os corpos aprovados ficaram preservados. A [reconciliação de status](../../evidence/planning-approval-status-reconciliation.json) registra a correção da etapa inicialmente omitida e suas 44 checagens; isso não é teste do produto.

## Conjunto apresentado

| Artefato | Autor / executor previsto | Escopo | Estado |
|---|---|---|---|
| [2001 r1 — testes](../../plans/2001/r1-requirement-test-plan.md) | dev-test-planning | 25 tarefas, 25 requisitos, 22 arquivos novos; sete tarefas sem alteração de fonte | draft |
| [2002 r1 — implementação](../../plans/2002/r1-product-implementation-plan.md) | dev-implementation-planning | 25 tarefas, 25 requisitos, 31 arquivos novos; uma tarefa sem alteração de fonte | draft |
| [1030 r1 — interfaces e fixtures](../1030/r1-test-interface-and-fixtures.md) | dev testes, combinado com dev implementação e integrado pelo orquestrador | API pública, alvos, objectNames, ownership e oráculos independentes | draft |
| [2306 r2 — aquisição e deploy](../../tools/2306/r2-qt-dependency-acquisition-and-deployment.md) | orquestrador, a partir das fontes e necessidades dos planos | Receita CMake/lockfile, arquivos oficiais verificados e deploy | draft |
| [1032 r1 — arranjo](../../decisions/1032/r1-engineering-execution-arrangement.md) | proposta do orquestrador com os autores | Sequência, ranges Git, snapshots nativos e efeitos | open |

O [retorno 1031](../1031/r1-implementation-planning-return.md) conserva a autoria de implementação. As evidências dos dois autores são snapshots anteriores à integração final de caminhos/ambientes; a [conferência integrada](../../evidence/planning-integration-checks.json) identifica os corpos atuais. Não houve revisão independente de produto.

## Sequência e pré-requisitos

1. Após aprovação concreta, o autor de testes cria os assets, captura BASE real e tenta executar no base antes de produto. Ausência de código, CMake, target ou dependência é **indisponibilidade**, sem RED fictício. Entrega arquivos, diagnóstico e TEST_ASSETS_HEAD real.
2. O autor de implementação parte desse retorno, escreve as fontes e o suporte, prepara dependências autorizadas e usa os testes originais. Os métodos de construção têm uma ordem de composição; a verificação integrada ocorre depois de existirem as fontes necessárias, sem exigir um verdict positivo de infraestrutura antes de criar os próprios arquivos que ela compila.
3. Um commit real revisado é exportado com manifesto/hash para os alvos nativos. Ubuntu 24.04 usa `/tmp/ceseb-native-1/source`, com build/deps/out nas árvores irmãs; Windows usa `C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/source`, igualmente com outputs fora de source. Autoria, Git e commit checks continuam no ROOT `/home/paulo/ceseb`.
4. O autor de testes conclui os mesmos casos e as demonstrações/inspeções sobre o pacote e snapshot reais. O range dos assets de 2001 é separado do snapshot runtime da implementação; não se inclui produto no commit check de testes por engano. Resultados são retornados fora dos corpos dos planos.
5. Após execução, inclusive parcial/falha, o fluxo entra em Synapses para revisão independente e reconciliação. Plano implemented, requisito pass e publicação remota continuam fatos distintos.

A [observação de ambiente](../../evidence/planning-environment-observation.json) confirma ROOT Ubuntu **26.04/WSL**, CMake/Ninja/GCC 13 ausentes no PATH inspecionado, e host Windows **11 Pro**, versão 10.0.26200. Isso não comprova MSVC/Qt instalados nem uma máquina limpa de aceitação. Ubuntu 24.04/GCC 13, MSVC 2022/v143, CMake/Ninja e desktops limpos autorizados são pré-requisitos explícitos. Sua ausência conserva a parte dependente como não executada; não se provisiona VM, compra licença ou instala ferramentas globalmente por inferência. WSL/Server CI/offscreen não substituem os desktops requeridos.

A aquisição usa Boost 1.86.0, GoogleTest 1.17.0 e Qt 6.12.0 oficial com pins/digests recuperados de fontes primárias. SDK mínimo: QtBase Windows; QtBase+ICU Linux. A leitura da tag confirmou windeployqt em QtBase; QtTools não foi selecionado. Transferência verifica TLS e SHA256 esperado antes da extração, sem credenciais de CI. Os pins e checksums foram lidos; nenhum payload foi baixado ou qualificado.

## Cobertura requisito → tarefa

Cada tarefa tem exatamente um Requirement r1, Kind, Method e tabela Files com operações exatas. Tarefas sem alteração de fonte têm tabela vazia justificada e não exigem commit artificial. Os arquivos de testes e de produto são disjuntos; ROOT README e outras alterações preexistentes ficam preservados. A documentação do produto ganha sua própria entrada `docs/README.md`.

| Requisito publicado | Plano 2001 | Plano 2002 |
|---|---|---|
| [1101 r1](../../requirements/1101/r1-explicit-rate-kind.md) | T1101 | I-1101 |
| [1102 r1](../../requirements/1102/r1-nominal-monthly.md) | T1102 | I-1102 |
| [1103 r1](../../requirements/1103/r1-effective-monthly.md) | T1103 | I-1103 |
| [1104 r1](../../requirements/1104/r1-annual-equivalents.md) | T1104 | I-1104 |
| [1105 r1](../../requirements/1105/r1-invalid-rate-input.md) | T1105 | I-1105 |
| [1106 r1](../../requirements/1106/r1-unrounded-consumer-rate.md) | T1106 | I-1106 |
| [1201 r1](../../requirements/1201/r1-loan-domain.md) | T1201 | I-1201 |
| [1202 r1](../../requirements/1202/r1-price-ledger.md) | T1202 | I-1202 |
| [1203 r1](../../requirements/1203/r1-sac-ledger.md) | T1203 | I-1203 |
| [1204 r1](../../requirements/1204/r1-money-invariants.md) | T1204 | I-1204 |
| [1205 r1](../../requirements/1205/r1-zero-and-single-period.md) | T1205 | I-1205 |
| [1206 r1](../../requirements/1206/r1-cent-precision-errors.md) | T1206 | I-1206 |
| [1207 r1](../../requirements/1207/r1-comparable-results.md) | T1207 | I-1207 |
| [1211 r1](../../requirements/1211/r1-localized-input.md) | T1211 | I-1211 |
| [1212 r1](../../requirements/1212/r1-rate-presentation.md) | T1212 | I-1212 |
| [1213 r1](../../requirements/1213/r1-comparison-presentation.md) | T1213 | I-1213 |
| [1214 r1](../../requirements/1214/r1-ui-state-recovery.md) | T1214 | I-1214 |
| [1215 r1](../../requirements/1215/r1-keyboard-navigation.md) | T1215 | I-1215 |
| [1216 r1](../../requirements/1216/r1-resize-access.md) | T1216 | I-1216 |
| [1217 r1](../../requirements/1217/r1-model-help.md) | T1217 | I-1217 |
| [1221 r1](../../requirements/1221/r1-build-contract.md) | T1221 | I-1221 |
| [1225 r1](../../requirements/1225/r1-runtime-packages.md) | T1225 | I-1225 |
| [1226 r1](../../requirements/1226/r1-native-smoke.md) | T1226 | I-1226 |
| [1227 r1](../../requirements/1227/r1-technical-documentation.md) | T1227 | I-1227 |
| [1228 r1](../../requirements/1228/r1-distribution-notices.md) | T1228 | I-1228 |

## Efeitos propostos e autoridade

A aprovação solicitada recai sobre os dois corpos de plano e os três inputs concretos do conjunto acima. Permite a execução dos arquivos/métodos listados, obtenção local das dependências públicas fixadas, builds, snapshots, staging, pacotes, procedimentos de teste nos ambientes já designados e commits locais por pathspec exato. A instalação do DEB de teste exige o ambiente limpo e o privilégio efetivamente autorizado; a falta desses inputs retorna lacuna. Não inclui criação de conta, compra, provisão de máquina, alteração global não declarada, push/PR/merge/release ou disparo de CI remoto. Criar o workflow como fonte não o executa.

No aceite, aplicar imediatamente os estados pelos tipos e preservar corpos: planos 2001/2002 publicados; documentos do conjunto versioned; decisão 1032 decided; cartão 2306 r2 mandatory sob seus gatilhos e r1 superseded. Isso será registrado com a resposta humana exata. Não antecipar esses estados agora.

## Conferência e limites

A conferência integrada cobre template dos planos, uma referência de requisito por tarefa, união e ownership dos arquivos, correspondência dos 25 requisitos nos dois planos, metadados/links, trace declarado e preservação de 40 inputs aprovados. O inventário de [arestas](../../evidence/planning-edge-dispositions.json) identifica os novos consumidores e mantém as relações históricas. Limites do corpus/provider ficam registrados, sem alegar cobertura semântica universal.

| Dimensão | Resultado desta preparação |
|---|---|
| Design | Aceito, status reconciliados |
| Planos | Dois drafts completos para aprovação |
| Execução / commit coverage | Não iniciada; nenhum BASE/HEAD futuro inventado |
| Testes, benchmark e pacotes | Não executados |
| Revisão independente / Synapses | Não iniciada |
| Requisitos | Published; nenhum pass/fail de produto atribuído |

Os próximos responsáveis são o humano para a decisão sobre este conjunto concreto e, depois do aceite, os autores previstos para a execução. A preparação termina neste gate; não inicia execução por silêncio.
