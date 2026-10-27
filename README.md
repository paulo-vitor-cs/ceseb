# CESEB — calculadora de financiamento

Aplicativo desktop em **C++20 e Qt 6 Widgets**, para Windows e Linux, com interface em português e valores em reais. Compara **Price e SAC** com taxa anual **nominal ou efetiva**, mostra prestações, totais, juros e taxas equivalentes. O cálculo ocorre localmente, sem conta ou serviço remoto.

Os cálculos usam dinheiro em centavos e comparações numéricas exatas para os arredondamentos definidos no projeto. Os arquivos próprios usam a [licença MIT](LICENSE); dependências têm termos próprios em [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

## Usar e compilar

- [Guia do usuário](docs/user-guide.md): entradas, exemplos, atalhos, ajuda e convenções financeiras.
- [Build, testes e pacotes](docs/build-and-test.md): dependências fixadas, núcleo isolado, aplicação e entrega Windows/Linux.
- [Documentação e relatório técnico](docs/README.md).

No Windows, extraia o ZIP completo e abra `bin/ceseb.exe`. No Ubuntu, instale o DEB e abra o lançador CESEB. Preserve as bibliotecas privadas, plugins e licenças que acompanham cada pacote. Os pacotes são gerados localmente; este repositório ainda não publica uma release para download.

## Validação pelo uso do aplicativo

Os **25 requisitos têm julgamento no código testado**: **22 aprovados e três reprovados**. Os seis que antes aguardavam demonstração foram exercitados no aplicativo real. A fonte executada é o commit `57ef26901d4381ead16c7347483d588ad9d92efe`; os commits posteriores até esta documentação não mudam seus 55 paths de produto/testes.

| Requisito | Resultado |
|---|---|
| 1215 — teclado | **pass**: Tab/inversa, Enter no formulário, Space, erro/correção, limpeza, ajuda e Escape nos dois sistemas. |
| 1216 — visibilidade e escalas | **fail**: no tema escuro Windows, valores digitados ficam brancos sobre fundo branco. |
| 1217 — ajuda e licenças | **pass**: conteúdo local completo e link abrindo o gerenciador de arquivos; inspeção offline Linux. |
| 1221 — núcleo independente | **pass**: compilação/consumo sem Qt no núcleo, Ubuntu 24/GCC 13 e Windows. |
| 1225 — pacote | **fail**: faltam avisos específicos de dxcompiler.dll/dxil.dll no ZIP Windows. |
| 1226 — cenários reais | **pass**: nominal/efetiva, transições, erro/correção, limpeza, teclado, redimensionamento e fechamento nos dois sistemas. |

O terceiro requisito reprovado é **1228**, pelo mesmo problema de avisos do ZIP. Há, portanto, **duas falhas concretas**: contraste no tema escuro Windows e materiais de avisos DXC/DXIL. Os cálculos corretos não eliminam esses defeitos. Não são falhas de compilação nem protocolos ainda aguardando execução.

Linux foi exercitado em Ubuntu **24.04.5**, em contêineres Docker com kernel WSL compartilhado, instalação limpa do DEB e desktop X11/Xvfb/Openbox privado. Sem ferramentas de desenvolvimento no runtime, houve uso por teclado, nominal/efetiva, erro/correção, limpeza, ajuda offline, pasta de licenças e 800×600 pixels lógicos nas escalas de 100% e 200%. Windows **11 Pro** usou o ZIP real, UI Automation para observação e entrada nativa guardada por PID/executável/janela; o tema global não foi alterado. Os relatórios registram o limite físico do monitor na captura de 200%.

Os testes automatizados anteriores passaram **26/26 por backend** em Linux e Windows. A execução adicional do núcleo Ubuntu 24/GCC 13 passou **21/21 sem Qt instalado durante o teste**; o consumidor Windows isolado passou **20/20 casos**, sem Qt nas dependências ou módulos carregados. [XML Ubuntu 24](docs/validation/r3/ubuntu24-core-results.xml) · [Resumo do uso real Windows](docs/validation/r3/windows-validation-summary.json).

Captura original da aplicação no Ubuntu 24.04; os resultados restantes ficam acessíveis por rolagem:

![CESEB em uso no Ubuntu 24.04](docs/validation/r3/ubuntu24-nominal.png)

[Captura Linux a 200%](docs/validation/r3/ubuntu24-200pct.png) · [Defeito real de contraste no Windows](docs/validation/r3/windows-dark-inputs.png).

## Projeto e rastreabilidade

O projeto segue Mikoshi Design, com requisitos de produto separados das ferramentas e dos planos. Os corpos aprovados e o histórico das revisões são preservados; notas de pesquisa em draft continuam identificadas como draft.

- [Design aprovado e resolução numérica/Qt](.mikoshi/brain/sessions/1-mortgage-desktop/documents/1015/r3-research-driven-design.md).
- [Planos e cobertura dos 25 requisitos](.mikoshi/brain/sessions/1-mortgage-desktop/documents/1033/r1-engineering-plan-review-index.md).
- [Rodada anterior](.mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r2/round.md).
- [Validação real Linux e primeira publicação](.mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r3/round.md).
- [Retomada Windows e resultados finais](.mikoshi/brain/sessions/1-mortgage-desktop/evidence/synapses/r3/round-r2.md).
- [Pedido humano original](.mikoshi/brain/sessions/1-mortgage-desktop/documents/1001/r1-human-request.md).

Os reports identificam o commit executado e os resultados por plataforma. Outputs operacionais completos podem permanecer locais; o repositório não afirma que um link de relatório contém todos os seus outputs. A simulação não inclui seguros, tarifas, impostos ou indexadores e não representa CET ou oferta de crédito.
