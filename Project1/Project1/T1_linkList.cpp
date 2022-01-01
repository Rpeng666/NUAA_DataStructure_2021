#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

typedef int elementType;

//采用顺序结构实现ADT list
class ADT_2 {
private:
	struct link {
		elementType data;
		link* next;
	};
	struct linklist {
		link* head;
		int len;
	};

	linklist* L = NULL;

public:
	//1.初始化操作
	void InitList() {
		L = new linklist;
		L->len = 0;
		L->head = NULL;
	}

	//2.销毁线性表
	void DestoryList() {
		if (L != NULL) {
			delete L->head;
			L = NULL;
			cout << "销毁成功" << endl;
			return;
		}
		cout << "销毁失败" << endl;
	}

	//3.清空线性表
	void ClearList() {
		if (L != NULL) {
			L->len = 0;
			cout << "清空成功" << endl;
			return;
		}
		cout << "清空失败" << endl;
	}

	//4.判断线性表是否为空
	bool ListEmpty() {
		if (L != NULL) {
			if (L->len == 0)
				return true;
		}
		return false;
	}

	//5.获取线性表的长度
	int ListLength() {
		if (L != NULL) {
			return L->len;
		}
	}

	//6.获取线性表的元素
	bool GetElem(int i, elementType& e) {
		if (L != NULL && i >= 1 && i <= L->len) {
			link*head = L->head;
			i--;
			while (i--) {
				head = head->next;
			}
			e = head->data;
			cout << "获取成功";
			return true;
		}
		cout << "获取失败";
		return false;
	}

	//7.获取元素位置
	int LocateElem(elementType e) {
		if (L != NULL) {
			link*head = L->head;
			for (int i = 1; i <= L->len; i++) {
				if (head->data == e) {
					return i;
				}
				head = head->next;
			}
			return 0;
		}
	}

	//8.获取前驱元素
	void PriorElem(elementType e) {
		if (L != NULL) {
			int i = 1;
			link* head = L->head;
			if (head->data == e) {
				cout << "NAN" << endl;
				return;
			}
			for (; i <= L->len - 1; i++) {
				if (head->next->data == e) break;
				head = head->next;
			}

			if (i != L->len) {
				cout << head->data << endl;
				return;
			}
		}
		cout << "NAN" << endl;
	}

	//9.获取后驱元素
	void NextElem(elementType e) {
		if (L != NULL) {
			int i = 1;
			link* head = L->head;
			for (; i <= L->len-1; i++) {
				if (head->data == e) {
					break;
				}
				head = head->next;
			}
			if (i != L->len) {
				cout << head->next->data << endl;
				return;
			}
		}
		cout << "NAN" << endl;
	}

	//10.依次输出每个元素
	void ListTraverse() {
		if (L != NULL ) {
			cout << "线性表长度：" << ListLength()<<"   线性表中的每个元素：";
			if (L->len == 0) {
				cout << "无" << endl;
				return;
			}
			link* head = L->head;
			while (head != NULL ) {
				cout << head->data<<" ";
				head = head->next;
			}
			return;
		}
		cout << "error" << endl;
	}

	//11.设置元素
	void SetElem(int i, elementType e) {
		elementType temp;
		if (L != NULL) {
			if (i >= 1 && i <= L->len) {
				link*head = L->head;
				i--;
				while (i--) {
					head = head->next;
				}
				head->data = e;
				cout << "设置成功" << endl;
				return;
			}
		}
		cout << "设置失败" << endl;
	}

	//12.插入元素
	void InsertELem(int i, elementType e) {
		if (L != NULL) {
			if (i >= 1 && i <= L->len + 1) {
				link* head = L->head,*temp = L->head;
				link* T = new link;
				T->data = e;
				if (i == 1) {
					T->next = head;
					L->head = T;
				}
				else {
					i--;
					while (i--) {
						temp = head;
						head = head->next;
					}
					temp->next = T;
					T->next = head;
				}
				L->len++;
				cout << "插入成功" << endl;
				return;
			}
		}
		cout << "插入失败" << endl;
	}

	//13.删除元素操作
	bool DeleteElem(int i, elementType& e) {
		if (L != NULL) {
			if (i >= 1 && i <= L->len) {
				link*head = L->head, *temp = L->head;
				if (i == 1) {
					temp = L->head;
					L->head = L->head->next;
					delete temp;
				}
				else {
					i--;
					while (i--) {
						temp = head;
						head = head->next;
					}
					temp->next = head->next;
					delete head;
				}
				L->len--;
				cout << "删除成功" << endl;
				return true;
			}
		}
		cout << "删除失败" << endl;
		return false;
	}

	//向末尾添加元素
	void emplace(elementType e) {
		InsertELem(L->len + 1, e);
	}

	//第二题的就地逆置
	void reverse() {
		if (L != NULL) {
			link* head = L->head;
			link* tail = L->head;
			link*temp;
			while (tail->next != NULL) tail = tail->next;
			L->head = tail;

			while (head != L->head) {
				temp = head;
				head = head->next;
				temp->next = tail->next;
				tail->next = temp;
			}
			
			return;
		}
		cout << "error" << endl;
	}


	//第三题的去重函数
	void deleteSame() {
		link* head = L->head;
		link *p, *s, *q;

		p = head->next;
		if (p->next == NULL)return;

		while (p != NULL){
			q = p;
			while (q->next != NULL){
				if (q->next->data == p->data || q->next->data == head->data){
					s = q->next;
					q->next = s->next;
					free(s);
					L->len--;
				}
				else {
					q = q->next;
				}
			}
			p = p->next;
		}
	}
};


int main() {
	ADT_2 linklist;
	fstream file;
	elementType temp, e;
	char str[100], q;

	file.open("T1.txt", ios::in);

	cout << "开始测试InitList（）" << endl;
	linklist.InitList();
	cout << "初始化操作完成" << endl;
	cout << "线性表：";
	linklist.ListTraverse();
	cout << endl << endl << endl;

	cout << "开始从文件中读入数字" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << temp << " ";
		linklist.emplace(temp);
	}
	cout << "数字全部输入成功" << endl;
	linklist.ListTraverse();
	cout << endl << endl << endl;

	cout << "开始测试ListEmpty（）" << endl;
	if (linklist.ListEmpty())cout << "线性表为空" << endl;
	else cout << "线性表非空" << endl;
	cout << endl << endl;

	cout << "开始测试getelem():" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << "线性表中第" << temp << "个元素";
		if (linklist.GetElem(temp, e))
			cout << "   其值为：" << e << endl;
		else
			cout << endl;
	}
	cout << endl << endl;

	cout << "开始测试LocateElem（）" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << "线性表中的元素“" << temp << "”的位置是 " << linklist.LocateElem(temp) << endl;
	}
	cout << endl << endl;

	cout << "开始测试PriorElem（）" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << "线性表中的元素“" << temp << "”的前置元素是：";
		linklist.PriorElem(temp);

	}
	cout << endl << endl;

	cout << "开始测试NextElem（）" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << "线性表中的元素“" << temp << "”的后置元素是：";
		linklist.NextElem(temp);
	}
	cout << endl << endl;

	cout << "开始测试SetElem（）" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp >> e;
		file.get(q);
		linklist.SetElem(temp, e);
		cout << "将线性表中的第" << temp << "个元素设置成“" << e << "”线性表如下：" << endl;
		linklist.ListTraverse();
		cout << endl;
	}
	cout << endl << endl;

	cout << "开始测试InsertELem（）" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp >> e;
		file.get(q);
		cout << "元素“" << e << "”在线性表中的第" << temp << "个位置";
		linklist.InsertELem(temp, e);

		cout << "线性表如下：" << endl;
		linklist.ListTraverse();
		cout << endl;
	}
	cout << endl << endl;

	cout << "开始测试DeleteElem（）" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << "线性表中的第 " << temp << " 个位置的元素";
		linklist.DeleteElem(temp, e);

		cout << "修改后的线性表：";
		linklist.ListTraverse();
		cout << endl;
	}
	cout << endl << endl;

	cout << "开始测试第二题的逆置" << endl;
	linklist.reverse();
	cout << "转置后的线性表：";
	linklist.ListTraverse();
	cout << endl << endl << endl;

	cout << "开始测试第三题的去重" << endl;
	linklist.deleteSame();
	cout << "去重后的线性表：";
	linklist.ListTraverse();
	cout << endl << endl << endl;

	cout << "开始测试ClearList（）" << endl;
	linklist.ClearList();
	cout << "清空后的线性表：";
	linklist.ListTraverse();
	cout << endl << endl;

	cout << "开始测试DestoryList（）" << endl;
	linklist.DestoryList();
	cout << "销毁后的线性表：";
	linklist.ListTraverse();
	cout << endl << endl;

	return 0;
}
