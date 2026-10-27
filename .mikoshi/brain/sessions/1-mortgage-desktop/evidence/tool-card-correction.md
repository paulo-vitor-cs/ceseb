---
id: 1020
revision: 1
type: document
tags:
- mortgage
- tools
- correction-evidence
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Relatório da realocação de prescrições de ferramentas para seis cartões
  operacionais com evidência e limites de autoria.
use_when:
- Conferir cartões operacionais, migração de prescrições e limites das verificações
  da correção na fase 4.
---
# Correção dos cartões de ferramentas

Owner: dev-tool-cards. Flow/head: design-project-1 / tool-cards. Escopo recebido: [1017](../documents/1017/r1-design-approval-and-quality-correction.md). A arquitetura aprovada na [spec 1014 r1](../specs/1014/r1-reproducible-delivery.md) foi preservada integralmente. Nenhum requisito, decisão aprovada, índice ou arquivo do orquestrador foi editado por este autor.

## Entrega e migração

| Cartão r1 | Operação e consumidores futuros | Relação com a correção |
|---|---|---|
| [2301](../tools/2301/r1-cmake-ctest-build.md) | CMake/CTest/Ninja, planos de implementação e testes | Método de build/testes fora das obrigações funcionais |
| [2302](../tools/2302/r1-googletest-runner.md) | Runner Google Test, plano de testes do núcleo | Prescrição histórica 1222 passa a tool e referência de plano |
| [2303](../tools/2303/r1-qttest-runner.md) | Runner Qt Test, plano de testes da interface | Prescrição histórica 1223 passa a tool e referência de plano |
| [2304](../tools/2304/r1-github-actions.md) | CI e observação pelo gh, planos e workflows futuros | Prescrição histórica 1224 passa a tool e referência de plano |
| [2305](../tools/2305/r1-native-compilers.md) | GCC/MSVC, planos de build/testes | Seleção de toolchain documentada como operação |
| [2306](../tools/2306/r1-qt-deployment.md) | Kit Qt e implantação, futuros planos de pacote | Método de coleta runtime, distinto de pacote utilizável |

Todos os cartões estão draft. A seleção técnica existe no design aprovado, mas seus novos corpos não recebem aprovação automática. A proposta de obrigação contextual consta em cada cartão; nenhuma ferramenta foi ativada por metadados. Não há planos escritos: consumidores são descritos sem links fictícios. A existência dos cartões não substitui o vínculo que os futuros planos deverão declarar.

O especialista responsável pelos requisitos mantém os corpos históricos de 1222/1223/1224 e seus vínculos, com aposentadoria sob a autoridade recebida. A correção preserva as obrigações reais de comportamento financeiro, interface, uso nativo e entrega nos requisitos correspondentes; não concede pass nem transforma cobertura de ferramenta em satisfação do produto.

## Conferência de conteúdo

Foi conferido em cada um dos seis cartões: os oito títulos exatos do template; propósito com fronteira; CLI real e metavariáveis identificadas; entradas/saídas; efeitos locais/remotos e recuperação; conta/permissões/licença pertinentes; baseline e configuração; consumidor de plano pendente; obrigação contextual proposta; estado documentado/observado separado; dependências/reuso e retirada com preservação de evidências. As chamadas de produto são propostas porque não existem binários, alvos CMake ou workflows do produto.

Google Test, Qt Test e CI foram descritos como meios de engenharia, sem requisitos novos de produto ou capacidades Mikoshi fictícias. Boost permanece dependência header-only do build aprovado, sem CLI inventada. Não foram criados planos para preencher a rastreabilidade artificialmente.

## Leituras e reutilização

Lidos: mikoshi-tool r10; template de tool; dev r15; controlled-metadata; authority-and-revisions; cartões retrieval 4191 r2, artifact-check 2521 r9 e session-memory 2523 r17; fonte humana 1017; spec 1014 aprovada; corpos anteriores de 1221 a 1228. Cartões existentes Git 2570 r8 e GitHub CLI 2572 r8 foram lidos para reuso de fronteiras de autoridade e credenciais. Eles são recursos provider-local do plugin, não arquivos portáteis do repositório. Não foram copiados nem substituídos pelos seis novos cartões. A busca por nomes/aliases em resources/brain/tools não localizou cartões específicos de CMake/GoogleTest/QtTest/compiladores que pudessem ser simplesmente reutilizados.

Consulta lexical executada sobre documents/ e decisions/ da sessão explícita: resultado partial com hits pertinentes e index_incompatible. A seleção armazenada do grafo era diferente. O grafo não foi reparado e nenhuma cobertura de suas arestas foi alegada. Fontes atribuídas foram abertas pelos paths exatos. Catálogo nativo não expõe Serena ou Context7; não foram declarados como usados. A indisponibilidade não justifica falha de template.

## Consulta documental externa

Em 2026-10-26 foram abertas unidades de documentação primária para as interfaces usadas, sem alegação de leitura integral de manuais extensos:

- [CMake 3.28 CLI](https://cmake.org/cmake/help/v3.28/manual/cmake.1.html): configure/build/install; [CTest 3.28](https://cmake.org/cmake/help/v3.28/manual/ctest.1.html): seleção e JUnit; [CPack 3.28](https://cmake.org/cmake/help/v3.28/manual/cpack.1.html): geradores de pacote; [download](https://cmake.org/download/) e [Ninja](https://ninja-build.org/manual.html): canais/interfaces.
- [Google Test](https://google.github.io/googletest/advanced.html): seleção e relatório XML; documentação corrente, a requalificar no binário 1.17.0 selecionado.
- [Qt Test 6.8](https://doc.qt.io/qt-6.8/qtest-overview.html): funções e opções do runner; [instalação Qt](https://doc.qt.io/qt-6.8/get-and-install-qt.html): Qt Account/instalador e alternativa de fontes; [Windows deploy](https://doc.qt.io/qt-6.8/windows-deployment.html) e [Linux deploy](https://doc.qt.io/qt-6.8/linux-deployment.html): bibliotecas e plugins. Documentação da série pode refletir patch posterior ao pin 6.8.3.
- [GitHub workflow run](https://cli.github.com/manual/gh_workflow_run), [run view](https://cli.github.com/manual/gh_run_view), [run watch](https://cli.github.com/manual/gh_run_watch): fronteiras de leitura e disparo remoto. Help local confirmou os flags usados.
- [GCC 13 options](https://gcc.gnu.org/onlinedocs/gcc-13.4.0/gcc/Overall-Options.html) e [ambiente MSVC](https://learn.microsoft.com/en-us/cpp/build/building-on-the-command-line?view=msvc-170): compilação e prompt nativo. A página Microsoft apresentou aviso de autorização no cabeçalho junto de corpo legível; somente as seções legíveis foram usadas.

Tentativas de abrir uma página GCC específica de g++ e uma página qtpaths não foram acessíveis; não sustentam observações positivas. O comando qtpaths proposto inicialmente foi removido do cartão antes da entrega. Esta consulta documental circunscrita não retroage para declarar cumprido um ciclo de pesquisa anterior nem uma compilação de conhecimento pelo fluxo research.

## Observação local e verificações

Somente consultas de PATH, versões e help local: g++ 15.2.0, gh 2.94.0 e Git 2.53.0 foram observados no WSL. g++-13, cmake, ctest, cpack, ninja, qmake6, qtpaths6 e windeployqt não foram encontrados no PATH, sem excluir instalações fora dele. Não houve novo exame de MSVC em prompt Windows nativo. Nada foi instalado, baixado, compilado ou executado como teste de produto; nenhum workflow remoto foi consultado/disparado.

A validação de metadados e links dos seis cartões retornou:

```json
[
  {
    "path": "tools/2301/r1-cmake-ctest-build.md",
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "tools/2302/r1-googletest-runner.md",
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "tools/2303/r1-qttest-runner.md",
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "tools/2304/r1-github-actions.md",
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "tools/2305/r1-native-compilers.md",
    "result": "ok",
    "diagnostics": []
  },
  {
    "path": "tools/2306/r1-qt-deployment.md",
    "result": "ok",
    "diagnostics": []
  }
]
```

Os resultados acima são estruturais; a conferência semântica de campos está descrita separadamente. Nenhum resultado pass de requisito, benchmark, qualificação Windows/Linux, auditoria jurídica ou revisão independente foi atribuído. O relatório também retornou exit 0 / result ok no check de metadados/links, sem diagnósticos.

## Próximo responsável

Orquestrador: receber o refinamento do especialista, registrar estes seis cartões e a preservação da arquitetura aprovada. Autores de planos futuros: referenciar os cartões exatos nas operações que os consomem e obter a autoridade aplicável aos efeitos; não reconstruir prescrições de ferramentas como requisitos de produto. Memória deste head: session_memory/design/tool-cards.yaml, revisão 1.
