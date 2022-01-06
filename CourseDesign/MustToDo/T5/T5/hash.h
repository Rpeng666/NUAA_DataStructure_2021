#ifndef HASH_H
#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;
#define N 400

struct Person {
	string ssn;
	string name;
	string date;
	string flight;
	int dis;
	int redrec;
	Person(string ssn=" ", string name = " ",string date=" ",string flight =" ",int dis = 0,int redrec=0) {
		this->ssn = ssn;
		this->name = name;
		this->date = date;
		this->flight = flight;
		this->dis = dis;
		this->redrec = redrec;
	}
	void changeInfo(string ssn, string name, string date, string flight, int dis, int redrec) {
		this->name = name;
		this->ssn = ssn;
		this->date = date;
		this->flight = flight;
		this->dis = dis;
		this->redrec = redrec;
	}
};

struct Node {
	string ssn;
	string name;
	string date;
	string flight;
	int dis;
	int redrec;
	Node* next;
	Node(string ssn=" ", string name = " ", string date = " ", string flight = " ", int dis = 0, Node* next=NULL, int redrec = 0) {
		this->ssn = ssn;
		this->name = name;
		this->date = date;
		this->flight = flight;
		this->dis = dis;
		this->next = next;
		this->redrec = redrec;
	}
	void changeInfo(string ssn, string name, string date, string flight, int dis, Node* next, int redrec) {
		this->ssn = ssn;
		this->name = name;
		this->date = date;
		this->flight = flight;
		this->dis = dis;
		this->next = next;
		this->redrec = redrec;
	}
};

class Hash{
private:
	Person hashMap[N];
	Node* nodemap[N];
	map<string, int> frequence;
	map<string, int> distance;
	int p = 367;
public:
	void readData_1(); //开放定址法（平方探测法）
	void readData_2(); // 链地址法
	void getFrequence();
	void getDistance();
	void getHashMap();
	void getNodeMap();
};


#endif // !HASH_H
