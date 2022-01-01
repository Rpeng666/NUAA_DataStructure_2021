#include<iostream>
#include<fstream>
using namespace std;
#define  MAXSIZE 100
typedef int elemType;

//��ʽ�ṹ
class ADT_Queue {
private:
	struct LNode {
		elemType elem;
		LNode* next;
	};
	LNode * head = NULL;
	LNode * tail = NULL;
	int len = 0;

public:
	void InitQueue() {
		head = new LNode;
		tail = head;
		len = 0;
	}

	void DestroyStack() {
		LNode* temp;
		if (head != NULL && tail != NULL) {
			while (head != NULL) {
				temp = head;
				head = head->next;
				delete temp;
			}
			delete head;
			head = tail = NULL;
		}
		len = -1;
	}

	void ClearQueue() {
		LNode* temp;
		if (head != NULL && tail != NULL) {
			while (head != NULL) {
				temp = head;
				head = head->next;
				delete temp;
			}
			len = 0;
		}
	}

	bool QueueEmpty() {
		if (head!= NULL && tail != NULL) {
			return len == 0;
		}
	}

	int QueueLength() {
		if (head != NULL && tail != NULL) {
			return len;
		}
		return -1;
	}

	elemType GetHead() {
		if (head != NULL && tail != NULL) {
			return head->elem;
		}
		return NULL;
	}

	void QueueTraverse() {
		if(len == -1)cout << "ERROR" << endl;
		else if (len == 0)cout << "��Ԫ��" << endl;
		else {
			cout << "���г��ȣ�" << len << "  ����Ԫ�أ�";
			LNode* temp = head;
			if (len != 0) {
				while (temp != tail) {
					cout << temp->elem << " ";
					temp = temp->next;
				}
				cout << endl;
				return;
			}
			cout << "��Ԫ��" << endl;
			return;
		}
	}

	void EnQueue(elemType e) {
		if (head != NULL && tail != NULL) {
			tail->elem = e;
			tail->next = new LNode;
			tail = tail->next;
			tail->next = NULL;
			cout << "Ԫ�ء�" << e << "����ӳɹ�" << endl;
			len++;
			return;
		}
		cout << "���ʧ��" << endl;
	}

	void DeQueue(elemType& e) {
		if (head != NULL && tail != NULL) {
			e = head->elem;
			LNode*temp = head;
			head = head->next;
			delete temp;
			cout << "���ӳɹ�" << endl;
			len--;
			return;
		}
		cout << "����ʧ��" << endl;
	}
};


int main() {
	ADT_Queue linkque;

	cout << "��ʼ����InitQueue()��" << endl;
	linkque.InitQueue();
	cout << "���б����� ";
	linkque.QueueTraverse();
	cout << endl;


	cout << endl << "��ʼ����PushEnQueue()����T1.txt����Ԫ��" << endl;
	int temp;
	char ch = ' ';
	elemType e = 0;

	fstream file("T1.txt", ios::in);

	while (ch != '\n') {
		file >> temp;
		file.get(ch);
		linkque.EnQueue(temp);
	}
	cout << endl << "����������ϣ����б�����" << endl;
	linkque.QueueTraverse();
	cout << endl << endl;

	cout << "��ʼ����QueueEmpty()" << endl;
	cout << "�����Ƿ�Ϊ�գ�" << linkque.QueueEmpty() << endl << endl;

	cout << "��ʼ����QueueLength()" << endl;
	cout << "���г��ȣ�" << linkque.QueueLength() << endl << endl;

	cout << "��ʼ����GetHead()" << endl;
	cout << "����ͷ��Ԫ�أ�" << linkque.GetHead() << endl << endl;


	cout << "��ʼ����QueueTraverse()" << endl;
	linkque.QueueTraverse();
	cout << endl << endl;
	

	cout << "��ʼ����DeQueue()" << endl;
	linkque.DeQueue(e);
	cout << "ɾ����βԪ�ء�" << e << "����Ķ��б�����" << endl;
	linkque.QueueTraverse();
	cout << endl;

	cout << "��ʼ����ClearQueue()" << endl;
	linkque.ClearQueue();
	cout << "���б�����";
	linkque.QueueTraverse();
	cout << endl;

	cout << "��ʼ����DestroyStack()" << endl;
	linkque.DestroyStack();
	cout << "���б�����";
	linkque.QueueTraverse();
	cout << endl;
}