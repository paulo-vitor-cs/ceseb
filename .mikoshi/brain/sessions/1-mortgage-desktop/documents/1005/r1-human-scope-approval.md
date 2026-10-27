---
id: 1005
revision: 1
type: document
tags:
- mortgage
- authority
- clarification
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Autorizações de avanço e escolhas humanas de taxas nominal e efetiva,
  comparação Price/SAC e interface Qt Widgets.
use_when:
- Recuperar as autorizações de fase e as escolhas humanas do projeto, distinguindo-as
  das propostas técnicas ainda em rascunho.
---
# Resposta humana ao gate da descoberta

Origem: resposta aos controles de pergunta neste chat em 2026-10-26.

Pergunta1: “A proposta r1 está em /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/documents/1003/r1-discovery-proposal.md: calculadora local com valor, taxa, prazo, parcela/total/juros, validação, Google Test e entrega Windows/Linux. Você aprova esse escopo e o avanço pelas fases de exploração, esclarecimentos e arquitetura em rascunho? O design concreto e os planos terão seus próprios gates.”

Resposta integral: “Aprovo esse avanço”.

Pergunta2: “Para o primeiro recorte, qual combinação você prefere? A proposta Price usa taxa anual nominal dividida por 12 e não inclui seguros, tarifas ou impostos. Precisão e arredondamento ainda serão especificados.” Opções apresentadas: Qt6 Widgets; Price; português e BRL. Qt6 Widgets; Price e SAC; português e BRL. Qt6 Widgets; Price; inglês e USD.

Resposta integral: “explique melhor cada uma dessas taxas”.

Interpretação de autoridade: o avanço pelas fases2 (exploração),3 (esclarecimentos) e4 (arquitetura em rascunho) está aprovado para o escopo apresentado. A resposta2 pede esclarecimento e não seleciona nenhuma opção. Taxa nominal/efetiva, Price/SAC, interface e idioma/moeda continuam abertos. Não há autorização para planos ou implementação futuros nem para uma nova publicação remota.

Fonte relacionada: [descoberta1003 r1](../1003/r1-discovery-proposal.md). A aprovação cobre o avanço proposto, sem transformar a proposta inteira em uma spec publicada.

## Emenda humana posterior: incluir as duas taxas

Após a explicação de que 12% anuais nominais com capitalização mensal equivalem a 1% mensal e 12,68% anuais efetivos, enquanto 12% anuais efetivos equivalem a aproximadamente 0,9489% mensais, o humano respondeu: “coloque ambas no app”.

Antecedente contextual: taxas nominal e efetiva. Autoridade recebida: incluir suporte às duas formas de taxa no aplicativo. Isso não seleciona entre os sistemas Price e SAC. A interface deve explicitar o tipo e o período e a especificação deve definir conversões e testes. Periodicidades expostas na interface e limites numéricos serão concretizados no design.

A declaração anterior de que nenhuma opção financeira havia sido selecionada permanece evidência do momento anterior; esta emenda resolve somente a inclusão de nominal e efetiva.

## Emenda humana: Price e SAC; pergunta sobre QML

Pergunta: “As taxas nominal e efetiva já estão incluídas. Para calcular as prestações, quais sistemas de amortização você quer no primeiro app?”
Resposta integral: “Price e SAC: comparar prestações fixas com prestações decrescentes”.

Pergunta sobre a combinação de interface, idioma e moeda: Qt6 Widgets pt-BR/BRL; Qt6 Quick/QML pt-BR/BRL; Qt6 Widgets inglês/USD.
Resposta integral: “Qt Quick/QML aumenta em quanto a complexidade do projeto?”

A escolha humana agora inclui Price e SAC, além de nominal e efetiva. A interface e a localização ainda não foram selecionadas; o humano pede explicação do custo de complexidade do QML antes da escolha.

## Emenda humana: escolher o caminho mais simples para a interface

Após a comparação entre Qt Widgets e Qt Quick/QML, o humano respondeu: “vamos pelo caminho mais simples”. O antecedente explícito é a recomendação de Qt Widgets para o formulário, resultados e comparação Price/SAC com menos tecnologias a manter.

Escolha reconciliada: Qt 6 Widgets, com interface C++. Esta escolha não remove nominal/efetiva nem Price/SAC. Idioma/moeda, distribuição, licença e políticas numéricas serão apresentados como propostas no design concreto; não são escolhas humanas presumidas. O avanço pelas fases2 a4 já está autorizado.
