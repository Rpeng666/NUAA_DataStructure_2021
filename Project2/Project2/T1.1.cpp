#include<iostream>
#include<fstream>
using namespace std;

struct LNode {
	int data;
	LNode *next;
};

//遍历线性表
void ListTraverse(LNode* p) {
	cout << "开始遍历元素" << endl;
	if (p != NULL) {
		while (p != NULL) {
			cout << p->data << ' ';
			p = p->next;
		}
		cout << "遍历完毕" << endl;
		return;
	}
	cout << "无" << endl;
}

//冒泡排序
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
	cout << "链式结构：" << endl;
	cout << "开始从T1.txt 读入数据" << endl;

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

	cout << "数据输入完毕" << endl << endl;

	ListTraverse(head);
	cout << endl;

	cout << "开始测试冒泡排序" << endl;
	sort(head);
	ListTraverse(head);

	return 0;
}




