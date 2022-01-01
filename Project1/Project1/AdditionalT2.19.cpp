#include<iostream>
#include<fstream>
using namespace std;

struct LinkList {
	int data;
	LinkList* next;
};
typedef int ElemType;


bool ListDelete_L(LinkList *L, ElemType mink, ElemType maxk){

	LinkList* p,* q, *prev = NULL;
	if (mink > maxk) return false;
	p = L;
	prev = p;
	p = p->next;
	while (p != NULL && p->data < maxk) {
		if (p->data <= mink) {
			prev = p;
			p = p->next;
		}
		else {
			prev->next = p->next;
			q = p;
			p = p->next;
			free(q);
		}
	}
	return true;
}

int main() {
	fstream file("T2.19.txt", ios::in);
	int temp,mink, maxk;
	char ch = ' ';
	LinkList* head = new LinkList, *t;
	head->next = head;
	t = head;

	while (ch != '\n') {
		t = t->next;
		file >> temp;
		file.get(ch);
		t->data = temp;
		t->next = new LinkList;
	}
	delete t->next;
	t->next = NULL;

	cout << "删除之前的元素分别为：" << endl;
	t = head;
	while (t != NULL) {
		cout << t->data << " ";
		t = t->next;
	}
	cout << endl;

	cout << "请输入mink：";
	cin >> mink;
	cout << "请输入maxk：";
	cin >> maxk;

	ListDelete_L(head, mink, maxk);

	cout << "删除之后的元素分别为：" << endl;
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	return 0;
}