#include<iostream>
#include<stack>
#include<math.h>
using namespace std;


struct Point {
	int row;
	int col;
};

bool JudgeQueenConfiction(Point curQueen, stack<Point> StkQueen) {
	int x, y;
	Point temp;

	while (StkQueen.size() != 0) {
		temp = StkQueen.top();
		StkQueen.pop();
		x = temp.row;
		y = temp.col;
		if (abs(x - curQueen.row) == abs(y - curQueen.col)) return false;

		if ((x == curQueen.row) || (y == curQueen.col)) return false;
	}

	return true;
}

void OutputResult(stack<Point> StkQueen, int N) {
	Point temp;

	for (int i = 1; i <= N; i++) {
		temp = StkQueen.top();
		StkQueen.pop();
		cout << "第" << i << "个皇后的坐标：(row = " << temp.row << ", col=" << temp.col << ")" << endl;
	}
	cout << endl;
}


//N皇后问题非递归实现
void PlaceQueen(int N) {
	stack<Point> StkQueen;
	Point curQueen;
	bool ret;


	int resultCount = 0;  //用来记录可行解的个数
	curQueen.col = curQueen.row = 1;  //N皇后问题的初始化位置为（1,1）
	StkQueen.emplace(curQueen);

	curQueen.row = 2;  //第二个尝试的位置是（2,1）
	curQueen.col = 1;

	//StkQueen.emplace(curQueen);

	while (curQueen.row <= N && curQueen.col <= N) {   //只要没有尝试到（N,N）的位置就不断循环
		while (curQueen.col <= N) {
			ret = JudgeQueenConfiction(curQueen, StkQueen);  //判断目前尝试的位置是否符合要求
			if (ret) {
				break;
			}
			curQueen.col += 1;
		}

		if (ret) {
			StkQueen.emplace(curQueen);
			curQueen.row += 1;
			curQueen.col = 1;

			if (curQueen.row > N) {
				OutputResult(StkQueen, N);
				resultCount++;

				curQueen = StkQueen.top();
				StkQueen.pop();
				curQueen.col += 1;

				while (curQueen.col > N && !StkQueen.empty()) {
					curQueen = StkQueen.top();
					StkQueen.pop();

					curQueen.col += 1;
				}
			}
		}

		else {
			curQueen = StkQueen.top();
			StkQueen.pop();
			curQueen.col += 1;

			while (curQueen.col > N && !StkQueen.empty()) {
				curQueen = StkQueen.top();
				StkQueen.pop();
				curQueen.col += 1;
			}
		}
	}
	cout << "符合条件的解的总个数：" << resultCount << endl;
}


int main() {
	int N;
	cout << "请输入N：" << endl;
	cin >> N;
	cout << "开始求解N皇后问题的可行解" << endl << endl;

	PlaceQueen(N);

	return 0;
}