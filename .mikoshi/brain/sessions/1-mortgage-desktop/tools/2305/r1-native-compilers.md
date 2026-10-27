---
id: 2305
revision: 1
type: tool
tags:
- mortgage
- tools
- compiler
- cross-platform
status: mandatory
created: '2026-10-26'
updated: '2026-10-26'
description: Contrato de seleção e uso dos compiladores nativos para builds C++20 da matriz
  aprovada.
use_when:
- Preparar ou observar os compiladores das rotas Windows 11 e Ubuntu 24.04 sem presumir equivalência
  com WSL.
---
# Compiladores GCC e MSVC da matriz nativa

## Purpose and Boundary

Fornecer o compilador e linker C++ para os planos de build/testes. GCC 13 em Ubuntu 24.04 x64 e MSVC 2022 v143 em Windows 11 x64 são a baseline da [spec 1014](../../specs/1014/r1-reproducible-delivery.md). Não constitui requisito de comportamento do aplicativo nem autoriza provisão de máquina. Correção de origem: [1017](../../documents/1017/r1-design-approval-and-quality-correction.md).

## Usage Contract

Observação da ferramenta e interfaces de compilação, a adaptar ao arquivo/saída exatos do plano:

```text
g++-13 --version
g++-13 -std=c++20 -c <source.cpp> -o <object.o>
cl
cl /nologo /std:c++20 /c <source.cpp> /Fo<object.obj>
```

`cl` deve executar no x64 Native Tools Command Prompt de VS 2022 ou ambiente equivalente configurado pelo instalador. O projeto usará normalmente [CMake 2301](../2301/r1-cmake-ctest-build.md) em vez de comandos manuais por arquivo. Compilação grava objetos/binários; observar versão não compila o produto. Guardar diagnósticos, ABI/arquitetura, SDK e runtime. Um compilador instalado em outro SO/arquitetura não qualifica esta rota.

## Access and Authentication

Compilar fontes locais não exige conta de serviço. Instalação do toolchain e acesso a SDKs dependem das permissões e dos termos do fornecedor. Os termos MSVC/CRT da versão usada governam redistribuição; disponibilidade do compilador não concede direito irrestrito de copiar runtime. Não alterar política global de PATH ou credenciais.

## Installation and Configuration

Procedimento a executar somente sob autorização: em Ubuntu 24.04, instalar o pacote nativo `g++-13` e registrar versões efetivas; em Windows, instalar Build Tools/Visual Studio 2022 com ferramentas C++ x64 e SDK compatível e abrir seu prompt nativo. Usar os scripts de ambiente fornecidos, evitando montar manualmente INCLUDE/LIB/PATH. A instalação existente fora do PATH deve ser localizada/qualificada antes de duplicá-la. Boost 1.86.0 fornece headers para decimal50; obtê-los por pin/checksum e configurá-los no build, sem inventar comando Boost.

## Contextual Obligations

Proposta para aprovação: obrigatório quando o plano qualificar o build da matriz nativa declarada. GCC 15 no WSL pode apoiar desenvolvimento, mas não substitui automaticamente GCC 13/Ubuntu 24.04 nem MSVC/Windows 11. Uma troca de baseline é decisão explícita, não reparo por conveniência.

## Availability and Evidence

Observado nesta autoria: `/usr/bin/g++`, GCC 15.2.0 no WSL; `g++-13` ausente do PATH. MSVC não foi reobservado em prompt nativo; exploração anterior não o encontrou no PATH geral de PowerShell, sem excluir instalação fora dele. Fontes lidas em 2026-10-26: [GCC 13 — overall options](https://gcc.gnu.org/onlinedocs/gcc-13.4.0/gcc/Overall-Options.html) e [MSVC command-line environment](https://learn.microsoft.com/en-us/cpp/build/building-on-the-command-line?view=msvc-170). Nenhum arquivo foi compilado.

## Dependencies and Reuse

Reutiliza [2301](../2301/r1-cmake-ctest-build.md) para build e [2306](../2306/r1-qt-deployment.md) para Qt compatível com ABI. Consumidores pendentes: planos de implementação e testes, incluindo jobs de [2304](../2304/r1-github-actions.md). Registrar toolchain existente e seus componentes reutilizados antes de instalar outro.

## Removal

Preservar fontes, logs e versões usados em evidências. Remover somente uma instalação dedicada que pertença ao escopo autorizado, após verificar dependências de outros projetos. Não desinstalar toolchains compartilhados nem mudar a baseline para fazer um teste passar.
