#include "T4_QT.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    T4_QT w;
    w.show();
    return a.exec();
}
