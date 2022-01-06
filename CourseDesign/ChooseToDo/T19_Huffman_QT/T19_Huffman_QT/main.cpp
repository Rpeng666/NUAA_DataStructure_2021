#include "T19_Huffman_QT.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    T19_Huffman_QT w;

    w.resize(1266, 630);
    w.setFixedSize(1266, 630);
    w.setWindowTitle("Huffman");

    w.show();
    return a.exec();
}
