#include<iostream>
#include<fstream>
using namespace std;
#define  MAXSIZE 100
typedef int elemType;

//顺序结构
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
		cout << "从栈底到栈顶的所有元素：";
		if (S != NULL) {
			if (S->top != -1) {
				for (int i = 0; i <= S->top; i++) {
					cout << S->elem[i] << " ";
				}
				cout << endl;
				return;
			}
			cout << "无元素" << endl;
			return;
		}
		cout << "ERROR" << endl;
	}

	void Push(elemType e) {
		if (S != NULL) {
			S->top++;
			S->elem[S->top] = e;
			cout << "元素“"<<e<<"” 压栈成功" << endl;
			return;
		}
		cout << "压栈失败" << endl;
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


	cout << "开始测试InitStack()："<< endl;
	seqstack.InitStack();
	cout << "栈遍历： ";
	seqstack.StackTraverse();
	cout << endl;


	cout << endl<<"开始测试Push()，从T1.txt读入元素" << endl;
	int temp;
	char ch = ' ';
	elemType e =0;

	fstream file("T1.txt", ios::in);

	while (ch != '\n') {
		file >> temp;
		file.get(ch);
		seqstack.Push(temp);
	}

	cout << endl<<"数据输入完毕，栈遍历：" << endl;
	seqstack.StackTraverse();
	cout << endl << endl;

	cout << "开始测试StackLength()" << endl;
	cout << "顺序栈的长度：" << seqstack.StackLength() << endl << endl;

	cout << "开始测试GetTop()" << endl;
	cout << "栈顶元素：" << seqstack.GetTop() << endl << endl;


	cout << "开始测试Pop()" << endl;
	seqstack.Pop(e);
	cout << "弹出的栈顶元素为：“"<<e<<"”后栈遍历：";
	seqstack.StackTraverse();

	seqstack.Pop(e);
	cout << "弹出的栈顶元素为：“" << e << "”后栈遍历：";
	seqstack.StackTraverse();
	cout << endl;


	cout << "开始测试StackEmpty()" << endl;
	cout << "栈是否为空：" << seqstack.StackEmpty() << endl;

	cout << "开始测试ClearStack()" << endl;
	seqstack.ClearStack();
	cout << "栈遍历：";
	seqstack.StackTraverse();
	cout << endl;

	cout << "开始测试DestroyStack()" << endl;
	seqstack.DestroyStack();
	cout << "栈遍历：";
	seqstack.StackTraverse();
	cout << endl;

}