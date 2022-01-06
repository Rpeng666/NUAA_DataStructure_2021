#include"Links.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


//从文本文件中读取数据构造链表
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
		cout <<endl<<endl<< "尝试将编号为 " << tag << " 的节点内容修改为 " << temp << endl << "结果：";
		link.changeInfo(tag, temp);
		link.travelAllInfo();
	}

	file.close();
}

int main() {
	Links link;
	cout << "从data.txt中读取字符串构造链表" << endl << endl;
	readData(link);
	cout << "$$$$$$$$$$$$$$$$$$$$$$分割线$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl << endl;

	cout << "链表中全部信息：" << endl;
	link.travelAllInfo();
	cout <<endl<<endl<< "$$$$$$$$$$$$$$$$$$$$$$分割线$$$$$$$$$$$$$$$$$$$$$$$$$$$$$#" << endl << endl << endl;

	cout << "篡改操作" << endl << endl;
	changeInfo(link);
	cout << "$$$$$$$$$$$$$$$$$$$$$$分割线$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;


	return 0;
}
