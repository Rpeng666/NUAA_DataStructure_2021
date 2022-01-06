#ifndef SORT_1_H
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
#pragma execution_character_set("utf-8")

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

class Sort_1 {
private:
	int nums[N];
	int tempList[N];

public:
	void createRandomNum();
	void readFile(string name);
	string bubbleSort(string name);
	string insertSort(string name);
	string shellSort(string name);
	void Qsort2(int low, int high);
	string quickSort(string name);
	string selectSort(string name);
	void adjustHeap(int k, int length);
	string heapSort(string name);
	void Merge(int A[], int TmpA[], int L, int R, int RightEnd);
	void Merge_pass(int A[], int TmpA[], int n, int length);
	string mergeSort(string name);
	string radixsort(string name);

};
#endif // !SORT_1_H

