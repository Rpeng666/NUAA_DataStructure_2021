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
		cout << "n�ķ�Χ�������鷶Χ" << endl;
		return 0;
	}

	else {
		for (; i <= n; i++) {
			if (i == 1) {
				arr[i-1] = 2;
				continue;
			}
			if (arr[i-2] > maxsize*1.0 / (2 * i) ){
				cout << "��ֵ���������޷��洢" << endl;   
				break;
			}
			arr[i-1] = arr[i - 2] * 2 * i;
		}
	}

	cout << "���潫�����ֵ��" << endl;

	for (int j = 0; j <= i - 2; j++) {
		cout << arr[j] << endl;
	}
	if (i - 2 != n) {
		cout << "������ֵ������޷��洢���޷�չʾ" << endl;
	}

	return 0;
}