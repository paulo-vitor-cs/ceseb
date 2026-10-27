---
id: 2306
revision: 1
type: tool
tags:
- mortgage
- tools
- qt
- deployment
status: superseded
created: '2026-10-26'
updated: '2026-10-26'
description: Contrato proposto de acesso ao kit Qt 6.12.0 e implantação das dependências runtime
  nos pacotes Windows e Ubuntu.
use_when:
- Preparar o kit Qt ou montar os pacotes runtime definidos na arquitetura, após aprovação da
  revisão aplicável.
---
# Qt Widgets e ferramentas de distribuição

## Purpose and Boundary

Usar Qt Core/Gui/Widgets, Test apenas no desenvolvimento, e coletar dependências de distribuição do aplicativo. A operação é ferramenta de engenharia; o comportamento público e a usabilidade do pacote permanecem requisitos de produto. Baseline aceita: [1014 r1](../../specs/1014/r1-reproducible-delivery.md). Revisão proposta: [1014 r2](../../specs/1014/r2-reproducible-delivery.md), condicionada à [decisão aberta 1026](../../decisions/1026/r1-qt-baseline-choice.md) e [correção 1017](../../documents/1017/r1-design-approval-and-quality-correction.md).

## Usage Contract

Interfaces propostas para os artefatos que um futuro plano definirá:

```text
windeployqt --version
windeployqt --release --dir <windows-stage> <app.exe>
cmake --install <build-dir> --prefix <linux-stage>
cpack --config <build-dir>/CPackConfig.cmake -G DEB
```

`windeployqt` copia dependências Qt para staging e deve rodar no ambiente do kit Windows compatível. Somente componentes necessários ao app entram no staging; QML, Qt Creator e exemplos não entram por mera presença no kit. Ele não resolve necessariamente todas as bibliotecas de terceiros nem garante que o CRT seja utilizável de forma portátil. O plano de pacote deve reconciliar o CRT permitido, arquivos Qt, plugins, avisos e dependências transitivas. Em Linux, as regras install/CPack devem ser escritas e verificadas; o comando não as cria. Falha ou biblioteca ausente reprova a operação; preservar logs e verificar o pacote em ambiente limpo.

## Access and Authentication

Execução das ferramentas locais não requer conta. O canal Qt Online Installer documentado usa Qt Account; criar ou autenticar conta não é autorizado por este cartão. Uma alternativa é obter e compilar fontes Qt sob os termos aplicáveis, se isso for selecionado em plano autorizado. Nenhuma assinatura comercial é inferida. Distribuição precisa conservar licenças/avisos e fonte correspondente conforme a baseline aprovada.

## Installation and Configuration

Após aprovação de 1026, obter exatamente Qt 6.12.0 oficial, kit base 6.12.0-0-202609280346 para MSVC 2022 x64 ou GCC compatível com Ubuntu 24.04, com integridade verificada. O responsável pela reconciliação instala o kit selecionado e fornece prefixo, ferramentas e componentes ao build; isso ainda não foi autorizado/executado. Test é somente dependência de teste. O plano Windows configura ambiente Qt/MSVC antes do deploy; o plano Linux instala Qt privado na árvore do app e declara bibliotecas de sistema, sem substituir Qt global.

## Contextual Obligations

Proposta para aprovação: obrigatório quando os planos precisarem configurar módulos Qt ou montar/verificar os pacotes selecionados. O cartão não autoriza instalação, aceitação de termos, cópia arbitrária do CRT ou publicação. A falta de acesso ao kit bloqueia a operação e retorna a lacuna; não autoriza mudar silenciosamente a versão aprovada.

## Availability and Evidence

Nesta autoria, qmake6, qtpaths6 e windeployqt não estão no PATH WSL. Nenhum kit 6.8.3 ou 6.12.0 ou pacote foi qualificado. Metadata e HEAD dos arquivos qtbase 6.12.0 foram observados em [evidence](../../evidence/qt-baseline-review/access-observation.json); não houve download dos payloads. A mudança proposta não altera silenciosamente o pin aceito. Fontes consultadas em 2026-10-26: [Get and Install Qt](https://doc.qt.io/qt-6.12/get-and-install-qt.html), [Windows deployment](https://doc.qt.io/qt-6.12/windows-deployment.html), [Linux deployment](https://doc.qt.io/qt-6.12/linux-deployment.html) e [CPack 3.28](https://cmake.org/cmake/help/v3.28/manual/cpack.1.html). São contratos documentados, não execução desta instalação.

## Dependencies and Reuse

Depende de [compiladores 2305](../2305/r1-native-compilers.md), [CMake/CTest 2301](../2301/r1-cmake-ctest-build.md) e ferramentas nativas do formato DEB quando o plano as selecionar. Testes usam [Qt Test 2303](../2303/r1-qttest-runner.md); CI referencia [2304](../2304/r1-github-actions.md). Consumidores: futuros planos de implementação, testes e empacotamento. Reusar kit compatível existente depois de observar versão/ABI; não instalar por mera presença do cartão.

## Removal

Manter fonte correspondente, licenças, manifestos e evidências dos pacotes distribuídos. Remover somente staging e kit dedicado autorizados, preservando instalações Qt de outros projetos. Substituição de kit requer consumidores identificados e nova qualificação do pacote; não atribuir os resultados antigos ao kit novo.
