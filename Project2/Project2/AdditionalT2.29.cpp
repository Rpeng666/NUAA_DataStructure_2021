#include<iostream>
#include<fstream>
using namespace std;


void listTravel(int* L,int n) {
	for (int i = 0; i < n; i++) {
		cout << L[i] << ' ';
	}
	cout << endl;
}


void GetFromTXT(int* &La, int &lenA, int* &Lb,int &lenB ,int* &Lc, int &lenC) {
	int *pa, *pb , *pc;
	fstream file("AdditionalT2.29.txt", ios::in);
	char ch = ' ';
	lenA = lenB = lenC = 0;

	pa = new int[100];
	La = pa;
	while (ch != '\n') {
		file >> pa[lenA++];
		file.get(ch);
	}


	ch = ' ';
	pb = new int[100];
	Lb = pb;
	while (ch != '\n') {
		file >> pb[lenB++];
		file.get(ch);
	}


	ch = ' ';
	pc = new int[100];
	Lc = pc;
	while (ch != '\n') {
		file >> pc[lenC++];
		file.get(ch);
	}
	file.close();
}


//��La��ɾ������Lb�г�������Lc�г��ֵ�Ԫ��
void func(int* &La, int &lenA, int* &Lb, int &lenB, int* &Lc, int &lenC) {
	int i = 0, j = 0, k = 0;
	//��Lb��Lc�����ظ���Ԫ��
	while (j <= lenB - 1 && k <= lenB - 1) {
		while (Lb[j] != Lc[k]) {
			if (Lc[k] < Lb[j])k++;
			else j++;
		}
		j++;
		cout << "��Lb��Lc�е��ظ�Ԫ�أ�" << Lc[k] << endl;

		//��Ȼ����La�в����Ƿ�������Ԫ�أ�������ھ�ɾ��
		if (i <= lenA - 1) {
			if (La[i] > Lc[k])
				continue;

			while (La[i] < Lc[k]) {
				i++;
				if (i > lenA - 1) 
					return;
			}
			if (La[i] == Lc[k]) {
				for (int p = i; p <= lenA -2 ; p++) {
					La[p] = La[p + 1];
				}
				lenA--;
			}
			
		}
		else 
			return;
	}
}


int main() {
	int*La, *Lb, *Lc,LenA = NULL,LenB= NULL,LenC = NULL;
	cout << "��ʼ��AdditionalT2.29.txt�л�ȡԪ�ع���La��Lb��Lc" << endl << endl;
	GetFromTXT(La, LenA, Lb, LenB, Lc, LenC);
	cout << "��ȡ��ϣ���ʼ����La��Lb��Lc" << endl;
	cout << "La:";
	listTravel(La, LenA);
	cout << endl << "Lb:";
	listTravel(Lb, LenB);
	cout << endl << "Lc:";
	listTravel(Lc, LenC);
	cout << endl;

	func(La, LenA, Lb, LenB, Lc, LenC);

	cout << endl << "��ʼ����La��Lb��Lc" << endl;
	cout << "La:";
	listTravel(La, LenA);
	cout << endl << "Lb:";
	listTravel(Lb, LenB);
	cout << endl << "Lc:";
	listTravel(Lc, LenC);
	cout << endl;
}