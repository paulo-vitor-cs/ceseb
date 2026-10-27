---
id: 2003
revision: 1
type: plan
tags: [mortgage, dispatch, implementation, correction]
status: partial implemented
created: '2026-10-27'
updated: 2026-10-27
description: Corrigir descoberta desktop do DEB e recuperação local de licenças e evidências da documentação entregue, preservando resultados históricos.
use_when:
- Executar a correção limitada de F1 e F2 após testes de base e liberação do mapa concreto.
---
# Correções limitadas de distribuição

## Context

Pedido e autoridade: [1036 r1](../../documents/1036/r1-bounded-corrections-and-validation-authority.md), original [1001 r1](../../documents/1001/r1-human-request.md), escolhas [1005 r1](../../documents/1005/r1-human-scope-approval.md), [1014 r3](../../specs/1014/r3-wsl-validation-delivery.md), achados F1/F2 de [2101 r1](../../evidence/synapses/r1/dev-review.md) e conciliação [2102 r1](../../evidence/synapses/r1/analyst.md). Os planos publicados 2001/2002 e seus resultados permanecem intactos. Este novo plano Dispatch tem duas tarefas; não reinicia o fluxo de feature.

Autor e executor: instância fresca `/root/implementation_correction`, role dev, mesmo head lógico `design-project-1/implementation-planning`, memória `session_memory/design/implementation-planning.yaml`. A leitura do contrato dev r15 foi manual; não há readback que comprove carregamento nativo da role, nem native_id observado. ROOT, MAIN e workspace de implementação: `/home/paulo/ceseb`; sessão explícita `1-mortgage-desktop`; ramo `codex/mortgage-desktop`; entrada ce5db2e9d7489e0b6258b449358d620a0c390b1e. Novo BASE_PRODUCT será o HEAD real após commit dos testes de regressão pelo autor separado. Produto somente após retorno de testes no base e liberação explícita do orquestrador para este corpo/mapa; silêncio não libera.

## Procedure and Effects

1. Preservar dirty/untracked, README raiz, 43 corpos aprovados, testes e evidências históricas. Registrar versões, fontes, hashes dos quatro paths e estado inicial somente no report próprio.
2. Receber regressões e RED comportamental de F1/F2 no base. Não editar testes. Confirmar HEAD/base e cobertura exata da liberação antes de escrever produto.
3. Executar D-1225 e D-1227 nos cinco paths abaixo. Não alterar dependências, pins, framework, modelos financeiros ou arquitetura. Compilar com CMake 3.28.6/Ninja 1.13.1, GCC 15.2 e Qt 6.12.0/Boost 1.86/GTest 1.17 já existentes; nenhum download, instalação global, sudo, máquina nova ou configuração permanente. Os prefixos e flags OpenGL privados serão os observados em 2021/2101.
4. Commit local com pathspec exato dos cinco arquivos; não stage conteúdo alheio. Configurar novo build Release com CESEB_SOURCE_REVISION igual ao HEAD real commitado. Não reutilizar SourceRevision ce5/2b para o novo binário.
5. Rodar regressões recebidas, suíte CTest completa offscreen e XCB (26 entries/20 GTest+4 QtTest+2 inventários), inventários não vazios e isolamento core-only (21 entries), com logs/JUnit. Se uma operação falhar, conservar resultado e repetir somente após causa identificada dentro do escopo. Sem diagnóstico financeiro ou benchmark duplicado.
6. Instalar somente em DESTDIR/stage próprio, gerar DEB com CPack, extrair e inspecionar com dpkg-deb sem instalar globalmente. Conferir launcher XDG, Exec, dependências, versão/arquitetura/revisão, RPATH/qxcb/ldd e manifesto, links locais do índice e evidências citadas. Nenhum Qt do SDK no LD_LIBRARY_PATH da auditoria do pacote; somente runtimes de sistema privados existentes. Não declarar instalação limpa nem runtime Windows por inspeção.
7. Salvar report 2221 r1 e assets em `evidence/dispatch/r2/implementation/`; executar plan check e check-commits no range real. Reportar resultado do procedimento, arquivos, comandos, source identity, gaps e próximo responsável. Não escrever status de REQ/spec nem declarar revisão independente. Root coordena demonstração Computer Use; a emenda normativa publicada é 1226 r2/1014 r3, seleção efetiva de 1038. Apenas 1226 aceita WSL; demais matrizes permanecem.

Build/out próprios: `build/dispatch-r2/implementation`, `out/dispatch-r2/implementation/{stage,packages,extracted}`. São outputs locais ignorados de ferramentas, não caminhos de fonte novos. Reports/logs próprios pertencem somente a `evidence/dispatch/r2/implementation/`.

## Tasks

### Task D-1225

Requirement: [1225 r1](../../requirements/1225/r1-runtime-packages.md)

Kind: implementation

Method: Instalar o desktop file existente também no destino absoluto `/usr/share/applications/ceseb.desktop` do DEB, com o runtime mantido em `/opt/ceseb`. Preservar Exec absoluto existente e dependências privadas. Usar a semântica DESTDIR do gerador DEB de CMake 3.28 para destinos absolutos; confirmar no pacote extraído antes de concluir. Um install manual de teste sempre recebe DESTDIR para impedir escrita global. Não adicionar scripts postinst nem copiar binários ou Qt global. Manter o launcher privado se isso evitar quebra do inventário existente; a descoberta usa a cópia XDG.

Dependencies: retorno de regressões no base; liberação deste corpo/mapa.

#### Files

| Operation | Path | Destination |
|---|---|---|
| modify | cmake/Packaging.cmake | - |
| modify | docs/user-guide.md | - |

Completion evidence: Regressão F1 muda de falha comportamental para sucesso; DEB extraído contém launcher em caminho XDG padrão com Exec correspondente ao app real. Manual declara os dois caminhos. Pacote e ambiente ficam identificados; Windows/instalação limpa permanecem fora desta correção e não recebem pass.

### Task D-1227

Requirement: [1227 r1](../../requirements/1227/r1-technical-documentation.md)

Kind: implementation

Method: Preservar README e seus links portáteis `../LICENSE` e `../THIRD_PARTY_NOTICES.md`, instalando cópias idênticas dos dois arquivos também na raiz do prefixo; manter originais de notices em licenses. Explicar o layout. Atualizar docs/build-and-test.md com o input documental explícito e substituir install com prefix-only por DESTDIR próprio e prefixo /opt/ceseb, impedindo que o novo launcher absoluto escreva no sistema durante staging. Reescrever somente a seção de evidências do relatório técnico para usar links relativos reais e recuperar a leitura dos resultados históricos. Conservar fórmulas, todas as 25 rotas requisito/tarefa/arquivo, falhas XCB autorais e F1/F2 ce5, sucessos e lacunas; nenhum sucesso histórico é reatribuído ao novo pacote.

A árvore de evidências entregue preservará os locators relativos ao ROOT, permitindo links iguais no checkout e pacote. Packaging.cmake terá input explícito `CESEB_DELIVERY_EVIDENCE_ROOT` (PATH, vazio por padrão). Compilar não requer esse input; install/package requer o export de registros históricos e falha com diagnóstico acionável se um item obrigatório faltar. Não introduzir dependência oculta de untracked do checkout: README/guia/relatório explicam que um git archive precisa receber esse input documental externo separado, com mesmos locators. A cópia é uma allowlist literal, sem glob, sem Brain inteiro/cache/memória/transcrição. A procedência local e hashes de entrada constam do report 2221; não se afirma publicação remota desses registros.

Allowlist exata, cada path relativo a CESEB_DELIVERY_EVIDENCE_ROOT e copiado ao mesmo path relativo no prefixo instalado:

- `.mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/execution.md`
- `.mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/aux-core-results.json`
- `.mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/aux-core-1.log`
- `.mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/aux-core-2.log`
- `.mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/aux-core-3.log`
- `.mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/aux-gui-ctest-offscreen.log`
- `.mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/aux-gui-ctest-offscreen.json`
- `.mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/aux-gui-ctest-xcb.log`
- `.mikoshi/brain/sessions/1-mortgage-desktop/evidence/implementation-planning/aux-gui-ctest-xcb.json`
- `.mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r1/dev-review.md`
- `.mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r1/dev/requirement-trace.json`
- `.mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r1/dev/execution.json`
- `.mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r1/dev/package-audit.json`
- `.mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r1/dev/package-execution.json`
- `out/review-wsl/ctest-offscreen.log`
- `out/review-wsl/ctest-offscreen.xml`
- `out/review-wsl/ctest-xcb.log`
- `out/review-wsl/ctest-xcb.xml`
- `out/review-wsl/core-isolation.log`
- `out/review-wsl/domain-details.log`
- `out/review-wsl/domain-details.xml`

Os dois reports completos são conservados como fontes históricas; seus links contextuais para autoridades/outros artefatos fora dessa allowlist são explicitamente fora do bundle. Cada alegação de execução presente no relatório técnico entregue apontará diretamente para registro incluído, com commit/ambiente, sem depender desses links contextuais. O novo procedimento 2221 fica separado para evitar autocitação circular: o pacote não afirma ter recebido uma execução futura nem inventa seu próprio hash.

Dependencies: D-1225; retorno dos testes; liberação do input documental explícito.

#### Files

| Operation | Path | Destination |
|---|---|---|
| modify | cmake/Packaging.cmake | - |
| modify | docs/README.md | - |
| modify | docs/technical-report.md | - |
| modify | docs/build-and-test.md | - |

Completion evidence: Regressões F2 positivas para README/licenças e evidências do relatório na árvore DEB, hashes das cópias iguais às entradas e todos os links diretos de evidência do relatório resolvidos. Relatório técnico conserva resultados negativos/não executados e mapa dos 25 requisitos. Build sem input documental continua possível; tentativa de empacotar sem um registro obrigatório falha antes de ser anunciado pacote completo.

## Windows follow-up within the same plan

A autorização humana posterior 1039 permite instalar ferramentas Windows; o syncer separado `/root/windows_tools_install` é responsável por esse ambiente, não por executar este plano. Após seu handoff observado e a liberação do root, exportar a fonte commitada do HEAD real de produto para ZIP imutável e manifesto, sem dirty/untracked. Export e cópia Windows são outputs operacionais, sem novos paths de fonte. Executar configure/build/test/package Windows Release na fonte exportada com CESEB_SOURCE_REVISION=HEAD real, MSVC 2022 v143/SDK, CMake/Ninja e kits/dependências aprovados presentes. Usar o input documental externo explícito e notices/fontes preparados; qualificar edição/termos REDIST e lista de DLLs antes de ativar flags de CRT ou anunciar pacote completo. Falta de kit Qt Windows, termos ou fonte exata permanece gap; não instalar/obter dependências por inferência. Registrar revisão, toolchain, comandos/logs e resultado de ZIP. Sem Git metadata no export, nunca obter identidade por fallback ao checkout errado. Linux prossegue independentemente. Demonstração Computer Use é do root, não deste executor.

## Limits and Tools

Cards 2301 r1/2306 r2, Git 2570 r8, plan 4189 r2, commit-check 4188 r2 e head-memory 2523 r17. Context7/Serena não estão expostos no catálogo desta instância; não serão instalados ou anunciados como usados. Documentação instalada CMake 3.28 e fonte atual são o fallback delimitado para install/CPack. Ausência de role readback nativo permanece lacuna. Windows/MSVC/CRT, smoke e escalas/teclado dos alvos não são resolvidos pela correção. Sem push/CI/PR/merge/release/promoção/fechamento, nova feature ou revisão normativa por este autor.
