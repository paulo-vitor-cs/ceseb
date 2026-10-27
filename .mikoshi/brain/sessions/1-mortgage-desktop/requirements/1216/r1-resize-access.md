---
id: 1216
revision: 1
type: requirement
tags:
- mortgage
- desktop-ui
- level-system
- verification-demonstration
status: fail
created: '2026-10-26'
updated: 2026-10-27
description: Manter controles, mensagens e resultados alcançáveis nas dimensões e escalas declaradas.
use_when:
- Verificar legibilidade e acesso ao formulário e resultados em 800 por 600 pixels lógicos nas
  duas escalas.
---
# Acesso ao conteúdo com redimensionamento

## Requirement

Quando a janela tiver 800 por 600 pixels lógicos nas escalas de 100% ou 200%, o aplicativo deve manter todo conteúdo necessário alcançável sem sobreposição impeditiva.

## Origin and Boundary

**Nível:** Sistema. **Classificação de verificação:** Demonstração. O alvo é a janela completa renderizada em cada plataforma e escala declarada.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1013 r1](../../specs/1013/r1-widgets-interface.md).

### Rationale

Redimensionar ou ampliar a escala não pode tornar uma ação ou resultado inacessível. O critério é acesso observável, não um julgamento subjetivo de modernidade.

## Verification

**Method:** Demonstração.

**Inputs and target:** Windows 11 e Ubuntu 24.04, cada um em escala de 100% e 200%; simulação R$ 1.000,00/0%/600 meses com aviso de quitação. Alvo lógico: a implementação desta obrigação na spec 1013 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. Nas quatro combinações de plataforma e escala, todos os campos, botões, cartões e mensagens são visíveis ou alcançáveis por rolagem vertical e teclado.
2. O formulário não exige rolagem horizontal; não há texto ou controle sobreposto que impeça seu uso.
3. Valores monetários e aviso de quitação possuem acesso ao texto completo, mesmo quando a largura exige rolagem ou reorganização do conteúdo.

### Procedure

1. Abrir a janela em cada combinação e ajustar para 800 por 600 pixels lógicos.
2. Produzir os resultados, percorrer controles e conteúdo por teclado/rolagem e registrar capturas que permitam conferir cada critério.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** As capturas qualificam somente as dimensões, escalas e plataformas executadas. Não estabelecem compatibilidade com toda resolução ou tecnologia assistiva. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1013 r1](../../specs/1013/r1-widgets-interface.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
