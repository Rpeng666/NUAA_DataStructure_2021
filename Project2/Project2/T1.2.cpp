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
	//1.初始化操作
	void InitList() {
		L = new SeqList;
		L->maxlen = 10;
		L->len = 0;
		L->data = new elementType[L->maxlen];

		for (int i = 0; i < 10; i++) {
			L->data[i] = 0;
		}
	}

	//2.销毁线性表
	void DestoryList() {
		if (L != NULL) {
			delete L->data;
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
			e = L->data[i - 1];
			cout << "获取成功";
			return true;
		}
		cout << "获取失败";
		return false;
	}

	//7.获取元素位置
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

	//8.获取前驱元素
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

	//9.获取后驱元素
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

	//10.依次输出每个元素
	void ListTraverse() {
		if (L != NULL) {
			cout << "线性表长度：" << ListLength();
			if (L->len != 0) {
				cout << "     每个元素分别为：";
				for (int i = 0; i < L->len; i++) {
					cout << L->data[i] << ' ';
				}
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
				temp = L->data[i - 1];
				L->data[i - 1] = e;
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
				cout << "元素“" << i << "” 插入成功" << endl;
				return;
			}
		}
		cout << "插入失败" << endl;
	}

	//13.删除元素操作
	bool DeleteElem(int i, elementType& e) {
		if (L != NULL) {
			if (i >= 1 && i <= L->len) {
				e = L->data[i - 1];
				for (int j = i - 1; j <= L->len - 2; j++) {
					L->data[j] = L->data[j + 1];
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

	//第二题的逆置函数
	void reverse() {
		for (int i = 0; i <= (L->len - 1) / 2; i++) {
			std::swap(L->data[i], L->data[L->len - 1 - i]);
		}
	}

	//第三题的去重函数
	void deleteSame() {
		//先给元素排序
		quickSort(0, L->len - 1, L->data);
		//然后再去重
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
		base = arr[left];  //取最左边的数为基准数
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
		//基准数归位
		arr[left] = arr[i];
		arr[i] = base;
		quickSort(left, i - 1, arr);//递归左边
		quickSort(i + 1, right, arr);//递归右边
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

	cout << "顺序结构：" << endl;

	int temp;

	ADT_1 list;
	list.InitList();


	fstream file("T1.txt", ios::in);
	cout << "开始从T1.txt 读入数据" << endl;

	while (!file.eof()) {
		file >> temp;
		list.emplace(temp);
	}
	cout << "读入完毕" << endl;

	list.ListTraverse();
	cout << endl << endl;

	cout << "开始测试冒泡排序" << endl;
	list.sort();
	list.ListTraverse();

	return 0;
}
