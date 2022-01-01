#include<iostream>
#include<fstream>
using namespace std;
#define  MAXSIZE 100
typedef int elemType;

//链式结构
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
		else if (len == 0)cout << "无元素" << endl;
		else {
			cout << "队列长度：" << len << "  队列元素：";
			LNode* temp = head;
			if (len != 0) {
				while (temp != tail) {
					cout << temp->elem << " ";
					temp = temp->next;
				}
				cout << endl;
				return;
			}
			cout << "无元素" << endl;
			return;
		}
	}

	void EnQueue(elemType e) {
		if (head != NULL && tail != NULL) {
			tail->elem = e;
			tail->next = new LNode;
			tail = tail->next;
			tail->next = NULL;
			cout << "元素“" << e << "”入队成功" << endl;
			len++;
			return;
		}
		cout << "入队失败" << endl;
	}

	void DeQueue(elemType& e) {
		if (head != NULL && tail != NULL) {
			e = head->elem;
			LNode*temp = head;
			head = head->next;
			delete temp;
			cout << "出队成功" << endl;
			len--;
			return;
		}
		cout << "出队失败" << endl;
	}
};


int main() {
	ADT_Queue linkque;

	cout << "开始测试InitQueue()：" << endl;
	linkque.InitQueue();
	cout << "队列遍历： ";
	linkque.QueueTraverse();
	cout << endl;


	cout << endl << "开始测试PushEnQueue()，从T1.txt读入元素" << endl;
	int temp;
	char ch = ' ';
	elemType e = 0;

	fstream file("T1.txt", ios::in);

	while (ch != '\n') {
		file >> temp;
		file.get(ch);
		linkque.EnQueue(temp);
	}
	cout << endl << "数据输入完毕，队列遍历：" << endl;
	linkque.QueueTraverse();
	cout << endl << endl;

	cout << "开始测试QueueEmpty()" << endl;
	cout << "队列是否为空：" << linkque.QueueEmpty() << endl << endl;

	cout << "开始测试QueueLength()" << endl;
	cout << "队列长度：" << linkque.QueueLength() << endl << endl;

	cout << "开始测试GetHead()" << endl;
	cout << "队列头部元素：" << linkque.GetHead() << endl << endl;


	cout << "开始测试QueueTraverse()" << endl;
	linkque.QueueTraverse();
	cout << endl << endl;
	

	cout << "开始测试DeQueue()" << endl;
	linkque.DeQueue(e);
	cout << "删除队尾元素“" << e << "”后的队列遍历：" << endl;
	linkque.QueueTraverse();
	cout << endl;

	cout << "开始测试ClearQueue()" << endl;
	linkque.ClearQueue();
	cout << "队列遍历：";
	linkque.QueueTraverse();
	cout << endl;

	cout << "开始测试DestroyStack()" << endl;
	linkque.DestroyStack();
	cout << "队列遍历：";
	linkque.QueueTraverse();
	cout << endl;
}