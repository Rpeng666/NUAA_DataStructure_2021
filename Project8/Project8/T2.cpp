#include<iostream>
#include<random>
using namespace std;
#define N 10

int * CreateRandomInt(int* rand_int, int n) {
	default_random_engine e;

	for (int i = 0; i < n; i++) {
		rand_int[i] = e() % 100;
	}
	return rand_int;
}


void display(int *rand_int) {
	for (int i = 0; i < N; i++) {
		cout << rand_int[i] << ' ';
		if (i % 20 == 0 && i != 0) {
			cout << endl;
		}
	}
}


void exchangeSort(int * rand_int) {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1-i; j++) {
			if (rand_int[j] > rand_int[j + 1]) {
				std::swap(rand_int[j], rand_int[j + 1]);
			}
		}
	}
}


void selectSort(int *rand_int) {
	int min_temp;
	int k = 0;

	for (int i = 0; i < N; i++) {
		min_temp = rand_int[i];
		for (int j = i + 1; j < N; j++) {
			if (rand_int[j] < min_temp) {
				min_temp = rand_int[j];
				k = j;
			}
		}

		std::swap(rand_int[i], rand_int[k]);
	}
}


void mergeSort(int *rand_int, int low,int high) {
	if (low > high)return;
	if (low == high + 1 || low == high) {
		if (rand_int[low] > rand_int[high]) {
			std::swap(rand_int[low], rand_int[high]);
		}
		return;
	}

	int mid = (low + high) / 2;
	mergeSort(rand_int, low, mid);
	mergeSort(rand_int, mid + 1, high);

	int i = low,j = mid+1, k = low;
	
	for (int i = low; i < high; i++) {
		for (int j = low; j < high +low - i; j++) {
			if (rand_int[j] > rand_int[j + 1]) {
				std::swap(rand_int[j], rand_int[j + 1]);
			}
		}
	}
}


int main() {

	int* rand_int = new int[N];

	cout << "随机生成" << N << "个（0," << N << "）内的数字" << endl;
	rand_int = CreateRandomInt(rand_int, N);

	cout << endl << "展示这100个随机数字：" << endl;
	display(rand_int);

	cout << endl << endl << "开始交换排序" << endl;
	exchangeSort(rand_int);
	cout << "排序完成，开始展示" << endl;
	display(rand_int);
	cout << endl;


	rand_int = CreateRandomInt(rand_int, N);
	cout << endl << endl << "开始选择排序" << endl;
	selectSort(rand_int);
	cout << "排序完成，开始展示" << endl;
	display(rand_int);
	cout << endl;


	rand_int = CreateRandomInt(rand_int, N);
	cout << endl << endl << "开始归并排序" << endl;
	mergeSort(rand_int, 0, N-1);
	cout << "排序完成，开始展示" << endl;
	display(rand_int);
	cout << endl;

	return 0;
}