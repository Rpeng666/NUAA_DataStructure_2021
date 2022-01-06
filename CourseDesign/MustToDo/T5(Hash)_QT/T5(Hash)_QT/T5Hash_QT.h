#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_T5Hash_QT.h"
#include"hash.h"
#include<qfiledialog.h>
#include<fstream>
#include<string>

class T5Hash_QT : public QMainWindow
{
    Q_OBJECT
private:
    Ui::T5Hash_QTClass ui;
    Hash hash;
    QString filename;

public:
    T5Hash_QT(QWidget *parent = Q_NULLPTR);
    void clickButton();
    void settextbrowser();
    void settextbrowser_2();
    void settextbrowser_3();
};
