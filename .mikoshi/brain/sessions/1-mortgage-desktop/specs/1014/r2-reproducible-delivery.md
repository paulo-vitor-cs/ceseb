---
id: 1014
revision: 2
type: spec
tags:
- mortgage
- build
- delivery
- cross-platform
status: partial implemented
created: '2026-10-26'
updated: 2026-10-26
description: Baseline proposta Qt 6.12.0 com Widgets dinâmico, fronteiras numéricas exatas e
  entrega Windows/Linux rastreável.
use_when:
- Preparar os planos de build, testes e distribuição após resolver a revisão Qt e o método numérico.
---
# Entrega reproduzível Windows e Linux

Uma funcionalidade de entrega: transformar a mesma revisão de código em builds testados e pacotes identificados, com documentação suficiente para uso e reprodução. Fonte: [pedido 1001](../../documents/1001/r1-human-request.md), [imagem 1002](../../documents/1002/r1-image-evidence.md) e [decisão 1011](../../decisions/1011/r1-complete-design-basis.md). Esta revisão proposta decorre da [análise 1024](../../documents/1024/r1-qt-baseline-review.md) e da [decisão aberta 1026](../../decisions/1026/r1-qt-baseline-choice.md); preserva [r1 aceita](r1-reproducible-delivery.md) e não herda sua aprovação. Esta spec define alvos e evidências futuras; não cria workflow ou autoriza execução.

## Baseline proposta e composição

| Componente | Baseline proposta |
|---|---|
| Linguagem | C++20, sem extensões obrigatórias do compilador |
| Qt | 6.12.0 oficial; kits base 6.12.0-0-202609280346; módulos Core/Gui/Widgets; Test somente para testes; link dinâmico |
| Numérico | Boost 1.86.0 Multiprecision header-only; cpp_int para fronteiras exatas conforme as specs numéricas sucessoras; aproximações decimais não decidem empates monetários |
| Testes de domínio | Google Test 1.17.0 |
| Build | CMake >= 3.28, CTest e gerador Ninja |
| Windows | Windows 11 x86_64; MSVC 2022/toolset v143, build Release |
| Linux | Ubuntu 24.04 x86_64, GCC 13, sessão desktop X11 ou XWayland, build Release |

A [matriz da tag v6.12.0](https://raw.githubusercontent.com/qt/qtdoc/v6.12.0/doc/src/platforms/supported-platforms.qdocinc) lista Windows 11 x64/MSVC 2022 e Ubuntu 24.04 x64/GCC 13. O [anúncio de 30/09/2026](https://www.qt.io/blog/qt-6.12-released) e o [arquivo oficial de fontes](https://download.qt.io/official_releases/qt/6.12/6.12.0/submodules/) identificam a release. Os [metadados Windows](https://download.qt.io/online/qtsdkrepository/windows_x86/desktop/qt6_6120/qt6_6120_msvc2022_64/Updates.xml) e [Linux](https://download.qt.io/online/qtsdkrepository/linux_x64/desktop/qt6_6120/qt6_6120/Updates.xml) identificam os dois kits base. A [observação de acesso](../../evidence/qt-baseline-review/access-observation.json) registrou HEAD 200; nenhum kit foi baixado ou executado. Arm, outras distribuições e Windows 10 ficam fora da matriz qualificada deste recorte.

A obtenção proposta usa o kit oficial sem patchset próprio. O plano fixa origem, identidade do build, componentes e hashes verificados; confirma conta/termos da rota escolhida sem criar credenciais por inferência. A existência de kit público não promete instalador sem conta. O build de Qt a partir de fontes fica como alternativa que requer revisão explícita se necessária. Qt Creator, documentação e exemplos oferecidos pelo instalador não são dependências runtime do app; o pacote contém somente componentes efetivamente necessários.

Manter Widgets/Fusion em C++ não exige funcionalidades novas da série. A mudança de pin não promete todos os futuros patches LTS, suporte comercial adquirido ou ausência global de vulnerabilidades. O [diff oficial CVE-2026-105924](https://download.qt.io/official_releases/qt/6.12/CVE-2026-105924-qtbase-6.12.diff) foi observado após a release: corrige conversão CBOR/JSON; o design não importa esses dados, mas a análise do código e pacote reais deve confrontar a superfície antes da entrega. Se houver caminho afetado, falha de acesso/ABI/licença ou necessidade de patch, registrar nova escolha antes de distribuir, sem substituir silenciosamente o pin. A avaliação concreta é parte do plano de dependências/empacotamento, não um requisito que prescreve ferramenta.

Alvos CMake separados: biblioteca financeira sem Qt; executável Widgets que a consome; testes GoogleTest do núcleo; testes QtTest do controlador/janela. Opção de build sem GUI deve permitir compilar/testar o núcleo sem instalar Qt. A configuração testa toolchain e encontra dependências, emitindo erro acionável se faltarem. Os planos fixarão fontes físicas; a responsabilidade pretendida é separar domínio, adaptador/apresentação e suporte de build, sem gerar um framework genérico.

Versões Qt/Boost/GoogleTest serão fixadas no mecanismo de dependências e downloads verificados por checksum/commit imutável. Não usar branches flutuantes nem um `latest` silencioso. CMake/Ninja/toolset e versão exata do compilador utilizados são registrados no log e relatório; CI declara imagens/compiladores, ações por commit e permissões mínimas de leitura. Uma mudança de pin é uma mudança explícita revisável. O build limpo pode requerer internet para obter dependências; a execução do app instalado é local.

## Verificação e evidência

GoogleTest cobre requisitos 1101..1106 e 1201..1207: casos normativos, limites, zero, entradas inválidas, tipos de taxa, regressões de centavos e invariantes. QtTest cobre parsing/estados/ações/foco de 1211..1217 sem transformar teste da interface em teste do cálculo. CTest agrega os alvos, propaga falhas e salva logs/JUnit com revisão e ambiente. A seleção vazia não conta como sucesso: usar `--no-tests=error` e conferir os casos esperados nos logs. Asserções monetárias comparam centavos inteiros; relações numéricas não devem perder precisão por conversão a double no runner. Teste de comportamento no base deve preceder implementação conforme o fluxo aprovado; erro de configuração não conta como RED. A política não atribui pass por contagem de testes ou percentual isolado de cobertura.

GitHub Actions propõe duas rotas de build/test/package: Windows x64/MSVC e Ubuntu 24.04/GCC 13. Nenhum job publica release automaticamente. Runner Windows hospedado pode ser Windows Server; nesse caso comprova compilação/teste naquele runner, e não o requisito de runtime Windows 11. Testes de GUI com backend offscreen ou Xvfb são evidência adicional de automação e não substituem leitura e interação em desktop real. A revisão de entrega precisa do conjunto requisito→plano/tarefa→arquivos→resultado no mesmo snapshot.

A evidência final obrigatória inclui abrir e usar o pacote em Windows 11 real e Ubuntu 24.04 desktop, ambos sem Qt/compilador de desenvolvimento previamente configurados: exemplo 1.000,00/12% nominal/3 meses, mudança para efetiva, entrada inválida/correção, limpar, navegação, redimensionar e fechar. Registrar SO/arquitetura, pacote/revisão, comandos/procedimento, resultados e captura visual. WSL com display não é, por si só, essa qualificação. Se o ambiente nativo não estiver disponível, o requisito continua sem resultado e a entrega declara a lacuna.

## Pacotes e dependências de execução

Windows: ZIP portátil contendo executável Release, DLLs Qt e plugins de plataforma necessários, CRT redistribuível app-local permitido e avisos locais; extrair e iniciar o executável. A coleta usa ferramentas Qt de deploy e confere dependências transitivas. CRT não será copiado arbitrariamente: o plano usa a lista redistribuível e os termos da instalação MSVC utilizada, conforme [Microsoft](https://learn.microsoft.com/en-us/cpp/windows/redistributing-visual-cpp-files?view=msvc-170). Não exige Visual Studio ou SDK instalado no usuário final.

Ubuntu 24.04: pacote `.deb` x86_64, com aplicativo e Qt 6.12.0 privado em árvore própria, RPATH/caminhos de plugins locais, atalho desktop e dependências de sistema declaradas pelo empacotamento. Não substituir Qt global. Pacote pode instalar dependências runtime do Ubuntu pelo gerenciador padrão; não requer headers, compilador ou ambiente de desenvolvimento. É qualificado somente para essa distribuição. [Deploy Linux/X11](https://doc.qt.io/qt-6.12/linux-deployment.html) e [deploy CMake](https://doc.qt.io/qt-6.12/cmake-deployment.html) descrevem aspectos de bibliotecas/plugins e suporte à implantação; a completude deste pacote precisa do teste limpo indicado acima.

Falha em biblioteca/plugin, criação do pacote ou instalação retorna falha da rota com logs, sem publicar um pacote como validado. Cada arquivo de pacote e seu relatório identificam versão, plataforma e commit; não inferir equivalência de binários a partir do nome. Um download interrompido deve ser validado novamente antes de uso, sem executar arquivo incompleto. Build/pacote não altera credenciais ou trust e não faz auto-update do app.

## Licença e documentação propostas

MIT para os arquivos originais, após aprovação, preservando avisos próprios. Qt Core/Gui/Widgets dinâmicos mantêm sua licença LGPLv3; o pacote inclui GPLv3/LGPLv3 e avisos, permite substituição das bibliotecas e fornece acesso à fonte correspondente exata de Qt usada e a eventuais modificações. O inventário cobre plugins e terceiros transitivos efetivamente distribuídos. QtTest e GoogleTest não serão colocados no pacote de usuário; seus avisos e licenças permanecem nos materiais de build. Incluir licença Boost e aviso GoogleTest ao distribuir seus fontes. MIT do app não relicencia esses materiais. Fontes primárias: [Qt licensing](https://doc.qt.io/qt-6.12/licensing.html), [LGPLv3](https://doc.qt.io/qt-6.12/lgpl.html), [MIT](https://opensource.org/license/mit), [Boost license](https://www.boost.org/LICENSE_1_0.txt), [GoogleTest license](https://github.com/google/googletest/blob/v1.17.0/LICENSE). Nenhuma licença foi ativada por este documento.

Documentação em português: instalar/usar; compilar/testar em cada plataforma; fórmulas e política de centavos; limites/exclusões; exemplo comparativo; dependências/licenças; relatório técnico de rastreabilidade e resultados por requisito/plataforma, com lacunas e resultados negativos. Os comandos publicados devem ser executados no ambiente declarado antes de receber marca de verificados. As specs guardam arquitetura; o relatório guarda observações, sem reescrever oráculos para refletir resultados.

## Estado atual e requisitos

A [exploração](../../evidence/initial-exploration.md) observou apenas GCC no WSL, sem as dependências de build/teste nas verificações feitas. CMake, Qt, Boost ou GoogleTest não foram instalados aqui. Native Serena/Context7 não estão expostos. Não há código, pacote, CI ou teste de produto executado.

Requisitos efetivos reutilizados: [1221](../../requirements/1221/r1-build-contract.md), [1225](../../requirements/1225/r1-runtime-packages.md), [1226](../../requirements/1226/r1-native-smoke.md), [1227](../../requirements/1227/r1-technical-documentation.md) e [1228](../../requirements/1228/r1-distribution-notices.md). Os requisitos históricos 1222 a 1224 permanecem obsolete; a sucessora não os reinclui. Ferramentas de engenharia: [2301 CMake/CTest](../../tools/2301/r1-cmake-ctest-build.md), [2302 GoogleTest](../../tools/2302/r1-googletest-runner.md), [2303 QtTest](../../tools/2303/r1-qttest-runner.md), [2304 Actions](../../tools/2304/r1-github-actions.md), [2305 compiladores](../../tools/2305/r1-native-compilers.md), [2306 Qt/deploy](../../tools/2306/r1-qt-deployment.md); os planos futuros selecionam seus consumidores e operações.

As specs [1008 r2](../1008/r2-annual-rate-conversion.md) e [1012 r2](../1012/r2-amortization-comparison.md) definem o método exato e seus limites; a [interface 1013 r2](../1013/r2-widgets-interface.md) recebe a quantização percentual exata; este contrato de entrega não altera fórmulas/oráculos financeiros. A revisão de Qt propõe apenas a baseline e condições verificáveis de obtenção/manutenção. Fontes externas consultadas em 2026-10-26. Aprovação desta revisão e aprovação dos planos têm efeitos distintos; não houve instalação, produto ou publicação por este rascunho.
