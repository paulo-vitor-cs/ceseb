---
id: 3004
revision: 1
type: document
tags:
- mortgage
- research
- synthesis
- divergences
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Síntese das três pesquisas com convergências, divergências de métodos,
  condições de distribuição e decisões pendentes do projeto aprovado.
use_when:
- Analisar os resultados FIN, TECH e DIST antes de selecionar correções, validação
  numérica ou revisão da baseline do projeto.
---
# Pesquisa consolidada para análise — Projeto 1

Autor: orquestrador. Data: 2026-10-26, America/Sao_Paulo. Autoridade: [pedido humano 1021 r1](../1021/r1-pending-research-authority.md). Esta síntese integra os três retornos recebidos; não é uma revisão independente de entrega nem um resultado de teste do produto. A arquitetura aprovada permanece preservada.

## Entregas e alcance

| Frente | Compilação | Notas completas em draft | Escopo observado |
|---|---|---|---|
| FIN | [3001 r1](../3001/r1-financial-research-compilation.md) | 3101 a 3105 | Definições, anuidade, livros discretos, comparação e contraevidência financeira |
| TECH | [3002 r1](../3002/r1-technology-research-compilation.md) | 3121 a 3126 | Documentação e código das versões fixadas, precisão, parsing, UI, build e runners |
| DIST | [3003 r1](../3003/r1-distribution-research-compilation.md) | 3141 a 3148 | Acesso a kits, manutenção, runtime, evidência nativa e termos de distribuição |

São três compilações e 19 notas, todas em draft. Foram recebidos os três retornos antes desta síntese. Cada compilação registra estratégia, consultas reais, unidades lidas, acesso, contraevidência, condições e suficiência por pergunta. As contagens não demonstram verdade ou ausência universal de divergências. Os 25 requisitos efetivos e as quatro specs não foram modificados pela pesquisa.

## Mapa de resultados e consequências

| ID | Resultado | Tipo de evidência e limite | Alvos e próximo consumidor |
|---|---|---|---|
| R1 | Conversão nominal/efetiva e anuidade postecipada convergem com as fontes. Os livros Price/SAC são coerentes sob avaliação exata das regras declaradas. | Fontes primárias e dedução algébrica; não é execução da biblioteca. | 1008/1012; 1101 a 1106 e 1201 a 1207. Preservar o modelo aceito. |
| R2 | Precisão decimal finita, guard digits e tolerância da taxa não garantem sozinhos o centavo matemático correto em todo empate. | Lacuna material de garantia; prova da descontinuidade, sem bug de runtime observado. | 1008/1012 e 1102/1106/1202 a 1206. Specialist deve justificar a decisão de fronteira; validação empírica requer plano próprio. |
| R3 | A conversão genérica para texto de Boost 1.86 usa empate para par; 1212 exige half-up. | Divergência de semântica em código-fonte fixado, não falha observada do app. | 1013/1212. O meio de apresentação deverá cumprir o oráculo, sem adaptar o oráculo ao default. |
| R4 | O QDoubleValidator/QLocale padrão não basta para a gramática estrita, agrupamento e dinheiro sem double. | Leitura do pin; não impede usar Qt Widgets com o MoneyCodec já previsto. | 1013/1211/1213/1214; plano do adaptador. Cuidado de implementação, sem troca implícita de GUI. |
| R5 | CTest pode terminar com sucesso sem testes; EXPECT_NEAR converte para double. | Contrato de ferramentas e fontes fixadas, não execução. | Tools 2301 a 2304 e futuros planos: selecionar casos, usar erro em seleção vazia ou conferir contagem, preservar comparação decimal e igualdade inteira de centavos. Não criar requisitos que obriguem ferramentas. |
| R6 | Qt 6.8.3 é acessível e sua matriz inclui os alvos escolhidos, mas não incorpora correções posteriores. O CVE-2025-5992 inclui essa versão. | Convergência da matriz, divergência temporal de manutenção; exposição da calculadora não demonstrada. | 1014/1011 e tool 2306. Humano/specialist precisam avaliar pin, patchset ou revisão de versão; nada foi selecionado automaticamente. |
| R7 | ZIP e DEB com Qt privado são rotas viáveis documentalmente, condicionadas a plugins, ABI, CRT e dependências reais. | Documentação e HEAD de arquivos, sem download/instalação dos kits ou pacote construído. | 1225/1226 e tools 2305/2306. Fechar inventário e ensaio limpo no plano posterior. |
| R8 | A distribuição mantém licenças por componente e fonte Qt correspondente; a edição MSVC/termos CRT efetivos ainda não foram qualificados. | Unidades legais e fonte lidas; Build Tools/CRT com acesso parcial/403. Sem certificação jurídica. | 1228. Responsável pelo toolchain confirma os termos da edição real antes de copiar o runtime. |
| R9 | CI, WSL e offscreen não substituem o desktop-alvo exigido pelo projeto. | Política de aceitação e documentação de ambientes; nenhum runtime local qualificado. | 1215/1216/1226/1227 e tool 2304. Obter evidência separada nas duas plataformas. |

## Duas decisões materiais prioritárias

### 1. Garantia numérica e fronteiras de arredondamento

O caso discriminante é **principal de 6 centavos, taxa nominal anual de 100% e prazo de um mês**. Matematicamente a taxa mensal é 1/12, os juros são 0,5 centavo, o half-up exige 1 centavo de juros e o pagamento final é 7 centavos. Uma aproximação ligeiramente inferior ao empate pode mudar o inteiro arredondado. Isso não afirma qual resultado a expressão concreta do Boost 1.86 produzirá.

A [documentação Boost 1.86](https://www.boost.org/doc/libs/1_86_0/libs/multiprecision/doc/html/boost_multiprecision/tut/floats/cpp_dec_float.html), unidade de guard digits/truncamento, não promete arredondamento financeiro exato em todas essas fronteiras. FIN desenvolve o argumento em [3104](../../knowledge/3104/r1-half-cent-boundaries.md); TECH trata o backend em [3121](../../knowledge/3121/r1-decimal-backend-rounding-boundary.md). Root abriu essa unidade primária para confirmar o limite documental.

Próximo trabalho proposto: justificar um método de decisão das fronteiras e preparar validação limitada nas duas toolchains, com referências independentes exatas para casos racionais. Se a solução alterar a interpretação ou os contratos aceitos, o specialist deverá apresentar a revisão concreta ao humano. Pesquisa não escolhe essa solução nem autoriza o experimento. Um caso isolado que passe não prova o domínio inteiro.

Na apresentação há um caso separado: anual nominal 0,000006% leva ao percentual mensal matemático 0,0000005%. Half-up em seis casas exige 0,000001%; empate para par aplicado à fixture decimal exata produz 0,000000%. A [nota 3126](../../knowledge/3126/r1-explicit-percentage-rounding.md) distingue o formatter isolado do pipeline com divisões anteriores. O programa ainda não foi executado.

### 2. Pin Qt e política de manutenção

O [aviso original CVE-2025-5992](https://lists.qt-project.org/pipermail/development/2025-July/046449.html), de 11 de julho de 2025, inclui Qt 6.8.0 a 6.8.3 em falha de negação de serviço ao processar determinados parâmetros/perfis ICC, e fornece patches. Root leu o corpo do aviso. Isso não demonstra que a futura calculadora alcance o caminho vulnerável, nem é um inventário completo de segurança.

A [nota 3142](../../knowledge/3142/r1-qt-683-patch-security-conditioning.md) separa a versão fixada, LTS comercial e fontes/patches posteriores já públicos. Fixar versão ajuda reprodução; não implica manutenção automática. As opções documentadas são manter o pin com avaliação explícita de alcance/risco, aplicar patchset rastreável ou propor outro pin acessível e corrigido. A pesquisa não escolheu uma opção, não adquiriu licença e não mudou a baseline. A escolha deve anteceder a obtenção/qualificação do kit pertinente.

## Convenções e fontes que não podem ser misturadas

Half-up mensal, distribuição inicial do resto SAC, rejeição de combinações inviáveis em centavos e quitação antecipada Price por arredondamento são convenções próprias. O achado de outras convenções bancárias não é, por si só, um erro. Os casos e invariantes aprovados continuam as referências.

O JSON histórico `amortization-reference-candidate.json` usava outra distribuição SAC; o relatório 1016 já o identifica como candidato. Ele não é um segundo oráculo vigente e não deve ser copiado para testes da política aprovada. O custo do modelo exclui seguros, tarifas, impostos, indexadores e outros custos; não deve ser apresentado como CET ou cotação bancária.

Uma página móvel da série Qt 6.8 pode descrever patch posterior ao 6.8.3; a fonte da tag foi usada onde a versão é decisiva. A ausência de GCC 13 numa lista parcial de compiladores testados do Boost não prova incompatibilidade. Disponibilidade pública de um índice e HEAD 200 não provam integridade, instalação, licença aceita ou funcionamento do kit.

## Ferramentas, leitura e limites

Context7 não foi exposto no catálogo nativo e ctx7 não foi encontrado no PATH. Os scouts registraram essa lacuna e usaram fontes oficiais versionadas/código; não foi simulada uma operação Context7. A consulta lexical do Brain funcionou, mas o índice de grafo permaneceu incompatível com a seleção; os corpos pertinentes foram lidos diretamente. Isso não equivale a cobertura mecânica completa do grafo.

DIST tentou a extração instalada via Pandoc e recebeu unavailable. Leu somente os nós de texto OOXML dos parágrafos relevantes do DOCX Community 2022, sem renderer ou alegação de leitura integral do documento; os termos Build Tools/CRT de outra edição não foram substituídos por esses. A edição real continua pendente. O aviso CVE-2026-107157 teve abertura inacessível; snippets e nome de patch não sustentam uma conclusão sobre o app.

Os autores registraram 6/6, 7/7 e 9/9 checks estruturais dos respectivos artefatos. Depois dos retornos, root ajustou espaçamento editorial em parte dos novos rascunhos, preservando consultas literais, código, URLs, conclusões e fontes. As checagens dos autores são evidência dos seus snapshots; a conferência pós-integração do root é registrada separadamente. Metadados/links não provam a verdade dos claims, resultados de produto, compatibilidade local ou licença de um pacote inexistente.

## Continuação e autoridade

A pesquisa pendente foi entregue em três compilações e 19 notas draft, com leitura, contraevidência e suficiência delimitadas. Há convergência documental e há pontos materiais ainda não resolvidos; não se afirma ausência universal de divergências. O design e os 25 requisitos não foram alterados.

Consumidores seguintes: humano e specialist para analisar R2/R6; autores dos planos para absorver os cuidados R3/R4/R5 e as condições R7/R8/R9. Nenhum experimento, build, teste de produto, instalação, plano de implementação, promoção de knowledge, Synapses ou publicação Git foi iniciado por este retorno.
