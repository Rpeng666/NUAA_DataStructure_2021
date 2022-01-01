#include<iostream>

using namespace std;

void func(int n, int m){

	int *nums = new int[n];

	for (int i = 1; i <= n; ++i){
		nums[i - 1] = i;
	}

	int pos = 0;
	int count = 1;

	while (n > 0){
		if (count == m){
			cout << nums[pos] << " ";
			for (int i = pos; i < n - 1; ++i)
			{
				nums[i] = nums[i + 1];
			}
			count = 1;
			n--;
		}
		else
		{
			++count;
			++pos;
			pos %= n;
		}
	}
}


int main() {
	int n, m;
	cout << "请输入人数n：" << endl;
	cin >> n;
	cout << "请输入m: " << endl;
	cin >> m;

	func(n, m);

	return 0;
}