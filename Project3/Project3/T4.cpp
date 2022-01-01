#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int m, Max = 0, res, a = 0, b = 0;
int sum[100005] = { 0 };
set<int>st;



int main() {
	pair<int, int>data[100005];
	int y1 = 0, y0 = 0, y = 0;
	cin >> m; //��������m
	for (int i = 0; i <= m - 1; i++) {
		cin >> a >> b;
		data[i] = make_pair(a, b);
	}

	sort(data, data + m);//�����ݽ������򣬷�����ǰ׺��

	//��sum�������洢ǰ׺��,sum[i]��ʾС��i��û�йҿƵ��˵ĸ���
	sum[0] = data[0].second;

	for (int i = 1; i <= m - 1; i++) {
		sum[i] = sum[i - 1] + data[i].second;
	}

	for (int i = 0; i <= m - 1; i++) {
		//ѡȡ��ֵ 
		int a = data[i].first;
		//��setȥ��
		if (st.count(a) != 0) continue;
		else st.insert(a);

		y1 = sum[m] - sum[i - 1];//���ڵ�����ֵʱ��Ӧͳ��Ԥ������Ϊ1�ĸ��� 
		y0 = i - 1 - sum[i - 1];//С����ֵʱ��Ӧͳ��Ԥ������Ϊ0�ĸ��� 
		y = y1 + y0;//�ϼ�Ԥ����ȷ���� 
		if (y >= Max) {
			Max = y;
			res = a;
		}
	}
	cout << res;
	return 0;
}