---
id: 2402
revision: 1
type: document
tags: [mortgage, dispatch, implementation, planning, correction]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Autoria finita do plano2006 para F3/F4, com dois paths de produto e handoff escopado Astra para Sol6.1.
use_when:
- Conferir o plano concreto e liberar sua execução após os testes de base retornarem.
---
# Retorno de autoria F3/F4

[Plano2006 r1](../../../../plans/2006/r1-f3-f4-corrections.md) preparado com três tarefas de um requisito cada: D-1216 modifica src/ui/main_window.cpp; D-1225 modifica cmake/WindowsDeploy.cmake; D-1228 inspeciona o efeito compartilhado sem criar modificação artificial. Mantém todos os critérios e pins, modelos financeiros, desenho Widgets/Fusion claro, resultados e planos publicados anteriores.

Autor Astra /root/f3_f4_product_author, roledev manualr15; native_id e native role readback não disponíveis. ROOT/MAIN/workspace /home/paulo/ceseb; sessão1-mortgage-desktop; flowdesign-project-1; mesmo headimplementation-planning; memória de entrada r14. [1041](../../../../documents/1041/r1-f3-f4-correction-authority.md) delimita os erros; [1040](../../../../documents/1040/r1-alternative-validation-and-branch-push.md) mantém execução alternativa e push pelo syncer. Não houve produto/teste editado, build, execução GUI, novo pacote, commit, status ou remoto nesta autoria. O HEAD observado continua b5bb61c7a9a73f3a9174044621a7497dc274d0f3.

## Escolhas e interfaces

A política clara da própria aplicação será aplicada no construtor existente MainWindow antes dos filhos. A regressão do test author constrói esse mesmo objeto sob paleta escura, sem API ausente ou seam que deixe appmain sem exercício. Paleta explícita cobre texto/fundo/seleção/links nos estados, popup, diálogo e versão; QSS completa pares de entrada e fundo da página. Nenhuma configuração global Windows, novo tema ou biblioteca. O desenho claro já consta1013r2; isto corrige sua realização.

QtBase025bdad181de241e81bf853c8a2d7bf3d19261a9 foi aberto diretamente no archive já distribuído, src/tools/windeployqt/main.cpp:465..480 e1760..1810. A flag separada --no-system-dxc-compiler está em472;1793..1801 condiciona sua necessidade a D3D12/certos recursos. CMake/src atuais não usam tais caminhos: Widgets/Core/Gui, sem QML/Quick. O plano omite DXC/DXIL pela receita, sem filtrar pacote depois, e exige PE closure, observação de módulos carregados e uso real antes de declarar a correção qualificada. Se descobrir dependência, retorna ao root; não inventa licença. A leitura incidental qfusionstyle.cpp1700..1710 não é base da conclusão.

O test author /root/f3_f4_test_author confirmou teste real de renderização sob paleta hostil e auditoria do ZIP real exigindo ausência dos dois componentes opcionais, runtime obrigatório presente e notices resolvidos. O ZIP antigo c716 deve falhar por seus componentes efetivamente presentes. Nenhum teste da simples existência da flag será usado como prova de composição. O remédio está dentro1041, sem nova decisão material detectada.

## Leitura efetiva e alcance

Leitura própria: memória atribuída r14; Dispatchr13 e delegated-context/native brief; devr15; plan-implementationr11/code-implementr9; contratos authority/revisions, verification/status, review-boundaries e logical-head-memory; cards plan4189r2, commit4188r2, artifact2521r9 e headmemory2523r17. Fontes locais1001/1005/1040/1041, obrigações/ACs1216/1225/1228r1,1013r2, baseline/verificação/distribuição1014r3, plano2003r1, report2281r2 completo e F3/trace2281r1,2222r1 corpo de qualificação/auditoria, qualified-windows-notices-gap.json. Código: src/app/main.cpp, src/ui/main_window.cpp, CMakeLists.txt e cmake/WindowsDeploy.cmake. Cards2301r1 e2306r2 contrato de build/deploy. A leitura de report/source é evidência documental, não nova execução ou revalidação jurídica. Os cards2302/2303/2305 listados no plano devem ser abertos pelo executor antes dos respectivos comandos; não alego nova execução deles nesta autoria.

Context7/Serena ausentes no catálogo observado; nenhuma instalação ou chamada alegada. Busca local dirigida e fonte vendor exata foram suficientes para a escolha; não houve pesquisa externa, leitura de outras conversas ou boot de root.

## Verificação e entrega

[plan check](plan-check.json): resultok, três tarefas e dois modifies, D-1228operations vazio. Primeiro parser reportou necessidade de tabela Files explícita no task sem mudanças; o draft foi corrigido com tabela vazia, preservando a semântica reference-only. [Artifact/links](plan-artifact-check.json): resultok, sem diagnostics. Estes são checks estruturais, não aprovação nem teste do produto.

A execução requer retorno real do testBASE e liberação do root para o corpo concreto. BASE_PRODUCT será o commit dos testes; pacote usará HEAD_PRODUCT real posterior aos dois patches. Windows/Linux usam outputs novos r4, SDKs privados existentes e os meios de UI já autorizados. O relatório de execução registrará módulos/PE closure, novos DEB/ZIP, suite/core/GUI e quatro combinações1216, preservando limites reais de máquina limpa e pixels visíveis.

Autoria concluída e ownership deste escritor liberado após memória r15. Próximo escritor: Sol6.1 atribuído pelo root, mesmo head e memória, depois do testBASE. O root conserva integração, eventual decisão material, Synapses e syncer remoto. Este retorno não encerra a correção nem muda status dos requisitos.
