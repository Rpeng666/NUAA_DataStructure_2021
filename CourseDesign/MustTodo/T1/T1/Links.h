#ifndef LINKS_H
#define LINKS_H

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;


struct Node {
	string str;
	int tag;
	int check;
	Node* next;
};


class Links {
private:
	Node* head;
	Node* tail;
	int size;

public:
	Links() {
		head = tail= NULL;
		size = 0;
	}

	//插入节点
	void insertNode(string str);

	//string中ASCII码之和
	static int sumOfAscii(string str);

	//检查一个string是否合乎要求
	bool isValid(string str);

	//更改节点信息
	void changeInfo(int tag,string newstr);

	//从头到尾遍历节点
	void travelAllInfo();

	//往新节点里注入信息
	void storeInfo(Node* &newNode, Node* &lastNode,string str);

	//展示一个节点的信息
	void displayOneNode(Node* target);

	static void linkIsValid(Node* head);


	~Links() {
		Node* temp = head;
		while (head != NULL) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}
};

#endif