#include<iostream>
#include<algorithm>
using namespace std;

struct Point {
	int x;
	int y;
};

int main() {
	int arr[15][15];
	Point points[4];
	int temp,k=0,colmin = 999,rowmin = -999,space;

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> temp;
			if (temp != 0) {
				colmin = colmin < j ? colmin : j;
				rowmin = rowmin > i ? rowmin : i;
				points[k].x = i;
				points[k].y = j;
				k++;
			}
		}
	}
	cin >> space;
	
	int col = space + colmin - 1;

	for (int i = 3; i < 15; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[points[j].x + i - rowmin + 1][points[j].y - colmin + col] == 1) {
				arr[points[0].x + i - rowmin][points[0].y - colmin + col] = 1;
				arr[points[1].x + i - rowmin][points[1].y - colmin + col] = 1;
				arr[points[2].x + i - rowmin][points[2].y - colmin + col] = 1;
				arr[points[3].x + i - rowmin][points[3].y - colmin + col] = 1;
				for (int t = i - 3; t < 15; t++) {
					for (int p = 0; p < 9; p++) {
						cout << arr[t][p] << ' ';
					}
					cout << arr[t][9] << endl;
				}
				return 0;
			}
		}

		for (int p = 0; p < 9; p++) {
			cout << arr[i - 3][p] << ' ';
		}
		cout << arr[i - 3][9] << endl;
	}
}