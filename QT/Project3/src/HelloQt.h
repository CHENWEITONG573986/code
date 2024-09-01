#pragma once
#include "ui_HelloQt.h"
#include <QMainWindow>

class HelloQt : public QMainWindow {
    Q_OBJECT
    
public:
    HelloQt(QWidget* parent = nullptr);
    ~HelloQt();

private:
    Ui_HelloQt* ui;
};