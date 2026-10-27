---
id: 1227
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
description: Entregar documentação em português e relatório técnico que descrevam uso, modelo
  e resultados com origem recuperável.
use_when:
- Conferir se a documentação entregue permite usar a versão e relacionar suas alegações às evidências.
---
# Documentação de uso e relatório técnico

## Requirement

Quando uma versão for entregue, sua documentação em português deve explicar o uso e o modelo e relacionar as alegações técnicas às evidências da mesma revisão.

## Origin and Boundary

**Nível:** Sistema. **Classificação de verificação:** Inspeção. Documentação e relatório são entregáveis completos previstos no Projeto 1.

**Origem:** [entregável de relatório técnico da imagem 1002 r1](../../documents/1002/r1-image-evidence.md), [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md).

**Fronteira:** [1014 r1](../../specs/1014/r1-reproducible-delivery.md).

### Rationale

O projeto deve permitir que outro desenvolvedor ou avaliador entenda as convenções e confira os resultados. Uma afirmação sem alvo ou evidência recuperável não sustenta o relatório técnico.

## Verification

**Method:** Inspeção.

**Inputs and target:** Pacotes e documentação da versão; instruções de instalação, uso, compilação e verificação; relatório técnico e registros de execução existentes. Alvo lógico: a implementação desta obrigação na spec 1014 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. A documentação cobre instalação e uso, compilação e verificação nas duas plataformas, fórmulas, política de centavos, limites, exclusões, exemplo Price/SAC e dependências/licenças.
2. O relatório relaciona cada requisito efetivo aos planos e arquivos pertinentes e ao resultado observado na revisão e plataforma identificadas.
3. Cada resultado distingue sucesso, falha e não executado; qualquer comando marcado como verificado possui registro de execução no ambiente declarado.
4. Links de evidência do relatório permitem recuperar o alvo e os resultados citados; uma lacuna é declarada e não convertida em resultado positivo.

### Procedure

1. Percorrer a documentação e conferir os tópicos pela lista de critérios.
2. Selecionar cada alegação marcada como verificada e recuperar seu registro, revisão e plataforma; confrontar também as falhas e lacunas declaradas.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** O relatório não substitui execução do produto nem altera os oráculos para acomodar um resultado. Esta obrigação não determina ferramentas de build, testes, automação ou revisão. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1014 r1](../../specs/1014/r1-reproducible-delivery.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
