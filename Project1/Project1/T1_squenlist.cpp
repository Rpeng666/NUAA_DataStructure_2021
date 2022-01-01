#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

typedef int elementType;

//采用顺序结构实现ADT list
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
			if (L != NULL ) {
				if(L->len == 0)
					return true;
			}
			return false;
		}

		//5.获取线性表的长度
		int ListLength() {
			if (L != NULL) {
				return L->len ;
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
			if (L != NULL ) {
				cout << "线性表长度：" << ListLength();
				if (L->len != 0) {
					cout  << "     每个元素分别为：";
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
					cout << "插入成功" << endl;
					return;
				}
			}
			cout << "插入失败" << endl;
		}

		//13.删除元素操作
		bool DeleteElem(int i, elementType& e) {
			if (L != NULL) {
				if (i >= 1 && i <= L->len ) {
					e = L->data[i-1];
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
			for (int i = 0; i <= (L->len - 1)/2; i++) {
				std::swap(L->data[i], L->data[L->len -1- i]);
			}
		}

		//第三题的去重函数
		void deleteSame() {
			//先给元素排序
			quickSort(0, L->len-1, L->data);
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
};


int main() {
	ADT_1 seqlist;
	fstream file;
	elementType temp, e;
	char str[100], q;

	file.open("T1.txt", ios::in);

	cout << "开始测试InitList（）" << endl;
	seqlist.InitList();
	cout << "初始化操作完成" << endl;
	cout << "线性表：";
	seqlist.ListTraverse();
	cout << endl << endl << endl;

	cout << "开始从文件中读入数字" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << temp << " ";
		seqlist.emplace(temp);
	}
	cout << "数字全部输入成功" << endl;
	seqlist.ListTraverse();
	cout << endl << endl << endl;

	cout << "开始测试ListEmpty（）" << endl;
	if (seqlist.ListEmpty())cout << "线性表为空" << endl;
	else cout << "线性表非空" << endl;
	cout << endl << endl;

	cout << "开始测试getelem():" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << "线性表中第" << temp << "个元素";
		if (seqlist.GetElem(temp, e))
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
		cout << "线性表中的元素“" << temp << "”的位置是 " << seqlist.LocateElem(temp) << endl;
	}
	cout << endl << endl;

	cout << "开始测试PriorElem（）" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << "线性表中的元素“" << temp << "”的前置元素是：";
		seqlist.PriorElem(temp);
		
	}
	cout << endl << endl;

	cout << "开始测试NextElem（）" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp;
		file.get(q);
		cout << "线性表中的元素“" << temp << "”的后置元素是：";
		seqlist.NextElem(temp);
	}
	cout << endl << endl;

	cout << "开始测试SetElem（）" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp >> e;
		file.get(q);
		seqlist.SetElem(temp, e);
		cout << "将线性表中的第" << temp << "个元素设置成“" << e << "”线性表如下："<<endl;
		seqlist.ListTraverse();
		cout << endl;
	}
	cout << endl << endl;

	cout << "开始测试InsertELem（）" << endl;
	file >> str;
	file.get(q);
	while (q != '\n') {
		file >> temp >> e;
		file.get(q);
		cout << "元素“" << e << "”在线性表中的第"<<temp<<"个位置";
		seqlist.InsertELem(temp, e);
		
		cout << "线性表如下：" << endl;
		seqlist.ListTraverse();
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
		seqlist.DeleteElem(temp, e);

		cout << "修改后的线性表：";
		seqlist.ListTraverse();
		cout << endl;
	}
	cout << endl << endl;

	cout << "开始测试第二题的转置" << endl;
	seqlist.reverse();
	cout << "转置后的线性表：";
	seqlist.ListTraverse();
	cout << endl << endl << endl;

	cout << "开始测试第三题的去重" << endl;
	seqlist.deleteSame();
	cout << "去重后的线性表：";
	seqlist.ListTraverse();
	cout << endl << endl << endl;

	cout << "开始测试ClearList（）" << endl;
	seqlist.ClearList();
	cout << "清空后的线性表：";
	seqlist.ListTraverse();
	cout << endl << endl;

	cout << "开始测试DestoryList（）" << endl;
	seqlist.DestoryList();
	cout << "销毁后的线性表：";
	seqlist.ListTraverse();
	cout << endl << endl;

	return 0;
}
