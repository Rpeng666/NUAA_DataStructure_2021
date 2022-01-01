#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	int m, n, L, temp;
	cin >> m >> n >> L;

	int *p = new int[L];
	fill(p, p + L, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			p[temp]++;
		}
	}
	for (int i = 0; i < L; i++) {
		cout << p[i] << ' ';
	}
}