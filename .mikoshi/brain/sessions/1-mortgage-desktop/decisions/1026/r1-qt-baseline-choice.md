---
id: 1026
revision: 1
type: decision
tags:
- mortgage
- design
- qt
- delivery
status: decided
created: '2026-10-26'
updated: '2026-10-26'
description: Escolha aberta da baseline Qt 6.12.0 oficial para preservar simplicidade de obtenção
  e manutenção do app Widgets.
use_when:
- Resolver o novo pin Qt e os efeitos sobre a spec de entrega antes dos planos.
---
# Escolha da baseline Qt após pesquisa

## Context

A arquitetura aceita [1014 r1](../../specs/1014/r1-reproducible-delivery.md) fixa Qt 6.8.3. O usuário pediu: “Vamos resolver os empates numéricos e revisar a versão do Qt com base nas pesquisas, mantendo o caminho mais simples e seguindo o fluxo da Mikoshi.” A análise [1024 r1](../../documents/1024/r1-qt-baseline-review.md) atualiza as pesquisas e fundamenta [1014 r2 proposta](../../specs/1014/r2-reproducible-delivery.md). A aprovação de r1 não se transfere a r2.

## Question

Aprovar Qt 6.12.0 oficial, com kits base 6.12.0-0-202609280346 para MSVC 2022 x64 e Linux GCC x64, preservando Widgets dinâmico e sem patchset próprio, para preparar os planos do projeto?

## Options

1. **Recomendada: Qt 6.12.0 oficial**, kit atual observável nos dois alvos, preservando módulos e compiladores; qualificar pacote real nos planos já previstos.
2. Manter Qt 6.8.3 original com avaliação explícita dos avisos posteriores e aceite de sua manutenção.
3. Qt 6.8.3 com patchset próprio, assumindo seleção dos patches, build e manutenção do framework nas duas plataformas.
4. Patch público posterior da série 6.8, condicionado a acesso/kit e correções reais; fontes 6.8.4/6.8.5 públicas não demonstram kit binário equivalente.
5. Rota comercial LTS, condicionada a licença e autorização próprias; não selecionada para esta proposta.

## Decision

**Open.** O specialist Qt recomenda a opção 1. Essa é uma proposta técnica do agente, não resposta humana. Não houve substituição da baseline aceita, aprovação de planos, obtenção/instalação de kit ou execução. O orquestrador deve apresentar esta escolha material ao humano junto da revisão numérica.

## Justification

A menor solução que mantém o escopo usa um kit oficial corrente com o mesmo backend Widgets, sem compilar e manter Qt modificado. Não existe código de produto a migrar. A matriz v6.12.0 mantém os alvos, CMake mínimo 3.25 não força aumentar o 3.28 já escolhido, e as unidades selecionadas mantêm alternativa LGPLv3. Versão recente não é garantia global de segurança: o novo diff CVE-2026-105924 e a necessidade de confrontar APIs/artefatos reais estão explicitados em 1024. A ausência prevista de CBOR/JSON na calculadora é uma fronteira do design, não prova de alcance runtime.

## Impact

- `related`: [1014 r1](../../specs/1014/r1-reproducible-delivery.md) → [1014 r2](../../specs/1014/r2-reproducible-delivery.md), sucessão proposta por mudança de pin e precisão do contrato de entrega. R1 permanece published, corpo preservado; r2 permanece draft até resposta humana.
- `related`: [1011 r1](../1011/r1-complete-design-basis.md), decisão anterior preservada; se aprovada, a escolha Qt é regida por 1026 sem reescrever a autoridade histórica de 1011.
- [1221](../../requirements/1221/r1-build-contract.md), [1225](../../requirements/1225/r1-runtime-packages.md), [1226](../../requirements/1226/r1-native-smoke.md), [1227](../../requirements/1227/r1-technical-documentation.md), [1228](../../requirements/1228/r1-distribution-notices.md): requisitos de produto reutilizados sem alteração semântica, porque não prescrevem o pin; aplicáveis a r1 e à sucessora quando aceita.
- 1222/1223/1224 continuam obsolete; sua presença histórica em r1 não os reinsere. A cobertura efetiva r2 os exclui.
- [2306](../../tools/2306/r1-qt-deployment.md): cartão ainda draft atualizado sob snapshot; distingue baseline aceita e candidato pendente. Cartões 2301–2305 continuam reutilizáveis; os futuros planos referenciam ferramentas e registram versões realmente executadas.
- [1015 r2](../../documents/1015/r2-refined-requirement-index.md), relatórios históricos, pesquisas 3003/3004 e notas 3141/3142/3124 conservam seus alvos históricos. O novo índice integrado deve apontar a sucessora como proposta, preservando leitura histórica.
- Não há planos/código/CI/release existentes a atualizar. Consumidores futuros: autores dos planos de build/teste/empacotamento, responsável por dependências e qualificação nativa.

O mapa acima cobre relações conhecidas e fontes lidas; o integrador conserva a lacuna do índice de grafo incompatível e registra a reconciliação transversal numérica/Qt no índice da sessão.
