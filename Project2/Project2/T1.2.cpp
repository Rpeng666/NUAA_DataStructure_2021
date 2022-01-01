#include<iostream>
#include<fstream>
using namespace std;

typedef int elementType;

class ADT_1 {
private:
	struct SeqList {
		elementType* data;
		int len;
		int maxlen;
	};

	SeqList* L = NULL;

public:
	//1.��ʼ������
	void InitList() {
		L = new SeqList;
		L->maxlen = 10;
		L->len = 0;
		L->data = new elementType[L->maxlen];

		for (int i = 0; i < 10; i++) {
			L->data[i] = 0;
		}
	}

	//2.�������Ա�
	void DestoryList() {
		if (L != NULL) {
			delete L->data;
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
			e = L->data[i - 1];
			cout << "��ȡ�ɹ�";
			return true;
		}
		cout << "��ȡʧ��";
		return false;
	}

	//7.��ȡԪ��λ��
	int LocateElem(elementType e) {
		if (L != NULL) {
			for (int i = 0; i < L->len; i++) {
				if (L->data[i] == e) {
					return i + 1;
				}
			}
			return 0;
		}
	}

	//8.��ȡǰ��Ԫ��
	void PriorElem(elementType e) {
		if (L != NULL) {
			int i = 0;
			for (; i < L->len; i++) {
				if (L->data[i] == e) {
					break;
				}
			}

			if (i < L->len && i>0) {
				cout << L->data[i - 1] << endl;
				return;
			}
		}
		cout << "NAN" << endl;
	}

	//9.��ȡ����Ԫ��
	void NextElem(elementType e) {
		if (L != NULL) {
			int i = 0;
			for (; i < L->len; i++) {
				if (L->data[i] == e) {
					break;
				}
			}
			if (i >= 0 && i <= L->len - 2) {
				cout << L->data[i + 1] << endl;
				return;
			}
		}
		cout << "NAN" << endl;
	}

	//10.�������ÿ��Ԫ��
	void ListTraverse() {
		if (L != NULL) {
			cout << "���Ա��ȣ�" << ListLength();
			if (L->len != 0) {
				cout << "     ÿ��Ԫ�طֱ�Ϊ��";
				for (int i = 0; i < L->len; i++) {
					cout << L->data[i] << ' ';
				}
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
				temp = L->data[i - 1];
				L->data[i - 1] = e;
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
				if (L->len + 1 > L->maxlen) {
					elementType * temp = new elementType[L->len + 10];
					for (int j = 0; j < L->len; j++) {
						temp[j] = L->data[j];
					}
					delete L->data;
					L->data = temp;
				}

				for (int p = L->len; p >= i; p--) {
					L->data[p] = L->data[p - 1];
				}
				L->data[i - 1] = e;
				L->len++;
				cout << "Ԫ�ء�" << i << "�� ����ɹ�" << endl;
				return;
			}
		}
		cout << "����ʧ��" << endl;
	}

	//13.ɾ��Ԫ�ز���
	bool DeleteElem(int i, elementType& e) {
		if (L != NULL) {
			if (i >= 1 && i <= L->len) {
				e = L->data[i - 1];
				for (int j = i - 1; j <= L->len - 2; j++) {
					L->data[j] = L->data[j + 1];
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

	//�ڶ�������ú���
	void reverse() {
		for (int i = 0; i <= (L->len - 1) / 2; i++) {
			std::swap(L->data[i], L->data[L->len - 1 - i]);
		}
	}

	//�������ȥ�غ���
	void deleteSame() {
		//�ȸ�Ԫ������
		quickSort(0, L->len - 1, L->data);
		//Ȼ����ȥ��
		int* arr = L->data;
		int p1 = 0, p2 = 1;
		while (p2 != L->len) {
			if (arr[p1] != arr[p2]) {
				p1++;
				arr[p1] = arr[p2];
			}
			p2++;
		}
		L->len = p1 + 1;
	}


	void quickSort(int left, int right, int *arr)
	{
		if (left >= right)
			return;
		int i, j, base, temp;
		i = left, j = right;
		base = arr[left];  //ȡ����ߵ���Ϊ��׼��
		while (i < j)
		{
			while (arr[j] >= base && i < j)
				j--;
			while (arr[i] <= base && i < j)
				i++;
			if (i < j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		//��׼����λ
		arr[left] = arr[i];
		arr[i] = base;
		quickSort(left, i - 1, arr);//�ݹ����
		quickSort(i + 1, right, arr);//�ݹ��ұ�
	}

	void sort() {
		for (int i = 0; i < L->len - 1; i++) {
			for (int j = 0; j < L->len - 1 - i; j++) {
				if (L->data[j] > L->data[j + 1]) {
					std::swap(L->data[j], L->data[j + 1]);
				}
			}
		}
	}
};






int main() {

	cout << "˳��ṹ��" << endl;

	int temp;

	ADT_1 list;
	list.InitList();


	fstream file("T1.txt", ios::in);
	cout << "��ʼ��T1.txt ��������" << endl;

	while (!file.eof()) {
		file >> temp;
		list.emplace(temp);
	}
	cout << "�������" << endl;

	list.ListTraverse();
	cout << endl << endl;

	cout << "��ʼ����ð������" << endl;
	list.sort();
	list.ListTraverse();

	return 0;
}
