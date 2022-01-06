#include "T15_compute_QT.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    T15_compute_QT w;
    w.show();
    return a.exec();
}
