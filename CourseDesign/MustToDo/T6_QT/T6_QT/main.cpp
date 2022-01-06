#include "T6_QT.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    T6_QT w;
    w.show();
    return a.exec();
}
