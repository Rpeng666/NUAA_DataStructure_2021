#include"compute.h"

bool Compute::setStr(string str) {
	clearAll();
	int size = str.size();
	if (str.size() >= 1) {
		this->computeStr = str;
		return true;
	}
	return false;
}

void Compute::compu() {
	double a, b, d;
	char c;
	c = OpeSt.top(), OpeSt.pop();
	a = NumSt.top(), NumSt.pop();
	b = NumSt.top(), NumSt.pop();
	switch (c)
	{
	case '*':d = b * a; break;
	case'/':d = b / a; break;
	case '+':d = b + a; break;
	case'-':d = b - a; break;
	default:
		break;
	}
	NumSt.emplace(d);
}

void Compute::calculate() {
	while (cur < computeStr.size()) {
		if (computeStr[cur] <= '9' && computeStr[cur] >= '0') {
			NumSt.emplace(computeStr[cur] - '0');
		}
		else if (computeStr[cur] == '+' || computeStr[cur] == '-' || computeStr[cur] == '*' || computeStr[cur] == '/') {
			if (OpeSt.empty()) {
				OpeSt.emplace(computeStr[cur++]);
				continue;
			}
			char topChar = OpeSt.top();

			if ( topChar == '(')
				OpeSt.emplace(computeStr[cur]);

			else if (cmp(computeStr[cur], topChar) == 1)
				OpeSt.emplace(computeStr[cur]);

			else if (cmp(computeStr[cur], topChar) != 1) {
				while (cmp(computeStr[cur], topChar) != 1) {
					compu();
					if (OpeSt.empty())
						break;
				}
				OpeSt.emplace(computeStr[cur]);
			}
		}

		else if (computeStr[cur] == '(') OpeSt.emplace(computeStr[cur]);

		else if (computeStr[cur] == ')') {
			char topChar = OpeSt.top();
			while (topChar != '(') {
				compu();
				topChar = OpeSt.top();
			}
			OpeSt.pop();
		}
		cur++;
	}

	while (!OpeSt.empty()) compu();

	result = NumSt.top();
	NumSt.pop();
}

int Compute::cmp(char ch1, char ch2) {
	if (ch1 == '+' || ch1 == '-') {
		if (ch2 == '*' || ch2 == '/') return -1;
		else if (ch2 == '+' || ch2 == '-') return 0;
		else if (ch2 == '(') return 1;
	}
	else if (ch1 == '*' || ch1 == '/') {
		if (ch2 == '*' || ch2 == '/') return 0;
		else if (ch2 == '+' || ch2 == '-') return 1;
		else if (ch2 == '(') return 1;
	}
}

void Compute::clearAll() {
	while (!NumSt.empty()) NumSt.pop();
	while (!OpeSt.empty())OpeSt.pop();
	tempNumSt.clear();
	tempOpeSt.clear();
	cur = 0;
}

vector<string> split(const string& str, const string& pattern) {
	vector<string> res;
	if (str == "")
		return res;
	//在字符串末尾也加入分隔符，方便截取最后一段
	string strs = str + pattern;
	size_t pos = strs.find(pattern);

	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		//去掉已分割的字符串,在剩下的字符串中进行分割
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(pattern);
	}

	return res;
}