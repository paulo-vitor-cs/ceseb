---
id: 1039
revision: 1
type: document
tags: [mortgage, windows, installation, human-authority]
status: versioned
created: '2026-10-27'
updated: '2026-10-27'
description: Autorização humana explícita para instalar as ferramentas necessárias ao build e validação no Windows existente.
use_when:
- Preparar e instalar o ambiente C++ Windows necessário ao projeto sem inferir conta paga, reboot ou publicação.
---
# Instalação Windows autorizada

Após a pergunta sobre MSVC/executável Windows, o usuário respondeu:

> Não tenho outra instalação ou executável

Depois, por iniciativa própria, autorizou:

> pode instalar no windows

Origem: chat atual em 27 de outubro de 2026. A [consulta observada](../../evidence/dispatch/r2/environment/windows-toolchain-current.json) confirmou Windows 11 Pro x64, sem instalação C++ retornada por vswhere e sem cl/cmake/ninja no PATH consultado.

A autorização cobre instalar os compiladores, SDK e ferramentas necessários à matriz C++ Windows já escolhida, incluindo MSVC 2022/v143 e meios de build; obter as dependências do projeto fixadas pelos cartões vigentes. O syncer prepara a receita concreta mínima, consulta fontes oficiais, verifica fornecedor/assinatura/versão antes de executar e registra edição, componentes, licença, paths, códigos de saída e chamada útil. A instalação Windows necessária está autorizada; a restrição anterior de não instalar globalmente não bloqueia estes efeitos explicitamente pedidos no Windows. WSL e conteúdo alheio permanecem preservados.

Não há autorização de compra, conta nova, reboot automático, mudança de segurança/privacidade, bypass de UAC, publicação remota ou promoção. Se o Windows exigir uma ação de elevação humana, registrar o estado e informar ao orquestrador; não automatizar diálogos de autenticação/segurança. Scripts de engenharia por ferramenta de terminal não são automação de terminal pela UI. O problema de inicialização do Computer Use continua separado da instalação do compilador.
