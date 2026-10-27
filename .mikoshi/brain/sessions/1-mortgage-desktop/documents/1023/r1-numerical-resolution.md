---
id: 1023
revision: 1
type: document
tags:
- mortgage
- analysis
- numerics
- rounding
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Analisar A1–A5 e justificar um método exato específico para resolver
  empates Price/SAC e percentuais sem mudar o modelo financeiro.
use_when:
- Revisar a proposta de representação exata e a prova de terminação antes de aprovar
  revisões numéricas ou planejar sua implementação.
---
# Resolução numérica — proposta do specialist

Escopo recebido em 2026-10-26: “Vamos resolver os empates numéricos e revisar a versão do Qt com base nas pesquisas, mantendo o caminho mais simples e seguindo o fluxo da Mikoshi.” Este relatório cobre somente o método numérico na fase 4; Qt é tratado por outra autoria. Aplicados mikoshi-analysis A1–A5, mikoshi-simplicity e mikoshi-decision. Sem implementação, experimento, instalação ou alteração das três r1 aceitas.

## A1 — finalidade, cenário e contraexemplo

Destinatários: humano, orquestrador e futuros autores dos planos. O objetivo é obter os mesmos centavos matemáticos e o texto half-up nas duas plataformas, preservando nominal/efetiva e Price/SAC. Principal 6 centavos, nominal anual 100%, prazo 1 dá m=1/12; juros de meio centavo devem resultar em 1 centavo, pagamento 7. Uma aproximação ligeiramente inferior cruza a fronteira, mesmo que seu erro esteja dentro da tolerância da taxa. É contraexemplo à inferência “taxa próxima implica centavo correto”; não é bug observado do Boost.

Na apresentação, nominal anual 0,000006% implica mensal exata 0,0000005%: mostrar 0,000001%, conforme half-up. A pesquisa separou formatter isolado e pipeline completo; a proposta cobre ambos.

## A2 — autoridade e invariantes preservados

Os pedidos anteriores escolheram ambas as convenções, Price/SAC e Widgets. As specs r1 foram aceitas; o novo pedido autoriza resolver a divergência e preparar revisões concretas, sem aprovar silenciosamente seu corpo. [Decisão 1025 aberta](../../decisions/1025/r1-exact-rounding-method.md) propõe mudar os meios, mantendo domínio, fórmulas, distribuição SAC, quitação Price, tolerâncias de projeção e regras de UI. Sem quantização mensal financeira nova, epsilon ou restrição do domínio tipado às seis casas da GUI.

O dado percentual de origem deve conservar seu decimal finito exato. Um valor já arredondado antes de chegar à API é aquele valor fornecido, não uma promessa de recuperar a intenção anterior. Um construtor rejeita NaN/infinito antes de criar racional. Não há código consumidor legado; os nomes/overloads físicos permanecem trabalho dos planos.

## A3 — decomposição e método concreto

[1008 r2](../../specs/1008/r2-annual-rate-conversion.md) conserva percentual p racional. Nominal: x=1+p/1200 racional. Efetiva: g=1+p/100 racional e x é a raiz positiva de x^12=g. Reduzir g=a/b; testar se numerador e denominador são potências de grau 12 inteiras por raiz inteira e comparação exata. Isso identifica x racional sem fatorar. O teste de raiz de grau 12, e não uma tentativa em precisão finita, decide a classificação.

[1012 r2](../../specs/1012/r2-amortization-comparison.md) continua com dinheiro e somas int64, usando inteiros grandes apenas nos intermediários. Para u/v>=0, `R(u/v)=(2u+v) div (2v)` resolve o half-up exato. No ramo nominal ou efetivo racional, isso basta para juros e anuidade.

No ramo efetivo irracional, decidir cada limiar de juro por `B*(x−1) >= j−1/2` equivalente a `g >= (1+(2j−1)/(2B))^12`. Potências e multiplicação cruzada inteiras resolvem inclusive igualdade; não há necessidade de aproximar a raiz em cada mês.

Price usa em centavos `F(x)=C*x^n/(1+x+...+x^(n−1))`. Em racional x=a/b, avaliar exatamente `C*a^n/(b*Σ a^j*b^(n−1−j))`, evitando cancelamento e tolerância. Para x irracional, iniciar [L,U]=[1,2], refinar por bisseção exata da raiz e avaliar F(L),F(U) como frações. F é estritamente crescente: equivale a C dividido pela soma de x^(-j), j=1..n, cujo denominador decresce. Se ambos os extremos arredondarem ao mesmo centavo, esse é o resultado. O refinamento termina pela prova abaixo.

[1013 r2](../../specs/1013/r2-widgets-interface.md) recebe os três percentuais já quantizados em inteiros de milionésimo de ponto percentual. Percentuais racionais usam divisão half-up; mensal efetiva e nominal anual derivada da raiz usam a mesma comparação de potência 12. Para K=100 ou 1200 e escala s=10^6, `R(s*K*(x−1))>=j` equivale a `x>=1+(2j−1)/(2sK)`. A UI só insere separador e seis dígitos. Não delega o desempate ao formatter de decimal de 50 dígitos e não devolve texto ao cálculo. A projeção decimal aproximada permanece disponível aos requisitos de taxa, sem decidir centavos.

### Por que a bisseção Price não fica presa num empate irracional

Esta é uma dedução do specialist apoiada pelo critério de irreducibilidade de binômios; não é teorema fornecido pelo Boost nem resultado de teste.

Se x>0 e x^12=g racional, existe d divisor de 12 e h racional positivo com polinômio mínimo x^d−h. Para justificar, tomar o menor d entre 1,2,3,4,6,12 para o qual g tem raiz racional de ordem 12/d; se o binômio fosse redutível, o critério de Capelli daria uma potência racional de ordem que divide d e reduziria ainda esse d. A exceção negativa do critério não se aplica a h positivo. Portanto o binômio é irredutível. No ramo irracional d>1.

Suponha F(x)=T racional positivo. Então x anula `C*X^n−T*Σ(j=0..n−1)X^j`.

- Se n<d, esse polinômio não nulo tem grau menor que o mínimo, impossível.
- Se n>=d, reduzir por X^d=h. O termo C*X^n contribui para somente um dos d resíduos. A soma tem coeficiente estritamente positivo em todos os d resíduos, pois inclui os expoentes 0..d−1 e h>0; ao multiplicar por −T, todos esses coeficientes são negativos. Pelo menos um resíduo diferente daquele do numerador permanece não zero. O resto não é zero, contrariando a divisibilidade pelo polinômio mínimo.

Logo F(x) não é racional quando x é irracional. Em particular não é meio-inteiro. Pela continuidade, um intervalo suficientemente estreito tem os mesmos arredondamentos nos dois extremos. Crescimento racional foi tratado por divisão inteira, cobrindo seus empates. O runtime só precisa reconhecer a raiz de grau 12 racional; não precisa construir d, polinômios mínimos, gcd polinomial, fatoração ou uma engine algébrica.

## A4 — comparação sob os mesmos critérios

| Meio | Exatidão nos empates | Mudança de contrato | Custo de manutenção |
|---|---|---|---|
| Decimal50 ou mais dígitos | Proximidade sem prova de fronteira | Nenhuma intenção nova, garantia insuficiente | Baixo, mas não satisfaz o alvo |
| Epsilon fixo | Pode elevar valor legitimamente abaixo do empate | Redefine implicitamente fronteiras | Baixo, sem oráculo defensável |
| Efetiva mensal quantizada em 18 casas + racional | Exata para a convenção quantizada | Muda o centavo-alvo de fronteiras da raiz matemática | Menor que a rota exata, requer nova escolha humana |
| Racional e comparação/refinamento de raiz de grau 12 | Preserva o centavo matemático, com a prova acima | Muda representação/meios, preserva fórmulas | Helpers específicos pequenos e testáveis; custo nativo não medido |

Recomendo a última opção porque cumpre o contrato inteiro sem acrescentar biblioteca. A dependência Boost 1.86 já inclui cpp_int/cpp_rational header-only. O custo adicional é uma classificação por raiz inteira de grau 12, comparadores racionais, potências e bisseção para a única prestação teórica. A escolha mudaria se o humano preferisse formalmente um modelo de taxa quantizada ou se a validação nativa demonstrasse custo operacional incompatível com o produto. Ainda não existe tal evidência; não se escolhe um thread, cache ou otimização especulativa.

## A5 — fontes, contraevidência e limites

Fontes de projeto lidas: síntese 3004; notas 3104, 3121, 3125, 3126; specs aceitas 1008/1012/1013; requisitos 1105/1106/1202/1203/1205/1212; memória local de autoria full-architecture somente como histórico. A pesquisa anterior cobre matemática financeira e observações de biblioteca; suas limitações continuam.

Nova consulta efetivamente executada: `Capelli theorem x^n a irreducible rational positive binomial theorem arxiv`. Fonte primária selecionada e aberta: Koley e Reddy, *Irreducibility of x^n−a*, arXiv:2006.03787v1, 06-06-2020, [HTML versionado](https://arxiv.org/html/2006.03787v1), unidades linhas 16–34, especialmente Theorem 1; também aberto o PDF, primeira página. O critério cobre o binômio positivo racional usado acima; não fornece o algoritmo financeiro ou desempenho. As demais partes da prova deste relatório são dedução própria.

[Manual Boost 1.86 cpp_int](https://www.boost.org/doc/libs/1_86_0/libs/multiprecision/doc/html/boost_multiprecision/tut/ints/cpp_int.html), unidades linhas 8–33, 65–103 e 117: documentação primária versionada confirma tipos de inteiro/racional de precisão arbitrária e operações; não comprova que uma implementação futura seja correta ou rápida. Não houve download/instalação de Boost, compilação, script de cálculo, experimento ou teste de produto. Os scripts locais desta autoria apenas escreveram/verificaram documentos e snapshots.

Terminação matemática não é limite de tempo ou memória. Entrada decimal finita arbitrariamente longa ou com expoente extremo pode custar muito mais que os casos da GUI; o contrato lógico não recebe uma nova limitação escondida. Os planos devem declarar representação física e condições de recurso, exercer percentuais tipados pequenos, raiz racional com mais de seis casas, vizinhanças de empate, limites C/n e ambas as toolchains. Não podem converter ausência de qualificação em pass. Não há tolerância monetária, relaxamento silencioso ou resultado parcial em falha.

## Artefatos, incidências e próximo passo

Criados: decisão 1025 aberta e specs 1008/1012/1013 r2 draft. Refinados somente cinco requisitos ainda draft: 1106, 1202, 1203, 1205 e 1212; preservados template, rationale, nível, acceptance criteria e rastreio. Os critérios novos incluem fronteira 6 centavos/100%, vizinhanças 5,999999/6/6,000001%, Price 3 centavos/zero/2 e os empates de apresentação. Nenhuma obrigação de ferramenta foi criada em requisitos.

Snapshot anterior: [numeric-preimages.json](../../evidence/numeric-preimages.json). Inventário das referências textuais às três specs antigas: [numeric-incident-edges.json](../../evidence/numeric-incident-edges.json), com destino e disposição por fonte. Esse é rastreio de texto nos corpora selecionados, não um grafo semântico certificado; índices incompatíveis anteriores continuam um limite. Referências históricas são preservadas, e os sucessores se relacionam aos requisitos mantidos. Nenhum plano de engenharia existe para ser reescrito.

Próximo responsável: orquestrador, para integrar Qt/numérico e apresentar o conjunto candidato ao humano no gate da fase 4. A aprovação anterior cobre as r1; esta proposta não herda aprovação das r2. Depois da decisão concreta, autores distintos preparam planos de implementação e testes; as execuções exigem a autoridade aplicável aos planos. Não há resultado pass/fail de requisito, implementação, publicação Git, promoção de knowledge ou Synapses neste retorno.
