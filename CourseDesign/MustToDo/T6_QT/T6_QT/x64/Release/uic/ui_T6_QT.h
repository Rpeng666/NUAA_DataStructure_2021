/********************************************************************************
** Form generated from reading UI file 'T6_QT.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T6_QT_H
#define UI_T6_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_T6_QTClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *T6_QTClass)
    {
        if (T6_QTClass->objectName().isEmpty())
            T6_QTClass->setObjectName(QString::fromUtf8("T6_QTClass"));
        T6_QTClass->resize(600, 400);
        menuBar = new QMenuBar(T6_QTClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        T6_QTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(T6_QTClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        T6_QTClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(T6_QTClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        T6_QTClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(T6_QTClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        T6_QTClass->setStatusBar(statusBar);

        retranslateUi(T6_QTClass);

        QMetaObject::connectSlotsByName(T6_QTClass);
    } // setupUi

    void retranslateUi(QMainWindow *T6_QTClass)
    {
        T6_QTClass->setWindowTitle(QApplication::translate("T6_QTClass", "T6_QT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class T6_QTClass: public Ui_T6_QTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T6_QT_H
