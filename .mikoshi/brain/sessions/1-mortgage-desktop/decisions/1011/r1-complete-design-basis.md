---
id: 1011
revision: 1
type: decision
tags:
- mortgage
- design
- decision
status: decided
created: '2026-10-26'
updated: '2026-10-26'
description: Escolhas humanas e propostas técnicas atribuídas para cálculo monetário,
  interface Widgets e entrega nas duas plataformas.
use_when:
- Revisar as escolhas concretas antes de aceitar o design e entrar em planejamento.
---
# Base concreta do design completo

Autor: specialist-full-architecture. Fonte de autoridade: [pedido1001](../../documents/1001/r1-human-request.md) e [emendas1005](../../documents/1005/r1-human-scope-approval.md). Estado open: a seleção humana dos recursos é conhecida; as propostas abaixo aguardam revisão do design concreto. Este registro foi escrito antes dos corpos dependentes.

| Problema | Escolha e origem | Alternativa e razão |
|---|---|---|
| Escopo funcional | Humano: nominal e efetiva; Price e SAC comparados; Qt 6 Widgets/C++ | Price somente e QML foram alternativas apresentadas; a resposta mais recente escolheu a interface mais simples, sem retirar os dois sistemas |
| Idioma/moeda | Proposta: pt-BR e BRL, sem seletor de moeda | Inglês/USD ou múltiplas moedas ampliam textos e formatos. pt-BR segue o idioma da conversa, sem atribuir essa escolha ao humano |
| Fronteira | Proposta: um núcleo C++ sem Qt, um adaptador/controlador Qt e uma janela Widgets | Camadas de serviços, banco, rede e plugins não atendem necessidade adicional deste recorte |
| Domínio | Proposta: principal de 1 a 10.000.000.000 centavos; prazo inteiro de 1 a 600 meses; entrada anual 0..100%, até seis casas na GUI | O máximo cobre simulações amplas e limita trabalho/overflow. Não é teto de crédito ou promessa de todos os contratos. Casos incompatíveis com centavos retornam erro definido |
| Dinheiro | Proposta: livro de saldos, juros e pagamentos em int64 de centavos; juros mensais half-up; quitação com limite de saldo | Arredondar somente o total deixa a soma das parcelas sem reconciliação. Fingir prazo exato após quitar cria saldos negativos |
| Decimal | Proposta: Boost.Multiprecision cpp_dec_float_50 para taxas e anuidade, com entradas construídas de texto decimal | double simplifica dependências, mas torna mais frágil a decisão em meio centavo. O backend proposto é header-only, sem biblioteca dinâmica extra; 50 casas não é alegação de aritmética real exata ou certificação universal |
| Price | Proposta: parcela ordinária arredondada; limite de quitação antecipada por centavos; ajuste final no prazo máximo; exibir quantidade efetiva | Ajustar apenas a última parcela solicitada pode criar saldo negativo antes dela. Nenhuma quitação antecipada será ocultada |
| SAC | Proposta: quociente inteiro de centavos mais um centavo nas primeiras parcelas correspondentes ao resto | Concentrar todo o resto na última amortização pode fazer a última prestação subir. A distribuição escolhida mantém amortizações e prestações não crescentes |
| UI | Proposta: formulário, equivalências e dois cartões; Fusion, layouts e estilos simples | QML, gráficos e cronograma mensal visível adicionam superfícies que não foram solicitadas |
| Build e distribuição | Proposta: C++20, CMake >=3.28, Qt 6.8.3, Boost 1.86.0, Google Test 1.17.0; Windows 11 x64/MSVC 2022 e Ubuntu 24.04 x64/GCC13 | Versões diferentes são futuras alterações controladas. Esta baseline é escolhida para reprodutibilidade, sem alegar que seja a mais recente |
| Licença | Proposta: MIT para código e documentação originais; Qt dinâmico sob LGPLv3 e avisos/licenças dos terceiros | Não selecionar uma licença deixa reutilização indefinida. Licenças de dependências não viram MIT. A aplicação da licença e a distribuição ficam para planos aprovados |

Consequências monetárias, vetores e falhas estão na [spec1012](../../specs/1012/r1-amortization-comparison.md). UI na [1013](../../specs/1013/r1-widgets-interface.md), entrega na [1014](../../specs/1014/r1-reproducible-delivery.md). Não há código, instalação, plano ou aceite nesta decisão.

Integração das fontes: todos os corpos anteriores envolvidos são rascunhos não aceitos; edições necessárias de1006/1007/1008 usam a mesma revisão1. Requisitos1101..1106 permanecem com seus corpos e oráculos. As ligações anteriores entre1007,1008,1101..1106 e1005 são retidas. Novas ligações conectam o núcleo de taxas à comparação, GUI e entrega; não há predecessor publicado ou plano a reescrever. A descoberta1003 e os relatórios anteriores ficam preservados como retratos históricos, sem tratar suas opções antigas como escolhas atuais.

Fontes primárias consultadas em2026-10-26: [Boost decimal50](https://www.boost.org/doc/libs/1_86_0/libs/multiprecision/doc/html/boost_multiprecision/tut/floats/cpp_dec_float.html); [plataformas Qt6.8](https://doc.qt.io/qt-6.8/supported-platforms.html); [arquivo Qt6.8.3](https://download.qt.io/archive/qt/6.8/6.8.3/); [Google Test1.17](https://github.com/google/googletest/releases/tag/v1.17.0); [MIT](https://opensource.org/license/mit). Esses documentos sustentam capacidades e versões, não resultados deste projeto.
