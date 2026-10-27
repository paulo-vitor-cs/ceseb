---
id: 1222
revision: 1
type: requirement
tags:
- mortgage
- delivery
- verification-test
status: obsolete
created: '2026-10-26'
updated: '2026-10-26'
description: Disponibilizar testes Google Test para todas as obrigações do núcleo.
use_when:
- Verificar suíte google test rastreável no aplicativo de financiamento.
---
# Suíte Google Test rastreável

Condição: entrada, ambiente ou sequência definidos no oráculo abaixo, sob a proposta de design referenciada. Obrigação: Disponibilizar testes Google Test para todas as obrigações do núcleo.

Método: Execução CTest e inspeção de mapeamento. Oráculo determinístico:

A suíte identifica cobertura de1101..1106 e1201..1207, com casos conhecidos,limites,zero,inválidos e regressões monetárias; logs por caso e saída CTest não zero quando há falha. O relatório vincula cada requisito a testes/resultados e commit. O teste-base precede implementação; falha de ambiente não é chamada RED. A presença desta suíte não atribui pass automático aos requisitos.

Fonte humana: [1001](../../documents/1001/r1-human-request.md), [1002](../../documents/1002/r1-image-evidence.md) e [1005](../../documents/1005/r1-human-scope-approval.md). Origem das políticas concretas propostas: [decisão1011](../../decisions/1011/r1-complete-design-basis.md). Contexto e fronteira: [spec1014](../../specs/1014/r1-reproducible-delivery.md). Requisito draft, sem plano aprovado, resultado de produto ou verdict de teste.
