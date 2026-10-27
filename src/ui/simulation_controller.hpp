// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs
#pragma once
#include "main_window.hpp"
#include <QObject>

namespace ceseb::ui {
class SimulationController final : public QObject {
public:
    SimulationController(MainWindow&,CompareFunction);
private:
    void calculate();
    void invalidate();
    MainWindow& window_;
    CompareFunction compare_;
};
}
