#include<iostream>
#include<fstream>
using namespace std;

struct LNode {
	int data;
	LNode* next;
};

void listTravel(LNode*head) {
	while (head != NULL) {
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}


LNode* MergeList(LNode* La, LNode*Lb) {
	//�Ƚ�����������ϲ�
	LNode*pa = La, *pb = Lb, *t, *p = La;

	while (pa != NULL && pb != NULL) {
		while (pb->data > pa->data) {
			p = pa;
			pa = pa->next;
			if (pa == NULL) {
				p->next = pb;
				break;
			}
		}

		if (pa == NULL)break;

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

	//�ٽ�������������
	p = La;
	if (La != NULL) {
		LNode* head = La, *tail = La, *temp;
		while (tail->next != NULL) tail = tail->next;
		La = tail;

		while (head != La) {
			temp = head;
			head = head->next;
			temp->next = tail->next;
			tail->next = temp;
		}
	}
	
	return La;
}



int main() {
	fstream file("AdditionalT2.24.txt", ios::in);
	char ch = ' ';
	cout << "��ʼ��AdditionalT2.24.txt�л�ȡԪ�ع���La��Lb" << endl;

	LNode*Lc;
	LNode * La = new LNode,*pa;
	La->next = La;
	pa = La;
	while (ch != '\n') {
		pa = pa->next;
		file >> pa->data;
		file.get(ch);
		pa->next = new LNode;
	}
	delete pa->next;
	pa->next = NULL;


	ch = ' ';
	LNode* Lb = new LNode,*pb;
	Lb->next = Lb;
	pb = Lb;
	while (ch != '\n') {
		pb = pb->next;
		file >> pb->data;
		file.get(ch);
		pb->next = new LNode;
	}
	delete pb->next;
	pb->next = NULL;

	cout << "��ȡ���" << endl << endl;
	cout << "La������" << endl;
	listTravel(La);
	cout << "Lb������" << endl;
	listTravel(Lb);

	cout << endl << "��ʼ�ϲ�����" << endl;

	Lc = MergeList(La, Lb);

	cout << "�ϲ����,��ʼ����Lc��" << endl;
	listTravel(Lc);
	cout << "�������" << endl;

	return 0;
}