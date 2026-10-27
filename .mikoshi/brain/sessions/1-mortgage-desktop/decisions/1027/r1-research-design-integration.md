---
id: 1027
revision: 1
type: decision
tags:
- mortgage
- design
- integration
- trace
status: decided
created: '2026-10-26'
updated: '2026-10-26'
description: Integração proposta das revisões numérica e Qt, conservando a autoridade e as relações
  das revisões aceitas.
use_when:
- Selecionar a revisão concreta após pesquisa sem transferir aprovação ou resultados históricos
  aos sucessores.
---
# Integração do delta de arquitetura

## Context

O [pedido 1022](../../documents/1022/r1-resolution-authority.md) autoriza resolver os empates e revisar Qt com simplicidade. O resultado da pesquisa permanece em [3004](../../documents/3004/r1-research-synthesis.md). A aprovação histórica em [1017](../../documents/1017/r1-design-approval-and-quality-correction.md) conserva seu alvo e não é tratada como resposta a texto futuro.

## Question and Options

Aprovar o conjunto concreto do [índice 1015 r3](../../documents/1015/r3-research-driven-design.md) para preparar os planos, ou ajustar as propostas antes da transição? O conjunto mantém modelo financeiro, GUI, alvos e entregáveis; altera o método que decide as fronteiras e o pin Qt. A alternativa de quantizar a taxa mensal mudaria a convenção e foi explicitamente comparada, sem ser adotada por silêncio. Manter Qt 6.8.3 ou patches próprios são alternativas registradas em 1026.

## Decision and Authority

**Open.** O integrador recomenda o conjunto das decisões [1025](../1025/r1-exact-rounding-method.md) e [1026](../1026/r1-qt-baseline-choice.md). Não há resposta humana a essas revisões. A gravação dos rascunhos é uma escolha de autoria autorizada; substituição da baseline aceita e entrada em planejamento dependem da resposta ao conjunto concreto. Planos, instalação, produto, promoção e publicação não estão executados por esta decisão.

## Impact and Relations

- Preservar os quatro arquivos aprovados r1 integralmente. As quatro specs r2 são sucessoras propostas, com relações `related` de origem e nenhuma herança de resultado.
- Manter todas as citações históricas que apontam a r1 em decisões anteriores, evidências, pesquisa e índices r1/r2. Seu significado é sustentar ou descrever aquela baseline, não selecionar automaticamente o r2.
- Acrescentar no novo conjunto as referências exatas aos sucessores e aos mesmos requisitos quando o contrato permanece aplicável. Requisitos ainda draft podem ser refinados em r1; os snapshots anteriores permanecem na evidência do specialist. Não há requisito aprovado sendo sobrescrito.
- Reconciliar as dependências cruzadas: 1008 r2 alimenta 1012 r2 e 1013 r2; 1014 r2 referencia os mesmos métodos. Nenhum caminho futuro de plano/arquivo é inventado.
- Refinar apenas os cartões draft 2301/2302/2303/2306, com preimages e sem operação instalada por inferência. O novo pin do QtTest acompanha a mesma candidata; os cartões 2304/2305 continuam aplicáveis. Os antigos requisitos de método 1222–1224 continuam obsolete.
- A evidência [resolution-edge-dispositions.json](../../evidence/resolution-edge-dispositions.json) enumera os links locais incidentes, com fonte, destino, tipo, contexto, disposição e razão. Ligações legadas preservadas são `retain`; novos vínculos são `add`; links de drafts redirecionados são `rebase`, com antes/depois conservados. Fontes externas conservam versão e unidade de leitura nas análises. Referências apenas textuais e evidência em JSON/YAML não são automaticamente arestas formais; constam no inventário complementar e mantêm sentido histórico.
- O índice global de grafo anteriormente incompatível é uma limitação histórica; a integração registra separadamente a observação atual sobre o corpus explícito. Não afirmar cobertura semântica universal a partir da extração de links.

## Verification and Continuation

A [conferência de integração](../../evidence/resolution-integration-checks.json) registra preservação, checks nativos de artefato, links e validação da sessão. Esses resultados dizem respeito à estrutura documental. As deduções numéricas estão em 1023; os fatos versionados do Qt estão em 1024. Não houve compilação, teste de produto, benchmark, pacote ou revisão independente.

O orquestrador apresenta o delta ao humano no gate de arquitetura. Após aceite aplicável, autores distintos preparam planos de testes e implementação; aprovação de design não aprova planos ainda não escritos. A sessão permanece em MAIN e disponível.
