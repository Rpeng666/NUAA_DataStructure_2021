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
	cout << "开始从AdditionalT.32.txt中读取数据构造链表：" << endl;
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

	cout << "元素获取完毕，开始遍历：" << endl;
	ListTravelByNext(head);

	cout << endl << "开始修改pre来构造双向链表" << endl;
	ChangeList(head);
	cout << "双向链表构造完毕" << endl << endl;

	cout << "开始用pre指针反向遍历链表" << endl;
	ListTravelByPre(p);

	return 0;
}