#include "notabook.h"
#include "./ui_notabook.h"
#include <QFile>

NotaBook::NotaBook(QWidget *parent)
    : QWidget(parent), ui(new Ui::NotaBook)
{
    ui->setupUi(this);
    this->setLayout(ui->verticalLayout);
    ui->Bottom->setLayout(ui->horizontalLayout);
    QObject::connect(ui->btnOpen, SIGNAL(clicked()), this, SLOT(on_btnOpen_clicked()));
    connect(this, SIGNAL(mysignal()), this, SLOT(myslot()));
    emit mysignal();
}

NotaBook::~NotaBook()
{
    delete ui;
}

void NotaBook::on_btnOpen_clicked()
{
    std::cout << "on_btnOpen_clicked" << std::endl;
    QFile file();
}

void NotaBook::myslot()
{
    std::cout << "myslot" << std::endl;
}
