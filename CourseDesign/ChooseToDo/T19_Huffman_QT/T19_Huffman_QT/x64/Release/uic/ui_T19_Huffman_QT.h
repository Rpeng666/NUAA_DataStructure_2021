/********************************************************************************
** Form generated from reading UI file 'T19_Huffman_QT.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T19_HUFFMAN_QT_H
#define UI_T19_HUFFMAN_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_T19_Huffman_QTClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *T19_Huffman_QTClass)
    {
        if (T19_Huffman_QTClass->objectName().isEmpty())
            T19_Huffman_QTClass->setObjectName(QString::fromUtf8("T19_Huffman_QTClass"));
        T19_Huffman_QTClass->resize(600, 400);
        menuBar = new QMenuBar(T19_Huffman_QTClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        T19_Huffman_QTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(T19_Huffman_QTClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        T19_Huffman_QTClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(T19_Huffman_QTClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        T19_Huffman_QTClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(T19_Huffman_QTClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        T19_Huffman_QTClass->setStatusBar(statusBar);

        retranslateUi(T19_Huffman_QTClass);

        QMetaObject::connectSlotsByName(T19_Huffman_QTClass);
    } // setupUi

    void retranslateUi(QMainWindow *T19_Huffman_QTClass)
    {
        T19_Huffman_QTClass->setWindowTitle(QApplication::translate("T19_Huffman_QTClass", "T19_Huffman_QT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class T19_Huffman_QTClass: public Ui_T19_Huffman_QTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T19_HUFFMAN_QT_H
