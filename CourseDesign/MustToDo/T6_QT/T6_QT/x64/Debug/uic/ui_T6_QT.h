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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_T6_QTClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextBrowser *textBrowser_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *T6_QTClass)
    {
        if (T6_QTClass->objectName().isEmpty())
            T6_QTClass->setObjectName(QString::fromUtf8("T6_QTClass"));
        T6_QTClass->resize(602, 288);
        centralWidget = new QWidget(T6_QTClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));

        verticalLayout_2->addWidget(textBrowser_2);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        T6_QTClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(T6_QTClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 602, 21));
        T6_QTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(T6_QTClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        T6_QTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(T6_QTClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        T6_QTClass->setStatusBar(statusBar);

        retranslateUi(T6_QTClass);

        QMetaObject::connectSlotsByName(T6_QTClass);
    } // setupUi

    void retranslateUi(QMainWindow *T6_QTClass)
    {
        T6_QTClass->setWindowTitle(QApplication::translate("T6_QTClass", "T6_QT", nullptr));
        pushButton_2->setText(QApplication::translate("T6_QTClass", "\351\232\217\346\234\272\347\224\237\346\210\220\346\225\260\345\255\227", nullptr));
        comboBox->setItemText(0, QApplication::translate("T6_QTClass", "\347\233\264\346\216\245\346\217\222\345\205\245\346\216\222\345\272\217", nullptr));
        comboBox->setItemText(1, QApplication::translate("T6_QTClass", "\345\270\214\345\260\224\346\216\222\345\272\217", nullptr));
        comboBox->setItemText(2, QApplication::translate("T6_QTClass", "\345\206\222\346\263\241\346\216\222\345\272\217", nullptr));
        comboBox->setItemText(3, QApplication::translate("T6_QTClass", "\345\277\253\351\200\237\346\216\222\345\272\217", nullptr));
        comboBox->setItemText(4, QApplication::translate("T6_QTClass", "\351\200\211\346\213\251\346\216\222\345\272\217", nullptr));
        comboBox->setItemText(5, QApplication::translate("T6_QTClass", "\345\240\206\346\216\222\345\272\217", nullptr));
        comboBox->setItemText(6, QApplication::translate("T6_QTClass", "\345\275\222\345\271\266\346\216\222\345\272\217", nullptr));
        comboBox->setItemText(7, QApplication::translate("T6_QTClass", "\345\237\272\346\225\260\346\216\222\345\272\217", nullptr));

        pushButton->setText(QApplication::translate("T6_QTClass", "\345\274\200\345\247\213\346\216\222\345\272\217", nullptr));
        pushButton_3->setText(QApplication::translate("T6_QTClass", "\346\270\205\347\251\272", nullptr));
        label->setText(QApplication::translate("T6_QTClass", "10\344\270\252\346\240\267\346\234\254\351\203\250\345\210\206\345\205\203\347\264\240", nullptr));
        label_2->setText(QApplication::translate("T6_QTClass", "10\344\270\252\346\240\267\346\234\254\346\216\222\345\272\217\345\220\216\347\232\204\345\211\21520\344\270\252\345\205\203\347\264\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class T6_QTClass: public Ui_T6_QTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T6_QT_H
