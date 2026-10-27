---
id: 1025
revision: 1
type: decision
tags:
- mortgage
- numerics
- design
status: decided
created: '2026-10-26'
updated: '2026-10-26'
description: Propor comparação exata de fronteiras numéricas mantendo fórmulas, domínio e half-up
  sem adotar quantização de taxa.
use_when:
- Resolver fronteiras half-up e rastrear a proposta numérica sem alterar as revisões já aceitas.
---
# Decisão numérica proposta para empates exatos

Autor: specialist-numeric-resolution, sob delegação do orquestrador na fase 4. Pedido vigente: “Vamos resolver os empates numéricos e revisar a versão do Qt com base nas pesquisas, mantendo o caminho mais simples e seguindo o fluxo da Mikoshi.” Esta decisão registra uma proposta concreta, não uma aprovação humana, execução ou mudança da baseline aceita. A revisão Qt pertence a outro recorte.

## Problema e critério

As specs aceitas [1008 r1](../../specs/1008/r1-annual-rate-conversion.md), [1012 r1](../../specs/1012/r1-amortization-comparison.md) e [1013 r1](../../specs/1013/r1-widgets-interface.md) exigem fórmulas nominais/efetivas e half-up, mas confiam a decisão monetária à aproximação decimal de 50 dígitos. [Pesquisa 3004](../../documents/3004/r1-research-synthesis.md) R2/R3 mostra que proximidade da taxa não decide um empate e que o formatter genérico pode usar outra convenção. Critério comum: preservar as duas taxas, ambos os livros, domínio, centavos exatos, apresentação half-up e a independência de Qt, usando a menor solução completa.

## Alternativas

| Alternativa | Consequência no mesmo contrato | Julgamento do specialist |
|---|---|---|
| Apenas decimal de 50 dígitos/mais dígitos ou epsilon fixo | Não prova o lado correto de toda fronteira; epsilon também pode promover valor legitimamente abaixo do empate. | Insuficiente. |
| Mensal efetiva quantizada, por exemplo em 18 casas, seguida de frações exatas | Menos código; redefine o alvo financeiro nas fronteiras e exige nova convenção material de produto. Nominal 100% não pode ser simplesmente truncada sem perder o caso de 6 centavos. | Alternativa possível somente com autorização explícita para mudar o modelo; não recomendada neste recorte. |
| Taxa original exata, decisão inteira das fronteiras e intervalo racional somente para Price efetiva irracional | Preserva o contrato matemático. Acrescenta helpers de inteiro grande, raiz inteira de grau 12, comparação por potência 12 e refinamento racional; não exige pacote novo nem engine algébrica genérica. | **Proposta recomendada.** |

## Escolha proposta e corpos

Adotar os sucessores draft [1008 r2](../../specs/1008/r2-annual-rate-conversion.md), [1012 r2](../../specs/1012/r2-amortization-comparison.md) e [1013 r2](../../specs/1013/r2-widgets-interface.md), que mantêm as fórmulas e livros e substituem o meio de decisão. A taxa normalizada conserva a convenção e o percentual decimal de origem como racional exato; projeções aproximadas servem apenas às tolerâncias de taxa, nunca ao centavo ou desempate textual. Inteiros grandes/frações usam a dependência Boost 1.86 já proposta. Não acrescentar MPFR, CAS, epsilon ou serviço.

O [relatório 1023](../../documents/1023/r1-numerical-resolution.md) contém método, prova de terminação, contraexemplos, fontes e limite de evidência. O desempenho de Windows/Linux não foi medido; será qualificado pelos planos posteriores. Aprovar o argumento não comprova a implementação.

## Incidências e preservação

As três r1 publicadas permanecem byte a byte intactas. O snapshot [numeric-preimages.json](../../evidence/numeric-preimages.json) registra os corpos antes da revisão. Nenhum plano existe neste recorte. Não reescrever decisões humanas 1007/1011 ou relatórios históricos como se já aprovassem o novo meio.

| Grupo incidente | Disposição |
|---|---|
| 1008 r1 ↔ 1012 r1 ↔ 1013 r1 | r2 aponta para r2 no conjunto candidato; r1 preserva a baseline aceita. |
| Requisitos 1101 a 1105, 1201, 1204, 1206, 1207, 1211, 1213 a 1217 | Comportamentos preservados; podem servir aos sucessores. Seus links históricos r1 permanecem válidos. O índice candidato deve registrar a aplicação às r2 sem inferir aprovação. |
| Requisitos draft 1106, 1202, 1203, 1205, 1212 | Refinados com contrato de transporte exato, fronteiras e oráculos; continuam draft, sem pass/fail. Snapshot anterior conservado. |
| Spec 1014 e tool cards | Incidência de Boost: apenas mudam quais tipos header-only do mesmo pin são usados; nenhum pacote/instalação novo. A revisão Qt e a integração de 1014 pertencem ao orquestrador. |
| Decisões 1007/1011/1018, documentos 1006/1015/1017/3001/3002/3004, notas 3101 a 3105 e 3121/3122/3125/3126, relatórios de autoria | Evidência histórica e proposições de sua revisão permanecem intactas. Esta decisão e o índice candidato registram o delta; não apagar descobertas ou falsificar fechamento da pesquisa. |

O inventário textual de incidências é registrado no relatório. Busca literal não prova cobertura total de grafo; o grafo incompatível anteriormente registrado continua um limite. A aprovação e a entrada nos planos pertencem ao orquestrador/humano. Sem autorização de build, experimento, instalação, commit, push, promoção ou Synapses por este retorno.
