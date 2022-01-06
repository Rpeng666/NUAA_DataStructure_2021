/********************************************************************************
** Form generated from reading UI file 'T5Hash_QT.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T5HASH_QT_H
#define UI_T5HASH_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_T5Hash_QTClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *T5Hash_QTClass)
    {
        if (T5Hash_QTClass->objectName().isEmpty())
            T5Hash_QTClass->setObjectName(QString::fromUtf8("T5Hash_QTClass"));
        T5Hash_QTClass->resize(600, 400);
        menuBar = new QMenuBar(T5Hash_QTClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        T5Hash_QTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(T5Hash_QTClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        T5Hash_QTClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(T5Hash_QTClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        T5Hash_QTClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(T5Hash_QTClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        T5Hash_QTClass->setStatusBar(statusBar);

        retranslateUi(T5Hash_QTClass);

        QMetaObject::connectSlotsByName(T5Hash_QTClass);
    } // setupUi

    void retranslateUi(QMainWindow *T5Hash_QTClass)
    {
        T5Hash_QTClass->setWindowTitle(QApplication::translate("T5Hash_QTClass", "T5Hash_QT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class T5Hash_QTClass: public Ui_T5Hash_QTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T5HASH_QT_H
