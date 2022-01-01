#include<iostream>

using namespace std;


struct LNode {
	int data;
	LNode * next;
};


LNode * linkList(int n) {
	int i = 0;
	LNode * head = new LNode,*p;
	head->next = head;
	p = head;

	for (i = 1; i <= n; i++) {
		p = p->next;
		p->data = i;
		p->next = new LNode;
	}
	delete p->next;
	p->next = head;

	return head;
}


void func(LNode* head, int m) {
	LNode * p = NULL;
	LNode * tail = head;

	while (tail->next != head) {
		tail = tail->next;
	}

	p = head;

	while (p->next != p) {
		int i = 0;
		for (i = 1; i < m; i++) {
			tail = p;
			p = p->next;
		}
		tail->next = p->next;
		cout << p->data << " ";
		delete p;
		p = tail->next;
	}
	cout << p->data << " ";
	delete p;
}


int main() {
	int n = 0, m = 0;
	LNode * head = NULL;
	cout << "请输入人数n:" << endl;
	cin >> n;
	cout << "请输入m:" << endl;
	cin >> m;

	head = linkList(n);

	func(head, m);
	return 0;
}