---
id: 1013
revision: 1
type: spec
tags:
- mortgage
- desktop-ui
- qt-widgets
status: superseded
created: '2026-10-26'
updated: '2026-10-26'
description: Janela desktop C++ para informar condições, explicar taxas e comparar Price/SAC
  com validação e estados explícitos.
use_when:
- Desenhar ou verificar formulário, resultados, localização, navegação e recuperação de erros
  do aplicativo.
---
# Interface de simulação e comparação em Qt Widgets

Escolha humana Qt Widgets: [1005](../../documents/1005/r1-human-scope-approval.md). Propostas de locale e apresentação: [1011](../../decisions/1011/r1-complete-design-basis.md). Uma janela principal C++/QtWidgets, com formulário e resultados lado a lado quando houver largura. Não haverá QML, cronograma mensal, exportação, login ou busca de taxas na internet.

## Componentes e contrato

`MainWindow` contém campos e cartões; `SimulationController` coleta texto, valida/parseia em pt-BR, chama uma vez o núcleo [1008](../1008/r1-annual-rate-conversion.md)/[1012](../1012/r1-amortization-comparison.md), traduz erros e atualiza a janela. `MoneyCodec` converte texto para centavos exatos e formata BRL; não converte valores monetários via double. QObject controla a vida dos componentes da janela; núcleo é independente de Qt. Sem thread de trabalho, timer, persistência de preferências ou chamadas de rede. A limitação de600 meses mantém trabalho finito; não há alegação de latência medida.

Proposta: idioma pt-BR, moeda BRL fixa, símbolo e unidade nos rótulos. Principal aceita texto sem agrupamento ou agrupamento brasileiro de três dígitos, até duas casas decimais; taxa anual aceita vírgula decimal e até seis casas, sem agrupamento, sinal, expoente ou símbolo%. Remover somente espaços externos. Não reinterpretar ponto decimal inglês como outro valor. Prazo aceita inteiro decimal sem sinal/agrupamento. Exemplos: `100.000,00` e `100000,00` significam10.000.000 centavos; `1,000`, `1,234.56`, `1e3` ou texto vazio são inválidos como principal; `4,5` é taxa4,5%, `4.5` é inválida. Zero é válido para taxa, não para principal/prazo. Limites adicionais são os de1012.

Combo explícito de taxa: “Nominal anual — capitalização mensal” e “Efetiva anual”; padrão nominal. Campos iniciais de exemplo:250.000,00;4,5;360 meses. Resultados começam vazios, sem cálculo automático. O botão Calcular usa valores atuais e exibe taxa efetiva mensal, nominal anual equivalente e efetiva anual equivalente, todas com seis casas decimais e unidades. O cálculo recebe a taxa integral, não os textos arredondados. Equivalente anual derivado acima de100% permanece visível.

## Esboço e conteúdo

```text
Calculadora de financiamento                     [Sobre e modelo]
Valor financiado (R$) [250.000,00]  Taxa anual (%) [4,5]
Tipo [Nominal anual — capitalização mensal v]  Prazo (meses) [360]
[Calcular] [Limpar]
Taxas equivalentes: mensal ...% | nominal anual ...% | efetiva anual ...%
Prazo informado: ... meses
[ Price                         ] [ SAC                         ]
[ Parcela ordinária R$...        ] [ Primeira parcela R$...       ]
[ Última parcela R$...           ] [ Última parcela R$...         ]
[ Pagamentos efetivos ...       ] [ Pagamentos efetivos ...      ]
[ Total pago R$...; Juros R$...  ] [ Total pago R$...; Juros R$...  ]
Diferença de juros (Price − SAC): R$...
```

Valores monetários mostram duas casas e separadores pt-BR. Se Price quitar antes, exibir “Quitado em k de n meses por ajuste de centavos”. Parcela final é identificada como ajustada quando diferente da ordinária. Em n=1, indicar que existe somente a parcela final; não sugerir duas cobranças. A diferença mantém sinal, sem rótulo de recomendação financeira.

## Estados e recuperação

Estados: `Editing`, `ValidResult`, `InvalidInput`. Ao alterar qualquer campo ou tipo depois do cálculo, apagar todos os resultados/equivalências/diferença e retornar Editing, impedindo leitura de resultado antigo como atual. Calcular válido substitui atomicamente os dois cartões. Calcular inválido apaga resultados, preserva entradas, mostra mensagem textual junto ao primeiro campo inválido e leva foco a ele. Ordem de validação visual: principal, taxa e tipo, prazo, admissibilidade de centavos. Mapeamento de foco: PrincipalOutOfRange→principal; erro de tipo de taxa→combo; erro de valor da taxa→taxa; TermOutOfRange→prazo; UnsupportedCentPrecision→principal, com orientação para ajustar valor/prazo/taxa. ArithmeticError é apresentado na área geral e foca Calcular. Mensagens não expõem traceback ou caminho interno. Corrigir e calcular novamente deve recuperar o fluxo normal. Limpar esvazia campos e resultados, restaura combo nominal e foco no principal. Fechar ou Escape encerra sem confirmação de salvamento, pois não existe persistência nem trabalho em segundo plano.

## Apresentação e acesso

Fusion com paleta clara, fundo neutro, cartões e destaque no botão; layouts gerenciam tamanhos, sem posições absolutas ou dependência de fontes externas. São meios de apresentação propostos, não um critério subjetivo de aprovação de “modernidade”. A janela inicia em1040x760 pixels lógicos. Em800x600 e escalas100%/200%, todo controle e resultado deve poder ser alcançado por layout/rolagem, sem sobreposição, texto irrecuperavelmente cortado ou rolagem horizontal do formulário.

Ordem Tab: principal→taxa→tipo→prazo→Calcular→Limpar→Sobre; Enter executa Calcular quando no formulário; Shift+Tab inverte; Escape fecha. Rótulos têm buddies e nomes acessíveis; mensagens e foco identificam erros, sem depender só de cor. Texto de resultados deve poder ser selecionado/copied. Sobre descreve nominal/efetiva, Price/SAC, pagamentos postecipados, centavos/prazo efetivo e exclusão de encargos/CET; contém versão e licenças locais, sem abrir rede automaticamente.

Requisitos: [1211](../../requirements/1211/r1-localized-input.md), [1212](../../requirements/1212/r1-rate-presentation.md), [1213](../../requirements/1213/r1-comparison-presentation.md), [1214](../../requirements/1214/r1-ui-state-recovery.md), [1215](../../requirements/1215/r1-keyboard-navigation.md), [1216](../../requirements/1216/r1-resize-access.md), [1217](../../requirements/1217/r1-model-help.md). [QtWidgets](https://doc.qt.io/qt-6.8/qtwidgets-index.html) documenta componentes, estilos e layouts; [QtTest](https://doc.qt.io/qt-6.8/qtest-overview.html) sustenta testes de eventos da interface. Consultados em2026-10-26. Nenhuma janela foi executada nesta autoria.
