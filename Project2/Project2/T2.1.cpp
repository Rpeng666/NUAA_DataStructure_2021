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

	// 初始化 
	seqlist La, Lb;
	La.L = new int[La.maxlen];
	Lb.L = new int[Lb.maxlen];


	cout << "顺序结构：" << endl;
	cout << "开始从T2.txt 读入数据" << endl;

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

	cout << "数据输入完毕" << endl << endl << endl;

	cout << "La的数据为：" << endl;
	for (int i = 0; i < La.len; i++) {
		cout << La.L[i] << ' ';
	}
	cout << endl;
	cout << "Lb的数据为：" << endl;
	for (int i = 0; i < Lb.len; i++) {
		cout << Lb.L[i] << ' ';
	}
	cout << endl;


	cout << "开始在La的空间上存储La和Lb的并集" << endl;
	
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

	cout << "合并完毕" << endl << "La的数据为：" << endl;

	for (int i = 0; i < La.len; i++) {
		cout << La.L[i] << ' ';
	}
	cout << endl;

}
