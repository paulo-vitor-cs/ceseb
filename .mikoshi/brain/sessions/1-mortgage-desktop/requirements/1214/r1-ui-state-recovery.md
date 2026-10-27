---
id: 1214
revision: 1
type: requirement
tags:
- mortgage
- desktop-ui
- level-integration
- verification-test
status: pass
created: '2026-10-26'
updated: 2026-10-27
description: Invalidar resultados antigos e recuperar o estado da interface após erros ou correções
  de entrada.
use_when:
- Verificar as transições entre formulário, controlador, validação e apresentação dos dois resultados.
---
# Coerência entre edição, validação e resultados

## Requirement

Quando uma entrada mudar ou um cálculo falhar, o controlador deve manter a apresentação coerente com a validade da entrada corrente e permitir novo cálculo após a correção.

## Origin and Boundary

**Nível:** Integração. **Classificação de verificação:** Teste. A obrigação cruza eventos dos campos, resposta do núcleo e estado visual controlado.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1013 r1](../../specs/1013/r1-widgets-interface.md).

### Rationale

Um resultado antigo ao lado de entradas novas pode ser interpretado como uma simulação atual. A falha deve preservar os dados editáveis e indicar onde o usuário pode corrigir.

## Verification

**Method:** Teste.

**Inputs and target:** Sequência válida R$ 1.000,00/12% nominal/3 meses; edição de cada campo e tipo; entradas inválidas; R$ 0,01/0%/600 meses; resposta controlada ArithmeticError. Alvo lógico: a implementação desta obrigação na spec 1013 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. Calcular válido substitui os dois cartões; editar qualquer campo ou tipo apaga cartões, equivalências e diferença antes de outro cálculo.
2. Calcular inválido preserva entradas, apaga resultados e apresenta mensagem; a prioridade é principal, taxa/tipo, prazo e admissibilidade de centavos.
3. O foco segue o erro: principal para PrincipalOutOfRange e UnsupportedCentPrecision; taxa para erro de valor de taxa; tipo para erro de convenção; prazo para TermOutOfRange. ArithmeticError aparece na área geral e foca Calcular.
4. Corrigir a entrada e calcular produz o novo par de resultados. Limpar esvazia campos e resultados, restaura o tipo nominal e foca o principal.
5. UnsupportedCentPrecision do caso R$ 0,01/0%/600 orienta a ajustar valor, prazo ou taxa; mensagens não exibem traceback ou caminho interno.

### Procedure

1. Obter o resultado válido, editar cada entrada separadamente e conferir a invalidação imediata.
2. Executar os erros isolados e combinados para conferir preservação, prioridade, mensagem e foco; usar uma resposta controlada para ArithmeticError.
3. Corrigir, calcular novamente e acionar Limpar, observando os estados finais.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** A resposta controlada de erro permite verificar a fronteira sem exigir uma falha aritmética artificial no domínio válido. Não comprova a navegação nativa completa por teclado. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1013 r1](../../specs/1013/r1-widgets-interface.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
