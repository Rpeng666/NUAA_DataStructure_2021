/********************************************************************************
** Form generated from reading UI file 'T4_QT.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T4_QT_H
#define UI_T4_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_T4_QTClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *T4_QTClass)
    {
        if (T4_QTClass->objectName().isEmpty())
            T4_QTClass->setObjectName(QString::fromUtf8("T4_QTClass"));
        T4_QTClass->resize(600, 400);
        menuBar = new QMenuBar(T4_QTClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        T4_QTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(T4_QTClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        T4_QTClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(T4_QTClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        T4_QTClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(T4_QTClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        T4_QTClass->setStatusBar(statusBar);

        retranslateUi(T4_QTClass);

        QMetaObject::connectSlotsByName(T4_QTClass);
    } // setupUi

    void retranslateUi(QMainWindow *T4_QTClass)
    {
        T4_QTClass->setWindowTitle(QApplication::translate("T4_QTClass", "T4_QT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class T4_QTClass: public Ui_T4_QTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T4_QT_H
