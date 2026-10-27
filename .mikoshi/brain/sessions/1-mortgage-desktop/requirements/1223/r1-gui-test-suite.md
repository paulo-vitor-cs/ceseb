---
id: 1223
revision: 1
type: requirement
tags:
- mortgage
- delivery
- verification-test
status: obsolete
created: '2026-10-26'
updated: '2026-10-26'
description: Disponibilizar testes QtTest das obrigações de entrada e estado da janela.
use_when:
- Verificar suíte qttest da interface no aplicativo de financiamento.
---
# Suíte QtTest da interface

Condição: entrada, ambiente ou sequência definidos no oráculo abaixo, sob a proposta de design referenciada. Obrigação: Disponibilizar testes QtTest das obrigações de entrada e estado da janela.

Método: Execução CTest e inspeção de mapeamento. Oráculo determinístico:

QtTest exercita1211..1214 e a sequência de teclado1215, incluindo eventos de edição e correção sem reimplementar os cálculos como oráculo da interface. O relatório separa testes offscreen/Xvfb de1215/1216 em desktop real e registra limitações. Uma falha da suíte propaga saída não zero em CTest.

Fonte humana: [1001](../../documents/1001/r1-human-request.md), [1002](../../documents/1002/r1-image-evidence.md) e [1005](../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: [decisão1011](../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: [spec1014](../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.
