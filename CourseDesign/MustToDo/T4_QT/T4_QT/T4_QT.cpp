#include "T4_QT.h"

T4_QT::T4_QT(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton, &QPushButton::clicked, this, &T4_QT::clickButton);
}


void T4_QT::clickButton()   {
    this->flag = ui.comboBox->currentIndex();
    this->from = ui.lineEdit->text();
    this->to = ui.lineEdit_2->text();

    bus.createGraph();

    if (flag == 0)
        result = bus.minTransfer(from.toStdString(), to.toStdString());
   /* else
        result = bus.minPassStop(from.toStdString(), to.toStdString());*/


    string out;

    for (int i = result.size(); i >= 0; i--) {
        out.append(result[i]);
        out.append("\n");
    }
    ui.textEdit->setText(QString::fromStdString(out));
}