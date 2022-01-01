//CSP£∫∑«¡„◊÷∂ŒŒ Ã‚

#include<iostream>
#include<algorithm>
using namespace std;


const int N = 500002;
const int M = 10002;
int a[N + 2], d[M + 1];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = a[n + 1] = 0;

	n = unique(a, a + n + 2) - a - 1;

	memset(d, 0, sizeof(d));

	for (int i = 1; i < n; i++) {
		if (a[i - 1] < a[i] && a[i] > a[i + 1]) d[a[i]]++;
		else if (a[i - 1] > a[i] && a[i] < a[i + 1]) d[a[i]]--;
	}

	int ans = 0, sum = 0;
	for (int i = M; i >= 1; i--) {
		sum += d[i];
		ans = max(ans, sum);
	}

	cout << ans;

	return 0;
}