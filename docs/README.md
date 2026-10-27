<!-- SPDX-License-Identifier: MIT -->
<!-- Copyright (c) 2026 paulo-vitor-cs -->
# CESEB 0.1.0

Calculadora desktop local de financiamento em C++20/Qt Widgets. Compare Price e
SAC com taxa anual nominal ou efetiva, em português e reais. O núcleo financeiro
também pode ser compilado sem Qt.

- [Como usar](user-guide.md)
- [Dependências, compilação e testes](build-and-test.md)
- [Modelo e resultados observados](technical-report.md)
- [Licença dos originais](../LICENSE)
- [Avisos de terceiros](../THIRD_PARTY_NOTICES.md)

Os alvos de entrega são Windows 11 x64/MSVC 2022 e Ubuntu 24.04 x64/GCC 13.
O desenvolvimento local usa WSL Ubuntu 26.04/GCC 15; os resultados desse ambiente
são auxiliares. Consulte o relatório técnico para distinguir testes executados,
pacotes disponíveis e qualificações ainda pendentes. Não há release publicada.

O DEB registra o lançador em `/usr/share/applications/ceseb.desktop` e mantém o
runtime em `/opt/ceseb`. As duas licenças do índice estão também na raiz da
árvore instalada; os materiais completos continuam em `licenses/`.

O relatório inclui links locais para um subconjunto explícito de registros
históricos, entregue com o pacote. Esses registros são um input documental
separado: um checkout ou `git archive` compila sem eles, mas o empacotamento
exige `CESEB_DELIVERY_EVIDENCE_ROOT` apontando ao export indicado no relatório.
Sua presença no pacote não significa que foram publicados no GitHub.
