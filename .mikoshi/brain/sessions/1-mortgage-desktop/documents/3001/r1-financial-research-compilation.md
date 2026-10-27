---
id: 3001
revision: 1
type: document
tags:
- mortgage
- research
- interest-rates
- amortization
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Financial research compilation separating exact rate and annuity mathematics, approved cent conventions, source inconsistencies and unresolved numerical guarantees.
use_when:
- Evaluating documentary convergence and divergences of the approved annual-rate and Price/SAC design before implementation planning.
---
# Financial research compilation

Owner: scout-finance. MAIN: /home/paulo/ceseb. Session:1-mortgage-desktop. Flow:research-project-basis. Head:research-finance. Research cut:2026-10-26, America/Sao_Paulo. Authority: [human research request1021 r1](../1021/r1-pending-research-authority.md).

The rate definitions and real-valued postpaid annuity are coherent under twelve equal months. The approved integer-cent ledgers are also internally coherent under exact evaluation of their declared rules. They are explicit product conventions; the sources do not make them universal banking rules. The material unresolved issue is the guarantee at half-cent boundaries: a finite approximate monthly rate, even extremely accurate, does not alone guarantee the exact half-up cent result. No product experiment was performed, so this is a mathematical assurance gap, not a demonstrated Boost or application failure.

## Authority, source cut and reuse

Read the human source bodies [1001 r1](../1001/r1-human-request.md), [1005 r1](../1005/r1-human-scope-approval.md), [1017 r1](../1017/r1-design-approval-and-quality-correction.md), and [effective index1015 r2](../1015/r2-refined-requirement-index.md). Design approval is recorded in1017. Specs [1008 r1](../../specs/1008/r1-annual-rate-conversion.md) and [1012 r1](../../specs/1012/r1-amortization-comparison.md) are published in frontmatter, although their preserved historical bodies still say candidate/draft. Effective requirements1101-1106 and1201-1207 are draft. Their complete bodies were read. No research finding changes those statuses or accepts the refined requirements.

Previous reports [1009 r1](../../evidence/financial-design.md) and [1016 r1](../../evidence/full-architecture.md), plus [rate JSON](../../evidence/rate-conversion-reference.json) and [candidate amortization JSON](../../evidence/amortization-reference-candidate.json), were used as seeds. FIN read1009; for1016 it read the relevant outcome/authority/source/arithmetic/retrieval sections and closing limits, not every historical check-result row. The JSON calculations remain attributed exploratory arithmetic. They do not become current requirement executions merely through this review.

Local search found no existing session knowledge at FIN's start. Explicit-corpus retrieval searched documents, decisions, specs, requirements, tools and knowledge. It returned lexical candidates with index_incompatible and graph unavailable. The first console output was truncated; the compact retained rerun is [retrieval-summary](../../evidence/research/finance/retrieval-summary.json). Exact required bodies were read independently of hit order. No graph completeness or cache repair is claimed.

## Strategy and route evidence

The question was split into: rate units and equivalence; cashflow timing and annuity; the cent ledger and payoff; SAC indivisibility and monotonicity; comparability and bank-specific exclusions; exact rounding versus approximate normalization. Portuguese terms included nominal/efetiva, capitalização, postecipada, SAC, centavos and liquidação. English expansions included ordinary annuity, final payment, missing penny and payoff. The [research log](../../evidence/research/finance/research-log.md) retains all17 actual discovery queries, source relationships, units, dates, access and exclusions.

Diverse seed families were BCB methodology and original authored technical work, ENAP teaching material, an independent finance textbook, textbook final-payment methods, a lender's own servicing explanation and a consumer regulator. Citation expansion followed the final-payment chapter to its attributed predecessor and institutional export. Adverse searches sought different rounding behavior, rounding residuals and indexed/daily conditions, rather than merely repeating the accepted equations.

Installed research r10, scout r15, strategy/read/counterevidence/sufficiency r3, search r10, route matrix, current controlled metadata and the authority/revision, verification/status and review-boundary contracts were read. Relevant retrieval4191 r2, check2521 r9, head-memory2523 r17, Context7 2560 r10 and discovery3407-3409 r7 cards were opened. Native web.run was used for actual search and source-unit opening. No Context7/Tavily/Exa/Brave binding was exposed; no service authentication was established. Root's concrete ctx7 PATH absence is retained in [access observation](../../evidence/research-access-observation.json). Permitted official-source fallback does not claim Context7 compliance. Versioned Boost investigation belongs to TECH. Formal extraction tools, scholarly citation-network services, paywalled standards and unrelated engineering sources were not needed for the present mathematical/documentary questions.

## Findings against exact approved references

| Claim / exact target | Evidence and interpretation | Classification and remaining limit |
|---|---|---|
|1008;1101-1104 r1: explicit nominal monthly-capitalized versus effective annual | ENAP 2015 sections 1.4-1.6 (F03); CRECISP T entries (F11). Nominal monthly fraction p/1200; effective annual monthly fraction(1+p/100)^(1/12)-1; annual inverses1200m and100[(1+m)^12-1]. | Mathematical convergence. No factual source supports making the two annual inputs interchangeable. Zero is exact in mathematics. Positive-rate strict inequalities need zero exception. |
|1008;1105;1201 r1:0..100% annual, principal and term bounds | These are stated human-approved design limits, not conclusions from a bank glossary or statute. A derived effective annual rate may exceed100% when nominal input is100%. | Product convention. No discovered contradictory mathematics requires changing the range. Legal/market maxima were not inferred. |
|1008;1106 r1: preserve normalized rate before finance | Formatting to a few displayed digits can perturb the numeric input; the algebraic equations operate on the original value. | Coherent data boundary. “Integral” means the chosen numerical value, not proof it equals an exact recurring/algebraic rate. |
|1012;1202 r1: Price theoretical payment | F01 BCB equation and F02 first-payment timing; F04 ordinary-annuity discussion. Invert P=A[1-(1+m)^-n]/m for m>0. | Mathematical convergence only for equal end-period cashflows and the stated exclusions. BCB's solver tolerance is not the app's cent tolerance. |
|1012;1202/1204/1205 r1: rounded monthly interest, final clearance and early stop | F05/F06 describe adjusted final payments; F07 documents a different lender rounding rule. FIN derives the adopted recurrence below. | Human convention with coherent exact ledger identities. External policy difference does not prove a design error. No bank engine or local app run was observed. |
|1012;1203/1204 r1: SAC q/r early allocation | F09 describes fixed principal amortization without indexation; integer proof below derives the adopted cent distribution. | Real-valued SAC idea converges. Which months receive indivisible cents remains product convention. Monotonic proof assumes exact/consistent R. |
|1012;1206 r1:UnsupportedCentPrecision | C<n prevents strictly positive integer SAC amortization in every month. Price a<=first rounded interest cannot reduce opening principal under the ordinary-payment rule. | Sufficient filters for this simulator's intended properties. They do not prove universal financial impossibility; independent products can accept zero-principal rows or different schedules. |
|1012;1207 r1: common normalized input and signed Price-SAC interest difference | Same requested principal/term/timing/rate/exclusions are necessary. FIN does not infer a universal sign, “better” system or bank CET. | Coherent nominal-sum comparison. Early Price stop means actual durations can differ, so actual count remains material. |
|1012 exact half-up versus finite numerical backend;1102/1103/1106 tolerances | FIN tie proof below; TECH supplied independently read Boost 1.86 documentary qualification by native message. | Material unresolved numerical guarantee. Source evidence does not establish observed failure of a pinned runtime. Backend precision findings remain TECH's report. |

## Exact mathematics and adopted discrete behavior

Write C for initial integer cents and B for opening cents. For nonnegative x define R(x)=floor(x+0.5), as the accepted design does. These are mathematical analyses of the declared contract; no fresh script or product execution supports them.

For a real annuity, P=A sum(k=1..n)(1+m)^(-k). At m=0 this sum is n, so A=P/n without a division-by-zero formula. For n=1, A=P(1+m). The first due date must be after one period; a payment at inception changes the annuity factor. [BCB methodology](https://www3.bcb.gov.br/CALCIDADAO/publico/exibirMetodologiaFinanciamentoPrestacoesFixas.do?method=exibirMetodologiaFinanciamentoPrestacoesFixas) and its [form/help](https://www.bcb.gov.br/pec/calculo/calc_financiamento/Default.asp?frame=1) support this timing and formula. Neither page specifies every monthly integer-cent state transition.

Price computes ordinary cents a=R(100A), I=R(Bm), pays min(a,B+I) before requested month n and B+I at n. If a>I_first, then subsequent I<=I_first because B decreases and R is monotone. An ordinary nonfinal row amortizes at least one cent; a capped row pays the remaining principal. No closing balance is negative. Final payment clears B, and every row has payment=principal_paid+interest. Summing yields total_paid=C+sum interest and sum principal_paid=C. The cap prevents an overpayment; immediate stopping prevents zero or negative later installments.

The zero-rate R$ 1,000/600-month case follows directly: C=100000, exact C/n=166+2/3 cents, so a=167. After598 ordinary payments,598×167=99866, leaving134 cents. Payment599 is134 and ends the ledger. This is exactly the accepted1202 case, not evidence of scheduled voluntary prepayment or a bank payoff quotation. It is also a counterexample to any unqualified “Price always has n identical payments” explanation. The approved design already discloses ordinary/final payments and actual/requested counts.

At n=1, both adopted systems pay C+R(Cm) once. Existing1205's C=100, nominal annual 6% gives m=.005 and exact interest.5 cent, hence1 cent. No extra residual row is mathematically needed. This finite-decimal example is useful but does not cover all representation-boundary conditions.

SAC defines q=C div n, r=C mod n and d_k=q+(k<=r). For C>=n, q>=1. Its sum is nq+r=C. The d sequence is nonincreasing and differs by at most one cent; B decreases each month, hence R(Bm) cannot increase for fixed m>=0. Their sum—the installment—is nonincreasing, including equal values caused by zero/rounded interest. Exactly n principal-positive rows clear the balance. At zero and a divisible principal, both systems match the same equal principal installments; for indivisible principals the cent distributions can differ. The [BCB NT56 SAC discussion](https://www.bcb.gov.br/content/publicacoes/notastecnicas/NT_56_202510.pdf), PDF pages 15-17, separately warns that indexation can cause rising payments. That different model is excluded here.

## Material assurance gap: exact half-cent versus approximate rate

The admissible discriminating case is C=6 cents, nominal annual 100%, n=1. Exact m=100/1200=1/12, so exact C m=.5 cent. The required half-up interest is1 cent and final payment7 cents for both Price and SAC. This conclusion is exact rational arithmetic on paper.

Now suppose an implementation represents m as m-epsilon for any tiny positive epsilon. Then6(m-epsilon)=.5-6epsilon and floor(6(m-epsilon)+.5)=0. Arbitrarily high finite precision does not by itself exclude this outcome, because rounding is discontinuous at the boundary. The result can also be correct in a real implementation because of its actual operation sequence and guard digits. FIN did not run that sequence and therefore reports neither a confirmed bug nor a pass.

The rate tolerance1e-12 in1102/1103/1106 does not settle the cent obligation. At B=10^10 cents it permits up to.01 cent interest perturbation before rounding; even a far smaller error can cross an exact tie. A blanket claim that “decimal50 guarantees exact half-up everywhere” would need more evidence or a mathematically justified boundary strategy. The approved money policy itself remains clear; the means of meeting it are unresolved.

FIN and TECH coordinated this distinction through native messages. TECH reports reading Boost 1.86 documentation describing truncating arithmetic and pinned implementation declarations involving round_indeterminate, plus a historical maintainer issue about rounding weaknesses. Those are attributed source findings pending TECH's exact report, not a FIN-reproduced observation. They strengthen the need for a bounded future check, while not establishing this six-cent result on Boost 1.86.

Proposed future work, requiring its own approval/plan: identify the exact Boost version, compiler and operation sequence; inspect single-period algebra and monetary rounding; compare6c/nominal 100%/one-month and neighboring input decimals against exact rational expectations on both chosen native toolchains. A passing isolated run would cover those inputs only. If a remedy changes the approved mathematical interpretation or numerical architecture, return that concrete choice to the human/specialist before its effect. No such experiment or revision occurred in this research.

## Counterevidence, source defects and historical drift

| Evidence | What it changes | What it does not establish |
|---|---|---|
|[Earnest first-party help](https://help.earnest.com/hc/en-us/articles/219178257-Why-Is-the-Total-Balance-on-My-Loan-Less-Than-the-Total-Sum-of-My-Minimum-Payments-Repaying-Your-Loan), F07: upward payment cents and daily accrual | Refutes treating half-up/monthly accrual as universal lender practice. | No requirement error: simulator intentionally selects another convention. No live lender-engine observation. |
|[Business Math institutional export](https://openlibrary-repo.ecampusontario.ca/jspui/bitstream/123456789/1081/1/Business-Math-A-Step-by-Step-Handbook-Abridged-1645549112.-htmlbook.html), F06: preserve internal balance and reconcile displayed pennies | A real alternate ledger presentation with different rounding location. | Not permission to substitute its outputs for1012's rounded-interest ledger. |
|BCB NT56 F09: indexed SAC may rise | Bounds “decreasing SAC” to no indexation/fixed rate. | No contradiction under the approved exclusions; no adoption of its proposed additional amortization. |
|Existing candidate JSON SAC for R$ 1,000/3 months: first343.33,last336.67; approved1012:343.34,336.66 | Concrete seed-policy drift;1016 explicitly acknowledges different allocation. | Not two competing authoritative oracles. The JSON must stay historical/exploratory. |
|[Dancy chapter 3.3](https://ecampusontario.pressbooks.pub/finmath1175/chapter/3-3-calculating-the-final-payment/), F05 example 3.3.1:8%/9% mismatch and200-14.49 shown185.11 | Primary educational source needs arithmetic checking before fixture reuse. | Does not refute final-adjustment principle or the accepted Price formula. No erratum absence guarantee. |
|[George Brown2014 handout](https://www.georgebrown.ca/sites/default/files/uploadedfiles/tlc/_documents/effective_interest_rates.pdf), F12 example 2 quarterly wording versus12 compounds | Source inconsistency, not a valid counterformula. | No numerical contradiction to ENAP's12 equal-month factor identity. |
|[CMN 4.881/2020](https://www.bcb.gov.br/content/estabilidadefinanceira/especialnor/Resolu%C3%A7%C3%A3o4881.pdf), F10 arts2-5, disclosure references NBR5891 | CET is a separate cost/rate contract. | The unaccessed standard is not proof of a compulsory monthly ledger rounding mode. Original text is not a certified complete current legal consolidation. |
|[CFPB payoff answer](https://www.consumerfinance.gov/ask-cfpb/what-is-a-payoff-amount-and-is-it-the-same-as-my-current-balance-en-205/), F08 | Payoff can include date-accrued interest and other amounts under a US contract. | Not Brazilian legal advice, and not the app's automatic cent-related early stop. |

The GUI's six annual decimal input bound is a separate product restriction. The long effective annual equivalent in1207 is expressly a core-interface fixture, not a promised GUI string. An arbitrary annual percentage with six decimals generally cannot express an exact equivalent of every other convention. Approximate GUI-equivalent entry therefore cannot promise identical cent results at every boundary.1207 already limits its stated monetary equivalence to the provided case away from half-cent boundaries; no contradiction was found there. FIN did not edit GUI contracts or perform parsing tests.

## Reading coverage and bounded sufficiency

The [source register](../../evidence/research/finance/research-log.md) distinguishes whole short source bodies, partial chapters/papers, consulted snippets and inaccessible bodies, with exact URLs, versions and units. Complete short substantive reading: F01/F02 BCB pages; F05 final-payment section; F07 lender answer; F08 CFPB answer; F10 resolution prose; F11 relevant glossary entries; F12 handout text. Partial larger works: F03 ENAP selected sections/credits; F04 OpenStax selected present-value/timing units; F06 institutional book selected sections; F09 NT56 selected context/SAC units. Formula graphics with lossy extraction were not presented as read equations; BCB F01 alt text and ENAP's plain-text factor table are readable.

CAIXA pages/PDFs returned errors/redirect loops or401. BCB dynamic FAQs and5004 early-liquidation page were JavaScript shells, and candidate PDF routes failed. Search snippets were not promoted into full-source proof. This leaves bank-specific Brazilian cent-allocation practice and legal early-payoff details unqualified. Those details are not needed to prove the local simulator recurrence and cannot be used to declare it bank-identical. No source offers universal absence of other divergences.

| Question | Sufficiency for this research consumer | Remaining gap / proposed responsible consumer |
|---|---|---|
|Rate definitions/conversion|Sufficient for the named equal-month mathematical interpretation; independent teaching source plus explicit factor derivation.|TECH/dev later establish implemented numerical behavior. |
|Price timing and zero/single period|Sufficient for algebra and local policy interpretation; regulator method and independent annuity source.|No product test and no universal banking ledger claim. |
|Cent rounding/final payments/early stop|Sufficient to distinguish conventions and derive accepted behavior; contrary lender and textbook methods actually read.|Exact backend tie guarantee unresolved; specialist/TECH/dev plan future proof/check. |
|SAC/remainder/monotonicity/filter|Sufficient mathematical argument for accepted finite-cent rules; indexed countercondition read.|Specific bank SAC cent policy not established. |
|Comparison/equivalent rates/GUI bound|Sufficient to bound like-for-like inputs and the long fixture's core-only role.|No universal cent equivalence from rounded GUI inputs, no user-specific financial recommendation or current legal certification. |
|Absence of any divergence anywhere|Not established or establishable from this bounded source set.|Human/orchestrator evaluates this compilation together with TECH/DIST; no blanket clearance. |

No time, token or query budget was imposed. Stopping is based on useful coverage of exact mathematics and meaningful alternative conventions, with the remaining numerical question requiring an unauthorized experiment/proof rather than more generic financial searches. This is not claimed global saturation. No new code, build, installation, benchmark, product test, requirement verdict, implementation status, design revision, knowledge promotion, Synapses or remote publication occurred.

## Separate knowledge deliverable and handoff

Five complete notes were authored after the reuse search, all r1/draft:

- [3101 annual-rate equivalence](../../knowledge/3101/r1-annual-rate-equivalence.md).
- [3102 annuity versus cent ledger](../../knowledge/3102/r1-annuity-and-cent-ledger.md).
- [3103 discrete SAC invariants](../../knowledge/3103/r1-discrete-sac-invariants.md).
- [3104 half-cent boundary guarantee](../../knowledge/3104/r1-half-cent-boundaries.md).
- [3105 comparison and bank scope](../../knowledge/3105/r1-comparison-and-bank-scope.md).

These are usable scoped claims with exact source units, conditions, counterevidence and limits, not promoted knowledge. The ownership range3101-3110 was not treated as a quota. Unused IDs remain free within the reserved ownership cut.

Structural artifact metadata/local links are checked with the installed `mikoshi check --links --profile current --json`; all six targets returned exit0/resultok with no diagnostics, retained in [artifact-checks](../../evidence/research/finance/artifact-checks.json). This checks authoring structure and link resolution, not the truth of formulas, financial certification, local runtime behavior or satisfaction of the referenced requirements. A separate author semantic/source audit confirmed the conditions and source mapping above; no independent review is claimed.

Self-authored head memory: [finance.yaml](../../session_memory/research/finance.yaml), revision2. Next responsible consumer: root orchestrator receives FIN/TECH/DIST, preserves their limits and presents the synthesis to the human. A specialist may later resolve the numerical assurance gap or prepare an authorized bounded experiment. Research completion alone does not start an analyst or publish this body.
