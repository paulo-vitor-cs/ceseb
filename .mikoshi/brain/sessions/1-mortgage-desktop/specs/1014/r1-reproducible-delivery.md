---
id: 1014
revision: 1
type: spec
tags:
- mortgage
- build
- delivery
- cross-platform
status: superseded
created: '2026-10-26'
updated: '2026-10-26'
description: Build CMake, testes GoogleTest/QtTest e pacotes com evidência nativa para a aplicação
  desktop nas plataformas declaradas.
use_when:
- Preparar ou verificar builds, testes, pacotes e documentação rastreável da calculadora nas
  duas plataformas.
---
# Entrega reproduzível Windows e Linux

Uma funcionalidade de entrega: transformar a mesma revisão de código em builds testados e pacotes identificados, com documentação suficiente para uso e reprodução. Fonte: [pedido1001](../../documents/1001/r1-human-request.md), [imagem1002](../../documents/1002/r1-image-evidence.md) e [decisão1011](../../decisions/1011/r1-complete-design-basis.md). Esta spec define alvos e evidências futuras; não cria workflow ou autoriza execução.

## Baseline proposta e composição

| Componente | Baseline proposta |
|---|---|
| Linguagem | C++20, sem extensões obrigatórias do compilador |
| Qt |6.8.3, módulos Core/Gui/Widgets; Test somente para testes; link dinâmico |
| Numérico | Boost1.86.0, cpp_dec_float_50 header-only |
| Testes de domínio | Google Test1.17.0 |
| Build | CMake >=3.28, CTest e gerador Ninja |
| Windows | Windows11 x86_64; MSVC2022/toolset v143, build Release |
| Linux | Ubuntu24.04 x86_64, GCC13, sessão desktop X11 ou XWayland, build Release |

A matriz Qt6.8 lista Windows11/MSVC2022 e Ubuntu24.04/GCC13; [arquivo oficial6.8.3](https://download.qt.io/archive/qt/6.8/6.8.3/) e [GoogleTest1.17](https://github.com/google/googletest/releases/tag/v1.17.0) confirmam versões existentes. A versão da série Qt6.8 documentada atualmente pode ter patch posterior; a baseline escolhida é6.8.3, não uma alegação de atualização automática. Arm, outras distribuições e Windows10 ficam fora da matriz qualificada deste recorte.

Alvos CMake separados: biblioteca financeira sem Qt; executável Widgets que a consome; testes GoogleTest do núcleo; testes QtTest do controlador/janela. Opção de build sem GUI deve permitir compilar/testar o núcleo sem instalar Qt. A configuração testa toolchain e encontra dependências, emitindo erro acionável se faltarem. Os planos fixarão fontes físicas; a responsabilidade pretendida é separar domínio, adaptador/apresentação e suporte de build, sem gerar um framework genérico.

Versões Qt/Boost/GoogleTest serão fixadas no mecanismo de dependências e downloads verificados por checksum/commit imutável. Não usar branches flutuantes nem um `latest` silencioso. CMake/Ninja/toolset e versão exata do compilador utilizados são registrados no log e relatório; CI declara imagens/compiladores, ações por commit e permissões mínimas de leitura. Uma mudança de pin é uma mudança explícita revisável. O build limpo pode requerer internet para obter dependências; a execução do app instalado é local.

## Verificação e evidência

GoogleTest cobre requisitos1101..1106 e1201..1207: casos normativos, limites, zero, entradas inválidas, tipos de taxa, regressões de centavos e invariantes. QtTest cobre parsing/estados/ações/foco de1211..1217 sem transformar teste da interface em teste do cálculo. CTest agrega os alvos, propaga falhas e salva logs/JUnit com revisão e ambiente. Teste de comportamento no base deve preceder implementação conforme o fluxo aprovado; erro de configuração não conta como RED. A política não atribui pass por contagem de testes ou percentual isolado de cobertura.

GitHub Actions propõe duas rotas de build/test/package: Windows x64/MSVC e Ubuntu24.04/GCC13. Nenhum job publica release automaticamente. Runner Windows hospedado pode ser Windows Server; nesse caso comprova compilação/teste naquele runner, e não o requisito de runtime Windows11. Testes de GUI com backend offscreen ou Xvfb são evidência adicional de automação e não substituem leitura e interação em desktop real. A revisão de entrega precisa do conjunto requisito→plano/tarefa→arquivos→resultado no mesmo snapshot.

A evidência final obrigatória inclui abrir e usar o pacote em Windows11 real e Ubuntu24.04 desktop, ambos sem Qt/compilador de desenvolvimento previamente configurados: exemplo1.000,00/12% nominal/3meses, mudança para efetiva, entrada inválida/correção, limpar, navegação, redimensionar e fechar. Registrar SO/arquitetura, pacote/revisão, comandos/procedimento, resultados e captura visual. WSL com display não é, por si só, essa qualificação. Se o ambiente nativo não estiver disponível, o requisito continua sem resultado e a entrega declara a lacuna.

## Pacotes e dependências de execução

Windows: ZIP portátil contendo executável Release, DLLs Qt e plugins de plataforma necessários, CRT redistribuível app-local permitido e avisos locais; extrair e iniciar o executável. A coleta usa ferramentas Qt de deploy e confere dependências transitivas. CRT não será copiado arbitrariamente: o plano usa a lista redistribuível e os termos da instalação MSVC utilizada, conforme [Microsoft](https://learn.microsoft.com/en-us/cpp/windows/redistributing-visual-cpp-files?view=msvc-170). Não exige Visual Studio ou SDK instalado no usuário final.

Ubuntu24.04: pacote `.deb` x86_64, com aplicativo e Qt6.8.3 privado em árvore própria, RPATH/caminhos de plugins locais, atalho desktop e dependências de sistema declaradas pelo empacotamento. Não substituir Qt global. Pacote pode instalar dependências runtime do Ubuntu pelo gerenciador padrão; não requer headers, compilador ou ambiente de desenvolvimento. É qualificado somente para essa distribuição. [Deploy Linux/X11](https://doc.qt.io/qt-6.8/linux-deployment.html) e [deploy CMake](https://doc.qt.io/qt-6.8/cmake-deployment.html) descrevem aspectos de bibliotecas/plugins e suporte à implantação; a completude deste pacote precisa do teste limpo indicado acima.

Falha em biblioteca/plugin, criação do pacote ou instalação retorna falha da rota com logs, sem publicar um pacote como validado. Cada arquivo de pacote e seu relatório identificam versão, plataforma e commit; não inferir equivalência de binários a partir do nome. Um download interrompido deve ser validado novamente antes de uso, sem executar arquivo incompleto. Build/pacote não altera credenciais ou trust e não faz auto-update do app.

## Licença e documentação propostas

MIT para os arquivos originais, após aprovação, preservando avisos próprios. Qt Core/Gui/Widgets dinâmicos mantêm sua licença LGPLv3; o pacote inclui GPLv3/LGPLv3 e avisos, permite substituição das bibliotecas e fornece acesso à fonte correspondente exata de Qt usada e a eventuais modificações. O inventário cobre plugins e terceiros transitivos efetivamente distribuídos. QtTest e GoogleTest não serão colocados no pacote de usuário; seus avisos e licenças permanecem nos materiais de build. Incluir licença Boost e aviso GoogleTest ao distribuir seus fontes. MIT do app não relicencia esses materiais. Fontes primárias: [Qt licensing](https://doc.qt.io/qt-6.8/licensing.html), [LGPLv3](https://doc.qt.io/qt-6.8/lgpl.html), [MIT](https://opensource.org/license/mit), [Boost license](https://www.boost.org/LICENSE_1_0.txt), [GoogleTest license](https://github.com/google/googletest/blob/v1.17.0/LICENSE). Nenhuma licença foi ativada por este documento.

Documentação em português: instalar/usar; compilar/testar em cada plataforma; fórmulas e política de centavos; limites/exclusões; exemplo comparativo; dependências/licenças; relatório técnico de rastreabilidade e resultados por requisito/plataforma, com lacunas e resultados negativos. Os comandos publicados devem ser executados no ambiente declarado antes de receber marca de verificados. As specs guardam arquitetura; o relatório guarda observações, sem reescrever oráculos para refletir resultados.

## Estado atual e requisitos

A [exploração](../../evidence/initial-exploration.md) observou apenas GCC no WSL, sem as dependências de build/teste nas verificações feitas. CMake, Qt, Boost ou GoogleTest não foram instalados aqui. Native Serena/Context7 não estão expostos. Não há código, pacote, CI ou teste de produto executado.

Requisitos: [1221](../../requirements/1221/r1-build-contract.md), [1222](../../requirements/1222/r1-core-test-suite.md), [1223](../../requirements/1223/r1-gui-test-suite.md), [1224](../../requirements/1224/r1-ci-evidence.md), [1225](../../requirements/1225/r1-runtime-packages.md), [1226](../../requirements/1226/r1-native-smoke.md), [1227](../../requirements/1227/r1-technical-documentation.md), [1228](../../requirements/1228/r1-distribution-notices.md). Fontes externas acessadas em2026-10-26. Planos futuros, instalação e publicação têm seus próprios efeitos e aprovações.
