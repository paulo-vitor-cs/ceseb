---
id: 1032
revision: 1
type: decision
tags:
- mortgage
- planning
- ownership
- execution
status: decided
created: '2026-10-26'
updated: '2026-10-26'
description: Arranjo proposto para autoria distinta, testes em dois momentos, snapshot nativo
  e aquisição de dependências nos planos.
use_when:
- Revisar os meios concretos dos planos 2001 e 2002 sem mudar as fórmulas ou antecipar sua execução.
---
# Arranjo dos planos de engenharia

## Problema e autoridade

O [aceite 1028](../../documents/1028/r1-revisions-approval-and-planning-authority.md) autoriza preparar os planos. A baseline Git é documental, com artefatos aceitos locais fora do HEAD. O fluxo exige autores distintos, testes escritos e tentados no base antes do produto, commit coverage e qualificação nativa. Não existe produto para fabricar um RED funcional no base.

## Alternativas e proposta

Autores: dev-test-planning para [2001](../../plans/2001/r1-requirement-test-plan.md) e dev-implementation-planning para [2002](../../plans/2002/r1-product-implementation-plan.md). O [contrato 1030](../../documents/1030/r1-test-interface-and-fixtures.md) compartilha API física, nomes dos alvos e ownership; oráculos vêm das specs/requisitos aceitos, e não de outputs da implementação.

1. **Proposto: checkout sequencial `/home/paulo/ceseb`.** Preservar fontes e alterações alheias; commits locais com pathspec exato. Fontes de design/planos são referências read-only sob ROOT com manifestos de bytes, sem commits artificiais. Um worktree adicional exigiria materializar essas referências e coordenar mais ownership sem ganho demonstrado neste projeto ainda sem código.
2. **Testes em dois momentos.** Criar e tentar executar assets no base real, registrando configuração/coleta ausente como indisponível. Após o retorno, implementação usa esses testes. Procedimentos de pacote/GUI nativa/documentação completam depois do produto. Não condicionar o início do produto a todos os procedimentos pós-produto já completos.
3. **Separar identidades Git.** O range de arquivos de teste usa BASE e TEST_ASSETS_HEAD reais. As execuções finais declaram IMPLEMENTATION_HEAD real separadamente. O produto tem BASE posterior ao retorno/commit de testes e HEAD de resultado próprios. Não usar o HEAD bootstrap como se já contivesse design ou testes, nem inventar ranges. Mudança posterior de testes retorna ao seu autor e exige reconciliação do range e do oráculo.
4. **Exportação nativa read-only.** Um snapshot do commit real pode ser exportado para `C:/Users/paulo/AppData/Local/Temp/ceseb-native-1/source` para build Windows, com manifesto e revisão explícita. É output de execução; não é outro lugar para editar fontes/Git. O commit check continua no ROOT canônico. A mesma disciplina vale para Ubuntu 24.04 em `/tmp/ceseb-native-1/source`, com CWD `/tmp/ceseb-native-1` e build/out fora da fonte. O ROOT observado é Ubuntu 26.04/WSL; não pode ser apresentado como Ubuntu 24.04. Os alvos nativos qualificados são precondições, sem VM/provisionamento privilegiado criado por inferência. WSL/runner Server/offscreen não substituem o desktop-alvo.
5. **Aquisição por CMake existente.** A [receita 2306 r2](../../tools/2306/r2-qt-dependency-acquisition-and-deployment.md) usa arquivos oficiais fixados e verificados, sem acrescentar aqtinstall, secrets, conta ou patchset Qt. O script/lock ainda serão implementados pelo plano 2002. Preparação do ambiente e engenharia do script têm responsáveis e momentos distintos. A r1 aceita do cartão fica preservada.

## Escolha e efeito

**Open para a aprovação dos meios e efeitos junto dos planos concretos.** A proposta é do orquestrador em coordenação com os dois autores. Os nomes de arquivos/alvos são meios técnicos delegados; não alteram o modelo financeiro aceito. Nenhuma instalação, exportação, código, teste, commit, push ou workflow remoto foi executado por esta decisão.

A aprovação será apresentada em um único conjunto: os dois planos, o contrato 1030 e o cartão sucessor 2306 r2. Sem duplicar um gate para o mesmo efeito. Instalação/custo/provisionamento não descritos permanecem fora desse conjunto. Fonte, executor, privilégios e limites precisam aparecer nos planos antes da pergunta.

## Incidências e continuação

Fontes aceitas 1008/1012/1013/1014 r2 e 25 requisitos permanecem intactos. Cartão 2306 r1 continua mandatory no recorte aceito; r2 é draft até aprovação aplicável. Os novos planos apontam para r2 como receita proposta. 2301 a 2305 continuam reutilizados. Não há plano anterior publicado a substituir. O índice de revisão dos planos e sua evidência registram cobertura de requisitos, operações e os resultados mecânicos antes da execução.
