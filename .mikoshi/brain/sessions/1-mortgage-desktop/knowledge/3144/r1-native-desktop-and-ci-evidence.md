---
id: 3144
revision: 1
type: knowledge
tags: [mortgage, research, delivery, cross-platform]
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Identidade real de runner e pacote limita o que CI, WSL e testes sem desktop podem comprovar.
use_when:
- Atribuir evidência de build, automação ou demonstração desktop a uma plataforma e revisão exatas.
---
# CI e desktop nativo precisam de evidências distintas

O [README oficial de windows-2022](https://raw.githubusercontent.com/actions/runner-images/main/images/windows/Windows2022-Readme.md), cabeçalho e seção Visual Studio, observado em 2026-10-26, identifica Windows Server 2022, imagem 20261022.344.1 e VS 2022. O [changelog de 2026-05-14](https://github.blog/changelog/2026-05-14-github-actions-upcoming-image-migrations/), seção Windows, registra migração de windows-latest/windows-2025 para VS 2026 e indica windows-2022 para permanecer em VS 2022. Labels fixam uma família; a imagem dessa família ainda evolui.

Contraevidência a equivalência WSL=desktop alvo: a [documentação Microsoft WSL GUI](https://learn.microsoft.com/en-us/windows/wsl/tutorials/gui-apps), introdução e limite de desktop, descreve aplicativos Linux integrados ao desktop Windows e explicita ausência de desktop Linux completo. A política do projeto em [1014](../../specs/1014/r1-reproducible-delivery.md) e [1226](../../requirements/1226/r1-native-smoke.md) requer uso dos pacotes em Windows 11 x64 e Ubuntu 24.04 desktop. É essa política que impede atribuir o mesmo resultado a WSL, offscreen ou Xvfb.

Inferência: uma VM com SO alvo e sessão desktop interativa pode ser proposta como ambiente de demonstração, registrando virtualização, gráficos, SO e limites; não foi provisionada ou aceita por esta nota. Um run Server só demonstra o que executou naquele Server.

Para evidência recuperável, guardar SHA, tentativa/run/job, imagem real, compilador, kit, pacote e hash do arquivo, logs e resultado por plataforma. Os [artefatos GitHub](https://docs.github.com/en/actions/tutorials/store-and-share-data), Retention/Validation, têm retenção configurável e validação de digest; não garantem preservação indefinida nem equivalência de dois nomes iguais. Os [princípios GitHub](https://docs.github.com/en/actions/reference/security/secure-use), least privilege e terceiros, apoiam permissões mínimas e dependências fixadas.

Não foram inspecionadas permissões remotas, criado workflow ou disparado job. Não existe resultado do produto. Fontes móveis devem ser reobservadas na execução; [3003](../../documents/3003/r1-distribution-research-compilation.md) delimita a pesquisa.
