#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;


int main()
{
	int n, L, t;

	int a[105];
	int speed[105];

	cin >> n >> L >> t;

	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	fill(speed, speed + 105, 1);

	while (t--){
		for (int i = 0; i < n; i++){
			if (a[i] == 0)
				speed[i] *= -1;
			if (a[i] == L)
				speed[i] *= -1;
			for (int j = 0; j < n; j++){
				if (a[i] == a[j] && i != j){
					speed[i] *= -1;
				}
			}
		}

		for (int i = 0; i < n; i++){
			a[i] += speed[i];
		}
	}

	for (int i = 0; i < n; i++){
		cout << a[i] << ' ';
	}
}
