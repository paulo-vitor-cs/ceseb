---
id: 1042
revision: 1
type: document
tags:
- mortgage
- dispatch
- scope
- execution-release
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Liberação dos corpos concretos 2005/2006 dentro da correção F3/F4 explicitamente solicitada,
  com teste de base antes de produto.
use_when:
- Conferir os limites, corpos e gates antes de escrever testes ou corrigir o produto.
---
# Liberação concreta F3/F4

O pedido humano [1041](../1041/r1-f3-f4-correction-authority.md) ordena corrigir os dois defeitos confirmados, não apenas preparar uma proposta. O root leu integralmente os dois planos e os retornos Astra 2401/2402. Seus efeitos concretos são meios técnicos necessários dessa mesma correção: sem critério, pin, cálculo, tema global, interface ou dependência nova. Não há nova resposta humana ou aprovação por silêncio; a execução depende da ordem explícita existente, aplicada ao recorte abaixo. Os checks estruturais não são a fonte dessa autoridade.

Liberado [2005 r1](../../plans/2005/r1-f3-f4-regressions.md): três tarefas para 1216/1225/1228, quatro paths de testes. O executor Sol 6.1 usa o mesmo head test-planning/memória de entrada r12. Criar regressões, executar o base e commitar somente seus quatro paths; retornar o resultado real e TEST_HEAD antes de produto. Esperam-se RED de conteúdo e de renderização, nunca falha de preparação tratada como RED.

Conferido [2006 r1](../../plans/2006/r1-f3-f4-corrections.md): três tarefas para os mesmos requisitos, somente dois modifies de produto: src/ui/main_window.cpp e cmake/WindowsDeploy.cmake. **A execução de produto continua bloqueada até o retorno real do base e liberação do root com TEST_HEAD.** A política clara da própria aplicação e exclusão de DXC opcional preservam o desenho e funcionalidade aprovados; dependência real inesperada retorna antes de qualquer rota alternativa.

Os planos foram marcados published preservando os corpos finais após a integração. O único ajuste de coordenação antes do freeze corrigiu os IDs futuros de reports de teste: base 2411 e final 2412, evitando colisão com a autoria de produto 2402. Preimages estão no scratch; nenhum oráculo, tarefa ou filemap mudou nessa integração.

Usar toolchains e caches privados existentes, Ubuntu 24/GCC 13 e Windows Community 2022. Pode-se adaptar invocação/mount privados necessários, sem novo componente global. Falta concreta de meio local retorna ao root com evidência. Testes e produto têm autores separados e execução Sol 6.1 no respectivo mesmo head. Novos builds, fontes exportadas e pacotes ficam em r4, preservando todos os outputs antigos.

Após retornos, seguir Synapses independente, analyst e syncer com a autoridade de push de 1040; não retomar somente local. README, coordenação e metadata final pertencem ao root/analyst/syncer, fora dos commits de teste/produto. Não autoriza merge, PR, release, tag ou CI manual.
