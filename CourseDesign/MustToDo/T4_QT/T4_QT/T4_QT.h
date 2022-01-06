#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_T4_QT.h"
#include"bus.h"

class T4_QT : public QMainWindow
{
    Q_OBJECT
private:
    Ui::T4_QTClass ui;
    QString from;
    QString to;
    int flag;
    Bus bus;
    vector<string> result;

public:
    T4_QT(QWidget *parent = Q_NULLPTR);

    void clickButton();
};
