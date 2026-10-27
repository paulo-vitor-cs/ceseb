---
id: 3102
revision: 1
type: knowledge
tags:
- mortgage
- amortization
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Explain why a theoretical end-period annuity does not uniquely prescribe a rounded cent ledger or final payment policy.
use_when:
- Selecting an oracle for rounded Price installments or reconciling different final installments between financial tools.
---
# A real annuity and a cent ledger are different contracts

The equal end-period annuity has present value P=A sum(k=1..n)(1+m)^(-k). For m>0 inversion gives A=Pm/[1-(1+m)^(-n)]. At m=0 its continuous extension is P/n. For n=1 the payment is P(1+m). This is exact algebra before any monetary rounding.

BCB's [fixed-payment methodology](https://www3.bcb.gov.br/CALCIDADAO/publico/exibirMetodologiaFinanciamentoPrestacoesFixas.do?method=exibirMetodologiaFinanciamentoPrestacoesFixas), whole short body/formula alt text, and [calculator help](https://www.bcb.gov.br/pec/calculo/calc_financiamento/Default.asp?frame=1), accessed 2026-10-26, identify monthly compound financing and a first payment after inception. They do not prescribe the simulator's cent state transition.

A discrete ledger must additionally name when interest, payment and balance are rounded, how the final balance is cleared, and whether payoff may precede the requested last period. The approved simulator rounds monthly interest on the integer opening balance and clears remaining principal plus interest at its final payment. A different documented approach retains unrounded internal balances and adjusts displayed principal/interest pennies: [Business Math Abridged, institutional export](https://openlibrary-repo.ecampusontario.ca/jspui/bitstream/123456789/1081/1/Business-Math-A-Step-by-Step-Handbook-Abridged-1645549112.-htmlbook.html),13.2 method and13.3 “Missing Penny”, based on Olivier/Lyryx2021B, accessed 2026-10-26. These policies can produce different row values without an algebraic error.

Counterevidence: [Earnest's first-party help](https://help.earnest.com/hc/en-us/articles/219178257-Why-Is-the-Total-Balance-on-My-Loan-Less-Than-the-Total-Sum-of-My-Minimum-Payments-Repaying-Your-Loan), substantive answer, undated, accessed 2026-10-26, describes daily accrual and minimum payments rounded upward, then a reduced last payment. It is a documented lender convention, not observed engine behavior or a universal BRL rule. Dancy's [2023 adapted chapter 3.3](https://ecampusontario.pressbooks.pub/finmath1175/chapter/3-3-calculating-the-final-payment/) discusses final adjustment but has arithmetic/table inconsistencies in example 3.3.1; do not copy that numerical example.

Use a complete policy as oracle. No cited source proves all banks use half-up, guarantees an identical final installment across products, or authorizes changing the accepted simulator policy. No local calculation or runtime was executed for this note.

Related: [1012 r1](../../specs/1012/r1-amortization-comparison.md); [source register](../../evidence/research/finance/research-log.md).
