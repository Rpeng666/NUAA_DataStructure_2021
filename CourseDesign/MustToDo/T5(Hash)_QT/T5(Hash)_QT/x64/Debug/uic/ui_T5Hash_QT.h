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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_T5Hash_QTClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *T5Hash_QTClass)
    {
        if (T5Hash_QTClass->objectName().isEmpty())
            T5Hash_QTClass->setObjectName(QString::fromUtf8("T5Hash_QTClass"));
        T5Hash_QTClass->resize(561, 362);
        centralWidget = new QWidget(T5Hash_QTClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));

        verticalLayout->addWidget(textBrowser_2);


        horizontalLayout_2->addLayout(verticalLayout);

        textBrowser_3 = new QTextBrowser(centralWidget);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));

        horizontalLayout_2->addWidget(textBrowser_3);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        T5Hash_QTClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(T5Hash_QTClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 561, 21));
        T5Hash_QTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(T5Hash_QTClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        T5Hash_QTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(T5Hash_QTClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        T5Hash_QTClass->setStatusBar(statusBar);

        retranslateUi(T5Hash_QTClass);

        QMetaObject::connectSlotsByName(T5Hash_QTClass);
    } // setupUi

    void retranslateUi(QMainWindow *T5Hash_QTClass)
    {
        T5Hash_QTClass->setWindowTitle(QApplication::translate("T5Hash_QTClass", "T5Hash_QT", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("T5Hash_QTClass", "\346\226\207\344\273\266\350\267\257\345\276\204", nullptr));
        pushButton->setText(QApplication::translate("T5Hash_QTClass", "\346\211\223\345\274\200", nullptr));
        textBrowser->setPlaceholderText(QApplication::translate("T5Hash_QTClass", "\345\274\200\346\224\276\345\256\232\345\235\200\346\263\225", nullptr));
        textBrowser_2->setPlaceholderText(QApplication::translate("T5Hash_QTClass", "\351\223\276\345\234\260\345\235\200\346\263\225", nullptr));
        textBrowser_3->setPlaceholderText(QApplication::translate("T5Hash_QTClass", "\344\274\230\350\264\250\345\256\242\346\210\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class T5Hash_QTClass: public Ui_T5Hash_QTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T5HASH_QT_H
