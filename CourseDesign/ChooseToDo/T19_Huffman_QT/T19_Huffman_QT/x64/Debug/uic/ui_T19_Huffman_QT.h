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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_T19_Huffman_QTClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QTextBrowser *textBrowser;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *T19_Huffman_QTClass)
    {
        if (T19_Huffman_QTClass->objectName().isEmpty())
            T19_Huffman_QTClass->setObjectName(QString::fromUtf8("T19_Huffman_QTClass"));
        T19_Huffman_QTClass->resize(659, 366);
        centralWidget = new QWidget(T19_Huffman_QTClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_5 = new QHBoxLayout(centralWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_3->addWidget(lineEdit_2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        horizontalLayout_4->addWidget(textBrowser);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        T19_Huffman_QTClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(T19_Huffman_QTClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 659, 21));
        T19_Huffman_QTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(T19_Huffman_QTClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        T19_Huffman_QTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(T19_Huffman_QTClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        T19_Huffman_QTClass->setStatusBar(statusBar);

        retranslateUi(T19_Huffman_QTClass);

        QMetaObject::connectSlotsByName(T19_Huffman_QTClass);
    } // setupUi

    void retranslateUi(QMainWindow *T19_Huffman_QTClass)
    {
        T19_Huffman_QTClass->setWindowTitle(QApplication::translate("T19_Huffman_QTClass", "T19_Huffman_QT", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("T19_Huffman_QTClass", "\350\257\267\345\213\277\350\257\273\346\211\223\345\274\200\345\255\230\346\234\211\351\235\236\350\213\261\346\226\207\345\255\227\347\254\246\347\232\204\346\226\207\344\273\266", nullptr));
        pushButton->setText(QApplication::translate("T19_Huffman_QTClass", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        comboBox->setItemText(0, QApplication::translate("T19_Huffman_QTClass", "Huffman\347\274\226\347\240\201", nullptr));
        comboBox->setItemText(1, QApplication::translate("T19_Huffman_QTClass", "Huffman\350\247\243\347\240\201", nullptr));

        pushButton_2->setText(QApplication::translate("T19_Huffman_QTClass", "\350\275\254\346\215\242", nullptr));
        label_3->setText(QApplication::translate("T19_Huffman_QTClass", "\347\233\256\346\240\207\350\267\257\345\276\204", nullptr));
        pushButton_3->setText(QApplication::translate("T19_Huffman_QTClass", "\346\211\223\345\274\200", nullptr));
        textBrowser->setPlaceholderText(QApplication::translate("T19_Huffman_QTClass", "Huffman\347\274\226\347\240\201\344\277\241\346\201\257", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class T19_Huffman_QTClass: public Ui_T19_Huffman_QTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T19_HUFFMAN_QT_H
