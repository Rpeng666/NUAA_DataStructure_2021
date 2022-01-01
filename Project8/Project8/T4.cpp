#include<iostream>
#include<time.h>
using namespace std;
#define N 10


int * CreateRandomInt(int* rand_int, int n) {
	srand((int)time(0));
	
	for (int i = 1; i < n+1; i++) {
		rand_int[i] = rand() % 100;
	}
	return rand_int;
}


void display(int *rand_int) {
	for (int i = 1; i < N+1; i++) {
		cout << rand_int[i] << ' ';
		if (i % 20 == 0 && i != 0) {
			cout << endl;
		}
	}
}

//调整为大顶堆
void HeadAdjust(int list[], int k, int len) {
	list[0] = list[k];
	for (int i = 2 * k; i <= len; i *= 2) {
		if (i < len && list[i] < list[i + 1]) {
			i++;
		}
		if (list[0] >= list[i])break;
		else {
			list[k] = list[i];
			k = i;
		}
	}
	list[k] = list[0];
}

//建立初始大顶堆
void BuildMaxHeap(int list[], int len) {
	for (int i = len / 2; i >= 1; i--) {
		HeadAdjust(list, i, len);
	}
}

//堆排序
void HeapSort(int list[], int len) {
	BuildMaxHeap(list, len);
	for (int i = len; i > 1; i--) {
		std::swap(list[i], list[1]);
		HeadAdjust(list, 1, i - 1);
	}
}


int main() {

	int* rand_int = new int[N + 1];

	cout << "随机生成" << N << "个（0," << N << "）内的数字" << endl;
	rand_int = CreateRandomInt(rand_int, N);

	cout << endl << "展示这" << N << "个随机数字：" << endl;
	display(rand_int);

	cout << endl << endl << "开始堆排序" << endl << endl;
	HeapSort(rand_int, N);
	cout << "排序完成，开始展示：" << endl;
	display(rand_int);

	return 0;
}
