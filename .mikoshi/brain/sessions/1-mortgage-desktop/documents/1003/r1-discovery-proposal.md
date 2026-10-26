---
id: 1003
revision: 1
type: document
tags:
- mortgage
- discovery
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Proposta concreta de escopo, atores, cenários, limites e escolhas abertas
  para o aplicativo de financiamento do Projeto 1.
use_when:
- Revisar a descoberta antes de autorizar exploração, esclarecimentos e arquitetura
  da calculadora desktop.
---
# Descoberta do Projeto 1 — proposta r1

Estado: rascunho para revisão humana. Fase atual: 1, Discovery. Nenhuma spec ou requirement foi aprovada e nenhum código de produto foi escrito.

## Necessidade e resultado esperado

Desenvolver uma calculadora de financiamento imobiliário desktop em C++, utilizável em Windows e Linux. A interface deve ser simples e moderna. O projeto deve demonstrar engenharia verificável com requisitos, design, implementação, testes e relatório técnico, conforme o painel Project 1.

## Atores e cenários

| Ator | Cenário | Resultado esperado proposto |
|---|---|---|
| Pessoa que simula financiamento | Informar principal, taxa e prazo e solicitar cálculo | Ver parcela mensal, total pago e juros totais com unidades explícitas |
| Pessoa que corrige uma simulação | Informar valores vazios, inválidos ou fora dos limites | Receber uma mensagem clara, preservar entradas e poder corrigir |
| Pessoa que explora condições | Calcular com juros zero e valores de fronteira | Obter comportamento definido pelos requisitos e sem falha da aplicação |
| Desenvolvedor ou avaliador | Compilar, executar testes e comparar com os requisitos | Reproduzir o resultado e localizar sua evidência |
| Usuário Windows ou Linux | Obter uma distribuição e abrir o aplicativo | Usar a interface sem configurar um ambiente de desenvolvimento |

## Escopo inicial proposto

1. Uma janela com entradas de valor financiado, taxa de juros anual e prazo.
2. Ação de calcular e resumo com parcela mensal, total pago e juros totais.
3. Simulação local sem conta, servidor ou conexão durante o uso.
4. Validação de entradas, unidades e erros explícitos, com operação por teclado.
5. Separação do cálculo financeiro da interface para permitir testes unitários com Google Test.
6. Testes de casos conhecidos, limites, juros zero, entradas inválidas e regressões. Cada oráculo deverá ter origem e tolerância justificadas.
7. Build e teste nas duas plataformas, com instruções de uso e distribuição verificável. Formatos finais de pacote e versões suportadas serão definidos no design.
8. Repositório público na conta pessoal, histórico Git e documentação técnica com rastreabilidade de requirement para plano, arquivo e resultado.

A tabela mensal de amortização e exportação CSV podem ser úteis, mas ficam fora deste primeiro recorte até escolha humana. Não há importação de dados, banco de dados, login, serviços bancários, RTOS, TinyML ou integração com os outros projetos.

## Tecnologias

| Origem | Tecnologia | Situação |
|---|---|---|
| Pedido humano e imagem | C++ | Exigido |
| Imagem, Project 1 | Google Test | Exigido |
| Imagem e pedido humano | GitHub; repositório pessoal público | Exigido e criação autorizada |
| Proposta do orquestrador | C++20 | Versão a confirmar no design |
| Proposta do orquestrador | Qt 6 Widgets com layouts, estilos e componentes desktop | Escolha material aberta |
| Proposta do orquestrador | CMake e CTest | A confirmar no design |
| Proposta do orquestrador | GitHub Actions para Windows e Linux | A confirmar no design; sem workflow criado nesta fase |

Qt Widgets oferece componentes, layouts, estilos e integração com CMake. A documentação Qt inclui Windows e Linux, mas a combinação exata de versão Qt, compilador e sistema operacional ainda precisa ser fixada. Google Test documenta integração com CMake e CTest. Essas leituras sustentam a viabilidade proposta; não comprovam um build deste projeto.

Fontes consultadas em 2026-10-26:

- [Qt Widgets](https://doc.qt.io/qt-6/qtwidgets-index.html).
- [Plataformas Qt](https://doc.qt.io/qt-6/supported-platforms.html).
- [Google Test com CMake](https://google.github.io/googletest/quickstart-cmake.html).

As páginas Qt são documentação corrente e não fixam a versão da dependência do projeto. Qt Quick/QML é uma alternativa para uma interface mais animada, com maior superfície de tecnologia. A proposta Widgets prioriza uma interface desktop direta e majoritariamente C++.

## Escolhas que permanecem abertas

| Escolha | Proposta para revisão | Alternativa e consequência |
|---|---|---|
| Sistema de amortização | Parcelas fixas (Price), para o exemplo da imagem | Price e SAC ampliam o modelo, a interface e os testes |
| Taxa e encargos | Taxa anual nominal dividida por 12; sem seguros, tarifas ou impostos | Taxa efetiva e custos adicionais exigem contratos e dados adicionais |
| Precisão financeira | Política de centavos e arredondamento explícita, a ser definida com oráculos | Não usar os números arredondados da imagem como definição implícita |
| Idioma e moeda | Interface pt-BR e BRL | Inglês e USD acompanham a apresentação da imagem; outros idiomas ampliam localização |
| Interface | Qt 6 Widgets | Qt Quick/QML acrescenta outra linguagem e opções visuais |
| Licença | A selecionar antes da distribuição de código e dependências | Repositório público, por si só, não escolhe uma licença |
| Plataformas | Windows e Linux desktop; versões e arquiteturas a fixar | Não prometer todas as distribuições nem todas as versões de Windows |

As propostas acima não estão decididas. Nenhuma inferência de silêncio resolverá essas escolhas.

## Workspace e artefatos afetados

O diretório inicial está vazio. Não existe código, Git, specs, requirements, planos, knowledge ou grafo anterior do projeto. Não há revisões ou arestas incidentes existentes a preservar. Interfaces pretendidas, ainda não especificadas: formulário → caso de uso → cálculo financeiro → resultado; validação → apresentação de erro; Google Test → núcleo financeiro; CMake/CTest → compilação e testes.

A associação MAIN é este workspace. Ainda não existe worktree de implementação. A sessão nova é [1-mortgage-desktop](../../session_state.yaml). O nome administrativo `ceseb` acompanha o diretório indicado pelo usuário e será usado para o repositório autorizado; pode ser renomeado posteriormente por instrução humana.

## Entregáveis previstos e critérios de conclusão

- Specs por funcionalidade e requisitos determinísticos, com revisões e escolhas atribuídas.
- Planos concretos de implementação e teste, de autoria distinta, submetidos à aprovação aplicável antes da execução.
- Aplicativo funcional, testes Google Test, build e evidência observada para Windows e Linux.
- Relatório técnico, instruções de compilação, execução e demonstração.
- Revisão independente na Synapses após a execução e reconciliação posterior aos retornos obrigatórios.

Nesta descoberta, somente o pedido, a extração da imagem, esta proposta e os registros de sessão são entregues. Não há resultado pass, implementação ou qualificação de runtime a declarar.

## Gate proposto

Revisar este escopo e autorizar, se adequado, as fases 2 (exploração), 3 (esclarecimentos) e 4 (arquitetura em rascunho). Confirmar ou alterar as escolhas de interface, modelo financeiro e idioma/moeda. Essa autorização não aprova por antecipação o design concreto nem planos futuros. A passagem para planejamento e execução continuará dependente dos gates aplicáveis.

O próximo responsável é o humano para o gate; após sua resposta, o dev explora o projeto sem código e o specialist prepara os esclarecimentos e a arquitetura conforme a autoridade recebida.

Fontes: [pedido humano](../1001/r1-human-request.md) e [extração da imagem](../1002/r1-image-evidence.md).
