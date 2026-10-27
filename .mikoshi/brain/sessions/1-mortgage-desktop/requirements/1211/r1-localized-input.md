---
id: 1211
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
description: Converter os campos brasileiros para principal em centavos, taxa anual e prazo
  sem reinterpretar formatos ambíguos.
use_when:
- Verificar o contrato de parsing entre formulário, controlador e entrada financeira tipada.
---
# Interpretação dos campos em pt-BR

## Requirement

Quando o usuário preencher o formulário, o adaptador de entrada deve converter somente os formatos pt-BR definidos para suas unidades tipadas, sem truncamento ou interpretação por outro locale.

## Origin and Boundary

**Nível:** Integração. **Classificação de verificação:** Teste. A evidência cruza os campos textuais e a entrada tipada entregue ao núcleo.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1013 r1](../../specs/1013/r1-widgets-interface.md).

### Rationale

Um texto pode parecer válido e representar outro valor em locale diferente. O adaptador deve rejeitar ambiguidades e preservar a convenção da taxa escolhida.

## Verification

**Method:** Teste.

**Inputs and target:** Principais 100.000,00 e 100000,00; textos inválidos 1,000, 1,234.56, 1e3 e vazio; taxas 4,5, 4.5, 4,123456 e 4,1234567; prazo 360, 0 e 3,5. Alvo lógico: a implementação desta obrigação na spec 1013 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. 100.000,00 e 100000,00 produzem 10.000.000 centavos; 1,000, 1,234.56, 1e3 e vazio são recusados como principal.
2. 4,5 produz o percentual anual 4,5; 4.5 é recusado. A taxa 4,123456 é aceita e 4,1234567 é recusada sem truncar a sétima casa.
3. 360 produz prazo de 360 meses; zero e prazo fracionário são recusados.
4. A convenção nominal ou efetiva escolhida é mantida no objeto tipado. Somente espaços externos são removidos; principal aceita no máximo duas casas, taxa no máximo seis e prazo somente inteiro sem sinal.

### Procedure

1. Preencher o formulário com cada fixture e solicitar a conversão pelo controlador.
2. Inspecionar o valor tipado ou o erro, incluindo o caso nominal e o efetivo, e conferir que a conversão não altera a entrada para torná-la válida.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** O parsing não comprova os cálculos financeiros nem aceita valores fora dos limites adicionais de 1201 e 1105. Não prescreve uma biblioteca de localização. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1013 r1](../../specs/1013/r1-widgets-interface.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
