---
id: 2306
revision: 2
type: tool
tags:
- mortgage
- tools
- dependencies
- qt
- deployment
status: mandatory
created: '2026-10-26'
updated: '2026-10-26'
description: Aquisição proposta de dependências oficiais por lockfile e CMake, com deploy Qt
  e staging nativo rastreável.
use_when:
- Preparar dependências ou distribuir o aplicativo pelos planos 2001 e 2002 com os pins aprovados
  e sem credenciais de CI.
---
# Aquisição oficial e deploy da baseline

## Purpose and Boundary

Sucessora proposta de [2306 r1 aceita](r1-qt-deployment.md), cujo corpo e evidências permanecem preservados. Consumidores: [plano de testes 2001](../../plans/2001/r1-requirement-test-plan.md) e [implementação 2002](../../plans/2002/r1-product-implementation-plan.md). A [autoridade 1028](../../documents/1028/r1-revisions-approval-and-planning-authority.md) aceita Qt 6.12.0 e permite preparar planos; esta receita concreta ainda precisa da aprovação do conjunto dos planos. O método de aquisição usa CMake já selecionado, sem adicionar um gerenciador de dependências de terceiros. Seleciona Qt Core/Gui/Widgets dinâmicos e Test apenas para desenvolvimento; o pacote do usuário contém somente o runtime necessário.

## Usage Contract

CLI proposta, a executar da raiz de fontes revisada somente após aprovação. `cmake/AcquireDependencies.cmake` e o lockfile ainda serão criados pela tarefa de infraestrutura de 2002. O plano de testes prevê o handoff para essa preparação, sem chamar um arquivo inexistente como se fosse uma dependência instalada.

```text
cmake -DCESEB_DEPS_ROOT=build/dependencies -DCESEB_DEPS_PLATFORM=linux -DCESEB_ACQUIRE_QT=ON -P cmake/AcquireDependencies.cmake
cmake -DCESEB_DEPS_ROOT=build/dependencies -DCESEB_DEPS_PLATFORM=windows -DCESEB_ACQUIRE_QT=ON -P cmake/AcquireDependencies.cmake
windeployqt --version
windeployqt --release --dir <windows-stage> <app.exe>
cmake --install <build-dir> --prefix <linux-stage>
cpack --config <build-dir>/CPackConfig.cmake -G DEB
```

O primeiro comando é para Linux; o segundo para Windows/MSVC 2022. `CESEB_ACQUIRE_QT=OFF` obtém somente os inputs de domínio quando o cenário do plano dispensar GUI. `CESEB_DEPS_PLATFORM` aceita somente linux/windows; não escolhe outra ABI por inferência. O script lê `cmake/dependencies.lock.json` junto de seu próprio arquivo, verifica versão/origem/arquivo e checksum fixados antes de extrair e registra `build/dependencies/acquisition-manifest.json`.

Saídas próprias: cache em `build/dependencies/downloads`; Boost em `build/dependencies/boost_1_86_0`; fontes GoogleTest em `build/dependencies/googletest-src`, prefixo compilado em `build/dependencies/install`; Qt em `build/dependencies/Qt/6.12.0/gcc_64` ou `msvc2022_64`. Os componentes transitivos exatos e hashes ficam no lockfile listado em 2002, sem um latest silencioso. GoogleTest é compilado na toolchain compatível pelo build planejado; extração de fonte não significa instalação binária concluída.

Cada transferência usa `file(DOWNLOAD)` com `TLS_VERIFY ON`, `EXPECTED_HASH` a partir do lock revisado, `NETRC IGNORED`, status e erro conferidos. Não enviar credenciais. Certificado inválido, manifesto divergente, checksum incorreto, plataforma não aceita, arquivo incompleto ou falha de extração interrompe a operação. Não executar nem reutilizar payload inválido. Extrair apenas para área própria depois de verificar o conteúdo e os destinos; não sobrescrever ambientes alheios. A operação não altera o lock para aceitar o que recebeu.

Deploy Windows reconcilia Qt DLLs/plugins e CRT app-local permitido; `windeployqt` não comprova sozinho a licença nem a completude do runtime. Deploy Linux usa Qt privado, RPATH e dependências de sistema declaradas, sem substituir Qt global. Exportações para build nativo são snapshots do commit real, com manifesto e `CESEB_SOURCE_REVISION`; não são outros locais de autoria/Git. Os planos fixam seus diretórios e comandos. Falha de pacote/ABI/plugin retorna falha com logs e impede declarar o pacote validado.

## Access and Authentication

Transferências propostas são HTTPS aos arquivos públicos oficiais identificados no lock, sem conta, token, organização paga ou secret de CI. Isso descreve o acesso aos arquivos específicos observados, não um instalador Qt sem conta. A rota Qt Online Installer continua exigindo Qt Account nos seus termos; usar essa rota ou criar uma conta não é fallback autorizado. Custo comercial e assinatura não estão selecionados. Falta de acesso interrompe o consumidor e retorna a lacuna, sem trocar pin ou compilar Qt modificado automaticamente.

Compilação requer ferramentas compatíveis e permissão de escrita nas áreas próprias de build. Interação nativa requer sessão gráfica no SO declarado. Empacotamento e instalação de teste podem requerer autorização do ambiente-alvo. Antes de copiar CRT, qualificar a edição real MSVC e seus termos; não aplicar termos Community a Build Tools por inferência. As licenças e fontes correspondentes dos materiais realmente distribuídos permanecem obrigatórias pela spec de entrega.

## Installation and Configuration

Baseline: CMake >= 3.28/Ninja e compiladores de [2305](../2305/r1-native-compilers.md); Boost 1.86.0, GoogleTest 1.17.0 e Qt 6.12.0 oficial, kits base 6.12.0-0-202609280346. Reusar ambiente comprovadamente compatível. O dev implementa o script/lock e o build; o responsável pelo ambiente executa a obtenção/instalação autorizada e entrega prefixos/manifests ao consumidor. Planos distinguem preparação externa do ambiente da engenharia do script. Nenhum provisionamento é autorizado pela mera presença deste cartão.

Configurar `CMAKE_PREFIX_PATH`/prefixos conforme os comandos dos planos, sem depender de PATH Qt global para validar pacotes limpos. Test só entra nos alvos de teste. DLLs de teste/GoogleTest/Qt Creator/Designer não entram no pacote do usuário por estarem presentes no kit. O inventário de arquivos distribuídos determina plugins, ICU e demais licenças transitivas realmente necessárias.

## Contextual Obligations

Proposta de destino após aprovação: mandatory quando os planos obtiverem dependências fixadas ou prepararem/verificarem os pacotes. A obrigação é contextual. Em build de domínio com Qt dispensado, não executar a rota GUI. Não fazer upload, push, release, alteração de conta ou instalação global por esta receita. Os planos concretos declaram seus efeitos, autor e ambiente; indisponibilidade continua uma lacuna observável.

## Availability and Evidence

Em 26/10/2026 o projeto não tem script de aquisição, CMakeLists, testes ou pacote. O estado de ferramentas ausentes no WSL foi observado na exploração, não substituído por este texto. As observações de [acesso Qt](../../evidence/qt-baseline-review/access-observation.json) e a [análise 1024](../../documents/1024/r1-qt-baseline-review.md) distinguem metadata/HEAD de download e uso de kit. O dev de implementação registra metadata e SHA256 oficiais dos arquivos Qt selecionados em [qt-acquisition-pins.json](../../evidence/implementation-planning/qt-acquisition-pins.json), sem baixar payload. O subconjunto proposto é QtBase Windows, QtBase Linux e ICU Linux. A localização de windeployqt em QtBase da tag 6.12.0 foi conferida em [evidência de origem](../../evidence/implementation-planning/deployment-tool-source-location.json); QtTools não é necessário nessa receita. O lockfile do plano reproduzirá os valores selecionados; não substitui checksum esperado pelo calculado depois de baixar. Nenhum payload, extração ou instalação ocorreu nesta autoria.

Fontes oficiais lidas nesta preparação: [file, CMake 3.28](https://cmake.org/cmake/help/v3.28/command/file.html), unidades Transfer/TLS_VERIFY/EXPECTED_HASH e ARCHIVE_EXTRACT, e [baseline 1014 r2](../../specs/1014/r2-reproducible-delivery.md). CMake 3.28 não verifica certificado por padrão; por isso o consumidor deve ativar a verificação explicitamente. A documentação confirma a interface; não qualifica uma extração futura de Qt. Context7 não está exposto no catálogo nativo; a leitura oficial versionada é o fallback registrado.

## Dependencies and Reuse

[2301 CMake/CTest](../2301/r1-cmake-ctest-build.md), [2302 GoogleTest](../2302/r1-googletest-runner.md), [2303 QtTest](../2303/r1-qttest-runner.md), [2304 CI](../2304/r1-github-actions.md), [2305 compiladores](../2305/r1-native-compilers.md). O script host-owned pertence à infraestrutura do produto e não cria uma capacidade Mikoshi nem requisito financeiro fictício. Os planos 2001/2002 e o [contrato 1030](../../documents/1030/r1-test-interface-and-fixtures.md) são os consumidores exatos. O [arranjo 1032](../../decisions/1032/r1-engineering-execution-arrangement.md) registra autoria, exportação e escolha de meio.

## Removal

Preservar lockfiles, fonte correspondente, avisos, inventário, manifestos e resultados. Remover somente caches, build e staging próprios depois de conferir ownership e conservar evidência necessária. Não apagar arquivos preexistentes de terceiros, instalações compartilhadas ou dados modificados. Uma interrupção exige inspecionar os arquivos/manifesto reais antes de repetir; payload incompleto é novamente verificado. Substituição do meio/pin requer revisão de consumidores e a autoridade aplicável, sem transferir resultados antigos.
