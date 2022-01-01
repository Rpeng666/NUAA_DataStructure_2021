#include<iostream>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	int s = 0, e=0;

	int * cross = new int[1000000];
	int total = 0;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		for (int k = s; k < e; k++)
			cross[k] = 1;
	}
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		for (int k = s; k < e; k++) {
			if (cross[k] == 1)
				total++;
		}
	}
	cout << total << endl;
}
