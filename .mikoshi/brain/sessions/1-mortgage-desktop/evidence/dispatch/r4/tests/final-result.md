---
id: 2412
revision: 1
type: document
tags: [mortgage, dispatch, tests, final-result]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Execução final própria de 2005 no produto 3f4dc69, com regressões, pacotes reais e demonstrações 100/200 nas duas plataformas.
use_when:
- Receber os resultados finais de2005 antes da revisão independente e da aplicação de status.
---
# Resultado final F3/F4

## Identidade, cortes e autoridade

ROOT `/home/paulo/ceseb`; sessão `1-mortgage-desktop`; flow/head `design-project-1/test-planning`; executor `/root/f3_f4_test_executor`, mesma tarefa interrompida/inacabada após [BASE2411](base-result.md), memória de entrada r13. A autoria Astra e execução Sol6.1 seguem o dispatch escopado [1041](../../../../documents/1041/r1-f3-f4-correction-authority.md), com liberação concreta [1042](../../../../documents/1042/r1-f3-f4-concrete-procedure-release.md). Papel devr15 foi lido manualmente; native_id e carregamento nativo do papel não observáveis. Standingpush [1040](../../../../documents/1040/r1-alternative-validation-and-branch-push.md) pertence ao root/syncer. Nenhum remoto foi escrito por este executor.

Plano fonte [2005r1](../../../../plans/2005/r1-f3-f4-regressions.md), corpo publicado preservado. BASE dos assets `b5bb61c7a9a73f3a9174044621a7497dc274d0f3`; TEST_HEAD `98af104b0f38160aaf04ee2915f4d60e949d13aa`. O range de cobertura continua **BASE..TEST_HEAD**, exclusivamente quatro paths de testes. O alvo funcional final é separadamente **PRODUCT_HEAD `3f4dc69ec84230b4035572fc62af3d13db451d2a`**. O delta TEST_HEAD..PRODUCT_HEAD contém somente os dois modifies de produto autorizados. Não houve alteração de teste, oráculo ou fonte durante esta fase final.

O root liberou Linux/static primeiro e depois Windows, com exclusividade de GUI por plataforma. Foram respeitados os holds. A liberação final nomeou os pacotes imutáveis e seus hashes. Não se executou o driver histórico sobre outputs antigos. Todos os comandos completos, ambientes e exits próprios ficam em `ROOT/out/test-evidence/dispatch-r4/final/`; os relatórios do produtor em evidence/dispatch/r4/implementation foram consultados como evidência atribuída, sem substituir estas execuções próprias.

## T1216

Exportações próprias de PRODUCT_HEAD: Linux `/work/r4/tests/final/source` no contêiner `ceseb-validation-r3-ubuntu24`, build irmão `/work/r4/tests/final/build`; Windows `C:/Users/paulo/AppData/Local/CESEB/r4/tests/final/source`, build irmão `build`. As233 fontes rastreadas permaneceram hash-identical à exportação de PRODUCT_HEAD após os ensaios; source-integrity.json. Nenhuma dependência foi adquirida ou instalada globalmente.

Ubuntu24.04.5/GCC13.3, CMake3.28.3/Ninja1.11.1: reutilização read-only dos kits privados do produtor em `/work/r4/implementation/{deps,sdk}`, Boost `/boost` e GTest `/work/gtest-install`. Configure/build próprios exit0. Inventários próprios listam20 casos financeiros e cinco slotsGUI. CTest offscreen **27/27** e XCB/Xvfb **27/27**, falhas/skips0; core-only/check_core_independence **21/21**, exit0. O core foi testado com descobertaQt desligada; a presença física de SDK no contêiner não é negada. Novo slot isolado nativo/XCB escala1 e2 e offscreen escala2 exit0; escala1 offscreen também integra a suíte completa. Arquivos own-suite-counts.json, linux-execution.json, XML/logs linux-ctest, linux-core e pixels-* registram os resultados reais.

Windows11 Pro build26200, Community2022/MSVC19.44.35228, Qt6.12.0, GTest1.17 e Boost1.86 privados existentes: configure/build próprios exit0; CTest offscreen **27/27** e windows **27/27**, falhas/skips0; core-only **21/21**, exit0. Novo slot isolado offscreen e windows nas escalas1/2: quatro processos exit0. Cada XMLQtTest tem init, um slot e cleanup, não três novos casos. Comandos/exits completos em windows-build/windows-execution.json, wrappers próprios e windows-own-suite-counts.json. PATH do SDK existe somente nos processos de teste, separado do processo empacotado.

O instrumento de pixels e os20 oráculos financeiros/quatro slotsGUI antigos são os mesmos de BASE. Lá a paleta clara tinha glifos e a escura tinha zero nos quatro controles; aqui todos os pares claro/escuro têm diferenças positivas nos quatro controles, nos backends/escalas executados. PNGs preenchido/vazio e XML preservados. Os guards de foco, texto não vazio, Price599/SAC600, geometria/DPR e restauração continuam ativos. Isso prova presença de glifos, não um limiar de contraste; a leitura seguinte é evidência distinta.

### Uso real Linux

DEB final foi instalado pelo próprio executor via dpkg no contêiner runtimeUbuntu24.04.5 `ceseb-validation-r3-runtime24`, preservando a instalação recebida em `/r4-tests-final/previous-installed` e todos os outputs anteriores. App `/opt/ceseb/bin/ceseb`, PATH `/usr/bin:/bin`, sem LD_LIBRARY_PATH/caminhosQt de desenvolvimento; ldd e maps observados usam Qt/ICU privados do pacote e bibliotecas de sistema. Ambiente sem rotaIPv4, somente interface lo. DisplayX11/Openbox/Xvfb privado2300x1900; isto é o aplicativo real renderizado em desktop virtual, não um hostUbuntu físico ou backend offscreen.

Drivers próprios `/r4-tests-final/ui-driver`, logs e cópia integral de evidência em final/linux-ui-evidence. Escalas de processo1 e2 com cliente800x600 lógico, capturas800x600/1600x1200. TecladoTab/reverso, nominal1000/12/3, efetiva, invalidação, principal inválido e recuperação, limpar e Escape foram exercitados; os dois roteiros sincronizados terminaram exit0, app_exit0 e nenhuma janela própria restante. Cenário1000/0/600 mostra Price599/SAC600 e aviso de quitação completo.

Medição em linux-layout-coverage.json identifica47 alvos concretos (campos, botões, rótulos e valores; exclui mensagem vazia), com47/47 retângulos inteiros dentro do cliente capturado nas duas escalas. AT-SPI auxilia posição/foco, não substitui pixels. Li diretamente cabeçalho, seleção e quatro campos, taxas, prazo, Price, SAC, aviso599/600, diferença e rodapé nas capturas de topo/rolagem. Não observei rolagem horizontal do formulário nem sobreposição impeditiva. Ajuda foi aberta e realmente rolada com wheel até limites/exclusões, com versão/revisão PRODUCT_HEAD legível; imagens help-scroll nas duas escalas. Popups foram capturados por cópia real da telaX11 recortada ao cliente próprio, com navegaçãoDown para opção efetiva. A primeira capturaXGetImage somente da janela, que mostrava região preta sob o popup, foi preservada e não usada como prova de leitura do overlay. Nenhuma imagem foi pós-editada.

### Uso real Windows

ZIP final extraído independentemente em `C:/Users/paulo/AppData/Local/CESEB/r4/tests/final/extracted`; executável dessa árvore, PATH Windows/System32+Windows, variáveis de SDK removidas. runtime-modules-theme.json identifica EXE/PID, módulosQt/qwindows/CRT app-local e Windows11; AppsUseLightTheme0/SystemUsesLightTheme0 foram observados read-only, sem mudar preferências. Não alego Windows sem SDK instalado; o processo foi usado sem caminhos de desenvolvimento.

Driver nativo guardado por PID/EXE/foreground/sessão desbloqueada. TecladoTab e ShiftTab foram conferidos exatamente; exemplo nominal/efetiva, erro/recuperação, limpar, ajuda e fechamento foram usados. Cliente800x600 lógico em100/200; DPI96 e escala de processo2 registrada. Imagens originais CopyFromScreen real, com windowRect/visibleRect/timestamp. Em200%, moveu-se somente a janela própria entre Y0/-220 para mostrar regiões fora do monitor1920x1080. A medição windows-layout-coverage.json exige retângulo inteiro dentro da interseção da captura real, viewport e WorkingArea1920x1032, excluindo taskbar: **47/47 alvos em cada escala**. Uma rolagem suplementar menor mostrou integralmente a parcela ordináriaR$1,67 que as páginas grossas anteriores pulavam. UIA fornece geometria e oráculos textuais, acompanhados por leitura visual de inputs/cartões/aviso/cabeçalho/prazo/diferença/rodapé. Não se aceitou PrintWindow fora da tela como evidência.

A captura extra solicitada pelo root `windows-ui/01-nominal-client-only.png` foi produzida diretamente com GetClientRect+ClientToScreen∩WorkingArea e CopyFromScreen,800x600, sem sombra/taskbar/desktop; metadata companion. Ajuda mostra versão/revisãoP e link local; a ativação abriu a pasta própria licenses, observada via Shell somente pelo target exato. Capturas suplementares de ajuda com wheel real e duas posições horizontais conservam o overlay externo/pet sem interferir nele e permitem conferir o conteúdo. Nenhum aplicativo alheio foi fechado ou recebeu entrada.

## T1225

Hash conferido antes de extrair cada pacote:

- ZIP `/mnt/c/Users/paulo/AppData/Local/CESEB/r4/implementation/packages-final/ceseb-0.1.0-windows-x86_64.zip`: **f5071e93d3c99afd4b5fae395322897c8d074f928f66952366eb0b05ad762d20**,84400666bytes.
- DEB `ROOT/out/dispatch-r4/implementation/linux/packages-qualified/ceseb_0.1.0_amd64.deb`: **8dd414362fc06456a7aadaf44acb5a80264514497433d0ba24f240d129628336**,97400034bytes.

Extrações novas final/windows-extracted e final/linux-extracted, sem symlinks para checkout. O mesmo check_windows_component_notices.cmake de BASE, sem mudança, agora exit0 sobre o ZIP real: executável, QtCore/Gui/Widgets, pluginqwindows, LICENSE/THIRD_PARTY_NOTICES e dez materiais declarados não vazios presentes; nenhum dxcompiler.dll/dxil.dll em qualquer pasta. A falha anterior por ambas DLLs permanece no2411. Comando igual aoBASE com CESEB_PACKAGE_ROOT final, registrado em windows-component-check.log. Scripts check_deb_desktop e check_distribution_links nos dois pacotes finais também exit0, system-checks.json. Aberturas reais de ambos entregáveis estão acima.

## T1228

Auditoria própria independent-package-audit.json confere **188 arquivos/187 hashes manifestos noZIP**, **184 arquivos/182 hashes noDEB**, todos os hashes declarados e SourceRevisionP;21 registros históricos entregues em cada pacote conferem byte-a-byte com as fontes de evidência do produtor, sem atribuir seus testes antigos ao alvoP. Inventário efetivo de DLLs/plugins/CRT e bibliotecas Linux preservado no JSON. InspectorPE próprio, adaptado e executado sobre a própria extração: **22 imagensAMD64**, imports e delay-imports sem dependência obrigatória irresolvida, inclusive nenhuma DXC/DXIL residual. qualified-windows-pe-closure.json próprio registra resoluções locais/System32/API-set. Auditorias do produtor foram lidas como confronto atribuído.

Todos os materiais licenses doZIP que existiam no pacote antigo foram comparados e permaneceram byte-identical, incluindo originaisBoost/GTest/Qt, SBOM/configurações/fonte e termosMSVC; nenhuma licença nova foi inventada para DXC. Os oito CRT Release coincidem porhash com os arquivosCommunity previamente qualificados e assinaturasValid atribuídas ao levantamento do produtor; crt-materials-comparison.json. THIRD_PARTY_NOTICES entregue foi lido, MIT restrita aos originais, QtBase6.12/LGPL/GPL e terceiros preservados. FonteQt025bdad incluída, sem modificações declaradas; arquivos/configurações/SBOM reais disponíveis. Hash da fonteQt noZIP2834e4b0e81214b98778ab5fb2adb2fff166d359a1c0347f3c4ba0cde50be369 e noDEB25a289843e3e5f60baeca66c32522ebce9051ef8119dba268d15e9811b4f0c44 correspondem aos arquivos de cada kit/pacote, não se inferiu identidade binária entre plataformas. O inventário não afirma distribuirDXC. SubstituibilidadeQt é inspeção de ligação dinâmica/configuração existente; **nenhum ensaioABI nem certificação jurídica** é alegado.

## Preparação, cobertura e retorno

Tentativas preservadas, sem transformar erro de preparo em defeito de produto ou apagar evidência:

- BASE35: sobrecarga void de setStyle corrigida somente no preparo em98, com logs/commits preservados; nenhum delta final nos testes.
- LinuxUI inicial: observador consultou About imediatamente apósSpace e recebeu[]; reobservação read-only confirmou diálogo próprio. Poll limitado porPID/EXE/title, sem repetirSpace, completou o mesmo procedimento. Primeira tentativa e post-error-windows.json retidos.
- Linuxpopup: janela de origem ficou ocluída noXGetImage; foi usada captura real da tela na região própria para demonstrar o popup, preservando a primeira.
- Windowspopup: UIASetFocus de controle fora do viewport não deslocou foco; o Escape posterior fechou a janela. Recuperação operacional porTab real e foco assertado, sem mudar obrigação.
- Windowsforeground: guardexpected5252/got5584Explorer interrompeu antes de entrada; identificação read-only e reativação explícita da própria instância, sem entrada noExplorer.
- Windowsclose200: helper ativou a janela principal antes deEscape e ela fechou; a consulta redundante Get-Process posterior falhou porque PID27832 já não existia. scale200-close-observation.json confirma ausência apósEscape guardado; não se mascara essa exceção do driver como exit0 do script original. Os roteiros suplementares fecham suas próprias instâncias e confirmam exitedtrue.

`mikoshi plan check-commits` fresco para BASE..TEST_HEAD: quatro operações cobertas, unexpected_paths e dirty_planned_paths vazios. Os quatro assets e as233 fontes exportadas permanecem iguais às revisões identificadas. Outputs próprios, memória própria e este report são os únicos escritos adicionais desta fase; produto/README/CI/sharedstate/memórias alheias/reports históricos preservados. Corpo2005 permanece publicado sem edição nem promoção de status por este executor.

Procedimento de2005 **complete**; T1216/T1225/T1228 **complete** para os métodos declarados. Isto é conclusão de execução do plano, não verdict independente de requisito, mudança de status, aprovação humana, merge ou release. Root recebe relatório e evidência para Synapses e aplicação dos resultados. Não há ensaioABI ou alegação de SDK ausente; o ambienteLinuxUI éX11 privado virtualizado e o Windows éhostreal observado. Não houve novo pin/componente global, remoto ou aquisição.

Leitura adicional direta nesta continuação: memória própriar13; liberaçãoP/pacotes recebida do root; scripts/logs/JSON atuais do produtor de build/package/CRT/PE/inventário; notices entregues; drivers reais e suas áreas modificadas operacionalmente; fontes/fixtures congeladas2005 reaproveitadas da leituraBASE. Context7/Serena continuam ausentes da descoberta nativa já registrada; nenhuma chamada fictícia ou native-role readback é alegado.

```mikoshi-result-v1
- kind: plan
  artifact:
    path: ../../../../plans/2005/r1-f3-f4-regressions.md
    id: 2005
    revision: 1
  range:
    base: b5bb61c7a9a73f3a9174044621a7497dc274d0f3
    head: 98af104b0f38160aaf04ee2915f4d60e949d13aa
  procedure: complete
  tasks:
  - id: T1216
    result: complete
    evidence: '#t1216'
  - id: T1225
    result: complete
    evidence: '#t1225'
  - id: T1228
    result: complete
    evidence: '#t1228'
```
