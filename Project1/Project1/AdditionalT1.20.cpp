#include<iostream>
using namespace std;


int main() {
	int n,x;
	cout << "��ȷ����ߵĴ���" << endl;
	cin >> n;

	int * a = new int[n+1];
	cout << "������ÿһ���ϵ��Ai��i=0,1,2��...��n��" << endl;
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
	}

	cout << "����ʽ���£�" << endl;
	cout << "y = " << a[0];
	for (int i = 1; i <= n; i++) {
		if (i == 1) cout << "+" << a[i] << "X";
		else cout << "+" << a[i] << "X^" << i;
	}
	cout << endl;

	cout << "���������x��ֵ��" << endl;
	cin >> x;

	int temp = 1, sum =a[0];

	for (int i = 1; i <= n; i++) {
		temp *= x;
		sum += a[i] * temp;
	}
	cout << "����ʽ��ֵ��" << sum << endl;
}