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
		cout << "��" << i << "���ʺ�����꣺(row = " << temp.row << ", col=" << temp.col << ")" << endl;
	}
	cout << endl;
}


//N�ʺ�����ǵݹ�ʵ��
void PlaceQueen(int N) {
	stack<Point> StkQueen;
	Point curQueen;
	bool ret;


	int resultCount = 0;  //������¼���н�ĸ���
	curQueen.col = curQueen.row = 1;  //N�ʺ�����ĳ�ʼ��λ��Ϊ��1,1��
	StkQueen.emplace(curQueen);

	curQueen.row = 2;  //�ڶ������Ե�λ���ǣ�2,1��
	curQueen.col = 1;

	//StkQueen.emplace(curQueen);

	while (curQueen.row <= N && curQueen.col <= N) {   //ֻҪû�г��Ե���N,N����λ�þͲ���ѭ��
		while (curQueen.col <= N) {
			ret = JudgeQueenConfiction(curQueen, StkQueen);  //�ж�Ŀǰ���Ե�λ���Ƿ����Ҫ��
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
	cout << "���������Ľ���ܸ�����" << resultCount << endl;
}


int main() {
	int N;
	cout << "������N��" << endl;
	cin >> N;
	cout << "��ʼ���N�ʺ�����Ŀ��н�" << endl << endl;

	PlaceQueen(N);

	return 0;
}