#include<iostream>
#include<random>
using namespace std;
#define N 100

int * CreateRandomInt(int* rand_int, int n) {
	default_random_engine e;

	for (int i = 0; i < n; i++) {
		rand_int[i] = e()%100;
	}
	return rand_int;
}

int Paritition(int* list, int low, int high) {
	int temp = list[low];

	while (low < high) {
		while (low < high && list[high] >= temp) {
			high--;
		}
		list[low] = list[high];

		while (low < high && list[low] <= temp) {
			low++;
		}
		list[high] = list[low];
	}
	list[low] = temp;
	return low;
}

void QuickSort(int* list, int low, int high) {
	if (low < high) {
		int temp = Paritition(list, low, high);
		QuickSort(list, low, temp - 1);
		QuickSort(list, temp + 1, high);
	}
}

void display(int *rand_int) {
	for (int i = 0; i < N; i++) {
		cout << rand_int[i] << ' ';
		if (i % 20 == 0 && i != 0) {
			cout << endl;
		}
	}
}


int main() {

	int* rand_int = new int[N];

	cout << "随机生成"<<N<<"个（0,"<<N<<"）内的数字" << endl;
	rand_int = CreateRandomInt(rand_int, N);

	cout << endl << "展示这100个随机数字：" << endl;
	display(rand_int);

	cout << endl << endl << "开始快速排序" << endl;
	QuickSort(rand_int, 0, N - 1);
	cout << "排序完成，开始展示" << endl;
	display(rand_int);
	cout << endl;

	return 0;
}