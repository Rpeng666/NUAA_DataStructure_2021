#include<iostream>
#include"hash.h"
using namespace std;

int main() {
	Hash hash;

	hash.readData_1();
	hash.getHashMap();
	hash.readData_2();
	hash.getNodeMap();

	cout << "�������" << endl;
	hash.getDistance();
	cout << "Ƶ����" << endl;
	hash.getFrequence();
	return 0;
}