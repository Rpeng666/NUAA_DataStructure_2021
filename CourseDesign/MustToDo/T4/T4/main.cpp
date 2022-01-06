#include<iostream>
#include"bus.h"
#include<string>
using namespace std;


int main() {
	string from, to;
	vector<string>temp;
	cout << "#######南京市公交提示系统######" << endl << endl;
	cout << "出发点: ";
	cin >> from;
	cout << endl << "目的地: ";
	cin >> to;
	cout << endl;

	Bus bus_1,bus_2;
	bus_1.createGraph();
	bus_2.createGraph();

	temp = bus_1.minTransfer(from, to);

	cout << endl << "最少转车路径：" << endl;
	for (int i = temp.size() - 1; i >= 0; i--) {
		cout <<"            "<< temp[i] << endl;
	}

	temp = bus_2.minPassStop(from, to);
	cout << endl << "最少站点路径：" << endl;
	for (int i = temp.size() - 1; i >= 0; i--) {
		cout <<"            "<< temp[i] << endl;
	}
	return 0;
}