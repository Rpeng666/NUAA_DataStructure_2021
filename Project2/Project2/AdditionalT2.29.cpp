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


//在La中删除既在Lb中出现又在Lc中出现的元素
void func(int* &La, int &lenA, int* &Lb, int &lenB, int* &Lc, int &lenC) {
	int i = 0, j = 0, k = 0;
	//在Lb和Lc中找重复的元素
	while (j <= lenB - 1 && k <= lenB - 1) {
		while (Lb[j] != Lc[k]) {
			if (Lc[k] < Lb[j])k++;
			else j++;
		}
		j++;
		cout << "在Lb和Lc中的重复元素：" << Lc[k] << endl;

		//再然后在La中查找是否存在这个元素，如果存在就删除
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
	cout << "开始从AdditionalT2.29.txt中获取元素构造La、Lb和Lc" << endl << endl;
	GetFromTXT(La, LenA, Lb, LenB, Lc, LenC);
	cout << "获取完毕，开始遍历La，Lb和Lc" << endl;
	cout << "La:";
	listTravel(La, LenA);
	cout << endl << "Lb:";
	listTravel(Lb, LenB);
	cout << endl << "Lc:";
	listTravel(Lc, LenC);
	cout << endl;

	func(La, LenA, Lb, LenB, Lc, LenC);

	cout << endl << "开始遍历La，Lb和Lc" << endl;
	cout << "La:";
	listTravel(La, LenA);
	cout << endl << "Lb:";
	listTravel(Lb, LenB);
	cout << endl << "Lc:";
	listTravel(Lc, LenC);
	cout << endl;
}