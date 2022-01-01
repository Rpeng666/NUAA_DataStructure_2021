#include<iostream>
using namespace std;


int main() {
	int n,x;
	cout << "请确定最高的次数" << endl;
	cin >> n;

	int * a = new int[n+1];
	cout << "请输入每一项的系数Ai（i=0,1,2，...，n）" << endl;
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
	}

	cout << "多项式如下：" << endl;
	cout << "y = " << a[0];
	for (int i = 1; i <= n; i++) {
		if (i == 1) cout << "+" << a[i] << "X";
		else cout << "+" << a[i] << "X^" << i;
	}
	cout << endl;

	cout << "请输入变量x的值：" << endl;
	cin >> x;

	int temp = 1, sum =a[0];

	for (int i = 1; i <= n; i++) {
		temp *= x;
		sum += a[i] * temp;
	}
	cout << "多项式的值：" << sum << endl;
}