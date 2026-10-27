---
id: 1215
revision: 1
type: requirement
tags:
- mortgage
- desktop-ui
- level-system
- verification-demonstration
status: pass
created: '2026-10-26'
updated: 2026-10-27
description: Permitir operar formulário, cálculo, limpeza, ajuda e fechamento pela sequência
  de teclado definida.
use_when:
- Verificar acesso por teclado e identificação acessível dos controles nas duas plataformas.
---
# Operação por teclado

## Requirement

Quando o usuário operar a janela principal pelo teclado, o aplicativo deve permitir as ações previstas com a ordem de foco e atalhos definidos.

## Origin and Boundary

**Nível:** Sistema. **Classificação de verificação:** Demonstração. A obrigação cobre o uso do aplicativo completo em uma sessão desktop real.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1013 r1](../../specs/1013/r1-widgets-interface.md).

### Rationale

Uma interface simples precisa permitir uso sem mouse e indicar onde está o foco. A ordem declarada torna esse acesso verificável nas duas plataformas.

## Verification

**Method:** Demonstração.

**Inputs and target:** Aplicativo em Windows 11 x86_64 e Ubuntu 24.04 x86_64; cenário R$ 1.000,00, nominal anual 12%, 3 meses, incluindo erro e correção. Alvo lógico: a implementação desta obrigação na spec 1013 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. Tab percorre principal, taxa, tipo, prazo, Calcular, Limpar e Sobre; Shift+Tab percorre a ordem inversa.
2. Enter no formulário executa Calcular; Escape na janela principal fecha o aplicativo.
3. Rótulos têm associação de foco e nomes acessíveis; o foco atual é observável.
4. O usuário consegue preencher, calcular, corrigir um erro, limpar, consultar a ajuda e fechar sem mouse em cada uma das duas plataformas.

### Procedure

1. Abrir o aplicativo em cada plataforma e executar a sequência declarada somente com o teclado.
2. Registrar a ordem de foco, efeitos de Enter/Escape e acesso à ajuda; confirmar os resultados normativos e a correção do erro.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** Automação de eventos isolada não substitui esta demonstração em desktop nativo. Evidência em um sistema não qualifica automaticamente o outro. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1013 r1](../../specs/1013/r1-widgets-interface.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
