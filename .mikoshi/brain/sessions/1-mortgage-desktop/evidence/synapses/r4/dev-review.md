---
id: 2441
revision: 1
type: document
tags: [mortgage, synapses, independent-review, correction]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Revisão independente do produto3f4, das correções F3/F4 e dos25 requisitos nas duas plataformas.
use_when:
- Aplicar os resultados exatos da rodada r4 após as execuções2005/2006, preservando os negativos históricos.
---
# Revisão independente F3/F4

## Corte e independência

ROOT `/home/paulo/ceseb`, sessão `1-mortgage-desktop`, flow `design-project-1`, head `independent-review`. Fresh actor `/root/f3_f4_independent_review`, distinto dos autores e executores de testes/produto. Memória de entrada r11. Dev r15 foi lido manualmente; configuração/carregamento nativo do papel e native_id não observáveis. Handle não prova identidade nativa.

Autoridade: [1041](../../../documents/1041/r1-f3-f4-correction-authority.md) e [1042](../../../documents/1042/r1-f3-f4-concrete-procedure-release.md); [1040](../../../documents/1040/r1-alternative-validation-and-branch-push.md) mantém o push posterior. Snapshot único julgado **3f4dc69ec84230b4035572fc62af3d13db451d2a**. Base pública b5bb61c; TEST_HEAD 98af104; fonte antiga 57ef269 não é fonte destes verdicts.

Recebidos e lidos completos2401/2402, [2411BASE](../../dispatch/r4/tests/base-result.md), [2412FINAL](../../dispatch/r4/tests/final-result.md) e [2421produto](../../dispatch/r4/implementation/result.md). Planos 2005/2006 e autoridade concretos publicados antes dos efeitos, quatro assets de teste antes dos dois modifies de produto.35corrigeu preparo voidsetStyle em98 antes do verdadeiroRED: esse erro não vale como falha comportamental. BASE mostra ausência de glifos nos quatro controles escuros e duasDLLs no ZIPc716; final conserva os oráculos e elimina ambos os triggers.

## Execução própria e cobertura

Export imutávelGitP próprio, sem editar fonte: Ubuntu24.04.5/GCC13.3/CMake3.28.3/Ninja1.11.1 em `/work/r4/review` do contêiner `ceseb-validation-r3-ubuntu24`; Windows11/Community2022/MSVC19.44/CMake3.31.6-msvc6/Ninja1.12.1 em `C:/Users/paulo/AppData/Local/CESEB/r4/review`. Qt6.12/GTest1.17/Boost1.86 privados existentes, sem aquisição/instalação global. Configures/builds próprios0. Comandos completos e exits em [Linux](dev/linux-execution.json) e [Windows](dev/windows-execution.json); wrappers/copias locais em `ROOT/out/review-r4`. O PATH do SDK pertence apenas aos testes, separado das demonstrações de pacote.

[Contagem dos XML próprios](dev/suite-counts.json): **27/27 offscreen e27/27 XCB no Ubuntu;27/27 offscreen e27/27 windows no Windows;21/21 core-only em cada plataforma; zero falhas/skips/disabled**.27=20 casos de domínio + 5 slots GUI + 2 inventários;21=20 casos de domínio + inventário. Inventários não vazios, pixel-slot1216 isolado1/2 XCB e offscreen/windows1/2 Windows também0. Core usa GUI OFF e descoberta de Qt desabilitada; não se alegou SDK fisicamente ausente no compilador. Não foi medida cobertura de linhas/branches. Grade financeira é determinística480combinações e vetores independentes; nenhuma alegação de exaustividade.

Suítes próprias reavaliam taxas, centavos, parser, apresentação e estados na fonte P. Demonstrações dos pacotes são atribuídas aos dois executores2412/2421 e inspecionadas nesta revisão; não as chamo de inputGUI próprio. Li diretamente pixels atuais Windows100clientclean, Windows200top/rolagem/ajuda-versão, Linux100/200formulário/cartões/aviso/rodapé. UIA/AT-SPIfornecem geometria/valores e não substituem pixels. Conferidos fluxos/logs/guards e cobertura47/47 nas quatro combinações. WindowsCopyFromScreen mede interseção real monitor/viewport/WorkingArea; mover somente janela própria trouxe regiões200% ao monitor1080, sem contar PrintWindowforatela. Mascoteexterno preservado e não operado. Linux é appXCB real em Xvfb/Openbox2300×1900 privadoUbuntu24, não monitorfísicoLinux nem backendoffscreen. Isso é a condição desktop virtual efetivamente demonstrada, sem substituir a obrigação por mera injeção de eventos isolados.

## Pacotes e composição

Auditoria própria [package-review](dev/package-review.json), extrações novas `ROOT/out/review-r4/{windows,linux}-extracted`. ZIP SHA256 **f5071e93d3c99afd4b5fae395322897c8d074f928f66952366eb0b05ad762d20**,188 arquivos / 187 hashes; DEB SHA256 **8dd414362fc06456a7aadaf44acb5a80264514497433d0ba24f240d129628336**,184 arquivos / 182 hashes. Todos hashes e sourceP conferem;21 registros históricos por pacote comparados byte-a-byte comGitP, sem reatribuição dos seus testes antigos. Regressões próprias de componentesWindows, launcherDEB e links nosdois pacotes0. [PEpróprio](dev/qualified-windows-pe-closure.json):22 AMD64, imports/delayimports resolvidos somente pacote/System32/APIsets, zero irresolvidos e zero DXC/DXIL. Módulos runtime atuais atribuídos mostram Qt/plugin/CRT app-local, sem recuperaçãoDXC viaSDK. RuntimeUbuntu24offline tem somente lo/sem rota e Qt privado/sem toolchain; Windows tem SDK fisicamente instalado, mas app abre sem PATH/variáveisSDK. Não exigi sua desinstalação como novo critério.

Notice mapping do produtor confrontado com inventários reais e materiais recuperáveis.127originais hashed é um subconjunto: a árvore licenses inteira tem132 arquivos Windows e 130 Linux; todos os 132 arquivos Windows são byte-idênticos aoantigo. Probe inicial próprio confundiu denominadores e parou por assert; observador corrigido sem mudar pacote/oráculo e tentativa registrada em [preparação](dev/preparation-observations.json). Não é defeito do produto. FonteQtBase025bdad, configurações/SBOM e terceiros preservados; CRTCommunity8 com hashes/termos qualificados atribuídos. Substituibilidade por inspeção de ligação dinâmica e configuração, sem ensaioABI ou certificação jurídica.

## Escopo e inspeção técnica

Li o delta inteirob5..P: quatro arquivos de testes e dois de produto. A paleta clara entra no construtorMainWindow antes dos filhos e cobre grupos/pares/seleção/popup/ajuda/página; QApplicationé o processo do app, não configuração globalWindows. QSScompleta os pares já previstos na1013r2. A opçãoQt separada omite compiladorDXC opcional; não há filtro posterior, D3D12/QML ou nova dependência. PE+módulos+uso exercitado confrontam o risco de carga opcional. Nenhum refactor ou API pública nova. Cálculos e20oráculos financeiros antigos inalterados.

Segurança examinada no recorte: entradas locais sem importação externa/rede/persistência, validação exata, erro sem path/traceback, ajuda resource e link somente local; não há novo boundary de credenciais/processo/rede nestes dois patches. A ausência deDXC reduz o material entregue sem fallbackobservado. O risco conhecido CBOR/JSONQt preserva a análise antiga: QtCorecontém o código e plugins usam metadados; não alego inacessibilidade global ou ausência de vulnerabilidades. Não houve scannerCVE, Semgrep ou serviço remoto; cardSemgrep é contextual e não foi exigido por este delta sem nova superfície. Simplicidade: dois modifies necessários à aparência e receita existentes, sem framework/temaAPI ou biblioteca adicional.

[Commitchecks próprios](dev/plan-2005-commits.json) e [2006](dev/plan-2006-commits.json) resultok:4/4 assets b5..98 e2/2 produto98..P, zero unexpected e dirty planned. Procedimentos complete declarados pelos executores2412/2421; cabe aoanalyst aplicar planos, não inferir requisito por completion. [Preservação](dev/preservation.json):49/49 corpos aprovados iguais, paths congelados atuais iguaisGitP. Reports antigos e alterações alheias preservados. Rootpossui taildocumentalposterior fora deste snapshot.

## Julgamentos

Cada seção abaixo aplica todos osACs da revisão exata nomeada no transporte. Para1101..1207, rotas originaisI/T-doID dos planos2002/2001 chegam a finance/exact_math e testesdomainhomônimos; para1211..1214 chegam a MoneyCodec/Controller/MainWindow e QtTesthomônimo.1215..1217 e1221/25/26/27/28 têm rotasI/Toriginais e procedimentos2004; as correções atuais acrescentamT/D1216/1225/1228 dos planos2005/2006. Leitura da implementação e oráculos acima sustenta as execuções próprias; demostrações/inspeções concretas são atribuídas nominalmente, não herdadas por similaridade decommit.

### Req 1101

**pass**, método test, revisão 1, snapshot P. Os dois tipos em12% dão0,01 e0,00948879293458… dentro de1e-12; ausente/desconhecido retornam InvalidRateKind sem sucesso.

### Req 1102

**pass**, método test, revisão 1, snapshot P. 0/4,5/12/100% nominal conferem0/0,00375/0,01/1÷12; origem racional e zero exato preservados.

### Req 1103

**pass**, método test, revisão 1, snapshot P. 0/4,5/12% efetivos conferem as referências de raiz12; tolerância1e-12 e zero exato. Caso tipado pequeno conserva origem positiva.

### Req 1104

**pass**, método test, revisão 1, snapshot P. N/E dos vetoresnominal/efetiva12 e zero conferem1e-9 ponto percentual; derivado nominal100% supera100% sem corte.

### Req 1105

**pass**, método test, revisão 1, snapshot P. NaN/±Infinity rejeitados NonFiniteRate nas duas convenções;−0,01/100,01 rejeitados RateOutOfRange;0/100 inclusivos finitos.

### Req 1106

**pass**, método test, revisão 1, snapshot P. Descritor efetivo28/25 e origem12 sobrevivem apresentações4/6casas; nominal100 conserva13/12 e ambos juros1centavo no principal6/n1. Leitura do caminho não encontrou parsing de rótulos ou projeção decidindo centavos.

### Req 1201

**pass**, método test, revisão 1, snapshot P. Limites0/10000000001 e0/601 rejeitados; principal1/n1 e máximo/n1/600 aceitos; prioridade principal→taxa/tipo→prazo→centavos conferida.

### Req 1202

**pass**, método test, revisão 1, snapshot P. Livros Price nominal3, zero600(599pagamentos),3centavos/n2 [2,1], nominal12 e efetiva12/n3 conferem centavos exatos, quitação e regra final.

### Req 1203

**pass**, método test, revisão 1, snapshot P. LivroSAC3 completo, quociente/resto, nlinhas, juros half-up e prestações não crescentes conferem;100%/principal6/n1 e vizinhança6% dão1 e0/1/1centavo.

### Req 1204

**pass**, método test, revisão 1, snapshot P. Identidades por linha e somas exatas conferem nos vetores e grade8principais×6prazos×2tipos×5taxas; rejeições UnsupportedCentPrecision separadas dos livros válidos. Não é prova exaustiva do domínio.

### Req 1205

**pass**, método test, revisão 1, snapshot P. Zero1200/12 dá12×100,00; prazo1 e empates nominal6%,100%/principal6, vizinhanças e efetiva exata201/200 conferem uma cobrança e juros half-up.

### Req 1206

**pass**, método test, revisão 1, snapshot P. Principal1/zero/600 e1200/nominal100/600 retornam UnsupportedCentPrecision, sem Comparison ou livro parcial.

### Req 1207

**pass**, método test, revisão 1, snapshot P. Mesma normalização alimenta os dois livros. Nominal12 e efetiva equivalente preservam livros e diferença+7centavos; efetiva12 dá diferença+6. Apresentação não altera dados.

### Req 1211

**pass**, método test, revisão 1, snapshot P. Gramáticas pt-BR, agrupamento, precisão2/6casas, espaços externos e prazo inteiro conferem os casos aceitos/rejeitados; ambas convenções chegam tipadas ao cálculo.

### Req 1212

**pass**, método test, revisão 1, snapshot P. Três rótulos nominais/efetivos e seis casas conferem; derivado>100%, vizinhanças0,000005/6/7 e fixture isolada0,0000005 dão half-up exato, sem retorno ao cálculo.

### Req 1213

**pass**, método test, revisão 1, snapshot P. Cartõesnominal3, efetiva3, zero600 e prazoúnico conferem todos valores/contagens/aviso/última ajustada e diferença assinada; execução automática própria e capturas atribuídas de pacote.

### Req 1214

**pass**, método test, revisão 1, snapshot P. Edição de cada campo/tipo invalida tudo; erros isolados/combinados preservam entradas, priorizam/focam corretamente; ArithmeticError controlado focaCalcular, recuperação eLimpar completos sem paths/traceback.

### Req 1215

**pass**, método demonstration, revisão 1, snapshot P. Demonstrações2412/2421 na fonte P mostram Tab/ShiftTab nos sete controles, Enter, Escape, preenchimento/erro/correção/LimparSpace/ajuda nos dois desktops. Código buddies/nomes/foco e logs atuais conferidos; não se inferiu do offscreen.

### Req 1216

**pass**, método demonstration, revisão 1, snapshot P. Capturas reais atuais lidas nas quatro combinações Ubuntu24/Windows11×100/200, cliente800×600lógico, zero1000/600:47/47 alvos inteiramente alcançados por viewport/tela; campos/cartões/aviso599/600 legíveis, sem rolagem horizontal ou sobreposição impeditiva. F4 resolvido.

### Req 1217

**pass**, método inspection, revisão 1, snapshot P. RecursoHTML entregue e ajuda realmente rolada contêm taxas, Price/SAC, primeiro vencimento, half-up/prazoefetivo, exclusões e nãoCET. VersãoP e licenças locais recuperáveis; runtime Linux offline somente lo/sem rota, sem dependência de resposta remota.

### Req 1221

**pass**, método test, revisão 1, snapshot P. Interfaces/core não incluemQt; builds próprios GUI OFF com descobertaQt desabilitada e consumidores20casos+inventário21/21 nos dois toolchains. Mesmo fonte P. SDK fisicamente em outra árvore não foi rotulado ausente; nenhuma dependênciaQt no componente.

### Req 1225

**pass**, método test, revisão 1, snapshot P. PacotesSHA identificados, manifesto/versãoP/avisos/runtime conferidos; ZIPsemDXC,22PEclosure0irresolvidas. DEBtemQt privado, dependências e launcher/usr.2412/2421abrem ambos sem PATH/varsSDK; runtimeUbuntu24sem toolchain. Windowsusa hostcomSDK fisicamente instalado mas processo app-local, sem configurá-lo para abrir. AC3 não exige desinstalarSDK dohost.

### Req 1226

**pass**, método demonstration, revisão 2, snapshot P. Demonstrações atuais2412/2421 com pacote/revisãoP/SO identificados concluem nominal, trocaefetiva com invalidação, valores normativos, erro/correção, limpar/teclado/redimensionar/Escape. LinuxUbuntu24X11privado emDocker/WSL e Windows11real separados; WSLexplicitamenteaceito neste requisito.

### Req 1227

**pass**, método inspection, revisão 1, snapshot P. DocsPT cobremuso/build/modelo/limites/licenças; matriz de25 relaciona planos/arquivos/resultados históricos e seus alvos.21 registros recuperáveis e links próprios passamnos dois pacotes. Docs explicitamente distinguem fonteatualP das execuçõeshistóricasce5/2b/6eb, falhas/lacunas; nenhuma alegação marcada verificada foi reatribuída aP. Os reports atuais separados2412/2421/2441 completam a entrega documental da correção; a versão interna histórica não é novo verdictP.

### Req 1228

**pass**, método inspection, revisão 1, snapshot P. MITsomenteoriginais; Qt/ICU/Boost/GTest/CRT e terceiros efetivos com materiais/fontes/config/SBOM recuperáveis; GPL/LGPL e QtBase025bdadexato sem modificações.132arquivos de licensesWindows todos byte-identical aoZIPantigo;CRT8Communityqualificados;DEB130arquivoslicenses conferidos. DXC/DXILnão distribuídos nem alegados; substituibilidade por linkage/configuração, sem alegação de ensaioABI/certificação jurídica.

## Resultado e limites

**25 requisitos pass, zero fail ou sem resultado; specs 1008 r2, 1012 r2, 1013 r2 e 1014 r3 com todos os membros pass no mesmoP. F3/F4 resolvidos nesta fonte/pacotes; negativos de 57/c716 permanecem históricos. Nenhum achado impeditivo novo.** A conclusão cobre somente entradas, ambientes, pacotes e escalas declarados; não certifica toda resolução, ABI, contrato bancário ou segurança global. A sessão não é encerrada por este parecer e não há aprovação humana inferida.

Leitura própria:need 1001;1040/1041/1042; quatro specs e25 requisitos efetivos completos;2005/2006completos;2401/2402/2411/2412/2421completos; delta6paths; finance.hpp, finance.cpp, exact_math.cpp/hpp, money_codec.cpp, simulation_controller.cpp, MainWindow completo, appmain,20 testes de domínio e supportfixtures, quatro QtTest antigos e novo 1216, scriptscomponents/core/launcher/links; CMakeLists/Packaging/WindowsDeploy; docsREADME/user-guide/build-and-test/technical-report, THIRD_PARTY_NOTICES e model-help. Logs/JSON/XML/fontes de ambiente e capturas atuais selecionadas acima. Não li todos979assets operacionais nem todoBrain. Skills/code-reviewr12 / Synapses r15, dev r15, contratosauthority/revision/verification/status/review-boundaries/resulttransition; cards2521/2523/4188/4193/2560/2561/2562. DescobertaALL_TOOLSsemContext7/Serena; nenhum uso fictício, instalação ou native-roleloading alegado. Fonte local exata+leitura dirigida são fallback com essa lacuna de ferramenta explícita.

A função nativa status.validate é usado somente leitura viaPython, pois CLI expõe apenas status set; nenhuma mutação de status. Artifactchecklinks separado. Checks completos emdev/; resultado mecânico não substitui o julgamento. Escritas somente2441/dev/outputs privados e memória própria. Próximo: root lê este retorno integral, analyst aplica29declarações e dois planoscomplete dos executores; syncercommita/publica recorteautorizado1040/1041 com confirmação remota. Nenhum patch, novo ciclo, merge, PR, release, tag ou CI manual iniciado por este revisor.

```mikoshi-result-v1
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1101/r1-explicit-rate-kind.md
    id: 1101
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1101/r1-explicit-rate-kind.md
      id: 1101
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1102/r1-nominal-monthly.md
      id: 1102
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1103/r1-effective-monthly.md
      id: 1103
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1104/r1-annual-equivalents.md
      id: 1104
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1105/r1-invalid-rate-input.md
      id: 1105
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1106/r1-unrounded-consumer-rate.md
      id: 1106
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1201/r1-loan-domain.md
      id: 1201
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1202/r1-price-ledger.md
      id: 1202
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1203/r1-sac-ledger.md
      id: 1203
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1204/r1-money-invariants.md
      id: 1204
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1205/r1-zero-and-single-period.md
      id: 1205
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1206/r1-cent-precision-errors.md
      id: 1206
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1207/r1-comparable-results.md
      id: 1207
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1211/r1-localized-input.md
      id: 1211
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1212/r1-rate-presentation.md
      id: 1212
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1213/r1-comparison-presentation.md
      id: 1213
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1214/r1-ui-state-recovery.md
      id: 1214
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1214'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1215/r1-keyboard-navigation.md
    id: 1215
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1215/r1-keyboard-navigation.md
      id: 1215
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: demonstration
    evidence: '#req-1215'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1216/r1-resize-access.md
    id: 1216
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1216/r1-resize-access.md
      id: 1216
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: demonstration
    evidence: '#req-1216'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1217/r1-model-help.md
    id: 1217
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1217/r1-model-help.md
      id: 1217
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: inspection
    evidence: '#req-1217'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1221/r1-build-contract.md
    id: 1221
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1221/r1-build-contract.md
      id: 1221
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1221'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1225/r1-runtime-packages.md
    id: 1225
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1225/r1-runtime-packages.md
      id: 1225
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1225'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1226/r2-wsl-linux-and-windows-smoke.md
    id: 1226
    revision: 2
  implementation:
    root: /home/paulo/ceseb
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1226/r2-wsl-linux-and-windows-smoke.md
      id: 1226
      revision: 2
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: demonstration
    evidence: '#req-1226'
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1227/r1-technical-documentation.md
    id: 1227
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1227/r1-technical-documentation.md
      id: 1227
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1228/r1-distribution-notices.md
      id: 1228
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: inspection
    evidence: '#req-1228'
- kind: spec
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/specs/1008/r2-annual-rate-conversion.md
    id: 1008
    revision: 2
  implementation:
    root: /home/paulo/ceseb
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1101'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1102/r1-nominal-monthly.md
      id: 1102
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1102'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1103/r1-effective-monthly.md
      id: 1103
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1103'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1104/r1-annual-equivalents.md
      id: 1104
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1104'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1105/r1-invalid-rate-input.md
      id: 1105
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1105'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1106/r1-unrounded-consumer-rate.md
      id: 1106
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1201'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1202/r1-price-ledger.md
      id: 1202
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1202'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1203/r1-sac-ledger.md
      id: 1203
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1203'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1204/r1-money-invariants.md
      id: 1204
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1204'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1205/r1-zero-and-single-period.md
      id: 1205
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1205'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1206/r1-cent-precision-errors.md
      id: 1206
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1206'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1207/r1-comparable-results.md
      id: 1207
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1211'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1212/r1-rate-presentation.md
      id: 1212
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1212'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1213/r1-comparison-presentation.md
      id: 1213
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1213'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1214/r1-ui-state-recovery.md
      id: 1214
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1214'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1215/r1-keyboard-navigation.md
      id: 1215
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: demonstration
    evidence: '#req-1215'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1216/r1-resize-access.md
      id: 1216
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: demonstration
    evidence: '#req-1216'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1217/r1-model-help.md
      id: 1217
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: inspection
    evidence: '#req-1217'
- kind: spec
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/specs/1014/r3-wsl-validation-delivery.md
    id: 1014
    revision: 3
  implementation:
    root: /home/paulo/ceseb
    commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
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
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1221/r1-build-contract.md
      id: 1221
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1221'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1225/r1-runtime-packages.md
      id: 1225
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: test
    evidence: '#req-1225'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1226/r2-wsl-linux-and-windows-smoke.md
      id: 1226
      revision: 2
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: demonstration
    evidence: '#req-1226'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1227/r1-technical-documentation.md
      id: 1227
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: inspection
    evidence: '#req-1227'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1228/r1-distribution-notices.md
      id: 1228
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 3f4dc69ec84230b4035572fc62af3d13db451d2a
    result: pass
    method: inspection
    evidence: '#req-1228'
```
