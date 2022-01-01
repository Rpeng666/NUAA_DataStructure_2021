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
	cout << "链式结构：" << endl;
	cout << "开始从T2.txt 读入数据" << endl;

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

	cout << "数据输入完毕" << endl << endl;

	cout << "链表LA中的元素" << endl;
	ListTravel(La);
	cout << endl;
	cout << "链表LB中的元素" << endl;
	ListTravel(Lb);
	cout << endl;

	cout << "开始在La的空间上存储La和Lb的并集" << endl;

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

	cout << "合并完毕" << endl << "La的数据为：" << endl;
	ListTravel(La);

	return 0;
}