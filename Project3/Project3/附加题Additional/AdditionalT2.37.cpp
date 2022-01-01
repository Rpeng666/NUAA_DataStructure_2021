#include<iostream>
#include<fstream>

using namespace std;

struct LNode {
	int data;
	LNode * pre;
	LNode * next;
};

void ListTravelByNext_1(LNode*head) {
	LNode* temp = head->next;
	cout << head->data << ' ';
	while (temp != head ) {
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}

void ListTravelByNext_2(LNode*head) {
	LNode* temp = head->next;
	cout << head->data << ' ';
	while (temp != NULL) {
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}

void ChangeList(LNode*head) {
	LNode*temp = head;
	LNode*target = head->next;
	
	while (1) {
		temp->next = temp->next->next;
		temp = temp->next;
		if (temp->next->next == head) {
			temp = temp->next;
			while (temp != target) {
				temp->next = temp->pre->pre;
				temp = temp->next;
			}
			temp->next = NULL;
			return;
		}
		else if (temp->next == head) {
			temp->next = temp->pre;
			temp = temp->next;
			while (temp != target) {
				temp->next = temp->pre->pre;
				temp = temp->next;
			}
			temp->next = NULL;
			return;
		}
	}
}

int main() {
	cout << "开始从AdditionalT.32.txt中读取数据构造链表：" << endl;
	fstream file("T2.32.txt", ios::in);
	char ch = ' ';
	LNode* head = new LNode, *p;
	p = head;
	p->next = p;
	p->pre = NULL;

	while (ch != '\n') {
		p = p->next;
		file >> p->data;
		p->next = new LNode;
		p->next->pre = p;
		file.get(ch);
	}
	delete p->next;
	p->next = head;
	head->pre = p;
	file.close();


	cout << "双向链表构造完毕，开始遍历：" << endl;

	ListTravelByNext_1(head);

	cout << "开始修改链表" << endl;
	ChangeList(head);
	cout << "修改完毕！开始遍历链表：" << endl;

	ListTravelByNext_2(head);


}