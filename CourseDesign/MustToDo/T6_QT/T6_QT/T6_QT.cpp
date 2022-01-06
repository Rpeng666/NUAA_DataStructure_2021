#include "T6_QT.h"

T6_QT::T6_QT(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    connect(ui.pushButton_3, &QPushButton::clicked, this, &T6_QT::clickButton_3);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &T6_QT::clickButton_2);
    connect(ui.pushButton, &QPushButton::clicked, this, &T6_QT::clickButton);
}


void T6_QT::clickButton_3() {
    ui.textBrowser_2->clear();
}

void T6_QT::clickButton_2() {
    sort_1.createRandomNum();
    string str,temp,filename;
    fstream file;

    for (int i = 1; i <= 10; i++) {
        str.clear();
        if (i == 1) filename = "negativeSeq.txt";
        else if (i == 2)filename = "positiveSeq.txt";
        else filename = "random" + std::to_string(i) + ".txt";

        file.open(filename.c_str(), ios::in);

        str.append(filename + "\n");
        getline(file, temp);
        str.append(temp);
        str.append("....\n\n");
        
        ui.textBrowser->append(QString::fromStdString(str));

        file.close();
    }
    
}

void T6_QT::clickButton() {

    //QThread* newthread = new QThread();

    int flag = ui.comboBox->currentIndex();

    string filename, str;

    for (int i = 1; i <= 10; i++) {
        if (i == 1) filename = "negativeSeq.txt";
        else if (i == 2)filename = "positiveSeq.txt";
        else filename = "random" + std::to_string(i) + ".txt";

        str.clear();

        switch (flag)
        {
        case 0:str = sort_1.insertSort(filename); break;
        case 1:str = sort_1.shellSort(filename); break;
        case 2:str = sort_1.bubbleSort(filename); break;
        case 3:str = sort_1.quickSort(filename); break;
        case 4:str = sort_1.selectSort(filename); break;
        case 5:str = sort_1.heapSort(filename); break;
        case 6:str = sort_1.mergeSort(filename); break;
        case 7:str = sort_1.radixsort(filename); break;
        default:
            break;
        }
        ui.textBrowser_2->append(QString::fromStdString(str));
    }
}