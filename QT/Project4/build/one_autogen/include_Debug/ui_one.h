/********************************************************************************
** Form generated from reading UI file 'one.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONE_H
#define UI_ONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_one
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *one)
    {
        if (one->objectName().isEmpty())
            one->setObjectName("one");
        one->resize(800, 600);
        centralwidget = new QWidget(one);
        centralwidget->setObjectName("centralwidget");
        one->setCentralWidget(centralwidget);
        menubar = new QMenuBar(one);
        menubar->setObjectName("menubar");
        one->setMenuBar(menubar);
        statusbar = new QStatusBar(one);
        statusbar->setObjectName("statusbar");
        one->setStatusBar(statusbar);

        retranslateUi(one);

        QMetaObject::connectSlotsByName(one);
    } // setupUi

    void retranslateUi(QMainWindow *one)
    {
        one->setWindowTitle(QCoreApplication::translate("one", "one", nullptr));
    } // retranslateUi

};

namespace Ui {
    class one: public Ui_one {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONE_H
