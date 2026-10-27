---
id: 2241
revision: 1
type: document
tags: [mortgage, synapses, independent-review, correction, linux, windows]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Revisão independente do snapshot 57 com 18 pass, 1228 fail por avisos DXC, seis requisitos sem resultado integral e startup técnico Windows observado.
use_when:
- Aplicar os resultados atuais dos 25 requisitos e a aplicabilidade completa das quatro specs na Synapses 2 sem repetir a revisão técnica.
---
# Revisão independente Synapses 2

Sou a instância fresca `/root/independent_review_r2`, mesmo head lógico `design-project-1/independent-review` e mesma memória atribuída. Não sou autor ou coautor de produto, testes ou planos nesta rodada. Li os contratos dev/code-review/security-review/search/synapses e as fontes recebidas. Não alterei esses materiais nem apliquei status.

Resultado atual: **18 requisitos pass, um fail (1228) e seis sem resultado completo**. Reexecutei independentemente os 17 oráculos financeiros/GUI e inspecionei integralmente a documentação corrigida (1227). F1 e F2 estão corrigidos no DEB atual. A inspeção do novo ZIP acrescentou F3: duas DLLs DXC sem materiais específicos de licença/avisos recuperáveis no pacote. O requisito 1225 integral ainda não tem resultado no 57: o novo ZIP existe, mas sua auditoria de avisos tem o defeito F3 e o uso em instalação limpa permanece indisponível. Seu fail no ce5 permanece histórico. Ausência de execução não foi convertida em falha nem em aprovação.

## Corte, autoridade e fontes

ROOT e implementação: `/home/paulo/ceseb`; sessão MAIN `.mikoshi/brain/sessions/1-mortgage-desktop`; branch `codex/mortgage-desktop`. **Snapshot único atual: 57ef26901d4381ead16c7347483d588ad9d92efe**. Autoridade: [1036](../../../documents/1036/r1-bounded-corrections-and-validation-authority.md), [1039](../../../documents/1039/r1-windows-tools-installation-authority.md) e [round 2240](round.md), complementadas pelas autoridades históricas 1028/1034/1035. Fontes aprovadas locais não foram alegadas como conteúdo Git do 57.

Seleção exata: specs 1008 r2/1012 r2/1013 r2/**1014 r3**; requisitos1101..1106, 1201..1207, 1211..1217, 1221/1225/1227/1228 r1 e **1226 r2**. A escolha humana 1037/1038 aceita WSL somente na parte Linux de 1226. Não herdei o resultado de 1226 r1. Retirement dos predecessores 1226 r1/1014 r2 foi recusado pelo CLI por exigir Related no corpo antigo; corpos aprovados preservados, seleção explícita sem regra latest. Não cabe ao reviewer forçar esse efeito.

Recebi e li integralmente [2211](../../dispatch/r2/tests/2211-r1-base-result.md), [2212](../../dispatch/r2/tests/2212-r1-final-result.md), [2221](../../dispatch/r2/implementation/2221-r1-implementation-result.md), [2231 r1](../../dispatch/r2/windows-tools/2231r1-installation.md) e [2231 r2](../../dispatch/r2/windows-tools/2231r2-community-installation.md). A correção de transporte de 2221 preserva a prosa anterior e declara D-1225/D-1227 complete com procedimento global partial; não acrescenta execução. Li original 1001/1005, todos os 25 corpos efetivos, quatro specs atuais e os planos 2003/2004 completos; recuperei 2101 e os reports históricos pertinentes, incluindo o XCB 25/26 original. As 19 notas de conhecimento foram lidos como drafts atribuídos, sem promoção ou força normativa nova; notas 6.8.3 não substituem o pin 6.12.0.

O corte tem 55 paths de produto/testes desde o bootstrap. Li os 55 integralmente e o delta atual de 7: dois creates de regressão no 4eb022d e cinco modifies posteriores no 57. Os 48 retidos têm os mesmos blobs de ce5; código financeiro/API/UI e oráculos antigos permanecem idênticos. Reuso dessa prova de identidade acompanha nova execução e novo julgamento, sem transportar automaticamente os 17 pass antigos. [Auditoria de fonte/pacote](dev/package-source-audit.json), [compatibilidade](dev/source-compatibility.json), [preservação](dev/body-preservation.json) e [matriz completa](dev/requirement-trace.json).

Todos os 55 paths selecionados permanecem limpos; hashes estáveis no build Linux. Export Windows próprio contém 70 arquivos imutáveis do Git archive 57, antes/depois idênticos. Os 22 assets anteriores e os dois novos scripts não foram alterados após seus commits. Conferi **47/47 corpos preservados**: 43 do snapshot aprovado antigo+quatro inputs atuais 1226 r2/1014 r3/2003/2004. README raiz, dirty/untracked e estado/memória raiz alheios permanecem fora de minha escrita.

## Execução própria

Linux: WSL2, Ubuntu 26.04 x86_64/GCC 15.2, CMake 3.28.6, Ninja 1.13.1, Qt 6.12.0, Boost 1.86.0, GTest 1.17.0 existentes. Build próprio `build/review-r2/linux`, core `build/review-r2/core`; logs em `out/review-r2`. Configure Release com GUI/TESTS ON, SourceRevision 57 real, Boost root e prefixos Qt/GTest/SDK privados explícitos. Ambiente do subprocesso; sem instalação/download ou alteração global. Comandos/exits/durações: `out/review-r2/linux-execution.json`.

Windows: Windows 11 Pro x64, Build Tools 2022 v17.14.35, MSVC 19.44.35228/v143, SDK 10.0.26100.0, CMake 3.31.6-msvc6, Ninja 1.12.1. Preflight próprio não encontrou instalador ativo. Export/build próprios em `C:/Users/paulo/AppData/Local/CESEB/review-r2`; reutilizei dependências nativas existentes somente leitura. Wrappers próprios chamam vcvars64 da instalação efetiva, PATHEXT/PATH apenas no processo e CWD explícito. Guard CRT OFF. Comandos/exits/durações e integridade: `out/review-r2/windows-execution.json`, `windows-integrity.json`. A sequência Windows encerrou antes do root orientar intervenção humana UAC. Nenhuma Community instalada/ativada foi presumida.

| Operação independente | Linux | Windows |
|---|---|---|
| Configure/build Release paralelo 2 |0/0|0/0|
| Inventário |20 casos domínio/13 suites+4 slots GUI|mesmo conjunto|
| CTest offscreen |26/26; 0 falhas ou skips|26/26; 0 falhas ou skips|
| CTest backend gráfico |26/26 XCB; 0 falhas ou skips|26/26 windows; 0 falhas ou skips|
| Core-only, GUI OFF, Qt discovery disabled |21/21; exit 0|21/21; exit 0|

Os 26 entries são 20 casos GTest+4 slots QtTest+2 inventários, não 26 requisitos. Li as saídas/JUnit, incluindo o núcleo 21/21 em ambos. Os testes Windows são binários Windows nativos iniciados pelo terminal; QtTest não é Computer Use nem demonstração manual. O warning inicial UNC é seguido por cd explícito correto; file(REAL_PATH) no diretório core ainda inexistente produziu warning de desenvolvedor, mas configure/build e todos 21 casos concluíram. Qt estava instalado; discovery disabled não demonstra ausência física.

Recompilei contra o core 57 o probe de observação independente já existente da rodada 1, sem criar/alterar assets: sete vetores normativos/fronteiras, todas as identidades de livros, SAC 12 literal e recomposição efetiva 0/4.5/12 passaram; `out/review-r2/oracle-probe.json/.log`. Isso preenche explicitamente os vetores de 1204 não esgotados pela grade. A grade automatizada cobre 480 entradas fixas; 330 comparações válidas e 150 recusas UnsupportedCentPrecision no run detalhado histórico compatível; os casos atuais foram reexecutados, sem alegar varredura de todo domínio.

Cobertura de código **não mensurada, não zero**. Instrumento previsto anteriormente: gcov 13/GCC 13, indisponível; não substituí por gcov 15 nem criei limiar. Denominador de código pertinente: seis unidades próprias src/core, src/ui, src/app e headers associados; exclui Qt/Boost/GTest, tests, moc/qrc/autogerados e build/stage. Universo de obrigações: 25 requisitos, 101 AC numerados; 75 AC pertencem aos 18 requisitos pass; quatro AC pertencem ao requisito 1228, com violação confirmada no AC2; 22 AC pertencem aos seis requisitos sem resultado integral. Uma contagem de testes não é cobertura de critérios.

## Correções e auditoria do pacote

Instalei somente sob DESTDIR próprio, gerei outro DEB 57 por CPack e extraí esse DEB e o recebido em diretórios próprios. Install/CPack/extract/info e as duas regressões retornaram 0 em cada pacote. Sem instalação global. Comandos:  `out/review-r2/package-execution.json`; driver:  `dev/package.py`.

- DEB recebido: SHA256 `6827856d68ad39d35490a31dfdec90df9fdf63f8e45bc95dfd103b06fdceb4b4`.
- DEB próprio:  `out/review-r2/packages/ceseb_0.1.0_amd64.deb`, SHA256 `0ab727f89ead1eb627afb6456cab595c007a1a3bcb9f0ffc1021f0bdfed24f45`.

São artefatos distintos do mesmo snapshot; não alego identidade binária/reprodutibilidade byte a byte. Em ambos, 177/177 hashes do prefixo e 127/127 registros de notices conferem; as duas cópias raiz de licenças são idênticas à origem e às cópias licenses; os quatro docs são idênticos ao 57. Os 21 registros da allowlist somam 311651 bytes e conferem literalmente com as origens. Os 30 links locais e 25 ocorrências de evidência no relatório resolvem dentro da árvore. O launcher global fica fora do manifesto do prefixo e foi conferido separadamente; não o escondo num denominador errado.

**F1/1225 corrigido no conteúdo observado.** Trigger anterior: descobrir o launcher após instalação padrão com busca XDG. Esperado: desktop file nos diretórios padrão com Exec real. Anterior ce5: somente /opt/ceseb/share/applications. Atual 57: `/usr/share/applications/ceseb.desktop` igual à fonte e Exec `/opt/ceseb/bin/ceseb` presente, com a cópia privada mantida. Causa corrigida em cmake/Packaging.cmake e manual. A regressão lê o DEB real e não deriva esperado do código de packaging. O antigo fail ce5 continua qualificado àquele snapshot; não há pass nem novo fail integral 1225 no 57 porque o restante do oráculo está indisponível.

**F2/1227 corrigido e requisito atual pass.** Trigger anterior: seguir os dois links de licença no índice instalado e recuperar as evidências técnicas. Esperado: arquivos locais entregues com origem/alvo. Atual 57: links resolvem cópias idênticas, 21 registros históricos explícitos incluídos e claims preservam seus alvos/limites. A leitura humana integral complementa a regressão que só confere existência. Textos de instalação/build Windows são instruções ainda condicionadas, sem selo falso de execução; relatos antigos distinguem núcleo 1d87900, GUI 6eb4c28, binário 2b e revisão ce5. O XCB 25/26 original e 17 pass/2 fail/6 sem resultado de 2101 permanecem atribuídos. Registros contextuais fora do subset estão identificados como não entregues; o índice direto recupera os registros de execução citados. Não é certificação jurídica ou afirmação de publicação GitHub do Brain.

A entrada `CESEB_DELIVERY_EVIDENCE_ROOT` é explícita e vazia por padrão; build não a exige, install/package a exige. Meu build Windows sem essa entrada concluiu. Li o negativo autoral `missing-input-check.json` e log: configure 0, install 1 por Delivery evidence unavailable e restauração 0; inspecionei o caminho causal atual. Não dupliquei o diagnóstico ou alterei a origem para obter verde. O staging por DESTDIR é documentado e evita escrita global do destino absoluto do launcher. Allowlist literal; nenhum Brain inteiro, cache, memória ou transcrição incluído por glob.

`readelf`/`ldd` próprios, com somente runtimes de sistema privados no LD_LIBRARY_PATH, retornaram 0/sem not found para app e qxcb nos dois DEBs. Qt resolve na extração privada; RPATH do app=$ORIGIN/../lib. QtCore/DBus/Gui/Widgets/XcbQpa e ICU estão presentes; sem QtNetwork/QtTest/GTest/glibc privada/headers no runtime. Isso não qualifica Ubuntu 24.04 limpo nem a execução do novo ZIP Windows descrito no complemento abaixo.

## Demonstração recebida e limites

Inspecionei o helper Linux, estados, eventos, hashes, mapas e as capturas 02/03/04/05/06/07/10/11/12. [Conferência](dev/ui-evidence-audit.json). O helper usa X11/XTest/XGetImage no cliente identificado por PID/UID/exe/_NET_WM_PID e confere foco. Não é ferramenta Windows nem Computer Use. Li o diagnóstico de duas tentativas de Computer Use/reset antes de JS: sandboxCwd is not a local file URI. Não houve fallback UIA/Win32, alteração de segurança ou imagem Windows fabricada.

Para 1226 r2, a evidência Linux do pacote recebido é suficiente para os cenários daquela parte: nominal 02 com 1/12/12.682503%, Price 340.02/340.03/1020.07/20.07, SAC 343.34/336.66/1020/20 e diferença +0.07; efetiva 03/04 invalida e recalcula os valores exigidos; 05/06 erro e recuperação, 07 limpar/nominal/foco, teclado, 10 resize 800×600 e Escape encerra. SHA 57 aparece na ajuda; pacote/hash e runtime conferem. Não tratei a tentativa inicial 01 de preenchimento incorreto como nominal aprovado. A recusa de foco do helper após fechar ajuda foi reconciliada e não é defeito comprovado do produto.

Sobre 11/12 abriu e rolou em namespace de rede privado distinto do host, somente lo e rota IPv4 vazia. Os tópicos 1..3 de 1217 e versão foram observados offline. O link para pasta local licenses existe, mas seu handler externo não foi acionado; falta verificar esse acesso pela aplicação para completar AC4. A imagem 800×600 está sem resultados e não substitui quatro combinações de escala. A navegação recebida é parcial para 1215 e não muda sua matriz Windows 11/Ubuntu 24.04. O novo ZIP Windows existe e teve abertura técnica local, mas não a demonstração financeira; 1226 r2 continua sem resultado integral. WSL aceito só em 1226, sem relaxar 1221/1225/1215/1216/1228.

## Complemento Windows recebido, startup e finding F3

Recebi e li integralmente [2231 r3](../../dispatch/r2/windows-tools/2231r3-community-readback.md) e [2222 r1](../../dispatch/r2/implementation/2222-r1-qualified-windows-result.md), além dos anexos materiais. A instalação Community foi estabelecida por readback de instância, logs e probe. Meus testes Windows anteriores continuam atribuídos ao Build Tools. O autor fez nova execução Community 17.14.43/cl 19.44.35229 sobre os 70 arquivos imutáveis 57: configure/build/inventários, 26/26 offscreen, 26/26 windows, 21/21 core, install e CPack retornaram 0. Esses runs adicionais são autorais; não reatribuo minha execução anterior à Community.

ZIP real: `C:/Users/paulo/AppData/Local/CESEB/r2/community-packages/ceseb-0.1.0-windows-x86_64.zip`, 91.450.912 bytes, SHA256 `c71634da99c2efe7774db55e011883b2c12f001db7a972404093f7c05968da4b`. Extraí cópia própria em `out/review-r2/windows-received`. Conferi 185 arquivos/184 hashes, 21 registros históricos idênticos, quatro documentos iguais ao 57, 30 links locais recuperáveis e regressão CMake de links exit 0. Os oito CRTs coincidem com a origem Community/VC/Redist; DOCX original e edition.txt conferem. Minha inspeção com objdump encontrou 24 PEs AMD64, com imports estáticos resolvidos na árvore, System32 ou API sets; o relatório autoral cobre também delayimports. A resolução de nomes não demonstra todos os carregamentos dinâmicos. [Auditoria própria](dev/windows-zip-audit.json), [script](dev/audit_windows_zip.py) e log `out/review-r2/windows-received-links.log`.

Por instrução posterior do root dentro do escopo 1225, executei uma única abertura técnica do ZIP em cópia nativa própria `C:/Users/paulo/AppData/Local/CESEB/review-r2/runtime`. PATH do processo era somente `C:\Windows\System32;C:\Windows`; removi variáveis de descoberta SDK/plugin no processo e selecionei backend windows. PID 12240 permaneceu vivo, com janela presente e título **CESEB · Calculadora de financiamento**. Qt6Core/Gui/Widgets vieram exclusivamente de runtime/bin do pacote; o inventário de módulos foi salvo. Encerrei somente esse processo, depois de conferir seu caminho, com own_process_ended=true. Wrapper exit 0. [Driver](dev/startup_windows.py), `out/review-r2/windows-runtime-execution.json` e `windows-runtime-startup.json` guardam argumentos, processo, módulos e cleanup. PowerShell recebeu opção ExecutionPolicy apenas para aquela invocação, sem mudança persistida de política ou configuração do sistema. Nenhum input, captura, UIA, input Win32 ou Computer Use foi usado. Essa abertura demonstra load local neste Windows 11 com PATH sem SDK; não é teste em máquina limpa, uso financeiro ou demonstração manual de 1226.

O ZIP também contém Qt6Network e plugins TLS/network/TUIO, imageformats, styles e plataforma Windows trazidos pelo deploy. Não descrevo esse conteúdo como mínimo ou sem QtNetwork. O app próprio não chama rede de negócio; isso não prova que todo código de plugin seja inalcançável sob outra configuração. Não abri campanha de exploração nem removi arquivos para forçar a auditoria.

### F3 — materiais de licença e avisos DXC ausentes

**P2, defeito confirmado de composição/documentação. Trigger:** extrair o ZIP c71634da e recuperar os materiais de cada componente incluído. **Esperado:** 1228 r1 AC2 exige licença e avisos recuperáveis no inventário e nos materiais acompanhantes. **Atual:** `bin/dxcompiler.dll` e `bin/dxil.dll`, versão 1.8.2502.11 segundo os metadados nativos, estão presentes. Seus hashes são `b855ee494c60a5dd0638d4574bc4d728c87fac5d415b9be3122058b5adefda77` e `2ae215743ca9c9c5ccfe4d53856e582c234a300a3186fc987c1d2bbe0738c50a`, idênticos aos arquivos de WindowsKits/10/Redist/D3D/x64. Inspecionei 112 textos de notices e o DOCX Community; não recuperam termos específicos e THIRD_PARTY_NOTICES não identifica DXC. No conjunto de 140 textos pesquisados, só o manifesto de hashes nomeia essas DLLs. A fonte QtBase incluída fornece o código de deploy, sem identificar materiais específicos desses binários SDK.

**Causa/path:** `/home/paulo/ceseb/cmake/WindowsDeploy.cmake:14` desliga `--no-system-d3d-compiler`, enquanto DXC tem opção separada. Na fonte QtBase exata, main.cpp:188 mantém systemDxc=true; main.cpp:473 define `--no-system-dxc-compiler`; main.cpp:583 faz o parse separado; main.cpp:1793..1797 acrescenta findDxc. utils.cpp:447 procura WindowsSdkDir/Redist/D3D. `/home/paulo/ceseb/cmake/ThirdPartyNotices.cmake` prepara Qt/Boost/GTest/ICU, sem um material para os novos componentes SDK. **Impacto:** quem recebe o ZIP não consegue recuperar os termos/avisos de dois componentes entregues e conferir sua preservação pelo inventário. **Base do fail 1228:** violação observada do AC2. O AC4 e as permissões jurídicas específicas não são presumidos ou aceitos pelo reviewer. Assinatura Microsoft válida não prova esses termos. Não concluo infração jurídica ou que o DOCX Community supre os materiais SDK.

A correção causal precisa cobrir os componentes efetivos e seus materiais ou revisar explicitamente a composição aprovada. É recomendação para decisão futura. Não mudei fontes, flags, pins ou pacote, não baixei licenças e não iniciei outro ciclo. O ZIP é artefato de engenharia gerado, ainda sem qualificação integral ou publicação. F3 não apaga as correções F1/F2.

## Planos, commits e procedimento

|Plano/range próprio|Check mecânico atual|Procedimento recebido e julgamento|
|---|---|---|
|2004 r1: ce5..4eb022d|ok/exit 0; dois creates cobertos; zero unexpected/dirty planned|D1227 complete; D1225 incomplete pelo complemento Windows/limpo; V1215/V1216/V1217/V1221/V1226/V1228 incomplete; global partial|
|2003 r1: 4eb022d..57|ok/exit 0; cinco modifies cobertos; zero unexpected/dirty planned|D-1225/D-1227 complete conforme Completion evidence limitado; follow-up Windows gerou ZIP em 2222, mas avisos DXC têm F3; global partial|

Os sete paths da rodada estão exatamente dispostos entre os dois autores. As regressões foram criadas/commitadas antes do produto e os logs 2211 mostram RED de conteúdo no DEB ce5, não erro de coleta. Os 22 assets/oráculos antigos permanecem. Check de commit não conclui requisito nem procedimento global. Nenhum plano recebe implemented por estes checks. Os planos 2001/2002 e resultados antigos permanecem históricos e não foram reescritos; suas rotas atuais são conservadas na matriz, complementadas por 2003/2004. As pendências dos planos antigos não são apagadas por novos resultados de requisito.

## Segurança e dependências delimitadas

Métodos: leitura dirigida de fontes/inputs/erros, novos paths de instalação e allowlist documental, pins/acquisition/deploy, manifestos/imports, avisos/fontes e busca redigida de três famílias de segredo nos 55 paths e nos 21 registros históricos efetivamente adicionados ao pacote. [Registro](dev/security-observation.json): zero hits nos padrões de chave privada/token GitHub/access key AWS; não é scanner abrangente ou certificação de ausência de segredos. Nenhum Semgrep/OSV/Gitleaks foi instalado ou serviço externo recebeu fontes.

Inputs financeiros locais passam por gramáticas ancoradas e conversões inteiras verificadas. Sem credencial, rede de negócio, conta, banco, persistência ou comando formado com texto do usuário. Ajuda embutida e link file local constante não aceitam URL remota digitável. Acquisition é operação explícita de engenharia por TLS/EXPECTED_HASH/Git commit fixo; não foi repetida. Ownership do cache/preservação, download part e checagem de inventário são limites observados no código, sem alegar sandbox hostil. A correção não muda pins, deps, fórmulas ou arquitetura. Não há abstração especulativa introduzida.

QtCore contém o trecho não corrigido da conversão URL CBOR→JSON que dereferencia byteData da string sem guard; li a unidade exata 025bdad em qjsoncbor.cpp e o caminho de metadados em qfactoryloader/qlibrary. O código financeiro próprio e seus imports não introduzem QCbor/QJson nem importação de documentos. Isso limita a superfície financeira observada; Qt usa CBOR internamente em plugins e logging debug pode chamar toJson. Portanto não declaro o caminho globalmente inalcançável, ausência global de CVE ou risco aceito pelo humano. A análise histórica 2101 permanece qualificada e compatível porque dependências/pins/imports não mudaram; não executei exploit ou nova campanha de vulnerabilidades. Patch/pin/risco material não foram alterados.

MIT originais, avisos Qt/Boost/GTest/ICU, fonte QtBase exata/configuração do fornecedor e inventário Linux foram recuperados/conferidos. Textos GPL/LGPL e instruções de substituição presentes; não reconstruí Qt nem qualifiquei ABI modificada. Minha batch própria anterior usou Build Tools e guard OFF. O suplemento2231 r3/2222 identificou a instalação Community real e oito CRTs permitidos com seus materiais; o guardON dessa execução é do executor. Permanecem as condições de distribuição e o defeitoDXC; instalação ou cópia do DOCX não prova acordo de usuário final nem direito geral de redistribuição. Nenhuma conclusão jurídica geral.

## Ferramentas, cobertura de leitura e retorno

Retrieval/trace próprios retornaram partial, index_incompatible por selection/profile. Graph neighbors retornou unavailable; não é stale e não reconstruí cache. Sete source_parse_error legados e dois use_when_missing em 2231 r1/r2 foram preservados; nenhum candidato foi excluído só por falta do campo. Trace recuperou as oito rotas de 2004; a matriz própria confere todos os 25 corpos e suas rotas. Context7/Serena não são expostos no catálogo desta instância; não foram usados/instalados. Leitura local é fallback delimitado, sem fingir quitação da obrigação de ferramenta. A role dev r15 foi lida manualmente; handle não prova carregamento/readback ou native_id.

Os três drafts 2231 r1/r2/r3 possuem metadata incompatível com o schema atual: type report fora do enum e campos tags/updated/use_when ausentes. O diagnóstico do root está em `evidence/synapses/r2/environment-artifact-checks.json`. Isso qualifica a integração documental, não invalida os arquivos, logs/probes/licenças lidos nem é requisito de produto. Não alterei esses reports; o analyst recebeu a responsabilidade de eventual correção metadata-only, com corpo/ID/revisão preservados.

A leitura cobre os 55 paths atuais, 25 requisitos, quatro specs efetivas, planos 2003/2004, autoridades exatas, sete reports recebidos completos (incluindo 2231 r3 e 2222), 19 notas draft, 2101 e históricos pertinentes/estruturas de 2001/2002. Os manifests registram hashes e identidade; não afirmo ler toda Qt/Boost ou todo Brain. Resultados de corpos aprovados foram julgados com suas fontes e efeitos atuais, sem alteração normativa. Telemetria opcional não tem série útil; não abri nova etapa.

O conjunto aplicável completo é 1008 r2={1101..1106}, 1012 r2={1201..1207}, 1013 r2={1211..1217}, 1014 r3={1221, 1225, 1226 r2, 1227, 1228}. Requisitos 1222..1224 obsolete excluídos. As specs 1008/1012 qualificam implemented no 57 pelos conjuntos completos pass; 1013/1014 r3 apenas partial implemented. O bloco seguinte tem 19 resultados de requisitos (18 pass e um fail) e quatro declarações completas de aplicabilidade. Os seis sem resultado são omitidos dos result rows, sem fabricar um terceiro estado ou transferir fail/pass ce5. Quem aplica é o analyst, após este retorno integral e os reports completos, sem repetir testes. O defeito 1228 mantém 1014 r3 parcial.

Não houve autoria/edição de produto/teste/plano, nova instalação, download, commit Git, push, PR, CI remoto, merge, release, promoção ou encerramento. Nenhum achado abre automaticamente outro ciclo. Próximo responsável: orquestrador→analyst da rodada 2 para reconciliar os relatórios e metadados; root/humano/syncer para as capacidades Windows/CRT/UAC e validações pendentes sob autorização própria.

## Resultado por requisito

### Req 1101

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1101 e 2002/I-1101; complemento 2003/2004: nenhum.

Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`. Testes: `tests/domain/req1101_rate_kind_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. Nominal 12 mensal 0.01 dentro 1e-12.
2. Efetiva 12 mensal 0.009488792934582974126355069193493956 dentro 1e-12.
3. nullopt e enum desconhecido retornam somente InvalidRateKind.

### Req 1102

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1102 e 2002/I-1102; complemento 2003/2004: nenhum.

Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`. Testes: `tests/domain/req1102_nominal_monthly_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. Quatro entradas 0/4.5/12/100 têm referências 0/.00375/.01/1/12.
2. Predicado Decimal usa erro absoluto 1e-12 sem double.
3. Zero numérico exato e crescimento racional 1.

### Req 1103

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1103 e 2002/I-1103; complemento 2003/2004: nenhum.

Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`. Testes: `tests/domain/req1103_effective_monthly_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. Efetiva 0 retorna zero exato.
2. Efetiva 4.5 atende referência e 1e-12.
3. Efetiva 12 atende referência e 1e-12; recomposição adicional 0/4.5/12 com erros 0/1.06245e-47/1.65447e-47.

### Req 1104

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1104 e 2002/I-1104; complemento 2003/2004: nenhum.

Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`. Testes: `tests/domain/req1104_annual_equivalents_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. Nominal 12 N=12 e E=12.682503013196972066120100 dentro 1e-9.
2. Efetiva 12 N=11.386551521499568951626083032192747 e E=12 dentro 1e-9.
3. Duas entradas zero retornam N/E zero exatos.
4. Nominal 100 E segue 100*((13/12)^12-1), acima 100 sem cap.

### Req 1105

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1105 e 2002/I-1105; complemento 2003/2004: nenhum.

Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`. Testes: `tests/domain/req1105_invalid_rate_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. NaN/Infinity/-Infinity ->NonFiniteRate em ambos tipos.
2. -0.01/100.01 ->RateOutOfRange em ambos tipos.
3. 0/100 aceitos com projeções finitas; análise do guard rejeita não finitos.

### Req 1106

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1106 e 2002/I-1106; complemento 2003/2004: nenhum.

Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`. Testes: `tests/domain/req1106_exact_rate_transport_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. Descritor efetivo retém kind, p=12, g=28/25 e projeção dentro 1e-12.
2. Textos quatro/seis casas 0.9489/0.948879 não alteram resultado.
3. compare chama normalize uma vez e passa rate aos dois livros; UI monta LoanInput a partir de MoneyCodec, sem ler labels.
4. Nominal 100 crescimento 13/12; principal 6, n=1 cobra juro 1 em ambos depois da quantização de labels.

### Req 1201

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1201 e 2002/I-1201; complemento 2003/2004: nenhum.

Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`. Testes: `tests/domain/req1201_loan_domain_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. C=0 e 10000000001 ->PrincipalOutOfRange sem Comparison.
2. n=0 e 601 com C válido ->TermOutOfRange.
3. C=1, n=1 eC máximo, n=1/600 aceitos a taxa 0.
4. Erros combinados respeitam principal, taxa/tipo, prazo, centavos.

### Req 1202

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1202 e 2002/I-1202; complemento 2003/2004: nenhum.

Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`. Testes: `tests/domain/req1202_price_ledger_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. Price 3: pagamentos 34002/34002/34003; juros 1000/670/337; saldos 66998/33666/0.
2. Resumo ordinary 34002, total 102007, interest 2007, actual 3.
3. Zero 600: ordinary 167, last 134, actual 599, total 100000.
4. Código e vetores verificam min(a, B+I) antes de n, quitação B+I em n e parada no saldo 0.
5. C=3, zero, n 2: ordinary 2 e pagamentos 2/1.
6. Efetiva 12, C=100000, n 3: ordinary 33968, pagamentos 33968/33968/33968; fronteiras do intervalo exato coincidem antes de aceitar.

### Req 1203

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1203 e 2002/I-1203; complemento 2003/2004: nenhum.

Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`. Testes: `tests/domain/req1203_sac_ledger_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. SAC 3 amort 33334/33333/33333; juros 1000/667/333; pagamentos 34334/34000/33666; saldos 66666/33333/0.
2. Resumo total 102000, interest 2000, actual 3.
3. Grade SAC admissível: n linhas e amortizaçãoq+(k<=r), diferenças<=1.
4. Juros calculados com saldo anterior e half-up exato; pagamentos não crescentes na grade.
5. C=6, 100%, n=1 ->juro 1/pagamento 7; vizinhos 5.999999/6/6.000001 ->juros 0/1/1.

### Req 1204

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1204 e 2002/I-1204; complemento 2003/2004: nenhum.

Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`. Testes: `tests/domain/req1204_money_invariants_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. Identidades de cada linha verificadas por cpp_int na grade e pelo probe de todos os vetores normativos/fronteiras.
2. Soma principal=C e saldo final 0; sem linha após quitação.
3. Total=sum pagamentos=C+sum juros e resumos iguais; probe inclui 120000/zero/12.
4. Price 1..n e SAC n em todos os livros produzidos; rejeições separadas.

### Req 1205

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1205 e 2002/I-1205; complemento 2003/2004: nenhum.

Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`. Testes: `tests/domain/req1205_zero_single_ties_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. 120000/zero/12: cada livro 12 pagamentos 10000, total 120000, juros 0.
2. 100/nominal 6/n=1: juro 1 e pagamento 101.
3. Uma única linha, saldo 0, sem segunda cobrança.
4. 6/nominal 100/n=1: juro 1 e pagamento 7 conservando 1/12.
5. Vizinhos 6%: juros 0/1/1, pagamentos 100/101/101.
6. Fixture exata 100*((201/200)^12-1), com mais de seis casas; classificada RationalGrowth 201/200, juro 1/pagamento 101.

### Req 1206

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1206 e 2002/I-1206; complemento 2003/2004: nenhum.

Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`. Testes: `tests/domain/req1206_cent_admissibility_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. C=1/zero/n=600 ->UnsupportedCentPrecision.
2. C=1200/nominal 100/n=600 ->UnsupportedCentPrecision; ordinary e primeiro juro 100.
3. Variante Error não contém Comparison; ambos os erros atômicos.

### Req 1207

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1207 e 2002/I-1207; complemento 2003/2004: nenhum.

Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`. Testes: `tests/domain/req1207_comparison_test.cpp`, `tests/support/financial_fixtures.hpp`.

1. Inspeção própria: uma normalize, mesmos C, n, rate para Price/SAC.
2. Nominal 12/100000/3 juros 2007/2000 e diferença +7.
3. Efetiva 12.682503013196972066120100 preserva livros literais.
4. Quantizar não altera origem; efetiva 12 distinta, juros 1904/1898, diferença +6.

### Req 1211

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1211 e 2002/I-1211; complemento 2003/2004: nenhum.

Produto: `src/ui/money_codec.hpp`, `src/ui/money_codec.cpp`. Testes: `tests/gui/req1211_localized_input_test.cpp`, `tests/gui/gui_tests.hpp`, `tests/gui/gui_test_main.cpp`.

1. Codec aceita 100.000,00/100000,00 ->10000000; recusa quatro formatos normativos.
2. Taxas 4,5/4,123456 aceitas; 4.5/4,1234567 recusadas sem truncar.
3. Prazo 360 aceito; 0/3,5 recusados.
4. Ambos tipos preservados; gramáticas ancoradas e trimmed externo; controlador monta objeto tipado.

### Req 1212

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1212 e 2002/I-1212; complemento 2003/2004: nenhum.

Produto: `include/ceseb/finance.hpp`, `src/core/finance.cpp`, `src/core/exact_math.hpp`, `src/core/exact_math.cpp`, `src/ui/money_codec.hpp`, `src/ui/money_codec.cpp`, `src/ui/main_window.hpp`, `src/ui/main_window.cpp`. Testes: `tests/gui/req1212_rate_presentation_test.cpp`, `tests/gui/gui_tests.hpp`.

1. Nominal 12 labels 1,000000% / 12,000000% / 12,682503%.
2. Efetiva 12 labels 0,948879% / 11,386552% / 12,000000%.
3. Quantização inteira half-up; captions associam tipo/período a cada label.
4. Nominal 100 mostra E161,...%; análise de quantize_rates usa fração exata da fórmula sem cap.
5. Pipeline nominal anual 0,000005% / 0,000006% / 0,000007% mostra mensal 0,000000% / 0,000001% / 0,000001%, respectivamente.
6. Fixture isolada 1/2000000 ponto percentual ->inteiro quantizado 1 (milionésimo de ponto percentual) e texto 0,000001%.

### Req 1213

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1213 e 2002/I-1213; complemento 2003/2004: nenhum.

Produto: `src/ui/main_window.hpp`, `src/ui/main_window.cpp`, `src/app/main.cpp`. Testes: `tests/gui/req1213_comparison_presentation_test.cpp`, `tests/gui/gui_tests.hpp`.

1. Nove campos de valores Price/SAC conferidos contra strings literais.
2. Ambos actual 3; diferença real R$ +0,07 preservada por present; fonte lida além do helper de teste que remove + para comparar magnitude.
3. Zero 600: requested 600; Price actual 599, last 1,34, aviso 599 de 600; SAC actual 600, last 1,66.
4. Texto de ajuste presente; n=1 identifica Parcela única, com quitação final.

### Req 1214

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1214 e 2002/I-1214; complemento 2003/2004: nenhum.

Produto: `src/ui/simulation_controller.hpp`, `src/ui/simulation_controller.cpp`, `src/ui/main_window.hpp`, `src/ui/main_window.cpp`. Testes: `tests/gui/req1214_state_recovery_test.cpp`, `tests/gui/gui_tests.hpp`.

1. Edição separada de principal/taxa/prazo/tipo limpa 16 labels imediatamente.
2. Erros combinados preservam entradas, limpam resultados e seguem prioridade.
3. Focus asserts principais/taxa/tipo/prazo/calcular passaram com janela ativa; switch de show_error confere mapeamento.
4. Correção recupera ambos cartões; Limpar esvazia campos, nominal e foco principal.
5. Mensagem de centavos orienta ajustar valor/prazo/taxa; mensagens constantes sem traceback/caminho.

### Req 1215

**sem resultado completo**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método demonstração. Rota histórica: 2001/T1215 e 2002/I-1215; complemento 2003/2004: V1215.

Produto: `src/ui/main_window.hpp`, `src/ui/main_window.cpp`, `src/app/main.cpp`. Testes: protocolo/inspeção sem mudança de fonte.

1. A sequência Linux recebida mostra parte da ordem Tab e Shift+Tab; falta protocolo integral em Windows 11 e Ubuntu 24.04.
2. Enter e Escape foram observados no Linux WSL; não nos dois desktops exigidos.
3. Buddies, accessibleName e destaque de foco existem no código; falta demonstração completa na matriz.
4. Preenchimento, cálculo, erro/correção, limpar, ajuda e fechar foram observados em WSL; não completam o oráculo de duas plataformas.

### Req 1216

**sem resultado completo**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método demonstração. Rota histórica: 2001/T1216 e 2002/I-1216; complemento 2003/2004: V1216.

Produto: `src/ui/main_window.hpp`, `src/ui/main_window.cpp`. Testes: protocolo/inspeção sem mudança de fonte.

1. Não há as quatro combinações Windows 11/Ubuntu 24.04 ×100%/200% com o cenário 1000/0%/600 em 800×600.
2. A captura 800×600 Linux está sem resultados; não demonstra todo formulário/cartões nos quatro alvos.
3. O caso de quitação 599/600 passou na suíte, mas falta acesso integral ao texto nas quatro renderizações exigidas.

### Req 1217

**sem resultado completo**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método inspeção. Rota histórica: 2001/T1217 e 2002/I-1217; complemento 2003/2004: V1217.

Produto: `src/ui/main_window.hpp`, `src/ui/main_window.cpp`, `resources/application.qrc`, `resources/model-help.html`. Testes: protocolo/inspeção sem mudança de fonte.

1. Conteúdo nominal/efetiva, Price/SAC, primeiro vencimento após um mês e postecipados foi lido em 11/12 offline e no recurso embutido.
2. Half-up, ajuste final, contagem efetiva e recusa de centavos presentes e coerentes.
3. Seguros, tarifas, impostos, indexadores e exclusão de CET presentes.
4. A ajuda abriu sem rede em namespace próprio apenas lo/sem rota; versão 0.1.0/SHA 57 corretos. O destino local licenses existe, mas o handler externo não foi aberto pela aplicação; AC4/procedimento permanece incompleto.

### Req 1221

**sem resultado completo**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método teste e inspeção. Rota histórica: 2001/T1221 e 2002/I-1221; complemento 2003/2004: V1221.

Produto: `CMakeLists.txt`, `CMakePresets.json`, `cmake/Dependencies.cmake`, `cmake/AcquireDependencies.cmake`, `cmake/dependencies.lock.json`, `cmake/Version.hpp.in`, `.github/workflows/ci.yml`. Testes: `tests/CMakeLists.txt`, `tests/system/check_core_independence.cmake`.

1. Interfaces/core e dependências de ligação não incluem Qt; inspeção de fonte e core-only 21/21 próprios nas duas toolchains disponíveis.
2. Qt discovery foi desabilitado nos builds Linux/Windows, mas Qt estava fisicamente instalado; não atribuo prova da condição sem SDK.
3. O mesmo 57 rodou nas duas toolchains, mas Linux é Ubuntu 26.04/GCC 15.2, sem Ubuntu 24.04/GCC 13. Oráculo integral indisponível.

### Req 1225

**sem resultado completo**; revisão 1, snapshot 57. Método: teste e inspeção. Rotas 2001/T1225, 2002/I-1225, 2003/D-1225 e 2004/D1225. Produto: Packaging.cmake, WindowsDeploy.cmake, desktop/qt.conf e CMakeLists. Sem mudança de fonte nesta revisão.

1. O ZIP c71634da existe com app/Qt/plugins/oito CRTs e DOCX Community; 24 PEs/imports foram inspecionados. F3 impede considerar completa a cobertura de avisos. Não deduzo falta de permissão legal nem novo fail 1225 só de termos não identificados.
2. F1 corrigido: ambos DEBs contêm `/usr/share/applications/ceseb.desktop` com Exec real, Qt privado, plugin XCB, dependências declaradas e manifestos conferidos.
3. Meu startup local Windows com PATH sem SDK mostrou PID/título/janela e Qt carregado do pacote. Falta a execução completa pelo caminho publicado nos ambientes limpos Windows 11/Ubuntu 24.04; essa abertura no host atual não a substitui.
4. DEBs e ZIP identificam 0.1.0/plataforma/SHA 57. O fail 1225 ce5 permanece histórico; 57 não recebe resultado integral.

### Req 1226

**sem resultado completo**; revisão 2, snapshot 57. Método: demonstração. As rotas históricas 2001/T1226/2002/I-1226 conservam 1226 r1; a sucessora 1226 r2 usa 2004/V1226. Pacotes/protocolo são inputs, sem operação adicional de fonte.

1. Linux WSL aceito: captura 02 confirma nominal, valores e equivalências; pacote/hash/Qt privado identificados. O startup técnico do ZIP Windows não inclui o cenário financeiro exigido.
2. Capturas 03/04 confirmam invalidação e efetiva 0,948879%; Price 339,68/1.019,04/19,04; SAC 342,83/336,49/1.018,98/18,98; diferença +0,06. Parte Windows sem cenário executado.
3. Capturas 05/06/07/10 e eventos confirmam erro/correção, recálculo, limpar, teclado, resize e Escape em WSL. Não houve demonstração dessas ações no Windows.
4. Capturas e identificadores vinculam a parte Linux ao 57. Computer Use indisponível antes de JS, QtTest e título de processo não completam captura/interação Windows.

### Req 1227

**pass**; revisão 1, snapshot `57ef26901d4381ead16c7347483d588ad9d92efe`, método inspeção. Rota histórica: 2001/T1227 e 2002/I-1227; complemento 2003/2004: D1227 e D-1227.

Produto: `docs/README.md`, `docs/user-guide.md`, `docs/build-and-test.md`, `docs/technical-report.md`. Testes: protocolo/inspeção sem mudança de fonte.

1. Quatro documentos em português cobrem instalação/uso/build/teste nas duas plataformas, fórmulas, centavos, limites, exclusões, exemplo e dependências/licenças. Todos iguais a 57 no DEB; dois links de licença agora resolvem cópias idênticas.
2. Tabela histórica cobre 25 rotas e a matriz 2101 recuperável identifica tarefas, arquivos, critério/alvo. Seleção posterior 1226 r2/1014 r3 explícita, sem herdar resultado. Texto distingue snapshot do pacote e atribuição histórica.
3. Confrontei alegações verificadas com 21 registros entregues: core 21/21, offscreen 26/26, XCB 25/26 original e 26/26 ce5; falhas/não executados permanecem. Comandos Windows atuais não são anunciados retroativamente como conteúdo histórico.
4. 30 ocorrências de links locais resolvem; 25 links de evidência do relatório recuperam 21 arquivos distintos, 311651 bytes, hashes iguais às origens. Fontes contextuais excluídas do subset estão declaradas. Nenhum sucesso futuro ou hash autorreferente foi inventado.

### Req 1228

**fail**; revisão 1, snapshot 57. Método: inspeção do ZIP Windows c71634da e dos materiais locais Linux. Rota2001/T1228, 2002/I-1228, 2004/V1228. Produto: WindowsDeploy.cmake, ThirdPartyNotices.cmake, Packaging.cmake, LICENSE/THIRD_PARTY_NOTICES e o conjunto real distribuído. [Finding F3](#f3--materiais-de-licença-e-avisos-dxc-ausentes).

1. MIT/copyright dos originais presentes e separados de terceiros; não atribuí MIT às DLLs Microsoft.
2. **Violação confirmada**: dxcompiler.dll/dxil.dll estão no ZIP, mas não têm licença/avisos identificáveis no inventário de componentes e materiais entregues.112textos de notices +DOCX Community foram inspecionados; só o manifesto de hashes os nomeia no total de 140textos pesquisados. Existência/signatura/hash não substituem licença/aviso.
3. QtBase fonte025bdad/SBOM/configuração/textos GPL/LGPL acompanham os pacotes; linkdinâmico e ausência de bloqueio próprio de substituição inspecionados. Não reconstruí/substituí ABI; não atribuo isso a failure observado.
4. Os oito CRTs coincidem com as origens Community e seus termos/edição são recuperáveis; isso não supre os materiais DXC nem prova todas as condições de distribuição. A consequência formal é fail pelo AC2; direito jurídico/condições não observadas continuam delimitados.

## Validação mecânica do transporte

O validador real `mikoshi_core.status.validate` aceitou **23/23 declarações**, em modo somente leitura, com todos os alvos no mesmo snapshot 57. Os conjuntos completos das specs possuem 25 membros; seis estão explicitamente sem resultado. Nenhum `status.run` ou `status set` foi chamado. A primeira coleta do retorno do validador confundiu a tupla Python com um objeto e gerou erro no observador, após a validação; corrigi apenas esse coletor e preservei `dev/declaration-validation-observer-error.json`. Ao acrescentar o novo resultado fail, o coletor ainda solicitou pass para 1228 e recebeu a recusa literal esperada; corrigi somente esse argumento e preservei `dev/declaration-validation-windows-target-observer-error.json`. O retorno final válido está em [declaration-validation.json](dev/declaration-validation.json). Isso valida o transporte e referências, não substitui os oráculos técnicos.

## Declaração mecânica exata

```mikoshi-result-v1
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1101/r1-explicit-rate-kind.md
    id: 1101
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1101/r1-explicit-rate-kind.md
      id: 1101
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1101'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1102/r1-nominal-monthly.md
    id: 1102
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1102/r1-nominal-monthly.md
      id: 1102
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1102'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1103/r1-effective-monthly.md
    id: 1103
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1103/r1-effective-monthly.md
      id: 1103
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1103'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1104/r1-annual-equivalents.md
    id: 1104
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1104/r1-annual-equivalents.md
      id: 1104
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1104'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1105/r1-invalid-rate-input.md
    id: 1105
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1105/r1-invalid-rate-input.md
      id: 1105
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1105'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1106/r1-unrounded-consumer-rate.md
    id: 1106
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1106/r1-unrounded-consumer-rate.md
      id: 1106
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1106'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1201/r1-loan-domain.md
    id: 1201
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1201/r1-loan-domain.md
      id: 1201
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1201'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1202/r1-price-ledger.md
    id: 1202
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1202/r1-price-ledger.md
      id: 1202
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1202'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1203/r1-sac-ledger.md
    id: 1203
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1203/r1-sac-ledger.md
      id: 1203
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1203'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1204/r1-money-invariants.md
    id: 1204
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1204/r1-money-invariants.md
      id: 1204
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1204'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1205/r1-zero-and-single-period.md
    id: 1205
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1205/r1-zero-and-single-period.md
      id: 1205
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1205'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1206/r1-cent-precision-errors.md
    id: 1206
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1206/r1-cent-precision-errors.md
      id: 1206
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1206'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1207/r1-comparable-results.md
    id: 1207
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1207/r1-comparable-results.md
      id: 1207
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1207'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1211/r1-localized-input.md
    id: 1211
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1211/r1-localized-input.md
      id: 1211
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1211'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1212/r1-rate-presentation.md
    id: 1212
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1212/r1-rate-presentation.md
      id: 1212
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1212'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1213/r1-comparison-presentation.md
    id: 1213
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1213/r1-comparison-presentation.md
      id: 1213
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1213'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1214/r1-ui-state-recovery.md
    id: 1214
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1214/r1-ui-state-recovery.md
      id: 1214
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1214'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1227/r1-technical-documentation.md
    id: 1227
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1227/r1-technical-documentation.md
      id: 1227
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: inspection
    evidence: '#req-1227'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1228/r1-distribution-notices.md
    id: 1228
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1228/r1-distribution-notices.md
      id: 1228
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: fail
    method: inspection
    evidence: '#req-1228'
- kind: spec
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/specs/1008/r2-annual-rate-conversion.md
    id: 1008
    revision: 2
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  applicability:
    mode: engineering
    declared_by: dev
    requirements:
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1101/r1-explicit-rate-kind.md
      id: 1101
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1102/r1-nominal-monthly.md
      id: 1102
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1103/r1-effective-monthly.md
      id: 1103
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1104/r1-annual-equivalents.md
      id: 1104
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1105/r1-invalid-rate-input.md
      id: 1105
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1106/r1-unrounded-consumer-rate.md
      id: 1106
      revision: 1
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1101/r1-explicit-rate-kind.md
      id: 1101
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1101'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1102/r1-nominal-monthly.md
      id: 1102
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1102'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1103/r1-effective-monthly.md
      id: 1103
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1103'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1104/r1-annual-equivalents.md
      id: 1104
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1104'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1105/r1-invalid-rate-input.md
      id: 1105
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1105'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1106/r1-unrounded-consumer-rate.md
      id: 1106
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1106'
- kind: spec
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/specs/1012/r2-amortization-comparison.md
    id: 1012
    revision: 2
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  applicability:
    mode: engineering
    declared_by: dev
    requirements:
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1201/r1-loan-domain.md
      id: 1201
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1202/r1-price-ledger.md
      id: 1202
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1203/r1-sac-ledger.md
      id: 1203
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1204/r1-money-invariants.md
      id: 1204
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1205/r1-zero-and-single-period.md
      id: 1205
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1206/r1-cent-precision-errors.md
      id: 1206
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1207/r1-comparable-results.md
      id: 1207
      revision: 1
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1201/r1-loan-domain.md
      id: 1201
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1201'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1202/r1-price-ledger.md
      id: 1202
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1202'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1203/r1-sac-ledger.md
      id: 1203
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1203'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1204/r1-money-invariants.md
      id: 1204
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1204'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1205/r1-zero-and-single-period.md
      id: 1205
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1205'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1206/r1-cent-precision-errors.md
      id: 1206
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1206'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1207/r1-comparable-results.md
      id: 1207
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1207'
- kind: spec
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/specs/1013/r2-widgets-interface.md
    id: 1013
    revision: 2
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  applicability:
    mode: engineering
    declared_by: dev
    requirements:
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1211/r1-localized-input.md
      id: 1211
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1212/r1-rate-presentation.md
      id: 1212
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1213/r1-comparison-presentation.md
      id: 1213
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1214/r1-ui-state-recovery.md
      id: 1214
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1215/r1-keyboard-navigation.md
      id: 1215
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1216/r1-resize-access.md
      id: 1216
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1217/r1-model-help.md
      id: 1217
      revision: 1
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1211/r1-localized-input.md
      id: 1211
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1211'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1212/r1-rate-presentation.md
      id: 1212
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1212'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1213/r1-comparison-presentation.md
      id: 1213
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1213'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1214/r1-ui-state-recovery.md
      id: 1214
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1214'
- kind: spec
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/specs/1014/r3-wsl-validation-delivery.md
    id: 1014
    revision: 3
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  applicability:
    mode: engineering
    declared_by: dev
    requirements:
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1221/r1-build-contract.md
      id: 1221
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1225/r1-runtime-packages.md
      id: 1225
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1226/r2-wsl-linux-and-windows-smoke.md
      id: 1226
      revision: 2
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1227/r1-technical-documentation.md
      id: 1227
      revision: 1
    - path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1228/r1-distribution-notices.md
      id: 1228
      revision: 1
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1227/r1-technical-documentation.md
      id: 1227
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: inspection
    evidence: '#req-1227'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1228/r1-distribution-notices.md
      id: 1228
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: fail
    method: inspection
    evidence: '#req-1228'
```
