#include<iostream>
#include<algorithm>
#include<map>
#include<utility>
using namespace std;



int main() {
	int n,x,y;
	int scores[5] = {0}, count = 0;
	cin >> n;
	map<pair<int, int>, int> ps;


	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		pair<int, int> M = make_pair(x, y);
		ps[M] = 1;
	}

	for (auto i = ps.begin(); i != ps.end(); i++) {
		count = 0;
		x = i->first.first;
		y = i->first.second;

		if (ps.find(make_pair(x,y+1)) != ps.end() && ps.find(make_pair(x, y - 1)) != ps.end() && ps.find(make_pair(x-1, y)) != ps.end() && ps.find(make_pair(x + 1, y )) != ps.end()) {
			if (ps.find(make_pair(x +1, y + 1)) != ps.end())count++;
			if (ps.find(make_pair(x +1, y - 1)) != ps.end())count++;
			if (ps.find(make_pair(x -1, y + 1)) != ps.end())count++;
			if (ps.find(make_pair(x -1, y - 1)) != ps.end())count++;
			scores[count]++;
		}
	}

	for (int i = 0; i < 5; i++) {
		cout << scores[i] << endl;
	}

	return 0;
}

