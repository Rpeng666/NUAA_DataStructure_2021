#include"Links.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


//���ı��ļ��ж�ȡ���ݹ�������
void readData(Links& link) {
	fstream file("data.txt", ios::in);
	string temp;
	
	while (!file.eof()) {
		getline(file, temp);
		link.insertNode(temp);
		cout << endl << endl;
	}

	file.close();
}

void changeInfo(Links& link) {
	fstream file("operate.txt", ios::in);
	string temp;
	int tag;

	while (!file.eof()) {
		file >> tag;
		file.ignore();
		getline(file, temp);
		cout <<endl<<endl<< "���Խ����Ϊ " << tag << " �Ľڵ������޸�Ϊ " << temp << endl << "�����";
		link.changeInfo(tag, temp);
		link.travelAllInfo();
	}

	file.close();
}

int main() {
	Links link;
	cout << "��data.txt�ж�ȡ�ַ�����������" << endl << endl;
	readData(link);
	cout << "$$$$$$$$$$$$$$$$$$$$$$�ָ���$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl << endl;

	cout << "������ȫ����Ϣ��" << endl;
	link.travelAllInfo();
	cout <<endl<<endl<< "$$$$$$$$$$$$$$$$$$$$$$�ָ���$$$$$$$$$$$$$$$$$$$$$$$$$$$$$#" << endl << endl << endl;

	cout << "�۸Ĳ���" << endl << endl;
	changeInfo(link);
	cout << "$$$$$$$$$$$$$$$$$$$$$$�ָ���$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;


	return 0;
}
