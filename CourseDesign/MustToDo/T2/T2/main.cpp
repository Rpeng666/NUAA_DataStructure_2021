#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<stack>
#include<graphics.h>
#include<stdlib.h>
#include<queue>
#include<Windows.h>
#define N 20

using namespace std;

struct Status {
	int x;
	int y;
	int dire;
	int step;

	Status(int x=0,int y=0,int dire=0, int step=0){
		this->x = x;
		this->y = y;
		this->dire = dire;
		this->step = step;
	}

	void changeInfo(int x, int y, int dire, int step) {
		this->x = x;
		this->y = y;
		this->dire = dire;
		this->step = step;
	}
};

bool map[N][N];  //false代表有遮挡物不能走，反之可以走
int x1, y_1, x2, y2;
int minstep = 999999999;
bool visited[N][N]{}; //true代表走过，false代表没走过
stack<Status>min_path;
stack<Status> path;

int Next[4][2] = {
		{-1,0}, //上走
		{1,0}, //下走
		{0,-1}, //左走
		{0,1}  //右走
};

//创造一个N*N的随机地图,随机入口和随机出口
void createRandomMap() {
	srand((int)time(0));
	fstream file("data.txt", ios::out);
	bool map[100][100]{};
	int temp;

	file << N << ' ' << N << endl;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			temp = rand() % 100;
			if (temp > 25) {
				file << 0 << ' ';
				map[j][i] = true;
			}
			else {
				file << 1 << ' ';
				map[j][i] = false;
			}
		}
		file << endl;
	}

	int x = rand()%N, y = rand()%N;
	while (map[x][y] == false) {
		x = rand() % N;
		y = rand() % N;
	}
	file << x << ' ' << y << ' ';

	x = rand() % N;
	y = rand() % N;
	while (map[x][y] == false) {
		x = rand() % N;
		y = rand() % N;
	}
	file << x << ' ' << y;

	file.close();
}

//从data.txt中读取地图信息
void getMapInfo() {
	fstream file("data.txt", ios::in);

	int temp1,temp2;

	file >> temp1 >> temp2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
			file >> temp1;
			if (temp1 == 0) map[i][j] = true;
			else map[i][j] = false;
		}
	}
	file >> x1 >> y_1 >> x2 >> y2;


	file.close();
}

void ChangeTopDire(int i) {
	Status temp = path.top();
	temp.dire = i + 1;
	path.pop();
	path.emplace(temp);
}

//深搜找路径（最短路径已废弃时间复杂度太大，只能找到路径）
void dfs(int x,int y,int step) {
	IMAGE img;
	Status top(x, y, 0, 0);

	visited[x][y] = true;
	path.emplace(top);

	while (!path.empty()) {
		top = path.top();
		//找到了出口
		if (top.x == x2 && top.y == y2) {
			if (top.step < minstep) {
				minstep = top.step;
				min_path = path;
				return;
			}
		}

		bool flag = false; //假设无路可走

		for (int i = top.dire; i < 4; i++) {
			//将这个点所能达到的所有点全部压入栈
			Status temp(top.x + Next[i][0], top.y + Next[i][1],0, top.step + 1);

			if (!visited[temp.x][temp.y] && temp.x >= 0 && temp.x < N && temp.y >= 0 && temp.y < N && map[temp.x][temp.y]&&temp.step <= minstep) {
				ChangeTopDire(i);
				path.emplace(temp);
				visited[temp.x][temp.y] = true;
				flag = true; //有路可走
				
				if (temp.x != x1 || temp.y != y_1) {
					if (temp.x != x2 || temp.y != y2) {
						loadimage(&img, _T("path.png"), 20, 20);
						putimage(20 * temp.y, 20 * temp.x, &img);
						Sleep(50);
					}
				}
				break;
			}
		}
		if (!flag) { //无路可走就弹栈回溯
			path.pop();
			if (top.x != x1 || top.y != y_1) {
				loadimage(&img, _T("1.png"), 20, 20);
				putimage(20 * top.y, 20 * top.x, &img);
				//visited[top.x][top.y] = false;
				Sleep(50);
			}
		}
	}
}

//广搜找路径(可以比较简单地找到最短路径)
void bfs(int x, int y) {
	queue<Status> qu;
	stack<Status> st;
	IMAGE img;

	Status temp(x, y, 0, 0),top;
	qu.emplace(temp);
	st.emplace(temp);

	visited[x][y] = true;

	while (!qu.empty()) {
		top = qu.front(); //弹出队首元素
		qu.pop();

		for (int i = 0; i < 4; i++) {
			temp.changeInfo(top.x + Next[i][0], top.y + Next[i][1], 0, top.step + 1);

			if (!visited[temp.x][temp.y] && temp.x >= 0 && temp.x < N && temp.y >= 0 && temp.y < N && map[temp.x][temp.y]) {
				loadimage(&img, _T("path.png"), 20, 20);
				putimage(20 * temp.y, 20 * temp.x, &img);
				Sleep(50);

				qu.emplace(temp);
				st.emplace(temp);
				visited[temp.x][temp.y] = true;
			}

			if (temp.x == x2 && temp.y == y2)
			{
				top = st.top(), st.pop();
				int i;
				while (!st.empty()) {
					
					for (i = 3; i >= 0; i--) {
						if (st.top().x + Next[i][0] == top.x && st.top().y + Next[i][1] == top.y)
							break;
					}

					if (i != -1) {
						min_path.emplace(st.top());
						top = st.top();
					}
					st.pop();
				}
				return;
			}
		}
	}
}


void drawPic() {
	initgraph(400, 400);	// 创建绘图窗口，大小为 640*640 像素
	IMAGE img;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == false) loadimage(&img, _T("2.png"), 20, 20);
			else {
				if(i == x1 && j == y_1)loadimage(&img, _T("from.png"), 20, 20);
				else if(i == x2 && j == y2) loadimage(&img, _T("to.png"), 20, 20);
				else loadimage(&img, _T("1.png"), 20, 20);
			}
			putimage(20 * j, 20 * i, &img);
		}
	}
}

void drawMinPath() {
	Status temp;
	IMAGE img;
	while (!min_path.empty()) {
		temp = min_path.top();
		min_path.pop();
		if(temp.x == x1 && temp.y == y_1) loadimage(&img, _T("from.png"), 20, 20);
		else if(temp.x == x2&& temp.y == y2) loadimage(&img, _T("to.png"), 20, 20);
		else loadimage(&img, _T("3.png"), 20, 20);
		putimage(20 * temp.y, 20 * temp.x, &img);
	}
	loadimage(&img, _T("to.png"), 20, 20);
	putimage(20 * y2, 20 * x2, &img);
}


int main() {
	createRandomMap();

	getMapInfo();
	
	drawPic();

	//dfs(x1, y_1, 0);

	bfs(x1, y_1);

	drawMinPath();

	system("pause");
	//closegraph();			// 关闭绘图窗口
	cout << 666 << endl;
	return 0;
}