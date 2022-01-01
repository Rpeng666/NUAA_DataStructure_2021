#include<iostream>
#include<algorithm>
using namespace std;

int A[601][601], s[601][601];


int main(){
	int n, L, r, t;

	cin >> n >> L >> r >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];       //读入数组
		}
	}

	//前缀和
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + A[i][j];
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			double cal = 0;
			int i_max = min(n, i + r);
			int i_min = max(1, i - r) - 1;
			int j_max = min(n, j + r);
			int j_min = max(1, j - r) - 1;
			double sum = s[i_max][j_max] - s[i_max][j_min] - s[i_min][j_max] + s[i_min][j_min];
			int num = (i_max - i_min)*(j_max - j_min);
			cal = (double)sum / (double)num;
			if (cal <= t) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
