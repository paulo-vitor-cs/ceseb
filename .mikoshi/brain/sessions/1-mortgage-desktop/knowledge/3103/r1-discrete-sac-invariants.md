---
id: 3103
revision: 1
type: knowledge
tags:
- mortgage
- amortization
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Establish cent conservation and nonincreasing payments for SAC with its integer remainder allocated to the first periods.
use_when:
- Reasoning about the approved discrete SAC model or distinguishing its rounding policy from indexed mortgage practice.
---
# Discrete SAC with an early remainder

Let C be positive integer principal cents and1<=n<=C. Define q=C div n, r=C mod n. Principal payment d_k=q+1 for k<=r and q otherwise. Then every d_k>=1, sum d_k=nq+r=C, principal components differ by at most one cent, and d_k is nonincreasing. With opening balance B_k, fixed m>=0 and monotone rounding R(x)=floor(x+0.5), interest I_k=R(B_k m) is nonincreasing because B_k decreases. Thus d_k+I_k is nonincreasing. After exactly n payments balance is zero. This is a direct proof from the simulator's adopted definition, not an empirical finding.

The real-valued SAC idea is fixed principal amortization and interest on remaining balance. Gilneu Francisco Astolfi Vivan, [BCB Nota Técnica56](https://www.bcb.gov.br/content/publicacoes/notastecnicas/NT_56_202510.pdf), October2025, “Adaptando o Sistema de Amortizações Constantes—SAC”, PDF pages 15-17, accessed 2026-10-26, explains that mechanism. It does not prescribe this early remainder distribution.

Countercondition: that paper explicitly explains that inflation-indexed SAC installments can increase. Its setting adds indexation to the balance. This does not contradict the proof for fixed nonnegative m, no indexation and the adopted discrete rule. The paper is an authored research proposal with the publisher's opinion disclaimer, not a banking contract or an experiment on this app.

The early remainder is a product convention. A final-only adjustment is another convention; it can increase the last principal component and does not imply nonincreasing installments. C<n is rejected by this simulator to preserve at least one cent amortization every period; this is not universal financial impossibility. The historical exploratory JSON uses final-adjustment SAC and must not silently replace the approved source.

Related: [1012 r1](../../specs/1012/r1-amortization-comparison.md); [1203 r1](../../requirements/1203/r1-sac-ledger.md); [source register](../../evidence/research/finance/research-log.md). No implementation result is assigned.
