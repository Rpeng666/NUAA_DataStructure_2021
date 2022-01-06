#include "T15_compute_QT.h"

T15_compute_QT::T15_compute_QT(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton, &QPushButton::clicked, this, &T15_compute_QT::getStr);
}


void T15_compute_QT::getStr() {
    if (com.setStr(ui.lineEdit->text().toStdString())) {
        com.calculate();
        ui.lineEdit_2->setText(QString::number(com.result));
    }
}