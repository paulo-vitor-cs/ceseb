<!-- SPDX-License-Identifier: MIT -->
<!-- Copyright (c) 2026 paulo-vitor-cs -->
# Uso da calculadora

No Windows, extraia o ZIP completo em uma pasta de sua escolha e abra
`bin/ceseb.exe`. Conserve `plugins/`, `licenses/` e as DLLs junto do aplicativo.
No Ubuntu 24.04, um DEB qualificado é instalado pelo gerenciador padrão e expõe
o lançador CESEB; o executável fica em `/opt/ceseb/bin/ceseb`. A produção e a
validação desses dois pacotes ainda dependem dos ambientes declarados. Não
substitua instalações globais de Qt para executar o aplicativo.

Informe valor financiado, taxa anual, tipo de taxa e prazo em meses, e pressione
**Calcular**. O aplicativo inicia com R$ 250.000,00, 4,5% nominal e 360 meses,
sem resultado calculado. **Limpar** apaga os campos e resultados e devolve o
foco ao valor. Editar qualquer entrada invalida imediatamente os resultados
anteriores; pressione Calcular para obter uma nova comparação.

O valor deve ficar entre R$ 0,01 e R$ 100.000.000,00. Exemplos aceitos:
`1000`, `1000,5`, `1.000,50`. Use vírgula decimal, até duas casas e agrupamento
de milhares completo quando houver pontos. A taxa aceita de 0% a 100%, até
seis casas com vírgula, sem símbolo `%`, sinal ou agrupamento. O prazo é um
inteiro de 1 a 600. Não use notação exponencial. Uma combinação muito pequena
para amortizar em centavos é recusada com orientação; o app não inventa uma
prestação que deixe a dívida crescer.

**Nominal anual, capitalização mensal** divide a taxa anual por 12 para obter
a taxa efetiva mensal. Para 12% nominal, são 1% ao mês e 12,682503% efetivos
ao ano. **Efetiva anual** representa o crescimento real no ano: para 12%
efetivos, a taxa mensal equivalente é 0,948879% e a nominal anual equivalente
é 11,386552%. A tela mostra as três taxas equivalentes com seis casas; o cálculo
usa o valor integral e não esses números arredondados da tela.

Price calcula uma parcela ordinária e ajusta a última prestação para quitar o
saldo em centavos. Pode haver quitação antes do prazo informado por efeitos
do arredondamento; o aviso e a contagem de pagamentos mostram isso. SAC divide
a amortização do principal pelos meses; as prestações normalmente decrescem,
com acerto de centavos no último pagamento. A comparação apresenta a primeira
ou ordinária, a última, a contagem efetiva, total pago e juros de cada sistema.
A diferença de juros é **Price menos SAC**, inclusive quando for negativa.

Exemplo de referência: R$ 1.000,00, 12% nominal, 3 meses. Price tem parcela
ordinária R$ 340,02, última R$ 340,03, total R$ 1.020,07 e juros R$ 20,07.
SAC tem primeira R$ 343,34, última R$ 336,66, total R$ 1.020,00 e juros R$ 20,00.
Ao trocar para efetiva anual, os resultados desaparecem até recalcular. Price
passa a R$ 339,68 nas três prestações, total R$ 1.019,04 e juros R$ 19,04;
SAC tem primeira R$ 342,83, última R$ 336,49, total R$ 1.018,98 e juros R$ 18,98.

As prestações são mensais e postecipadas, com taxa fixa. Não há seguros,
tarifas, impostos, indexadores, entrada, carência ou datas de calendário.
Total pago e juros são deste modelo simplificado; não representam CET ou uma
oferta de crédito. Os cálculos ocorrem localmente, sem conexão, conta ou arquivo
de dados; nada é salvo entre execuções.

Tab percorre valor, taxa, tipo, prazo, Calcular, Limpar e Sobre e modelo;
Shift+Tab faz o caminho inverso. Enter nos campos executa o cálculo e Escape
fecha a janela. Erros limpam a comparação e levam o foco ao primeiro campo que
precisa de correção. A janela pode ser redimensionada; os resultados passam a
uma coluna em largura menor e a rolagem vertical mantém o conteúdo acessível.

**Sobre e modelo** abre ajuda local, versão e revisão de fonte. O link de
licenças abre a pasta local do pacote. Não precisa de rede. Para substituir ou
reconstruir o Qt, leia os avisos e fontes correspondentes em `licenses/`.
