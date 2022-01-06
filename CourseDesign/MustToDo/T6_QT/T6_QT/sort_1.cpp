#include"sort_1.h"
#include<string>
using namespace std;

void Sort_1::createRandomNum() {
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

void Sort_1::readFile(string name) {
	fstream file(name.c_str(), ios::in);
	int temp = 0, i = 0;

	while (!file.eof()) {
		file >> temp;
		if (file.fail())break;

		nums[i++] = temp;
	}
	file.close();
}

string Sort_1::bubbleSort(string name) {

	readFile(name);
	string str;
	clock_t startTime, endTime;
	startTime = clock();

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (nums[j] > nums[j + 1]) {
				std::swap(nums[j], nums[j + 1]);
			}
		}
	}

	endTime = clock();

	str.append(name + "前20个元素：");

	for (int i = 0; i < 20; i++) {
		str.append(std::to_string(nums[i]) + " ");
	}
	double time_use = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	str.append("排序用时：" + std::to_string(time_use) + " s\n\n");

	return str;
}

string Sort_1::insertSort(string name) {
	readFile(name);
	string str;

	clock_t startTime, endTime;
	startTime = clock();

	for (int i = 1; i < N; i++) {
		int j = i;
		while (j >= 1 && nums[j] < nums[j - 1]) {
			std::swap(nums[j], nums[j - 1]);
			j--;
		}
	}
	endTime = clock();

	str.append(name + "前20个元素：");

	for (int i = 0; i < 20; i++) {
		str.append(std::to_string(nums[i]) + " ");
	}
	double time_use = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	str.append("排序用时：" + std::to_string(time_use) + " s\n\n");

	return str;
}

string Sort_1::shellSort(string name) {
	string str;
	readFile(name);

	clock_t startTime, endTime;
	startTime = clock();

	int h = 1;
	while (h < N / 3) {
		h = h * 3 + 1;
	}
	//三重循环
	while (h >= 1) {
		for (int j = h; j < N; j++) {
			for (int i = j; i >= h && nums[i] < nums[i - h]; i -= h) {
				std::swap(nums[i], nums[i - h]);
			}
		}
		h /= 3;
	}


	endTime = clock();

	str.append(name + "前20个元素：");

	for (int i = 0; i < 20; i++) {
		str.append(std::to_string(nums[i]) + " ");
	}
	double time_use = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	str.append("排序用时：" + std::to_string(time_use) + " s\n\n");

	return str;
}

void Sort_1::Qsort2(int low, int high) {
	stack<pair<int, int>> st;
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

string Sort_1::quickSort(string name) {
	string str;
	readFile(name);

	clock_t startTime, endTime;
	startTime = clock();

	//Qsort1(nums, 0, N - 1);  递归版本，50000个数字栈爆了
	Qsort2(0, N - 1);

	endTime = clock();

	str.append(name + "前20个元素：");

	for (int i = 0; i < 20; i++) {
		str.append(std::to_string(nums[i]) + " ");
	}
	double time_use = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	str.append("排序用时：" + std::to_string(time_use) + " s\n\n");

	return str;
}

string Sort_1::selectSort(string name) {
	string str;
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

	str.append(name + "前20个元素：");

	for (int i = 0; i < 20; i++) {
		str.append(std::to_string(nums[i]) + " ");
	}
	double time_use = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	str.append("排序用时：" + std::to_string(time_use) + " s\n\n");

	return str;
}

void Sort_1::adjustHeap(int k, int length) {
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

string Sort_1::heapSort(string name) {
	string str;
	readFile(name);

	clock_t startTime, endTime;
	startTime = clock();

	int len = N;
	//建立初始大顶堆
	for (int i = N / 2 - 1; i >= 0; i--) {
		adjustHeap(i, len);
	}
	//开始堆排序
	for (int i = N - 1; i >= 0; i--) {
		std::swap(nums[i], nums[0]);
		adjustHeap(0, i);
	}

	endTime = clock();

	str.append(name + "前20个元素：");

	for (int i = 0; i < 20; i++) {
		str.append(std::to_string(nums[i]) + " ");
	}
	double time_use = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	str.append("排序用时：" + std::to_string(time_use) + " s\n\n");

	return str;
}

void Sort_1::Merge(int A[], int TmpA[], int L, int R, int RightEnd) {
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

void Sort_1::Merge_pass(int A[], int TmpA[], int n, int length) {
	int i, j;

	for (i = 0; i <= n - 2 * length; i += 2 * length)
		Merge(A, TmpA, i, i + length, i + 2 * length - 1);
	if (i + length < n) /* 归并最后2个子列*/
		Merge(A, TmpA, i, i + length, n - 1);
}

string Sort_1::mergeSort(string name) {
	int n = N;
	int length;
	int* TmpA;

	string str;
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

	endTime = clock();

	str.append(name + "前20个元素：");

	for (int i = 0; i < 20; i++) {
		str.append(std::to_string(nums[i]) + " ");
	}
	double time_use = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	str.append("排序用时：" + std::to_string(time_use) + " s\n\n");

	return str;
}

string Sort_1::radixsort(string name) {
	string str;
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
	for (i = 1; i <= d; i++) {
		for (j = 0; j < 10; j++)count[j] = 0;

		for (j = 0; j < N; j++) {
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

	str.append(name + "前20个元素：");

	for (int i = 0; i < 20; i++) {
		str.append(std::to_string(nums[i]) + " ");
	}
	double time_use = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	str.append("排序用时：" + std::to_string(time_use) + " s\n\n");

	return str;
}
