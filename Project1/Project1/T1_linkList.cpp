#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

typedef int elementType;

//����˳��ṹʵ��ADT list
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
	//1.��ʼ������
	void InitList() {
		L = new linklist;
		L->len = 0;
		L->head = NULL;
	}

	//2.�������Ա�
	void DestoryList() {
		if (L != NULL) {
			delete L->head;
			L = NULL;
			cout << "���ٳɹ�" << endl;
			return;
		}
		cout << "����ʧ��" << endl;
	}

	//3.������Ա�
	void ClearList() {
		if (L != NULL) {
			L->len = 0;
			cout << "��ճɹ�" << endl;
			return;
		}
		cout << "���ʧ��" << endl;
	}

	//4.�ж����Ա��Ƿ�Ϊ��
	bool ListEmpty() {
		if (L != NULL) {
			if (L->len == 0)
				return true;
		}
		return false;
	}

	//5.��ȡ���Ա�ĳ���
	int ListLength() {
		if (L != NULL) {
			return L->len;
		}
	}

	//6.��ȡ���Ա��Ԫ��
	bool GetElem(int i, elementType& e) {
		if (L != NULL && i >= 1 && i <= L->len) {
			link*head = L->head;
			i--;
			while (i--) {
				head = head->next;
			}
			e = head->data;
			cout << "��ȡ�ɹ�";
			return true;
		}
		cout << "��ȡʧ��";
		return false;
	}

	//7.��ȡԪ��λ��
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

	//8.��ȡǰ��Ԫ��
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

	//9.��ȡ����Ԫ��
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

	//10.�������ÿ��Ԫ��
	void ListTraverse() {
		if (L != NULL ) {
			cout << "���Ա��ȣ�" << ListLength()<<"   ���Ա��е�ÿ��Ԫ�أ�";
			if (L->len == 0) {
				cout << "��" << endl;
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

	//11.����Ԫ��
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
				cout << "���óɹ�" << endl;
				return;
			}
		}
		cout << "����ʧ��" << endl;
	}

	//12.����Ԫ��
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
				cout << "����ɹ�" << endl;
				return;
			}
		}
		cout << "����ʧ��" << endl;
	}

	//13.ɾ��Ԫ�ز���
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
				cout << "ɾ���ɹ�" << endl;
				return true;
			}
		}
		cout << "ɾ��ʧ��" << endl;
		return false;
	}

	//��ĩβ���Ԫ��
	void emplace(elementType e) {
		InsertELem(L->len + 1, e);
	}

	//�ڶ���ľ͵�����
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


	//�������ȥ�غ���
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

	cout << "��ʼ����InitList����" << endl;
	linklist.InitList();
	cout << "��ʼ���������" << endl;
	cout << "���Ա�";
	linklist.ListTraverse();
	cout << endl << endl << endl;

	cout << "��ʼ���ļ��ж�������" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << temp << " ";
		linklist.emplace(temp);
	}
	cout << "����ȫ������ɹ�" << endl;
	linklist.ListTraverse();
	cout << endl << endl << endl;

	cout << "��ʼ����ListEmpty����" << endl;
	if (linklist.ListEmpty())cout << "���Ա�Ϊ��" << endl;
	else cout << "���Ա�ǿ�" << endl;
	cout << endl << endl;

	cout << "��ʼ����getelem():" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << "���Ա��е�" << temp << "��Ԫ��";
		if (linklist.GetElem(temp, e))
			cout << "   ��ֵΪ��" << e << endl;
		else
			cout << endl;
	}
	cout << endl << endl;

	cout << "��ʼ����LocateElem����" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << "���Ա��е�Ԫ�ء�" << temp << "����λ���� " << linklist.LocateElem(temp) << endl;
	}
	cout << endl << endl;

	cout << "��ʼ����PriorElem����" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << "���Ա��е�Ԫ�ء�" << temp << "����ǰ��Ԫ���ǣ�";
		linklist.PriorElem(temp);

	}
	cout << endl << endl;

	cout << "��ʼ����NextElem����" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << "���Ա��е�Ԫ�ء�" << temp << "���ĺ���Ԫ���ǣ�";
		linklist.NextElem(temp);
	}
	cout << endl << endl;

	cout << "��ʼ����SetElem����" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp >> e;
		file.get(q);
		linklist.SetElem(temp, e);
		cout << "�����Ա��еĵ�" << temp << "��Ԫ�����óɡ�" << e << "�����Ա����£�" << endl;
		linklist.ListTraverse();
		cout << endl;
	}
	cout << endl << endl;

	cout << "��ʼ����InsertELem����" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp >> e;
		file.get(q);
		cout << "Ԫ�ء�" << e << "�������Ա��еĵ�" << temp << "��λ��";
		linklist.InsertELem(temp, e);

		cout << "���Ա����£�" << endl;
		linklist.ListTraverse();
		cout << endl;
	}
	cout << endl << endl;

	cout << "��ʼ����DeleteElem����" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << "���Ա��еĵ� " << temp << " ��λ�õ�Ԫ��";
		linklist.DeleteElem(temp, e);

		cout << "�޸ĺ�����Ա�";
		linklist.ListTraverse();
		cout << endl;
	}
	cout << endl << endl;

	cout << "��ʼ���Եڶ��������" << endl;
	linklist.reverse();
	cout << "ת�ú�����Ա�";
	linklist.ListTraverse();
	cout << endl << endl << endl;

	cout << "��ʼ���Ե������ȥ��" << endl;
	linklist.deleteSame();
	cout << "ȥ�غ�����Ա�";
	linklist.ListTraverse();
	cout << endl << endl << endl;

	cout << "��ʼ����ClearList����" << endl;
	linklist.ClearList();
	cout << "��պ�����Ա�";
	linklist.ListTraverse();
	cout << endl << endl;

	cout << "��ʼ����DestoryList����" << endl;
	linklist.DestoryList();
	cout << "���ٺ�����Ա�";
	linklist.ListTraverse();
	cout << endl << endl;

	return 0;
}
