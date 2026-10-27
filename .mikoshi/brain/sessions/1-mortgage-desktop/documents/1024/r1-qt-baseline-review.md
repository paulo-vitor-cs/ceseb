---
id: 1024
revision: 1
type: document
tags:
- mortgage
- design
- qt
- delivery
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Análise A1–A5 da revisão Qt 6.8.3 para 6.12.0, acesso aos kits, alternativas
  e limites de manutenção.
use_when:
- Decidir a revisão concreta da baseline Qt mantendo Widgets e os compiladores escolhidos.
---
# Revisão da baseline Qt por simplicidade

Autor: specialist Qt, head qt-resolution, fase 4 do fluxo Design. Pedido vigente: “Vamos resolver os empates numéricos e revisar a versão do Qt com base nas pesquisas, mantendo o caminho mais simples e seguindo o fluxo da Mikoshi.” Consumidor: orquestrador e humano. Esta análise propõe uma revisão concreta; a decisão [1026](../../decisions/1026/r1-qt-baseline-choice.md) continua open. Não houve instalação, build, teste de produto ou troca efetiva da baseline aceita.

## A1 — Pergunta, cenário e fronteira

Que pin atende a Windows 11 x64/MSVC 2022 e Ubuntu 24.04 x64/GCC 13, com Widgets dinâmico e uma rota de obtenção reproduzível, sem assumir manutenção própria de Qt? Cenário: outro desenvolvedor configura o mesmo kit e monta ZIP/DEB. Contraexemplo: escolher somente um número chamado LTS e descobrir que o patch requer assinatura ou compilação própria. Preservam-se C++20, GUI C++ Widgets/Fusion, módulos Core/Gui/Widgets e Test apenas no desenvolvimento; não se acrescentam QML, StyleKit, Canvas Painter ou novos recursos do Qt.

## A2 — Autoridade, fatos e hipóteses

A escolha anterior aceita é [1014 r1](../../specs/1014/r1-reproducible-delivery.md), Qt 6.8.3; o pedido atual autoriza preparar sua revisão, não herdar a aprovação anterior para novo corpo. Foram recuperados [pesquisa DIST 3003](../3003/r1-distribution-research-compilation.md), [síntese 3004](../3004/r1-research-synthesis.md), [acesso 3141](../../knowledge/3141/r1-qt-683-access-routes.md), [manutenção 3142](../../knowledge/3142/r1-qt-683-patch-security-conditioning.md), [baseline 3124](../../knowledge/3124/r1-pinned-baseline-core-isolation.md) e [cartão 2306](../../tools/2306/r1-qt-deployment.md). As consultas abaixo são atualização direcionada dessas perguntas, não uma repetição completa da pesquisa.

Não existe código de produto a migrar. Menor alteração de número não implica menor custo total se exigir manter patches e reconstruir o framework. Kits publicados não provam compatibilidade do aplicativo; a hipótese de viabilidade do kit novo precisa dos builds e da qualificação nativa já exigidos pelo projeto.

## A3 — Evidência discriminante e responsabilidades

| Unidade primária lida em 2026-10-26 | Fato observado e limite |
|---|---|
| [Anúncio Qt 6.12, cabeçalho e Update Today](https://www.qt.io/blog/qt-6.12-released) | Release 6.12 de 30/09/2026 disponível pelo instalador; não transforma suporte LTS comercial em assinatura adquirida pelo projeto. |
| [Matriz na tag v6.12.0, bloco desktop](https://raw.githubusercontent.com/qt/qtdoc/v6.12.0/doc/src/platforms/supported-platforms.qdocinc) | Mantém Ubuntu 24.04 x64/GCC 13 e Windows 11 x64/MSVC 2022. Não é resultado do aplicativo. |
| [Configuração QtBase v6.12.0](https://raw.githubusercontent.com/qt/qtbase/v6.12.0/.cmake.conf) | Mínimo CMake para consumir Qt compartilhado é 3.25; o mínimo 3.28 do projeto permanece suficiente documentalmente. Não certifica toda versão futura de CMake. |
| [Metadata Windows](https://download.qt.io/online/qtsdkrepository/windows_x86/desktop/qt6_6120/qt6_6120_msvc2022_64/Updates.xml) e [metadata Linux](https://download.qt.io/online/qtsdkrepository/linux_x64/desktop/qt6_6120/qt6_6120/Updates.xml) | Unidades base exatas identificam 6.12.0-0-202609280346, win64_msvc2022_64 e linux_gcc_64. HEAD dos dois qtbase retornou 200 sem autenticação; payloads não foram baixados. |
| [Arquivo oficial de fontes 6.12.0](https://download.qt.io/official_releases/qt/6.12/6.12.0/submodules/) | Fonte qtbase 6.12.0 listada. Recuperabilidade e correspondência do kit exato serão conferidas no plano; não basta link para latest. |
| [Licenciamento 6.12, módulos/terceiros](https://doc.qt.io/qt-6.12/licensing.html) e cabeçalhos SPDX da tag | As unidades selecionadas conservam alternativa LGPLv3; terceiros e ferramentas têm condições próprias. Não é certificação de um pacote ainda inexistente. |

A [observação de acesso](../../evidence/qt-baseline-review/access-observation.json) guarda metadata exata, hashes das respostas e HEAD com redirecionamento. O kit Linux se identifica como RHEL 9.6; a nota da documentação sobre Ubuntu/glibc 2.39 está no contexto Arm, e a página também menciona glibc 2.34 para binários Linux. Esses nomes/notas não substituem inspeção ELF/GLIBCXX do kit x64. Ubuntu 24.04 permanece o alvo de qualificação.

Cabeçalhos SPDX lidos na tag v6.12.0: [QObject](https://raw.githubusercontent.com/qt/qtbase/v6.12.0/src/corelib/kernel/qobject.h), [QGuiApplication](https://raw.githubusercontent.com/qt/qtbase/v6.12.0/src/gui/kernel/qguiapplication.h), [QApplication](https://raw.githubusercontent.com/qt/qtbase/v6.12.0/src/widgets/kernel/qapplication.cpp), [Fusion](https://raw.githubusercontent.com/qt/qtbase/v6.12.0/src/widgets/styles/qfusionstyle.cpp), [Windows QPA](https://raw.githubusercontent.com/qt/qtbase/v6.12.0/src/plugins/platforms/windows/qwindowsintegration.cpp), [xcb QPA](https://raw.githubusercontent.com/qt/qtbase/v6.12.0/src/plugins/platforms/xcb/qxcbmain.cpp) e [QtTest](https://raw.githubusercontent.com/qt/qtbase/v6.12.0/src/testlib/qtestcase.h). Leitura limitada aos cabeçalhos para essa classificação; não alega leitura integral dessas implementações.

### Manutenção e contraevidência

O [aviso original CVE-2025-5992](https://lists.qt-project.org/pipermail/development/2025-July/046449.html), já lido na pesquisa, inclui 6.8.3; a [lista oficial de vulnerabilidades](https://wiki.qt.io/List_of_known_vulnerabilities_in_Qt_products) identifica correção em 6.8.4. O mesmo índice, nas unidades CVE-2026-107157/16762/95620/105923, registra 6.12.0 entre as versões corrigidas. Isso sustenta revisão do pin; não prova segurança total ou exploração na calculadora.

A abertura direta do novo aviso [CVE-2026-107157](https://www.qt.io/blog/security-advisory-cve-2026-107157) voltou a falhar. Seu corpo aparece na pesquisa web, mas a conclusão acima usa a unidade legível do índice oficial, não uma alegação de leitura integral do aviso inacessível.

Contra uma alegação de Qt 6.12.0 totalmente atualizado, o [índice 6.12](https://download.qt.io/official_releases/qt/6.12/) já contém em 26/10/2026 o [diff CVE-2026-105924](https://download.qt.io/official_releases/qt/6.12/CVE-2026-105924-qtbase-6.12.diff). O diff completo foi lido via GET textual: commit, correção em qjsoncbor.cpp e testes do fornecedor. Trata de dereferência nula ao converter para JSON uma tag CBOR URL vazia. Não foi aplicado nem executado. O app projetado não importa CBOR/JSON; alcance pelo pacote real continua uma verificação de superfície futura. Essa constatação não exige acrescentar parsing, um mecanismo de patches ou código Qt customizado ao projeto. Se a análise do código/pacote identificar um caminho afetado, a baseline deve ser revista explicitamente antes da entrega.

## A4 — Alternativas sob os mesmos critérios

| Opção | Simplicidade e acesso | Contraponto | Proposta |
|---|---|---|---|
| Manter 6.8.3 original | Preserva kit já documentado e pin anterior | Mantém avisos posteriores conhecidos; tratamento de alcance ainda necessário | Viável somente com aceitação explícita de manutenção/risco; não recomendada para começar projeto sem código. |
| 6.8.3 + patches públicos | Corrige problemas selecionados sem nova série | Exige selecionar/aplicar patches, construir Qt nas duas plataformas, manter fonte modificada e nova identidade de binários | Maior custo de manutenção para este app. |
| 6.8.4/6.8.5 público | Fontes listadas no arquivo; 6.8.4 corrige 5992 | Isso não comprova kit binário equivalente nem todos os avisos posteriores corrigidos; pode exigir build próprio | Sem vantagem demonstrada sobre kit atual. |
| 6.8.9 LTS comercial | Rota de manutenção do fornecedor documentada | Acesso imediato comercial e termos próprios; assinatura não autorizada | Não selecionada para este projeto pessoal público. |
| 6.11.3 | Tabela móvel/aviso menciona versão | Nesta leitura, índice oficial 6.11 ainda listava 6.11.2; wiki previa 6.11.3 para hoje sem realização; anúncio direto inacessível | Não escolher disponibilidade ainda não observada por inferência. |
| **6.12.0 oficial sem patches próprios** | **Kits binários identificados nos dois alvos; mesmos módulos/compiladores, sem produto anterior a migrar** | Release recente; exige requalificar APIs/pacote e revisar avisos por superfície; não promete receber todo patch LTS sem condições | **Recomendada como pin concreto.** |

Mudar a versão não exige adotar funcionalidades novas. A escolha se inverteria se os kits exatos não fossem recuperáveis/compatíveis, se a licença das unidades reais não permitisse a rota escolhida, ou se a análise de superfície revelasse vulnerabilidade aplicável que exigisse patch ainda ausente. Não haverá fallback silencioso para outra versão.

## A5 — Juízo, limites e continuação

Recomendação técnica: Qt **6.12.0**, kits base **6.12.0-0-202609280346**, módulos Core/Gui/Widgets dinâmicos; Test somente no desenvolvimento. Evitar patchset próprio e build de Qt na primeira entrega. Manter C++20, MSVC 2022/v143, GCC 13 e CMake >=3.28. A diferença substantiva é o pin/framework obtido; domínio financeiro e UX não mudam por essa escolha.

Foi preparada [1014 r2](../../specs/1014/r2-reproducible-delivery.md), preservando r1, e revisado o cartão draft 2306 com a condição explícita de aprovação 1026. Os requisitos de produto 1221/1225–1228 continuam servindo; 1222–1224 permanecem obsolete e foram retirados da cobertura efetiva da sucessora. Ferramentas ficam nos cartões e futuros planos. A linha Boost da sucessora aceita a revisão numérica em paralelo, sem fixar uma arquitetura decimal insuficiente como único meio.

O papel humano resolve a escolha concreta 1026; autores dos planos fixam obtenção/checksums, composição runtime/licenças e verificação nativa. Nenhum experimento, kit Qt, compra, conta, instalação, alteração da spec r1, CI ou publicação ocorreu. A análise documental e HEAD encerram a incerteza sobre o candidato; não substituem futura execução das duas toolchains.
