---
id: 1038
revision: 1
type: document
tags: [mortgage, authority, wsl, application]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Aplicação limitada da escolha humana WSL em 1226 com sucessoras, incidências e efeitos mecânicos registrados.
use_when:
- Recuperar a autoridade e o recorte efetivo de 1226 r2 e 1014 r3 antes da validação.
---
# Aplicação da emenda WSL

A [instrução humana 1036](../1036/r1-bounded-corrections-and-validation-authority.md) autoriza diretamente aceitar WSL como validação Linux em 1226. Foram preparados [1226 r2](../../requirements/1226/r2-wsl-linux-and-windows-smoke.md) e [1014 r3](../../specs/1014/r3-wsl-validation-delivery.md), com os mesmos valores e quatro critérios de aceite de 1226 r1. A revisão mantém Windows 11 e não relaxa outros requisitos. A publicação destas sucessoras aplica essa escolha específica; não é inferida de silêncio nem uma aceitação de resultado do produto.

A revisão de 55 declarações incidentes está em evidence/dispatch/r2/impact/amendment-edge-dispositions.json. Todos os endpoints históricos permanecem, inclusive planos publicados, pesquisa e relatórios. Novos planos usam os novos locators exatos. Os corpos predecessores permanecem byte a byte preservados. Resultados antigos não são transferidos às sucessoras.

As transições de decisão e retirement são tentadas pelo CLI nativo e seus resultados ficam em evidence/dispatch/r2/impact/amendment-status.json. Se uma restrição mecânica impedir retirement sem alterar um corpo aprovado, manter seu estado anterior e registrar o diagnóstico; a seleção operacional deste recorte é explicitamente 1226 r2 e 1014 r3, não uma inferência de latest. Não modificar corpo predecessor para forçar o validador.

```mikoshi-result-v1
- kind: decision
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/decisions/1037/r1-wsl-linux-validation-choice.md
    id: 1037
    revision: 1
  resolution: decided
  actor: human
  source: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/documents/1036/r1-bounded-corrections-and-validation-authority.md
  scope:
    targets:
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/decisions/1037/r1-wsl-linux-validation-choice.md
      id: 1037
      revision: 1
    effect: decided
- kind: retirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1226/r1-native-smoke.md
    id: 1226
    revision: 1
  state: superseded
  reason: Escolha humana em1036 aceitaWSL na parteLinux de1226; sucessora conserva
    outrosoráculos e corpo predecessor intacto.
  authority: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/documents/1036/r1-bounded-corrections-and-validation-authority.md
  successor:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1226/r2-wsl-linux-and-windows-smoke.md
    id: 1226
    revision: 2
- kind: retirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/specs/1014/r2-reproducible-delivery.md
    id: 1014
    revision: 2
  state: superseded
  reason: Escolha humana em1036 aceitaWSL na parteLinux de1226; sucessora conserva
    outrosoráculos e corpo predecessor intacto.
  authority: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/documents/1036/r1-bounded-corrections-and-validation-authority.md
  successor:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/specs/1014/r3-wsl-validation-delivery.md
    id: 1014
    revision: 3
```
