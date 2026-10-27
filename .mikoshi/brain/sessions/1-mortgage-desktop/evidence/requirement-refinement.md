---
id: 1019
revision: 1
type: document
tags:
- mortgage
- requirement-refinement
- evidence
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Relatório de correção do corpo dos requisitos, classificação, fronteira
  com ferramentas e referências preservadas.
use_when:
- Conferir a correção metodológica dos requisitos e seus limites antes de planejar
  implementação e testes.
---
# Correção dos requisitos — relatório de autoria

Owner: specialist-requirement-refinement. Flow/head: design-project-1/requirement-refinement. Autoria corretiva na fase 4, sob [1017 r1](../documents/1017/r1-design-approval-and-quality-correction.md). O design foi aceito pelo humano; a qualidade dos requisitos anteriores foi rejeitada.

## Resultado e limites

Antes: 28 requisitos em draft, com corpos abreviados, sem estrutura completa do template e sem nível explícito. Depois: **25 requisitos de produto refinados em draft** e **3 registros de método obsolete**. São 11 de unidade, 6 de integração e 8 de sistema. Os 25 corpos apresentam 92 critérios de aceitação numerados. A contagem descreve a autoria; não é medida de satisfação do produto.

A [decisão 1018 r1](../decisions/1018/r1-requirement-conformance-correction.md) foi escrita antes das alterações. O [índice 1015 r2](../documents/1015/r2-refined-requirement-index.md) declara a cobertura efetiva e preserva o índice r1. Os corpos das quatro specs aprovadas e das decisões de design aceitas não foram alterados. Nenhuma revisão nova de spec foi necessária.

Os requisitos 1222, 1223 e 1224 ficaram obsolete com os corpos exatos intactos. As prescrições foram preservadas nos cartões draft 2302, 2303 e 2304, com planos futuros como consumidores; os demais meios estão em 2301, 2305 e 2306. O corpo de 1221 agora trata apenas a independência/portabilidade do núcleo. Os requisitos 1225 a 1228 conservam propriedades reais dos pacotes, operação e documentação, sem determinar ferramentas.

Não houve plano, código, instalação, build, teste de produto, CI, commit, push, council ou Synapses. Os requisitos não receberam pass/fail. A aprovação do design foi preservada; esta correção não pede um segundo aceite da mesma arquitetura.

## Leitura e método de correção

Foram lidos diretamente: template requirement.md completo; contrato specialist; skill design; regras 2259, 2260 e 2261; seções operativas de authority-and-revisions, controlled-metadata e versioned-artifacts; cartões de artifact-check, session-memory e retrieval; review-boundaries e logical-head-memory. Fontes do projeto lidas integralmente: pedido 1001, extração 1002, emendas 1005, correção 1017, quatro specs e 28 requisitos anteriores. Trechos truncados da primeira leitura de requisitos de UI e classificação foram recuperados em chamadas menores antes da escrita.

Cada corpo foi reconciliado com sua fonte e fronteira aprovada, não apenas expandido com títulos. O nível foi escolhido pela unidade de observação: módulo isolado, contrato entre componentes ou aplicação/entregável completo. Métodos e níveis estão nas tags permitidas e no corpo; nenhum campo extra de frontmatter foi criado. As seções são Requirement, Origin and Boundary, Verification e Trace; Rationale e Acceptance Criteria são subseções explícitas. Procedimento e limites distinguem a obrigação do método futuro de execução.

A aritmética do caso de uso nativo efetivo anual de 12%, R$ 1.000,00 e 3 meses foi derivada em Python Decimal com precisão 60, seguindo exatamente a política aprovada: Price [339,68; 339,68; 339,68], total 1.019,04 e juros 19,04; SAC [342,83; 339,66; 336,49], total 1.018,98 e juros 18,98. Esse detalhamento tornou o oráculo de 1226 explícito. É cálculo de referência da regra existente, não pesquisa nova, teste de produto ou mudança do modelo.

As consultas primárias e a aritmética anteriores continuam classificadas como tal. Esta correção documental não é usada para declarar retrospectivamente uma compilação de pesquisa ou notas de conhecimento inexistentes.

## Conferência de conteúdo por requisito

Na coluna de estrutura, “sim” significa conferência dos quatro cabeçalhos, rationale específico, classificação visível/tags, entradas e alvo, procedimento, critérios, oráculo, limites e trace. Também foi conferida a correspondência entre a obrigação e seus critérios. Não representa uma revisão independente nem satisfação da implementação.

| Requisito | Nível | Critérios | Estrutura completa | Conteúdo reconciliado |
|---|---|---|---|---|
| 1101/r1 | Unidade | 3 | sim | Convenção explícita e erros de tipo sem inferência pelo percentual. |
| 1102/r1 | Unidade | 3 | sim | Divisão nominal por 1200 com quatro vetores e tolerância mensal. |
| 1103/r1 | Unidade | 3 | sim | Equivalência composta com referências independentes e zero exato. |
| 1104/r1 | Unidade | 4 | sim | Equivalentes anuais, unidade de tolerância e valor derivado acima do teto de entrada. |
| 1105/r1 | Unidade | 3 | sim | Não finitos e limites inclusivos, sem sucesso parcial. |
| 1106/r1 | Integração | 3 | sim | Fronteira normalizador/consumidor preserva a taxa; formatação não realimenta cálculo. |
| 1201/r1 | Unidade | 4 | sim | Limites tipados e prioridade de erro; fração textual fica no adaptador. |
| 1202/r1 | Unidade | 4 | sim | Livro Price exato, ajuste final e quitação antecipada com quantidade efetiva. |
| 1203/r1 | Unidade | 4 | sim | Livro SAC exato, resto no início e prestações não crescentes. |
| 1204/r1 | Unidade | 4 | sim | Conservação em cada linha e soma, sem tolerância monetária. |
| 1205/r1 | Unidade | 3 | sim | Zero e prazo único, incluindo empate half-up e ausência de cobrança adicional. |
| 1206/r1 | Unidade | 3 | sim | Duas causas de inadmissibilidade em centavos com erro e atomicidade. |
| 1207/r1 | Integração | 4 | sim | Mesma taxa e condições para ambos os modelos; diferença assinada em centavos. |
| 1211/r1 | Integração | 4 | sim | Contrato textual/tipado pt-BR, unidades e recusa de ambiguidade/truncamento. |
| 1212/r1 | Integração | 4 | sim | Rótulos com seis casas, tipo/período, tolerância e saída derivada não limitada. |
| 1213/r1 | Sistema | 4 | sim | Resumos observáveis, última parcela e prazos informado/efetivo distintos. |
| 1214/r1 | Integração | 5 | sim | Máquina de estados entre edição, controlador e resultado; prioridade e foco definidos. |
| 1215/r1 | Sistema | 4 | sim | Operação completa por teclado em cada desktop, com ordem e atalhos verificáveis. |
| 1216/r1 | Sistema | 3 | sim | Acesso em quatro combinações de plataforma/escala com critérios de conteúdo alcançável. |
| 1217/r1 | Sistema | 4 | sim | Ajuda offline com convenções, exclusões e identificação local. |
| 1221/r1 | Integração | 3 | sim | Independência/portabilidade do núcleo; seleção do build e compilador retirada. |
| 1225/r1 | Sistema | 4 | sim | Propriedade do pacote utilizável pelo usuário sem ambiente de desenvolvimento. |
| 1226/r1 | Sistema | 4 | sim | Cenário nativo completo com nominal/efetiva e referência monetária exata. |
| 1227/r1 | Sistema | 4 | sim | Documentação/relatório entregáveis com alegações recuperáveis, não ferramenta. |
| 1228/r1 | Sistema | 4 | sim | Avisos/inventário do conteúdo distribuído, não escolha de executor ou biblioteca. |

A conferência nativa dos 25 corpos encontrou os quatro cabeçalhos exatos, todos os campos de verificação e uma classificação de nível/método em tags, 92 critérios numerados, nenhum whitespace final e nenhum padrão de palavra portuguesa colada a número entre os padrões conferidos. Os corpos efetivos não prescrevem Google Test, QtTest, CMake ou GitHub Actions. Essa busca lexical é evidência auxiliar; a classificação semântica por obrigação está na tabela e na decisão, não é inferida apenas da ausência de nomes.

## Preservação e referências incidentes

Comparação direta com evidence/requirements-refinement-preimages.json confirmou os corpos exatos das quatro specs, dos três requisitos obsolete e o arquivo inteiro 1015 r1 preservados. As specs continuam com os estados de aceite registrados pelo orquestrador. A edição dos requisitos rejeitados mantém sua revisão 1; não se herdou aceite nem resultado.

A enumeração anterior contém 157 declarações incidentes. Foi repetida a inspeção de todos os Markdown da sessão, excetuando o conteúdo literal de blocos cercados, para referências locais que saem de um dos 28 requisitos ou apontam a ele. Cada par anterior fonte/destino continua presente. Referências dos registros e specs históricos a requisitos obsolete são retidas como históricas; não entram na cobertura efetiva. As novas ligações são de autoridade corretiva, cobertura ou consumidores de ferramentas. Nenhum redirecionamento silencioso de revisão foi aplicado.

### Declarações anteriores e disposição

O JSON preserva fonte, linha, destino, declaração e significado. Colchetes em strings usam escapes JSON para não criar links relativos ao próprio relatório; decodificar o JSON recupera o texto original.

```json
[
  {
    "source": "requirements/1101/r1-explicit-rate-kind.md",
    "line": 23,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1101/r1-explicit-rate-kind.md",
    "line": 23,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "reference": "../../specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1101/r1-explicit-rate-kind.md",
    "line": 23,
    "target": "decisions/1007/r1-rate-design-basis.md",
    "reference": "../../decisions/1007/r1-rate-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1102/r1-nominal-monthly.md",
    "line": 23,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1102/r1-nominal-monthly.md",
    "line": 23,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "reference": "../../specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1102/r1-nominal-monthly.md",
    "line": 23,
    "target": "decisions/1007/r1-rate-design-basis.md",
    "reference": "../../decisions/1007/r1-rate-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1103/r1-effective-monthly.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1103/r1-effective-monthly.md",
    "line": 24,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "reference": "../../specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1103/r1-effective-monthly.md",
    "line": 24,
    "target": "decisions/1007/r1-rate-design-basis.md",
    "reference": "../../decisions/1007/r1-rate-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1104/r1-annual-equivalents.md",
    "line": 23,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1104/r1-annual-equivalents.md",
    "line": 23,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "reference": "../../specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1104/r1-annual-equivalents.md",
    "line": 23,
    "target": "decisions/1007/r1-rate-design-basis.md",
    "reference": "../../decisions/1007/r1-rate-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1105/r1-invalid-rate-input.md",
    "line": 23,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1105/r1-invalid-rate-input.md",
    "line": 23,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "reference": "../../specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1105/r1-invalid-rate-input.md",
    "line": 23,
    "target": "decisions/1007/r1-rate-design-basis.md",
    "reference": "../../decisions/1007/r1-rate-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1106/r1-unrounded-consumer-rate.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1106/r1-unrounded-consumer-rate.md",
    "line": 24,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "reference": "../../specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1106/r1-unrounded-consumer-rate.md",
    "line": 24,
    "target": "decisions/1007/r1-rate-design-basis.md",
    "reference": "../../decisions/1007/r1-rate-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md). Contexto: \u005bspec1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md). Política candidata atribuída: \u005bdecisão1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md). Este requisito é um rascunho sem plano aprovado, alvo implementado ou resultado de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1201/r1-loan-domain.md",
    "line": 25,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1201/r1-loan-domain.md",
    "line": 25,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1201/r1-loan-domain.md",
    "line": 25,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1201/r1-loan-domain.md",
    "line": 25,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1201/r1-loan-domain.md",
    "line": 25,
    "target": "specs/1012/r1-amortization-comparison.md",
    "reference": "../../specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1202/r1-price-ledger.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1202/r1-price-ledger.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1202/r1-price-ledger.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1202/r1-price-ledger.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1202/r1-price-ledger.md",
    "line": 24,
    "target": "specs/1012/r1-amortization-comparison.md",
    "reference": "../../specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1203/r1-sac-ledger.md",
    "line": 25,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1203/r1-sac-ledger.md",
    "line": 25,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1203/r1-sac-ledger.md",
    "line": 25,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1203/r1-sac-ledger.md",
    "line": 25,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1203/r1-sac-ledger.md",
    "line": 25,
    "target": "specs/1012/r1-amortization-comparison.md",
    "reference": "../../specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1204/r1-money-invariants.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1204/r1-money-invariants.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1204/r1-money-invariants.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1204/r1-money-invariants.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1204/r1-money-invariants.md",
    "line": 24,
    "target": "specs/1012/r1-amortization-comparison.md",
    "reference": "../../specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1205/r1-zero-and-single-period.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1205/r1-zero-and-single-period.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1205/r1-zero-and-single-period.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1205/r1-zero-and-single-period.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1205/r1-zero-and-single-period.md",
    "line": 24,
    "target": "specs/1012/r1-amortization-comparison.md",
    "reference": "../../specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1206/r1-cent-precision-errors.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1206/r1-cent-precision-errors.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1206/r1-cent-precision-errors.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1206/r1-cent-precision-errors.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1206/r1-cent-precision-errors.md",
    "line": 24,
    "target": "specs/1012/r1-amortization-comparison.md",
    "reference": "../../specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1207/r1-comparable-results.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1207/r1-comparable-results.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1207/r1-comparable-results.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1207/r1-comparable-results.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1207/r1-comparable-results.md",
    "line": 24,
    "target": "specs/1012/r1-amortization-comparison.md",
    "reference": "../../specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1012\u005d(../../specs/1012/r1-amortization-comparison.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1211/r1-localized-input.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1211/r1-localized-input.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1211/r1-localized-input.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1211/r1-localized-input.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1211/r1-localized-input.md",
    "line": 24,
    "target": "specs/1013/r1-widgets-interface.md",
    "reference": "../../specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1212/r1-rate-presentation.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1212/r1-rate-presentation.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1212/r1-rate-presentation.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1212/r1-rate-presentation.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1212/r1-rate-presentation.md",
    "line": 24,
    "target": "specs/1013/r1-widgets-interface.md",
    "reference": "../../specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1213/r1-comparison-presentation.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1213/r1-comparison-presentation.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1213/r1-comparison-presentation.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1213/r1-comparison-presentation.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1213/r1-comparison-presentation.md",
    "line": 24,
    "target": "specs/1013/r1-widgets-interface.md",
    "reference": "../../specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1214/r1-ui-state-recovery.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1214/r1-ui-state-recovery.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1214/r1-ui-state-recovery.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1214/r1-ui-state-recovery.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1214/r1-ui-state-recovery.md",
    "line": 24,
    "target": "specs/1013/r1-widgets-interface.md",
    "reference": "../../specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1215/r1-keyboard-navigation.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1215/r1-keyboard-navigation.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1215/r1-keyboard-navigation.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1215/r1-keyboard-navigation.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1215/r1-keyboard-navigation.md",
    "line": 24,
    "target": "specs/1013/r1-widgets-interface.md",
    "reference": "../../specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1216/r1-resize-access.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1216/r1-resize-access.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1216/r1-resize-access.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1216/r1-resize-access.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1216/r1-resize-access.md",
    "line": 24,
    "target": "specs/1013/r1-widgets-interface.md",
    "reference": "../../specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1217/r1-model-help.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1217/r1-model-help.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1217/r1-model-help.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1217/r1-model-help.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1217/r1-model-help.md",
    "line": 24,
    "target": "specs/1013/r1-widgets-interface.md",
    "reference": "../../specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1013\u005d(../../specs/1013/r1-widgets-interface.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1221/r1-build-contract.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1221/r1-build-contract.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1221/r1-build-contract.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1221/r1-build-contract.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1221/r1-build-contract.md",
    "line": 24,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "reference": "../../specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1222/r1-core-test-suite.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "requirements/1222/r1-core-test-suite.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "requirements/1222/r1-core-test-suite.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "requirements/1222/r1-core-test-suite.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "requirements/1222/r1-core-test-suite.md",
    "line": 24,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "reference": "../../specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "requirements/1223/r1-gui-test-suite.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "requirements/1223/r1-gui-test-suite.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "requirements/1223/r1-gui-test-suite.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "requirements/1223/r1-gui-test-suite.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "requirements/1223/r1-gui-test-suite.md",
    "line": 24,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "reference": "../../specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "requirements/1224/r1-ci-evidence.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "requirements/1224/r1-ci-evidence.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "requirements/1224/r1-ci-evidence.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "requirements/1224/r1-ci-evidence.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "requirements/1224/r1-ci-evidence.md",
    "line": 24,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "reference": "../../specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "requirements/1225/r1-runtime-packages.md",
    "line": 26,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1225/r1-runtime-packages.md",
    "line": 26,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1225/r1-runtime-packages.md",
    "line": 26,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1225/r1-runtime-packages.md",
    "line": 26,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1225/r1-runtime-packages.md",
    "line": 26,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "reference": "../../specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1226/r1-native-smoke.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1226/r1-native-smoke.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1226/r1-native-smoke.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1226/r1-native-smoke.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1226/r1-native-smoke.md",
    "line": 24,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "reference": "../../specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1227/r1-technical-documentation.md",
    "line": 25,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1227/r1-technical-documentation.md",
    "line": 25,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1227/r1-technical-documentation.md",
    "line": 25,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1227/r1-technical-documentation.md",
    "line": 25,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1227/r1-technical-documentation.md",
    "line": 25,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "reference": "../../specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1228/r1-distribution-notices.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "reference": "../../documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1228/r1-distribution-notices.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "reference": "../../documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1228/r1-distribution-notices.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "reference": "../../documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1228/r1-distribution-notices.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "reference": "../../decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "requirements/1228/r1-distribution-notices.md",
    "line": 24,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "reference": "../../specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1008/r1-annual-rate-conversion.md",
    "line": 53,
    "target": "requirements/1101/r1-explicit-rate-kind.md",
    "reference": "../../requirements/1101/r1-explicit-rate-kind.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos candidatos: \u005b1101 tipo explícito\u005d(../../requirements/1101/r1-explicit-rate-kind.md), \u005b1102 nominal mensal\u005d(../../requirements/1102/r1-nominal-monthly.md), \u005b1103 efetiva mensal\u005d(../../requirements/1103/r1-effective-monthly.md), \u005b1104 equivalentes anuais\u005d(../../requirements/1104/r1-annual-equivalents.md), \u005b1105 entrada inválida\u005d(../../requirements/1105/r1-invalid-rate-input.md), \u005b1106 taxa integral ao consumidor\u005d(../../requirements/1106/r1-unrounded-consumer-rate.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1008/r1-annual-rate-conversion.md",
    "line": 53,
    "target": "requirements/1102/r1-nominal-monthly.md",
    "reference": "../../requirements/1102/r1-nominal-monthly.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos candidatos: \u005b1101 tipo explícito\u005d(../../requirements/1101/r1-explicit-rate-kind.md), \u005b1102 nominal mensal\u005d(../../requirements/1102/r1-nominal-monthly.md), \u005b1103 efetiva mensal\u005d(../../requirements/1103/r1-effective-monthly.md), \u005b1104 equivalentes anuais\u005d(../../requirements/1104/r1-annual-equivalents.md), \u005b1105 entrada inválida\u005d(../../requirements/1105/r1-invalid-rate-input.md), \u005b1106 taxa integral ao consumidor\u005d(../../requirements/1106/r1-unrounded-consumer-rate.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1008/r1-annual-rate-conversion.md",
    "line": 53,
    "target": "requirements/1103/r1-effective-monthly.md",
    "reference": "../../requirements/1103/r1-effective-monthly.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos candidatos: \u005b1101 tipo explícito\u005d(../../requirements/1101/r1-explicit-rate-kind.md), \u005b1102 nominal mensal\u005d(../../requirements/1102/r1-nominal-monthly.md), \u005b1103 efetiva mensal\u005d(../../requirements/1103/r1-effective-monthly.md), \u005b1104 equivalentes anuais\u005d(../../requirements/1104/r1-annual-equivalents.md), \u005b1105 entrada inválida\u005d(../../requirements/1105/r1-invalid-rate-input.md), \u005b1106 taxa integral ao consumidor\u005d(../../requirements/1106/r1-unrounded-consumer-rate.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1008/r1-annual-rate-conversion.md",
    "line": 53,
    "target": "requirements/1104/r1-annual-equivalents.md",
    "reference": "../../requirements/1104/r1-annual-equivalents.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos candidatos: \u005b1101 tipo explícito\u005d(../../requirements/1101/r1-explicit-rate-kind.md), \u005b1102 nominal mensal\u005d(../../requirements/1102/r1-nominal-monthly.md), \u005b1103 efetiva mensal\u005d(../../requirements/1103/r1-effective-monthly.md), \u005b1104 equivalentes anuais\u005d(../../requirements/1104/r1-annual-equivalents.md), \u005b1105 entrada inválida\u005d(../../requirements/1105/r1-invalid-rate-input.md), \u005b1106 taxa integral ao consumidor\u005d(../../requirements/1106/r1-unrounded-consumer-rate.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1008/r1-annual-rate-conversion.md",
    "line": 53,
    "target": "requirements/1105/r1-invalid-rate-input.md",
    "reference": "../../requirements/1105/r1-invalid-rate-input.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos candidatos: \u005b1101 tipo explícito\u005d(../../requirements/1101/r1-explicit-rate-kind.md), \u005b1102 nominal mensal\u005d(../../requirements/1102/r1-nominal-monthly.md), \u005b1103 efetiva mensal\u005d(../../requirements/1103/r1-effective-monthly.md), \u005b1104 equivalentes anuais\u005d(../../requirements/1104/r1-annual-equivalents.md), \u005b1105 entrada inválida\u005d(../../requirements/1105/r1-invalid-rate-input.md), \u005b1106 taxa integral ao consumidor\u005d(../../requirements/1106/r1-unrounded-consumer-rate.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1008/r1-annual-rate-conversion.md",
    "line": 53,
    "target": "requirements/1106/r1-unrounded-consumer-rate.md",
    "reference": "../../requirements/1106/r1-unrounded-consumer-rate.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos candidatos: \u005b1101 tipo explícito\u005d(../../requirements/1101/r1-explicit-rate-kind.md), \u005b1102 nominal mensal\u005d(../../requirements/1102/r1-nominal-monthly.md), \u005b1103 efetiva mensal\u005d(../../requirements/1103/r1-effective-monthly.md), \u005b1104 equivalentes anuais\u005d(../../requirements/1104/r1-annual-equivalents.md), \u005b1105 entrada inválida\u005d(../../requirements/1105/r1-invalid-rate-input.md), \u005b1106 taxa integral ao consumidor\u005d(../../requirements/1106/r1-unrounded-consumer-rate.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1012/r1-amortization-comparison.md",
    "line": 62,
    "target": "requirements/1201/r1-loan-domain.md",
    "reference": "../../requirements/1201/r1-loan-domain.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md), \u005b1202\u005d(../../requirements/1202/r1-price-ledger.md), \u005b1203\u005d(../../requirements/1203/r1-sac-ledger.md), \u005b1204\u005d(../../requirements/1204/r1-money-invariants.md), \u005b1205\u005d(../../requirements/1205/r1-zero-and-single-period.md), \u005b1206\u005d(../../requirements/1206/r1-cent-precision-errors.md), \u005b1207\u005d(../../requirements/1207/r1-comparable-results.md). Somente rascunho; nenhum plano, implementação ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1012/r1-amortization-comparison.md",
    "line": 62,
    "target": "requirements/1202/r1-price-ledger.md",
    "reference": "../../requirements/1202/r1-price-ledger.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md), \u005b1202\u005d(../../requirements/1202/r1-price-ledger.md), \u005b1203\u005d(../../requirements/1203/r1-sac-ledger.md), \u005b1204\u005d(../../requirements/1204/r1-money-invariants.md), \u005b1205\u005d(../../requirements/1205/r1-zero-and-single-period.md), \u005b1206\u005d(../../requirements/1206/r1-cent-precision-errors.md), \u005b1207\u005d(../../requirements/1207/r1-comparable-results.md). Somente rascunho; nenhum plano, implementação ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1012/r1-amortization-comparison.md",
    "line": 62,
    "target": "requirements/1203/r1-sac-ledger.md",
    "reference": "../../requirements/1203/r1-sac-ledger.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md), \u005b1202\u005d(../../requirements/1202/r1-price-ledger.md), \u005b1203\u005d(../../requirements/1203/r1-sac-ledger.md), \u005b1204\u005d(../../requirements/1204/r1-money-invariants.md), \u005b1205\u005d(../../requirements/1205/r1-zero-and-single-period.md), \u005b1206\u005d(../../requirements/1206/r1-cent-precision-errors.md), \u005b1207\u005d(../../requirements/1207/r1-comparable-results.md). Somente rascunho; nenhum plano, implementação ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1012/r1-amortization-comparison.md",
    "line": 62,
    "target": "requirements/1204/r1-money-invariants.md",
    "reference": "../../requirements/1204/r1-money-invariants.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md), \u005b1202\u005d(../../requirements/1202/r1-price-ledger.md), \u005b1203\u005d(../../requirements/1203/r1-sac-ledger.md), \u005b1204\u005d(../../requirements/1204/r1-money-invariants.md), \u005b1205\u005d(../../requirements/1205/r1-zero-and-single-period.md), \u005b1206\u005d(../../requirements/1206/r1-cent-precision-errors.md), \u005b1207\u005d(../../requirements/1207/r1-comparable-results.md). Somente rascunho; nenhum plano, implementação ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1012/r1-amortization-comparison.md",
    "line": 62,
    "target": "requirements/1205/r1-zero-and-single-period.md",
    "reference": "../../requirements/1205/r1-zero-and-single-period.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md), \u005b1202\u005d(../../requirements/1202/r1-price-ledger.md), \u005b1203\u005d(../../requirements/1203/r1-sac-ledger.md), \u005b1204\u005d(../../requirements/1204/r1-money-invariants.md), \u005b1205\u005d(../../requirements/1205/r1-zero-and-single-period.md), \u005b1206\u005d(../../requirements/1206/r1-cent-precision-errors.md), \u005b1207\u005d(../../requirements/1207/r1-comparable-results.md). Somente rascunho; nenhum plano, implementação ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1012/r1-amortization-comparison.md",
    "line": 62,
    "target": "requirements/1206/r1-cent-precision-errors.md",
    "reference": "../../requirements/1206/r1-cent-precision-errors.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md), \u005b1202\u005d(../../requirements/1202/r1-price-ledger.md), \u005b1203\u005d(../../requirements/1203/r1-sac-ledger.md), \u005b1204\u005d(../../requirements/1204/r1-money-invariants.md), \u005b1205\u005d(../../requirements/1205/r1-zero-and-single-period.md), \u005b1206\u005d(../../requirements/1206/r1-cent-precision-errors.md), \u005b1207\u005d(../../requirements/1207/r1-comparable-results.md). Somente rascunho; nenhum plano, implementação ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1012/r1-amortization-comparison.md",
    "line": 62,
    "target": "requirements/1207/r1-comparable-results.md",
    "reference": "../../requirements/1207/r1-comparable-results.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md), \u005b1202\u005d(../../requirements/1202/r1-price-ledger.md), \u005b1203\u005d(../../requirements/1203/r1-sac-ledger.md), \u005b1204\u005d(../../requirements/1204/r1-money-invariants.md), \u005b1205\u005d(../../requirements/1205/r1-zero-and-single-period.md), \u005b1206\u005d(../../requirements/1206/r1-cent-precision-errors.md), \u005b1207\u005d(../../requirements/1207/r1-comparable-results.md). Somente rascunho; nenhum plano, implementação ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1013/r1-widgets-interface.md",
    "line": 59,
    "target": "requirements/1211/r1-localized-input.md",
    "reference": "../../requirements/1211/r1-localized-input.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1211\u005d(../../requirements/1211/r1-localized-input.md), \u005b1212\u005d(../../requirements/1212/r1-rate-presentation.md), \u005b1213\u005d(../../requirements/1213/r1-comparison-presentation.md), \u005b1214\u005d(../../requirements/1214/r1-ui-state-recovery.md), \u005b1215\u005d(../../requirements/1215/r1-keyboard-navigation.md), \u005b1216\u005d(../../requirements/1216/r1-resize-access.md), \u005b1217\u005d(../../requirements/1217/r1-model-help.md). \u005bQtWidgets\u005d(https://doc.qt.io/qt-6.8/qtwidgets-index.html) documenta componentes, estilos e layouts; \u005bQtTest\u005d(https://doc.qt.io/qt-6.8/qtest-overview.html) sustenta testes de eventos da interface. Consultados em2026-10-26. Nenhuma janela foi executada nesta autoria.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1013/r1-widgets-interface.md",
    "line": 59,
    "target": "requirements/1212/r1-rate-presentation.md",
    "reference": "../../requirements/1212/r1-rate-presentation.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1211\u005d(../../requirements/1211/r1-localized-input.md), \u005b1212\u005d(../../requirements/1212/r1-rate-presentation.md), \u005b1213\u005d(../../requirements/1213/r1-comparison-presentation.md), \u005b1214\u005d(../../requirements/1214/r1-ui-state-recovery.md), \u005b1215\u005d(../../requirements/1215/r1-keyboard-navigation.md), \u005b1216\u005d(../../requirements/1216/r1-resize-access.md), \u005b1217\u005d(../../requirements/1217/r1-model-help.md). \u005bQtWidgets\u005d(https://doc.qt.io/qt-6.8/qtwidgets-index.html) documenta componentes, estilos e layouts; \u005bQtTest\u005d(https://doc.qt.io/qt-6.8/qtest-overview.html) sustenta testes de eventos da interface. Consultados em2026-10-26. Nenhuma janela foi executada nesta autoria.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1013/r1-widgets-interface.md",
    "line": 59,
    "target": "requirements/1213/r1-comparison-presentation.md",
    "reference": "../../requirements/1213/r1-comparison-presentation.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1211\u005d(../../requirements/1211/r1-localized-input.md), \u005b1212\u005d(../../requirements/1212/r1-rate-presentation.md), \u005b1213\u005d(../../requirements/1213/r1-comparison-presentation.md), \u005b1214\u005d(../../requirements/1214/r1-ui-state-recovery.md), \u005b1215\u005d(../../requirements/1215/r1-keyboard-navigation.md), \u005b1216\u005d(../../requirements/1216/r1-resize-access.md), \u005b1217\u005d(../../requirements/1217/r1-model-help.md). \u005bQtWidgets\u005d(https://doc.qt.io/qt-6.8/qtwidgets-index.html) documenta componentes, estilos e layouts; \u005bQtTest\u005d(https://doc.qt.io/qt-6.8/qtest-overview.html) sustenta testes de eventos da interface. Consultados em2026-10-26. Nenhuma janela foi executada nesta autoria.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1013/r1-widgets-interface.md",
    "line": 59,
    "target": "requirements/1214/r1-ui-state-recovery.md",
    "reference": "../../requirements/1214/r1-ui-state-recovery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1211\u005d(../../requirements/1211/r1-localized-input.md), \u005b1212\u005d(../../requirements/1212/r1-rate-presentation.md), \u005b1213\u005d(../../requirements/1213/r1-comparison-presentation.md), \u005b1214\u005d(../../requirements/1214/r1-ui-state-recovery.md), \u005b1215\u005d(../../requirements/1215/r1-keyboard-navigation.md), \u005b1216\u005d(../../requirements/1216/r1-resize-access.md), \u005b1217\u005d(../../requirements/1217/r1-model-help.md). \u005bQtWidgets\u005d(https://doc.qt.io/qt-6.8/qtwidgets-index.html) documenta componentes, estilos e layouts; \u005bQtTest\u005d(https://doc.qt.io/qt-6.8/qtest-overview.html) sustenta testes de eventos da interface. Consultados em2026-10-26. Nenhuma janela foi executada nesta autoria.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1013/r1-widgets-interface.md",
    "line": 59,
    "target": "requirements/1215/r1-keyboard-navigation.md",
    "reference": "../../requirements/1215/r1-keyboard-navigation.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1211\u005d(../../requirements/1211/r1-localized-input.md), \u005b1212\u005d(../../requirements/1212/r1-rate-presentation.md), \u005b1213\u005d(../../requirements/1213/r1-comparison-presentation.md), \u005b1214\u005d(../../requirements/1214/r1-ui-state-recovery.md), \u005b1215\u005d(../../requirements/1215/r1-keyboard-navigation.md), \u005b1216\u005d(../../requirements/1216/r1-resize-access.md), \u005b1217\u005d(../../requirements/1217/r1-model-help.md). \u005bQtWidgets\u005d(https://doc.qt.io/qt-6.8/qtwidgets-index.html) documenta componentes, estilos e layouts; \u005bQtTest\u005d(https://doc.qt.io/qt-6.8/qtest-overview.html) sustenta testes de eventos da interface. Consultados em2026-10-26. Nenhuma janela foi executada nesta autoria.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1013/r1-widgets-interface.md",
    "line": 59,
    "target": "requirements/1216/r1-resize-access.md",
    "reference": "../../requirements/1216/r1-resize-access.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1211\u005d(../../requirements/1211/r1-localized-input.md), \u005b1212\u005d(../../requirements/1212/r1-rate-presentation.md), \u005b1213\u005d(../../requirements/1213/r1-comparison-presentation.md), \u005b1214\u005d(../../requirements/1214/r1-ui-state-recovery.md), \u005b1215\u005d(../../requirements/1215/r1-keyboard-navigation.md), \u005b1216\u005d(../../requirements/1216/r1-resize-access.md), \u005b1217\u005d(../../requirements/1217/r1-model-help.md). \u005bQtWidgets\u005d(https://doc.qt.io/qt-6.8/qtwidgets-index.html) documenta componentes, estilos e layouts; \u005bQtTest\u005d(https://doc.qt.io/qt-6.8/qtest-overview.html) sustenta testes de eventos da interface. Consultados em2026-10-26. Nenhuma janela foi executada nesta autoria.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1013/r1-widgets-interface.md",
    "line": 59,
    "target": "requirements/1217/r1-model-help.md",
    "reference": "../../requirements/1217/r1-model-help.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1211\u005d(../../requirements/1211/r1-localized-input.md), \u005b1212\u005d(../../requirements/1212/r1-rate-presentation.md), \u005b1213\u005d(../../requirements/1213/r1-comparison-presentation.md), \u005b1214\u005d(../../requirements/1214/r1-ui-state-recovery.md), \u005b1215\u005d(../../requirements/1215/r1-keyboard-navigation.md), \u005b1216\u005d(../../requirements/1216/r1-resize-access.md), \u005b1217\u005d(../../requirements/1217/r1-model-help.md). \u005bQtWidgets\u005d(https://doc.qt.io/qt-6.8/qtwidgets-index.html) documenta componentes, estilos e layouts; \u005bQtTest\u005d(https://doc.qt.io/qt-6.8/qtest-overview.html) sustenta testes de eventos da interface. Consultados em2026-10-26. Nenhuma janela foi executada nesta autoria.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1014/r1-reproducible-delivery.md",
    "line": 67,
    "target": "requirements/1221/r1-build-contract.md",
    "reference": "../../requirements/1221/r1-build-contract.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1221\u005d(../../requirements/1221/r1-build-contract.md), \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md), \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md), \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md), \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md), \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md), \u005b1228\u005d(../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1014/r1-reproducible-delivery.md",
    "line": 67,
    "target": "requirements/1222/r1-core-test-suite.md",
    "reference": "../../requirements/1222/r1-core-test-suite.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1221\u005d(../../requirements/1221/r1-build-contract.md), \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md), \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md), \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md), \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md), \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md), \u005b1228\u005d(../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "specs/1014/r1-reproducible-delivery.md",
    "line": 67,
    "target": "requirements/1223/r1-gui-test-suite.md",
    "reference": "../../requirements/1223/r1-gui-test-suite.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1221\u005d(../../requirements/1221/r1-build-contract.md), \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md), \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md), \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md), \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md), \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md), \u005b1228\u005d(../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "specs/1014/r1-reproducible-delivery.md",
    "line": 67,
    "target": "requirements/1224/r1-ci-evidence.md",
    "reference": "../../requirements/1224/r1-ci-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1221\u005d(../../requirements/1221/r1-build-contract.md), \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md), \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md), \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md), \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md), \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md), \u005b1228\u005d(../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  },
  {
    "source": "specs/1014/r1-reproducible-delivery.md",
    "line": 67,
    "target": "requirements/1225/r1-runtime-packages.md",
    "reference": "../../requirements/1225/r1-runtime-packages.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1221\u005d(../../requirements/1221/r1-build-contract.md), \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md), \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md), \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md), \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md), \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md), \u005b1228\u005d(../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1014/r1-reproducible-delivery.md",
    "line": 67,
    "target": "requirements/1226/r1-native-smoke.md",
    "reference": "../../requirements/1226/r1-native-smoke.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1221\u005d(../../requirements/1221/r1-build-contract.md), \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md), \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md), \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md), \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md), \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md), \u005b1228\u005d(../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1014/r1-reproducible-delivery.md",
    "line": 67,
    "target": "requirements/1227/r1-technical-documentation.md",
    "reference": "../../requirements/1227/r1-technical-documentation.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1221\u005d(../../requirements/1221/r1-build-contract.md), \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md), \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md), \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md), \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md), \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md), \u005b1228\u005d(../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "specs/1014/r1-reproducible-delivery.md",
    "line": 67,
    "target": "requirements/1228/r1-distribution-notices.md",
    "reference": "../../requirements/1228/r1-distribution-notices.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1221\u005d(../../requirements/1221/r1-build-contract.md), \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md), \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md), \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md), \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md), \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md), \u005b1228\u005d(../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Preserve source and approved-design context while refining its unaccepted requirement body."
  },
  {
    "source": "tools/2302/r1-googletest-runner.md",
    "line": 22,
    "target": "requirements/1222/r1-core-test-suite.md",
    "reference": "../../requirements/1222/r1-core-test-suite.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Google Test 1.17.0 é o meio selecionado no design para verificar comportamento financeiro. A prescrição antes colocada em \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md) migra para este cartão e para referências dos futuros planos; os critérios financeiros permanecem nos requisitos de produto. Fontes: \u005bspec 1014\u005d(../../specs/1014/r1-reproducible-delivery.md) e \u005b1017\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Preserve exact source relation and original rejected method record."
  }
]
```

### Declarações atuais e relações adicionadas

```json
[
  {
    "source": "decisions/1018/r1-requirement-conformance-correction.md",
    "line": 38,
    "target": "requirements/1222/r1-core-test-suite.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md) | obsolete; corpo histórico intacto | \u005b2302: execução de testes do núcleo\u005d(../../tools/2302/r1-googletest-runner.md) | \u005b1101\u005d(../../requirements/1101/r1-explicit-rate-kind.md) a 1106 e \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md) a 1207 continuam os oráculos do núcleo |",
    "disposition": "add",
    "scope": "historical",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "decisions/1018/r1-requirement-conformance-correction.md",
    "line": 38,
    "target": "requirements/1101/r1-explicit-rate-kind.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md) | obsolete; corpo histórico intacto | \u005b2302: execução de testes do núcleo\u005d(../../tools/2302/r1-googletest-runner.md) | \u005b1101\u005d(../../requirements/1101/r1-explicit-rate-kind.md) a 1106 e \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md) a 1207 continuam os oráculos do núcleo |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "decisions/1018/r1-requirement-conformance-correction.md",
    "line": 38,
    "target": "requirements/1201/r1-loan-domain.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md) | obsolete; corpo histórico intacto | \u005b2302: execução de testes do núcleo\u005d(../../tools/2302/r1-googletest-runner.md) | \u005b1101\u005d(../../requirements/1101/r1-explicit-rate-kind.md) a 1106 e \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md) a 1207 continuam os oráculos do núcleo |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "decisions/1018/r1-requirement-conformance-correction.md",
    "line": 39,
    "target": "requirements/1223/r1-gui-test-suite.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md) | obsolete; corpo histórico intacto | \u005b2303: execução de testes da interface\u005d(../../tools/2303/r1-qttest-runner.md) | \u005b1211\u005d(../../requirements/1211/r1-localized-input.md) a 1217 preservam a entrada, apresentação e uso da interface |",
    "disposition": "add",
    "scope": "historical",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "decisions/1018/r1-requirement-conformance-correction.md",
    "line": 39,
    "target": "requirements/1211/r1-localized-input.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md) | obsolete; corpo histórico intacto | \u005b2303: execução de testes da interface\u005d(../../tools/2303/r1-qttest-runner.md) | \u005b1211\u005d(../../requirements/1211/r1-localized-input.md) a 1217 preservam a entrada, apresentação e uso da interface |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "decisions/1018/r1-requirement-conformance-correction.md",
    "line": 40,
    "target": "requirements/1224/r1-ci-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md) | obsolete; corpo histórico intacto | \u005b2304: automação de integração\u005d(../../tools/2304/r1-github-actions.md) | \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md) e \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md) preservam pacote utilizável, operação nas plataformas e relatório com evidência |",
    "disposition": "add",
    "scope": "historical",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "decisions/1018/r1-requirement-conformance-correction.md",
    "line": 40,
    "target": "requirements/1225/r1-runtime-packages.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md) | obsolete; corpo histórico intacto | \u005b2304: automação de integração\u005d(../../tools/2304/r1-github-actions.md) | \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md) e \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md) preservam pacote utilizável, operação nas plataformas e relatório com evidência |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "decisions/1018/r1-requirement-conformance-correction.md",
    "line": 40,
    "target": "requirements/1226/r1-native-smoke.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md) | obsolete; corpo histórico intacto | \u005b2304: automação de integração\u005d(../../tools/2304/r1-github-actions.md) | \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md) e \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md) preservam pacote utilizável, operação nas plataformas e relatório com evidência |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "decisions/1018/r1-requirement-conformance-correction.md",
    "line": 40,
    "target": "requirements/1227/r1-technical-documentation.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md) | obsolete; corpo histórico intacto | \u005b2304: automação de integração\u005d(../../tools/2304/r1-github-actions.md) | \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md) e \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md) preservam pacote utilizável, operação nas plataformas e relatório com evidência |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 39,
    "target": "requirements/1101/r1-explicit-rate-kind.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1101 r1\u005d(../../requirements/1101/r1-explicit-rate-kind.md) | Convenção explícita da taxa anual | Unidade |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 40,
    "target": "requirements/1102/r1-nominal-monthly.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1102 r1\u005d(../../requirements/1102/r1-nominal-monthly.md) | Conversão nominal anual para efetiva mensal | Unidade |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 41,
    "target": "requirements/1103/r1-effective-monthly.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1103 r1\u005d(../../requirements/1103/r1-effective-monthly.md) | Conversão efetiva anual para efetiva mensal | Unidade |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 42,
    "target": "requirements/1104/r1-annual-equivalents.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1104 r1\u005d(../../requirements/1104/r1-annual-equivalents.md) | Equivalentes anuais da taxa normalizada | Unidade |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 43,
    "target": "requirements/1105/r1-invalid-rate-input.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1105 r1\u005d(../../requirements/1105/r1-invalid-rate-input.md) | Rejeição de percentual anual inválido | Unidade |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 44,
    "target": "requirements/1106/r1-unrounded-consumer-rate.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1106 r1\u005d(../../requirements/1106/r1-unrounded-consumer-rate.md) | Preservação da taxa entre normalização e cálculo | Integração |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 45,
    "target": "requirements/1201/r1-loan-domain.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1201 r1\u005d(../../requirements/1201/r1-loan-domain.md) | Validação do domínio do financiamento | Unidade |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 46,
    "target": "requirements/1202/r1-price-ledger.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1202 r1\u005d(../../requirements/1202/r1-price-ledger.md) | Pagamentos Price em centavos | Unidade |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 47,
    "target": "requirements/1203/r1-sac-ledger.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1203 r1\u005d(../../requirements/1203/r1-sac-ledger.md) | Amortização SAC com distribuição do resto | Unidade |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 48,
    "target": "requirements/1204/r1-money-invariants.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1204 r1\u005d(../../requirements/1204/r1-money-invariants.md) | Conservação dos saldos e totais | Unidade |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 49,
    "target": "requirements/1205/r1-zero-and-single-period.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1205 r1\u005d(../../requirements/1205/r1-zero-and-single-period.md) | Cálculo nos casos de juros zero e prazo único | Unidade |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 50,
    "target": "requirements/1206/r1-cent-precision-errors.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1206 r1\u005d(../../requirements/1206/r1-cent-precision-errors.md) | Rejeição de combinações inviáveis em centavos | Unidade |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 51,
    "target": "requirements/1207/r1-comparable-results.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1207 r1\u005d(../../requirements/1207/r1-comparable-results.md) | Comparação sob as mesmas condições financeiras | Integração |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 52,
    "target": "requirements/1211/r1-localized-input.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1211 r1\u005d(../../requirements/1211/r1-localized-input.md) | Interpretação dos campos em pt-BR | Integração |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 53,
    "target": "requirements/1212/r1-rate-presentation.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1212 r1\u005d(../../requirements/1212/r1-rate-presentation.md) | Apresentação das taxas com tipo e período | Integração |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 54,
    "target": "requirements/1213/r1-comparison-presentation.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1213 r1\u005d(../../requirements/1213/r1-comparison-presentation.md) | Apresentação da comparação e do prazo efetivo | Sistema |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 55,
    "target": "requirements/1214/r1-ui-state-recovery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1214 r1\u005d(../../requirements/1214/r1-ui-state-recovery.md) | Coerência entre edição, validação e resultados | Integração |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 56,
    "target": "requirements/1215/r1-keyboard-navigation.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1215 r1\u005d(../../requirements/1215/r1-keyboard-navigation.md) | Operação por teclado | Sistema |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 57,
    "target": "requirements/1216/r1-resize-access.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1216 r1\u005d(../../requirements/1216/r1-resize-access.md) | Acesso ao conteúdo com redimensionamento | Sistema |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 58,
    "target": "requirements/1217/r1-model-help.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1217 r1\u005d(../../requirements/1217/r1-model-help.md) | Ajuda local sobre o modelo | Sistema |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 59,
    "target": "requirements/1221/r1-build-contract.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1221 r1\u005d(../../requirements/1221/r1-build-contract.md) | Independência do núcleo financeiro | Integração |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 60,
    "target": "requirements/1225/r1-runtime-packages.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1225 r1\u005d(../../requirements/1225/r1-runtime-packages.md) | Pacotes utilizáveis pelo usuário final | Sistema |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 61,
    "target": "requirements/1226/r1-native-smoke.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1226 r1\u005d(../../requirements/1226/r1-native-smoke.md) | Operação completa nas duas plataformas | Sistema |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 62,
    "target": "requirements/1227/r1-technical-documentation.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1227 r1\u005d(../../requirements/1227/r1-technical-documentation.md) | Documentação de uso e relatório técnico | Sistema |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 63,
    "target": "requirements/1228/r1-distribution-notices.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1228 r1\u005d(../../requirements/1228/r1-distribution-notices.md) | Avisos e licenças dos materiais distribuídos | Sistema |",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 69,
    "target": "requirements/1222/r1-core-test-suite.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md) | obsolete; corpo intacto | \u005b2302: executor de testes do núcleo\u005d(../../tools/2302/r1-googletest-runner.md) | Plano de testes/verificação do núcleo |",
    "disposition": "add",
    "scope": "historical",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 70,
    "target": "requirements/1223/r1-gui-test-suite.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md) | obsolete; corpo intacto | \u005b2303: executor de testes da interface\u005d(../../tools/2303/r1-qttest-runner.md) | Plano de testes/verificação de interface |",
    "disposition": "add",
    "scope": "historical",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "documents/1015/r2-refined-requirement-index.md",
    "line": 71,
    "target": "requirements/1224/r1-ci-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "| \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md) | obsolete; corpo intacto | \u005b2304: integração automatizada\u005d(../../tools/2304/r1-github-actions.md) | Planos de implementação e verificação da automação |",
    "disposition": "add",
    "scope": "historical",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1101/r1-explicit-rate-kind.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1101/r1-explicit-rate-kind.md",
    "line": 29,
    "target": "decisions/1007/r1-rate-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1101/r1-explicit-rate-kind.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1101/r1-explicit-rate-kind.md",
    "line": 31,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1101/r1-explicit-rate-kind.md",
    "line": 60,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1101/r1-explicit-rate-kind.md",
    "line": 60,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1101/r1-explicit-rate-kind.md",
    "line": 60,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1102/r1-nominal-monthly.md",
    "line": 28,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1102/r1-nominal-monthly.md",
    "line": 28,
    "target": "decisions/1007/r1-rate-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1102/r1-nominal-monthly.md",
    "line": 28,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1102/r1-nominal-monthly.md",
    "line": 30,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1102/r1-nominal-monthly.md",
    "line": 59,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1102/r1-nominal-monthly.md",
    "line": 59,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1102/r1-nominal-monthly.md",
    "line": 59,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1103/r1-effective-monthly.md",
    "line": 27,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1103/r1-effective-monthly.md",
    "line": 27,
    "target": "decisions/1007/r1-rate-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1103/r1-effective-monthly.md",
    "line": 27,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1103/r1-effective-monthly.md",
    "line": 29,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1103/r1-effective-monthly.md",
    "line": 58,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1103/r1-effective-monthly.md",
    "line": 58,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1103/r1-effective-monthly.md",
    "line": 58,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1104/r1-annual-equivalents.md",
    "line": 28,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1104/r1-annual-equivalents.md",
    "line": 28,
    "target": "decisions/1007/r1-rate-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1104/r1-annual-equivalents.md",
    "line": 28,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1104/r1-annual-equivalents.md",
    "line": 30,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1104/r1-annual-equivalents.md",
    "line": 60,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1104/r1-annual-equivalents.md",
    "line": 60,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1104/r1-annual-equivalents.md",
    "line": 60,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1105/r1-invalid-rate-input.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1105/r1-invalid-rate-input.md",
    "line": 29,
    "target": "decisions/1007/r1-rate-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1105/r1-invalid-rate-input.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1105/r1-invalid-rate-input.md",
    "line": 31,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1105/r1-invalid-rate-input.md",
    "line": 60,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1105/r1-invalid-rate-input.md",
    "line": 60,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1105/r1-invalid-rate-input.md",
    "line": 60,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1106/r1-unrounded-consumer-rate.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1106/r1-unrounded-consumer-rate.md",
    "line": 29,
    "target": "decisions/1007/r1-rate-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1106/r1-unrounded-consumer-rate.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005binclusão de nominal e efetiva em 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), com convenções e tolerâncias de \u005b1007 r1\u005d(../../decisions/1007/r1-rate-design-basis.md), aceitas na aprovação do design registrada em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1106/r1-unrounded-consumer-rate.md",
    "line": 31,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1106/r1-unrounded-consumer-rate.md",
    "line": 60,
    "target": "specs/1008/r1-annual-rate-conversion.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1106/r1-unrounded-consumer-rate.md",
    "line": 60,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1106/r1-unrounded-consumer-rate.md",
    "line": 60,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1008 r1\u005d(../../specs/1008/r1-annual-rate-conversion.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1201/r1-loan-domain.md",
    "line": 29,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1201/r1-loan-domain.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1201/r1-loan-domain.md",
    "line": 29,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1201/r1-loan-domain.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1201/r1-loan-domain.md",
    "line": 29,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1201/r1-loan-domain.md",
    "line": 31,
    "target": "specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1201/r1-loan-domain.md",
    "line": 61,
    "target": "specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1201/r1-loan-domain.md",
    "line": 61,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1201/r1-loan-domain.md",
    "line": 61,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1202/r1-price-ledger.md",
    "line": 29,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1202/r1-price-ledger.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1202/r1-price-ledger.md",
    "line": 29,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1202/r1-price-ledger.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1202/r1-price-ledger.md",
    "line": 29,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1202/r1-price-ledger.md",
    "line": 31,
    "target": "specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1202/r1-price-ledger.md",
    "line": 61,
    "target": "specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1202/r1-price-ledger.md",
    "line": 61,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1202/r1-price-ledger.md",
    "line": 61,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1203/r1-sac-ledger.md",
    "line": 28,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1203/r1-sac-ledger.md",
    "line": 28,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1203/r1-sac-ledger.md",
    "line": 28,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1203/r1-sac-ledger.md",
    "line": 28,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1203/r1-sac-ledger.md",
    "line": 28,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1203/r1-sac-ledger.md",
    "line": 30,
    "target": "specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1203/r1-sac-ledger.md",
    "line": 60,
    "target": "specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1203/r1-sac-ledger.md",
    "line": 60,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1203/r1-sac-ledger.md",
    "line": 60,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1204/r1-money-invariants.md",
    "line": 29,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1204/r1-money-invariants.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1204/r1-money-invariants.md",
    "line": 29,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1204/r1-money-invariants.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1204/r1-money-invariants.md",
    "line": 29,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1204/r1-money-invariants.md",
    "line": 31,
    "target": "specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1204/r1-money-invariants.md",
    "line": 61,
    "target": "specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1204/r1-money-invariants.md",
    "line": 61,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1204/r1-money-invariants.md",
    "line": 61,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1205/r1-zero-and-single-period.md",
    "line": 29,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1205/r1-zero-and-single-period.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1205/r1-zero-and-single-period.md",
    "line": 29,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1205/r1-zero-and-single-period.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1205/r1-zero-and-single-period.md",
    "line": 29,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1205/r1-zero-and-single-period.md",
    "line": 31,
    "target": "specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1205/r1-zero-and-single-period.md",
    "line": 60,
    "target": "specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1205/r1-zero-and-single-period.md",
    "line": 60,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1205/r1-zero-and-single-period.md",
    "line": 60,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1206/r1-cent-precision-errors.md",
    "line": 28,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1206/r1-cent-precision-errors.md",
    "line": 28,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1206/r1-cent-precision-errors.md",
    "line": 28,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1206/r1-cent-precision-errors.md",
    "line": 28,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1206/r1-cent-precision-errors.md",
    "line": 28,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1206/r1-cent-precision-errors.md",
    "line": 30,
    "target": "specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1206/r1-cent-precision-errors.md",
    "line": 59,
    "target": "specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1206/r1-cent-precision-errors.md",
    "line": 59,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1206/r1-cent-precision-errors.md",
    "line": 59,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1207/r1-comparable-results.md",
    "line": 27,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1207/r1-comparable-results.md",
    "line": 27,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1207/r1-comparable-results.md",
    "line": 27,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1207/r1-comparable-results.md",
    "line": 27,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1207/r1-comparable-results.md",
    "line": 27,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1207/r1-comparable-results.md",
    "line": 29,
    "target": "specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1207/r1-comparable-results.md",
    "line": 59,
    "target": "specs/1012/r1-amortization-comparison.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1207/r1-comparable-results.md",
    "line": 59,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1207/r1-comparable-results.md",
    "line": 59,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1012 r1\u005d(../../specs/1012/r1-amortization-comparison.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1211/r1-localized-input.md",
    "line": 29,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1211/r1-localized-input.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1211/r1-localized-input.md",
    "line": 29,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1211/r1-localized-input.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1211/r1-localized-input.md",
    "line": 29,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1211/r1-localized-input.md",
    "line": 31,
    "target": "specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1211/r1-localized-input.md",
    "line": 61,
    "target": "specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1211/r1-localized-input.md",
    "line": 61,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1211/r1-localized-input.md",
    "line": 61,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1212/r1-rate-presentation.md",
    "line": 29,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1212/r1-rate-presentation.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1212/r1-rate-presentation.md",
    "line": 29,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1212/r1-rate-presentation.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1212/r1-rate-presentation.md",
    "line": 29,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1212/r1-rate-presentation.md",
    "line": 31,
    "target": "specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1212/r1-rate-presentation.md",
    "line": 61,
    "target": "specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1212/r1-rate-presentation.md",
    "line": 61,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1212/r1-rate-presentation.md",
    "line": 61,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1213/r1-comparison-presentation.md",
    "line": 29,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1213/r1-comparison-presentation.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1213/r1-comparison-presentation.md",
    "line": 29,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1213/r1-comparison-presentation.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1213/r1-comparison-presentation.md",
    "line": 29,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1213/r1-comparison-presentation.md",
    "line": 31,
    "target": "specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1213/r1-comparison-presentation.md",
    "line": 61,
    "target": "specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1213/r1-comparison-presentation.md",
    "line": 61,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1213/r1-comparison-presentation.md",
    "line": 61,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1214/r1-ui-state-recovery.md",
    "line": 29,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1214/r1-ui-state-recovery.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1214/r1-ui-state-recovery.md",
    "line": 29,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1214/r1-ui-state-recovery.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1214/r1-ui-state-recovery.md",
    "line": 29,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1214/r1-ui-state-recovery.md",
    "line": 31,
    "target": "specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1214/r1-ui-state-recovery.md",
    "line": 63,
    "target": "specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1214/r1-ui-state-recovery.md",
    "line": 63,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1214/r1-ui-state-recovery.md",
    "line": 63,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1215/r1-keyboard-navigation.md",
    "line": 28,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1215/r1-keyboard-navigation.md",
    "line": 28,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1215/r1-keyboard-navigation.md",
    "line": 28,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1215/r1-keyboard-navigation.md",
    "line": 28,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1215/r1-keyboard-navigation.md",
    "line": 28,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1215/r1-keyboard-navigation.md",
    "line": 30,
    "target": "specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1215/r1-keyboard-navigation.md",
    "line": 60,
    "target": "specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1215/r1-keyboard-navigation.md",
    "line": 60,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1215/r1-keyboard-navigation.md",
    "line": 60,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1216/r1-resize-access.md",
    "line": 29,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1216/r1-resize-access.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1216/r1-resize-access.md",
    "line": 29,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1216/r1-resize-access.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1216/r1-resize-access.md",
    "line": 29,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1216/r1-resize-access.md",
    "line": 31,
    "target": "specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1216/r1-resize-access.md",
    "line": 60,
    "target": "specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1216/r1-resize-access.md",
    "line": 60,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1216/r1-resize-access.md",
    "line": 60,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1217/r1-model-help.md",
    "line": 29,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1217/r1-model-help.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1217/r1-model-help.md",
    "line": 29,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1217/r1-model-help.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1217/r1-model-help.md",
    "line": 29,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1217/r1-model-help.md",
    "line": 31,
    "target": "specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1217/r1-model-help.md",
    "line": 61,
    "target": "specs/1013/r1-widgets-interface.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1217/r1-model-help.md",
    "line": 61,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1217/r1-model-help.md",
    "line": 61,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1013 r1\u005d(../../specs/1013/r1-widgets-interface.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1221/r1-build-contract.md",
    "line": 29,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1221/r1-build-contract.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1221/r1-build-contract.md",
    "line": 29,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1221/r1-build-contract.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1221/r1-build-contract.md",
    "line": 29,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1221/r1-build-contract.md",
    "line": 31,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1221/r1-build-contract.md",
    "line": 60,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1221/r1-build-contract.md",
    "line": 60,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1221/r1-build-contract.md",
    "line": 60,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1222/r1-core-test-suite.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1222/r1-core-test-suite.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1222/r1-core-test-suite.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1222/r1-core-test-suite.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1222/r1-core-test-suite.md",
    "line": 24,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1223/r1-gui-test-suite.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1223/r1-gui-test-suite.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1223/r1-gui-test-suite.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1223/r1-gui-test-suite.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1223/r1-gui-test-suite.md",
    "line": 24,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1224/r1-ci-evidence.md",
    "line": 24,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1224/r1-ci-evidence.md",
    "line": 24,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1224/r1-ci-evidence.md",
    "line": 24,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1224/r1-ci-evidence.md",
    "line": 24,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1224/r1-ci-evidence.md",
    "line": 24,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Fonte humana: \u005b1001\u005d(../../documents/1001/r1-human-request.md), \u005b1002\u005d(../../documents/1002/r1-image-evidence.md) e \u005b1005\u005d(../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: \u005bdecisão1011\u005d(../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: \u005bspec1014\u005d(../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1225/r1-runtime-packages.md",
    "line": 28,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1225/r1-runtime-packages.md",
    "line": 28,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1225/r1-runtime-packages.md",
    "line": 28,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1225/r1-runtime-packages.md",
    "line": 28,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1225/r1-runtime-packages.md",
    "line": 28,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1225/r1-runtime-packages.md",
    "line": 30,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1225/r1-runtime-packages.md",
    "line": 60,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1225/r1-runtime-packages.md",
    "line": 60,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1225/r1-runtime-packages.md",
    "line": 60,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1226/r1-native-smoke.md",
    "line": 29,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1226/r1-native-smoke.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1226/r1-native-smoke.md",
    "line": 29,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1226/r1-native-smoke.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1226/r1-native-smoke.md",
    "line": 29,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1226/r1-native-smoke.md",
    "line": 31,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1226/r1-native-smoke.md",
    "line": 61,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1226/r1-native-smoke.md",
    "line": 61,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1226/r1-native-smoke.md",
    "line": 61,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1227/r1-technical-documentation.md",
    "line": 29,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bentregável de relatório técnico da imagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md), \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1227/r1-technical-documentation.md",
    "line": 29,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bentregável de relatório técnico da imagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md), \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1227/r1-technical-documentation.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bentregável de relatório técnico da imagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md), \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1227/r1-technical-documentation.md",
    "line": 29,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bentregável de relatório técnico da imagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md), \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1227/r1-technical-documentation.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bentregável de relatório técnico da imagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md), \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1227/r1-technical-documentation.md",
    "line": 31,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1227/r1-technical-documentation.md",
    "line": 61,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1227/r1-technical-documentation.md",
    "line": 61,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1227/r1-technical-documentation.md",
    "line": 61,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1228/r1-distribution-notices.md",
    "line": 29,
    "target": "documents/1001/r1-human-request.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1228/r1-distribution-notices.md",
    "line": 29,
    "target": "documents/1005/r1-human-scope-approval.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1228/r1-distribution-notices.md",
    "line": 29,
    "target": "decisions/1011/r1-complete-design-basis.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1228/r1-distribution-notices.md",
    "line": 29,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1228/r1-distribution-notices.md",
    "line": 29,
    "target": "documents/1002/r1-image-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Origem:** \u005bpedido humano 1001 r1\u005d(../../documents/1001/r1-human-request.md) e \u005bescolhas humanas 1005 r1\u005d(../../documents/1005/r1-human-scope-approval.md), detalhados na \u005bdecisão de design 1011 r1\u005d(../../decisions/1011/r1-complete-design-basis.md) e aprovados em \u005b1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: \u005bimagem 1002 r1\u005d(../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1228/r1-distribution-notices.md",
    "line": 31,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "**Fronteira:** \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1228/r1-distribution-notices.md",
    "line": 61,
    "target": "specs/1014/r1-reproducible-delivery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "requirements/1228/r1-distribution-notices.md",
    "line": 61,
    "target": "documents/1017/r1-design-approval-and-quality-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "requirements/1228/r1-distribution-notices.md",
    "line": 61,
    "target": "decisions/1018/r1-requirement-conformance-correction.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Related: \u005b1014 r1\u005d(../../specs/1014/r1-reproducible-delivery.md); \u005bcorreção autorizada 1017 r1\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md); \u005bdecisão de correção 1018 r1\u005d(../../decisions/1018/r1-requirement-conformance-correction.md).",
    "disposition": "add",
    "scope": "current",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "specs/1008/r1-annual-rate-conversion.md",
    "line": 53,
    "target": "requirements/1101/r1-explicit-rate-kind.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos candidatos: \u005b1101 tipo explícito\u005d(../../requirements/1101/r1-explicit-rate-kind.md), \u005b1102 nominal mensal\u005d(../../requirements/1102/r1-nominal-monthly.md), \u005b1103 efetiva mensal\u005d(../../requirements/1103/r1-effective-monthly.md), \u005b1104 equivalentes anuais\u005d(../../requirements/1104/r1-annual-equivalents.md), \u005b1105 entrada inválida\u005d(../../requirements/1105/r1-invalid-rate-input.md), \u005b1106 taxa integral ao consumidor\u005d(../../requirements/1106/r1-unrounded-consumer-rate.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1008/r1-annual-rate-conversion.md",
    "line": 53,
    "target": "requirements/1102/r1-nominal-monthly.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos candidatos: \u005b1101 tipo explícito\u005d(../../requirements/1101/r1-explicit-rate-kind.md), \u005b1102 nominal mensal\u005d(../../requirements/1102/r1-nominal-monthly.md), \u005b1103 efetiva mensal\u005d(../../requirements/1103/r1-effective-monthly.md), \u005b1104 equivalentes anuais\u005d(../../requirements/1104/r1-annual-equivalents.md), \u005b1105 entrada inválida\u005d(../../requirements/1105/r1-invalid-rate-input.md), \u005b1106 taxa integral ao consumidor\u005d(../../requirements/1106/r1-unrounded-consumer-rate.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1008/r1-annual-rate-conversion.md",
    "line": 53,
    "target": "requirements/1103/r1-effective-monthly.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos candidatos: \u005b1101 tipo explícito\u005d(../../requirements/1101/r1-explicit-rate-kind.md), \u005b1102 nominal mensal\u005d(../../requirements/1102/r1-nominal-monthly.md), \u005b1103 efetiva mensal\u005d(../../requirements/1103/r1-effective-monthly.md), \u005b1104 equivalentes anuais\u005d(../../requirements/1104/r1-annual-equivalents.md), \u005b1105 entrada inválida\u005d(../../requirements/1105/r1-invalid-rate-input.md), \u005b1106 taxa integral ao consumidor\u005d(../../requirements/1106/r1-unrounded-consumer-rate.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1008/r1-annual-rate-conversion.md",
    "line": 53,
    "target": "requirements/1104/r1-annual-equivalents.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos candidatos: \u005b1101 tipo explícito\u005d(../../requirements/1101/r1-explicit-rate-kind.md), \u005b1102 nominal mensal\u005d(../../requirements/1102/r1-nominal-monthly.md), \u005b1103 efetiva mensal\u005d(../../requirements/1103/r1-effective-monthly.md), \u005b1104 equivalentes anuais\u005d(../../requirements/1104/r1-annual-equivalents.md), \u005b1105 entrada inválida\u005d(../../requirements/1105/r1-invalid-rate-input.md), \u005b1106 taxa integral ao consumidor\u005d(../../requirements/1106/r1-unrounded-consumer-rate.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1008/r1-annual-rate-conversion.md",
    "line": 53,
    "target": "requirements/1105/r1-invalid-rate-input.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos candidatos: \u005b1101 tipo explícito\u005d(../../requirements/1101/r1-explicit-rate-kind.md), \u005b1102 nominal mensal\u005d(../../requirements/1102/r1-nominal-monthly.md), \u005b1103 efetiva mensal\u005d(../../requirements/1103/r1-effective-monthly.md), \u005b1104 equivalentes anuais\u005d(../../requirements/1104/r1-annual-equivalents.md), \u005b1105 entrada inválida\u005d(../../requirements/1105/r1-invalid-rate-input.md), \u005b1106 taxa integral ao consumidor\u005d(../../requirements/1106/r1-unrounded-consumer-rate.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1008/r1-annual-rate-conversion.md",
    "line": 53,
    "target": "requirements/1106/r1-unrounded-consumer-rate.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos candidatos: \u005b1101 tipo explícito\u005d(../../requirements/1101/r1-explicit-rate-kind.md), \u005b1102 nominal mensal\u005d(../../requirements/1102/r1-nominal-monthly.md), \u005b1103 efetiva mensal\u005d(../../requirements/1103/r1-effective-monthly.md), \u005b1104 equivalentes anuais\u005d(../../requirements/1104/r1-annual-equivalents.md), \u005b1105 entrada inválida\u005d(../../requirements/1105/r1-invalid-rate-input.md), \u005b1106 taxa integral ao consumidor\u005d(../../requirements/1106/r1-unrounded-consumer-rate.md).",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1012/r1-amortization-comparison.md",
    "line": 62,
    "target": "requirements/1201/r1-loan-domain.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md), \u005b1202\u005d(../../requirements/1202/r1-price-ledger.md), \u005b1203\u005d(../../requirements/1203/r1-sac-ledger.md), \u005b1204\u005d(../../requirements/1204/r1-money-invariants.md), \u005b1205\u005d(../../requirements/1205/r1-zero-and-single-period.md), \u005b1206\u005d(../../requirements/1206/r1-cent-precision-errors.md), \u005b1207\u005d(../../requirements/1207/r1-comparable-results.md). Somente rascunho; nenhum plano, implementação ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1012/r1-amortization-comparison.md",
    "line": 62,
    "target": "requirements/1202/r1-price-ledger.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md), \u005b1202\u005d(../../requirements/1202/r1-price-ledger.md), \u005b1203\u005d(../../requirements/1203/r1-sac-ledger.md), \u005b1204\u005d(../../requirements/1204/r1-money-invariants.md), \u005b1205\u005d(../../requirements/1205/r1-zero-and-single-period.md), \u005b1206\u005d(../../requirements/1206/r1-cent-precision-errors.md), \u005b1207\u005d(../../requirements/1207/r1-comparable-results.md). Somente rascunho; nenhum plano, implementação ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1012/r1-amortization-comparison.md",
    "line": 62,
    "target": "requirements/1203/r1-sac-ledger.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md), \u005b1202\u005d(../../requirements/1202/r1-price-ledger.md), \u005b1203\u005d(../../requirements/1203/r1-sac-ledger.md), \u005b1204\u005d(../../requirements/1204/r1-money-invariants.md), \u005b1205\u005d(../../requirements/1205/r1-zero-and-single-period.md), \u005b1206\u005d(../../requirements/1206/r1-cent-precision-errors.md), \u005b1207\u005d(../../requirements/1207/r1-comparable-results.md). Somente rascunho; nenhum plano, implementação ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1012/r1-amortization-comparison.md",
    "line": 62,
    "target": "requirements/1204/r1-money-invariants.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md), \u005b1202\u005d(../../requirements/1202/r1-price-ledger.md), \u005b1203\u005d(../../requirements/1203/r1-sac-ledger.md), \u005b1204\u005d(../../requirements/1204/r1-money-invariants.md), \u005b1205\u005d(../../requirements/1205/r1-zero-and-single-period.md), \u005b1206\u005d(../../requirements/1206/r1-cent-precision-errors.md), \u005b1207\u005d(../../requirements/1207/r1-comparable-results.md). Somente rascunho; nenhum plano, implementação ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1012/r1-amortization-comparison.md",
    "line": 62,
    "target": "requirements/1205/r1-zero-and-single-period.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md), \u005b1202\u005d(../../requirements/1202/r1-price-ledger.md), \u005b1203\u005d(../../requirements/1203/r1-sac-ledger.md), \u005b1204\u005d(../../requirements/1204/r1-money-invariants.md), \u005b1205\u005d(../../requirements/1205/r1-zero-and-single-period.md), \u005b1206\u005d(../../requirements/1206/r1-cent-precision-errors.md), \u005b1207\u005d(../../requirements/1207/r1-comparable-results.md). Somente rascunho; nenhum plano, implementação ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1012/r1-amortization-comparison.md",
    "line": 62,
    "target": "requirements/1206/r1-cent-precision-errors.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md), \u005b1202\u005d(../../requirements/1202/r1-price-ledger.md), \u005b1203\u005d(../../requirements/1203/r1-sac-ledger.md), \u005b1204\u005d(../../requirements/1204/r1-money-invariants.md), \u005b1205\u005d(../../requirements/1205/r1-zero-and-single-period.md), \u005b1206\u005d(../../requirements/1206/r1-cent-precision-errors.md), \u005b1207\u005d(../../requirements/1207/r1-comparable-results.md). Somente rascunho; nenhum plano, implementação ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1012/r1-amortization-comparison.md",
    "line": 62,
    "target": "requirements/1207/r1-comparable-results.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1201\u005d(../../requirements/1201/r1-loan-domain.md), \u005b1202\u005d(../../requirements/1202/r1-price-ledger.md), \u005b1203\u005d(../../requirements/1203/r1-sac-ledger.md), \u005b1204\u005d(../../requirements/1204/r1-money-invariants.md), \u005b1205\u005d(../../requirements/1205/r1-zero-and-single-period.md), \u005b1206\u005d(../../requirements/1206/r1-cent-precision-errors.md), \u005b1207\u005d(../../requirements/1207/r1-comparable-results.md). Somente rascunho; nenhum plano, implementação ou verdict de teste.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1013/r1-widgets-interface.md",
    "line": 59,
    "target": "requirements/1211/r1-localized-input.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1211\u005d(../../requirements/1211/r1-localized-input.md), \u005b1212\u005d(../../requirements/1212/r1-rate-presentation.md), \u005b1213\u005d(../../requirements/1213/r1-comparison-presentation.md), \u005b1214\u005d(../../requirements/1214/r1-ui-state-recovery.md), \u005b1215\u005d(../../requirements/1215/r1-keyboard-navigation.md), \u005b1216\u005d(../../requirements/1216/r1-resize-access.md), \u005b1217\u005d(../../requirements/1217/r1-model-help.md). \u005bQtWidgets\u005d(https://doc.qt.io/qt-6.8/qtwidgets-index.html) documenta componentes, estilos e layouts; \u005bQtTest\u005d(https://doc.qt.io/qt-6.8/qtest-overview.html) sustenta testes de eventos da interface. Consultados em2026-10-26. Nenhuma janela foi executada nesta autoria.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1013/r1-widgets-interface.md",
    "line": 59,
    "target": "requirements/1212/r1-rate-presentation.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1211\u005d(../../requirements/1211/r1-localized-input.md), \u005b1212\u005d(../../requirements/1212/r1-rate-presentation.md), \u005b1213\u005d(../../requirements/1213/r1-comparison-presentation.md), \u005b1214\u005d(../../requirements/1214/r1-ui-state-recovery.md), \u005b1215\u005d(../../requirements/1215/r1-keyboard-navigation.md), \u005b1216\u005d(../../requirements/1216/r1-resize-access.md), \u005b1217\u005d(../../requirements/1217/r1-model-help.md). \u005bQtWidgets\u005d(https://doc.qt.io/qt-6.8/qtwidgets-index.html) documenta componentes, estilos e layouts; \u005bQtTest\u005d(https://doc.qt.io/qt-6.8/qtest-overview.html) sustenta testes de eventos da interface. Consultados em2026-10-26. Nenhuma janela foi executada nesta autoria.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1013/r1-widgets-interface.md",
    "line": 59,
    "target": "requirements/1213/r1-comparison-presentation.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1211\u005d(../../requirements/1211/r1-localized-input.md), \u005b1212\u005d(../../requirements/1212/r1-rate-presentation.md), \u005b1213\u005d(../../requirements/1213/r1-comparison-presentation.md), \u005b1214\u005d(../../requirements/1214/r1-ui-state-recovery.md), \u005b1215\u005d(../../requirements/1215/r1-keyboard-navigation.md), \u005b1216\u005d(../../requirements/1216/r1-resize-access.md), \u005b1217\u005d(../../requirements/1217/r1-model-help.md). \u005bQtWidgets\u005d(https://doc.qt.io/qt-6.8/qtwidgets-index.html) documenta componentes, estilos e layouts; \u005bQtTest\u005d(https://doc.qt.io/qt-6.8/qtest-overview.html) sustenta testes de eventos da interface. Consultados em2026-10-26. Nenhuma janela foi executada nesta autoria.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1013/r1-widgets-interface.md",
    "line": 59,
    "target": "requirements/1214/r1-ui-state-recovery.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1211\u005d(../../requirements/1211/r1-localized-input.md), \u005b1212\u005d(../../requirements/1212/r1-rate-presentation.md), \u005b1213\u005d(../../requirements/1213/r1-comparison-presentation.md), \u005b1214\u005d(../../requirements/1214/r1-ui-state-recovery.md), \u005b1215\u005d(../../requirements/1215/r1-keyboard-navigation.md), \u005b1216\u005d(../../requirements/1216/r1-resize-access.md), \u005b1217\u005d(../../requirements/1217/r1-model-help.md). \u005bQtWidgets\u005d(https://doc.qt.io/qt-6.8/qtwidgets-index.html) documenta componentes, estilos e layouts; \u005bQtTest\u005d(https://doc.qt.io/qt-6.8/qtest-overview.html) sustenta testes de eventos da interface. Consultados em2026-10-26. Nenhuma janela foi executada nesta autoria.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1013/r1-widgets-interface.md",
    "line": 59,
    "target": "requirements/1215/r1-keyboard-navigation.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1211\u005d(../../requirements/1211/r1-localized-input.md), \u005b1212\u005d(../../requirements/1212/r1-rate-presentation.md), \u005b1213\u005d(../../requirements/1213/r1-comparison-presentation.md), \u005b1214\u005d(../../requirements/1214/r1-ui-state-recovery.md), \u005b1215\u005d(../../requirements/1215/r1-keyboard-navigation.md), \u005b1216\u005d(../../requirements/1216/r1-resize-access.md), \u005b1217\u005d(../../requirements/1217/r1-model-help.md). \u005bQtWidgets\u005d(https://doc.qt.io/qt-6.8/qtwidgets-index.html) documenta componentes, estilos e layouts; \u005bQtTest\u005d(https://doc.qt.io/qt-6.8/qtest-overview.html) sustenta testes de eventos da interface. Consultados em2026-10-26. Nenhuma janela foi executada nesta autoria.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1013/r1-widgets-interface.md",
    "line": 59,
    "target": "requirements/1216/r1-resize-access.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1211\u005d(../../requirements/1211/r1-localized-input.md), \u005b1212\u005d(../../requirements/1212/r1-rate-presentation.md), \u005b1213\u005d(../../requirements/1213/r1-comparison-presentation.md), \u005b1214\u005d(../../requirements/1214/r1-ui-state-recovery.md), \u005b1215\u005d(../../requirements/1215/r1-keyboard-navigation.md), \u005b1216\u005d(../../requirements/1216/r1-resize-access.md), \u005b1217\u005d(../../requirements/1217/r1-model-help.md). \u005bQtWidgets\u005d(https://doc.qt.io/qt-6.8/qtwidgets-index.html) documenta componentes, estilos e layouts; \u005bQtTest\u005d(https://doc.qt.io/qt-6.8/qtest-overview.html) sustenta testes de eventos da interface. Consultados em2026-10-26. Nenhuma janela foi executada nesta autoria.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1013/r1-widgets-interface.md",
    "line": 59,
    "target": "requirements/1217/r1-model-help.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1211\u005d(../../requirements/1211/r1-localized-input.md), \u005b1212\u005d(../../requirements/1212/r1-rate-presentation.md), \u005b1213\u005d(../../requirements/1213/r1-comparison-presentation.md), \u005b1214\u005d(../../requirements/1214/r1-ui-state-recovery.md), \u005b1215\u005d(../../requirements/1215/r1-keyboard-navigation.md), \u005b1216\u005d(../../requirements/1216/r1-resize-access.md), \u005b1217\u005d(../../requirements/1217/r1-model-help.md). \u005bQtWidgets\u005d(https://doc.qt.io/qt-6.8/qtwidgets-index.html) documenta componentes, estilos e layouts; \u005bQtTest\u005d(https://doc.qt.io/qt-6.8/qtest-overview.html) sustenta testes de eventos da interface. Consultados em2026-10-26. Nenhuma janela foi executada nesta autoria.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1014/r1-reproducible-delivery.md",
    "line": 67,
    "target": "requirements/1221/r1-build-contract.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1221\u005d(../../requirements/1221/r1-build-contract.md), \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md), \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md), \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md), \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md), \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md), \u005b1228\u005d(../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1014/r1-reproducible-delivery.md",
    "line": 67,
    "target": "requirements/1222/r1-core-test-suite.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1221\u005d(../../requirements/1221/r1-build-contract.md), \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md), \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md), \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md), \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md), \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md), \u005b1228\u005d(../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1014/r1-reproducible-delivery.md",
    "line": 67,
    "target": "requirements/1223/r1-gui-test-suite.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1221\u005d(../../requirements/1221/r1-build-contract.md), \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md), \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md), \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md), \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md), \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md), \u005b1228\u005d(../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1014/r1-reproducible-delivery.md",
    "line": 67,
    "target": "requirements/1224/r1-ci-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1221\u005d(../../requirements/1221/r1-build-contract.md), \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md), \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md), \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md), \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md), \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md), \u005b1228\u005d(../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1014/r1-reproducible-delivery.md",
    "line": 67,
    "target": "requirements/1225/r1-runtime-packages.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1221\u005d(../../requirements/1221/r1-build-contract.md), \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md), \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md), \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md), \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md), \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md), \u005b1228\u005d(../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1014/r1-reproducible-delivery.md",
    "line": 67,
    "target": "requirements/1226/r1-native-smoke.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1221\u005d(../../requirements/1221/r1-build-contract.md), \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md), \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md), \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md), \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md), \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md), \u005b1228\u005d(../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1014/r1-reproducible-delivery.md",
    "line": 67,
    "target": "requirements/1227/r1-technical-documentation.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1221\u005d(../../requirements/1221/r1-build-contract.md), \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md), \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md), \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md), \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md), \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md), \u005b1228\u005d(../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "specs/1014/r1-reproducible-delivery.md",
    "line": 67,
    "target": "requirements/1228/r1-distribution-notices.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Requisitos: \u005b1221\u005d(../../requirements/1221/r1-build-contract.md), \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md), \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md), \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md), \u005b1225\u005d(../../requirements/1225/r1-runtime-packages.md), \u005b1226\u005d(../../requirements/1226/r1-native-smoke.md), \u005b1227\u005d(../../requirements/1227/r1-technical-documentation.md), \u005b1228\u005d(../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.",
    "disposition": "retain",
    "scope": "current",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "tools/2302/r1-googletest-runner.md",
    "line": 22,
    "target": "requirements/1222/r1-core-test-suite.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Google Test 1.17.0 é o meio selecionado no design para verificar comportamento financeiro. A prescrição antes colocada em \u005b1222\u005d(../../requirements/1222/r1-core-test-suite.md) migra para este cartão e para referências dos futuros planos; os critérios financeiros permanecem nos requisitos de produto. Fontes: \u005bspec 1014\u005d(../../specs/1014/r1-reproducible-delivery.md) e \u005b1017\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md).",
    "disposition": "retain",
    "scope": "historical",
    "reason": "Same source/target documentary relation preserved; line can move during rejected-draft rewrite."
  },
  {
    "source": "tools/2303/r1-qttest-runner.md",
    "line": 21,
    "target": "requirements/1223/r1-gui-test-suite.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Qt Test 6.8.3 é o meio escolhido para os testes de interface, distinto dos oráculos de produto. A prescrição histórica \u005b1223\u005d(../../requirements/1223/r1-gui-test-suite.md) é realocada para este cartão e para futuros planos. A \u005bspec 1014\u005d(../../specs/1014/r1-reproducible-delivery.md) mantém o design aprovado; \u005b1017\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md) exige a correção de classificação.",
    "disposition": "add",
    "scope": "historical",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  },
  {
    "source": "tools/2304/r1-github-actions.md",
    "line": 23,
    "target": "requirements/1224/r1-ci-evidence.md",
    "relation": "citation (documentary Markdown reference; native graph unavailable)",
    "meaning": "Automatizar as rotas de engenharia selecionadas no design; a prescrição histórica \u005b1224\u005d(../../requirements/1224/r1-ci-evidence.md) migra para esta ferramenta e para o plano consumidor. A capacidade de CI não é uma função do aplicativo. Fontes: \u005bspec 1014\u005d(../../specs/1014/r1-reproducible-delivery.md), \u005b1017\u005d(../../documents/1017/r1-design-approval-and-quality-correction.md). Repositório limitado a `paulo-vitor-cs/ceseb`.",
    "disposition": "add",
    "scope": "historical",
    "reason": "New correction-authority, effective coverage or tool-consumer context explicitly linked."
  }
]
```

## Retrieval e cobertura

Consulta lexical executada com root explícito, sessão 1-mortgage-desktop e corpus restrito a requirements/, specs/, documents/ e decisions/. Foram examinadas 42 fontes; os hits incluíram a correção 1017 e fontes pertinentes. Resultado partial, diagnóstico index_incompatible, graph unavailable e body_context partial. Nenhum índice foi reconstruído e nenhum plugin ou fonte protegida foi reparado. Os corpos pertinentes foram lidos diretamente; a enumeração textual acima não é uma observação do grafo mecânico nem cobre fontes fora dessa sessão.

## Verificação mecânica

A conferência de conteúdo precedeu o check de metadados e links. Conjunto observado: 31 corpos verificados, 31 resultados ok. Os três registros obsolete foram verificados quanto a metadados/links, não normalizados para o template de requisito efetivo. Um resultado ok do check não atesta rationale suficiente, atomicidade, aprovação ou satisfação de produto.

## Próximo responsável

Orquestrador: conferir este retorno, atualizar seus registros e conduzir o próximo passo autorizado. Os planos de implementação e verificação ainda não existem; seus autores devem mapear requisitos efetivos às tarefas e referenciar os cartões de ferramentas consumidos. A entrega preserva o aceite da arquitetura, não aprova um plano futuro. Memória própria: session_memory/design/requirement-refinement.yaml.

### Resultados observados de metadados e links

```json
[
  {
    "path": "requirements/1101/r1-explicit-rate-kind.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1102/r1-nominal-monthly.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1103/r1-effective-monthly.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1104/r1-annual-equivalents.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1105/r1-invalid-rate-input.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1106/r1-unrounded-consumer-rate.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1201/r1-loan-domain.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1202/r1-price-ledger.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1203/r1-sac-ledger.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1204/r1-money-invariants.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1205/r1-zero-and-single-period.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1206/r1-cent-precision-errors.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1207/r1-comparable-results.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1211/r1-localized-input.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1212/r1-rate-presentation.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1213/r1-comparison-presentation.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1214/r1-ui-state-recovery.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1215/r1-keyboard-navigation.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1216/r1-resize-access.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1217/r1-model-help.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1221/r1-build-contract.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1222/r1-core-test-suite.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1223/r1-gui-test-suite.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1224/r1-ci-evidence.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1225/r1-runtime-packages.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1226/r1-native-smoke.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1227/r1-technical-documentation.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "requirements/1228/r1-distribution-notices.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "decisions/1018/r1-requirement-conformance-correction.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "documents/1015/r2-refined-requirement-index.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "evidence/requirement-refinement.md",
    "exit": 0,
    "result": "ok",
    "diagnostics": []
  }
]
```
