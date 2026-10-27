---
id: 1225
revision: 1
type: requirement
tags:
- mortgage
- delivery
- level-system
- verification-test
status: pass
created: '2026-10-26'
updated: 2026-10-27
description: Fornecer pacotes executáveis nas plataformas declaradas sem exigir ambiente de
  desenvolvimento do usuário.
use_when:
- Verificar completude dos pacotes Windows e Ubuntu e suas dependências de execução.
---
# Pacotes utilizáveis pelo usuário final

## Requirement

Quando uma versão for entregue, seus pacotes devem permitir instalar ou extrair e abrir o aplicativo nos sistemas declarados sem configurar ferramentas de desenvolvimento.

## Origin and Boundary

**Nível:** Sistema. **Classificação de verificação:** Teste. O alvo é o entregável instalável ou extraível recebido pelo usuário final.

**Origem:** [pedido humano 1001 r1](../../documents/1001/r1-human-request.md) e [escolhas humanas 1005 r1](../../documents/1005/r1-human-scope-approval.md), detalhados na [decisão de design 1011 r1](../../decisions/1011/r1-complete-design-basis.md) e aprovados em [1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md). Contexto do Projeto 1: [imagem 1002 r1](../../documents/1002/r1-image-evidence.md); a imagem não é a fonte das políticas numéricas ou de interface específicas.

**Fronteira:** [1014 r1](../../specs/1014/r1-reproducible-delivery.md).

### Rationale

Um executável que depende do ambiente do desenvolvedor não atende a um usuário desktop comum. O pacote deve identificar suas dependências e permitir abertura a partir de uma instalação limpa.

## Verification

**Method:** Teste.

**Inputs and target:** ZIP para Windows 11 x86_64 e DEB para Ubuntu 24.04 x86_64; ambientes limpos, sem diretórios de desenvolvimento no PATH; revisão e plataforma identificadas. Alvo lógico: a implementação desta obrigação na spec 1014 r1; a revisão de código e os arquivos concretos serão fixados no plano aprovado.

### Acceptance Criteria

1. O ZIP contém o executável e as bibliotecas, plugins, runtime redistribuível permitido e avisos necessários à execução.
2. O DEB contém aplicativo, bibliotecas privadas necessárias, atalho desktop e dependências de sistema declaradas; não substitui uma instalação global compartilhada do framework gráfico.
3. Após extração ou instalação padrão, o aplicativo abre sem compilador, headers ou framework gráfico de desenvolvimento previamente configurados.
4. Cada pacote identifica versão, revisão de fonte e plataforma; ausência de biblioteca ou plugin necessário impede considerar o pacote utilizável.

### Procedure

1. Inspecionar os arquivos e metadados de cada pacote e suas dependências declaradas.
2. Extrair ou instalar no ambiente limpo correspondente e abrir o aplicativo pelo caminho de uso publicado, registrando o resultado.

**Oracle:** Todos os critérios numerados devem ser verdadeiros para as respectivas entradas; um resultado divergente, ausente ou fora da tolerância explícita reprova o caso. Erro de ambiente ou alvo indisponível é ausência de evidência, não resultado de comportamento.

**Limits:** A completude vale para os pacotes e sistemas efetivamente executados. Dependências de sistema declaradas podem ser instaladas pelo gerenciador padrão; não se promete execução em toda distribuição Linux. Esta autoria não executou o produto nem atribuiu pass/fail ao requisito.

## Trace

Related: [1014 r1](../../specs/1014/r1-reproducible-delivery.md); [correção autorizada 1017 r1](../../documents/1017/r1-design-approval-and-quality-correction.md); [decisão de correção 1018 r1](../../decisions/1018/r1-requirement-conformance-correction.md).

**Plano de implementação:** ainda não criado. **Plano de testes/verificação:** ainda não criado. Cada plano aplicável deverá vincular sua tarefa a este requisito r1 e declarar método e arquivos. Os executores e as ferramentas de verificação pertencem ao plano; este requisito declara o comportamento e seu oráculo.
