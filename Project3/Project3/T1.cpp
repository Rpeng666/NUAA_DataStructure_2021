#include<iostream>
#include<fstream>
using namespace std;
#define  MAXSIZE 100
typedef int elemType;

//˳��ṹ
class ADT_Stack {
private:
	struct Stack {
		elemType  *elem;
		int  top;
	};
	Stack * S;

public:
	void InitStack() {
		S = new Stack;
		S->elem = new elemType[(sizeof(elemType)*MAXSIZE)];
		S->top = -1;
	}

	void DestroyStack() {
		if (S != NULL) {
			delete S->elem;
			delete S;
		}
		S = NULL;
	}

	void ClearStack() {
		if (S != NULL) {
			S->top = -1;
		}
	}

	bool StackEmpty() {
		if (S != NULL) {
			return S->top == -1;
		}
	}

	int StackLength() {
		if (S != NULL) {
			return S->top + 1;
		}
		return -1;
	}

	elemType GetTop() {
		if (S != NULL && S->top != -1) {
			return S->elem[S->top];
		}
		return NULL;
	}

	void StackTraverse() {
		cout << "��ջ�׵�ջ��������Ԫ�أ�";
		if (S != NULL) {
			if (S->top != -1) {
				for (int i = 0; i <= S->top; i++) {
					cout << S->elem[i] << " ";
				}
				cout << endl;
				return;
			}
			cout << "��Ԫ��" << endl;
			return;
		}
		cout << "ERROR" << endl;
	}

	void Push(elemType e) {
		if (S != NULL) {
			S->top++;
			S->elem[S->top] = e;
			cout << "Ԫ�ء�"<<e<<"�� ѹջ�ɹ�" << endl;
			return;
		}
		cout << "ѹջʧ��" << endl;
	}

	void Pop(elemType &e) {
		if (S != NULL && S->top != -1) {
			e = S->elem[S->top];
			S->top--;
		}
	}
};



int main() {
	ADT_Stack seqstack;


	cout << "��ʼ����InitStack()��"<< endl;
	seqstack.InitStack();
	cout << "ջ������ ";
	seqstack.StackTraverse();
	cout << endl;


	cout << endl<<"��ʼ����Push()����T1.txt����Ԫ��" << endl;
	int temp;
	char ch = ' ';
	elemType e =0;

	fstream file("T1.txt", ios::in);

	while (ch != '\n') {
		file >> temp;
		file.get(ch);
		seqstack.Push(temp);
	}

	cout << endl<<"����������ϣ�ջ������" << endl;
	seqstack.StackTraverse();
	cout << endl << endl;

	cout << "��ʼ����StackLength()" << endl;
	cout << "˳��ջ�ĳ��ȣ�" << seqstack.StackLength() << endl << endl;

	cout << "��ʼ����GetTop()" << endl;
	cout << "ջ��Ԫ�أ�" << seqstack.GetTop() << endl << endl;


	cout << "��ʼ����Pop()" << endl;
	seqstack.Pop(e);
	cout << "������ջ��Ԫ��Ϊ����"<<e<<"����ջ������";
	seqstack.StackTraverse();

	seqstack.Pop(e);
	cout << "������ջ��Ԫ��Ϊ����" << e << "����ջ������";
	seqstack.StackTraverse();
	cout << endl;


	cout << "��ʼ����StackEmpty()" << endl;
	cout << "ջ�Ƿ�Ϊ�գ�" << seqstack.StackEmpty() << endl;

	cout << "��ʼ����ClearStack()" << endl;
	seqstack.ClearStack();
	cout << "ջ������";
	seqstack.StackTraverse();
	cout << endl;

	cout << "��ʼ����DestroyStack()" << endl;
	seqstack.DestroyStack();
	cout << "ջ������";
	seqstack.StackTraverse();
	cout << endl;

}