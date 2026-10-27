---
id: 1006
revision: 1
type: document
tags:
- mortgage
- clarification
- interest-rates
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Interpretação reconciliada das escolhas nominal/efetiva, Price/SAC e
  Qt Widgets, com propostas restantes submetidas ao design concreto.
use_when:
- Recuperar as respostas de escopo e separar escolhas humanas das propostas do design
  completo.
---
# Esclarecimentos — Projeto1

## Interpretação reconciliada

O humano aprovou avanço pelas fases de exploração, esclarecimentos e arquitetura em rascunho, conforme [1005 r1](../1005/r1-human-scope-approval.md). Escolheu também incluir taxas nominal e efetiva. A entrada anual já faz parte do [escopo apresentado](../1003/r1-discovery-proposal.md). O desenho independente proposto usa dois tipos explícitos: nominal anual com capitalização mensal e efetiva anual. A mesma taxa efetiva mensal normalizada alimentará o modelo de financiamento que vier a ser selecionado.

Por exemplo,12% ao ano nominais, capitalizados mensalmente, representam1% ao mês e aproximadamente 12,682503% ao ano efetivos.12% ao ano efetivos representam aproximadamente0,948879% ao mês. Esses valores são equivalência matemática entre períodos; não representam um custo adicional nem a soma dos juros de um financiamento amortizado. O [glossário CRECISP](https://crecisp.gov.br/comunicacao/glossario/t) apresenta o primeiro exemplo. As fórmulas e casos candidatos estão na [spec1008](../../specs/1008/r1-annual-rate-conversion.md).

O pedido “ambas” é associado ao antecedente nominal/efetiva. Posteriormente, o humano selecionou separadamente “Price e SAC: comparar prestações fixas com prestações decrescentes”, conforme1005. A inclusão dos dois sistemas está resolvida; sua formulação e integração com as duas taxas ainda serão desenhadas. Ambos os tipos de taxa podem ser usados com qualquer sistema de amortização suportado. Taxa efetiva de juros também não equivale por si só ao CET; o recorte segue sem seguros, tarifas e impostos enquanto não houver ampliação explícita.

## Perguntas apresentadas e respostas recebidas

1. **O primeiro aplicativo deve calcular somente Price, com prestações de principal e juros constantes, ou permitir escolher Price e SAC, cuja amortização do principal é constante e cujas prestações diminuem no modelo sem correção e encargos?** Price mantém o recorte próximo ao exemplo da imagem. Price+SAC acrescenta um seletor, dois modelos e seus resultados/testes; não exige automaticamente uma tabela mensal ou exportação. A recomendação inicial permanece Price para este primeiro recorte, mas essa seleção é humana.
2. **Podemos preparar o design da interface com Qt6 Widgets, em português e valores em BRL, ou você prefere outra combinação?** Qt6 Widgets mantém componentes desktop e código de interface em C++; Qt Quick/QML oferece outra tecnologia visual, com uma linguagem adicional. Outro idioma ou moeda altera formatos e textos. O pedido exige interface simples e moderna, sem escolher uma biblioteca, idioma ou moeda.

Resposta à pergunta1: o humano selecionou ambos, Price e SAC. Resposta à pergunta2: “Qt Quick/QML aumenta em quanto a complexidade do projeto?”. O orquestrador recebeu a pergunta e apresentará a comparação concreta; Naquele momento GUI e idioma/moeda permaneciam abertos. Não existe base medida neste projeto sem código para um percentual exato de aumento. A pergunta de complexidade não selecionou Widgets ou QML; depois dela, a resposta “vamos pelo caminho mais simples” selecionou Qt Widgets. O humano já aprovou o avanço de fases; não é necessário repetir esse gate.

## Trabalho independente concluído e limites

Foi preparado o rascunho de conversão de taxas, sem escolher um sistema de amortização ou GUI. [Decisão1007](../../decisions/1007/r1-rate-design-basis.md) separa a escolha humana das propostas técnicas. Limite candidato 0..100% anual, tolerâncias numéricas e arredondamento somente de apresentação são propostas do specialist para avaliação no design concreto; não são perguntas de implementação transferidas ao usuário nem escolhas já aprovadas.

A exploração constatou ausência de código, build e testes. Somente GCC foi observado no WSL; CMake, Ninja, Qt e GoogleTest não foram encontrados nas verificações limitadas. Serena e Context7 não estão expostos. Isso limita execução futura, não as duas perguntas de produto. Fonte: [exploração](../../evidence/initial-exploration.md).

Licença, combinações exatas de plataforma/compilador, formato de distribuição e arredondamento monetário permanecem itens do design concreto. Não impedem o contrato independente de conversão de taxas e não são solicitados como escolhas nesta rodada. Não houve plano, implementação, teste de produto, publicação ou revisão independente.

## Reconciliação final das escolhas para o rascunho completo

A emenda mais recente de1005 seleciona Qt 6 Widgets/C++ para o caminho mais simples. Nominal/efetiva e Price/SAC continuam exigidos. Não existe nova pergunta de preferência técnica nesta rodada: pt-BR/BRL, centavos, limites, baseline e licençaMIT são propostas concretas atribuídas em [1011](../../decisions/1011/r1-complete-design-basis.md), para revisão conjunta no [índice1015](../1015/r1-concrete-design-index.md). Essas propostas não são apresentadas como decisões humanas já recebidas. O próximo gate é o design concreto e sua passagem ao planejamento, não uma repetição do avanço de fases já aprovado.
