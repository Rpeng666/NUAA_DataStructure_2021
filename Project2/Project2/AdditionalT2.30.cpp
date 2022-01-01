#include<iostream>
#include<fstream>
using namespace std;

struct LNode {
	int data;
	LNode* next;
};

void listTravel(LNode* head) {
	while (head != NULL) {
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}


void GetFromTXT(LNode* &La, LNode* &Lb, LNode* &Lc) {
	fstream file("AdditionalT2.29.txt", ios::in);
	char ch = ' ';

	La = new LNode;
	LNode *pa = La;

	La->next = La;
	while (ch != '\n') {
		pa = pa->next;
		file >> pa->data;
		file.get(ch);
		pa->next = new LNode;
	}
	delete pa->next;
	pa->next = NULL;


	ch = ' ';
	Lb = new LNode;
	LNode *pb;

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


	ch = ' ';
	Lc = new LNode;
	LNode *pc;
	Lc->next = Lc;
	pc = Lc;
	while (ch != '\n') {
		pc = pc->next;
		file >> pc->data;
		file.get(ch);
		pc->next = new LNode;
	}
	delete pc->next;
	pc->next = NULL;

	file.close();
}


//��La��ɾ������Lb�г�������Lc�г��ֵ�Ԫ��
void func(LNode* &La, LNode* &Lb, LNode* &Lc) {
	LNode*pa = La, *pb = Lb, *pc = Lc;

	//����Lb��Lc���ҵ�����Ԫ��
	while (pb != NULL && pc != NULL) {
		while (pc->data != pb->data) {
			if (pc->data < pb->data) pc = pc->next;
			else pb = pb->next;

		}
		pb = pb->next;
		cout << "��Lb��Lc�е��ظ�Ԫ�أ�" << pc->data << endl;
		//��Ȼ����La�в����Ƿ�������Ԫ�أ�������ھ�ɾ��
		if (La->data == pc->data) {
			La = La->next;
			pa = pa->next;
		}
		else {
			if (pa == NULL)break;
			while (pa->next->data != pc->data) {
				pa = pa->next;
				if (pa->next == NULL)return;
			}
			if (pa != NULL) pa->next = pa->next->next;
		}
	}
}



int main() {
	LNode* La = NULL, *Lb = NULL, *Lc = NULL;
	cout << "��ʼ��AdditionalT2.29.txt�л�ȡԪ�ع���La��Lb��Lc" << endl;
	GetFromTXT(La, Lb, Lc);
	cout << "��ȡ��ϣ���ʼ����La��Lb��Lc" << endl;
	cout << "La:";
	listTravel(La);
	cout << endl << "Lb:";
	listTravel(Lb);
	cout << endl << "Lc:";
	listTravel(Lc);
	cout << endl;

	cout << "��ʼ��La��ɾ������Lb�г�������Lc�г��ֵ�Ԫ��" << endl;
	func(La, Lb, Lc);
	cout << endl<<"ɾ����ϣ���ʼ����La,Lb,Lc" << endl << endl;
	cout << "La:";
	listTravel(La);
	cout << endl << "Lb:";
	listTravel(Lb);
	cout << endl << "Lc:";
	listTravel(Lc);
	cout << endl;

	return 0;
}
