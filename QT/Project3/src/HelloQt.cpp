#include "HelloQt.h"

HelloQt::HelloQt(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_HelloQt)
{
    ui->setupUi(this);
}

HelloQt::~HelloQt()
{
    delete ui; 
}