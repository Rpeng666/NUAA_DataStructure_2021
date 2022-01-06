#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_T6_QT.h"
#include"sort_1.h"
#include<string>
#include<qthread.h>
#pragma execution_character_set("utf-8")

using namespace std;


class T6_QT : public QMainWindow
{
    Q_OBJECT

private:
    Ui::T6_QTClass ui;
    Sort_1 sort_1;

public:
    T6_QT(QWidget *parent = Q_NULLPTR);
    void clickButton_3();
    void clickButton_2();
    void clickButton();
};
