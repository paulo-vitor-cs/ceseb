---
id: 2304
revision: 1
type: tool
tags:
- mortgage
- tools
- ci
- github
status: mandatory
created: '2026-10-26'
updated: '2026-10-26'
description: Contrato de observação e disparo autorizado das rotas de CI do repositório pessoal
  público.
use_when:
- Referenciar a automação de build e testes em planos ou observar uma execução GitHub Actions
  específica.
---
# GitHub Actions e observação pelo GitHub CLI

## Purpose and Boundary

Automatizar as rotas de engenharia selecionadas no design; a prescrição histórica [1224](../../requirements/1224/r1-ci-evidence.md) migra para esta ferramenta e para o plano consumidor. A capacidade de CI não é uma função do aplicativo. Fontes: [spec 1014](../../specs/1014/r1-reproducible-delivery.md), [1017](../../documents/1017/r1-design-approval-and-quality-correction.md). Repositório limitado a `paulo-vitor-cs/ceseb`.

## Usage Contract

Leituras documentadas, para uma execução explicitamente selecionada:

```text
gh workflow list -R paulo-vitor-cs/ceseb
gh run list -R paulo-vitor-cs/ceseb --commit <sha>
gh run view <run-id> -R paulo-vitor-cs/ceseb --log
gh run watch <run-id> -R paulo-vitor-cs/ceseb --exit-status
```

Somente quando um plano e a autoridade de efeito cobrirem o disparo:

```text
gh workflow run <workflow-id> -R paulo-vitor-cs/ceseb --ref <authorized-ref>
```

O disparo remoto exige workflow com `workflow_dispatch`. Grava eventos e pode consumir runners; não foi executado nesta correção. Identificar SHA, branch, tentativa, jobs, SO real e artefatos. Um run falho ou incompleto não comprova entrega. Após resposta de disparo perdida, consultar runs/ref antes de repetir; não iniciar execuções duplicadas por suposição.

## Access and Authentication

Leitura e disparo dependem da visibilidade do recurso e das permissões da conta/token. Reutilizar o armazenamento de credenciais autorizado do gh, sem imprimir valores. No CI, usar o segredo nativo do provedor com escopo mínimo e acesso apenas ao repositório selecionado; não criar PAT ou ampliar permissões automaticamente. Cotas e políticas são as da conta; nenhum plano pago é selecionado pelo cartão.

## Installation and Configuration

GitHub CLI já está no PATH local. A futura configuração do repositório deve fixar actions por commit e versões de dependências, declarar rotas Windows/MSVC e Ubuntu/GCC e registrar os ambientes reais. Não há workflow de produto criado. Configurar autenticação ou instalar runners requer autoridade separada; a criação anterior do repositório não comprova permissões de disparo.

## Contextual Obligations

Proposta para aprovação: obrigatório quando um plano autorizado criar ou usar as rotas de CI selecionadas no design; observação de uma execução não autoriza novo disparo, push, release ou merge. O plano referencia este cartão e os critérios de produto que seus jobs verificarão. Nenhuma rotina publica release automaticamente neste recorte.

## Availability and Evidence

Observado em WSL, 2026-10-26: gh 2.94.0 e help local de workflow run/run view/run watch. Nenhuma chamada remota de workflow, autenticação nova ou execução de CI ocorreu. Fontes: [workflow run](https://cli.github.com/manual/gh_workflow_run), [run view](https://cli.github.com/manual/gh_run_view) e [run watch](https://cli.github.com/manual/gh_run_watch), consultadas nesta data. CLI disponível não significa workflow instalado, runner qualificado ou job passado.

## Dependencies and Reuse

Rotas consomem [2301](../2301/r1-cmake-ctest-build.md), [2302](../2302/r1-googletest-runner.md), [2303](../2303/r1-qttest-runner.md), [2305](../2305/r1-native-compilers.md) e [2306](../2306/r1-qt-deployment.md). Consumidores: futuros planos de implementação/testes e seus workflows. Reutiliza o contrato provider-local GitHub CLI 2572 r8 do plugin Mikoshi; esse recurso foi lido localmente, não é um arquivo portátil deste repositório. Não foi duplicado ou ativado aqui.

## Removal

Desativar/remover somente workflow ou runner dedicado e autorizado, preservando runs, logs e artefatos necessários à rastreabilidade. Não revogar credenciais compartilhadas nem apagar o repositório. Uma substituição precisa identificar consumidores e evitar atribuir resultados antigos ao novo workflow.
