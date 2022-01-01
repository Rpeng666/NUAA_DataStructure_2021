#include<iostream>
using namespace std;
#define maxsize 9999
#define arrsize 100

int main() {
	int  n, i = 1;
	int arr[arrsize];

	cout << "Please enter n:" << endl;
	cin >> n;

	if (n > arrsize ) {
		cout << "n的范围超出数组范围" << endl;
		return 0;
	}

	else {
		for (; i <= n; i++) {
			if (i == 1) {
				arr[i-1] = 2;
				continue;
			}
			if (arr[i-2] > maxsize*1.0 / (2 * i) ){
				cout << "数值过大，数组无法存储" << endl;   
				break;
			}
			arr[i-1] = arr[i - 2] * 2 * i;
		}
	}

	cout << "下面将输出数值：" << endl;

	for (int j = 0; j <= i - 2; j++) {
		cout << arr[j] << endl;
	}
	if (i - 2 != n) {
		cout << "后续的值计算机无法存储，无法展示" << endl;
	}

	return 0;
}