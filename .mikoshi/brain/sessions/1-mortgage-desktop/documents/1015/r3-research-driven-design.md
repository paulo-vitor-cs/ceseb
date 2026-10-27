---
id: 1015
revision: 3
type: document
tags:
- mortgage
- design-index
- numerical-assurance
- qt
status: versioned
created: '2026-10-26'
updated: '2026-10-26'
description: Revisão concreta do design para decidir centavos e apresentação por aritmética
  exata e propor Qt 6.12.0 oficial.
use_when:
- Aprovar o delta de arquitetura após as pesquisas, preservando a baseline aceita e preparando
  a entrada em planejamento.
---
# Revisão concreta após as pesquisas

Fase **4 — arquitetura**. O [pedido 1022](../1022/r1-resolution-authority.md) solicita resolver os empates numéricos e revisar Qt pelo caminho mais simples. A arquitetura anterior foi aceita em [1017](../1017/r1-design-approval-and-quality-correction.md); seus quatro corpos r1 continuam intactos. As revisões abaixo são propostas completas para esse delta, sem aprovação herdada nem resultado de produto. Os índices [r1](r1-concrete-design-index.md) e [r2](r2-refined-requirement-index.md) permanecem como histórico.

## Proposta recomendada

**Arredondamento:** preservar half-up, as fórmulas e os livros Price/SAC. Guardar a taxa original exatamente e decidir as fronteiras por operações inteiras/racionais usando Boost já previsto. Para a taxa efetiva, comparar potências exatas e usar um intervalo racional somente onde a prestação Price o exige. A decisão do centavo não depende da aproximação decimal, de epsilon nem das seis casas da interface. Não se acrescenta uma escala convencional de taxa mensal.

Caso decisivo: **R$ 0,06, taxa nominal anual de 100%, um mês → R$ 0,01 de juros e R$ 0,07 de pagamento**, em ambos os sistemas. A apresentação também usa half-up explícito: nominal anual 0,000006% → percentual mensal exibido 0,000001%. O contrato cobre o empate e valores dos dois lados; não adapta o oráculo ao formatter da biblioteca.

O método precisa de inteiros grandes, frações, teste de raiz inteira de grau 12 e bisseção. A prova que justifica terminar o refinamento de Price está na [análise 1023](../1023/r1-numerical-resolution.md); ela não exige um motor algébrico no programa. A simplicidade aqui preserva o comportamento prometido sem nova biblioteca. Latência e uso de memória ainda precisam ser medidos nos futuros planos, sobretudo nos limites; terminação matemática não equivale a desempenho observado.

**Qt:** propor **6.12.0 oficial**, kits base **6.12.0-0-202609280346**, preservando Widgets/Fusion, C++20, MSVC 2022/v143 e GCC 13, Windows 11 x64 e Ubuntu 24.04 x64. Há matriz e metadata oficiais, além de HEAD 200 dos dois qtbase; não houve download dos kits. Essa rota evita manter patches próprios ou compilar Qt modificado para iniciar um projeto sem código. A [análise 1024](../1024/r1-qt-baseline-review.md) compara as alternativas e conserva os avisos conhecidos, sem declarar segurança global. A disponibilidade dos kits não comprova integridade, ABI, licenças do pacote ou execução nativa.

## Revisões para aprovação

| Funcionalidade | Baseline aceita, preservada | Proposta concreta | Requisitos de produto |
|---|---|---|---|
| Conversão e origem da taxa | [1008 r1](../../specs/1008/r1-annual-rate-conversion.md) | [1008 r2](../../specs/1008/r2-annual-rate-conversion.md) | 1101 a 1106 |
| Comparação e decisão dos centavos | [1012 r1](../../specs/1012/r1-amortization-comparison.md) | [1012 r2](../../specs/1012/r2-amortization-comparison.md) | 1201 a 1207 |
| Interface e quantização da apresentação | [1013 r1](../../specs/1013/r1-widgets-interface.md) | [1013 r2](../../specs/1013/r2-widgets-interface.md) | 1211 a 1217 |
| Baseline e entrega reproduzível | [1014 r1](../../specs/1014/r1-reproducible-delivery.md) | [1014 r2](../../specs/1014/r2-reproducible-delivery.md) | 1221 e 1225 a 1228 |

As decisões [1025: método exato](../../decisions/1025/r1-exact-rounding-method.md) e [1026: Qt](../../decisions/1026/r1-qt-baseline-choice.md) estão **open**. A [integração 1027](../../decisions/1027/r1-research-design-integration.md) conserva a disposição das relações. O gate diz respeito ao delta concreto acima. Não reabre a escolha por ambas as taxas, Price/SAC ou Widgets.

## Requisitos e ferramentas

Continuam **25 requisitos ativos em draft**, com os níveis e a cobertura listados no [índice de refinamento r2](r2-refined-requirement-index.md). As specs sucessoras reutilizam os requisitos aplicáveis. Foram refinados [1106](../../requirements/1106/r1-unrounded-consumer-rate.md), [1202](../../requirements/1202/r1-price-ledger.md), [1203](../../requirements/1203/r1-sac-ledger.md), [1205](../../requirements/1205/r1-zero-and-single-period.md) e [1212](../../requirements/1212/r1-rate-presentation.md). A decisão 1025 registra os refinamentos dos requisitos ainda não aceitos e seus snapshots: critérios exatos de fronteira e apresentação, com rationale, acceptance criteria, procedimento e oráculo. Nenhum resultado pass ou implemented foi atribuído.

Os requisitos históricos 1222 a 1224 continuam obsolete. Google Test, QtTest, CTest, CI, compiladores e deploy continuam em **tools**, consumidos pelos futuros planos. Foram conciliados os cartões draft [2301](../../tools/2301/r1-cmake-ctest-build.md), [2302](../../tools/2302/r1-googletest-runner.md), [2303](../../tools/2303/r1-qttest-runner.md) e [2306](../../tools/2306/r1-qt-deployment.md): seleção vazia não conta como sucesso, asserções exatas não passam por double e QtTest acompanha o pin Qt proposto. [2304](../../tools/2304/r1-github-actions.md) e [2305](../../tools/2305/r1-native-compilers.md) permanecem aplicáveis. Descrever esses meios não executa comandos de produto.

## Evidência, limites e próximo passo

Os dois especialistas entregam suas análises A1–A5 e os sucessores. O orquestrador integra os retornos, confere metadados/links e preservação dos quatro corpos aceitos, e registra as relações em [evidência de integração](../../evidence/resolution-integration-checks.json). Essas conferências são estruturais e documentais; não são revisão independente de produto nem testes das toolchains.

| Dimensão | Estado desta revisão |
|---|---|
| Maturidade | Quatro sucessoras draft; duas decisões técnicas abertas para resposta humana |
| Planos | Ainda não escritos nem executados |
| Testes de produto e desempenho | Não executados |
| Revisão independente / Synapses | Não iniciados |
| Resultado por requisito | Sem verdict de execução |

**Escolha apresentada:** aprovar estas revisões e o refinamento dos requisitos para preparar os planos, ou indicar ajustes. A primeira opção não instala dependências nem aprova planos futuros. O próximo passo após o aceite é a fase 5, com autores distintos dos planos de testes e de implementação; os planos concretos mantêm seu próprio gate antes de execução. Não houve commit/push deste delta, promoção de knowledge ou publicação de release.
