---
id: 1012
revision: 2
type: spec
tags:
- mortgage
- financial-core
- amortization
status: implemented
created: '2026-10-26'
updated: 2026-10-27
description: Comparar Price e SAC com as mesmas políticas de centavos e decidir seus arredondamentos
  por aritmética exata.
use_when:
- Definir e verificar os livros Price/SAC com decisão exata de centavos e quitação integral.
---
# Comparação monetária Price e SAC

Revisão candidata de [1012 r1 aceita](r1-amortization-comparison.md), preservada. Delta de meios e aprovação pendente: [1025](../../decisions/1025/r1-exact-rounding-method.md). Base humana: [1005](../../documents/1005/r1-human-scope-approval.md). Políticas herdadas do design aceito: [decisão 1011](../../decisions/1011/r1-complete-design-basis.md). Uma funcionalidade: produzir uma comparação local dos dois sistemas para a mesma simulação.

## Fronteira e dados

Operação pura e síncrona `compare(LoanInput) -> Comparison | CalculationError`. `LoanInput` contém `principal_cents:int64`, `term_months:int`, `AnnualRate` da [spec 1008](../1008/r2-annual-rate-conversion.md). A comparação normaliza uma vez a taxa e fornece a mesma taxa mensal integral aos dois cálculos. Sem Qt, rede, conta, credencial, banco de dados ou relógio de calendário.

Proposta de domínio: principal 1..10.000.000.000 centavos (R$ 0,01..100.000.000,00), prazo 1..600 meses, taxa anual conforme 1008. Primeiro vencimento ao final do primeiro mês; pagamentos mensais postecipados; períodos iguais. Sem carência, entrada, aportes extras, indexadores, inflação, seguros, tarifas ou impostos. O total é principal mais juros deste modelo, não CET.

`ScheduleSummary` contém sistema, prazo solicitado, quantidade efetiva de pagamentos, primeira/última prestação, parcela ordinária Price, totais de principal/juros/pagamentos e indicador de liquidação antes do prazo por centavos. Um livro interno temporário de até 600 linhas `{period, opening_balance, interest, principal_paid, payment, closing_balance}` sustenta somas e testes. Não é uma tabela de UI nem um arquivo persistido. `Comparison` reúne as duas saídas, equivalências da taxa e diferença assinada `Price.interest - SAC.interest`. Uma falha em qualquer modelo retorna erro sem comparação parcial.

## Matemática e política monetária proposta

Taxas preservam a origem e o descritor exatos de 1008 r2. Inteiros grandes e frações exatas usam Boost.Multiprecision já presente na baseline; decimal 50 não decide centavos. Valores monetários finais e somas continuam int64 de centavos, com conversão verificada. Para z>=0 em centavos, `R(z)=floor(z+0.5)`: half-up inclusive empates. A taxa não é quantizada para a apresentação nem para uma escala mensal convencional. O método exato abaixo implementa as mesmas fórmulas e livros.

Se P é o principal em reais, n o prazo solicitado e m a taxa mensal decimal, a prestação teórica Price é `A=P/n` para m=0 e `A=P*m/(1-(1+m)^(-n))` para m>0. A fórmula é a inversão da anuidade postecipada apresentada pelo [BCB](https://www3.bcb.gov.br/CALCIDADAO/publico/exibirMetodologiaFinanciamentoPrestacoesFixas.do?method=exibirMetodologiaFinanciamentoPrestacoesFixas). O livro em centavos abaixo é política explícita deste simulador, não política atribuída ao BCB ou à imagem.

Price: `a=R(100*A)`. Com saldo de abertura B em centavos, juros do mês `I=R(B*m)`. Nos meses k<n, `payment=min(a,B+I)`; no mês k=n, `payment=B+I`. `principal_paid=payment-I`; novo saldo `B-principal_paid`. Ao zerar o saldo, encerrar o livro imediatamente; não criar parcelas negativas nem pagamentos futuros zero. Assim as prestações ordinárias são a, a última quita exatamente o saldo e pode ser diferente de a. A quantidade efetiva pode ser menor que n por arredondamento. A GUI exibe esse fato e os dois prazos.

SAC: `q=principal_cents div n`, `r=principal_cents mod n`. Amortização do principal no mês k é `q+1` se k<=r, e q nos demais. Sobre cada saldo de abertura, `I=R(B*m)`; prestação é amortização+I. Os centavos indivisíveis são distribuídos no início. O principal amortizado difere no máximo um centavo entre meses; as prestações são não crescentes. A igualdade matemática P/n é aproximada por essa distribuição explícita, não por uma última amortização desproporcional.

Admissibilidade de centavos: se principal_cents<n, retornar `UnsupportedCentPrecision`, pois SAC não consegue amortizar ao menos um centavo em cada mês. Se a prestação Price a for <= ao primeiro juro `R(principal_cents*m)`, retornar o mesmo erro, pois a parcela ordinária não amortiza sequer um centavo. Nenhum piso monetário arbitrário adicional é usado. A interface explica como ajustar valor/prazo/taxa. Outros erros: `PrincipalOutOfRange`, `TermOutOfRange` e erros de 1008; entradas inválidas não produzem saídas. Limites mantêm somas conservadoramente abaixo de 10^12 centavos; qualquer conversão aritmética fora de int64 retorna `ArithmeticError`, sem resultado parcial.

## Método de decisão de centavos

Para fração não negativa u/v, v>0, usar `R(u/v)=(2u+v) div (2v)` com inteiros exatos. Para taxa nominal e para crescimento efetivo racional, cada juro Bm e a prestação teórica são frações; a divisão inteira resolve qualquer empate, inclusive divisões recorrentes.

No ramo efetivo irracional, juros continuam decididos sem raiz aproximada. Para inteiro j>=1, `R(B*(x−1))>=j` equivale a `g >= (1+(2j−1)/(2B))^12`, comparado por multiplicação cruzada inteira. Buscar o maior j permitido dentro de 0..B: o domínio aprovado implica m<1, logo esse teto basta. Igualdade inclui o valor superior, conforme half-up. B=0 tem juros zero, sem divisão. A comparação é exata mesmo no empate e não requer loop de precisão para cada linha.

A prestação Price teórica em centavos pode ser escrita `F(x)=C*x^n / S_n(x)`, `S_n(x)=1+x+...+x^(n−1)`. Essa forma usa somas positivas e vale também em x=1, onde F=C/n; evita o cancelamento de `1−(1+m)^−n`. Para racional x=a/b, a>=b>0, avaliar exatamente `F=C*a^n / (b*Σ(j=0..n−1) a^j*b^(n−1−j))`, por potências inteiras e somas, e arredondar pela divisão acima.

Somente para x efetivo irracional: conservar limites racionais L<=x<=U, inicialmente [1,2] porque g está em [1,2]. Bisseção decide de que lado está a raiz por comparar o ponto médio elevado à potência 12 com g. F é contínua e estritamente crescente para C>0,n>=1: `F=C / Σ(j=1..n)x^(−j)` e o denominador decresce. Avaliar os dois extremos como frações exatas. Quando `R(F(L))=R(F(U))`, esse inteiro é a prestação ordinária. Caso contrário refinar o mesmo intervalo. Não usar limite fixo de dígitos para aceitar uma resposta incerta.

O refinamento termina matematicamente: se x é irracional e x^12 racional positivo, F(x) não é racional, portanto não pode ser um meio-inteiro. A prova de redução no binômio mínimo está em [1023](../../documents/1023/r1-numerical-resolution.md). Crescimentos racionais foram separados antes e seus empates são decididos pela divisão inteira. O runtime não precisa fatorar inteiros, construir polinômios mínimos, executar gcd polinomial ou usar biblioteca algébrica. Uma raiz inteira 12 para classificar e uma bisseção para a prestação bastam. Reutilizar a origem normalizada em ambos os sistemas.

A terminação matemática não estabelece latência ou memória aceitáveis. O esforço depende também da representação de entrada e da proximidade da fronteira, além dos 600 períodos. Os planos posteriores deverão avaliar o desempenho dos casos GUI e dos pequenos percentuais tipados, nas duas toolchains, antes de declarar a entrega funcional. Nenhum benchmark foi executado. Falha de recurso/aritmética nunca autoriza escolher um centavo arbitrário ou entregar comparação parcial.

## Vetores normativos preservados

Os vetores abaixo vêm da r1 aceita e foram originalmente apoiados por cálculo independente em Python Decimal 60. Estão preservados como oráculos do modelo. Esse cálculo exploratório não prova todas as fronteiras; a justificação do novo método está acima. Não houve teste de produto. A taxa m=0,01 corresponde à entrada nominal anual 12%.

| Entrada (reais; taxa mensal; meses) | Price: regular / última / quantidade / total / juros | SAC: primeira / última / quantidade / total / juros |
|---|---|---|
| 1.200,00;0;12 |100,00 /100,00 /12 /1.200,00 /0,00 |100,00 /100,00 /12 /1.200,00 /0,00 |
| 1.000,00;0,01;3 |340,02 /340,03 /3 /1.020,07 /20,07 |343,34 /336,66 /3 /1.020,00 /20,00 |
| 100.000,00;0,01;12 |8.884,88 /8.884,85 /12 /106.618,53 /6.618,53 |9.333,34 /8.416,66 /12 /106.500,00 /6.500,00 |
| 1.000,00;0;600 |1,67 /1,34 /599 /1.000,00 /0,00 |1,67 /1,66 /600 /1.000,00 /0,00 |
| 0,01;0;600 | `UnsupportedCentPrecision`, nenhuma comparação | Mesmo erro da comparação |

Para 1.000,00;1%;3, o livro Price `(juros,amortização,pagamento,saldo)` é `(10,00;330,02;340,02;669,98)`, `(6,70;333,32;340,02;336,66)`, `(3,37;336,66;340,03;0)`. No SAC: `(10,00;333,34;343,34;666,66)`, `(6,67;333,33;340,00;333,33)`, `(3,33;333,33;336,66;0)`. Empate half-up: principal 1,00, nominal anual 6%, prazo 1 => juros 0,01 e pagamento 1,01 nos dois sistemas.

## Invariantes, recuperação e rastreamento

Cada linha satisfaz em centavos: opening-closing=principal_paid; payment=principal_paid+interest; principal_paid>0; closing>=0. Somatório principal_paid=principal inicial; saldo final 0; total=sum(payment)=principal+sum(interest). Price possui 1..n pagamentos; SAC possui n. Alterar somente apresentação não muda os resultados. Comparação não declara universalmente que um sistema é melhor; retorna diferença numérica assinada.

O estado pertence à chamada, sem concorrência interna. Falha descarta o livro; outra chamada válida não herda dados. No fechamento da janela não há operação externa para cancelar. Responsabilidades pretendidas: módulo de amortização do núcleo e consumidor controlador da [UI 1013](../1013/r2-widgets-interface.md); arquivos concretos e tarefas pertencem aos planos futuros.

Requisitos: [1201](../../requirements/1201/r1-loan-domain.md), [1202](../../requirements/1202/r1-price-ledger.md), [1203](../../requirements/1203/r1-sac-ledger.md), [1204](../../requirements/1204/r1-money-invariants.md), [1205](../../requirements/1205/r1-zero-and-single-period.md), [1206](../../requirements/1206/r1-cent-precision-errors.md), [1207](../../requirements/1207/r1-comparable-results.md). Sucessor ainda draft; nenhum plano, implementação ou verdict de teste.


## Vetores de fronteira acrescentados pela pesquisa

Além de todos os vetores anteriores preservados: principal 6 centavos, nominal anual 100%, n=1 => juros 1 centavo, pagamento 7 centavos nos dois sistemas. Principal 100 centavos, n=1, nominal anual 5,999999% / 6% / 6,000001% => juros 0 / 1 / 1 centavo e pagamento 100 / 101 / 101 centavos. Principal 3 centavos, taxa zero, n=2 => parcela ordinária Price 2 centavos e pagamentos [2;1]; SAC também [2;1]. No domínio tipado, p=100*((201/200)^12−1) efetivo é decimal finito válido, com m=1/200; principal 100 centavos e n=1 deve dar 1 centavo de juros e 101 de pagamento. Essa fixture deve ser construída exatamente antes da chamada, sem double e sem reduzir p às seis casas da GUI. São deduções analíticas da política, não resultados executados.
