---
id: 1221
revision: 1
type: requirement
tags:
- mortgage
- delivery
- level-integration
- verification-test
status: pass
created: '2026-10-26'
updated: 2026-10-27
description: Permitir compilar e consumir o núcleo financeiro nas plataformas declaradas sem
  dependência da interface gráfica.
use_when:
- Verificar que as interfaces e a composição do núcleo financeiro não dependem dos componentes
  gráficos.
---
# Independência do núcleo financeiro

## Requirement

Quando o núcleo financeiro for compilado ou consumido isoladamente, suas interfaces e dependências devem permitir esse uso sem instalar, ligar ou inicializar o framework gráfico do aplicativo.

## Origin and Boundary

**Nível:** Integração. **Classificação de verificação:** Teste. A obrigação trata a fronteira entre o núcleo reutilizável e a interface que o consome.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1014 r1](../../specs/1014/r1-reproducible-delivery.md).

### Rationale

A separação permite verificar o cálculo sem inicializar uma janela e evita acoplamento da regra financeira ao ambiente gráfico. A obrigação é a independência do componente, não a escolha de um sistema de build.

## Verification

**Method:** Teste.

**Inputs and target:** Mesma revisão de fonte do núcleo, desabilitando os componentes gráficos; ambientes Windows 11 x86_64 e Ubuntu 24.04 x86_64 definidos no design. Alvo lógico: a implementação desta obrigação na spec 1014 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. As interfaces públicas e dependências de ligação do núcleo não incluem componentes da interface gráfica.
2. O núcleo isolado pode ser compilado e utilizado pelos casos de conversão e amortização sem os componentes gráficos instalados ou inicializados.
3. A mesma revisão de fonte atende os dois ambientes declarados sem alteração manual da fonte do núcleo entre as plataformas.

### Procedure

1. Inspecionar as interfaces e dependências do componente financeiro.
2. Nos dois ambientes, compilar e consumir somente o núcleo a partir da mesma revisão, sem os componentes gráficos, e verificar os contratos financeiros aplicáveis.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** Este requisito não escolhe compilador, gerador, executor de testes ou automação de CI. A operação do aplicativo e dos pacotes completos é verificada em 1225 e 1226. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1014 r1](../../specs/1014/r1-reproducible-delivery.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
