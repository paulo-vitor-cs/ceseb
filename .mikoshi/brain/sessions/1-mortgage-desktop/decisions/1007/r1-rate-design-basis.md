---
id: 1007
revision: 1
type: decision
tags:
- mortgage
- interest-rates
- decision
status: decided
created: '2026-10-26'
updated: '2026-10-26'
description: Base atribuída para suportar taxas anuais nominal e efetiva e propor
  seu contrato de conversão mensal.
use_when:
- Distinguir a inclusão humana de ambas as taxas das propostas técnicas de unidades,
  limites e precisão do conversor.
---
# Base de decisão para as duas taxas

Autor deste registro: specialist-financial-design. Estado open: as escolhas técnicas candidatas ainda aguardam aceitação do design concreto. A inclusão de ambos os tipos já é uma escolha humana e não volta a ficar indefinida por esse estado agregado.

## Escolha humana já recebida

Problema: a taxa anual nominal com capitalização mensal e a taxa anual efetiva representam valores diferentes para o mesmo número digitado. Alternativas apresentadas no contexto: trabalhar com nominal, efetiva ou ambas. O humano escolheu “coloque ambas no app”, depois da explicação nominal/efetiva. Fonte exata: [emenda1005 r1](../../documents/1005/r1-human-scope-approval.md). Efeito autorizado: incluir ambos os tipos no design do aplicativo. Price/SAC e a tecnologia gráfica não foram selecionados por essa frase. Em resposta posterior independente, o humano escolheu “Price e SAC: comparar prestações fixas com prestações decrescentes” (1005). Ambos os sistemas agora fazem parte do escopo; tecnologia gráfica e idioma/moeda continuam abertos.

## Propostas técnicas do specialist

| Problema | Proposta candidata | Alternativas e razão |
|---|---|---|
| Período da entrada | Dois tipos explícitos: nominal anual com capitalização mensal; efetiva anual | Entrada mensal adicional amplia o formulário. A entrada anual mantém o recorte aprovado em1003 |
| Unidade interna | Converter ambos para taxa efetiva mensal em fração decimal, mantendo equivalentes anuais em percentual | Passar percentuais não tipados até o cálculo facilita confusão de unidade |
| Interface entre módulos | Função pura do núcleo recebe tipo e percentual anual e retorna resultado ou erro | Acoplar à GUI impediria testes unitários simples e reutilização pelo cálculo |
| Limite da entrada | Candidato 0% a100% ao ano inclusive, para os dois tipos | Sem teto ou outro teto são alternativas.100% é um limite de produto proposto, amplo para a simulação e verificável; não é teto bancário, legal ou escolhido pelo humano |
| Precisão | Candidata: erro absoluto máximo 1e-12 para taxa mensal decimal e1e-9 ponto percentual para equivalentes anuais nos casos declarados | Decimal exato ou outro orçamento de erro pode ser escolhido no design completo. A tolerância mantém várias ordens de precisão além da apresentação percentual; não define centavos de prestações |
| Arredondamento | Preservar a taxa normalizada no núcleo; arredondar somente sua apresentação | Arredondar a taxa mensal mostrada antes do cálculo pode acumular erro em muitos meses |

Origem das propostas: necessidade humana de ambos os tipos, entrada anual já proposta em1003, separação entre cálculo e interface, engenharia determinística e [referência matemática exploratória](../../evidence/rate-conversion-reference.json). Esta última é aritmética Decimal de apoio e não é teste de produto nem oráculo aprovado.

As propostas serão usadas apenas nos rascunhos [spec1008](../../specs/1008/r1-annual-rate-conversion.md) e requirements1101..1106. Nenhum plano executável é autorizado. A política de arredondamento monetário, a formulação concreta dos dois sistemas de amortização selecionados, GUI, idioma/moeda, licença e plataformas concretas continuam pendentes. Não há revisão predecessora, plano antigo ou aresta publicada afetada; os links novos acrescentam rastreabilidade às fontes preservadas.

## Integração com o design completo

A resposta posterior registrada em1005 escolheu Qt Widgets. A proposta completa de [1011](../1011/r1-complete-design-basis.md) concretiza o tipo numérico do núcleo como Boost decimal50 e preserva estas conversões e os requisitos1101..1106. O teto0..100% aplica-se à entrada anual; a GUI proposta aceita seis casas, sem limitar equivalentes derivados. A política monetária das prestações é separada na spec1012. Os estados open/draft continuam e nenhuma proposta técnica foi aceita por silêncio. Esta adição integra um rascunho não publicado; não altera um corpo aprovado.
