---
id: 2301
revision: 1
type: tool
tags:
- mortgage
- tools
- build
- test-execution
status: mandatory
created: '2026-10-26'
updated: '2026-10-26'
description: Contrato operacional de configuração, compilação e execução de testes com CMake/CTest
  e gerador Ninja.
use_when:
- Preparar ou executar o build e a agregação de testes autorizados da calculadora.
---
# CMake, CTest e Ninja para build e testes

## Purpose and Boundary

Orquestrar configuração, build, instalação em staging e testes locais. O consumidor será o autor/executor dos planos de implementação e testes, ainda não escritos. A seleção de ferramentas deriva da [spec 1014 aprovada](../../specs/1014/r1-reproducible-delivery.md); a separação de requisitos vem da [correção humana 1017](../../documents/1017/r1-design-approval-and-quality-correction.md). Não é uma obrigação funcional da calculadora.

## Usage Contract

Interface documentada; as chamadas de produto abaixo são propostas e não foram executadas:

```text
cmake --version
ninja --version
cmake -S <source-root> -B <build-dir> -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build <build-dir> --parallel
ctest --test-dir <build-dir> -C Release --output-on-failure --no-tests=error --output-junit <absolute-report.xml>
cmake --install <build-dir> --prefix <staging-dir>
```

Substituir metavariáveis por caminhos exatos do futuro plano. Flags próprias da aplicação, alvos e labels ainda não existem. Configuração grava cache e arquivos no build; build cria binários; testes podem criar evidências; install grava o staging. CTest retorna falha quando testes falham. Registrar comando, diretório, revisão, versões, saída e código de retorno. Usar `--no-tests=error` na agregação e conferir também a contagem/seleção dentro dos runners: um executável registrado no CTest pode executar zero casos internos. Erro de configuração ou zero testes encontrados não demonstra sucesso de requisitos. A pesquisa [3123](../../knowledge/3123/r1-test-runner-evidence-semantics.md) registra a semântica da versão fixada. Corrigir a causa dentro da autoridade, preservar logs e repetir somente a operação afetada.

## Access and Authentication

Configuração/build locais não exigem conta. A primeira obtenção de fontes pode exigir rede; usar somente origens e pins aprovados. Não introduzir credenciais em flags ou logs. É necessária escrita em build/staging e execução de ferramentas compatíveis.

## Installation and Configuration

Baseline: CMake >= 3.28 e Ninja, com versão efetivamente usada registrada. Uma instalação autorizada obtém binários oficiais ou pacote nativo compatível, verifica integridade e configura PATH apenas no ambiente selecionado. Usar o compilador de [2305](../2305/r1-native-compilers.md). Qt vem de [2306](../2306/r1-qt-deployment.md); Boost 1.86.0 é dependência de headers do núcleo, obtida por pin e checksum, sem CLI própria. O futuro mecanismo CMake deve declarar os prefixos de descoberta e o modo sem GUI. Não há CMakeLists ou presets no projeto ainda.

## Contextual Obligations

Proposta para aprovação: uso obrigatório quando um plano autorizado configurar, compilar ou agregar testes desta baseline. O plano deve referenciar este cartão, selecionar alvos/caminhos e declarar os efeitos. Não executar toda a interface só porque o cartão existe. A indisponibilidade interrompe a operação dependente; instalação requer sua autorização aplicável.

## Availability and Evidence

Observação em 2026-10-26, WSL: cmake, ctest, cpack e ninja não encontrados no PATH. Isso não exclui instalações fora dele. Contratos documentados: [cmake 3.28](https://cmake.org/cmake/help/v3.28/manual/cmake.1.html), [ctest 3.28](https://cmake.org/cmake/help/v3.28/manual/ctest.1.html), [download CMake](https://cmake.org/download/) e [Ninja](https://ninja-build.org/manual.html), seções CLI consultadas nesta data. Nenhum configure, build, teste ou install foi realizado. Cartão draft não prova instalação, configuração ou operação.

## Dependencies and Reuse

Reutilizar ambiente compatível após verificar versões; não alterar ferramentas compartilhadas por conveniência. Testes de domínio usam [2302](../2302/r1-googletest-runner.md), GUI usa [2303](../2303/r1-qttest-runner.md), automação usa [2304](../2304/r1-github-actions.md). Planos consumidores permanecem pendentes, sem links inventados. CPack, incluído na família CMake, será usado para empacotamento somente pelo contrato de 2306.

## Removal

Remover apenas diretórios de build/staging pertencentes ao plano após preservar evidências necessárias. Não apagar fontes, pins, bibliotecas globais ou ambientes de outros projetos. Aposentar o cartão exige identificar os planos consumidores e sua substituição, sem desinstalação implícita.
