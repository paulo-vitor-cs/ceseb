---
id: 1017
revision: 1
type: document
tags:
- mortgage
- authority
- requirement-refinement
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Aprovação humana do design acompanhada de rejeição da qualidade dos requisitos
  e pedido de prestação de contas do fluxo.
use_when:
- Distinguir o design aprovado dos requisitos a corrigir e recuperar a autoridade
  desta correção documental.
---
# Aprovação do design e correção dos requisitos

O humano declarou, integralmente:

> O design está aprovado, porém todos requisitos são apenas esboços. estão fora do padrão do template, contem erros de formatação (como números colados em palavras) e não tem Campos como acceptance criteria, rationale ou se requisitos é de unidade, integração ou sistema. Alem disso, tem requisitos que descrevem ferramentas a serem utilizados - isso está errado, na metodologia da mikoshi isso entra como tools e é referenciado no plano, e não em requisitos

A resposta seguinte pediu prestação de contas:

> não esta no fluxo da mikoshi esse refino? qual fase você está? foram feitas pesquisas conforme fluxo?

Interpretação de autoridade: o design apresentado em [1015 r1](../1015/r1-concrete-design-index.md), specs 1008/1012/1013/1014 r1, está aprovado. A qualidade dos requisitos foi rejeitada; eles continuam sem aceite e devem ser corrigidos na fase 4. A aprovação do design não aprova planos ou execução. As escolhas técnicas e funcionais do design permanecem; ferramentas devem ser documentadas como tools e selecionadas por planos, sem virar obrigações de produto.

O refinamento inclui a estrutura integral do template, acceptance criteria e rationale explícitos, nível/classificação em tags e corpo, procedimento e oráculo, rastreabilidade, correção de espaços e revisão do limite entre requisito e ferramenta. Não será solicitado novamente o mesmo aceite de design para corrigir essas falhas.

Evidência do que de fato ocorreu: consultas primárias e aritmética de apoio estão nos relatórios [1009](../../evidence/financial-design.md) e [1016](../../evidence/full-architecture.md). Não foi produzido um pacote de pesquisa com compilação e notas de conhecimento pelo fluxo de research. Checks anteriores validaram metadados/links e não a completude metodológica do corpo. Essa lacuna não é atribuída à indisponibilidade de Context7/Serena.

Os corpos anteriores foram preservados em `evidence/requirements-refinement-preimages.json`. Nenhum código, plano, teste de produto ou nova publicação remota foi autorizado nesta correção.
