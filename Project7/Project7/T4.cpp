#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000][1000];

int main() {
	int n, m, x, y, value, min = 999, sum = 0,j=0;
	cin >> n >> m;
	bool *visited = new bool[n];

	for (int i = 0; i < n; i++)visited[i] = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 999999999;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> value;
		arr[x-1][y-1] = arr[y-1][x-1] = value;
	}

	visited[0] = true;
	int total = 1;

	while (total != n) {
		min = 9999999;
		for (int i = 0; i < n; i++) {
			
			if (visited[i]) {
				j = 0;
				for (; j < n; j++) {
					if (arr[i][j] < min && !visited[j]) {
						min = arr[i][j];
						x = i;
						y = j;
					}
				}
			}
		}
		if (min != 9999999) {
			visited[y] = true;
			sum += min;
			total++;
		}
	}
	delete visited;

	cout << sum << endl;
	return 0;
}