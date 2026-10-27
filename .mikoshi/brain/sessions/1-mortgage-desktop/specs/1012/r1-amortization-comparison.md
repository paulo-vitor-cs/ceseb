---
id: 1012
revision: 1
type: spec
tags:
- mortgage
- financial-core
- amortization
status: superseded
created: '2026-10-26'
updated: '2026-10-26'
description: Modelo discreto em centavos para comparar Price e SAC com mesma entrada, quitação
  explícita e totais reconciliados.
use_when:
- Definir ou testar parcelas, juros, liquidação e comparação dos dois sistemas de amortização.
---
# Comparação monetária Price e SAC

Base humana: [1005](../../documents/1005/r1-human-scope-approval.md). Políticas propostas para aprovação: [decisão1011](../../decisions/1011/r1-complete-design-basis.md). Uma funcionalidade: produzir uma comparação local dos dois sistemas para a mesma simulação.

## Fronteira e dados

Operação pura e síncrona `compare(LoanInput) -> Comparison | CalculationError`. `LoanInput` contém `principal_cents:int64`, `term_months:int`, `AnnualRate` da [spec1008](../1008/r1-annual-rate-conversion.md). A comparação normaliza uma vez a taxa e fornece a mesma taxa mensal integral aos dois cálculos. Sem Qt, rede, conta, credencial, banco de dados ou relógio de calendário.

Proposta de domínio: principal1..10.000.000.000 centavos (R$0,01..100.000.000,00), prazo1..600 meses, taxa anual conforme1008. Primeiro vencimento ao final do primeiro mês; pagamentos mensais postecipados; períodos iguais. Sem carência, entrada, aportes extras, indexadores, inflação, seguros, tarifas ou impostos. O total é principal mais juros deste modelo, não CET.

`ScheduleSummary` contém sistema, prazo solicitado, quantidade efetiva de pagamentos, primeira/última prestação, parcela ordinária Price, totais de principal/juros/pagamentos e indicador de liquidação antes do prazo por centavos. Um livro interno temporário de até600 linhas `{period, opening_balance, interest, principal_paid, payment, closing_balance}` sustenta somas e testes. Não é uma tabela de UI nem um arquivo persistido. `Comparison` reúne as duas saídas, equivalências da taxa e diferença assinada `Price.interest - SAC.interest`. Uma falha em qualquer modelo retorna erro sem comparação parcial.

## Matemática e política monetária proposta

Taxas e avaliação da fórmula usam `cpp_dec_float_50`, construído de texto decimal, sem passagem por double. Valores monetários são int64 de centavos. Para x>=0 em centavos, `R(x)=floor(x+0.5)`: arredondamento half-up, inclusive empates. Não se arredonda a taxa para as seis casas da apresentação.

Se P é o principal em reais, n o prazo solicitado e m a taxa mensal decimal, a prestação teórica Price é `A=P/n` para m=0 e `A=P*m/(1-(1+m)^(-n))` para m>0. A fórmula é a inversão da anuidade postecipada apresentada pelo [BCB](https://www3.bcb.gov.br/CALCIDADAO/publico/exibirMetodologiaFinanciamentoPrestacoesFixas.do?method=exibirMetodologiaFinanciamentoPrestacoesFixas). O livro em centavos abaixo é política explícita deste simulador, não política atribuída ao BCB ou à imagem.

Price: `a=R(100*A)`. Com saldo de abertura B em centavos, juros do mês `I=R(B*m)`. Nos meses k<n, `payment=min(a,B+I)`; no mês k=n, `payment=B+I`. `principal_paid=payment-I`; novo saldo `B-principal_paid`. Ao zerar o saldo, encerrar o livro imediatamente; não criar parcelas negativas nem pagamentos futuros zero. Assim as prestações ordinárias são a, a última quita exatamente o saldo e pode ser diferente de a. A quantidade efetiva pode ser menor que n por arredondamento. A GUI exibe esse fato e os dois prazos.

SAC: `q=principal_cents div n`, `r=principal_cents mod n`. Amortização do principal no mês k é `q+1` se k<=r, e q nos demais. Sobre cada saldo de abertura, `I=R(B*m)`; prestação é amortização+I. Os centavos indivisíveis são distribuídos no início. O principal amortizado difere no máximo um centavo entre meses; as prestações são não crescentes. A igualdade matemática P/n é aproximada por essa distribuição explícita, não por uma última amortização desproporcional.

Admissibilidade de centavos: se principal_cents<n, retornar `UnsupportedCentPrecision`, pois SAC não consegue amortizar ao menos um centavo em cada mês. Se a prestação Price a for <= ao primeiro juro `R(principal_cents*m)`, retornar o mesmo erro, pois a parcela ordinária não amortiza sequer um centavo. Nenhum piso monetário arbitrário adicional é usado. A interface explica como ajustar valor/prazo/taxa. Outros erros: `PrincipalOutOfRange`, `TermOutOfRange` e erros de1008; entradas inválidas não produzem saídas. Limites mantêm somas conservadoramente abaixo de10^12 centavos; qualquer conversão aritmética fora de int64 retorna `ArithmeticError`, sem resultado parcial.

## Vetores normativos candidatos

Valores abaixo são centavos exatos para esta política, calculados independentemente em Python Decimal60; não houve teste de produto. A taxa m=0,01 corresponde à entrada nominal anual12%.

| Entrada (reais; taxa mensal; meses) | Price: regular / última / quantidade / total / juros | SAC: primeira / última / quantidade / total / juros |
|---|---|---|
| 1.200,00;0;12 |100,00 /100,00 /12 /1.200,00 /0,00 |100,00 /100,00 /12 /1.200,00 /0,00 |
| 1.000,00;0,01;3 |340,02 /340,03 /3 /1.020,07 /20,07 |343,34 /336,66 /3 /1.020,00 /20,00 |
| 100.000,00;0,01;12 |8.884,88 /8.884,85 /12 /106.618,53 /6.618,53 |9.333,34 /8.416,66 /12 /106.500,00 /6.500,00 |
| 1.000,00;0;600 |1,67 /1,34 /599 /1.000,00 /0,00 |1,67 /1,66 /600 /1.000,00 /0,00 |
| 0,01;0;600 | `UnsupportedCentPrecision`, nenhuma comparação | Mesmo erro da comparação |

Para1.000,00;1%;3, o livro Price `(juros,amortização,pagamento,saldo)` é `(10,00;330,02;340,02;669,98)`, `(6,70;333,32;340,02;336,66)`, `(3,37;336,66;340,03;0)`. No SAC: `(10,00;333,34;343,34;666,66)`, `(6,67;333,33;340,00;333,33)`, `(3,33;333,33;336,66;0)`. Empate half-up: principal1,00, nominal anual6%, prazo1 => juros0,01 e pagamento1,01 nos dois sistemas.

## Invariantes, recuperação e rastreamento

Cada linha satisfaz em centavos: opening-closing=principal_paid; payment=principal_paid+interest; principal_paid>0; closing>=0. Somatório principal_paid=principal inicial; saldo final0; total=sum(payment)=principal+sum(interest). Price possui1..n pagamentos; SAC possui n. Alterar somente apresentação não muda os resultados. Comparação não declara universalmente que um sistema é melhor; retorna diferença numérica assinada.

O estado pertence à chamada, sem concorrência interna. Falha descarta o livro; outra chamada válida não herda dados. No fechamento da janela não há operação externa para cancelar. Responsabilidades pretendidas: módulo de amortização do núcleo e consumidor controlador da [UI1013](../1013/r1-widgets-interface.md); arquivos concretos e tarefas pertencem aos planos futuros.

Requisitos: [1201](../../requirements/1201/r1-loan-domain.md), [1202](../../requirements/1202/r1-price-ledger.md), [1203](../../requirements/1203/r1-sac-ledger.md), [1204](../../requirements/1204/r1-money-invariants.md), [1205](../../requirements/1205/r1-zero-and-single-period.md), [1206](../../requirements/1206/r1-cent-precision-errors.md), [1207](../../requirements/1207/r1-comparable-results.md). Somente rascunho; nenhum plano, implementação ou verdict de teste.
