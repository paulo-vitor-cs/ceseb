---
id: 3101
revision: 1
type: knowledge
tags:
- mortgage
- interest-rates
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Distinguish annual nominal monthly capitalization from annual effective rates under twelve equal compound periods.
use_when:
- Converting explicitly identified annual rates into monthly rates or comparing their annual equivalents.
---
# Annual rate equivalence for equal months

For annual percent p, monthly effective fraction m is p/1200 when p is nominal with monthly capitalization. When p is effective annual, m=(1+p/100)^(1/12)-1. The annual nominal percent corresponding to m is1200m; annual effective percent is100[(1+m)^12-1]. These equations follow by equating the year-end factor of twelve equal compound periods.

Use only with the named compounding convention, equal months and no additional cashflow costs. Nominal 12% means monthly 1%; effective 12% means monthly about0.9488792934583%. These are different inputs. At zero all equivalents are zero. For positive monthly m, effective annual exceeds nominal annual; the strict inequality does not hold at zero. Negative rates, unequal day counts, variable rates and fees require separate models.

Primary teaching source: Ana Paula Cavalcanti, ENAP, *Matemática Financeira*, Brasília 2015 (content credit2013), [Unidade1](https://repositorio.enap.gov.br/bitstream/1/2704/1/Unidade%201%20-%20Taxa%20de%20Juros.pdf), sections 1.4-1.6, PDF pages 8-12, accessed 2026-10-26. The monthly/yearly factor identity and nominal-period proportional conversion are explicit there. CRECISP's [T glossary](https://crecisp.gov.br/comunicacao/glossario/t), entries Taxa efetiva/nominal, undated, accessed same day, supplies an introductory rounded example rather than an exact oracle.

Counterevidence and limits: ENAP's unqualified strict inequality needs the positive-rate condition above. George Brown College's [2014 handout](https://www.georgebrown.ca/sites/default/files/uploadedfiles/tlc/_documents/effective_interest_rates.pdf), example 2, mixes quarterly wording and twelve-period numbers; that inconsistency cannot refute the factor identity. None of these sources establishes the app's0..100% product bound, six annual decimal input limit, decimal backend accuracy or a CET. Current mathematical applicability is separate from source age.

Related: [1008 r1](../../specs/1008/r1-annual-rate-conversion.md); [FIN source register](../../evidence/research/finance/research-log.md). This note is research draft; no requirement result or publication follows.
