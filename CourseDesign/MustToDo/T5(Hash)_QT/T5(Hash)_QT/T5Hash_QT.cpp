#include "T5Hash_QT.h"
#include<algorithm>

using namespace std;

T5Hash_QT::T5Hash_QT(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton, &QPushButton::clicked, this, &T5Hash_QT::clickButton);
}


void T5Hash_QT::clickButton() {
    this->filename = QFileDialog::getOpenFileName();
    ui.lineEdit->setText(this->filename);
    this->hash.readData_1();
    this->hash.readData_2();

    this->settextbrowser();
    this->settextbrowser_2();
    this->settextbrowser_3();
}

void T5Hash_QT::settextbrowser() {
    Person* temp = this->hash.getHashMap();
    string str;

    for (int i = 0; i < N; i++) {
        str.append(QString::number(i).toStdString());
        str.append(" SSN:");
        if (temp[i].ssn != " ") {
            str.append(temp[i].ssn),str.append(" 重定向次数：");
            //str.append(temp[i].name), str.append(" ");
            str.append(QString::number(temp[i].redrec).toStdString());
        }
        else str.append("空");

        str += '\n';
    }
    ui.textBrowser->setText(QString::fromStdString(str));
}

void T5Hash_QT::settextbrowser_2() {
    Node** nodemap = this->hash.getNodeMap();
    Node* temp;
    string str;

    for (int i = 0; i < N; i++) {
        temp = nodemap[i];
        str.append(QString::number(i).toStdString());
        str.append(" ");
        if (temp == NULL)str.append("空\n");
        else {
            while (temp != NULL) {
                str.append(temp->ssn);
                if(temp->next == NULL)str.append(" \n");
                else str.append(" \n    ");
                temp = temp->next;
            }
        }
    }
    ui.textBrowser_2->setText(QString::fromStdString(str));
}

struct SortNode {
    string name;
    string ssn;
    int dist;
    int freq;
};

bool cmp(SortNode& a, SortNode& b) {
    return a.freq > b.freq;
}

void T5Hash_QT::settextbrowser_3() {
    map<string, int> frequence = this->hash.getFrequence();
    map<string, int> distance = this->hash.getDistance();
    int size = frequence.size();
    string str;
    SortNode* nodelist = new SortNode[size];
    int i = 0;

    for (auto j = frequence.begin(); j != frequence.end(); j++, i++) {

        nodelist[i].ssn = j->first;
        nodelist[i].freq = j->second;
        nodelist[i].dist = distance[j->first];
        
    }

    sort(nodelist, nodelist + size, cmp);

    for (int i = 0; i < size; i++) {

        str.append("SSN:");
        str.append(nodelist[i].ssn);
        str.append("  频数：");
        str.append(std::to_string(nodelist[i].freq));
        str.append("  里程数:");
        str.append(std::to_string(nodelist[i].dist));
        str.append("\n");

    }

    ui.textBrowser_3->setText(QString::fromStdString(str));
}