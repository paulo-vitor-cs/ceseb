---
id: 3104
revision: 1
type: knowledge
tags:
- mortgage
- interest-rates
- amortization
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Show why an absolute rate accuracy tolerance or finite decimal precision alone cannot guarantee exact half-up cents at rounding boundaries.
use_when:
- Assessing numerical guarantees for exact money rounding after nominal or effective rate normalization.
---
# Exact cents need rounding-boundary reasoning

The function R(x)=floor(x+0.5) for nonnegative cent amounts is discontinuous at every x=j+0.5. Any downward perturbation at that exact tie produces a lower integer. Therefore arbitrarily small absolute error alone does not guarantee the exact mathematical half-up result.

Discriminating admissible case from [1008 r1](../../specs/1008/r1-annual-rate-conversion.md) and [1012 r1](../../specs/1012/r1-amortization-comparison.md): C=6 cents, nominal annual percent 100, n=1. Exact m=100/1200=1/12. Interest is C m=1/2 cent, so R(C m)=1 cent; final payment is7 cents in both systems. A hypothetical represented monthly value m-epsilon gives C(m-epsilon)=0.5-6epsilon and R=0 for any sufficiently small epsilon>0. This is an analytic counterexample to a guarantee based solely on closeness, not an observation about a specific backend result.

The existing R$ 1/nominal 6%/one-month tie uses terminating m=.005. It does not discriminate nonterminating division. At maximum opening principal10^10 cents, monthly rate error10^-12 corresponds to interest error up to.01 cent before rounding. Even that bound cannot certify a tie decision. Preserving the numeric rate rather than reparsing its displayed text removes one error source; it does not make an irrational or recurring rate exact.

Derivation basis: the source-defined nominal conversion is consistent with ENAP 2015 [Unidade1 sections 1.4-1.6](https://repositorio.enap.gov.br/bitstream/1/2704/1/Unidade%201%20-%20Taxa%20de%20Juros.pdf), accessed 2026-10-26. Half-up and exact cent behavior are approved local conventions. The proof above is scout-authored mathematical reasoning, with no new script, benchmark or product experiment.

Limits and contrary possibilities: an actual implementation can round this case correctly through representation details, guard digits, exact rational operations or explicit boundary handling. Hence this note does not assert a Boost 1.86 runtime bug or prove failure on any pinned build. TECH owns backend evidence. A future authorized check should identify exact build/operations and compare this and neighboring cases against exact rational expected cents; successful isolated examples would still not prove every domain input.

Related: [1102 r1](../../requirements/1102/r1-nominal-monthly.md); [1205 r1](../../requirements/1205/r1-zero-and-single-period.md); [FIN compilation](../../documents/3001/r1-financial-research-compilation.md).
