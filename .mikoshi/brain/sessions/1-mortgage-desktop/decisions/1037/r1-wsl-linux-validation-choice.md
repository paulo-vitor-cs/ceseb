---
id: 1037
revision: 1
type: decision
tags: [mortgage, validation, wsl, human-choice]
status: decided
created: '2026-10-27'
updated: 2026-10-27
description: Escolha humana de aceitar WSL na evidência Linux de 1226, preservando Windows e demais critérios.
use_when:
- Interpretar a sucessão 1226 r1 para r2 e 1014 r2 para r3 sem relaxar outros requisitos.
---
# Aceitação de WSL para Linux em 1226

Decisor: humano. Fonte literal e interpretação contextual em [1036 r1](../../documents/1036/r1-bounded-corrections-and-validation-authority.md). O usuário aceita WSL como validação Linux para 1226 e mantém o objetivo Windows/Linux. Esta decisão não atribui resultado de execução e não autoriza substituir binário Windows por processo Linux no host Windows.

A escolha é implementada por [1226 r2](../../requirements/1226/r2-wsl-linux-and-windows-smoke.md), sucessora de [1226 r1](../../requirements/1226/r1-native-smoke.md), e [1014 r3](../../specs/1014/r3-wsl-validation-delivery.md), sucessora de [1014 r2](../../specs/1014/r2-reproducible-delivery.md). Preservar os corpos predecessores e seus resultados históricos; não transferir resultados às novas revisões. Demais requisitos continuam em suas revisões e oráculos aprovados.

Incidências anteriores: 24 declarações para 1226 r1 e 31 para 1014 r2, com cobertura complete_within_declared_corpus e sem frontier na consulta explícita. Planos, decisões, fontes de pesquisa e relatórios históricos conservam suas referências anteriores. As ferramentas conservam as condições de baseline sem mudanças de pin. Novos planos usam as sucessoras explicitamente; não reescrever planos publicados nem fontes históricas.

Related: [1226 r1](../../requirements/1226/r1-native-smoke.md); [1226 r2](../../requirements/1226/r2-wsl-linux-and-windows-smoke.md); [1014 r2](../../specs/1014/r2-reproducible-delivery.md); [1014 r3](../../specs/1014/r3-wsl-validation-delivery.md).
