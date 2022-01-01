#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

struct seqlist{
	int* L;
	int len = 0;
	int maxlen = 100;
};


int main() {

	// ��ʼ�� 
	seqlist La, Lb;
	La.L = new int[La.maxlen];
	Lb.L = new int[Lb.maxlen];


	cout << "˳��ṹ��" << endl;
	cout << "��ʼ��T2.txt ��������" << endl;

	int temp;
	char ch = ' ';

	fstream file("T2.txt", ios::in);

	while (ch != '\n') {
		file >> temp;
		file.get(ch);
		La.L[La.len++] = temp;
	}
	ch = ' ';
	while (ch != '\n') {
		file >> temp;
		file.get(ch);
		Lb.L[Lb.len++] = temp;
	}

	cout << "�����������" << endl << endl << endl;

	cout << "La������Ϊ��" << endl;
	for (int i = 0; i < La.len; i++) {
		cout << La.L[i] << ' ';
	}
	cout << endl;
	cout << "Lb������Ϊ��" << endl;
	for (int i = 0; i < Lb.len; i++) {
		cout << Lb.L[i] << ' ';
	}
	cout << endl;


	cout << "��ʼ��La�Ŀռ��ϴ洢La��Lb�Ĳ���" << endl;
	
	int i = 0, j = 0;

	while (i < La.len && j < Lb.len) {
		while (Lb.L[j] < La.L[i]) {
			i++;
		}

		if (Lb.L[j] == La.L[i]) {
			j++;
			continue;
		}

		for (int p = La.len; p >= i+1; p--) {
			La.L[p] = La.L[p - 1];
		}
		La.L[i] = Lb.L[j];
		La.len++;

		j++;
	}

	cout << "�ϲ����" << endl << "La������Ϊ��" << endl;

	for (int i = 0; i < La.len; i++) {
		cout << La.L[i] << ' ';
	}
	cout << endl;

}
