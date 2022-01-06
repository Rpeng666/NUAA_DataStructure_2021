#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<fstream>
using namespace std;

struct Json {
	map<string, string> data;
	map<string, Json*> next; //一种递归的结构
	Json& operator=(const Json& j) {
		data = j.data, next = j.next; 
		return *this;
	}
};

//用来存所有的字符串
vector<string> S;

//查询S[i][j]及其之后的字符第一个（b？为：不为）字符ch的位置
void find(int& i, int& j, const int& ni, char c, bool b = true, int nj = 0) {
	for (; i < ni; ++i, j = 0)
		for (nj = S[i].size(); j < nj; ++j)
			if ((b && S[i][j] == c) || (!b && S[i][j] != c))
				return;
}

//从S[i][j]开始得到题意的字符串
string getStr(int& i, int& j, const int& ni, int nj = 0, string s = "") {
	for (; i < ni; ++i, j = 0)
		for (nj = S[i].size(); j < nj; ++j)
			if (S[i][j] == '\\')
				s += j + 1 < nj ? S[i][++j] : S[++i][j = 0], nj = S[i].size();
			else if (S[i][j] == '\"')
				return s;
			else
				s += S[i][j];
	return s;
}

Json BuildJson(int& i, int& j, const int& ni, int nj) {//递归创建Json对象
	Json json;
	//找到第一个'{'，此为该对象的左作用域
	find(i, j, ni, '{');
	//循环处理可能的键值对
	while (i < ni) {
		//找到第一个不为空格的字符位置 如果这个字符是该对象的右作用域退出循环
		find(i, ++j, ni, ' ', false);
		//i==ni为何要判断？
		if (i == ni || S[i][j] == '}') break;
		string key, value;
		//找到第一个 ‘\”’ 并从它的下一个位置得到字符串
		find(i, j, ni, '\"'), key = getStr(i, ++j, ni);
		//找到‘:’之后的第一个非空格字符
		find(i, j, ni, ':'), find(i, ++j, ni, ' ', false);
		//key的值是一个对象
		if (S[i][j] == '{')
			json.next[key] = new Json(BuildJson(i, j, ni, S[i].size()));
		else//key的值为字符串
			find(i, j, ni, '\"'), json.data[key] = value = getStr(i, ++j, ni);
		//找到第一个非空格字符
		find(i, ++j, ni, ' ', false);
		//如果是右作用域 退出循环 否则一定是‘,’
		if (i < ni && j < nj && S[i][j] == '}') break;
	}
	return json;
}


////IMPORTANT
//vector<string> split(const string& str, const string& pattern) {
//	vector<string> res;
//	if (str == "")
//		return res;
//	//在字符串末尾也加入分隔符，方便截取最后一段
//	string strs = str + pattern;
//	size_t pos = strs.find(pattern);
//
//	while (pos != strs.npos)
//	{
//		string temp = strs.substr(0, pos);
//		res.push_back(temp);
//		//去掉已分割的字符串,在剩下的字符串中进行分割
//		strs = strs.substr(pos + 1, strs.size());
//		pos = strs.find(pattern);
//	}
//
//	return res;
//}


int main() {
	int n, m, I = 0, J = 0;
	string str;
	fstream file("data.txt", ios::in);

	if (file.fail()) {
		cout << "文件打开错误！" << endl;
		return 0;
	}

	file >> n >> m;
	file.get();

	for (int i = 0; i < n; ++i) {
		getline(file, str);
		S.emplace_back(str);
	}

	Json json = BuildJson(I, J, S.size(), S[0].size());

	for (int i = 0; i < m; ++i) {
		getline(file, str);
		S.emplace_back(str);
	}

	for (int i = n, xi = i + 1, ni = n + m, l, j = 0, k, f, nj = S[i].size(); i < ni; ++i, l = 0, ++xi) {
		Json jsontemp = json;
		j = 0, nj = S[i].size(), k = i, f = 0;

		for (; k == i && j < nj && f == 0; j++) {
			l = j, find(k, j, xi, '.');
			string key = S[i].substr(l, (k == i ? j : nj) - l);//分割'.'
			if (k == i && j < nj) {//还有后续的字符串
				if (jsontemp.next.find(key) == jsontemp.next.end()) break;
				jsontemp = *jsontemp.next[key];
			}
			else {//没有后续的字符串
				if (jsontemp.data.find(key) != jsontemp.data.end())
					cout << "STRING " << jsontemp.data[key] << endl, f = 1;
				if (jsontemp.next.find(key) != jsontemp.next.end())
					cout << "OBJECT" << endl, f = 1;
			}
		}

		//没有查到某个键
		if (f == 0) {
			cout << "NOTEXIST" << endl;
		}
	}
	return 0;
}