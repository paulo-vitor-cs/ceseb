---
id: 2101
revision: 1
type: document
tags: [mortgage, synapses, independent-review, verification, wsl]
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Revisão independente do snapshot ce5 com suíte WSL própria, veredictos determinísticos, dois defeitos de entrega e lacunas nativas preservadas.
use_when:
- Aplicar os resultados de requisitos e a aplicabilidade completa das quatro specs na rodada Synapses 1 sem repetir a revisão técnica.
---
# Revisão independente Synapses 1

Sou o dev independente `/root/independent_review`, owner `dev-independent-review`, head `independent-review`. Não sou autor ou coautor dos planos 2001/2002, produto ou assets de teste; não alterei esses materiais. A leitura e os testes abaixo são próprios. A declaração cobre somente os oráculos executados/inspecionados neste corte. Não emito aceite de produto, segurança geral ou parecer jurídico.

Resultado:** 17 requisitos pass, 2 fail por violações observadas e 6 sem resultado completo**. As ausências de Windows 11/MSVC 2022 e Ubuntu 24.04/GCC 13 não foram convertidas em fail. Specs 1008 r2/1012 r2 têm o conjunto aplicável completo todos os resultados pass no snapshot ce5; 1013 r2 permanece parcial; 1014 r2 permanece parcial com duas falhas. Planos 2001/2002 mantêm procedimento parcial; commit coverage não conclui seus protocolos. Nenhum reparo está autorizado por este relatório.

## Corte e autoridade

ROOT `/home/paulo/ceseb`; sessão MAIN explícita `/home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop`; ramo `codex/mortgage-desktop`. Autoridade: [1034 r1](../../../documents/1034/r1-engineering-execution-approval.md), [direção WSL 1035 r1](../../../documents/1035/r1-wsl-execution-direction.md) e [round 2100 r1](round.md). Aprovação do design atual: [1028 r1](../../../documents/1028/r1-revisions-approval-and-planning-authority.md). Os corpos publicados contêm narrativa histórica de proposta; 1028/1034 fixam a autoridade atual, sem alterar retroativamente a autoridade.

| Identidade | Commit |
|---|---|
| Snapshot único revisado e do novo build/pacote deste dev | ce5db2e9d7489e0b6258b449358d620a0c390b1e |
| Produto congelado pelo autor |76b9fe2ff8b6a034c9880daa315a7875f3d9bcdf|
| Binário/DEB anterior do autor |2b16879dfe1eb6ec55ea8d9310b2ae575cb1c7cf|
| Assets originais /BASE_IMPL|4e7e1842efe188c889dd9d5235f131f1502779b2|
| TEST_BASE|0bbd2854703444a27ce04600f5e227e0351f61bc|

[Entrada](dev/entry.json) captura status completo, SO/toolchain, 53 paths e hashes. [Integridade final](dev/integrity.json): HEAD ce5, 53 paths relevantes limpos e hashes estáveis; 43/43 corpos do snapshot aprovado preservados. README raiz, estado/memória raiz e demais documentos dirty/untracked anteriores permanecem alheios e preservados. A existência de fontes aprovadas locais/untracked não foi alegada como conteúdo de ce5. Os resultados técnicos referem-se aos 53 paths commitados; requisitos/specs referenciam os corpos locais exatos publicados.

Delta 2 b..ce5: somente docs/technical-report.md e os cinco arquivos GUI de preparação do teste. Inspecionei esse diff; a identidade anterior não foi reatribuída. Além de extrair o DEB anterior para comparação, gerei e extraí novo DEB ce5 a partir do meu build, eliminando dependência de inferir equivalência de pacote para os achados. Nenhum DEB foi instalado globalmente.

## Execução própria e cobertura

[Comandos/ambiente/durações](dev/execution.json), logs/JUnit em `/home/paulo/ceseb/out/review-wsl/`. CMake 3.28.6/Ninja 1.13.1 dos prefixos privados, GNU 15.2.0, Ubuntu 26.04 x86_64/WSL, Qt 6.12.0, Boost 1.86.0 e GTest 1.17.0 existentes. Configure Release usa explicitamente CESEB_SOURCE_REVISION=ce5, CMAKE_CXX_COMPILER=/usr/bin/g++, GUI e TESTS ON, Boost root, prefixos Qt, GTest e SDK do sistema e os três caminhos OpenGL reais. O script [run_review.py](dev/run_review.py) conserva os argumentos integrais; subprocessos usam lista de argumentos, sem ambiguidades de shell. DISPLAY=: 0; LD_LIBRARY_PATH dos testes contém runtime do sistema e SDK Qt. Isso não é teste de pacote fechado.

| Operação | Resultado próprio |
|---|---|
| Configure Release GUI |exit 0, 1.755 s|
| Build GUI, parallel 2|exit 0, 63.272 s|
| Inventários binários|13 suites GTest/20 casos; 4 slots QtTest, seleção não vazia|
| CTest offscreen|26/26, 0 fail, 0 skip; exit 0, 0.872 s|
| CTest XCB/WSLg|26/26, 0 fail, 0 skip; exit 0, 0.955 s|
| Script de isolamento real, GUI OFF e descoberta Qt desabilitada|configure/build/domain 21/21; exit 0, 93.340 s|
| GTest completo com XML/recursos|20/20; 0 fail/disabled; 0.285 s, pico RSS de 5880 KiB|
| Complemento de oráculo em código auxiliar owned|7 casos normativos/fronteiras e recomposição 0/4.5/12; exit 0|

Os 26 entries CTest são 20 casos GTest+4 slots QtTest+2 inventários. Não são 26 requisitos. Li os logs e XML finais. O [probe](dev/oracle-probe.json) cobre explicitamente todas as invariantes do vetor 120000/zero/12 e o vetor SAC de 12 meses que exigiam observação complementar, além das fronteiras de 1201; usa o core ce5 real e constantes normativas, sem gerar expectativas com outputs do app. Não alterou assets. Medição de Price irracional/limite retornou 13985 µs para o conjunto registrado no GTest; é observação WSL, sem orçamento de latência aprovado. Grade fixa 480 entradas: 330 comparações válidas, 150 recusas UnsupportedCentPrecision. SAC isolado também exercita sua grade admissível. A grade não esgota o domínio e suas recusas não são livros aprovados.

Universo de requisitos: 25 r1 ativos, 101 AC numerados; a matriz adiante atribui cada critério e sua lacuna. 71 AC dos 17 requisitos com resultado pass foram verificados por testes completos e inspeção do caminho de dados, sem tolerância monetária. Dois requisitos têm violação observada; os demais 6 não recebem resultado completo. Uma contagem de asserts/casos não substitui esse mapa. Requisitos 1222..1224 são obsolete e excluídos explicitamente.

Cobertura de código **não mensurada**, não zero. Instrumento previsto pelo plano: gcov 13/GCC 13, indisponível no ambiente. gcov 15 existe, mas não foi usado como substituto. Denominador proposto: seis unidades.cpp próprias em src/core, src/ui e src/app e seus headers associados; exclusões: Boost/GTest/Qt, tests, moc/qrc/autogerados, build/staging. Não há percentual ou limiar inventado. A matriz de critérios está disponível apesar da falta desse diagnóstico. SDK Qt existe no host: Qt discovery desabilitado no isolamento prova a seleção core-only, não ausência física da instalação nem a execução dos dois ambientes exigidos por 1221.

## Achados confirmados

### F1 — lançador DEB fora da busca desktop padrão

**Prioridade P2; defeito confirmado. Trigger:**  instalar o DEB em um desktop com XDG_DATA_DIRS padrão e procurar o lançador CESEB prometido no manual. **Esperado:**  entrada.desktop acessível na busca padrão do desktop sem configurar ambiente de desenvolvimento. **Atual:**  o único arquivo é `/opt/ceseb/share/applications/ceseb.desktop`; o control DEB possui apenas control/md5sums, sem postinst ou registro/cópia adicional. Não existe entrada em /usr/share/applications ou /usr/local/share/applications. **Path causal:**  `/home/paulo/ceseb/cmake/Packaging.cmake:58`, combinado com CPACK_PACKAGING_INSTALL_PREFIX=/opt/ceseb na mesma fonte. **Base violada:**  1225 r1 AC 2, 1014 r2, pacotes e I-1225; docs/user-guide.md afirma que instalação expõe lançador. **Impacto:**  usuário não obtém o acesso desktop publicado; precisa descobrir o binário em /opt ou ajustar manualmente o ambiente. Não observei nem alego crash do app.

O teste de inventário foi executado no DEB ce5 extraído, sem instalação global. O [XDG Menu, File locations](https://specifications.freedesktop.org/menu/latest/paths.html) exige coleta em XDG_DATA_DIRS/applications; a [Base Directory 0.8](https://specifications.freedesktop.org/basedir/latest/) define defaults /usr/local/share e /usr/share. A inferência de ausência no menu padrão decorre dessas regras e do inventário completo, não de uma captura de Ubuntu 24. **Resultado 1225: fail por essa violação observada.** Windows ausente e smoke limpo continuam lacunas separadas.

### F2 — links de licença quebrados na documentação instalada

**Prioridade P2; defeito confirmado. Trigger:**  abrir `/opt/ceseb/docs/README.md` do pacote e seguir “Licença dos originais”/“Avisos de terceiros”. **Esperado:**  resolver os materiais locais que acompanham a versão. **Atual:**  os links ../LICENSE e ../THIRD_PARTY_NOTICES.md resolvem para arquivos ausentes em /opt/ceseb; os arquivos reais ficam em /opt/ceseb/licenses/. Três links de documentos resolvem, dois não. **Paths:**  `/home/paulo/ceseb/docs/README.md:12` e `:13`; causa de composição em cmake/Packaging.cmake, que instala esses arquivos em licenses e copia docs sem adaptar os links. **Base violada:**  1227 r1 AC 1/AC 4, 1014 r2, documentação e I-1227/T1227. **Impacto:**  o índice entregue não permite recuperar os avisos pelos links publicados. Os materiais existem, portanto isto não é uma conclusão de falta de licença ou infração jurídica. Os registros operacionais citados pelo relatório instalado também não estão no DEB; permanecem evidência local da sessão, sem publicação remota alegada. **Resultado 1227: fail pela ligação documental observada.**

Ambos os achados aparecem no DEB 2b anterior e foram reproduzidos no novo pacote ce5. [Auditoria própria](dev/package-audit.json) e [comandos](dev/package-execution.json) conservam paths, controle, resolução de links e hashes. Não houve correção de produto/documentação/pacote nesta revisão.

## Pacote, dependências e segurança delimitada

Novo pacote ce5: `/home/paulo/ceseb/out/review-wsl/packages/ceseb_0.1.0_amd64.deb`, SHA256 `6692adb56379f62e1412ec4b5fe9df5b0d23385c914119f301fbbc08698d2079`. SourceRevision ce5 foi encontrado no binário extraído. DEB 2b anterior: `/home/paulo/ceseb/out/packages/aux-wsl-closed/ceseb_0.1.0_amd64.deb`, SHA256 `d04f97d5cdc89f886bad6be46159d4d821eaf1e2374775eb1092ba0d643b31a6`. São artefatos distintos, ambos auxiliares WSL e sem publicação.

Install/CPack/extract/info/contents/readelf/ldd retornaram 0. Auditoria do meu pacote usa **somente o prefixo de runtime do sistema** em LD_LIBRARY_PATH, sem SDK Qt; Qt resolve na própria árvore extraída. RUNPATH do app=$ORIGIN/../lib; plugin XCB presente e dependências sem “not found”. Runtime Qt Core/DBus/Gui/Widgets/XcbQpa+ICU 73.2; somente platforms/libqxcb.so; sem QtTest, GTest, QtNetwork ou glibc privada/headers do SDK. 154/154 hashes instalados e 127/127 notices conferem. Duas linhas de metadados em cada SHA256SUMS não são linhas de checksum; não são anunciadas como manifesto puro sem avisos. Isso não é instalação/uso limpo Ubuntu 24.

MIT/copyright dos originais, GPL/LGPL Qt e avisos/transitivos presentes. Fonte QtBase exata 025bdad181de241e81bf853c8a2d7bf3d19261a9 no SBOM, arquivo completo, config do fornecedor e textos de terceiros incluídos; hash recuperável no inventário. Não troquei o pin, não reconstruí Qt nem ensaiei substituição ABI; Windows/CRT/REDIST não qualificados. 1228 permanece sem resultado completo. A presença de inventários não certifica direitos jurídicos gerais.

Métodos escolhidos: leitura dirigida de entradas/limites/erros, fontes/build/acquisition/deploy, pins/avisos, imports ELF e busca redigida de três famílias de padrões de segredo nos 53 paths selecionados. [Registro](dev/security-observation.json): zero hits nesses padrões, sem scanner abrangente. Não foram instalados Semgrep/OSV/Gitleaks nem enviados fontes a serviço externo. Superfícies do app: campos de texto locais; regex ancoradas e conversões inteiras verificadas; sem banco, conta, rede de negócio, persistência ou execução de comandos. Ajuda embutida e link local construído pelo appdir, sem URL digitável do usuário. Acquisition é efeito explícito de engenharia, com TLS_VERIFY/EXPECTED_HASH/commit Git fixo, separado do runtime; não foi repetida nesta revisão. Não há framework genérico/worker/cache especulativo: helpers numéricos específicos, core/UI separados. A complexidade exata implementa a escolha 1025; nenhum defeito de estilo foi tratado como bug.

CVE-2026-105924: li integralmente o diff retido e o trecho correspondente da fonte QtBase exata  não corrigida. O caminho vulnerável está presente em QtCore: conversão de tag CBOR URL 32 com string vazia para JSON dereferencia ByteData ausente. O app próprio não possui imports QCbor/QJson nem API de importação de documentos; os inputs financeiros não alcançam esse parser. **Limite adicional:**  Qt usa CBOR internamente para metadados de plugins; qfactoryloader.cpp: parse/fromCbor e toJson, e qlibrary.cpp chama toJson no logging debug. Portanto ausência de imports no app não prova ausência global do caminho no processo. O pacote usa o plugin XCB oficial fixado, sem input CBOR arbitrário identificado nesse fluxo; plugin/ambiente substituído por terceiro muda a fronteira. Não houve exploração ou teste com plugin malicioso; não declaro CVE inexistente ou mitigação universal. O acesso web direto ao patch retornou indisponível; fonte local integral, hash e trechos efetivos foram confrontados. Não há finding de exposição pela entrada GUI demonstrado, nem autoridade para patch/aceite de risco material nesta rodada.

## Histórico e plano/commit coverage

[2011 completo](../../test-execution/2001/r1-base-result.md): greenfield sem CMake/API ->UNAVAILABLE antes de comportamento; preservado como tal, sem RED fabricado. [2012 completo](../../test-execution/2001/r1-final-result.md) e [2021 completo](../../implementation-planning/execution.md) foram consumidos integralmente, com anexos materiais pertinentes. O XCB original 25/26 não foi apagado. O diff ce5 só altera o helper e quatro slots; ele espera qWaitForWindowActive e verifica a precondição, sem remover assert de foco ou oráculo. 17 assets idênticos e cinco ajustes de preparação; produtos/testes/autorias e SHAs continuam distintos. Minha nova execução em ce5 é a evidência atual, sem reescrever o resultado original.

| Range/check próprio | Observado e disposição |
|---|---|
|2001: 0bbd..4e7|22/22 creates cobertos; check atual partial/exit 4 pois 5 paths GUI commitados após HEAD 4e7 aparecem em dirty_planned_paths em relação àquele HEAD. O check histórico de 2011 foi ok e clean naquele momento e é preservado; não foi um check original falho.|
|2001: 76b9..ce5|partial/exit 4: plano declara 22 creates, delta contém 5 modifies; nenhum create coberto. Sem reescrever plano ou chamar correção de execução completa.|
|2001: 0bbd..ce5|ok/exit 0, 22 creates cobertos, 0 dirty planned, 31 unexpected paths de produto. Cada um pertence ao filemap 2002, disposição retain, ownership de produto, sem atribuir autoria ao executor de 2001.|
|2002:4e7..76b9|ok/exit 0, 31/31 creates, 0 unexpected, 0 dirty planned.|

JSONs integrais: [original](dev/test-original.json), [correção](dev/test-correction.json), [full](dev/test-full.json), [produto](dev/product-final.json). Os 31 unexpected paths são exatamente os 31 paths do filemap 2002; listas verificadas na leitura dos dois planos e do delta de 53 paths. Nenhum caminho não disposto ou falta de commit final foi ocultado. Completar 22/31 arquivos não conclui procedimentos. 2012 declara 25 tarefas incomplete; 2021 declara 14 complete e 11 incomplete, com procedure partial. As distinções locais/nativas desses reports são coerentes e não são elevadas para resultado de produto por minha revisão.

## Busca, leitura e limites de ferramentas

Usei mikoshi-search/trace com ROOT e corpus explícitos. Retrieval e trace retornam partial, com rotas locais recuperáveis e graph index_incompatible; 7 diagnósticos source_parse_error nos relatórios legados sem schema corrente. Graph neighbors retorna unavailable/index_incompatible. Não é stale; não houve rebuild, correção de fonte ou alteração de configuração. [Retrieval](dev/retrieval.json), [trace](dev/trace.json), [neighbors](dev/neighbors.json) preservam a cobertura e fronteira. A matriz abaixo é conferência semântica própria sobre todos os 25 corpos, ambos os planos e 53 paths, não alegação de grafo completo.

Context7/Serena não estão expostos no catálogo desta instância; suas operações não foram chamadas nem instaladas. Essa obrigação de ferramenta permanece lacuna explícita, sem contaminar retrospectivamente as execuções observadas. Consultei fonte QtBase exata  local e fontes oficiais XDG para as duas questões limitadas; não fiz nova pesquisa ampla. Não houve agente adicional, CI remoto, push/PR/merge/release, promoção, instalação global ou mudança de máquina.

[Manifesto de leitura](dev/source-read-manifest.json): original 1001/1005, quatro specs r2, 25 requisitos r1 ativos, ambos os planos integrais, reports 2011/2012/2021, 19 knowledge notes atribuídas; análises 1023/1024, autoridades 1028/1034/1035, contrato 1030 e todos os 53 paths do delta. Também li os cards 2301..2306 r2, memories dos dois autores e do responsável pelo ambiente, skills code-review/security-review/search/trace/dev-tools, agente dev, contratos authority/verification/review/result-transition, cards git/retrieval/graph/trace/commitcheck/headmemory/artifactcheck/Context7/Serena. Li as unidades QtBase mencionadas acima; não alego leitura de toda Qt ou todos os payloads. Manifestos materialmente repetitivos foram conferidos por parsing/hash; não confundo hash com leitura semântica integral.

## Resultado por requisito

A [matriz JSON](dev/requirement-trace.json) guarda cada rota exata requirement r1→tarefas de 2001/2002→todos os arquivos declarados e observações por AC. Os casos GTest ReqNNNN e slots Qt correspondentes foram executados em ce5; leitura própria do código complementa os critérios de transporte/normalização/formatação. Para requisitos sem resultado não há linha pass/fail fabricada na declaração.

### Req 1101

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1101 +2002 r1/I-1101. Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`. Testes: `tests/domain/req1101_rate_kind_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. Nominal 12 mensal 0.01 dentro 1e-12.
2. Efetiva 12 mensal 0.009488792934582974126355069193493956 dentro 1e-12.
3. nullopt e enum desconhecido retornam somente InvalidRateKind.

### Req 1102

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1102 +2002 r1/I-1102. Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`. Testes: `tests/domain/req1102_nominal_monthly_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. Quatro entradas 0/4.5/12/100 têm referências 0/.00375/.01/1/12.
2. Predicado Decimal usa erro absoluto 1e-12 sem double.
3. Zero numérico exato e crescimento racional 1.

### Req 1103

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1103 +2002 r1/I-1103. Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`. Testes: `tests/domain/req1103_effective_monthly_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. Efetiva 0 retorna zero exato.
2. Efetiva 4.5 atende referência e 1e-12.
3. Efetiva 12 atende referência e 1e-12; recomposição adicional 0/4.5/12 com erros 0/1.06245e-47/1.65447e-47.

### Req 1104

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1104 +2002 r1/I-1104. Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`. Testes: `tests/domain/req1104_annual_equivalents_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. Nominal 12 N=12 e E=12.682503013196972066120100 dentro 1e-9.
2. Efetiva 12 N=11.386551521499568951626083032192747 e E=12 dentro 1e-9.
3. Duas entradas zero retornam N/E zero exatos.
4. Nominal 100 E segue 100*((13/12)^12-1), acima 100 sem cap.

### Req 1105

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1105 +2002 r1/I-1105. Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`. Testes: `tests/domain/req1105_invalid_rate_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. NaN/Infinity/-Infinity ->NonFiniteRate em ambos tipos.
2. -0.01/100.01 ->RateOutOfRange em ambos tipos.
3. 0/100 aceitos com projeções finitas; análise do guard rejeita não finitos.

### Req 1106

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1106 +2002 r1/I-1106. Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`. Testes: `tests/domain/req1106_exact_rate_transport_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. Descritor efetivo retém kind, p=12, g=28/25 e projeção dentro 1e-12.
2. Textos quatro/seis casas 0.9489/0.948879 não alteram resultado.
3. compare chama normalize uma vez e passa rate aos dois livros; UI monta LoanInput a partir de MoneyCodec, sem ler labels.
4. Nominal 100 crescimento 13/12; principal 6, n=1 cobra juro 1 em ambos depois da quantização de labels.

### Req 1201

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1201 +2002 r1/I-1201. Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`. Testes: `tests/domain/req1201_loan_domain_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. C=0 e10000000001 ->PrincipalOutOfRange sem Comparison.
2. n=0 e 601 com C válido ->TermOutOfRange.
3. C=1, n=1 eC máximo, n=1/600 aceitos a taxa 0.
4. Erros combinados respeitam principal, taxa/tipo, prazo, centavos.

### Req 1202

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1202 +2002 r1/I-1202. Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`. Testes: `tests/domain/req1202_price_ledger_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. Price 3: pagamentos 34002/34002/34003; juros 1000/670/337; saldos 66998/33666/0.
2. Resumo ordinary 34002, total 102007, interest 2007, actual 3.
3. Zero 600: ordinary 167, last 134, actual 599, total 100000.
4. Código e vetores verificam min(a, B+I) antes de n, quitação B+I em n e parada no saldo 0.
5. C=3, zero, n 2: ordinary 2 e pagamentos 2/1.
6. Efetiva 12, C=100000, n 3: ordinary 33968, pagamentos 33968/33968/33968; fronteiras do intervalo exato coincidem antes de aceitar.

### Req 1203

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1203 +2002 r1/I-1203. Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`. Testes: `tests/domain/req1203_sac_ledger_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. SAC 3 amort 33334/33333/33333; juros 1000/667/333; pagamentos 34334/34000/33666; saldos 66666/33333/0.
2. Resumo total 102000, interest 2000, actual 3.
3. Grade SAC admissível: n linhas e amortizaçãoq+(k<=r), diferenças<=1.
4. Juros calculados com saldo anterior e half-up exato; pagamentos não crescentes na grade.
5. C=6, 100%, n=1 ->juro 1/pagamento 7; vizinhos 5.999999/6/6.000001 ->juros 0/1/1.

### Req 1204

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1204 +2002 r1/I-1204. Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`. Testes: `tests/domain/req1204_money_invariants_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. Identidades de cada linha verificadas por cpp_int na grade e pelo probe de todos os vetores normativos/fronteiras.
2. Soma principal=C e saldo final 0; sem linha após quitação.
3. Total=sum pagamentos=C+sum juros e resumos iguais; probe inclui 120000/zero/12.
4. Price 1..n e SAC n em todos os livros produzidos; rejeições separadas.

### Req 1205

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1205 +2002 r1/I-1205. Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`. Testes: `tests/domain/req1205_zero_single_ties_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. 120000/zero/12: cada livro 12 pagamentos 10000, total 120000, juros 0.
2. 100/nominal 6/n=1: juro 1 e pagamento 101.
3. Uma única linha, saldo 0, sem segunda cobrança.
4. 6/nominal 100/n=1: juro 1 e pagamento 7 conservando 1/12.
5. Vizinhos 6%: juros 0/1/1, pagamentos 100/101/101.
6. Fixture exata 100*((201/200)^12-1), com mais de seis casas; classificada RationalGrowth 201/200, juro 1/pagamento 101.

### Req 1206

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1206 +2002 r1/I-1206. Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`. Testes: `tests/domain/req1206_cent_admissibility_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. C=1/zero/n=600 ->UnsupportedCentPrecision.
2. C=1200/nominal 100/n=600 ->UnsupportedCentPrecision; ordinary e primeiro juro 100.
3. Variante Error não contém Comparison; ambos os erros atômicos.

### Req 1207

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1207 +2002 r1/I-1207. Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`. Testes: `tests/domain/req1207_comparison_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. Inspeção própria: uma normalize, mesmos C, n, rate para Price/SAC.
2. Nominal 12/100000/3 juros 2007/2000 e diferença+7.
3. Efetiva 12.682503013196972066120100 preserva livros literais.
4. Quantizar não altera origem; efetiva 12 distinta, juros 1904/1898, diferença+6.

### Req 1211

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1211 +2002 r1/I-1211. Produto: `src/ui/money_codec.hpp`, `src/ui/money_codec.cpp`. Testes: `tests/gui/req1211_localized_input_test.cpp`, `tests/gui/gui_tests.hpp`, `tests/gui/gui_test_main.cpp`.

1. Codec aceita 100.000, 00/100000, 00 ->10000000; recusa quatro formatos normativos.
2. Taxas 4, 5/4, 123456 aceitas; 4.5/4,1234567 recusadas sem truncar.
3. Prazo 360 aceito; 0/3, 5 recusados.
4. Ambos tipos preservados; gramáticas ancoradas e trimmed externo; controlador monta objeto tipado.

### Req 1212

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1212 +2002 r1/I-1212. Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`, `src/ui/money_codec.hpp`, `src/ui/money_codec.cpp`, `src/ui/main_window.hpp`, `src/ui/main_window.cpp`. Testes: `tests/gui/req1212_rate_presentation_test.cpp`, `tests/gui/gui_tests.hpp`.

1. Nominal 12 labels 1, 000000/12, 000000/12, 682503%.
2. Efetiva 12 labels 0, 948879/11, 386552/12, 000000%.
3. Quantização inteira half-up; captions associam tipo/período a cada label.
4. Nominal 100 mostra E161,...%; análise de quantize_rates usa fração exata da fórmula sem cap.
5. Pipeline 0, 000005/6/7 mostra mensal 0, 000000/1/1%.
6. Fixture isolada 1/2000000 ponto percentual ->inteiro 1 e texto 0, 000001%.

### Req 1213

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1213 +2002 r1/I-1213. Produto: `src/ui/main_window.hpp`, `src/ui/main_window.cpp`, `src/app/main.cpp`. Testes: `tests/gui/req1213_comparison_presentation_test.cpp`, `tests/gui/gui_tests.hpp`.

1. Nove campos de valores Price/SAC conferidos contra strings literais.
2. Ambosactual 3; diferença realR$ +0, 07 preservada por present; fonte lida além do helper de teste que remove+ para comparar magnitude.
3. Zero 600: requested 600; Priceactual 599, last 1, 34, aviso 599 de 600; SACactual 600, last 1, 66.
4. Texto de ajuste presente; n=1 identifica Parcela única, com quitação final.

### Req 1214

**pass**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1214 +2002 r1/I-1214. Produto: `src/ui/simulation_controller.hpp`, `src/ui/simulation_controller.cpp`, `src/ui/main_window.hpp`, `src/ui/main_window.cpp`. Testes: `tests/gui/req1214_state_recovery_test.cpp`, `tests/gui/gui_tests.hpp`.

1. Edição separada de principal/taxa/prazo/tipo limpa 16 labels imediatamente.
2. Erros combinados preservam entradas, limpam resultados e seguem prioridade.
3. Focus asserts principais/taxa/tipo/prazo/calcular passaram com janela ativa; switch de show_error confere mapeamento.
4. Correção recupera ambos cartões; Limpar esvazia campos, nominal e foco principal.
5. Mensagem de centavos orienta ajustar valor/prazo/taxa; mensagens constantes sem traceback/caminho.

### Req 1215

**sem resultado**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1215 +2002 r1/I-1215. Produto: `src/ui/main_window.hpp`, `src/ui/main_window.cpp`, `src/app/main.cpp`. Testes: nenhuma operação de fonte; protocolo/inspeção.

1. Sem resultado: exige demonstração de teclado nos dois desktops; inspeção de taborder/atalhos/buddies não substitui.
2. Sem resultado: exige demonstração de teclado nos dois desktops; inspeção de taborder/atalhos/buddies não substitui.
3. Sem resultado: exige demonstração de teclado nos dois desktops; inspeção de taborder/atalhos/buddies não substitui.
4. Sem resultado: exige demonstração de teclado nos dois desktops; inspeção de taborder/atalhos/buddies não substitui.

### Req 1216

**sem resultado**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1216 +2002 r1/I-1216. Produto: `src/ui/main_window.hpp`, `src/ui/main_window.cpp`. Testes: nenhuma operação de fonte; protocolo/inspeção.

1. Sem resultado: quatro combinações Windows 11/Ubuntu 24 x 100/200% em 800 x 600 não executadas.
2. Sem resultado: quatro combinações Windows 11/Ubuntu 24 x 100/200% em 800 x 600 não executadas.
3. Sem resultado: quatro combinações Windows 11/Ubuntu 24 x 100/200% em 800 x 600 não executadas.

### Req 1217

**sem resultado**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1217 +2002 r1/I-1217. Produto: `src/ui/main_window.hpp`, `src/ui/main_window.cpp`, `resources/application.qrc`, `resources/model-help.html`. Testes: nenhuma operação de fonte; protocolo/inspeção.

1. Tópicos 1..3 presentes em HTML local/qrc; falta abrir ajuda e links no pacote instalado em sessão já offline para completar procedimento.
2. Tópicos 1..3 presentes em HTML local/qrc; falta abrir ajuda e links no pacote instalado em sessão já offline para completar procedimento.
3. Tópicos 1..3 presentes em HTML local/qrc; falta abrir ajuda e links no pacote instalado em sessão já offline para completar procedimento.
4. Tópicos 1..3 presentes em HTML local/qrc; falta abrir ajuda e links no pacote instalado em sessão já offline para completar procedimento.

### Req 1221

**sem resultado**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1221 +2002 r1/I-1221. Produto: `CMakeLists.txt`, `CMakePresets.json`, `cmake/Dependencies.cmake`, `cmake/AcquireDependencies.cmake`, `cmake/dependencies.lock.json`, `cmake/Version.hpp.in`, `.github/workflows/ci.yml`. Testes: `tests/CMakeLists.txt`, `tests/system/check_core_independence.cmake`.

1. API/core sem Qt e isolamento WSL21/21 observados.
2. Qt discovery desabilitado, mas SDK existe; não é prova do ambiente sem instalação Qt.
3. Sem resultado: duas plataformas declaradas e mesma fonte sem Qt nelas não foram executadas.

### Req 1225

**fail**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1225 +2002 r1/I-1225. Produto: `cmake/Packaging.cmake`, `cmake/WindowsDeploy.cmake`, `packaging/ceseb.desktop`, `packaging/qt.conf`, `CMakeLists.txt`. Testes: nenhuma operação de fonte; protocolo/inspeção.

1. ZIP Windows não produzido; ausência permanece lacuna.
2. FAIL observado no DEB ce5: desktop file somente em /opt/ceseb/share/applications, fora dos diretórios XDG padrão, sem registro adicional.
3. Abertura limpa dos dois SOs não executada; closureldd emWSL não substitui.
4. DEB identifica versão 0.1.0/amd64/ce5; pacoteWindows continua ausente.

### Req 1226

**sem resultado**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1226 +2002 r1/I-1226. Produto: nenhuma operação de fonte; pacotes/protocolo reference-only. Testes: nenhuma operação de fonte; protocolo/inspeção.

1. Sem resultado: demonstração dos pacotes nos dois desktops explicitamente excluiWSL.
2. Sem resultado: demonstração dos pacotes nos dois desktops explicitamente excluiWSL.
3. Sem resultado: demonstração dos pacotes nos dois desktops explicitamente excluiWSL.
4. Sem resultado: demonstração dos pacotes nos dois desktops explicitamente excluiWSL.

### Req 1227

**fail**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1227 +2002 r1/I-1227. Produto: `docs/README.md`, `docs/user-guide.md`, `docs/build-and-test.md`, `docs/technical-report.md`. Testes: nenhuma operação de fonte; protocolo/inspeção.

1. Documentação portuguesa cobre tópicos, mas dois links de licenças emdocs/README.md quebram na árvore instalada.
2. Mapa dos 25 e distinções históricas presentes; rastreabilidade técnica lida contra reports e commits.
3. Resultados positivos/negativos/nãoexecutados atribuídos no relatório; comando nativo não é alegado verificado.
4. FAIL observado na documentação instalada: links ../LICENSE e ../THIRD_PARTY_NOTICES não recuperam os materiais; evidências de execução citadas não acompanham a árvore DEB.

### Req 1228

**sem resultado**; snapshot `ce5db2e9d7489e0b6258b449358d620a0c390b1e`. Rota: 2001 r1/T1228 +2002 r1/I-1228. Produto: `LICENSE`, `THIRD_PARTY_NOTICES.md`, `cmake/ThirdPartyNotices.cmake`, `CMakeLists.txt`, `CMakePresets.json`, `cmake/Dependencies.cmake`, `cmake/AcquireDependencies.cmake`, `cmake/dependencies.lock.json`, `cmake/Version.hpp.in`, `.github/workflows/ci.yml`, `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`, `src/ui/money_codec.hpp`, `src/ui/money_codec.cpp`, `src/ui/main_window.hpp`, `src/ui/main_window.cpp`, `src/ui/simulation_controller.hpp`, `src/ui/simulation_controller.cpp`, `src/app/main.cpp`, `resources/application.qrc`, `resources/model-help.html`. Testes: nenhuma operação de fonte; protocolo/inspeção.

1. MIT dos originais/copyright presentes; não estendido a terceiros.
2. Inventário Linux e 127 materiais de notices com hashes válidos; Windows/CRT não qualificados.
3. Fonte QtBase exata 025 bd...incluída, textos GPL/LGPL e configuração; possibilidade de substituição indicada sem bloqueio; substituição/reconstrução não executada.
4. Sem resultado global: inventário/termosruntime Windows e pacote alvo ausentes; inspeçãoLinux não certifica direito jurídico.

## Aplicabilidade e retorno ao analyst

O dev declara os conjuntos completos aplicáveis, sem inferi-los das linhas de resultado: 1008 r2 = {1101..1106}; 1012 r2 = {1201..1207}; 1013 r2 = {1211..1217}; 1014 r2 = {1221, 1225, 1226, 1227, 1228}. São 25 membros distintos no mesmo snapshot ce5. Os requisitos 1222..1224 permanecem obsolete e excluídos.

As specs 1008 e 1012 qualificam implemented pelo predicado dos seus requisitos determinísticos na revisão declarada; isso não qualifica o produto Windows/Linux nem conclui os planos. A spec 1013 recebe quatro resultados pass entre sete requisitos; a spec 1014 recebe dois resultados fail entre cinco requisitos. Os seis membros faltantes permanecem sem resultado, preservando seu estado anterior. Nenhum conjunto vazio de resultados foi necessário nas quatro declarações, e não há linha fabricada para os seis requisitos sem resultado.

Próximo responsável: analyst 2102, para aplicar as declarações sem repetir a verificação técnica e conciliar planos, relatórios e metadados sob as autoridades existentes. As lacunas de ambiente nativo, Context7/Serena, perfil de grafo, cobertura e inventário Windows permanecem explícitas. Os achados F1/F2 não autorizam correção ou novo ciclo. A revisão termina com este retorno. A sessão continua aberta, sem aceite humano, push, PR, merge, release, promoção ou fechamento inferidos.

## Validação mecânica do retorno

O primeiro uso read-only de `status.validate` recusou as 23 entradas por ausência de uma associação única de implementation_workspace na sessão. O [diagnóstico inicial](dev/declaration-validation-before-binding.json) está preservado. O owner raiz registrou a associação do fluxo design-project-1 com o checkout já aprovado `/home/paulo/ceseb`; não alterei o estado raiz. Após esse ajuste documental, [23/23 declarações foram validadas](dev/declaration-validation.json) pelo validador real do runtime, sem transição de status. O check de artefato e links também retornou ok. Esses checks validam o transporte e as referências; os resultados técnicos continuam sustentados pela revisão acima.

## Declaração mecânica exata

```mikoshi-result-v1
- kind: requirement
  artifact:
    path: ../../../requirements/1101/r1-explicit-rate-kind.md
    id: 1101
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1101/r1-explicit-rate-kind.md
      id: 1101
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1101'
- kind: requirement
  artifact:
    path: ../../../requirements/1102/r1-nominal-monthly.md
    id: 1102
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1102/r1-nominal-monthly.md
      id: 1102
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1102'
- kind: requirement
  artifact:
    path: ../../../requirements/1103/r1-effective-monthly.md
    id: 1103
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1103/r1-effective-monthly.md
      id: 1103
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1103'
- kind: requirement
  artifact:
    path: ../../../requirements/1104/r1-annual-equivalents.md
    id: 1104
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1104/r1-annual-equivalents.md
      id: 1104
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1104'
- kind: requirement
  artifact:
    path: ../../../requirements/1105/r1-invalid-rate-input.md
    id: 1105
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1105/r1-invalid-rate-input.md
      id: 1105
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1105'
- kind: requirement
  artifact:
    path: ../../../requirements/1106/r1-unrounded-consumer-rate.md
    id: 1106
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1106/r1-unrounded-consumer-rate.md
      id: 1106
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1106'
- kind: requirement
  artifact:
    path: ../../../requirements/1201/r1-loan-domain.md
    id: 1201
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1201/r1-loan-domain.md
      id: 1201
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1201'
- kind: requirement
  artifact:
    path: ../../../requirements/1202/r1-price-ledger.md
    id: 1202
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1202/r1-price-ledger.md
      id: 1202
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1202'
- kind: requirement
  artifact:
    path: ../../../requirements/1203/r1-sac-ledger.md
    id: 1203
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1203/r1-sac-ledger.md
      id: 1203
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1203'
- kind: requirement
  artifact:
    path: ../../../requirements/1204/r1-money-invariants.md
    id: 1204
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1204/r1-money-invariants.md
      id: 1204
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1204'
- kind: requirement
  artifact:
    path: ../../../requirements/1205/r1-zero-and-single-period.md
    id: 1205
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1205/r1-zero-and-single-period.md
      id: 1205
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1205'
- kind: requirement
  artifact:
    path: ../../../requirements/1206/r1-cent-precision-errors.md
    id: 1206
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1206/r1-cent-precision-errors.md
      id: 1206
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1206'
- kind: requirement
  artifact:
    path: ../../../requirements/1207/r1-comparable-results.md
    id: 1207
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1207/r1-comparable-results.md
      id: 1207
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1207'
- kind: requirement
  artifact:
    path: ../../../requirements/1211/r1-localized-input.md
    id: 1211
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1211/r1-localized-input.md
      id: 1211
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1211'
- kind: requirement
  artifact:
    path: ../../../requirements/1212/r1-rate-presentation.md
    id: 1212
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1212/r1-rate-presentation.md
      id: 1212
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1212'
- kind: requirement
  artifact:
    path: ../../../requirements/1213/r1-comparison-presentation.md
    id: 1213
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1213/r1-comparison-presentation.md
      id: 1213
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1213'
- kind: requirement
  artifact:
    path: ../../../requirements/1214/r1-ui-state-recovery.md
    id: 1214
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1214/r1-ui-state-recovery.md
      id: 1214
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1214'
- kind: requirement
  artifact:
    path: ../../../requirements/1225/r1-runtime-packages.md
    id: 1225
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1225/r1-runtime-packages.md
      id: 1225
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: fail
    method: test
    evidence: '#req-1225'
- kind: requirement
  artifact:
    path: ../../../requirements/1227/r1-technical-documentation.md
    id: 1227
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  results:
  - requirement:
      path: ../../../requirements/1227/r1-technical-documentation.md
      id: 1227
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: fail
    method: inspection
    evidence: '#req-1227'
- kind: spec
  artifact:
    path: ../../../specs/1008/r2-annual-rate-conversion.md
    id: 1008
    revision: 2
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  applicability:
    mode: engineering
    declared_by: dev
    requirements:
    - path: ../../../requirements/1101/r1-explicit-rate-kind.md
      id: 1101
      revision: 1
    - path: ../../../requirements/1102/r1-nominal-monthly.md
      id: 1102
      revision: 1
    - path: ../../../requirements/1103/r1-effective-monthly.md
      id: 1103
      revision: 1
    - path: ../../../requirements/1104/r1-annual-equivalents.md
      id: 1104
      revision: 1
    - path: ../../../requirements/1105/r1-invalid-rate-input.md
      id: 1105
      revision: 1
    - path: ../../../requirements/1106/r1-unrounded-consumer-rate.md
      id: 1106
      revision: 1
  results:
  - requirement:
      path: ../../../requirements/1101/r1-explicit-rate-kind.md
      id: 1101
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1101'
  - requirement:
      path: ../../../requirements/1102/r1-nominal-monthly.md
      id: 1102
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1102'
  - requirement:
      path: ../../../requirements/1103/r1-effective-monthly.md
      id: 1103
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1103'
  - requirement:
      path: ../../../requirements/1104/r1-annual-equivalents.md
      id: 1104
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1104'
  - requirement:
      path: ../../../requirements/1105/r1-invalid-rate-input.md
      id: 1105
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1105'
  - requirement:
      path: ../../../requirements/1106/r1-unrounded-consumer-rate.md
      id: 1106
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1106'
- kind: spec
  artifact:
    path: ../../../specs/1012/r2-amortization-comparison.md
    id: 1012
    revision: 2
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  applicability:
    mode: engineering
    declared_by: dev
    requirements:
    - path: ../../../requirements/1201/r1-loan-domain.md
      id: 1201
      revision: 1
    - path: ../../../requirements/1202/r1-price-ledger.md
      id: 1202
      revision: 1
    - path: ../../../requirements/1203/r1-sac-ledger.md
      id: 1203
      revision: 1
    - path: ../../../requirements/1204/r1-money-invariants.md
      id: 1204
      revision: 1
    - path: ../../../requirements/1205/r1-zero-and-single-period.md
      id: 1205
      revision: 1
    - path: ../../../requirements/1206/r1-cent-precision-errors.md
      id: 1206
      revision: 1
    - path: ../../../requirements/1207/r1-comparable-results.md
      id: 1207
      revision: 1
  results:
  - requirement:
      path: ../../../requirements/1201/r1-loan-domain.md
      id: 1201
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1201'
  - requirement:
      path: ../../../requirements/1202/r1-price-ledger.md
      id: 1202
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1202'
  - requirement:
      path: ../../../requirements/1203/r1-sac-ledger.md
      id: 1203
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1203'
  - requirement:
      path: ../../../requirements/1204/r1-money-invariants.md
      id: 1204
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1204'
  - requirement:
      path: ../../../requirements/1205/r1-zero-and-single-period.md
      id: 1205
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1205'
  - requirement:
      path: ../../../requirements/1206/r1-cent-precision-errors.md
      id: 1206
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1206'
  - requirement:
      path: ../../../requirements/1207/r1-comparable-results.md
      id: 1207
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1207'
- kind: spec
  artifact:
    path: ../../../specs/1013/r2-widgets-interface.md
    id: 1013
    revision: 2
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  applicability:
    mode: engineering
    declared_by: dev
    requirements:
    - path: ../../../requirements/1211/r1-localized-input.md
      id: 1211
      revision: 1
    - path: ../../../requirements/1212/r1-rate-presentation.md
      id: 1212
      revision: 1
    - path: ../../../requirements/1213/r1-comparison-presentation.md
      id: 1213
      revision: 1
    - path: ../../../requirements/1214/r1-ui-state-recovery.md
      id: 1214
      revision: 1
    - path: ../../../requirements/1215/r1-keyboard-navigation.md
      id: 1215
      revision: 1
    - path: ../../../requirements/1216/r1-resize-access.md
      id: 1216
      revision: 1
    - path: ../../../requirements/1217/r1-model-help.md
      id: 1217
      revision: 1
  results:
  - requirement:
      path: ../../../requirements/1211/r1-localized-input.md
      id: 1211
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1211'
  - requirement:
      path: ../../../requirements/1212/r1-rate-presentation.md
      id: 1212
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1212'
  - requirement:
      path: ../../../requirements/1213/r1-comparison-presentation.md
      id: 1213
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1213'
  - requirement:
      path: ../../../requirements/1214/r1-ui-state-recovery.md
      id: 1214
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: pass
    method: test
    evidence: '#req-1214'
- kind: spec
  artifact:
    path: ../../../specs/1014/r2-reproducible-delivery.md
    id: 1014
    revision: 2
  implementation:
    root: /home/paulo/ceseb
    commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
  applicability:
    mode: engineering
    declared_by: dev
    requirements:
    - path: ../../../requirements/1221/r1-build-contract.md
      id: 1221
      revision: 1
    - path: ../../../requirements/1225/r1-runtime-packages.md
      id: 1225
      revision: 1
    - path: ../../../requirements/1226/r1-native-smoke.md
      id: 1226
      revision: 1
    - path: ../../../requirements/1227/r1-technical-documentation.md
      id: 1227
      revision: 1
    - path: ../../../requirements/1228/r1-distribution-notices.md
      id: 1228
      revision: 1
  results:
  - requirement:
      path: ../../../requirements/1225/r1-runtime-packages.md
      id: 1225
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: fail
    method: test
    evidence: '#req-1225'
  - requirement:
      path: ../../../requirements/1227/r1-technical-documentation.md
      id: 1227
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: ce5db2e9d7489e0b6258b449358d620a0c390b1e
    result: fail
    method: inspection
    evidence: '#req-1227'
```
