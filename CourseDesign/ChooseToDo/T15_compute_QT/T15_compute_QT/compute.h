#ifndef COMPUTE_H
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Compute {
public:
	string computeStr;
	stack<int> NumSt;
	vector<stack<int>> tempNumSt;
	stack<char> OpeSt;
	vector<stack<int>> tempOpeSt;
	int cur = 0;
	double result;

	bool setStr(string str);
	void calculate();
	int cmp(char ch1, char ch2);
	void compu();
	void clearAll();
	vector<string> split();
};

#endif // !COMPUTE_H
