#include<iostream>
#include<fstream>
#include<ctime>
#include<algorithm>
#include<stack>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#define N 50000

int nums[N];
int tempList[N];

void createRandomNum() {
	srand((int)time(0));
	string filename;
	for (int i = 3; i <= 10; i++) {
		filename = "random";
		if (i != 10) filename += char(i + '0');
		else filename += "10";

		filename += ".txt";

		for (int i = 0; i < N; i++) {
			nums[i] = rand() % 50000;
		}
		//随机数字
		fstream file(filename.c_str(), ios::out);
		for (int i = 0; i < N; i++) {
			file << nums[i] << ' ';
			if (i != 0 && i % 30 == 0) {
				file << endl;
			}
		}
		file.close();

		if (i == 3) {
			//正序数字
			sort(nums, nums + N);

			file.open("positiveSeq.txt", ios::out);
			for (int i = 0; i < N; i++) {
				file << nums[i] << ' ';
				if (i != 0 && i % 30 == 0) {
					file << endl;
				}
			}
			file.close();

			//逆序数字
			file.open("negativeSeq.txt", ios::out);
			for (int i = N - 1; i >= 0; i--) {
				file << nums[i] << ' ';
				if (i != 0 && i % 30 == 0) {
					file << endl;
				}
			}
			file.close();
		}
	}
}

void readFile(string name) {
	fstream file(name, ios::in);
	int temp = 0,i=0;

	while (!file.eof()) {
		file >> temp;
		if (file.fail())break;

		nums[i++] = temp;
	}
	file.close();
}

void bubbleSort(string name) {
	cout << "冒泡排序(" << name <<"):" << endl;
	readFile(name);

	clock_t startTime, endTime;
	startTime = clock();

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N-1 - i; j++) {
			if (nums[j] > nums[j + 1]) {
				std::swap(nums[j], nums[j + 1]);
			}
		}
	}

	endTime = clock();

	cout << "前20个元素：";
	for (int i = 0; i < 20; i++) {
		cout << nums[i] << ' ';
	}
	
	cout << "排序用时：" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}

void insertSort(string name) {
	cout << "插入排序(" << name << "):" << endl;
	readFile(name);

	clock_t startTime, endTime;
	startTime = clock();

	for (int i = 1; i < N; i++) {
		int j = i;
		while (j >= 1 &&nums[j] < nums[j - 1]) {
			std::swap(nums[j], nums[j - 1]);
			j--;
		}
	}


	endTime = clock();

	cout << "前20个元素：";
	for (int i = 0; i < 20; i++) {
		cout << nums[i] << ' ';
	}

	cout << "排序用时：" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}

void shellSort(string name) {
	cout << "希尔排序(" << name << "):" << endl;
	readFile(name);

	clock_t startTime, endTime;
	startTime = clock();

	int h = 1;
	while (h < N / 3) {
		h = h * 3 + 1;
	}
	//三重循环
	while (h >= 1) {
		for (int j = h; j < N; j ++) {
			for (int i = j; i >= h && nums[i] < nums[i - h]; i -= h) {
				std::swap(nums[i], nums[i - h]);
			}
		}
		h /= 3;
	}


	endTime = clock();

	cout << "前20个元素：";
	for (int i = 0; i < 20; i++) {
		cout << nums[i] << ' ';
	}

	cout << "排序用时：" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}


//非递归版本的快排
void Qsort2(int low, int high) {
	stack<pair<int,int>> st;
	st.emplace(make_pair(low, high));

	while (!st.empty()) {
		pair<int, int> t = st.top();
		st.pop();

		low = t.first;
		high = t.second;

		if (low < high) {

			int mid = low, left = low, right = high;
			int temp = nums[left];

			while (left < right) {

				while (left < right && nums[right] >= temp) right--;
				nums[left] = nums[right];

				while (left < right && nums[left] <= temp) left++;
				nums[right] = nums[left];
			}
			nums[left] = temp;

			st.emplace(make_pair(left + 1, high));
			st.emplace(make_pair(low, left - 1));
		}
	}
}

void quickSort(string name) {
	cout << "快速排序(" << name << "):" << endl;
	readFile(name);

	clock_t startTime, endTime;
	startTime = clock();

	//Qsort1(nums, 0, N - 1);  递归版本，50000个数字栈爆了
	Qsort2(0, N - 1);

	endTime = clock();

	cout << "前20个元素：";
	for (int i = 0; i < 20; i++) {
		cout << nums[i] << ' ';
	}

	cout << "排序用时：" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}

void selectSort(string name) {
	cout << "选择排序(" << name << "):" << endl;
	readFile(name);

	clock_t startTime, endTime;
	startTime = clock();

	for (int i = 0; i < N; i++) {
		int minNum = nums[i], place = i;
		int j = i;
		for (; j < N; j++) {
			if (nums[j] < minNum) {
				minNum = nums[j];
				place = j;
			}
		}
		std::swap(nums[i], nums[place]);
	}

	endTime = clock();

	cout << "前20个元素：";
	for (int i = 0; i < 20; i++) {
		cout << nums[i] << ' ';
	}

	cout << "排序用时：" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}

//调整大顶堆
void adjustHeap(int k,int length) {
	while (k < length) {
		if (2 * k + 2 < length) {
			if (nums[k] >= nums[2 * k + 1] && nums[k] >= nums[2 * k + 2])break;
			else {
				if (nums[2 * k + 1] > nums[2 * k + 2]) {
					std::swap(nums[k], nums[2 * k + 1]);
					k = 2 * k + 1;
				}
				else {
					std::swap(nums[k], nums[2 * k + 2]);
					k = 2 * k + 2;
				}
			}
		}
		else if (2 * k + 1 < length) {
			if (nums[2 * k + 1] > nums[k]) {
				std::swap(nums[2 * k + 1], nums[k]);
				k = 2 * k + 1;
			}
			break;
		}
		else break;
	}
}


void heapSort(string name) {
	cout << "堆排序(" << name << "):" << endl;
	readFile(name);

	clock_t startTime, endTime;
	startTime = clock();

	int len = N;
	//建立初始大顶堆
	for (int i = N / 2 - 1; i >= 0; i--) {
		adjustHeap( i, len);
	}
	//开始堆排序
	for (int i = N  - 1; i >= 0; i--) {
		std::swap(nums[i], nums[0]);
		adjustHeap( 0, i);
	}

	endTime = clock();

	cout << "前20个元素：";
	for (int i = 0; i < 20; i++) {
		cout << nums[i] << ' ';
	}

	cout << "排序用时：" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}

struct Status {
	int left;
	int right;
	int temp;
	Status(int left = -1, int right = -1, int temp = -1) {
		this->left = left;
		this->right = right;
		this->temp = temp;
	}
};

//归并排序
void Merge(int A[], int TmpA[], int L, int R, int RightEnd) {
	int LeftEnd, NumElements, Tmp;
	int i;

	LeftEnd = R - 1; /* 左边终点位置 */
	Tmp = L;         /* 有序序列的起始位置 */
	NumElements = RightEnd - L + 1;

	while (L <= LeftEnd && R <= RightEnd) {
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++]; /* 将左边元素复制到TmpA */
		else
			TmpA[Tmp++] = A[R++]; /* 将右边元素复制到TmpA */
	}

	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++]; /* 直接复制左边剩下的 */
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++]; /* 直接复制右边剩下的 */
	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd];   /*将有序的TmpA[]复制回A[] */
}

/* length = 当前有序子列的长度*/
void Merge_pass(int A[], int TmpA[], int n, int length)
{ /* 两两归并相邻有序子列 */
	int i, j;

	for (i = 0; i <= n - 2 * length; i += 2 * length)
		Merge(A, TmpA, i, i + length, i + 2 * length - 1);
	if (i + length < n) /* 归并最后2个子列*/
		Merge(A, TmpA, i, i + length, n - 1);
}

void mergeSort(string name) {
	int n = N;
	int length;
	int* TmpA;

	cout << "归并排序(" << name << "):" << endl;
	readFile(name);

	clock_t startTime, endTime;
	startTime = clock();

	length = 1; /* 初始化子序列长度*/
	TmpA = (int*)malloc(n * sizeof(int));
	if (TmpA != NULL) {
		while (length < n) {
			Merge_pass(nums, TmpA, n, length);
			length *= 2;
		}
		free(TmpA);
	}
	else printf("空间不足");

	endTime = clock();

	cout << "前20个元素：";
	for (int i = 0; i < 20; i++) {
		cout << nums[i] << ' ';
	}

	cout << "排序用时：" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}

//基数排序
void radixsort(string name) {
	cout << "基数排序(" << name << "):" << endl;
	readFile(name);

	clock_t startTime, endTime;
	startTime = clock();
	int maxNums = -999, d = 0;
	for (int i = 0; i < N; i++) maxNums = maxNums > nums[i] ? maxNums : nums[i];
	
	while (int(maxNums / pow(10, d)) != 0)d++;

	int tmp[N];
	int count[10]; //计数器
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++){
		for (j = 0; j < 10; j++)count[j] = 0; 

		for (j = 0; j < N; j++){
			k = (nums[j] / radix) % 10; 
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; 
		for (j = N - 1; j >= 0; j--) 
		{
			k = (nums[j] / radix) % 10;
			tmp[count[k] - 1] = nums[j];
			count[k]--;
		}
		for (j = 0; j < N; j++) 
			nums[j] = tmp[j];
		radix = radix * 10;
	}

	endTime = clock();

	cout << "前20个元素：";
	for (int i = 0; i < 20; i++) {
		cout << nums[i] << ' ';
	}

	cout << "排序用时：" << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}


int main() {
	createRandomNum();

	shellSort("positiveSeq.txt");
	shellSort("negativeSeq.txt");
	shellSort("random3.txt");
	shellSort("random4.txt");
	shellSort("random5.txt");
	shellSort("random6.txt");
	shellSort("random7.txt");
	shellSort("random8.txt");
	shellSort("random9.txt");
	shellSort("random10.txt");
	cout << endl << endl;

	quickSort("positiveSeq.txt");
	quickSort("negativeSeq.txt");
	quickSort("random3.txt");
	quickSort("random4txt");
	quickSort("random5.txt");
	quickSort("random6.txt");
	quickSort("random7.txt");
	quickSort("random8.txt");
	quickSort("random9.txt");
	quickSort("random10.txt");
	cout << endl << endl;

	heapSort("positiveSeq.txt");
	heapSort("negativeSeq.txt");
	heapSort("random3.txt");
	heapSort("random4.txt");
	heapSort("random5.txt");
	heapSort("random6.txt");
	heapSort("random7.txt");
	heapSort("random8.txt");
	heapSort("random9.txt");
	heapSort("random10.txt");
	cout << endl << endl;

	radixsort("positiveSeq.txt");
	radixsort("negativeSeq.txt");
	radixsort("random3.txt");
	radixsort("random4.txt");
	radixsort("random5.txt");
	radixsort("random6.txt");
	radixsort("random7.txt");
	radixsort("random8.txt");
	radixsort("random9.txt");
	radixsort("random10.txt");
	cout << endl << endl;

	mergeSort("positiveSeq.txt");
	mergeSort("negativeSeq.txt");
	mergeSort("random3.txt");
	mergeSort("random4.txt");
	mergeSort("random5.txt");
	mergeSort("random6.txt");
	mergeSort("random7.txt");
	mergeSort("random8.txt");
	mergeSort("random9.txt");
	mergeSort("random10.txt");
	cout << endl << endl;

	
	selectSort("positiveSeq.txt");
	selectSort("negativeSeq.txt");
	selectSort("random3.txt");
	selectSort("random4.txt");
	selectSort("random5.txt");
	selectSort("random6.txt");
	selectSort("random7.txt");
	selectSort("random8.txt");
	selectSort("random9.txt");
	selectSort("random10.txt");
	cout << endl << endl;

	insertSort("positiveSeq.txt");
	insertSort("negativeSeq.txt");
	insertSort("random3.txt");
	insertSort("random4.txt");
	insertSort("random5.txt");
	insertSort("random6.txt");
	insertSort("random7.txt");
	insertSort("random8.txt");
	insertSort("random9.txt");
	insertSort("random10.txt");
	cout << endl << endl;

	bubbleSort("positiveSeq.txt");
	bubbleSort("negativeSeq.txt");
	bubbleSort("random3.txt");
	bubbleSort("random4.txt");
	bubbleSort("random5.txt");
	bubbleSort("random6.txt");
	bubbleSort("random7.txt");
	bubbleSort("random8.txt");
	bubbleSort("random9.txt");
	bubbleSort("random10.txt");
	cout << endl << endl;
}