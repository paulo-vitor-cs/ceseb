---
id: 1015
revision: 2
type: document
tags:
- mortgage
- design-index
- requirement-refinement
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Índice de cobertura efetiva após o refinamento dos requisitos, preservando
  o design aprovado e separando ferramentas de obrigações de produto.
use_when:
- Consultar os requisitos efetivos e os cartões de ferramentas que orientarão os planos
  após a correção metodológica.
---
# Requisitos refinados do design aprovado

Fase atual: **4 — arquitetura e refinamento de requisitos**. O humano aprovou o design e rejeitou a qualidade dos requisitos, conforme [1017 r1](../1017/r1-design-approval-and-quality-correction.md). Esta revisão do índice organiza a correção; não solicita novamente o aceite da arquitetura, não aprova planos futuros e não atribui resultado de produto.

## Baseline arquitetural preservada

| Funcionalidade | Spec aprovada, corpo preservado | Requisitos efetivos r1 |
|---|---|---|
| Convenções e conversão de taxa | [1008 r1](../../specs/1008/r1-annual-rate-conversion.md) | 1101 a 1106 |
| Comparação monetária Price/SAC | [1012 r1](../../specs/1012/r1-amortization-comparison.md) | 1201 a 1207 |
| Interface e estados do aplicativo | [1013 r1](../../specs/1013/r1-widgets-interface.md) | 1211 a 1217 |
| Independência e entrega do produto | [1014 r1](../../specs/1014/r1-reproducible-delivery.md) | 1221 e 1225 a 1228 |

Os corpos das quatro specs não foram editados. Seus trechos de autoria ainda descrevem o momento em que eram propostas; a autoridade atual de aceite está em 1017. Os links de 1014 r1 para os antigos requisitos de método permanecem como histórico, não como cobertura efetiva.

## Cobertura efetiva

São **25 requisitos de produto em draft**: 11 de unidade, 6 de integração e 8 de sistema. Unidade trata um módulo isolado; integração trata interfaces entre componentes; sistema trata a aplicação ou um entregável completo. Cada requisito contém os níveis e métodos nas tags e no corpo, obrigação observável, origem, rationale, acceptance criteria, procedimento, oráculo, limites e trace. O relatório de autoria conserva o checklist de cada item.

| Requisito | Obrigação | Nível |
|---|---|---|
| [1101 r1](../../requirements/1101/r1-explicit-rate-kind.md) | Convenção explícita da taxa anual | Unidade |
| [1102 r1](../../requirements/1102/r1-nominal-monthly.md) | Conversão nominal anual para efetiva mensal | Unidade |
| [1103 r1](../../requirements/1103/r1-effective-monthly.md) | Conversão efetiva anual para efetiva mensal | Unidade |
| [1104 r1](../../requirements/1104/r1-annual-equivalents.md) | Equivalentes anuais da taxa normalizada | Unidade |
| [1105 r1](../../requirements/1105/r1-invalid-rate-input.md) | Rejeição de percentual anual inválido | Unidade |
| [1106 r1](../../requirements/1106/r1-unrounded-consumer-rate.md) | Preservação da taxa entre normalização e cálculo | Integração |
| [1201 r1](../../requirements/1201/r1-loan-domain.md) | Validação do domínio do financiamento | Unidade |
| [1202 r1](../../requirements/1202/r1-price-ledger.md) | Pagamentos Price em centavos | Unidade |
| [1203 r1](../../requirements/1203/r1-sac-ledger.md) | Amortização SAC com distribuição do resto | Unidade |
| [1204 r1](../../requirements/1204/r1-money-invariants.md) | Conservação dos saldos e totais | Unidade |
| [1205 r1](../../requirements/1205/r1-zero-and-single-period.md) | Cálculo nos casos de juros zero e prazo único | Unidade |
| [1206 r1](../../requirements/1206/r1-cent-precision-errors.md) | Rejeição de combinações inviáveis em centavos | Unidade |
| [1207 r1](../../requirements/1207/r1-comparable-results.md) | Comparação sob as mesmas condições financeiras | Integração |
| [1211 r1](../../requirements/1211/r1-localized-input.md) | Interpretação dos campos em pt-BR | Integração |
| [1212 r1](../../requirements/1212/r1-rate-presentation.md) | Apresentação das taxas com tipo e período | Integração |
| [1213 r1](../../requirements/1213/r1-comparison-presentation.md) | Apresentação da comparação e do prazo efetivo | Sistema |
| [1214 r1](../../requirements/1214/r1-ui-state-recovery.md) | Coerência entre edição, validação e resultados | Integração |
| [1215 r1](../../requirements/1215/r1-keyboard-navigation.md) | Operação por teclado | Sistema |
| [1216 r1](../../requirements/1216/r1-resize-access.md) | Acesso ao conteúdo com redimensionamento | Sistema |
| [1217 r1](../../requirements/1217/r1-model-help.md) | Ajuda local sobre o modelo | Sistema |
| [1221 r1](../../requirements/1221/r1-build-contract.md) | Independência do núcleo financeiro | Integração |
| [1225 r1](../../requirements/1225/r1-runtime-packages.md) | Pacotes utilizáveis pelo usuário final | Sistema |
| [1226 r1](../../requirements/1226/r1-native-smoke.md) | Operação completa nas duas plataformas | Sistema |
| [1227 r1](../../requirements/1227/r1-technical-documentation.md) | Documentação de uso e relatório técnico | Sistema |
| [1228 r1](../../requirements/1228/r1-distribution-notices.md) | Avisos e licenças dos materiais distribuídos | Sistema |

## Prescrições de ferramentas retiradas da cobertura de produto

| Requisito histórico r1 | Estado | Cartão de operação | Consumidor futuro |
|---|---|---|---|
| [1222](../../requirements/1222/r1-core-test-suite.md) | obsolete; corpo intacto | [2302: executor de testes do núcleo](../../tools/2302/r1-googletest-runner.md) | Plano de testes/verificação do núcleo |
| [1223](../../requirements/1223/r1-gui-test-suite.md) | obsolete; corpo intacto | [2303: executor de testes da interface](../../tools/2303/r1-qttest-runner.md) | Plano de testes/verificação de interface |
| [1224](../../requirements/1224/r1-ci-evidence.md) | obsolete; corpo intacto | [2304: integração automatizada](../../tools/2304/r1-github-actions.md) | Planos de implementação e verificação da automação |

As obrigações reais que esses meios verificam continuam nos requisitos financeiros, de interface e de entrega da tabela acima. Não há requisitos novos exigindo um executor ou serviço de CI.

Os demais meios estão em [2301: build e agregação de testes](../../tools/2301/r1-cmake-ctest-build.md), [2305: compiladores nativos](../../tools/2305/r1-native-compilers.md) e [2306: dependências de distribuição](../../tools/2306/r1-qt-deployment.md). Todos os cartões são draft; descrever comandos não prova instalação ou execução. Os planos deverão referenciar os cartões exatos que consumirem, quando forem escritos e aprovados. Não há links fictícios para planos inexistentes.

## Revisões, evidência e continuação

O [índice 1015 r1](r1-concrete-design-index.md) é preservado. Este r2 é uma revisão documental de cobertura, não uma substituição silenciosa do design. A [decisão 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md) registra a correção, as alternativas e a disposição das relações. O [relatório 1019](../../evidence/requirement-refinement.md) enumera as verificações de corpo e de links e as referências incidentes; o [relatório 1020](../../evidence/tool-card-correction.md) documenta os cartões de ferramentas.

Maturidade: arquitetura aprovada; requisitos refinados em draft; planos ainda não criados; testes de produto não executados; revisão independente não iniciada. As consultas documentais anteriores não são declaradas retrospectivamente como pesquisa completa pelo fluxo research. O próximo responsável é o orquestrador, para conferir este retorno e conduzir os próximos passos sob a autoridade existente.
