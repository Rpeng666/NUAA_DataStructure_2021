#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	int r, y, g;
	cin >> r >> y >> g;
	int n;
	cin >> n;
	long long sum = 0;
	int k, t;

	for (int i = 0; i < n; i++) {
		cin >> k >> t;
		int temp = sum % (r + y + g);

		if (k == 0) sum += t;
		else if (k == 1) {
			//ºìµÆ
			if (temp < t)
				sum += t - temp;
			//ÂÌµÆ
			else if (temp >= t && temp < t + g);		
			//»ÆµÆ 
			else if (temp >= t + g && temp < t + g + y)
				sum += t + g + y - temp + r;
			//ºìµÆ 
			else if (temp >= t + g + y)
				sum += t + g + y + r - temp;
		}
		else if (k == 2) {
			//»ÆµÆ 
			if (temp < t)
				sum += t - temp + r;
			//ºìµÆ	
			else if (temp >= t && temp < t + r)
				sum += t + r - temp;
			//ÂÌµÆ	
			else if (temp >= t + r && temp < t + r + g); 
			//»ÆµÆ
			else if (temp >= t + r + g)
				sum += t + r + g + y - temp + r;
		}
		else if (k == 3) {
			//ÂÌµÆ
			if (temp < t);
			//»ÆµÆ
			else if (temp >= t && temp < t + y)
				sum += t + y - temp + r;
			//ºìµÆ
			else if (temp >= t + y && temp < t + y + r)
				sum += t + y + r - temp;
			//ÂÌµÆ	
			else if (temp >= t + y + r);
		}
	}
	cout << sum;
	return 0;
}