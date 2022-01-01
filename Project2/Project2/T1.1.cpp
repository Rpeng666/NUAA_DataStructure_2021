#include<iostream>
#include<fstream>
using namespace std;

struct LNode {
	int data;
	LNode *next;
};

//�������Ա�
void ListTraverse(LNode* p) {
	cout << "��ʼ����Ԫ��" << endl;
	if (p != NULL) {
		while (p != NULL) {
			cout << p->data << ' ';
			p = p->next;
		}
		cout << "�������" << endl;
		return;
	}
	cout << "��" << endl;
}

//ð������
void sort(LNode* head) {
	LNode*p1 = head, *tail = head;

	while (tail->next != NULL)tail = tail->next;

	while (tail != head) {
		p1 = head;
		while (p1->next != tail) {
			if (p1->data > p1->next->data) {
				std::swap(p1->data, p1->next->data);
			}
			p1 = p1->next;
		}
		if (p1->data > p1->next->data) {
			std::swap(p1->data, p1->next->data);
		}
		tail = p1;
	}
}


int main() {
	cout << "��ʽ�ṹ��" << endl;
	cout << "��ʼ��T1.txt ��������" << endl;

	int temp;

	LNode* head = new LNode, *p;
	head->next = head;
	p = head;

	fstream file("T1.txt", ios::in);

	while (!file.eof()) {
		p = p->next;
		p->next = new LNode;
		file >> temp;
		p->data = temp;
	}
	delete p->next;
	p->next = NULL;

	cout << "�����������" << endl << endl;

	ListTraverse(head);
	cout << endl;

	cout << "��ʼ����ð������" << endl;
	sort(head);
	ListTraverse(head);

	return 0;
}




