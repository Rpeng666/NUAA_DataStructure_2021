#include "T5Hash_QT.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    T5Hash_QT w;
    w.show();
    return a.exec();
}
