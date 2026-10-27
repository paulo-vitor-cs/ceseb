---
id: 2272
revision: 1
type: document
tags: [mortgage, validation, linux, desktop, keyboard, packaging]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Uso real do aplicativo distribuído em Ubuntu 24.04 isolado, com teclado, cenários financeiros, escalas 100 e 200, ajuda offline e abertura das licenças pelo gerenciador de arquivos.
use_when:
- Julgar os critérios Linux de 1215, 1216, 1217, 1225 e 1226 junto à evidência Windows e ao teste isolado do núcleo 1221.
---
# Aplicativo Linux usado e validado

## Resultado observado

Usei o **executável real do DEB**, instalado pelo APT em um ambiente Ubuntu 24.04.5 sem compilador, headers de desenvolvimento, CMake, Ninja, Boost/GoogleTest ou Qt SDK. Preenchi o formulário por teclado, calculei nominal e efetiva, provoquei um erro, corrigi, limpei, abri ajuda, redimensionei, percorri os resultados por rolagem e fechei por Escape. Os cenários executados concluíram sem falha do aplicativo. Os resultados financeiros exibidos coincidem com os valores normativos.

Também acionei o link de licenças **dentro do aplicativo**: ele abriu o PCManFM no endereço **/opt/ceseb/licenses**, com os oito arquivos/pastas locais visíveis. Essa execução ocorreu offline, com somente a interface lo e nenhuma rota IPv4. A abertura pelo lançador desktop publicado e a reabertura com valores padrão foram observadas separadamente.

Esta é execução autoral de validação. Não alterei status de requisito, corpos publicados, produto, testes do repositório, Git ou remoto; o julgamento independente pertence à revisão que recebe este report. O comportamento observado abaixo permite julgar cada critério, em vez de substituir os testes por uma ausência genérica de evidência.

## Autoridade, fonte e ambiente

[1040 r1](../../../documents/1040/r1-alternative-validation-and-branch-push.md) autoriza os meios alternativos solicitados pelo usuário. Procedimentos anteriores de [2004 r1](../../../plans/2004/r1-distribution-regression-and-validation.md) foram reutilizados com a autoridade atual de preparar ambientes privados reversíveis; nenhum corpo de plano foi reescrito. Mesma memória do head lógico design-project-1/test-planning, instância fresca /root/linux_app_validation_r3, ROOT /home/paulo/ceseb e sessão 1-mortgage-desktop. Leitura manual dos contratos não comprova carregamento nativo de role/plugin; native_id desconhecido.

- Fonte congelada: **57ef26901d4381ead16c7347483d588ad9d92efe**.
- DEB: **ceseb 0.1.0 amd64**, SHA256 **6827856d68ad39d35490a31dfdec90df9fdf63f8e45bc95dfd103b06fdceb4b4**.
- Runtime: contêiner próprio **ceseb-validation-r3-runtime24**, Ubuntu **24.04.5 LTS**, x86_64, kernel WSL compartilhado. É Ubuntu 24.04 em userspace isolado; não é uma máquina com kernel Ubuntu separado.
- Desktop de teste: Xvfb privado, display :95 com 2300×1900 pixels, Openbox, aplicação Qt XCB real, entrada XTest e capturas XGetImage. As árvores AT-SPI foram lidas externamente para identificar controles, foco, texto e limites. Não é QtTest nem backend Qt offscreen.
- Escalas por processo: QT_SCALE_FACTOR=1 e 2. Janela de 800×600 pixels lógicos, com capturas de **800×600** e **1600×1200** pixels, respectivamente. Nenhuma escala global foi alterada.
- PATH do app somente /usr/bin:/bin; nenhum LD_LIBRARY_PATH, QT_PLUGIN_PATH ou prefixo de SDK. Qt vem do pacote privado em /opt/ceseb.
- Rede: desconectada somente a bridge deste contêiner; host e outros contêineres não foram alterados. D-Bus, X11 e arquivos locais funcionaram no ambiente offline.

O [report 2273](ubuntu24-core.md) contém o bootstrap, preflight limpo, dependências resolvidas e a execução do núcleo em outro contêiner antes de instalar runtime gráfico. Fonte/export de 70 arquivos preservados. Esse retorno foi lido integralmente; não reatribuo seu teste como execução própria.

## Critérios efetivamente executados

| Requisito e critério | Observação Linux |
|---|---|
| [1215 r1](../../../requirements/1215/r1-keyboard-navigation.md), AC1 | Tab percorreu valor → taxa → tipo → prazo → Calcular → Limpar → Sobre → valor. Shift+Tab percorreu a ordem inversa. Captura e foco AT-SPI foram registrados em cada passo nas duas escalas. |
| 1215, AC2 | Return no campo prazo calculou a entrada nominal; Return no tipo calculou efetiva; Return no valor recuperou o erro. Escape fechou a janela, exit 0, sem janela própria restante. |
| 1215, AC3 | Rótulos e controles têm nomes externos observáveis, e os campos/botões exibem foco nas capturas. A associação dos quatro rótulos e os accessible names também foram confrontados com main_window.cpp do mesmo snapshot. O combo expõe o texto selecionado na árvore AT-SPI, com o rótulo visível Tipo de taxa. |
| 1215, AC4 | Preenchimento, cálculo, erro/correção, limpeza, acesso à ajuda e fechamento foram feitos por teclado, sem mouse. A ativação posterior do link externo de licença foi uma inspeção separada com clique no texto observado. |
| [1216 r1](../../../requirements/1216/r1-resize-access.md), AC1 | Executei 1.000,00 / 0% / 600 meses nas duas escalas. Todos os 47 textos/controles relevantes ficaram inteiramente dentro da janela em pelo menos uma captura da sequência de rolagem e foco. |
| 1216, AC2 | O formulário permaneceu utilizável e dentro da largura; não houve rolagem horizontal ou sobreposição impeditiva. Cartões foram reorganizados verticalmente em 800 pixels lógicos. |
| 1216, AC3 | Price mostrou 599 pagamentos, parcela ordinária R$ 1,67, última R$ 1,34 e aviso completo de quitação em 599 de 600 meses; SAC mostrou 600 pagamentos. Valores, aviso e rodapé foram alcançados por rolagem e inspecionados visualmente em 100% e 200%. |
| [1217 r1](../../../requirements/1217/r1-model-help.md), AC1–3 | A ajuda real aberta offline contém nominal/efetiva, Price/SAC, postecipados/primeiro pagamento após um mês, centavos/ajuste/contagem, exclusões e total não CET. Conteúdo AT-SPI e capturas de ajuda preservados. |
| 1217, AC4 | A janela mostrou CESEB 0.1.0 e revisão 57. O clique no link abriu PCManFM, PID 5429, título licenses, cmdline /usr/bin/pcmanfm /opt/ceseb/bin/../licenses; a captura mostra /opt/ceseb/licenses e os oito itens locais, sem rede. |
| [1221 r1](../../../requirements/1221/r1-build-contract.md), AC1–3 Linux | Atribuído a 2273: Ubuntu 24.04.5/GCC 13.3, script original de isolamento exit 0, 21/21 testes; ausência física de Qt antes do teste e ligação sem Qt. Mesma fonte 57, sem edição manual. |
| [1225 r1](../../../requirements/1225/r1-runtime-packages.md), AC2–4 Linux | DEB instalado pelo APT em runtime separado sem SDK/buildtools; bibliotecas privadas/dependências, metadados e launcher conferidos. O desktop entry publicado foi realmente lançado via Gio.DesktopAppInfo.launch, retornou true e abriu /opt/ceseb/bin/ceseb. Duas aberturas, com alteração de entrada entre elas, mostraram os padrões e nenhum resultado persistido. |
| [1226 r2](../../../requirements/1226/r2-wsl-linux-and-windows-smoke.md), AC1–4 Linux | Nominal, efetiva, invalidação, erro/correção, limpeza, teclado, redimensionamento e fechamento executados no pacote. Entradas, valores, plataforma, PID/exe, fonte e capturas registrados. O kernel é WSL e o desktop X11 é privado, condições reais explicitadas. |

As observações de 1215 e 1216 são das **duas combinações Linux**. O outro actor executa Windows; este report não transfere resultado entre sistemas. A presença do finding F3 no ZIP Windows permanece separada da execução do DEB. Não declaro o requisito 1225 inteiro aprovado sem a leitura conjunta de seu critério Windows.

## Valores exibidos

| Entrada | Taxas exibidas | Price | SAC | Diferença |
|---|---|---|---|---|
| 1.000,00; nominal 12%; 3 meses | Mensal 1,000000%; nominal 12,000000%; efetiva 12,682503% | Ordinária 340,02; última 340,03; 3 pagamentos; total 1.020,07; juros 20,07 | Primeira 343,34; última 336,66; 3 pagamentos; total 1.020,00; juros 20,00 | +0,07 |
| 1.000,00; efetiva 12%; 3 meses | Mensal 0,948879%; nominal 11,386552%; efetiva 12,000000% | Ordinária/última 339,68; 3 pagamentos; total 1.019,04; juros 19,04 | Primeira 342,83; última 336,49; 3 pagamentos; total 1.018,98; juros 18,98 | +0,06 |
| 1.000,00; 0%; 600 meses | Três taxas 0,000000% | Ordinária 1,67; última 1,34; 599 pagamentos; total 1.000,00; juros 0,00; aviso de quitação 599/600 | Primeira 1,67; última 1,66; 600 pagamentos; total 1.000,00; juros 0,00 | 0,00 |

Editar o tipo apagou a comparação antes do recálculo. Principal 0 provocou mensagem de erro e foco no valor; corrigir para 1.000,00 recuperou o mesmo resultado nominal. Limpar apagou campos/resultados e restaurou o foco no valor. Esses estados estão capturados, sem inferência de contagem de testes unitários.

## Evidências principais

[Driver X11/AT-SPI e roteiro literal](../../../../../../../out/validation-r3/ubuntu24/ui-driver/run-ui.py) · [Helper anterior reutilizado](../../../../../../../out/validation-r3/ubuntu24/ui-driver/prior-helper.py) · [Cobertura observada de 47 controles/textos e sequências de foco](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/observed-coverage.json).

[Estado 100%](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/scale-1-recovered/state.json) · [Eventos 100%](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/scale-1-recovered/events.jsonl) · [Resultado 100%](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/scale-1-recovered/result.json) · [Estado 200%](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/scale-2/state.json) · [Eventos 200%](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/scale-2/events.jsonl) · [Resultado 200%](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/scale-2/result.json).

[Nominal: formulário](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/scale-1-recovered/03-nominal-enter.png) · [Nominal: Price](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/scale-1-recovered/03-nominal-scroll-2.png) · [Nominal: totais SAC](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/scale-1-recovered/03-nominal-scroll-4.png) · [Efetiva e totais](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/scale-1-recovered/07-effective-scroll-2.png).

[Quitação 100%](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/scale-1-recovered/09-zero600-scroll-1.png) · [Final 100%](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/scale-1-recovered/09-zero600-scroll-3.png) · [Quitação 200%](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/scale-2/09-zero600-scroll-1.png) · [Final 200%](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/scale-2/09-zero600-scroll-3.png).

[Ajuda offline](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/scale-1-recovered/11-help-top.png) · [Árvore com texto da ajuda](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/scale-1-recovered/11-help-top.json) · [Roteiro do clique nas licenças](../../../../../../../out/validation-r3/ubuntu24/ui-driver/license-click.py) · [Resultado do handler](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/license-handler/result.json) · [Pasta aberta pelo app](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/license-handler/external-licenses-folder.png) · [Árvore externa do PCManFM](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/license-handler/external-accessibility.json).

[Roteiro do launcher/reabertura](../../../../../../../out/validation-r3/ubuntu24/ui-driver/desktop-launch.py) · [Resultado do launcher](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/desktop-launch-recovered/result.json) · [Padrões após reabrir](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/desktop-launch-recovered/desktop-defaults-2.png).

As capturas são originais da janela renderizada e foram inspecionadas diretamente. A análise de bounds e cobertura ajuda localizar o texto completo nas capturas, sem substituir a inspeção visual ou alegar suporte a toda tecnologia assistiva.

## Tentativas e recuperação dos meios de teste

A primeira execução 100% preservada em scale-1 registrou as ações e o fechamento; seu clique caiu na área vazia do QLabel, sem ativar o link. O roteiro foi corrigido para clicar no texto observado. A execução scale-1-recovered então acionou de fato xdg-open, mas revelou uma ausência do desktop mínimo: sem utilitário file, xdg-mime não identificou inode/directory e o handler não abriu. Instalei somente esse utilitário runtime no contêiner próprio, preservei [o log](../../../../../../../out/validation-r3/ubuntu24/ui-evidence/install-handler-runtime-file.log), desconectei novamente a bridge e repeti o clique no roteiro license-click. A prova final é a pasta aberta; não se substituiu o app, o link ou o handler por mock. A configuração do host e a composição do DEB não mudaram.

Na verificação do launcher, a imagem mínima não possui o executável gio. Usei a API Gio já instalada para lançar o mesmo desktop entry real. Um coletor inicialmente contou um processo zombie junto ao processo reaberto e recusou a seleção; preservei o log, capturei a janela real reaberta e corrigi somente o filtro para processos com /proc/PID/exe existente. O resultado final contém duas chamadas reais bem-sucedidas e duas janelas identificadas, com defaults observados. Nenhuma dessas correções alterou produto, critério ou resultado financeiro.

## Leitura e retorno

Li a memória própria r9, autoridade 1040, requisitos 1215/1216/1217/1221/1225 e 1226 r2, plano 2004, main_window.cpp, docs/user-guide.md, helper operacional anterior, contratos Dispatch/head-memory e cards pertinentes; recebi 2273 integral. Os runtime/desktop scripts são somente meios operacionais em out/; nenhum arquivo de produto/teste do repositório foi alterado. Não li todo Brain, bibliotecas de terceiros ou todos os logs anteriores. Não alego Computer Use funcionando: foi usado o outro método explicitamente pedido pelo usuário.

Todos os processos CESEB próprios foram fechados ao fim dos roteiros. Os contêineres e evidências privados foram mantidos para inspeção/reprodução; o próximo responsável é a revisão independente/root, que recebe os resultados Linux junto aos Windows e aplica somente os julgamentos sustentados. Não há novo finding de comportamento Linux nas execuções realizadas.
