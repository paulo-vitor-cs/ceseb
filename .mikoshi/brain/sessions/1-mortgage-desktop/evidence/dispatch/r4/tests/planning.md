---
id: 2401
revision: 1
type: document
tags: [mortgage, dispatch, tests, planning]
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Autoria concreta do plano2005, com regressões F3/F4 e handoff ao executor do mesmo head.
use_when:
- Conferir o corpo e liberar a execução limitada de2005 antes de mudanças no produto.
---
# Retorno de autoria dos testes

[Plano2005r1](../../../../plans/2005/r1-f3-f4-regressions.md) pronto como draft: três tarefas, uma exigência real por tarefa, quatro paths de testes (dois modify/dois create). Nenhum teste ou produto foi editado, build executado ou commit criado nesta autoria. Root/MAIN `/home/paulo/ceseb`, flow design-project-1, head test-planning, owner dev-test-planning. Autoridade [1041](../../../../documents/1041/r1-f3-f4-correction-authority.md); autor Astra, execução posterior Sol6.1, mantendo head/memória e separação do produto.

F4: slot QtTest exercita MainWindow existente após paleta herdada escura; par de imagens preenchido/vazio dos quatro controles discrimina glifos ausentes, sem API nova ou comparação de fonteQSS. Preparação exclui borda/seta/cursor e bloqueia sinais no par. Native Windows/Ubuntu100/200 e leitura de cabeçalho/rodapé/ajuda completam o protocolo; presença de pixels não é limiar de legibilidade nem substituto de demonstração. A proposta deve falhar comportamentalmente no base; essa expectativa ainda não foi executada. Erro de preparo é indisponibilidade, não RED.

F3: coordenado diretamente com `/root/f3_f4_product_author`: produto2006 limita alterações a main_window.cpp/WindowsDeploy.cmake, aplica paleta na construção existente e omite DXC opcional. Checker inspeciona ZIP real e reprova dxcompiler/dxil em qualquer diretório, exigindo também runtime e notices existentes. Assim não passa um pacote vazio nem testa mera flag do deploy. O ZIPc716 retido contém ambas as DLLs e será a entradaBASE; SHA/revisão serão verificados antes da extração. T1228 usa inspeção por componente e materiais, sem inventar uma licençaDXC. Aceitar retençãoDXC com novos avisos não está implicitamente coberto por este corpo.

Suite declarada corrigida pela leitura real de tests/CMakeLists:26=20domínio+4GUI+2inventários, passando a27; core-only21 e scriptcore separado. Nenhum novo caso financeiro. Comandos/prefixos MSVCCommunity, Qt6.12, Boost1.86, GTest1.17, CMake/Ninja e drivers existentes estão no plano. WSLG/GCC15 é auxiliar; Ubuntu24/GCC13 e Windows11 preservam identidades. Sem instalação global ou mudança de configurações de tema.

Leitura própria: memória test-planningr11 integral; dispatchr13, delegated-context/nativebrief, plan-testsr7, devr15; contratos authority/revisions, verification/status, review-boundaries/task-file-format; cards4189/2521/2523, projeto2301/2303/2305/2306r2. Need1001, autoridade1041, specs1013r2/1014r3 e requisitos1216/1225/1228 íntegros; plano2004 e seus procedimentos; review2281r2 (julgamento/F4), review2281r1 (1225/F3), F3 original2241r2 e métodos/inventários;2271r2/2272 seções cenário/ambiente/resultados/limites;2273 ambienteGCC13; qualified-windows-run.py literal; run-core.sh literal. Fontes existentes: tests/CMakeLists, gui_test_main, gui_tests.hpp, appmain, construção/main_window até composição e ajuda pertinente; THIRD_PARTY_NOTICES e preparaçãoThirdPartyNotices; inventário real de licenses do ZIP extraído. Não reli todoBrain ou logs/imagens de toda rodada; as demonstrações antigas são atribuídas aos reports, sem alegação de nova observação de pixels.

Native roleconfiguration não foi fornecida como campo observável; devr15 foi lido manualmente. Handle `/root/f3_f4_test_author`, native_id desconhecido; nenhuma comprovação de injeção/carregamento nativo. Descoberta ALL_TOOLS não contém Context7/Serena; não alego chamadas nem instalação. Bibliotecas/API já existentes são reusadas.

Checks nativos: [plan-check](plan-check.json), [artifact-check](plan-artifact-check.json), leitura somente, result ok/exit0 (3tarefas/4paths, schema/links sem diagnósticos). Esses checks não aprovam corpo nem executam produto. Report e memória são os únicos efeitos adicionais; histórico e fontes preservados. Memória própria atualizada para r12, ownership liberado ao root para despacho Sol6.1 do mesmo head. Próximo passo: root lê/libera corpo concreto; executor cria testes, executaBASE, commita quatropaths e retorna 2411 antes do produto. Final 2412 fica posterior ao PRODUCT_HEAD/pacotes. Nenhum requisito recebe verdict por este relatório.
