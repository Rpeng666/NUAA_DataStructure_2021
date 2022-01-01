#include<iostream>
#include<fstream>
using namespace std;

struct LNode {
	int data;
	LNode *next;
};



void ListTravel(LNode* head) {
	while (head != NULL) {
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}



int main() {
	cout << "��ʽ�ṹ��" << endl;
	cout << "��ʼ��T2.txt ��������" << endl;

	int temp;
	char ch = ' ';
	LNode* La = new LNode,*pa = La;
	LNode* Lb = new LNode,*pb = Lb;
	La->next = La;
	Lb->next = Lb;

	fstream file("T2.txt", ios::in);

	while (ch != '\n') {
		pa = pa->next;
		file >> pa->data;
		file.get(ch);
		pa->next = new LNode;
	}
	pa->next = NULL;

	ch = ' ';
	while (ch != '\n') {
		pb = pb->next;
		file >> pb->data;
		file.get(ch);
		pb->next = new LNode;
	}
	pb->next = NULL;

	cout << "�����������" << endl << endl;

	cout << "����LA�е�Ԫ��" << endl;
	ListTravel(La);
	cout << endl;
	cout << "����LB�е�Ԫ��" << endl;
	ListTravel(Lb);
	cout << endl;

	cout << "��ʼ��La�Ŀռ��ϴ洢La��Lb�Ĳ���" << endl;

	pa = La;
	pb = Lb;
	LNode* t,*p =pa;


	while (pa != NULL && pb != NULL) {
		while (pb->data < pa->data) {
			p = pa;
			pa = pa->next;
			if (pa == NULL) {
				p->next = pb;
				break;
			}
		}

		if (pa == NULL)break;

		if (pa->data == pb->data) {
			pb = pb->next;
			continue;
		}

		t = pb;
		pb = pb->next;
		t->next = pa;
		if (pa == La) {
			pa = t;
			La = pa;
		}
		else
			p->next = t;
	}

	cout << "�ϲ����" << endl << "La������Ϊ��" << endl;
	ListTravel(La);

	return 0;
}