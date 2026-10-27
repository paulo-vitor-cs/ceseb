# CESEB — calculadora de financiamento

Aplicativo desktop em **C++20 e Qt 6 Widgets**, para Windows e Linux, com interface em português e valores em reais. Compara **Price e SAC** com taxa anual **nominal ou efetiva**, mostra prestações, totais, juros e taxas equivalentes. O cálculo ocorre localmente, sem conta ou serviço remoto.

Os cálculos usam dinheiro em centavos e comparações numéricas exatas para os arredondamentos definidos no projeto. Os arquivos próprios usam a [licença MIT](LICENSE); dependências têm termos próprios em [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

## Usar e compilar

- [Guia do usuário](docs/user-guide.md): entradas, exemplos, atalhos, ajuda e convenções financeiras.
- [Build, testes e pacotes](docs/build-and-test.md): dependências fixadas, núcleo isolado, aplicação e entrega Windows/Linux.
- [Documentação e relatório técnico](docs/README.md).

No Windows, extraia o ZIP completo e abra `bin/ceseb.exe`. No Ubuntu, instale o DEB e abra o lançador CESEB. Preserve as bibliotecas privadas, plugins e licenças que acompanham cada pacote. Os pacotes são gerados localmente; este repositório ainda não publica uma release para download.

## Validação pelo uso do aplicativo

Os **25 requisitos efetivos passaram na revisão independente** do código `3f4dc69ec84230b4035572fc62af3d13db451d2a`. As duas falhas encontradas anteriormente foram corrigidas: a interface mantém os campos e textos legíveis com o Windows em tema escuro; o pacote Windows deixa de distribuir as DLLs opcionais DXC/DXIL, sem perder dependências necessárias. Os critérios de aceite e os cálculos foram preservados.

As regressões foram executadas antes da correção e reproduziram ambas as falhas. Os mesmos testes passaram depois, sem mudar os oráculos. As suítes finais passaram **27/27 com interface**, nos backends offscreen e nativo, e **21/21 do núcleo**, em Ubuntu 24.04/GCC 13 e Windows 11/MSVC Community 2022. A revisão independente repetiu as suítes em builds próprios. [XML Linux](docs/validation/r4/ubuntu24-ctest-native.xml) · [XML Windows](docs/validation/r4/windows-ctest-native.xml) · [Núcleo Linux](docs/validation/r4/ubuntu24-core.xml) · [Núcleo Windows](docs/validation/r4/windows-core.xml).

O app empacotado foi usado por teclado nas escalas **100% e 200% nos dois sistemas**: taxa nominal/efetiva, comparação Price/SAC, erro e correção, invalidação de resultados, limpeza, ajuda, pasta local de licenças e fechamento. Foram conferidos 47/47 controles e textos necessários em cada escala. As capturas de 200% no Windows cobrem regiões efetivamente visíveis, movendo apenas a janela do app; o tema e a configuração global do display foram preservados.

Linux usou Ubuntu **24.04.5** em contêineres com kernel WSL compartilhado e desktop X11/Xvfb/Openbox privado; o DEB foi instalado no runtime sem ferramentas de desenvolvimento e usado offline. Windows **11 Pro** usou o ZIP real sem caminhos de desenvolvimento no processo, com entradas guardadas por executável, PID, janela ativa e sessão desbloqueada. A presença de SDK em outro diretório do host não é apresentada como dependência do aplicativo.

Captura original do aplicativo Windows corrigido, com o sistema em tema escuro:

![CESEB em uso no Windows 11](docs/validation/r4/windows-nominal.png)

[Ubuntu 24.04](docs/validation/r4/ubuntu24-nominal.png) · [Ubuntu a 200%](docs/validation/r4/ubuntu24-200pct.png) · [Identidade dos pacotes testados](docs/validation/r4/packages.json). Os pacotes testados correspondem ao código `3f4dc69`; commits documentais posteriores não são uma nova execução. O histórico das falhas e das capturas anteriores permanece em `docs/validation/r3` e nos relatórios das rodadas anteriores.

## Projeto e rastreabilidade

O projeto segue Mikoshi Design, com requisitos de produto separados das ferramentas e dos planos. Os corpos aprovados e o histórico das revisões são preservados; notas de pesquisa em draft continuam identificadas como draft.

- [Design aprovado e resolução numérica/Qt](.mikoshi/brain/sessions/1-mortgage-desktop/documents/1015/r3-research-driven-design.md).
- [Planos e cobertura dos 25 requisitos](.mikoshi/brain/sessions/1-mortgage-desktop/documents/1033/r1-engineering-plan-review-index.md).
- [Rodada anterior](.mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r2/round.md).
- [Validação real Linux e primeira publicação](.mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r3/round.md).
- [Retomada Windows e resultados finais](.mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r3/round-r2.md).
- [Correções F3/F4, revisão independente e publicação](.mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r4/round.md).
- [Pedido humano original](.mikoshi/brain/sessions/1-mortgage-desktop/documents/1001/r1-human-request.md).

Os reports identificam o commit executado e os resultados por plataforma. Outputs operacionais completos podem permanecer locais; o repositório não afirma que um link de relatório contém todos os seus outputs. A simulação não inclui seguros, tarifas, impostos ou indexadores e não representa CET ou oferta de crédito.
