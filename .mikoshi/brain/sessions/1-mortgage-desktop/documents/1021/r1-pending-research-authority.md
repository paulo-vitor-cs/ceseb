---
id: 1021
revision: 1
type: document
tags:
- mortgage
- research
- authority
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Pedido humano de despacho das pesquisas pendentes para confrontar o projeto
  aprovado com evidências e divergências.
use_when:
- Recuperar os eixos, limites e autoridade da rodada de pesquisa documental do Projeto
  1.
---
# Pesquisa pendente — pedido e recorte

Pedido humano integral:

> despache as pesquisas pendentes para analisarmos se não existe qualquer divergência e para embalamos nosso projeto, conforme $mikoshi:mikoshi-research

Skill explicitamente invocada: mikoshi-research r10, no pacote instalado 3.0.0. O propósito operacional é fundamentar o projeto e identificar convergências, divergências e lacunas em relação ao design aprovado. A palavra original “embalamos” é preservada; viabilidade de distribuição/empacotamento é pesquisada, sem construir pacotes nesta rodada.

## Eixos de pesquisa

| ID | Pergunta discriminante | Alvos existentes | Compilação e ownership |
|---|---|---|---|
| FIN | As definições de taxas, anuidade, livros Price/SAC e arredondamento são coerentes, e quais partes são convenções próprias ou divergem das fontes? | Specs 1008/1012 r1; requisitos 1101 a 1106 e 1201 a 1207 | scout research-finance; documento 3001; knowledge 3101 a 3110 |
| TECH | A baseline C++20, Qt 6.8.3, Boost 1.86 decimal50, CMake/CTest e testes sustenta os contratos e a precisão pretendida? | Specs 1008/1013/1014 r1; requisitos efetivos de integração/interface; tools 2301 a 2305 | scout research-technology; documento 3002; knowledge 3121 a 3130 |
| DIST | A distribuição Windows 11/Ubuntu 24.04 e o acesso aos kits, dependências, patches e licenças têm divergências ou condicionantes materiais? | Spec 1014 r1; requisitos 1225 a 1228; tools 2304 a 2306 | scout research-distribution; documento 3003; knowledge 3141 a 3150 |

As faixas de IDs reservam ownership, não impõem quantidade de notas ou orçamento. Não foi fornecido orçamento de tempo, tokens ou número de consultas. A suficiência será julgada pela cobertura útil de cada pergunta, fontes contrárias e limites efetivamente encontrados.

Cada scout deve pesquisar antes de concluir, registrar consultas reais e expansão de fontes, ler as unidades relevantes, procurar contraevidência e produzir duas entregas: compilação e notas de conhecimento completas em draft. Diferenciar fonte normativa/documental, alegação de fornecedor, evidência empírica, inferência e convenção humana. Uma busca negativa limitada não prova ausência universal de divergências.

## Corpus e fronteiras

MAIN: /home/paulo/ceseb. Sessão: 1-mortgage-desktop. Fontes locais: [pedido original](../1001/r1-human-request.md), [autoridade e emendas](../1005/r1-human-scope-approval.md), [aceite do design/correção](../1017/r1-design-approval-and-quality-correction.md), [índice efetivo](../1015/r2-refined-requirement-index.md), quatro specs aprovadas, 25 requisitos efetivos, seis cartões e relatórios anteriores. Os três requisitos obsolete são história, não critérios de produto atuais.

Fontes externas: documentação versionada oficial, literatura primária e projetos/repositórios primários pertinentes, padrões acessíveis quando necessários. Context7 deve ter resultado real ou lacuna concreta, com uso de fontes oficiais permitido e atribuído quando a ferramenta não estiver disponível. Não usar metadados de catálogo como leitura integral. Consultas pontuais passadas podem ser reutilizadas como sementes, sem serem rebatizadas como pesquisa completa anterior.

A pesquisa não altera o design aceito, requisitos, ferramentas existentes, licença ou ambiente. Não autoriza implementação, instalação, experimento/benchmark de produto, promoção/publicação, Git push, council ou Synapses. Uma divergência material retorna para análise do humano e do specialist. Um experimento necessário será proposto separadamente. O orquestrador aguardará todos os retornos e produzirá a síntese documental 3004 para análise.
