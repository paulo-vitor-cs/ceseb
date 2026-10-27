<!-- SPDX-License-Identifier: MIT -->
<!-- Copyright (c) 2026 paulo-vitor-cs -->
# Dependências e redistribuição

A licença MIT cobre os originais do CESEB. Os componentes abaixo conservam as
licenças de seus autores. Nenhuma licença comercial de Qt foi selecionada.

| Componente | Revisão | Uso e materiais |
|---|---|---|
| Boost.Multiprecision e headers usados | 1.86.0 | Código de headers incorporado ao núcleo; Boost Software License 1.0, texto original em `licenses/boost-LICENSE_1_0.txt`. |
| QtBase Core, Gui, Widgets e plugins efetivamente instalados | 6.12.0, SDK 6.12.0-0-202609280346 | Bibliotecas dinâmicas, opção LGPLv3 para os módulos usados; textos LGPLv3/GPLv3 e demais licenças do fornecedor, SBOM e atribuições em `licenses/qtbase/`. QtTest é usado somente nos testes. |
| ICU | 73.2 no SDK Linux selecionado | Bibliotecas dinâmicas ICU exigidas por QtCore; licença original e avisos Unicode em `licenses/icu-LICENSE.txt`. |
| GoogleTest | 1.17.0, 52eb8108c5bdec04579160ae17225d66034bd723 | Somente build/testes, não entra no runtime. BSD-3-Clause original em `licenses/googletest-LICENSE.txt` como documentação das fontes de engenharia. |
| Runtime MSVC | versão/edição reais do host qualificado | Apenas DLLs Release explicitamente permitidas pela lista REDIST da instalação observada. O ZIP só pode ser produzido após qualificação registrada; nenhum runtime Windows foi qualificado no WSL. |

O SBOM oficial identifica a fonte QtBase por
`025bdad181de241e81bf853c8a2d7bf3d19261a9`, recuperável em
https://code.qt.io/qt/qtbase.git . O script `cmake/ThirdPartyNotices.cmake`
confere esse identificador contra o SBOM do kit usado, obtém o commit exato e
inclui o arquivo completo de fonte em `licenses/source/qtbase-025bdad181de241e81bf853c8a2d7bf3d19261a9.tar.gz`.
Não aplicamos modificações ao framework. A configuração original do fornecedor
(`config_qtbase.opt`, `config_qtbase.summary`) e seu SBOM acompanham o pacote.
Os hashes dos materiais e o inventário de arquivos instalados ficam no próprio
pacote. A composição real de Windows deve ser conferida contra seu próprio SBOM;
divergência da fonte esperada impede empacotar em vez de presumir equivalência.

QtBase inclui código de terceiros. O SBOM do SDK Linux observado identifica,
entre outros, PCRE2 10.48, libpng 1.6.58, libjpeg-turbo 3.2.0, HarfBuzz 14.5.0,
double-conversion 3.4.0, dados Unicode/CLDR e algoritmos auxiliares. Os textos
originais de `LICENSES/`, todos os `qt_attribution.json` e os arquivos de
licença/avisos da árvore `src/3rdparty/` são preservados, junto da fonte completa.
A presença de uma atribuição no inventário não significa que todo módulo do
SDK foi copiado para o runtime. O manifesto de arquivos do staging identifica
as bibliotecas e plugins efetivamente distribuídos.

O usuário pode substituir as bibliotecas Qt dinâmicas por uma versão modificada
compatível com a ABI e reconstruir o aplicativo a partir das fontes MIT. Não
há assinatura, verificação criptográfica ou restrição do CESEB que impeça a
substituição. No Linux, as bibliotecas privadas ficam em `lib/`, plugins em
`plugins/` e `bin/qt.conf` aponta para essas pastas. No Windows, Qt fica em
`bin/` e plugins em `plugins/`. Guarde uma cópia antes de substituir; conserve
a arquitetura, a versão/ABI e as dependências compatíveis. Depuração e engenharia
reversa para depurar modificações dessas bibliotecas não são proibidas por este
projeto. Consulte os textos integrais LGPLv3/GPLv3 incluídos para os direitos e
obrigações aplicáveis.

Para reconstruir Qt, extraia a fonte incluída, consulte as instruções `README.md`
e `configure -help` dessa revisão e use as opções originais do fornecedor como
referência, em uma árvore de build separada. O aplicativo usa ligação dinâmica;
instruções de build do CESEB estão em `docs/build-and-test.md`. Alterar Qt e
redistribuir requer conservar as modificações e as fontes correspondentes
segundo os termos aplicáveis. Este projeto não afirma que uma biblioteca
modificada desconhecida preserve o comportamento financeiro ou a ABI.

O caminho de CVE-2026-105924 é conversão de CBOR com tag URL vazia para JSON,
em `qjsoncbor.cpp`. O aplicativo usa campos de texto locais e aritmética C++;
não chama `QCborValue`, `fromCbor`, `toJsonValue` nem APIs JSON/CBOR e não lê
arquivos/documentos externos. Essa inspeção limita o caminho conhecido do app;
não certifica ausência global de vulnerabilidades no Qt. Não aplicamos o patch
nem alteramos o pin aprovado. Nenhum pacote deve ser declarado completo sem
os avisos/fontes reais e, no Windows, a qualificação do CRT.
