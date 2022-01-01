#include<iostream>
#include<algorithm>
using namespace std;


int  main() {
	int N, m, temp,sum=0,D=0,T =0;
	cin >> N;
	int* alltree = new int[N];
	int* tree = new int[N];
	memset(tree, 0, sizeof(tree));   //在CSP服务器上无法使用，会编译出错

	for (int i = 0; i < N; i++) {
		cin >> m;
		cin >> alltree[i];

		for (int j = 1; j < m; j++) {
			cin >> temp;
			if (temp <= 0) alltree[i] += temp;
			else {
				if (alltree[i] > temp) {
					tree[i] = 1;
				}
				alltree[i] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++)sum += alltree[i];
	for (int i = 0; i < N; i++) {
		if (tree[i] == 1)
			D++;
	}

	for (int i = 0; i < N; i++) {
		if (tree[i] == 1 && tree[(i + 1)%N] == 1 && tree[(i + 2)%N] == 1) {
			T++;
		}
	}
	delete tree;
	delete alltree;
	cout << sum << ' ' << D << ' ' << T << endl;
}