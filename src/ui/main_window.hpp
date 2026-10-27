// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs
#pragma once
#include <ceseb/finance.hpp>
#include <QMainWindow>
#include <QString>
#include <functional>
#include <map>

class QBoxLayout;
class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QResizeEvent;
namespace ceseb::ui {
using CompareFunction=std::function<Result<Comparison>(const LoanInput&)>;
class SimulationController;
class MainWindow final : public QMainWindow {
public:
    explicit MainWindow(CompareFunction=ceseb::compare,QWidget* parent=nullptr);
protected:
    void resizeEvent(QResizeEvent*) override;
private:
    friend class SimulationController;
    void clear_results();
    void present(const Comparison&,const QuantizedRates&);
    void show_error(ErrorCode);
    void show_about();
    QLineEdit *principal_{}, *rate_{}, *term_{};
    QComboBox* kind_{};
    QPushButton *calculate_{}, *clear_{}, *about_{};
    QLabel* message_{};
    QBoxLayout* cards_{};
    std::map<QString,QLabel*> results_;
};
}
