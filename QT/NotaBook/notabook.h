#ifndef NOTABOOK_H
#define NOTABOOK_H

#include <QWidget>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class NotaBook;
}
QT_END_NAMESPACE

class NotaBook : public QWidget
{
    Q_OBJECT

public:
    NotaBook(QWidget *parent = nullptr);
    ~NotaBook();

signals:
    void mysignal();

private slots:
    void on_btnOpen_clicked();
    void myslot();

private:
    Ui::NotaBook *ui;
};
#endif // NOTABOOK_H
