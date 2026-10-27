---
id: 3105
revision: 1
type: knowledge
tags:
- mortgage
- amortization
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Bound a fixed-rate Price/SAC comparison to its shared inputs and distinguish its totals from contractual CET or bank payoff quotes.
use_when:
- Explaining simulated Price/SAC interest differences or deciding whether a bank result is comparable to the local model.
---
# Conditions for an interpretable comparison

Comparing simulated Price and SAC requires the same principal, rate convention, monthly normalized rate, requested term, timing, cost exclusions and cent policy. The returned signed total-interest difference is a nominal sum for those cashflows. It does not by itself decide affordability, present value, investment opportunity or the best product for a borrower. If rounding ends Price earlier, the effective duration must also accompany the shared requested term.

The app's total principal plus interest is not a CET. The official [CMN Resolution 4.881/2020 PDF](https://www.bcb.gov.br/content/estabilidadefinanceira/especialnor/Resolu%C3%A7%C3%A3o4881.pdf), articles2-5, dated 2020-12-23, read2026-10-26, consolidates additional contractual costs and specifies annual CET disclosure. Its reference to NBR5891 concerns that disclosure; this note neither reconstructs the standard's text nor imports it as a monthly half-up ledger rule. This is a product scope distinction, not legal-compliance advice or certification of all current amendments.

The [CFPB payoff answer](https://www.consumerfinance.gov/ask-cfpb/what-is-a-payoff-amount-and-is-it-the-same-as-my-current-balance-en-205/), reviewed 2026-08-28, substantive answer read2026-10-26, distinguishes US payoff at a specified date from current principal balance. It includes accrued interest and potentially other amounts. It does not establish Brazilian early-payoff charges. Consequently the simulator's final B+rounded-monthly-interest and automatic early cent stop are not bank payoff quotes.

Counterconditions: daily accrual, inflation correction, irregular dates, fees, insurance, extra payments or different rounding conventions can produce other totals with the same headline annual number. Such differences require matching the full model before alleging an error. BCB technical work on indexed SAC, discussed in [3103 r1](../3103/r1-discrete-sac-invariants.md), shows one concrete excluded mechanism. No empirical banking statement was reproduced locally.

Related: [1012 r1](../../specs/1012/r1-amortization-comparison.md); [1207 r1](../../requirements/1207/r1-comparable-results.md); [FIN source register](../../evidence/research/finance/research-log.md).
