#include<iostream>

using namespace std;



int main() {
	int n,temp; 
	int arr[20][5];  //用二维数组模拟车厢 
	int index[20] = { 0 };//记录每排已经坐下了几人 
	cin >> n;
	

	for (int i = 0; i < n; i++) {
		cin >> temp;
		bool flag = true;
		for (int j = 0; j < 20; j++) {
			if (5 - index[j] >= temp) {   //如果以前的位置存在连续的作为可以坐
				for (int k = 0; k < temp; k++) {
					arr[j][index[j]++] = i + 1;
				}
				flag = false;
				break;
			}
		}
		//如果以前的位置不存在连续的作为可以坐
		if (flag) {
			for (int j = 0; j < 20; j++) {
				if (index[j] < 5) {
					for (int k = index[j]; k < 5; k++) {
						arr[j][index[j]++] = i + 1;
						temp--;
					}
					if (temp == 0)break;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 20; j++) {
			for (int k = 0; k < index[j]; k++) {
				if (arr[j][k] == i + 1)cout << j * 5 + (k + 1) << " ";
			}
		}
		cout << endl;
	}

	return 0;
}