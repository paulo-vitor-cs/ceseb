---
id: 1224
revision: 1
type: requirement
tags:
- mortgage
- delivery
- verification-test
status: obsolete
created: '2026-10-26'
updated: '2026-10-26'
description: Executar build, testes e empacotamento nas rotas Windows e Ubuntu declaradas.
use_when:
- Verificar ci nas duas rotas com logs no aplicativo de financiamento.
---
# CI nas duas rotas com logs

Condição: entrada, ambiente ou sequência definidos no oráculo abaixo, sob a proposta de design referenciada. Obrigação: Executar build, testes e empacotamento nas rotas Windows e Ubuntu declaradas.

Método: Inspeção e observação de workflow no commit-alvo. Oráculo determinístico:

Execuções GitHub Actions do commit-alvo possuem rotaWindows/MSVC eUbuntu24.04/GCC13, pins de dependências/ações e logs/JUnit de build/testes/pacote. Falha de teste reprova a rota. Nenhum job cria release automaticamente. Registrar SO real do runner; um runner WindowsServer não é evidência de runtime Windows11.

Fonte humana: [1001](../../documents/1001/r1-human-request.md), [1002](../../documents/1002/r1-image-evidence.md) e [1005](../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: [decisão1011](../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: [spec1014](../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.
