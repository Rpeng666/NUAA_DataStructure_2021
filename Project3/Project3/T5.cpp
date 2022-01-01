#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct windows {
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
};

struct point {
	int x;
	int y;
};

int main() {
	int n, m, x, y;
	cin >> n >> m;
	windows temp;
	point poi;
	vector<windows> arr;
	vector<point> t;

	for (int i = 0; i <= n - 1; i++) {
		cin >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2;
		temp.num = i + 1;
		arr.emplace_back(temp);
	}

	for (int i = 0; i <= m - 1; i++) {
		cin >> poi.x >> poi.y;
		t.emplace_back(poi);
	}

	for (int i = 0; i <= m - 1; i++) {
		x = t[i].x;
		y = t[i].y;
		int j = n - 1;
		for (; j >= 0; j--) {
			if (x >= arr[j].x1 && x <= arr[j].x2 && y <= arr[j].y2 && y >= arr[j].y1) {
				cout << arr[j].num << endl;
				temp = arr[j];
				arr.erase(arr.begin() + j);
				arr.insert(arr.end(), temp);
				break;
			}
		}
		if (j == -1)cout << "IGNORED" << endl;
	}
	return 0;
}