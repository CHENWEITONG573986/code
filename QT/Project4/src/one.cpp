#include "one.h"

one::one(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_one)
{
    ui->setupUi(this);
}

one::~one()
{
    delete ui; 
}