#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<fstream>
using namespace std;

struct Json {
	map<string, string> data;
	map<string, Json*> next; //һ�ֵݹ�Ľṹ
	Json& operator=(const Json& j) {
		data = j.data, next = j.next; 
		return *this;
	}
};

//���������е��ַ���
vector<string> S;

//��ѯS[i][j]����֮����ַ���һ����b��Ϊ����Ϊ���ַ�ch��λ��
void find(int& i, int& j, const int& ni, char c, bool b = true, int nj = 0) {
	for (; i < ni; ++i, j = 0)
		for (nj = S[i].size(); j < nj; ++j)
			if ((b && S[i][j] == c) || (!b && S[i][j] != c))
				return;
}

//��S[i][j]��ʼ�õ�������ַ���
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

Json BuildJson(int& i, int& j, const int& ni, int nj) {//�ݹ鴴��Json����
	Json json;
	//�ҵ���һ��'{'����Ϊ�ö������������
	find(i, j, ni, '{');
	//ѭ��������ܵļ�ֵ��
	while (i < ni) {
		//�ҵ���һ����Ϊ�ո���ַ�λ�� �������ַ��Ǹö�������������˳�ѭ��
		find(i, ++j, ni, ' ', false);
		//i==niΪ��Ҫ�жϣ�
		if (i == ni || S[i][j] == '}') break;
		string key, value;
		//�ҵ���һ�� ��\���� ����������һ��λ�õõ��ַ���
		find(i, j, ni, '\"'), key = getStr(i, ++j, ni);
		//�ҵ���:��֮��ĵ�һ���ǿո��ַ�
		find(i, j, ni, ':'), find(i, ++j, ni, ' ', false);
		//key��ֵ��һ������
		if (S[i][j] == '{')
			json.next[key] = new Json(BuildJson(i, j, ni, S[i].size()));
		else//key��ֵΪ�ַ���
			find(i, j, ni, '\"'), json.data[key] = value = getStr(i, ++j, ni);
		//�ҵ���һ���ǿո��ַ�
		find(i, ++j, ni, ' ', false);
		//������������� �˳�ѭ�� ����һ���ǡ�,��
		if (i < ni && j < nj && S[i][j] == '}') break;
	}
	return json;
}


////IMPORTANT
//vector<string> split(const string& str, const string& pattern) {
//	vector<string> res;
//	if (str == "")
//		return res;
//	//���ַ���ĩβҲ����ָ����������ȡ���һ��
//	string strs = str + pattern;
//	size_t pos = strs.find(pattern);
//
//	while (pos != strs.npos)
//	{
//		string temp = strs.substr(0, pos);
//		res.push_back(temp);
//		//ȥ���ѷָ���ַ���,��ʣ�µ��ַ����н��зָ�
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
		cout << "�ļ��򿪴���" << endl;
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
			string key = S[i].substr(l, (k == i ? j : nj) - l);//�ָ�'.'
			if (k == i && j < nj) {//���к������ַ���
				if (jsontemp.next.find(key) == jsontemp.next.end()) break;
				jsontemp = *jsontemp.next[key];
			}
			else {//û�к������ַ���
				if (jsontemp.data.find(key) != jsontemp.data.end())
					cout << "STRING " << jsontemp.data[key] << endl, f = 1;
				if (jsontemp.next.find(key) != jsontemp.next.end())
					cout << "OBJECT" << endl, f = 1;
			}
		}

		//û�в鵽ĳ����
		if (f == 0) {
			cout << "NOTEXIST" << endl;
		}
	}
	return 0;
}