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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_T4_QTClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *T4_QTClass)
    {
        if (T4_QTClass->objectName().isEmpty())
            T4_QTClass->setObjectName(QString::fromUtf8("T4_QTClass"));
        T4_QTClass->resize(550, 307);
        centralWidget = new QWidget(T4_QTClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        horizontalLayout->addLayout(verticalLayout);

        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_3->addWidget(textEdit);


        horizontalLayout_2->addLayout(verticalLayout_3);

        T4_QTClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(T4_QTClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 550, 21));
        T4_QTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(T4_QTClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        T4_QTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(T4_QTClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        T4_QTClass->setStatusBar(statusBar);

        retranslateUi(T4_QTClass);

        QMetaObject::connectSlotsByName(T4_QTClass);
    } // setupUi

    void retranslateUi(QMainWindow *T4_QTClass)
    {
        T4_QTClass->setWindowTitle(QApplication::translate("T4_QTClass", "T4_QT", nullptr));
        label->setText(QApplication::translate("T4_QTClass", "\345\207\272\345\217\221\345\234\260", nullptr));
        comboBox->setItemText(0, QApplication::translate("T4_QTClass", "\350\275\254\350\275\246\346\254\241\346\225\260\346\234\200\345\260\221", nullptr));
        comboBox->setItemText(1, QApplication::translate("T4_QTClass", "\347\273\217\350\277\207\347\253\231\347\202\271\346\234\200\345\260\221", nullptr));

        label_2->setText(QApplication::translate("T4_QTClass", "\347\233\256\347\232\204\345\234\260", nullptr));
        pushButton->setText(QApplication::translate("T4_QTClass", "\346\237\245\346\211\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class T4_QTClass: public Ui_T4_QTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T4_QT_H
