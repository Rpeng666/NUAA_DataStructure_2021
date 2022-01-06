#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_T19_Huffman_QT.h"
#include<qfiledialog.h>
#include"huffman.h"


class T19_Huffman_QT : public QMainWindow
{
    Q_OBJECT
private:
    Ui::T19_Huffman_QTClass ui;
    QString filename;
    Huffman huffmanTree;

public:
    T19_Huffman_QT(QWidget *parent = Q_NULLPTR);
    void clickButton_1();
    void clickButton_2();
    void clickButton_3();

    void setTextBrowser();
    void setTargetPath();
};
