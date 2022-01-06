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

	//����ڵ�
	void insertNode(string str);

	//string��ASCII��֮��
	static int sumOfAscii(string str);

	//���һ��string�Ƿ�Ϻ�Ҫ��
	bool isValid(string str);

	//���Ľڵ���Ϣ
	void changeInfo(int tag,string newstr);

	//��ͷ��β�����ڵ�
	void travelAllInfo();

	//���½ڵ���ע����Ϣ
	void storeInfo(Node* &newNode, Node* &lastNode,string str);

	//չʾһ���ڵ����Ϣ
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