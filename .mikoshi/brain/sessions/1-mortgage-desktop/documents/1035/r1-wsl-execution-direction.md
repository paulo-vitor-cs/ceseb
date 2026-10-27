---
id: 1035
revision: 1
type: document
tags: [mortgage, execution, environment, wsl]
status: versioned
created: '2026-10-26'
updated: '2026-10-26'
description: Diretriz humana de usar WSL na execução atual, com o ambiente observado registrado nos resultados.
use_when:
- Executar os planos localmente no WSL e atribuir cada evidência ao ambiente real.
---
# Diretriz de ambiente para execução

Pergunta feita ao humano:

> Para a validação nativa, você já tem Ubuntu 24.04 com desktop/GCC 13 ou MSVC 2022 instalado em algum local que eu deva usar? Se tiver, informe o caminho ou a forma de acesso. Vou continuar os testes e a implementação enquanto isso.

Resposta humana integral:

> deve usar o wsl

Origem: resposta ao esclarecimento assíncrono do chat durante a execução dos planos aprovados em [1034](../1034/r1-engineering-execution-approval.md).

A execução local atual usa WSL: Ubuntu 26.04 e GCC 15.2 observados, com ferramentas/dependências locais aprovadas. Os relatórios registram esse ambiente e o commit real de cada resultado. Os requisitos financeiros e a implementação avançam no ambiente disponível.

A matriz e os critérios específicos de Windows/Linux permanecem nos corpos aprovados. A atribuição de qualquer resultado por plataforma deve identificar o ambiente efetivamente observado. Uma escolha posterior de cross-compiler, pin, privilégio ou provisão material será apresentada com seu efeito concreto antes de executá-la. Esta diretriz não é resultado de teste, nem prova de compatibilidade de uma plataforma que não foi executada.
