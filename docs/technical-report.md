<!-- SPDX-License-Identifier: MIT -->
<!-- Copyright (c) 2026 paulo-vitor-cs -->
# Modelo técnico e evidência

CESEB 0.1.0 implementa as revisões aprovadas dos quatro contratos e 25 requisitos
da sessão `1-mortgage-desktop`. Plano de implementação 2002 r1; plano de testes
2001 r1; API e fixtures físicas 1030 r1. Essas fontes ficam sob
`.mikoshi/brain/sessions/1-mortgage-desktop/`. Resultados de engenharia não
substituem julgamento independente dos requisitos.

O núcleo C++20 não inclui Qt. `include/ceseb/finance.hpp` expõe resultados ou
erros tipados, sem double na entrada monetária. Capital e cada linha de saldo,
juros, amortização e prestação são inteiros de centavos. Percentuais canônicos
são convertidos para racionais arbitrários; a interface pt-BR valida texto
antes de converter. A normalização preserva o percentual original e representa
o crescimento mensal por racional ou raiz duodécima exata.

Para nominal anual `r`, o crescimento mensal é `x = 1 + r/12`; para efetiva
anual, `x = (1+r)^(1/12)`. As taxas equivalentes são `x-1`, `12(x-1)` e `x^12-1`.
Decimais de 50 dígitos servem às projeções de leitura, com rejeição de overflow
ou underflow não nulo; nenhuma decisão em centavos ou de exibição a seis casas
depende dessas projeções aproximadas. Raízes racionais são detectadas por
potenciação inteira; comparações de meia unidade elevam limiares à potência12.

Price usa `C*x^n/(1+x+...+x^(n-1))` para a prestação teórica, com caminho `C/n`
em taxa zero. Para raiz irracional, limites racionais são refinados até as duas
extremidades arredondarem ao mesmo centavo. Não há epsilon, timeout financeiro
ou escolha arbitrária em empate. Todo arredondamento é half-up, incluindo
empate positivo exato; valores negativos de apresentação são formatados após
calcular o sinal e a magnitude exatos.

O livro de Price calcula juros mensais arredondados sobre o saldo anterior;
a amortização é prestação menos juros, e a última quita saldo e juros. Se o
saldo se extinguir antes, encerra a série e informa contagem efetiva. A parcela
ordinária precisa exceder o primeiro juro em centavos, e o capital precisa
permitir amortização positiva. SAC usa o quociente inteiro `q = C/n` e resto
`r = C%n`: as primeiras `r` amortizações recebem `q+1` centavos e as demais,
`q`. Os juros incidem sobre o saldo anterior. A função SAC isolada não depende da admissibilidade de Price;
`compare` exige ambos os livros válidos e retorna resultado atômico. Somas de
amortização, pagamentos, juros e saldos são verificadas antes de retornar.

A interface Widgets usa Fusion, cartões simples, campos com rótulos associados,
ordem de teclado e rolagem vertical. Não há QML, persistência, threads de
trabalho, parsing de JSON/CBOR, rede ou conta. Sobre e modelo é recurso local.
Ajuda, exclusões, taxa equivalente e ajustes finais estão visíveis ao usuário.

## Estado observado

`build_source_commit` do primeiro núcleo testado:
`1d87900e2d0ced86177e97b832ef1e92311f589c`.
`BASE_IMPL` e assets de testes imutáveis:
`4e7e1842efe188c889dd9d5235f131f1502779b2`.
O `reviewed_result_commit` final é registrado no relatório separado de execução;
este documento não inventa o hash do próprio commit.

No WSL Ubuntu 26.04/GCC 15.2.0, CMake 3.28.6 e Ninja 1.13.1, a rota core-first
com GUI desabilitada foi compilada antes de obter o SDK Qt. Os 20 casos de
domínio e o inventário de suites passaram (21/21 CTest). Incluem taxa zero,
nominal/efetiva, raiz racional/irracional, fronteiras de empate, rejeições,
C=10.000.000.000 centavos/n=600, fechamento de livros e grades determinísticas.
Evidência recuperável: `evidence/implementation-planning/aux-core-results.json`,
`aux-core-{1,2,3}.log` na sessão e `out/implementation/aux-core.xml` no checkout.

A primeira aquisição Qt verificou os dois arquivos oficiais, mas o script
extraiu o layout flat na pasta errada. A correção foi somente o destino do
qtbase e ICU, com arquivos anteriores preservados; a nova chamada retornou0
e `qtpaths` confirmou o prefixo. O primeiro configure GUI chegou ao Qt6Gui e
falhou por falta de OpenGL de desenvolvimento (`WrapOpenGL`). Essa tentativa é
evidência de ambiente, não falha de comportamento do aplicativo. Resultados
subsequentes constam do relatório separado e serão incorporados abaixo quando
observados.

Windows 11/MSVC 2022 e Ubuntu 24.04/GCC 13 desktop não estão disponíveis no host
observado. Não houve build Windows, smoke nativo desses alvos, instalação limpa
de pacote, CI remoto, push, PR ou release. Nenhuma dessas lacunas é pass.

## Rastreabilidade da implementação

Todos os requisitos abaixo são r1. A tabela indica autoria e evidência, não
emite verdict de requisito. `E-core` designa os logs 21/21 acima; `E-gui` e
`E-native` dependem das execuções identificadas no relatório final. Arquivos
auxiliares do build e licenças pertencem a I-1221/I-1228, não a requisitos de
ferramenta inventados.

| Req | Tarefa2002 / tarefa2001 | Arquivos principais | Evidência e limite |
|---|---|---|---|
|1101|I-1101 / T1101|finance.hpp, finance.cpp|E-core; WSL auxiliar|
|1102|I-1102 / T1102|finance.cpp, exact_math.cpp|E-core; WSL auxiliar|
|1103|I-1103 / T1103|finance.cpp, exact_math.cpp|E-core; WSL auxiliar|
|1104|I-1104 / T1104|finance.cpp|E-core; WSL auxiliar|
|1105|I-1105 / T1105|finance.cpp|E-core; WSL auxiliar|
|1106|I-1106 / T1106|finance.cpp, money_codec.cpp|E-core e GUI; WSL auxiliar|
|1201|I-1201 / T1201|finance.cpp|E-core; WSL auxiliar|
|1202|I-1202 / T1202|finance.cpp, exact_math.cpp|E-core; WSL auxiliar|
|1203|I-1203 / T1203|finance.cpp|E-core; WSL auxiliar|
|1204|I-1204 / T1204|finance.cpp|E-core; WSL auxiliar|
|1205|I-1205 / T1205|exact_math.cpp, finance.cpp|E-core; WSL auxiliar|
|1206|I-1206 / T1206|finance.cpp|E-core; WSL auxiliar|
|1207|I-1207 / T1207|finance.cpp|E-core; WSL auxiliar|
|1211|I-1211 / T1211|money_codec.cpp, simulation_controller.cpp|E-gui; alvo nativo pendente|
|1212|I-1212 / T1212|main_window.cpp, money_codec.cpp|E-gui; alvo nativo pendente|
|1213|I-1213 / T1213|main_window.cpp|E-gui; alvo nativo pendente|
|1214|I-1214 / T1214|simulation_controller.cpp, main_window.cpp|E-gui; alvo nativo pendente|
|1215|I-1215 / T1215|main_window.cpp|inspeção/teclado nativo pendente|
|1216|I-1216 / T1216|main_window.cpp|escala/área útil nativa pendente|
|1217|I-1217 / T1217|model-help.html, application.qrc|ajuda offline; inspeção nativa pendente|
|1221|I-1221 / T1221|CMakeLists.txt, cmake/, finance.hpp|E-core; ambos toolchains alvo pendentes|
|1225|I-1225 / T1225|Packaging.cmake, WindowsDeploy.cmake, packaging/|pacotes nativos completos pendentes|
|1226|I-1226 / T1226|sem alteração adicional de fonte|E-native pendente nos dois alvos|
|1227|I-1227 / T1227|docs/|documentação atual; cross-check independente pendente|
|1228|I-1228 / T1228|LICENSE, THIRD_PARTY_NOTICES.md, ThirdPartyNotices.cmake|Qt fonte exata/avisos reais; CRT Windows pendente|

As fontes correspondentes Qt são do commit indicado no SBOM, sem modificações.
O arquivo completo, textos e configuração de build do fornecedor são preparados
por comando explícito para inclusão no pacote. A inspeção do caminho conhecido
CVE-2026-105924 está em `THIRD_PARTY_NOTICES.md`; não é certificação de segurança.
Empacotamento sem esses materiais ou CRT qualificado falha de forma explícita.
