#include<iostream>
#include"hash.h"
using namespace std;

int main() {
	Hash hash;

	hash.readData_1();
	hash.getHashMap();
	hash.readData_2();
	hash.getNodeMap();

	cout << "里程数：" << endl;
	hash.getDistance();
	cout << "频数：" << endl;
	hash.getFrequence();
	return 0;
}