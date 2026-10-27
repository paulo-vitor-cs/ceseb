// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs
#include "ui/main_window.hpp"
#include <ceseb/version.hpp>
#include <QApplication>
#include <QLocale>
#include <QStyleFactory>

int main(int argc,char** argv) {
    QApplication app(argc,argv);
    QApplication::setApplicationName(QStringLiteral("CESEB"));
    QApplication::setApplicationVersion(QString::fromLatin1(ceseb::version::number));
    QApplication::setOrganizationName(QStringLiteral("paulo-vitor-cs"));
    QLocale::setDefault(QLocale(QLocale::Portuguese,QLocale::Brazil));
    QApplication::setStyle(QStyleFactory::create(QStringLiteral("Fusion")));
    ceseb::ui::MainWindow window;window.show();
    return app.exec();
}
