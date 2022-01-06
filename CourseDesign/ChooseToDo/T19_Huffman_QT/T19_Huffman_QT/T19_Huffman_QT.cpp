#include "T19_Huffman_QT.h"
#include<fstream>
#include<string>

using namespace std;


T19_Huffman_QT::T19_Huffman_QT(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton, &QPushButton::clicked, this, &T19_Huffman_QT::clickButton_1);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &T19_Huffman_QT::clickButton_2);
    connect(ui.pushButton_3, &QPushButton::clicked, this, &T19_Huffman_QT::clickButton_3);
}

void T19_Huffman_QT::clickButton_1() {
    this->filename = QFileDialog::getOpenFileName();
    ui.lineEdit->setText(this->filename);
}

void T19_Huffman_QT::clickButton_2() {
    if (ui.comboBox->currentIndex() == 1) {  //½âÂë
        huffmanTree.recodeFromDat(this->filename.toStdString());
        huffmanTree.writeRecodeTxt();
    }
    else { //±àÂë
        huffmanTree.statics(this->filename.toStdString());
        huffmanTree.huffman_First();
        huffmanTree.writeHuffmanTxtFirst();
        this->setTextBrowser();
        huffmanTree.writeCodeTxt();
        huffmanTree.writeCodeDat();
        this->setTargetPath();
    }
}

void T19_Huffman_QT::clickButton_3() {


}

void T19_Huffman_QT::setTextBrowser() {
    fstream file("Huffman.txt", ios::in);
    string content, temp;

    while (!file.eof()) {
        getline(file, temp);
        content = content + temp + '\n';
    }
    ui.textBrowser->setText(QString::fromStdString(content));
}



void T19_Huffman_QT::setTargetPath() {
    QString filename = QCoreApplication::applicationDirPath();
    ui.lineEdit_2->setText(filename);
}

