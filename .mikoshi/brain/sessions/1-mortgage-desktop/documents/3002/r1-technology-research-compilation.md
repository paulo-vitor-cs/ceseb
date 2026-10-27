---
id: 3002
revision: 1
type: document
tags:
- mortgage
- research
- technology
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Pesquisa documental da baseline C++ e Qt, precisão decimal, parsing e execução de testes da calculadora.
use_when:
- Analisar compatibilidade, limites numéricos e lacunas de validação da baseline aprovada antes de planejar implementação.
---
# Compilação TECH — baseline e fronteiras observáveis

Owner: scout-technology. MAIN: `/home/paulo/ceseb`. Sessão: `1-mortgage-desktop`. Flow/head: `research-project-basis/research-technology`. Pesquisa em 2026-10-26, America/Sao_Paulo. Autoridade: [1021 r1](../1021/r1-pending-research-authority.md). Design aprovado: [1017 r1](../1017/r1-design-approval-and-quality-correction.md); cobertura efetiva: [1015 r2](../1015/r2-refined-requirement-index.md).

## Resultado delimitado

A combinação escolhida tem interfaces documentais compatíveis com o recorte. A matriz **fixada em Qt 6.8.3**, e não apenas a página corrente, inclui Windows 11 x64/MSVC 2022 e Ubuntu 24.04/GCC 13. CMake 3.28 supera os mínimos documentados de Qt compartilhado e GoogleTest 1.17. A separação núcleo C++/adaptador Widgets pode realizar a independência de Qt. Isso é suporte documental e inferência arquitetural, sem build ou uso nativo observado.

Há uma lacuna material: **50 dígitos decimais não garantem o arredondamento half-up matematicamente exato de todos os juros**. Outra divergência concreta de semântica: a formatação de precisão do backend Boost usa empate para par; [1212 r1](../../requirements/1212/r1-rate-presentation.md) exige half-up. Os componentes podem ser usados, mas não substituem a política de arredondamento e a gramática de entrada da aplicação. Nenhuma falha do produto foi observada, pois não existe execução autorizada nesta rodada.

## Perguntas, método e acesso real

Subperguntas: compatibilidade por versão/plataforma; garantias e limites de decimal50; texto, moeda e apresentação percentual; isolamento de Qt; APIs/flags dos runners; evidência que desafia o caminho mais simples. Widgets permanece a escolha humana. O estudo não compara novamente Widgets/QML como preferência.

Leitura local: documentos 1001/1005/1017/1021, índice 1015 r2, specs 1008/1012/1013/1014 r1, os 25 requisitos efetivos e tools 2301..2305 r1. Relatórios `initial-exploration.md`, `financial-design.md` e `full-architecture.md` foram sementes, com seus limites históricos preservados. Os requisitos obsolete 1222..1224 não foram usados como critérios atuais. Não havia knowledge local a reutilizar no início desta pesquisa; consulta lexical e inspeção do diretório precederam as notas novas.

A consulta local foi `cpp_dec_float Qt CMake rounding precision testing`, com `mikoshi retrieval search`, root explícito, sessão completa e seis `--corpus` separados: documents, decisions, specs, requirements, tools e knowledge desta sessão. Resultado `partial`, lexical disponível, grafo indisponível por `index_incompatible: Stored selection/profile differs`. Resultado integral: [retrieval.json](../../evidence/research/technology/retrieval.json). Não houve reparo ou rebuild do índice. Os corpos de domínio foram abertos por referência, além dos hits.

O catálogo atual expõe `web__run`, efetivamente usado em busca, abertura, find e expansão por link. Não expõe Context7, Tavily, Exa, Brave ou Fetch MCP. `ctx7` não está no PATH, reobservado nesta pesquisa. Foram lidos Context7 2560 r10, matriz de rotas e cartões 3407/3408/3409/3431 nas seções de contrato/acesso/gatilho; não foram criados conta, chave ou configuração. A ausência de interface nativa e o acesso não qualificado dessas rotas são gaps, não resultados vazios de busca. Fontes oficiais via web são o fallback permitido por 1021; não satisfazem ficticiamente uma operação Context7. Não houve necessidade de converter documentos locais, renderização interativa ou corpus acadêmico; os demais gatilhos da matriz não foram acionados.

### Consultas externas realmente enviadas

| Ordem | Consulta literal | Motivo e expansão |
|---|---|---|
| Q1 | `site.boost.org 1_86 cpp_dec_float guard digits truncating rounding string conversion` | Precisão, truncamento e entrada; expansão direta para manual 1.86 e tag boost-1.86.0. |
| Q2 | `site.doc.qt.io qt 6.8 supported platforms Ubuntu 24.04 GCC 13 MSVC 2022` | Matriz; a página corrente levou à conferência das fontes qtdoc v6.8.3. |
| Q3 | `site.github.com/google/googletest v1.17.0 C++17 MSVC` | Release e requisito de linguagem; expansão para fonte/CMake/docs da tag. |
| Q4 | `site.github.com/boostorg/multiprecision/issues cpp_dec_float rounding division precision` | Contraevidência; abriu issue 368, incluindo respostas de mantenedores e revisões históricas. |
| Q5 | `site.boost.org/doc/libs/1_86_0 log1p expm1 multiprecision` | Estabilidade em taxas pequenas; fontes 1.86 abertas diretamente. |
| Q6 | `site.qt.io/blog "Qt 6.8.3" "released"` | Data e patch; blog levou por link às release notes oficiais. |
| Q7 | `site.github.com/qt/qtbase "6.8.3" "junitxml"` | Runner fixado; conferência direta em qtestcase.cpp v6.8.3. |

Foram usadas sementes primárias independentes por componente: Boost, Qt, GoogleTest e Kitware/CMake. Não se contam manual, implementação e issue do mesmo projeto como três reproduções independentes. A busca também trouxe fontes secundárias e versões latest; elas foram descartadas como base decisiva quando havia original fixado.

## Mapa de unidades efetivamente lidas

Todas as fontes abaixo foram acessadas em 2026-10-26. “Parcial” significa a unidade indicada, não leitura integral do manual/repositório. As respostas relevantes e seus limites estão em [extrações iniciais](../../evidence/research/technology/source-access-extracts.json) e [seguimento](../../evidence/research/technology/source-access-followup.json); não são prova de execução.

| ID | Fonte exata e revisão | Unidade e leitura | Papel |
|---|---|---|---|
| B1 | [Boost cpp_dec_float 1.86](https://www.boost.org/doc/libs/1_86_0/libs/multiprecision/doc/html/boost_multiprecision/tut/floats/cpp_dec_float.html) | Página curta integral: tipo, precisão, exceção de string, guard digits, NaN/inf, truncamento. | Contrato do fornecedor. |
| B2 | [cpp_dec_float.hpp boost-1.86.0](https://github.com/boostorg/multiprecision/blob/boost-1.86.0/include/boost/multiprecision/cpp_dec_float.hpp) | Parcial: constantes/limbs 79..110; divisão 921..962, 1040..1188; str 1761..1917; parser 1920..2005; floor 3081..3095; numeric_limits 3270..3316. | Implementação fixada; sem execução. |
| B3 | [Issue Multiprecision 368](https://github.com/boostorg/multiprecision/issues/368) | Parcial: corpo e respostas de 2021, confirmação/correção parcial 1.76/1.77, confirmação 1.78 em 2022, resposta do mantenedor de 18/01/2024. | Relatos históricos e avaliação do mantenedor. |
| B4 | [Issue Boost 929](https://github.com/boostorg/boost/issues/929) | Corpo integral, exemplo declarado em 1.85, sem resposta de mantenedor visível. | Relato do usuário; não prova do pin. |
| B5 | [log1p 1.86](https://www.boost.org/doc/libs/1_86_0/libs/math/doc/html/math_toolkit/powers/log1p.html), [expm1 1.86](https://www.boost.org/doc/libs/1_86_0/libs/math/doc/html/math_toolkit/powers/expm1.html) | Páginas integrais de API, cancelamento, política, testes/limites. | Mecanismo e documentação numérica. |
| B6 | [Release Boost 1.86](https://www.boost.org/releases/1.86.0/) | Parcial: mudanças Multiprecision e lista de compiladores testados. | Changelog; não matriz de aprovação do app. |
| Q8 | [Matriz qtdoc v6.8.3](https://github.com/qt/qtdoc/blob/v6.8.3/doc/src/platforms/supported-platforms.qdocinc), [página fonte v6.8.3](https://github.com/qt/qtdoc/blob/v6.8.3/doc/src/platforms/supported-platforms.qdoc) | Seções desktop, condições de suporte e disponibilidade, linhas 8..94/8..50; parcial. | Matriz do pin. |
| Q9 | [Matriz Qt 6.8 corrente](https://doc.qt.io/qt-6.8/supported-platforms.html), [QLocale corrente](https://doc.qt.io/qt-6.8/qlocale.html) | Matriz desktop e APIs numéricas; parcial; páginas identificam série/patch corrente, QLocale 6.8.9. | Evidência de drift. |
| Q10 | [qlocale.h v6.8.3](https://github.com/qt/qtbase/blob/v6.8.3/src/corelib/text/qlocale.h), [qlocale.cpp v6.8.3](https://github.com/qt/qtbase/blob/v6.8.3/src/corelib/text/qlocale.cpp) | Declarações numéricas/currency; corpos currency 4332..4412; parcial. | Tipos, unidade de formatação. |
| Q11 | [qvalidator.cpp v6.8.3](https://github.com/qt/qtbase/blob/v6.8.3/src/gui/util/qvalidator.cpp) | QDoubleValidator 471..677; parcial. | Gramática/defaults/fixup/conversão. |
| Q12 | [qlineedit.cpp v6.8.3](https://github.com/qt/qtbase/blob/v6.8.3/src/widgets/widgets/qlineedit.cpp) | Sinais, validator/Enter, textChanged/textEdited; parcial. | Estados e teclado. |
| Q13 | [qtestcase.cpp v6.8.3](https://github.com/qt/qtbase/blob/v6.8.3/src/testlib/qtestcase.cpp) | CLI -functions/-o/junitxml 675..751 e retorno 1819..1883; parcial. | Runner fixado. |
| Q14 | [Widgets 6.8](https://doc.qt.io/qt-6.8/qtwidgets-index.html), [High DPI 6.8](https://doc.qt.io/qt-6.8/highdpi.html) | Styles/layouts/uso CMake e modelo de coordenadas 137..168; parcial, corrente. | Capacidade e limites de UI. |
| Q15 | [QtBase .cmake.conf v6.8.3](https://github.com/qt/qtbase/blob/v6.8.3/.cmake.conf) | Arquivo curto integral, versão e mínimos Qt compartilhado. | Compatibilidade CMake fixada. |
| Q16 | [Qt 6.8.3 release notes](https://code.qt.io/cgit/qt/qtreleasenotes.git/about/qt/6.8.3/release-note.md), [anúncio](https://www.qt.io/blog/qt-6.8.3-released) | Anúncio integral; notes: introdução, qtbase/CLDR e lista de correções qtbase até a seção seguinte; parcial. | Expansão por citação e changelog. |
| G1 | [GoogleTest v1.17 release](https://github.com/google/googletest/releases/tag/v1.17.0), [CMake raiz fixado](https://github.com/google/googletest/blob/v1.17.0/CMakeLists.txt) | Notas de release; versão/mínimo do CMake raiz e opção CRT em googletest/CMakeLists; parcial. | C++17 mínimo, CMake 3.16, CRT. |
| G2 | [advanced.md v1.17.0](https://github.com/google/googletest/blob/v1.17.0/docs/advanced.md) | Filtros/listagem, disabled, no-test-linked e XML 1640..1750/1896..1972; parcial. | Flags do pin. |
| G3 | [gtest.h v1.17.0](https://github.com/google/googletest/blob/v1.17.0/googletest/include/gtest/gtest.h), [gtest-port.h](https://github.com/google/googletest/blob/v1.17.0/googletest/include/gtest/internal/gtest-port.h) | DoubleNearPredFormat 1470..1477/macros 1820..1839; linguagem 253..263; parcial. | Precisão da asserção e linguagem. |
| C1 | [CTest 3.28](https://cmake.org/cmake/help/v3.28/manual/ctest.1.html) | Opções test-dir/config/output/failure/JUnit/no-tests e listagem; parcial. | Semântica CLI. |
| C2 | [GoogleTest module 3.28](https://cmake.org/cmake/help/v3.28/module/GoogleTest.html) | Seções de descoberta, XML e execução paralela; parcial. | Integração e limites. |
| C3 | [CXX_STANDARD 3.28](https://cmake.org/cmake/help/v3.28/prop_tgt/CXX_STANDARD.html), [Ninja 3.28](https://cmake.org/cmake/help/v3.28/generator/Ninja.html) | Páginas curtas integrais; find_package apenas assinatura/versionamento. | Composição e opções. |

Tentativas sem corpo útil: página Boost `map_nc.html` retornou erro interno; caminho QtBase presumido para `supported-platforms.qdocinc` retornou 404, recuperado no qtdoc correto. Isso não prova ausência das capacidades. Não foi lido integralmente qualquer repositório, manual geral Qt/CMake ou histórico total de issues.

## Claims, contraprovas e interfaces afetadas

### T1 — versões e compiladores

Q8 confirma as duas configurações escolhidas. Q15 e G1 registram mínimos CMake 3.16 para os usos pertinentes, abaixo de 3.28. G1/G3 exigem pelo menos C++17, compatível com o C++20 escolhido. B6 lista VC14.3; sua lista de GCC C++20 vai até 12, portanto não comprova especificamente GCC 13. Não se infere incompatibilidade dessa ausência. Qt, Boost, GoogleTest e CMake separadamente não demonstram o conjunto compilado. Exatos MSVC/GCC, ABI, SDK, runtime e versões CMake/Ninja continuam para futura qualificação.

**Classificação:** convergência documental com lacuna de execução; Q9 é drift de documentação, não troca autorizada do pin. Afeta [1014](../../specs/1014/r1-reproducible-delivery.md) e tools 2301/2305. CMake `>=3.28` é limite mínimo, não garantia de comportamento de toda versão futura. Selecionar e registrar uma versão efetivamente executada continua necessário.

Q16 registra CLDR 46.1 e correções de fonte/estilos/testes em 6.8.3. Os títulos de fixes não foram usados para afirmar que a aplicação está afetada ou que não há regressões restantes. O anúncio comercial e o pin não qualificam manutenção, pacote ou licença, temas de DIST. Diferença entre notas glibc da documentação fonte fixada e página móvel foi encaminhada ao scout DIST, sem diagnóstico de incompatibilidade binária.

### T2 — decimal50 e half-up monetário

B1 declara ponto flutuante decimal finito, guard digits, truncamento e NaN/inf. B2 usa armazenamento finito, divisão geral por inversa iterativa e `floor` sobre o valor representado. Nada disso é contrato de arredondamento decimal financeiro corretamente arredondado. B3 contém confirmação do mantenedor de problemas históricos de divisão seguida de floor/ceil; exemplos mudam entre 1.76/1.77 e retornam em outros casos. B4 refere 1.85, sem confirmação do mantenedor. Não são reprodução em 1.86/MSVC 2022/GCC 13.

**Inferência analítica, coordenada com FIN:** para principal 6 centavos, nominal anual 100%, prazo 1, m exato = 1/12 e juros exatos = 0,5 centavo; half-up exige 1 centavo e pagamento 7. Uma aproximação abaixo do empate pode mudar o inteiro arredondado. Operações posteriores podem também arredondar a aproximação novamente, portanto a direção/resultado do programa concreto não foi deduzida como falha confirmada. “Não arredondar a taxa” significa preservar toda a precisão disponível, não representar exatamente toda fração recorrente.

A tolerância mensal 1e-12 permite até 0,01 centavo de diferença no produto B*m quando B=10^10 centavos. Mesmo erro menor pode cruzar empate; o critério de taxa não implica o oráculo monetário exato. O exemplo aprovado de 6% nominal tem m terminante e não discrimina 1/12. **Classificação:** garantia não demonstrada, material para specs [1008](../../specs/1008/r1-annual-rate-conversion.md)/[1012](../../specs/1012/r1-amortization-comparison.md), 1102/1106/1202..1206. O consumidor specialist deve resolver o método de certificação/empates antes de afirmar precisão global. Nenhuma substituição de biblioteca foi selecionada.

### T3 — taxas pequenas, extrema e construção

B5 fornece operações templadas `log1p`/`expm1` para reduzir cancelamento. Sua documentação não é erro máximo provado para todas as expressões decimal50 nos dois compiladores. Para m>0, a forma analiticamente equivalente `P*m / -expm1(-n*log1p(m))` evita formar diretamente `1-(1+m)^(-n)`; zero continua ramo separado. É meio candidato, não mudança do modelo. Usar argumentos decimais materializados evita que constantes/overloads inteiros levem ao tipo errado.

O menor percentual positivo da GUI com seis casas é 0,000001%, mas a interface tipada de 1008 não declara esse piso: taxas positivas representáveis muito menores podem perder incremento em `1+x`. Testar apenas a GUI não fecha o domínio tipado. B1/B2 confirmam parser decimal e suporte a não finitos: texto canônico deve ser construído sem passar por double; valores não finitos precisam ser recusados explicitamente antes de comparações de faixa. Literal C++ `0.1` nasce como double; dígitos adicionais não recuperam a intenção decimal perdida.

**Inferência de intervalo, não experimento:** em taxas não negativas deste domínio, m<=1/12, saldo<=10^10 centavos, até 600 linhas. Juros mensais ficam abaixo de 833.333.334 centavos; principal mais 600 desses limites fica abaixo de 5,11e11 centavos e int64. Isso favorece centavos inteiros, mas não prova o código, arredondamento, conversões ou operações intermediárias. Entradas fora de domínio e underflow/overflow do backend ainda exigem tratamento. Afeta 1103/1105, 1201/1204/1206 e ArithmeticError. A escolha de estabilidade e o teste pertencem a planos posteriores.

### T4 — texto e moeda não são fornecidos automaticamente pelo locale

Q11 mostra QDoubleValidator com notação científica padrão, aceitação de separadores de grupo sem verificar sua posição e conversão double. Seu fixup pode modificar precisão textual. Isso diverge de usar esse componente sozinho para a gramática estrita de [1211](../../requirements/1211/r1-localized-input.md), que recusa expoente/sinal, agrupamento inválido e sétima casa sem truncar. Q10 oferece overloads monetários integrais e double, sem overload em centavos fracionários nem decimal50; inteiro 100 representa a unidade monetária 100, não 100 centavos.

**Inferência arquitetural:** o MoneyCodec aprovado precisa validar a gramática, acumular dígitos inteiros com limite antes de converter e compor reais/centavos na saída. A taxa validada pode virar texto decimal canônico para Boost. Formatar percentuais é outra política. Isso é trabalho local substantivo, embora pequeno; “Qt tem locale” não o elimina. Sem passagem monetária por double, usando a mesma representação para toda comparação e mantendo diferença assinada, a fronteira é realizável. Não há necessidade documental de introduzir framework ou serviço adicional.

### T5 — seis casas half-up divergem do formatter genérico

B2 implementa desempate para par em `str` de precisão. Isso difere do half-up de 1212. Exemplo analítico aceito na gramática: anual nominal 0,000006% -> mensal percentual exato 0,0000005% -> exibição half-up `0,000001%`. Um formatter de empate para par sobre o valor decimal exato produz `0,000000%`. Para o pipeline completo, a divisão anterior também pode perturbar a fronteira; o resultado concreto permanece não observado. A validação futura deve separar fixture exata do formatter e conversão end-to-end. **Classificação:** divergência demonstrada na semântica do método genérico, não falha observada da aplicação; 1013/1212 e futuro adaptador. Política explícita de quantização antes do texto é necessária; não mudar 1212 para acomodar o default.

### T6 — UI e independência do núcleo

Q14 sustenta widgets/layouts e coordenadas lógicas. Isso permite compor cartões, foco e rolagem, mas não garante acesso a 800x600/200%, fonte legível, seleção de texto ou navegação final. Q12 distingue `textChanged` de `textEdited` e condiciona sinais de Enter ao estado Acceptable do validator: ligar Calcular somente a returnPressed pode ocultar a recuperação de entrada inválida. A futura composição precisa preservar [1214](../../requirements/1214/r1-ui-state-recovery.md)/[1215](../../requirements/1215/r1-keyboard-navigation.md), com caminho de validação comum às ações. Escape de QMainWindow e conteúdo selecionável também exigem configuração/comportamento explícito.

**Inferência de arquitetura:** Qt deve ser descoberto apenas quando GUI/teste de GUI estiver habilitado; interfaces financeiras devem usar tipos C++/Boost, sem QString/QObject. Linkar Widgets apenas ao executável/adaptador e QtTest apenas ao teste torna possível [1221](../../requirements/1221/r1-build-contract.md). Um find_package(Qt6 REQUIRED) incondicional na raiz impediria o build sem Qt mesmo que a biblioteca não ligasse Qt. C3 recomenda impedir decay do padrão e desligar extensões; isso deve ser conferido no futuro build. Não foi criado CMakeLists nem validada latência; 600 meses limita iterações, não tempo de UI medido.

### T7 — runners e relatórios

G2 confirma `--gtest_list_tests`, wildcard `--gtest_filter` e `--gtest_output=xml:path`; disabled/skips e filtros vazios precisam aparecer na interpretação. G1 adiciona `--gtest_fail_if_no_test_linked`, que não prova que um filtro selecionou caso. G3 mostra EXPECT_NEAR usando double; um predicado de erro absoluto calculado no tipo decimal preserva o critério, enquanto centavos requerem igualdade inteira. Não usar coerção a double como oráculo de precisão decimal.

Q13 confirma `-functions`, seleção por função e `-o path,junitxml` no pin 6.8.3, retorno não zero em falha e limite de exit code. C1 confirma JUnit em 3.28, mas uma chamada normal sem testes pode retornar sucesso; futuro plano deve adicionar `--no-tests=error` ou verificação explícita da seleção. C2 descobre testes executando o binário, diferencia POST_BUILD/PRE_TEST e recomenda XML_OUTPUT_DIR para evitar colisão de XML em execução paralela. GoogleTest e CTest podem gerar relatórios em granularidades diferentes; preservar ambos quando necessários ao trace.

**Classificação:** contratos de flags confirmados em fonte; perigos de interpretação/defaults, não exigências funcionais novas. Afeta tools [2301](../../tools/2301/r1-cmake-ctest-build.md), [2302](../../tools/2302/r1-googletest-runner.md), [2303](../../tools/2303/r1-qttest-runner.md), [2304](../../tools/2304/r1-github-actions.md), futuros planos e 1227. QtTest com display virtual/offscreen não substitui 1215/1216/1226 nativos, já exigidos pelo design. Windows requer runtime/ABI coerente com GoogleTest; G1 fornece opção de CRT, sem escolher instalação nesta pesquisa.

## Conhecimento novo e reutilização

Notas completas em draft: [3121 precisão e empates](../../knowledge/3121/r1-decimal-backend-rounding-boundary.md), [3122 gramática e moeda](../../knowledge/3122/r1-qt-text-money-boundary.md), [3123 runners e evidência](../../knowledge/3123/r1-test-runner-evidence-semantics.md), [3124 versões e isolamento](../../knowledge/3124/r1-pinned-baseline-core-isolation.md), [3125 estabilidade](../../knowledge/3125/r1-small-rate-evaluation.md), [3126 apresentação half-up](../../knowledge/3126/r1-explicit-percentage-rounding.md). As notas separam garantias do backend, UI, runner, composição e método numérico, pois seus domínios de validade diferem. FIN conserva convenções financeiras e oráculos; DIST conserva distribuição/licenças. Sem cópia de notas dos outros scouts.

## Suficiência, lacunas e próximo consumidor

Cobertura útil para examinar o design e preparar decisões: todos os eixos TECH têm fonte primária e limite identificados; houve expansão por implementação, changelog e contraevidência, além de documentação geral. Não é busca exaustiva de todo bug ou prova de ausência de divergências. A questão financeira exata permanece **inconclusiva por necessidade de prova/ensaio**, não por falta de uma consulta genérica adicional. Context7 permanece gap de acesso; não é atribuído a ele o problema numérico.

Próximo responsável: orquestrador recebe os três relatórios; humano e specialist analisam divergências materiais. Autores de planos posteriores podem consumir fontes atribuídas. Não foram iniciados Synapses, analyst, promoção ou alteração de requisito.

Propostas de validação futura, cada uma com plano e autorização próprios:

1. **Precisão do pin:** mesmo fonte mínimo em MSVC 2022 x64 e GCC 13 x64, Boost 1.86 confirmado por macros/hash. Registrar opções/otimização, `numeric_limits`, toda expressão avaliada e dígitos suficientes para diagnóstico. Comparar principal 6 centavos/100% nominal/n=1 com o oráculo racional independente de 1 centavo de juros/7 pagos; conservar também o empate terminante de 6%/R$ 1 e valores exatos dos dois lados da fronteira. Distinguir divisão por inteiro, por decimal e materialização de expressões quando forem caminhos reais candidatos. Um caso que passa não prova o domínio inteiro; um desvio não autoriza mudar o oráculo.
2. **Taxas pequenas/extremas:** zero, menor positivo da GUI, positivos tipados abaixo da precisão de `1+x`, 100% nos dois tipos, n=1/600, principal mínimo/máximo admissível e condições UnsupportedCentPrecision; comparar fórmula direta/estável com referência independente de maior precisão ou certificação apropriada. Julgar centavos por oráculo exato, não só tolerância mensal. Não usar benchmark remoto como latência do app.
3. **Apresentação:** fixture decimal exata `0.0000005` percentual para seis casas e caminho anual nominal `0,000006`; esperado `0,000001%`. Confirmar que MoneyCodec não usa double, a gramática recusa grupos mal posicionados e formato inglês, e exibe inteiros assinados em duas casas. Nenhum código foi escrito nesta pesquisa.
4. **Build/testes:** configurar núcleo sem Qt instalado/descoberto; suíte com erro deliberado controlado e seleção vazia para verificar propagação/registro; GoogleTest decimal via predicado; verificar CLI no binário fixado. Qualificação da UI, escala, teclado e pacote nas duas plataformas segue seus requisitos próprios. Build de runner hospedado/WSL não é demonstração Windows 11/Ubuntu desktop.

## Auditoria desta entrega

Revisão de autoria conferiu correspondência fonte→claim, versões, separação entre observação e inferência, todos os 25 requisitos efetivos, ownership e metadados fechados. Os sete artefatos retornaram `ok`, sem diagnósticos, em `mikoshi check --links --profile current`. O registro completo da checagem e os hashes dos corpos finais estão em [artifact-checks.json](../../evidence/research/technology/artifact-checks.json). Seu resultado é estrutural; não verifica matemática, compilação, instalação ou requisitos. Memória própria: `session_memory/research/technology.yaml`. Não houve novo experimento, download de pacote, instalação, compilação, teste de produto, benchmark ou edição do design aprovado.
