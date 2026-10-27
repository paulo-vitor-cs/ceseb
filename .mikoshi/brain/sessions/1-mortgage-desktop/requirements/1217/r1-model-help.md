---
id: 1217
revision: 1
type: requirement
tags:
- mortgage
- desktop-ui
- level-system
- verification-inspection
status: pass
created: '2026-10-26'
updated: 2026-10-27
description: Disponibilizar ajuda local com as convenções de cálculo, exclusões e identificação
  da versão.
use_when:
- Conferir se a ajuda pode ser consultada offline e explica o modelo efetivamente usado pela
  simulação.
---
# Ajuda local sobre o modelo

## Requirement

Quando o usuário abrir Sobre e modelo, o aplicativo deve disponibilizar localmente a descrição das convenções usadas e das exclusões da simulação.

## Origin and Boundary

**Nível:** Sistema. **Classificação de verificação:** Inspeção. A obrigação é um recurso de informação acessível no aplicativo distribuído.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1013 r1](../../specs/1013/r1-widgets-interface.md).

### Rationale

Sem as convenções e exclusões, o usuário pode confundir a estimativa com um financiamento completo. A ajuda local mantém essas informações acessíveis sem serviço externo.

## Verification

**Method:** Inspeção.

**Inputs and target:** Pacote instalado com rede indisponível; conteúdo de Sobre e modelo e arquivos locais de licença. Alvo lógico: a implementação desta obrigação na spec 1013 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. A ajuda explica nominal/efetiva, Price/SAC, primeiro pagamento após um mês e pagamentos postecipados.
2. O conteúdo descreve arredondamento em centavos, ajuste final e quantidade efetiva de parcelas.
3. O conteúdo informa a ausência de seguros, tarifas, impostos e indexadores e que o total do modelo não é CET.
4. A ajuda identifica a versão e permite acessar as licenças locais; abrir o conteúdo não depende de resposta de um serviço remoto.

### Procedure

1. Abrir Sobre e modelo com a rede indisponível.
2. Conferir a presença e coerência de cada tópico com as specs aprovadas e verificar o acesso aos arquivos locais indicados.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** A inspeção verifica conteúdo e disponibilidade local; não é aconselhamento financeiro nem auditoria geral de licenças. O inventário do pacote é verificado em 1228. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1013 r1](../../specs/1013/r1-widgets-interface.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
