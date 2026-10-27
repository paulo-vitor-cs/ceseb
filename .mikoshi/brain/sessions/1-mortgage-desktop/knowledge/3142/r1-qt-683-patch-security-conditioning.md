---
id: 3142
revision: 1
type: knowledge
tags: [mortgage, research, qt, delivery]
status: draft
created: '2026-10-26'
updated: '2026-10-26'
description: Pin Qt 6.8.3 conserva reprodução, mas não incorpora correções posteriores nem acesso comercial LTS automaticamente.
use_when:
- Avaliar manutenção e segurança de uma entrega fixada em Qt 6.8.3 antes de decidir patches ou mudança de baseline.
---
# Pin Qt 6.8.3 e atualizações posteriores

Qt 6.8.3 é uma versão de 2025-03-27. Em 2026-10-26, a [política e tabela Qt 6.8](https://doc.qt.io/qt-6.8/qt-releases.html), seções LTS/Commercial support, identificam suporte comercial de cinco anos desde 6.8 e versão LTS 6.8.9. O [anúncio 6.8.9 de 2026-09-16](https://www.qt.io/blog/commercial-lts-qt-6.8.9-released), Getting/Accessing Sources, condiciona acesso imediato à licença comercial. Esse suporte não transforma todo binário 6.8.3 em atualizado.

Há contraevidência concreta a “6.8.3 sem correções pendentes”: o [aviso original CVE-2025-5992, 2025-07-11](https://lists.qt-project.org/pipermail/development/2025-July/046449.html) inclui 6.8.0 a 6.8.3 em falha de negação de serviço por parâmetros/perfis ICC em QtGui, e aponta patch público. O [índice oficial](https://wiki.qt.io/List_of_known_vulnerabilities_in_Qt_products#CVE-2025-5992) registra correção em 6.8.4. Isso não demonstra exploração no aplicativo de cálculo, cujo conteúdo e caminhos executados ainda não existem.

Também há contraevidência a “todo patch posterior está fechado para sempre”: o [arquivo público 6.8](https://download.qt.io/archive/qt/6.8/) lista fontes 6.8.4 e 6.8.5 e patches individuais em 2026-10-26. Não se inferem kits binários equivalentes ou entrega completa atual de LTS a partir desses diretórios.

Inferência de engenharia: reprodutibilidade e manutenção são obrigações diferentes. Identificar componentes realmente distribuídos, alcance de cada aviso, patchset e fonte exata; devolver escolha material ao responsável. Não trocar o pin, aplicar patch ou adquirir assinatura por inferência. A lista consultada é parcial e tem dados editoriais que podem exigir confirmação no aviso original; não é atestado global de segurança. Registro completo e limites em [3003](../../documents/3003/r1-distribution-research-compilation.md).
