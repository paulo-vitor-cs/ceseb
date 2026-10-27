---
id: 1228
revision: 1
type: requirement
tags:
- mortgage
- delivery
- level-system
- verification-inspection
status: pass
created: '2026-10-26'
updated: 2026-10-27
description: Preservar as licenças e os avisos aplicáveis aos arquivos e componentes efetivamente
  distribuídos.
use_when:
- Inspecionar identificação de licenças, avisos e acesso à fonte correspondente nos materiais
  da versão.
---
# Avisos e licenças dos materiais distribuídos

## Requirement

Quando um pacote ou material de fonte for distribuído, ele deve preservar os avisos e materiais exigidos pelas licenças dos componentes efetivamente incluídos, conforme o inventário da versão.

## Origin and Boundary

**Nível:** Sistema. **Classificação de verificação:** Inspeção. A obrigação é uma propriedade verificável do conjunto de arquivos entregue ao usuário.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1014 r1](../../specs/1014/r1-reproducible-delivery.md).

### Rationale

A licença dos arquivos originais não altera os termos dos componentes incorporados. Um inventário rastreável permite conferir quais avisos e materiais acompanham cada componente realmente distribuído.

## Verification

**Method:** Inspeção.

**Inputs and target:** Pacotes e fontes distribuídos; inventário com versão e licença de cada componente; política MIT dos arquivos originais e termos de terceiros identificados no design. Alvo lógico: a implementação desta obrigação na spec 1014 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. Os arquivos originais são identificados sob MIT, com o aviso de copyright aplicável; essa identificação não é atribuída aos materiais de terceiros.
2. Cada componente distribuído possui sua licença e avisos recuperáveis no inventário e nos materiais que o acompanham.
3. Para os componentes sob GPLv3/LGPLv3 descritos no design, os textos aplicáveis e o acesso recuperável à fonte correspondente exata e modificações são disponibilizados; a substituição das bibliotecas dinâmicas permanece possível conforme esses termos.
4. Os termos dos demais componentes e runtimes efetivamente incluídos são preservados; um componente não distribuído não é alegado como conteúdo do pacote.

### Procedure

1. Comparar o conteúdo real do pacote e dos materiais de fonte com o inventário da versão.
2. Recuperar os textos, avisos e fontes indicados para cada componente aplicável e registrar qualquer ausência ou identificação divergente.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** A inspeção deve usar versões e termos exatos do conteúdo distribuído. Não é uma auditoria jurídica geral, ativação de licença nesta autoria ou prescrição de ferramenta de construção. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1014 r1](../../specs/1014/r1-reproducible-delivery.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
