---
id: 1041
revision: 1
type: document
tags:
- mortgage
- authority
- dispatch
- correction
status: draft
created: '2026-10-27'
updated: '2026-10-27'
description: Pedido humano de Dispatch para corrigir F3/F4, preservando os critérios aprovados e a publicação
  já explicitamente solicitada.
use_when:
- Preparar e executar a correção limitada dos avisos DXC/DXIL e do texto invisível no Windows, com regressões
  antes do produto.
---
# Correções F3 e F4 solicitadas

Pedido humano integral desta etapa:

> $mikoshi:mikoshi-dispatch dev para corrigir esses erros

O usuário forneceu também o corpo completo de mikoshi-dispatch r13, no plugin 3.0.0. O pedido sucede o resultado dos seis requisitos: quatro pass e dois fail; inventário global de 22 pass e três fail.

Erros autorizados: **F4/P2**, requisito 1216 r1 AC1, campos preenchidos invisíveis no Windows escuro; **F3/P2**, requisitos 1225 r1 AC1 e 1228 r1 AC2, avisos específicos DXC/DXIL ausentes no ZIP. Fontes exatas: 2281 r2 em evidence/synapses/r3/dev-review-r2.md, 2271 r2 Windows e 2272 Linux. Código testado 57ef269; HEAD atual b5bb61c documental, com 55 paths de produto/testes iguais. Não mudar o modelo financeiro, Qt 6.12/Widgets/Fusion, idioma, moeda ou critérios por inferência.

Executar Dispatch limitado, com novas instâncias dos mesmos heads e respectivas memórias. Autoria de testes e produto separada, planos concretos 2005/2006 com tarefas por requisito, operações exatas e oráculos existentes. O fluxo fornecido explicita autoria Astra e execução Sol 6.1; será usada essa atribuição escopada, preservando o mesmo head e memória entre autor e executor. Testes escritos e executados no base antes do código de produto. O root confere os corpos concretos antes da liberação, verificando se seus efeitos são somente os meios técnicos da correção já ordenada; uma alternativa material nova não recebe aprovação implícita.

Meios admitidos: corrigir a aparência da própria aplicação sem mudar o tema/configuração global do Windows e corrigir a composição/avisos do pacote sem acrescentar dependência ou licença por inferência. Reusar os SDKs e ambientes privados já preparados, inclusive Ubuntu 24/GCC 13 e Community 2022; não instalar novos componentes globais. Questão técnica deve ser resolvida por fonte disponível. Escolha material nova retorna ao humano antes do efeito dependente.

A autoridade de push em 1040 permanece para a mesma branch codex/mortgage-desktop e repositório pessoal público. Completar a rodada até Synapses e syncer, incluindo commit/push e confirmação direta do remoto. Não retomar o limite antigo de somente local. Não autoriza merge, PR, release, tag ou disparo manual de CI por inferência. Preservar requisitos/specs/planos aprovados, reports anteriores, dados e alterações de outros owners.
