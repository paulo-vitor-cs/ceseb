---
id: 3124
revision: 1
type: knowledge
tags:
- mortgage
- research
- technology
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Suporte documental da matriz Qt 6.8.3 e condições de composição para compilar o núcleo sem Qt.
use_when:
- Preparar a matriz de build e revisar descoberta de dependências da baseline aprovada.
---
# Baseline fixada e núcleo independente de Qt

## Claim

A matriz de Qt 6.8.3 inclui os alvos desktop escolhidos; a independência do núcleo é compatível com essa baseline quando dependências de Qt ficam nos consumidores de GUI, inclusive durante a configuração.

## Fontes e condições

[Qtdoc v6.8.3 supported-platforms.qdocinc](https://github.com/qt/qtdoc/blob/v6.8.3/doc/src/platforms/supported-platforms.qdocinc), unidades desktop 8..94, lidas em 2026-10-26: Ubuntu 24.04/GCC 13 e Windows 11 x86_64/MSVC 2022 são configurações listadas. [QtBase .cmake.conf v6.8.3](https://github.com/qt/qtbase/blob/v6.8.3/.cmake.conf) registra mínimo CMake 3.16 para consumir Qt compartilhado. [GoogleTest CMake v1.17](https://github.com/google/googletest/blob/v1.17.0/CMakeLists.txt) registra mínimo 3.16; [release v1.17](https://github.com/google/googletest/releases/tag/v1.17.0) exige ao menos C++17. C++20/CMake 3.28 não conflitam com esses mínimos.

[Boost 1.86 cpp_dec_float](https://www.boost.org/doc/libs/1_86_0/libs/multiprecision/doc/html/boost_multiprecision/tut/floats/cpp_dec_float.html) documenta backend C++ header-only. [CMake 3.28 CXX_STANDARD](https://cmake.org/cmake/help/v3.28/prop_tgt/CXX_STANDARD.html) documenta decay do padrão e seus controles; o plano precisa exigir padrão 20 e desligar extensões para corresponder à escolha do projeto.

## Consequência arquitetural inferida

A interface do núcleo pode usar tipos C++/Boost sem QString/QObject. Descobrir Qt apenas no ramo de GUI/testes Qt, em vez de find_package REQUIRED incondicional na raiz, permite configurar o núcleo sem Qt. Essa é condição de construção coerente com [1221 r1](../../requirements/1221/r1-build-contract.md), não evidência de que um CMakeLists existente já a cumpre. Não foi criado código/build.

## Contraevidência e drift

A [página móvel Qt 6.8](https://doc.qt.io/qt-6.8/supported-platforms.html) pode descrever outro patch; páginas de classes consultadas identificam 6.8.9. Lista de suporte do fornecedor não garante o pacote concreto. A [release Boost 1.86](https://www.boost.org/releases/1.86.0/) lista VC14.3, mas a lista GCC C++20 examinada vai até 12; ausência de 13 nessa lista não prova incompatibilidade. Mínimos de CMake não certificam toda versão futura permitida por >=3.28. C++20 não implica que todas as APIs opcionais da linguagem sejam usadas ou qualificadas.

## Consumidor e pendência

Autor dos planos de build/testes: fixar dependências por identidade e verificar o conjunto com os compiladores exatos/ABI/runtime; construir o núcleo isolado nas duas plataformas. WSL/GCC 15 histórico não comprova Ubuntu 24.04/GCC 13. Distribuição e licenças ficam no relatório DIST. [Compilação 3002](../../documents/3002/r1-technology-research-compilation.md), T1/T6. Draft; nenhuma qualificação de build ou runtime.

