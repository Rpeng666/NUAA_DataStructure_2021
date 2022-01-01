#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

typedef int elementType;

//����˳��ṹʵ��ADT list
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
			if (L != NULL ) {
				if(L->len == 0)
					return true;
			}
			return false;
		}

		//5.��ȡ���Ա�ĳ���
		int ListLength() {
			if (L != NULL) {
				return L->len ;
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
			if (L != NULL ) {
				cout << "���Ա��ȣ�" << ListLength();
				if (L->len != 0) {
					cout  << "     ÿ��Ԫ�طֱ�Ϊ��";
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
					cout << "����ɹ�" << endl;
					return;
				}
			}
			cout << "����ʧ��" << endl;
		}

		//13.ɾ��Ԫ�ز���
		bool DeleteElem(int i, elementType& e) {
			if (L != NULL) {
				if (i >= 1 && i <= L->len ) {
					e = L->data[i-1];
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
			for (int i = 0; i <= (L->len - 1)/2; i++) {
				std::swap(L->data[i], L->data[L->len -1- i]);
			}
		}

		//�������ȥ�غ���
		void deleteSame() {
			//�ȸ�Ԫ������
			quickSort(0, L->len-1, L->data);
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
};


int main() {
	ADT_1 seqlist;
	fstream file;
	elementType temp, e;
	char str[100], q;

	file.open("T1.txt", ios::in);

	cout << "��ʼ����InitList����" << endl;
	seqlist.InitList();
	cout << "��ʼ���������" << endl;
	cout << "���Ա�";
	seqlist.ListTraverse();
	cout << endl << endl << endl;

	cout << "��ʼ���ļ��ж�������" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << temp << " ";
		seqlist.emplace(temp);
	}
	cout << "����ȫ������ɹ�" << endl;
	seqlist.ListTraverse();
	cout << endl << endl << endl;

	cout << "��ʼ����ListEmpty����" << endl;
	if (seqlist.ListEmpty())cout << "���Ա�Ϊ��" << endl;
	else cout << "���Ա�ǿ�" << endl;
	cout << endl << endl;

	cout << "��ʼ����getelem():" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << "���Ա��е�" << temp << "��Ԫ��";
		if (seqlist.GetElem(temp, e))
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
		cout << "���Ա��е�Ԫ�ء�" << temp << "����λ���� " << seqlist.LocateElem(temp) << endl;
	}
	cout << endl << endl;

	cout << "��ʼ����PriorElem����" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << "���Ա��е�Ԫ�ء�" << temp << "����ǰ��Ԫ���ǣ�";
		seqlist.PriorElem(temp);
		
	}
	cout << endl << endl;

	cout << "��ʼ����NextElem����" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << "���Ա��е�Ԫ�ء�" << temp << "���ĺ���Ԫ���ǣ�";
		seqlist.NextElem(temp);
	}
	cout << endl << endl;

	cout << "��ʼ����SetElem����" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp >> e;
		file.get(q);
		seqlist.SetElem(temp, e);
		cout << "�����Ա��еĵ�" << temp << "��Ԫ�����óɡ�" << e << "�����Ա����£�"<<endl;
		seqlist.ListTraverse();
		cout << endl;
	}
	cout << endl << endl;

	cout << "��ʼ����InsertELem����" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp >> e;
		file.get(q);
		cout << "Ԫ�ء�" << e << "�������Ա��еĵ�"<<temp<<"��λ��";
		seqlist.InsertELem(temp, e);
		
		cout << "���Ա����£�" << endl;
		seqlist.ListTraverse();
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
		seqlist.DeleteElem(temp, e);

		cout << "�޸ĺ�����Ա�";
		seqlist.ListTraverse();
		cout << endl;
	}
	cout << endl << endl;

	cout << "��ʼ���Եڶ����ת��" << endl;
	seqlist.reverse();
	cout << "ת�ú�����Ա�";
	seqlist.ListTraverse();
	cout << endl << endl << endl;

	cout << "��ʼ���Ե������ȥ��" << endl;
	seqlist.deleteSame();
	cout << "ȥ�غ�����Ա�";
	seqlist.ListTraverse();
	cout << endl << endl << endl;

	cout << "��ʼ����ClearList����" << endl;
	seqlist.ClearList();
	cout << "��պ�����Ա�";
	seqlist.ListTraverse();
	cout << endl << endl;

	cout << "��ʼ����DestoryList����" << endl;
	seqlist.DestoryList();
	cout << "���ٺ�����Ա�";
	seqlist.ListTraverse();
	cout << endl << endl;

	return 0;
}
