---
id: 2281
revision: 1
type: document
tags: [mortgage, synapses, independent-review, validation]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: 'Revisão dos seis requisitos com uso real do app: 1217 e 1221 pass, 1225 fail por avisos DXC ausentes e três protocolos Windows interrompidos pela sessão bloqueada.'
use_when:
- Aplicar os novos resultados sustentados no snapshot 57 e recuperar os cenários Linux executados e os passos Windows que precisam de sessão desbloqueada.
---
# Revisão independente da validação real

## Resultado

No snapshot **57ef26901d4381ead16c7347483d588ad9d92efe**, os novos julgamentos são **1217 r1 pass, 1221 r1 pass e 1225 r1 fail**. Os cenários Linux de teclado, layout, nominal/efetiva, erro/correção, limpeza, ajuda e fechamento foram executados no aplicativo do DEB. Os protocolos Windows de **1215, 1216 e 1226 r2 foram interrompidos antes do primeiro input**, porque a própria sessão Windows está bloqueada. Não há falha observada do app nesses três requisitos e não há declaração de pass para o que o bloqueio impediu executar.

O fail de 1225 agora tem **evidência atual do 57**, pelo AC1: o ZIP contém dxcompiler.dll/dxil.dll sem materiais específicos de avisos/licença recuperáveis. É o mesmo finding F3 já confirmado em 1228, agora aplicado ao critério de composição de 1225. O fato de o aplicativo abrir não torna verdadeiro um critério de pacote que inclui os avisos. Não é uma conclusão jurídica geral.

Somados aos resultados próprios anteriores de [2241](../r2/dev-review.md), no MESMO snapshot e com identidades conferidas, o inventário fica em **20 pass, dois fail (1225 e 1228) e três protocolos Windows interrompidos (1215, 1216, 1226)**. Este documento não reabre os outros 19 requisitos nem transforma as execuções autorais em testes próprios novos.

## Independência, corte e fontes

Instância fresca `/root/independent_validation_review_r3`, mesmo head lógico `design-project-1/independent-review`, mesma [memória própria](../../../session_memory/design/independent-review.yaml), entrada r6. Sou o reviewer independente, separado dos autores de 2271/2272/2273. ROOT/MAIN/workspace de implementação `/home/paulo/ceseb`; sessão `1-mortgage-desktop`; branch `codex/mortgage-desktop`. Provider codex, native_id desconhecido; um handle não demonstra carregamento nativo de role/plugin.

Autoridade atual [1040](../../../documents/1040/r1-alternative-validation-and-branch-push.md); rodada [2280](round.md). Recebi todos os retornos necessários: [2271 Windows parcial por bloqueio](../../dispatch/r3/windows-validation.md), [2272 app Linux final](../../dispatch/r3/linux-validation.md), [2273 Ubuntu 24/core final](../../dispatch/r3/ubuntu24-core.md). O root confirmou o retorno completo desses três autores antes deste fechamento. O [push já confirmado](../../dispatch/r3/push-result.json) pertence ao root; este reviewer não executou Git remoto.

[Identidade conferida](dev/source-identity.json): **55/55 paths de produto/testes iguais aos hashes da minha própria revisão 2241**, HEAD57 e zero dirty selecionado. As seis revisões de requisito também coincidem byte a byte com as que este mesmo head leu integralmente na revisão anterior; reli obrigação, alvo, ACs e limites exatos. Preservei as specs/planos e todos os resultados históricos. Os oito tasks de 2004 e seu filemap de dois creates continuam os publicados; a execução atual muda os meios de demonstração sob 1040, sem editar esse corpo ou o produto.

A suíte própria anterior no mesmo 57 — Linux e Windows, 26/26 por backend e 21/21 core — é **reutilizada com atribuição**, por identidade comprovada, sem nova alegação de execução. O recorte novo é a inspeção dos ensaios reais de usuário e da execução isolada Ubuntu 24. Não repeti uma suíte inteira sem alteração relevante que o justificasse. Não emito implemented para os planos, cujo procedimento completo continua sendo responsabilidade do autor.

## Observações conferidas

[Inspeção própria dos registros recebidos](dev/received-evidence-inspection.json) confrontou os nomes/valores externos AT-SPI com os oráculos e as capturas reais, não com dados sintéticos. O driver XTest foi lido: ele inicia `/opt/ceseb/bin/ceseb`, verifica PID/UID/EXE/janela, envia teclas e roda a janela XCB instalada; não injeta resultados no core. O ambiente é Ubuntu **24.04.5** em userspace de contêiner com kernel WSL compartilhado, Xvfb/Openbox privado, display :95; não é uma máquina com kernel Ubuntu separado, QtTest ou backend Qt offscreen. A exceção WSL de 1226 não foi transferida para outros oráculos por inferência. Os testes de software no desktop privado são relatados nas condições reais; não extrapolam para toda configuração física ou tecnologia assistiva.

| Entrada observada nas duas escalas Linux | Valores conferidos |
|---|---|
| R$ 1.000,00; nominal anual 12%; 3 meses | Taxas 1,000000% / 12,000000% / 12,682503%; Price 340,02 / 340,03 / total 1.020,07 / juros 20,07; SAC 343,34 / 336,66 / total 1.020,00 / juros 20,00; diferença +0,07. |
| R$ 1.000,00; efetiva anual 12%; 3 meses | Taxas 0,948879% / 11,386552% / 12,000000%; Price 339,68 / 339,68 / total 1.019,04 / juros 19,04; SAC 342,83 / 336,49 / total 1.018,98 / juros 18,98; diferença +0,06. |
| R$ 1.000,00; 0%; 600 meses | Price ordinária 1,67, última 1,34, 599 pagamentos; SAC primeira 1,67, última 1,66, 600 pagamentos; ambos total 1.000,00 e juros zero. Aviso completo de quitação em 599 de 600 meses alcançado por rolagem. |

Invalidação e limpeza removeram os valores anteriores. Entrada zero gerou erro e correção recuperou o resultado nominal. Return nos campos calculou; Escape encerrou com exit0. Tab e Shift+Tab percorreram a ordem declarada; o item selecionado interno do combo também expõe flag AT-SPI focused, por isso o foco de controle foi identificado pelo papel text/combo box/push button e confrontado com capturas, sem confundir a seleção interna com outro destino de foco.

As capturas de 100% são **800×600 pixels**, e as de 200%, **1600×1200**, para a janela solicitada de 800×600 lógicos. O actor registrou 47/47 textos/controles integralmente alcançados na união das capturas de rolagem/foco de cada escala. Inspecionei diretamente formulário nominal, totais nominal/efetiva, aviso completo e SAC a 200%, e o gerenciador de licenças. Não identifiquei sobreposição impeditiva nas imagens inspecionadas. Isso não inventa as duas combinações Windows ainda não executadas.

## Req 1217

**Resultado: pass — inspection.** Todos os quatro ACs foram verificados no app distribuído, offline. O texto real do QTextBrowser, extraído pela árvore acessível, contém nominal/efetiva, Price/SAC, primeiro pagamento após um mês e postecipados; centavos/half-up/ajuste final e pagamentos efetivos; seguros/tarifas/impostos/indexadores excluídos e total não CET. A janela mostra **CESEB 0.1.0 e revisão 57**.

O link foi ativado dentro da própria janela. A evidência final mostra **PCManFM PID 5429**, título `licenses`, comando `/usr/bin/pcmanfm /opt/ceseb/bin/../licenses` e endereço visual **/opt/ceseb/licenses**, com oito itens. [Resultado do handler](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/license-handler/result.json) e [captura inspecionada](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/license-handler/external-licenses-folder.png). Só `lo` e nenhuma rota IPv4 estavam presentes. A dependência mínima de desktop `file`, inicialmente ausente, foi instalada somente no contêiner; a bridge foi desconectada novamente antes do clique final. Os erros anteriores de coordenada/fixture foram preservados e não confundidos com comportamento do produto.

1228 verifica a composição de avisos; a falha Windows de DXC não apaga o sucesso de abrir os arquivos locais por este recurso Linux. O AC4 exige acesso local offline e foi observado, não deduzido apenas pela existência de uma pasta.

## Req 1221

**Resultado: pass — test.** A fronteira pública `include/ceseb/finance.hpp` usa tipos C++/Boost, sem Qt; `ceseb_core` liga somente `ceseb_boost_headers`, e a descoberta Qt está dentro do bloco CESEB_BUILD_GUI. Li CMakeLists, Dependencies.cmake, API pública e o script original de independência. A composição é a mesma do 57 já revisado.

- **Ubuntu 24/GCC 13.3:** o script original configurou/compilou/consumiu o núcleo sem Qt fisicamente disponível antes desse teste; XML **21/21**, zero failures/errors/skips; `ldd` sem Qt. O export de 70 arquivos permaneceu igual ao snapshot. Dados em 2273 e `out/validation-r3/ubuntu24/core-result.json`, logs, XML e enumeração antes de GUI.
- **Windows 11/MSVC 2022 Community:** o build core-only existente do mesmo 57 tem CESEB_BUILD_GUI=OFF, Qt6 discovery disabled, compiler cl da Community e revisão 57 no CMakeCache. O consumidor foi executado sozinho em uma pasta, PATH apenas Windows/System32: **20 casos de conversão/amortização em 13 suites, exit0**. PE imports e 15 amostras de módulos em execução não contêm Qt; há apenas EXE e DLLs Windows/CRT. O wrapper posterior de amostragem teve ExitCode null, e esse null não foi convertido em zero; o zero é da execução direta anterior.

O requisito é a independência da compilação/consumo do **componente**, não a remoção de qualquer SDK instalado em outro diretório do computador. O core Windows não precisa instalar, ligar ou inicializar Qt; sua composição, execução e módulos mostram essa condição. A antiga exigência de provar desinstalação global do SDK Windows excedia a obrigação de 1221. Esta interpretação não muda seu corpo ou oráculo. Os dois SOs usam a mesma revisão de fonte, sem alteração manual entre eles.

## Req 1225

**Resultado: fail — inspection; F3 existente, AC1.** [Identidade atual do ZIP](dev/package-current-identity.json) confirma SHA256 **c71634da99c2efe7774db55e011883b2c12f001db7a972404093f7c05968da4b**, exatamente o pacote auditado pelo mesmo head em 2241. `bin/dxcompiler.dll` e `bin/dxil.dll` continuam presentes; nesta conferência, 38 arquivos textuais com extensões txt/md/html/json/spdx sob licenses foram examinados e não contêm menções específicas. Isso apoia o inventário anterior mais amplo e não é uma nova auditoria jurídica.

A ausência específica de materiais foi confirmada na [revisão própria anterior F3](../r2/dev-review.md#f3--materiais-de-licença-e-avisos-dxc-ausentes), incluindo a origem SDK/versões e a flag separada de DXC no windeployqt. A causa no mesmo código continua em `cmake/WindowsDeploy.cmake:14`: a flag D3D não exclui automaticamente DXC. Nenhuma correção foi feita. O AC1 exige os avisos junto da composição entregue; não está satisfeito. Uma violação observada basta para fail, sem exigir declarar pass nos demais ACs.

O conteúdo Linux foi efetivamente instalado pelo APT no Ubuntu 24 limpo, sem compilador/headers/SDK. Bibliotecas privadas e launcher foram conferidos; duas chamadas reais `Gio.DesktopAppInfo.launch` abriram `/opt/ceseb/bin/ceseb` pelo desktop entry publicado, com padrões ao reabrir. Esses sucessos são preservados. O ZIP também abriu e carregou Qt privado no Windows, mas isso não corrige a falta dos avisos e não prova uma máquina Windows globalmente limpa. O fail de ce5 por launcher é histórico; este resultado fail no 57 tem outra evidência concreta, o AC1/F3 do ZIP.

## Req 1215

**Execução Linux concluída; protocolo Windows interrompido por bloqueio da sessão.** A sequência Linux registrou principal→taxa→tipo→prazo→Calcular→Limpar→Sobre e inversa, Return, erro/correção, limpeza, ajuda e Escape por teclado, rótulos e foco observáveis. Esses resultados têm capturas em 100% e 200%. Nenhuma tecla foi enviada no Windows porque WTS confirmou LOCK. Não há resultado global pass/fail para esta obrigação de duas plataformas nesta rodada.

## Req 1216

**Duas combinações Linux executadas com sucesso; duas combinações Windows não iniciadas.** O cenário 1000/0/600, os textos/controles 47/47, a reorganização vertical, a ausência de rolagem horizontal impeditiva e o aviso completo foram observados em 800×600 lógicos nas escalas 1/2. O bloqueio Windows impediu os dois casos de interação/captura. Não extrapolei de Linux, árvore acessível estática ou suite QtTest para Windows.

## Req 1226

**Cenários Linux executados com sucesso; protocolo financeiro Windows interrompido antes do primeiro input.** O app Linux do DEB executou nominal/efetiva com todos os valores acima, transições, erro/correção, limpeza, teclado, redimensionamento e fechamento; SO, pacote, SHA, revisão e capturas foram preservados. Windows abriu o EXE e tem controles/módulos observáveis, mas não recebeu a entrada nominal/efetiva e não produziu a sequência visual requerida. Por isso não é declarado pass a partir de startup ou presença de SDK.

[2271](../../dispatch/r3/windows-validation.md) identifica o motivo concreto: app 24464, PowerShell 22344 e LockApp 25640 pertencem à **mesma SessionId 1**; WTSQuerySessionInformationW/WTSSessionInfoEx retornou **SessionFlags LOCK=0**. A distinção LOCK 0/UNLOCK 1 foi lida no WtsApi32.h instalado. Essa é uma condição da sessão, separada da antiga rejeição de URI do Computer Use. O usuário já recebeu o pedido de desbloquear; não houve tentativa de contornar lock, credenciais ou segurança.

## Trace, agregados e limites

Rotas verificadas: 1215/V1215 e 1216/V1216→`src/ui/main_window.cpp` e driver/capturas; 1217/V1217→`resources/model-help.html`, MainWindow::show_about e handler real; 1221/V1221→API/ceseb_core/script original e consumidores nos dois SOs; 1225/D1225→Packaging/WindowsDeploy, scripts de composição e pacotes; 1226 r2/V1226→aplicação distribuída, fonte 57 e sequências por SO. Os scripts novos de 2004 e o range ce5..4eb não mudaram; produto permanece 4eb..57. Não existe modificação nova de arquivo do filemap a cobrir nesta validação somente operacional.

As specs **1013 r2 e 1014 r3 continuam partial implemented**, com seus conjuntos completos explicitamente declarados abaixo. Os resultados de 1211–1214,1227 e1228 nas linhas desses agregados são reutilizados da minha própria 2241, no mesmo 57 com 55/55 fontes conferidas. São reafirmações atribuídas; não novos testes ou transições individuais. Sem os resultados Windows de 1215/16/1226 e com 1225/1228 fail, nenhuma das duas specs pode receber implemented.

A busca nativa scoped retornou partial com identity_ambiguous/index_incompatible; o [retorno](dev/retrieval.json) foi preservado, sem rebuild por este reviewer. Context7/Serena não estão expostos no catálogo deste host; nenhuma chamada ou instalação foi alegada. Nenhuma pesquisa externa foi necessária para reler o mesmo código e julgar os registros recebidos. A source/reading coverage está em [manifesto](dev/source-read-manifest.json). A comparação de identidade e a inspeção dos JSON/capturas são próprias; as execuções de 2271/2272/2273 são atribuídas aos autores. Não executei input Windows, novas suítes de produto, mudanças de status, source patches, Git remoto, promoção ou alterações de ambiente.

## Transporte e handoff

As declarações usam o snapshot Git exato, sem alterar corpo de requisito/spec. O validator nativo `mikoshi_core.status.validate` é somente leitura; a CLI pública deste runtime oferece status set, não um comando status validate. A conferência do transporte e o check de schema/links ficam em [declaration-validation.json](dev/declaration-validation.json) e [report-check.json](dev/report-check.json). Validação mecânica não é novo julgamento semântico.

Próximo responsável: analyst recebe este relatório completo e os três retornos autorais. Deve aplicar somente 1217 pass, 1221 pass, 1225 fail e os dois agregados parciais qualificados. Deve preservar 1215/1216/1226 sem novo pass/fail e seus motivos concretos de interrupção. O syncer conserva o push explicitamente solicitado e seu readback; a antiga limitação local não é retomada. A sessão permanece aberta para retomar os três protocolos Windows quando houver desktop desbloqueado, sem inventar execução por silêncio.

## Declaração mecânica exata

```mikoshi-result-v1
- kind: requirement
  artifact:
    path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1217/r1-model-help.md
    id: 1217
    revision: 1
  implementation:
    root: /home/paulo/ceseb
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1217/r1-model-help.md
      id: 1217
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
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
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1221/r1-build-contract.md
      id: 1221
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
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
    commit: 57ef26901d4381ead16c7347483d588ad9d92efe
  results:
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1225/r1-runtime-packages.md
      id: 1225
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: fail
    method: inspection
    evidence: '#req-1225'
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
    evidence: ../r2/dev-review.md#req-1211
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1212/r1-rate-presentation.md
      id: 1212
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: ../r2/dev-review.md#req-1212
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1213/r1-comparison-presentation.md
      id: 1213
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: ../r2/dev-review.md#req-1213
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1214/r1-ui-state-recovery.md
      id: 1214
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: ../r2/dev-review.md#req-1214
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1217/r1-model-help.md
      id: 1217
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
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
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1221/r1-build-contract.md
      id: 1221
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: test
    evidence: '#req-1221'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1225/r1-runtime-packages.md
      id: 1225
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: fail
    method: inspection
    evidence: '#req-1225'
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1227/r1-technical-documentation.md
      id: 1227
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: pass
    method: inspection
    evidence: ../r2/dev-review.md#req-1227
  - requirement:
      path: /home/paulo/ceseb/.mikoshi/brain/sessions/1-mortgage-desktop/requirements/1228/r1-distribution-notices.md
      id: 1228
      revision: 1
    implementation:
      root: /home/paulo/ceseb
      commit: 57ef26901d4381ead16c7347483d588ad9d92efe
    result: fail
    method: inspection
    evidence: ../r2/dev-review.md#req-1228
```
