---
id: 1018
revision: 1
type: decision
tags:
- mortgage
- requirement-refinement
- artifact-conformance
status: open
created: '2026-10-26'
updated: '2026-10-26'
description: Correção dos requisitos rejeitados, classificação por nível e separação
  das prescrições de ferramentas sem mudar a arquitetura aprovada.
use_when:
- Reconciliar requisitos efetivos, ferramentas de verificação e referências históricas
  após a correção metodológica solicitada.
---
# Correção metodológica dos requisitos

Autor: specialist-requirement-refinement. Fonte de autoridade: [correção humana 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). O humano aprovou a arquitetura e rejeitou a qualidade dos requisitos. Esta decisão registra a correção antes das edições. O estado inicial é open; não afirma uma nova aprovação humana de cada corpo corrigido.

## Escolha e limite

Corrigir os requisitos de produto ainda não aceitos na revisão 1, conforme o template vigente. Preservar os corpos aprovados das specs 1008, 1012, 1013 e 1014 r1 e as decisões de design aceitas. Os requisitos anteriores foram preservados integralmente em `evidence/requirements-refinement-preimages.json` pelo orquestrador. Não há planos anteriores a alterar.

Alternativas consideradas: apenas acrescentar títulos; reescrever a arquitetura; ou corrigir corpo, classificação e fronteira requisito/ferramenta. Foi selecionada a terceira, porque atende a correção explícita sem mudar comportamento ou esconder a falha anterior. Acrescentar títulos, isoladamente, não satisfaz a correção.

## Critérios de autoria

Cada requisito efetivo mantém as seções Requirement, Origin and Boundary, Verification e Trace. A origem inclui Rationale específico; a verificação inclui Acceptance Criteria numerados, método, entrada/alvo, procedimento, oráculo e limites. Uma linha de classificação visível corresponde às tags de nível e método. Unidade trata um módulo isolado; integração trata contratos entre componentes; sistema trata o aplicativo ou entregável completo. Nível não é alegação de resultado de teste.

A correção mantém os modelos matemáticos, tolerâncias e vetores aprovados no design. Nenhuma obrigação escolhe executor de testes, sistema de build, CI ou biblioteca como se fosse comportamento de produto. Os planos futuros escolhem as operações documentadas nos cartões de ferramentas.

## Disposição dos requisitos de método

| Fonte r1 | Disposição | Meio preservado em tool draft | Obrigações reais preservadas |
|---|---|---|---|
| [1222](../../requirements/1222/r1-core-test-suite.md) | obsolete; corpo histórico intacto | [2302: execução de testes do núcleo](../../tools/2302/r1-googletest-runner.md) | [1101](../../requirements/1101/r1-explicit-rate-kind.md) a 1106 e [1201](../../requirements/1201/r1-loan-domain.md) a 1207 continuam os oráculos do núcleo |
| [1223](../../requirements/1223/r1-gui-test-suite.md) | obsolete; corpo histórico intacto | [2303: execução de testes da interface](../../tools/2303/r1-qttest-runner.md) | [1211](../../requirements/1211/r1-localized-input.md) a 1217 preservam a entrada, apresentação e uso da interface |
| [1224](../../requirements/1224/r1-ci-evidence.md) | obsolete; corpo histórico intacto | [2304: automação de integração](../../tools/2304/r1-github-actions.md) | [1225](../../requirements/1225/r1-runtime-packages.md), [1226](../../requirements/1226/r1-native-smoke.md) e [1227](../../requirements/1227/r1-technical-documentation.md) preservam pacote utilizável, operação nas plataformas e relatório com evidência |

O requisito 1221 conserva a independência e portabilidade do núcleo financeiro, uma fronteira arquitetural observável. A seleção do sistema de build e dos compiladores passa aos cartões 2301/2305. Os requisitos 1225 a 1228 conservam propriedades dos entregáveis; não obrigam o uso de uma ferramenta para produzi-los.

## Relações e fontes preservadas

As referências já declaradas de requisitos efetivos para specs, necessidade e decisões de origem são retidas. As referências das specs aprovadas para 1222/1223/1224 são retidas como históricas; esses três nós não integram a cobertura efetiva. As ligações não são apagadas nem silenciosamente apontadas a uma revisão nova. O [índice 1015 r2](../../documents/1015/r2-refined-requirement-index.md) declara a cobertura corrigida e as substituições de método, enquanto o [1015 r1](../../documents/1015/r1-concrete-design-index.md) permanece preservado.

As novas referências a esta decisão e à fonte 1017 são adicionadas para explicar a correção. Não há mudança dos corpos aceitos das specs nem alegação de supersessão automática do índice anterior. O relatório 1019 conserva a enumeração nativa de cada declaração de relação incidente, com fonte, linha, destino, significado e disposição. O grafo mecânico está indisponível nesta seleção; essa enumeração textual não é uma observação de grafo.

## Autoridade e evidência

O trabalho permanece na fase 4. Não há novo gate de arquitetura, plano, código, instalação, execução de testes de produto, publicação ou Synapses nesta correção. Consulta lexical encontrou as fontes, mas retornou index_incompatible; as fontes pertinentes foram abertas diretamente. As consultas primárias e a aritmética anteriores não são reclassificadas retrospectivamente como pesquisa completa.
