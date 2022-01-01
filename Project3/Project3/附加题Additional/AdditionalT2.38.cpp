#include<iostream>
#include<fstream>

using namespace std;


struct LNode {
	int data;
	int freq =0;
	LNode* pre;
	LNode* next;
};


void ListTravelByNext(LNode* head) {
	LNode* temp = head->next;
	cout << head->data << " (" << head->freq << ")  ";
	while (temp != head) {
		cout << temp->data << " (" << temp->freq << ")  ";
		temp = temp->next;
	}
	cout << endl;
}

void Sort(LNode*head) {
	//ð������
	LNode*p1 = head, *tail = head->pre;
	while (tail != head) {
		p1 = head;
		while (p1 != tail) {
			if (p1->freq < p1->next->freq) {
				std::swap(p1->data, p1->next->data);
				std::swap(p1->freq, p1->next->freq);
			}
			p1 = p1->next;
		}
		tail = tail->pre;
	}
}


bool FindNum(int num, LNode* head) {
	LNode*temp = head;

	while (num != temp->data) {
		temp = temp->next;
		if (temp == head) {
			return false;
		}
	}

	temp->freq++;
	Sort(head);

	return true;
}


int main() {
	cout << "��ʼ��AdditionalT.32.txt�ж�ȡ���ݹ�������" << endl << endl;
	fstream file("T2.38.txt", ios::in);
	int num;
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


	cout << "������ϣ���ʼ������" << endl;
	ListTravelByNext(head);
	cout << endl;

	cout << "��ʼ���в��Ҹı�Ƶ�Ȳ�����" << endl << endl;
	ch = ' ';
	while (ch != '\n') {
		file >> num;
		file.get(ch);
		if (FindNum(num, head)) {
			cout << "����Ԫ�ء�" << num << "���ɹ���չʾĿǰ�����������" << endl << endl;
			ListTravelByNext(head);
			cout << endl << endl;
		}
		else {
			cout << "���Ҳ���Ԫ�ء�" << num << "��" << endl << endl;
		}
	}
}