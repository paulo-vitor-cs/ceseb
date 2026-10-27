<!-- SPDX-License-Identifier: MIT -->
<!-- Copyright (c) 2026 paulo-vitor-cs -->
# Compilação e testes

Requer CMake >=3.28, Ninja e Git. Alvos: Ubuntu 24.04 x64/GCC 13 e Windows 11
x64/MSVC 2022 v143. No Windows use o prompt x64 Native Tools da instalação
licenciada observada; registre edição, SDK e `cl`. Não há instalador de
compilador ou alteração global de PATH no projeto. No Ubuntu, o SDK Qt precisa
das dependências de desenvolvimento OpenGL, fontconfig e xkbcommon-x11. Ausência
é erro de ambiente, não motivo para inventar caminhos de bibliotecas.

Os pins completos estão em `cmake/dependencies.lock.json`. Boost 1.86.0 é
header-only; GoogleTest 1.17.0 usa o commit exato indicado no lock. QtBase
6.12.0-0-202609280346 é obtido por arquivos públicos oficiais com SHA256 esperado
e verificação TLS; no Linux, ICU 73.2 é parte do kit selecionado. O script não
usa conta, instalador Qt, aqtinstall ou senha. O cache é apenas
`build/dependencies`, exige marcador de ownership e conserva material inesperado
para diagnóstico. Não altere os pins para contornar uma falha.

No checkout Git, registre `git rev-parse HEAD`. Em uma fonte exportada, defina
`CESEB_SOURCE_REVISION` com esse SHA real de 40 caracteres antes de configurar.
Os exemplos abaixo assumem CWD na fonte e revisão real na variável. Primeiro
compile o núcleo em um ambiente sem Qt:

```sh
cmake -DCESEB_DEPS_ROOT=build/dependencies -DCESEB_DEPS_PLATFORM=linux -DCESEB_ACQUIRE_QT=OFF -P cmake/AcquireDependencies.cmake
cmake -S . -B build/core-only -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=g++-13 -DCESEB_SOURCE_REVISION="$CESEB_SOURCE_REVISION" -DCESEB_BUILD_GUI=OFF -DCESEB_BUILD_TESTS=ON -DCESEB_BOOST_ROOT="$PWD/build/dependencies/boost_1_86_0" -DCMAKE_PREFIX_PATH="$PWD/build/dependencies/install"
cmake --build build/core-only --parallel 2
ctest --test-dir build/core-only --output-on-failure --no-tests=error
```

Depois obtenha o SDK e compile a interface:

```sh
cmake -DCESEB_DEPS_ROOT=build/dependencies -DCESEB_DEPS_PLATFORM=linux -DCESEB_ACQUIRE_QT=ON -P cmake/AcquireDependencies.cmake
cmake -S . -B build/linux-release -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=g++-13 -DCESEB_SOURCE_REVISION="$CESEB_SOURCE_REVISION" -DCESEB_BUILD_GUI=ON -DCESEB_BUILD_TESTS=ON -DCESEB_BOOST_ROOT="$PWD/build/dependencies/boost_1_86_0" "-DCMAKE_PREFIX_PATH=$PWD/build/dependencies/Qt/6.12.0/gcc_64;$PWD/build/dependencies/install"
cmake --build build/linux-release --parallel 2
ctest --test-dir build/linux-release --output-on-failure --no-tests=error
build/linux-release/bin/ceseb
```

Os presets `core-only`, `linux-release` e `windows-release` ajudam a composição,
mas os prefixos precisam ser reais. No Windows, use `CESEB_DEPS_PLATFORM=windows`,
`CMAKE_CXX_COMPILER=cl`, kit `Qt/6.12.0/msvc2022_64` e build
`build/windows-release` nos mesmos comandos. Em PowerShell, passe o argumento
inteiro `-DCMAKE_PREFIX_PATH=...;...` entre aspas e confira `$LASTEXITCODE` após
cada chamada; no cmd, use `%CESEB_SOURCE_REVISION%`. Acrescente apenas o `bin`
do Qt selecionado ao PATH do processo de testes Windows, para localizar as DLLs.
Executáveis gerados: `bin/ceseb`, `bin/ceseb_domain_tests`, `bin/ceseb_gui_tests`
(com `.exe` no Windows).

O runner de domínio lista os casos com `--gtest_list_tests`; as seleções são
`--gtest_filter=Req1101.*` etc. Qt Test lista com `-functions`. CTest exige 13
suites de domínio e quatro slots GUI; filtro vazio não é sucesso. Em headless,
`QT_QPA_PLATFORM=offscreen` permite testes determinísticos auxiliares, sem
substituir uso interativo no desktop. Para diagnóstico GCC, um build separado
com `CESEB_ENABLE_COVERAGE=ON` aplica `--coverage`; não há limiar de cobertura
inventado nem instrumentação no Release normal.

Empacotamento exige o input documental externo `CESEB_DELIVERY_EVIDENCE_ROOT`,
com os 21 registros históricos e locators listados no relatório técnico. Esse
export não vem de `git archive`: forneça-o separadamente e conserve sua
proveniência. No checkout original, a raiz pode ser o próprio checkout quando
os registros estiverem presentes. Build sem instalação não exige esse input;
install/package interrompe com diagnóstico se a raiz ou algum registro faltar.
No Windows, passe `-DCESEB_DELIVERY_EVIDENCE_ROOT=C:/caminho/do/export` ao
configure, antes de install/CPack.

Empacotamento exige primeiro os textos e a fonte exata de Qt indicados pelo
SBOM. Esse comando obtém o commit correspondente e não compila nem modifica Qt:

```sh
cmake -DCESEB_DEPS_ROOT=build/dependencies -DCESEB_QT_ROOT=build/dependencies/Qt/6.12.0/gcc_64 -P cmake/ThirdPartyNotices.cmake
cmake -S . -B build/linux-release -DCESEB_DELIVERY_EVIDENCE_ROOT="$CESEB_DELIVERY_EVIDENCE_ROOT"
DESTDIR="$PWD/out/stage/linux" cmake --install build/linux-release --prefix /opt/ceseb
cpack --config build/linux-release/CPackConfig.cmake -G DEB -B out/packages
```

No staging Linux, use sempre `DESTDIR`: o prefixo privado fica sob
`out/stage/linux/opt/ceseb`, e o lançador absoluto fica sob
`out/stage/linux/usr/share/applications`. `--prefix` sozinho não redireciona
esse destino absoluto. Não execute install de teste sem DESTDIR.

Saídas previstas: `out/packages/ceseb_0.1.0_amd64.deb` e
`out/packages/ceseb-0.1.0-windows-x86_64.zip`, com SHA256 e manifesto de fonte e
arquivos. O DEB instala Qt privado em `/opt/ceseb/lib`, plugins em `plugins` e
RPATH `$ORIGIN/../lib`; não inclui glibc. No Windows, o script windeployqt é do
kit selecionado e não copia um instalador vc_redist. Antes de ZIP, configure
`CESEB_MSVC_REDIST_QUALIFIED=ON`, `CESEB_MSVC_EDITION` observado e
`CESEB_MSVC_REDIST_LICENSE` apontando aos termos originais aplicáveis; conserve
a lista REDIST e confira cada DLL Release coletada. Não habilite o flag sem
essa inspeção. Em export com cache fora da fonte, defina também
`CESEB_NOTICES_ROOT` com a pasta real de notices preparada.

O workflow usa ações fixadas por SHA, apenas `workflow_dispatch`, e testa em
Ubuntu 24.04 e Windows Server 2022. Não publica release. Arquivo de CI presente
não significa run executado; Server/headless não qualifica o desktop Windows11.
Qualificação final precisa dos dois desktops limpos sem Qt/compilador do SDK e
do mesmo snapshot/pacote. Consulte o relatório para o que foi observado.
