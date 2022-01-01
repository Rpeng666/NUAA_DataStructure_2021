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
	cin >> m; //读入人数m
	for (int i = 0; i <= m - 1; i++) {
		cin >> a >> b;
		data[i] = make_pair(a, b);
	}

	sort(data, data + m);//对数据进行排序，方便求前缀和

	//用sum数组来存储前缀和,sum[i]表示小于i中没有挂科的人的个数
	sum[0] = data[0].second;

	for (int i = 1; i <= m - 1; i++) {
		sum[i] = sum[i - 1] + data[i].second;
	}

	for (int i = 0; i <= m - 1; i++) {
		//选取阈值 
		int a = data[i].first;
		//用set去重
		if (st.count(a) != 0) continue;
		else st.insert(a);

		y1 = sum[m] - sum[i - 1];//大于等于阈值时，应统计预测结果中为1的个数 
		y0 = i - 1 - sum[i - 1];//小与阈值时，应统计预测结果中为0的个数 
		y = y1 + y0;//合计预测正确次数 
		if (y >= Max) {
			Max = y;
			res = a;
		}
	}
	cout << res;
	return 0;
}