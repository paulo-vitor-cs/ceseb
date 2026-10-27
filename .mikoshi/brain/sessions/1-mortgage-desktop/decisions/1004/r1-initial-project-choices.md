---
id: 1004
revision: 1
type: decision
tags:
- mortgage
- discovery
status: open
created: '2026-10-26'
updated: '2026-10-26'
description: Registro atribuído das escolhas administrativas iniciais e das alternativas
  materiais ainda abertas na descoberta.
use_when:
- Distinguir escolhas administrativas do orquestrador de decisões de design ainda
  dependentes do humano.
---
# Escolhas iniciais da descoberta

Autor: orquestrador. Fonte de autoridade: [pedido humano](../../documents/1001/r1-human-request.md). A decisão permanece open porque as escolhas materiais abaixo não foram resolvidas.

Escolhas administrativas locais dentro do pedido: associar este projeto novo à sessão 1-mortgage-desktop e ao fluxo design-project-1; usar o workspace atual como MAIN; usar `ceseb`, nome do workspace, para o repositório público autorizado na conta pessoal observada `paulo-vitor-cs`. Alternativas seriam outro ID de sessão e outro nome de repositório; estes não mudam o comportamento do aplicativo. Não há revisão anterior afetada.

Escolhas propostas, ainda sem seleção humana: Qt 6 Widgets ou Qt Quick; Price ou Price mais SAC; taxa nominal ou efetiva; política de arredondamento; idioma e moeda; licença; versões exatas de plataforma e dependências. Razões e consequências estão na [proposta r1](../../documents/1003/r1-discovery-proposal.md).

A criação pública do repositório foi pedida diretamente. Publicar esta base documental não significa aprovação do seu conteúdo como design. Nenhum código de produto, plano de engenharia, PR, merge ou release está incluído neste recorte.

## Escolha humana recebida durante esclarecimentos

Fonte: [resposta e emenda humana1005 r1](../../documents/1005/r1-human-scope-approval.md). O humano aprovou o avanço pelas fases2 a4 em rascunho e pediu “coloque ambas no app”, no contexto da explicação das taxas nominal e efetiva. A opção selecionada é suportar as duas taxas. Alternativas: aceitar somente nominal, reproduzindo a interpretação inicial da imagem; aceitar somente efetiva. Razão contextual: permitir ambas as interpretações explícitas da taxa. A formulação das conversões, precisão e limites ainda pertence à arquitetura. Esta decisão agregada permanece open por conter outras escolhas materiais pendentes; a escolha humana acima não é revertida por esse estado agregado.

## Escolha humana de amortização

Conforme emenda em [1005 r1](../../documents/1005/r1-human-scope-approval.md), a resposta “Price e SAC: comparar prestações fixas com prestações decrescentes” seleciona os dois sistemas e a comparação no aplicativo. A alternativa Price somente foi descartada pelo humano para o primeiro recorte. A pergunta sobre complexidade de QML não seleciona framework gráfico nem localização.

## Escolha humana de interface

Fonte: emenda em [1005 r1](../../documents/1005/r1-human-scope-approval.md). O humano escolheu “vamos pelo caminho mais simples”, no contexto da recomendação de Qt Widgets. Fica selecionado Qt 6 Widgets com interface C++, preservando ambos os tipos de taxa e os sistemas Price/SAC. Idioma/moeda e demais detalhes concretos serão propostas atribuídas no design para sua revisão, sem nova pergunta ritual de avanço de fase.
