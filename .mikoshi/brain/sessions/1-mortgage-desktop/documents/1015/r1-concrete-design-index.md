---
id: 1015
revision: 1
type: document
tags:
- mortgage
- design-index
- human-gate
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Índice das revisões de design, escolhas propostas e pedido de passagem
  da arquitetura ao planejamento.
use_when:
- Revisar o design completo antes de aprovar sua baseline e o início da autoria de
  planos.
---
# Design concreto para revisão — Projeto1

Este documento é um índice de revisão. A arquitetura permanece nas specs exatas abaixo. Todos os corpos são r1 e continuam draft; decisões1007/1011 estão open. A autoria foi autorizada pela [resposta1005](../1005/r1-human-scope-approval.md), sem aprovação antecipada dos corpos.

| Funcionalidade | Revisão a revisar | Requisitos r1 |
|---|---|---|
| Conversão nominal/efetiva anual | [spec1008](../../specs/1008/r1-annual-rate-conversion.md) |1101..1106 |
| Comparação monetária Price/SAC | [spec1012](../../specs/1012/r1-amortization-comparison.md) |1201..1207 |
| Interface Qt Widgets | [spec1013](../../specs/1013/r1-widgets-interface.md) |1211..1217 |
| Entrega nas duas plataformas | [spec1014](../../specs/1014/r1-reproducible-delivery.md) |1221..1228 |

Escolhas humanas preservadas: C++; Windows/Linux; GoogleTest/GitHub; nominal e efetiva; Price e SAC comparados; interface Qt Widgets mais simples. A [decisão1011](../../decisions/1011/r1-complete-design-basis.md) atribui ao specialist as propostas ainda a aceitar: pt-BR/BRL; principal atéR$100milhões, prazo até600meses e entrada anual0..100%; dinheiro em centavos com half-up, Price com ajuste final/possível quitação por centavos e quantidade real visível, SAC com resto inicial; decimal50header-only; baselineC++20/Qt6.8.3/Boost1.86/GoogleTest1.17; Windows11x64/MSVC2022 e Ubuntu24.04x64/GCC13; ZIP/DEB; licençaMIT própria com avisos dos terceiros.

Ponto de atenção concreto: R$1.000,00 a juros zero em600meses gera599 pagamentos Price, última deR$1,34, pela política de centavos. O SAC mantém600 pagamentos, última deR$1,66. Isso está explicitamente no oráculo e na UI; não será escondido como prazo contratual idêntico. O humano pode solicitar outra política antes da aceitação.

Proposta de resposta ao gate: aceitar ou alterar as quatro specs e seus28requisitos r1, junto às propostas de1007/1011, e autorizar a passagem à autoria dos planos de implementação e teste. Essa resposta não aprova planos que ainda não existem nem sua execução. Um único aceite pode nomear este conjunto e a transição. Mudança solicitada volta aos rascunhos antes do planejamento dependente.

O orquestrador oferecerá council opcional uma vez, antes de implementação. Council só ocorre por pedido humano e não substitui aprovação. Após o gate, devs distintos normalmente escrevem seus próprios planos de teste e implementação; os planos concretos recebem aprovação aplicável; testes são escritos/executados no base antes do produto. Não há planos nesta entrega.

Maturidade desta rodada: arquitetura draft; plano não iniciado; teste de produto não executado; revisão independente não iniciada; satisfação de requisitos sem verdict. Build e uso nativo ainda precisam de ambientes/dependências. [Relatório1016](../../evidence/full-architecture.md) contém autoria, fontes, inventário, verificações estruturais e limites.
