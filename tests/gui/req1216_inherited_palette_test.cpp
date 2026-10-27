// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs
#include "gui_tests.hpp"
#include <QApplication>
#include <QDir>
#include <QImage>
#include <QPalette>
#include <QSignalBlocker>
#include <QStyle>
#include <QStyleFactory>
#include <memory>
#include <QStyleOptionComboBox>
#include <QStyleOptionFrame>

namespace {
struct ApplicationAppearance {
    QPalette palette = QApplication::palette();
    QString styleName = QApplication::style()->name();
    ~ApplicationAppearance() {
        // setStyle takes ownership and deletes the previous style: retain its name.
        QApplication::setStyle(QStyleFactory::create(styleName));
        QApplication::setPalette(palette);
    }
};
QPalette fixturePalette(bool dark) {
    const std::unique_ptr<QStyle> fusion(QStyleFactory::create(QStringLiteral("Fusion")));
    QPalette p = fusion->standardPalette();
    for (auto group : {QPalette::Active, QPalette::Inactive, QPalette::Disabled}) {
        p.setColor(group,QPalette::Window,dark ? QColor(40,40,40) : QColor(240,240,240));
        p.setColor(group,QPalette::Button,dark ? QColor(40,40,40) : QColor(240,240,240));
        p.setColor(group,QPalette::Base,dark ? QColor(25,25,25) : QColor(Qt::white));
        for (auto role : {QPalette::Text,QPalette::WindowText,QPalette::ButtonText})
            p.setColor(group,role,dark ? QColor(Qt::white) : QColor(Qt::black));
    }
    return p;
}
qsizetype changedPixels(const QImage& a,const QImage& b) {
    qsizetype count=0;
    for (int y=0;y<a.height();++y) for (int x=0;x<a.width();++x)
        if (a.pixel(x,y)!=b.pixel(x,y)) ++count;
    return count;
}
}
void GuiContractTests::req1216_inherited_palette() {
    ApplicationAppearance restore;
    QVERIFY(QApplication::setStyle(QStyleFactory::create(QStringLiteral("Fusion"))));
    QStringList failures;
    QString output=qEnvironmentVariable("CESEB_PIXEL_EVIDENCE_DIR");
    if (output.isEmpty()) output=QDir::currentPath()+QStringLiteral("/palette-evidence");
    QVERIFY2(QDir().mkpath(output),"Precondition: writable image evidence directory");
    for (bool dark : {false,true}) {
        QApplication::setPalette(fixturePalette(dark));
        gui_fixture::MainWindow w;
        w.resize(800,600);
        QVERIFY2(gui_fixture::show(w),"Precondition: active real MainWindow");
        gui_fixture::Form f(w); QVERIFY(f.valid());
        QVERIFY(f.fill(QStringLiteral("1.000,00"),QStringLiteral("0"),false,QStringLiteral("600")));
        f.run();
        QVERIFY(gui_fixture::contains_integer(gui_fixture::label(w,"pricePaymentsValue"),599));
        QVERIFY(gui_fixture::contains_integer(gui_fixture::label(w,"sacPaymentsValue"),600));
        QVERIFY(!gui_fixture::label(w,"priceAdjustmentNotice").isEmpty());
        f.calculate->setFocus();
        for (auto* edit : {f.principal,f.rate,f.term}) { edit->deselect(); edit->clearFocus(); }
        QCoreApplication::processEvents(); QTest::qWait(40);
        const auto inspect=[&](QWidget* control,const QRect& crop,const auto& getText,const auto& setText) {
            const QString text=getText();
            if (text.isEmpty() || crop.isEmpty() || control->hasFocus()) {
                failures << QStringLiteral("PREPARATION %1").arg(control->objectName()); return;
            }
            const QSize geometry=control->size();
            const QSignalBlocker block(control);
            const QPixmap full=control->grab(crop);
            setText(QString{}); control->repaint(); QCoreApplication::processEvents();
            const QPixmap blank=control->grab(crop);
            setText(text); control->repaint(); QCoreApplication::processEvents();
            const QString stem=output+QStringLiteral("/%1-%2").arg(dark?QStringLiteral("dark"):QStringLiteral("light"),control->objectName());
            const bool saved=full.save(stem+QStringLiteral("-filled.png")) && blank.save(stem+QStringLiteral("-blank.png"));
            if (!saved || geometry!=control->size() || full.size()!=blank.size() || full.devicePixelRatio()!=blank.devicePixelRatio() || full.isNull()) {
                failures << QStringLiteral("PREPARATION geometry/DPR/image %1").arg(control->objectName()); return;
            }
            const auto count=changedPixels(full.toImage(),blank.toImage());
            qInfo().noquote() << (dark?"dark":"light") << control->objectName() << "glyph-difference-pixels" << count << "crop" << crop << "DPR" << full.devicePixelRatio();
            if (count==0) failures << QStringLiteral("ABSENT GLYPHS %1 %2").arg(dark?QStringLiteral("dark"):QStringLiteral("light"),control->objectName());
        };
        for (auto* edit : {f.principal,f.rate,f.term}) {
            // QSS contents include padding; inset further to exclude frame/cursor.
            const QRect crop=edit->contentsRect().adjusted(14,7,-14,-7);
            inspect(edit,crop,[&]{return edit->text();},[&](const QString& s){edit->setText(s);});
        }
        QStyleOptionComboBox option; option.initFrom(f.kind); option.rect=f.kind->rect();
        option.editable=false; option.frame=f.kind->hasFrame();
        const QRect crop=f.kind->style()->subControlRect(QStyle::CC_ComboBox,&option,QStyle::SC_ComboBoxEditField,f.kind).adjusted(8,5,-8,-5);
        const int index=f.kind->currentIndex();
        QVERIFY(index>=0);
        inspect(f.kind,crop,[&]{return f.kind->itemText(index);},[&](const QString& s){f.kind->setItemText(index,s);});
        w.close();
    }
    QVERIFY2(failures.isEmpty(),qPrintable(failures.join(QLatin1Char('\n'))));
}
