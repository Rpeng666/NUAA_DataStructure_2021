#include<iostream>
#include<fstream>

using namespace std;


struct LNode {
	int data;
	LNode* pre = NULL;
	LNode* next;
};



void ListTravelByNext(LNode * head) {
	while (head != NULL) {
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}

void ChangeList(LNode*head) {
	if (head == NULL) return;
	
	while (head->next != NULL) {
		head->next->pre = head;
		head = head->next;
	}
}

void ListTravelByPre(LNode* tail) {
	while (tail != NULL) {
		cout << tail->data << ' ';
		tail = tail->pre;
	}
	cout << endl;
}

int main() {
	cout << "��ʼ��AdditionalT.32.txt�ж�ȡ���ݹ�������" << endl;
	fstream file("T2.32.txt", ios::in);
	char ch = ' ';
	LNode* head = new LNode, *p;
	p = head;
	p->next = p;

	while (ch != '\n') {
		p = p->next;
		file >> p->data;
		p->next = new LNode;
		file.get(ch);
	}
	delete p->next;
	p->next = NULL;
	file.close();

	cout << "Ԫ�ػ�ȡ��ϣ���ʼ������" << endl;
	ListTravelByNext(head);

	cout << endl << "��ʼ�޸�pre������˫������" << endl;
	ChangeList(head);
	cout << "˫�����������" << endl << endl;

	cout << "��ʼ��preָ�뷴���������" << endl;
	ListTravelByPre(p);

	return 0;
}