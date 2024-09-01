#pragma once
#include "ui_one.h"
#include <QMainWindow>

class one : public QMainWindow {
    Q_OBJECT
    
public:
    one(QWidget* parent = nullptr);
    ~one();

private:
    Ui_one* ui;
};