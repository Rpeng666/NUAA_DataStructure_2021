#include<iostream>
#include"bus.h"
#include<string>
using namespace std;


int main() {
	string from, to;
	vector<string>temp;
	cout << "#######�Ͼ��й�����ʾϵͳ######" << endl << endl;
	cout << "������: ";
	cin >> from;
	cout << endl << "Ŀ�ĵ�: ";
	cin >> to;
	cout << endl;

	Bus bus_1,bus_2;
	bus_1.createGraph();
	bus_2.createGraph();

	temp = bus_1.minTransfer(from, to);

	cout << endl << "����ת��·����" << endl;
	for (int i = temp.size() - 1; i >= 0; i--) {
		cout <<"            "<< temp[i] << endl;
	}

	temp = bus_2.minPassStop(from, to);
	cout << endl << "����վ��·����" << endl;
	for (int i = temp.size() - 1; i >= 0; i--) {
		cout <<"            "<< temp[i] << endl;
	}
	return 0;
}