/********************************************************************************
** Form generated from reading UI file 'T15_compute_QT.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T15_COMPUTE_QT_H
#define UI_T15_COMPUTE_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_T15_compute_QTClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *T15_compute_QTClass)
    {
        if (T15_compute_QTClass->objectName().isEmpty())
            T15_compute_QTClass->setObjectName(QString::fromUtf8("T15_compute_QTClass"));
        T15_compute_QTClass->resize(600, 400);
        menuBar = new QMenuBar(T15_compute_QTClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        T15_compute_QTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(T15_compute_QTClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        T15_compute_QTClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(T15_compute_QTClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        T15_compute_QTClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(T15_compute_QTClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        T15_compute_QTClass->setStatusBar(statusBar);

        retranslateUi(T15_compute_QTClass);

        QMetaObject::connectSlotsByName(T15_compute_QTClass);
    } // setupUi

    void retranslateUi(QMainWindow *T15_compute_QTClass)
    {
        T15_compute_QTClass->setWindowTitle(QApplication::translate("T15_compute_QTClass", "T15_compute_QT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class T15_compute_QTClass: public Ui_T15_compute_QTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T15_COMPUTE_QT_H
