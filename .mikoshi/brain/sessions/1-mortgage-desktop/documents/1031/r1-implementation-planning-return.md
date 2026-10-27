---
id: 1031
revision: 1
type: document
tags:
- mortgage
- implementation-plan
- handoff
status: versioned
created: '2026-10-26'
updated: '2026-10-26'
description: Retorno da autoria do plano de implementação com 25 requisitos, 31 arquivos novos,
  contrato coordenado com testes e limites de execução.
use_when:
- Integrar e aprovar o plano 2002, conferindo cobertura, dependências, ownership e o retorno
  obrigatório dos testes antes de produto.
---
# Retorno do plano de implementação

Autor: dev-implementation-planning; handle `/root/implementation_planning`. Contexto: [aprovação 1028](../1028/r1-revisions-approval-and-planning-authority.md), no workspace `/home/paulo/ceseb`. Entrega: [plano 2002 r1](../../plans/2002/r1-product-implementation-plan.md), ainda draft para aprovação concreta. Este retorno é autoria e integração, não revisão independente nem execução do produto.

## Resultado concreto

São 25 tarefas, cada uma com uma única referência exata a requisito publicado, Kind implementation, método e tabela de operações. A união tem **31 arquivos novos**, sem modificar o README.md que já contém mudanças de coordenação. `docs/README.md` é a entrada criada para a documentação do produto. Não há rename/delete, mudanças de fontes aprovadas ou de arquivos tests/. A tarefa I-1226 é uma demonstração/inspeção sem mudança de fonte, com tabela vazia explícita; não se cria commit artificial.

A composição contém núcleo financeiro independente de Qt, origem/taxas exatas e decisões de fronteira, MoneyCodec, controlador/janela Widgets/Fusion, build e aquisição de dependências, workflow manual, empacotamento ZIP/DEB e avisos/documentação. O plano preserva nominal/efetiva, Price/SAC, os oráculos e todos os limites aprovados.

## Coordenação efetivamente realizada

O dev testes produziu o [contrato 1030](../1030/r1-test-interface-and-fixtures.md), lido e aceito por este autor: finance.hpp público, Result/NormalizedRate/Schedule/Comparison e assinaturas, targets ceseb_core/ceseb_ui/ceseb/ceseb_domain_tests/ceseb_gui_tests e objectNames Qt. O único seam CompareFunction serve à resposta controlada ArithmeticError de 1214. O produto normal usa compare real; testes financeiros não usam um core fictício.

Os autores combinaram versão 0.1.0, nomes de pacotes, flags CMake, caminhos bin e prefixos. Root definiu execução sequencial em MAIN e export Git nativo imutável para Windows, com build/deps fora de source. O autor dos testes escreve e tenta executar no base antes de qualquer alteração de produto. Ausência de fonte/header/target/dependência continua indisponibilidade de coleta, sem RED fabricado. Depois de seu retorno, 2002 usa os testes recebidos, sem editá-los. Protocolos nativos e documentação do mesmo plano 2001 são completados pós-produto, sem ciclo exigindo 2001 implemented antes do código.

`BASE_IMPL=TEST_ASSETS_HEAD` real, posterior ao commit dos assets. O range de commit dos testes continua próprio; o alvo runtime da verificação final será IMPLEMENTATION_HEAD. Fontes/planos aprovados untracked podem ser read-only sob ROOT com seu manifesto; não foram commitados por conveniência. O plano separa ordem de autoria dos métodos e conclusão da verificação integrada: V-CORE/V-BUILD requerem as fontes posteriores e não bloqueiam sua criação com um gate circular.

## Fontes consultadas e observações

Lidas as skills plan-implementation, design e simplicity; template de plan e task-file-format; cards mecânicos 4189/4196/4188/2570/2521/2523; os seis cards de projeto, quatro specs r2, necessidade original, autoridade 1028 e os 25 requisitos. As análises 1023/1024 foram lidas como apoio e limite, sem transferir para elas resultado de produto. As leituras de ferramentas/alguns requisitos que tiveram saída truncada foram recuperadas em consultas menores; as seções normativas e critérios efetivos foram lidos.

Novas leituras primárias foram limitadas a identidade para tornar a aquisição concreta. GET de metadata oficial, sem payload, confirmou:

- GoogleTest 1.17.0: commit 52eb8108c5bdec04579160ae17225d66034bd723; Boost 1.86.0: arquivo e SHA256 oficiais.
- Qt SDK 6.12.0-0-202609280346: unidades exatas, URLs e digests SHA256 oficiais por arquivo. O candidato inicial incluía QtTools para deploy Windows, mas a leitura do diretório e CMakeLists **v6.12.0** mostrou windeployqt em QtBase. O plano seleciona somente QtBase no Windows e QtBase+ICU no Linux; a metadata QtTools continua como alternativa não selecionada.
- Actions checkout v7.0.1 e upload-artifact v7.0.2: refs oficiais resolvidas a commits e unidade runs do action.yml em node24. Nenhum workflow foi criado ou disparado.

Evidências: [pins de fontes](../../evidence/implementation-planning/source-pins.json), [pins SDK](../../evidence/implementation-planning/qt-acquisition-pins.json), [pins CI](../../evidence/implementation-planning/ci-action-pins.json), [localização do tool](../../evidence/implementation-planning/deployment-tool-source-location.json) e [CMakeLists do windeployqt](../../evidence/implementation-planning/windeployqt-tagged-build.txt). Não foi lido ou executado o payload de Qt/GTest/Boost, nem houve download de tais arquivos binários/fontes.

## Verificação e limites

A conferência nativa de estrutura, metadados e links está em [checks.json](../../evidence/implementation-planning/checks.json). O [manifesto](../../evidence/implementation-planning/input-and-file-manifest.json) conserva hashes dos requisitos/specs e a união de arquivos. Esses checks não são compilação, testes, benchmark, commit coverage ou pass de requisito. Os caminhos de produto citados são operações futuras, não arquivos já existentes. BASE/HEAD de execução continuam a ser capturados de commits reais quando o plano for executado.

A aquisição proposta exige TLS_VERIFY ON, NETRC IGNORED, vendor SHA256 antes de extrair e manifesto/validação de relocação Qt. Ela consome a [sucessora 2306 r2](../../tools/2306/r2-qt-dependency-acquisition-and-deployment.md), draft para aprovação conjunta com o plano. Não instala ou assume login de Qt Account. CMake/GCC/MSVC/Ninja, desktop nativo e acesso permitido à edição/CRT precisam ser efetivamente disponibilizados/observados. A rota não faz build/patch próprio de Qt. A presença de kit não comprova ABI, runtime, licença do pacote ou ausência universal de vulnerabilidade.

A aprovação futura cobre o corpo e efeitos locais delimitados: fonte/commits por pathspec, obtenção explícita dos componentes públicos e builds/exports/staging/pacotes nas árvores indicadas. Instalação privilegiada ou provisão de máquina não é inferida; a falta de ambiente retorna lacuna. Nenhuma conta, credencial, assinatura, push, PR, merge, release ou CI remoto é executado por este retorno. O próximo responsável é o orquestrador para integrar ambos os planos, conferir cobertura e apresentar o conjunto concreto ao humano. Autoria dos arquivos desta entrega será liberada após o retorno.
