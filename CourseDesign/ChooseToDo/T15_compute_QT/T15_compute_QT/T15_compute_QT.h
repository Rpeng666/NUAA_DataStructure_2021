#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_T15_compute_QT.h"
#include"compute.h"
class T15_compute_QT : public QMainWindow
{
    Q_OBJECT
private:
    Ui::T15_compute_QTClass ui;
    Compute com;
public:
    T15_compute_QT(QWidget *parent = Q_NULLPTR);
    void getStr();

};
