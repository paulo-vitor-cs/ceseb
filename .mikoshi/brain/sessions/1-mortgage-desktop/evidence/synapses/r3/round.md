---
id: 2280
revision: 1
type: document
tags: [mortgage, synapses, validation, publication]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: "Resultados dos seis requisitos pelo uso real do app: 1217 e 1221 pass, 1225 fail por avisos e três protocolos Windows interrompidos por sessão bloqueada; branch de código publicada."
use_when:
- Recuperar os ensaios reais, resultados aplicados e publicação solicitada, antes de retomar a interação Windows.
---
# Validação real dos seis requisitos

O aplicativo real foi usado nos cenários pedidos. O novo resultado é **1217 pass, 1221 pass e 1225 fail**; os cenários Linux de **1215, 1216 e 1226** passaram. Os protocolos desses três no Windows pararam antes da primeira entrada, porque a sessão está bloqueada. O inventário do código executado é **20 pass, dois fail e três protocolos Windows interrompidos**, com os motivos concretos abaixo.

Autoridade humana: [1040](../../../documents/1040/r1-alternative-validation-and-branch-push.md), pedido de usar outro meio e fazer o push. A limitação anterior de somente local foi introduzida na proposta do orquestrador e não impede a publicação agora ordenada. Os corpos aprovados não foram reescritos para mudar critérios.

## Publicação e identidade

O push de **codex/mortgage-desktop** foi executado com exit 0 e a referência remota foi conferida diretamente em **57ef26901d4381ead16c7347483d588ad9d92efe**, no [repositório pessoal público](https://github.com/paulo-vitor-cs/ceseb/tree/codex/mortgage-desktop). [Recibo do push do código](../../dispatch/r3/push-result.json). Nenhum merge, PR ou release foi criado. Essa é a revisão executada pelos pacotes e pelos testes; alterações documentais posteriores não são novas execuções de código.

ROOT/MAIN e workspace de implementação: /home/paulo/ceseb, sessão 1-mortgage-desktop. As **55 fontes de produto/testes continuam idênticas** ao commit 57; as **47 fontes aprovadas preservam seus corpos**. O README foi atualizado para descrever o aplicativo implementado, os resultados reais e as pendências. Duas capturas originais foram copiadas para docs/validation/r3 sem edição de pixels. A seleção documental de publicação conserva IDs, revisões e estados, incluindo as notas draft; não promove conhecimento. Recibos posteriores à seleção não se tornam parte retroativa do snapshot que descrevem.

## Ensaios realmente executados

[2271 Windows](../../dispatch/r3/windows-validation.md): EXE do ZIP aberto em Windows 11, PID 24464, 58 controles acessíveis com nomes e rótulos corretos; Qt Core/Gui/Widgets e qwindows somente da árvore privada do pacote. Consumidor do núcleo executado sozinho com PATH Windows/System32: **20/20 casos, exit 0**; dependências PE e módulos carregados sem Qt. A ativação recusou input porque o foreground era LockApp. A API WTS confirmou app, PowerShell e LockApp na mesma SessionId 1, SessionFlags LOCK=0; nenhuma tecla ou clique foi enviado e não houve tentativa de desbloqueio.

[2273 núcleo e runtime Ubuntu 24](../../dispatch/r3/ubuntu24-core.md): Ubuntu 24.04.5/GCC 13.3 em contêiner próprio, kernel WSL compartilhado; núcleo configurado, compilado e consumido **sem Qt fisicamente disponível durante o teste, 21/21, exit 0**. Depois foi preparado outro runtime separado, com o DEB instalado pelo APT e dependências desktop, sem compilador, headers de desenvolvimento, CMake, Ninja, Qt SDK ou mounts de fontes. Somente esse ambiente foi desconectado da rede para os testes offline.

[2272 aplicativo Linux](../../dispatch/r3/linux-validation.md): uso do executável real do DEB numa sessão X11/Xvfb/Openbox privada. Preenchimento por teclado, nominal/efetiva, Enter, erro com valor zero, correção, invalidação por edição, Limpar, ajuda e Escape foram executados. Tab e Shift+Tab seguiram a ordem publicada. Nas escalas 100% e 200%, janela 800×600 lógica, as capturas foram 800×600 e 1600×1200; todos os 47 textos/controles relevantes foram alcançados por foco/rolagem, sem sobreposição impeditiva observada. O caso 1000/0/600 mostrou aviso completo de quitação Price em 599/600 e SAC 600. O desktop entry real foi lançado duas vezes e os padrões voltaram ao reabrir.

O link de licenças foi acionado dentro do app e abriu **PCManFM PID 5429, endereço /opt/ceseb/licenses, oito itens locais**, offline com somente lo e nenhuma rota IPv4. O primeiro clique em área vazia e a ausência inicial do utilitário file no desktop mínimo foram preservados. Corrigiu-se apenas o meio de teste e completou-se esse utilitário runtime no contêiner; a rede foi novamente desconectada antes do clique final. O produto não mudou.

## Valores da interface

| Entrada | Price | SAC | Diferença de juros |
|---|---|---|---|
| R$ 1.000,00; nominal 12%; 3 meses | Parcela 340,02; última 340,03; total 1.020,07; juros 20,07 | Primeira 343,34; última 336,66; total 1.020,00; juros 20,00 | +0,07 |
| R$ 1.000,00; efetiva 12%; 3 meses | Parcela/última 339,68; total 1.019,04; juros 19,04 | Primeira 342,83; última 336,49; total 1.018,98; juros 18,98 | +0,06 |
| R$ 1.000,00; 0%; 600 meses | Ordinária 1,67; última 1,34; 599 pagamentos; total 1.000,00; juros zero | Primeira 1,67; última 1,66; 600 pagamentos; total 1.000,00; juros zero | 0,00 |

Os valores foram lidos externamente pela árvore acessível e confrontados com capturas da janela real. As capturas públicas do [formulário nominal](../../../../../../../docs/validation/r3/ubuntu24-nominal.png) e do [conteúdo a 200%](../../../../../../../docs/validation/r3/ubuntu24-200pct.png) são cópias originais dos ensaios. Os reports preservam as referências completas aos outputs locais e os limites de cada ambiente; não são QtTest ou dados sintéticos de cálculo.

## Julgamentos e estados aplicados

[2281 revisão independente](dev-review.md) recebeu todos os retornos completos antes de concluir e validou 5/5 declarações somente leitura. Reutilizou sua suíte anterior no mesmo 57 por identidade 55/55, sem alegar repetição nova: Linux/Windows 26/26 por backend e 21/21 core. A inspeção nova foi das execuções reais recebidas e do consumidor isolado.

| Requisito | Resultado desta rodada |
|---|---|
|1215 r1|Teclado Linux executado com sucesso nas duas escalas; Windows interrompido por LOCK.|
|1216 r1|Duas combinações Linux executadas com sucesso; duas Windows aguardam sessão desbloqueada.|
|1217 r1|**pass**: ajuda completa e licenças abertas pelo aplicativo, offline.|
|1221 r1|**pass**: interfaces, build e consumo do núcleo independentes de Qt nos dois sistemas.|
|1225 r1|**fail atual no 57**, AC1: avisos específicos DXC/DXIL ausentes no ZIP.|
|1226 r2|Cenários financeiros e transições Linux executados; protocolo Windows interrompido antes da entrada.|

A ausência de avisos para dxcompiler.dll/dxil.dll é o mesmo finding F3 que já reprova 1228; não é um parecer jurídico geral. Uma violação confirmada de AC1 basta para fail de 1225. O DEB e a abertura técnica Windows tiveram sucesso, preservados sem esconder a falha de composição. O fail antigo ce5 de launcher e a falta de julgamento da rodada 2 permanecem históricos, com seus próprios snapshots.

[2291 reconciliação](analyst.md) aplicou cinco operações nativas, todas exit 0: 1217/1221 published→pass, 1225 fail→fail com evidência atual 57 e duas specs parciais reafirmadas. Houve duas mudanças literais de estado. Specs 1008 r2/1012 r2 continuam implemented; 1013 r2/1014 r3 continuam partial implemented. Não houve nova transição de plano. 19 notas de conhecimento seguem draft; predecessores 1226 r1/1014 r2 mantêm o diagnóstico de retirement já recusado, sem nova tentativa ou edição de corpo aprovado.

Os três protocolos Windows ficam prontos para retomar quando WTS indicar sessão desbloqueada. O usuário recebeu o pedido de desbloqueio; não se deduz execução por silêncio. O app e o driver permanecem disponíveis conforme 2271. A sessão continua aberta; não houve correção automática do finding F3, promoção, merge, release ou aceite de produto. Telemetria opcional não foi usada nesta rodada.
