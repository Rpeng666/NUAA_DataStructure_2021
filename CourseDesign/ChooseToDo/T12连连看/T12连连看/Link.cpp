#include"Link.h"

void Link::createRandomMap() {
	srand((int)time(0)); //随机种子
	fstream file("map.txt", ios::out);
	//先给每种图片分配两张
	int nums[10]{ 2,2,2,2,2,2,2,2,2,2 };
	int sum = 180, place = 0;

	while (sum != 0) {
		place = rand() % 10;
		nums[place] += 2; //分配每种图片的个数
		sum -= 2;
	}

	int allpic[200]{}, i = 0, j = 0;

	while (nums[9] > 0) {
		allpic[j++] = i;
		nums[i]--;   //将图片转换到另一个数组中存储
		if (nums[i] <= 0)i++;
	}

	std::random_shuffle(allpic, allpic + 200);  //打乱图片

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			file << allpic[i * 20 + j] << ' ';
		}
		file << endl;
	}
	file.close();
}

void Link::readMap() {
	fstream file("map.txt", ios::in);
	//map用来存储图片位置信息
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 22; j++) {
			if (i == 0 || i == 11 || j == 0 || j == 21) map[i][j] = -1;
			else file >> map[i][j];
		}
	}
	file.close();
}

void Link::loadImageFromPhoto(IMAGE& img, int num) {
	switch (num)
	{  //贴图片
	case 0:loadimage(&img, _T("photos/0.jpg"), 60, 60); break;
	case 1:loadimage(&img, _T("photos/1.jpg"), 60, 60); break;
	case 2:loadimage(&img, _T("photos/2.jpg"), 60, 60); break;
	case 3:loadimage(&img, _T("photos/3.jpg"), 60, 60); break;
	case 4:loadimage(&img, _T("photos/4.jpg"), 60, 60); break;
	case 5:loadimage(&img, _T("photos/5.jpg"), 60, 60); break;
	case 6:loadimage(&img, _T("photos/6.jpg"), 60, 60); break;
	case 7:loadimage(&img, _T("photos/7.jpg"), 60, 60); break;
	case 8:loadimage(&img, _T("photos/8.jpg"), 60, 60); break;
	case 9:loadimage(&img, _T("photos/9.jpg"), 60, 60); break;
	case -1:loadimage(&img, _T("photos/10.jpg"), 60, 60); break;
	default:
		break;
	}
}

struct Status {
	int x;
	int y;
	int dire;
	int step;

	Status(int x = 0, int y = 0, int dire = -1, int step = 0) {
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


bool Link::BFS(int x, int y, int x2, int y2) {
	queue<Status> qu;
	stack<Status> st;
	stack<Status>min_path;
	bool visited[12][22]{}; //true代表走过，false代表没走过
	IMAGE img;
	loadImageFromPhoto(img, -1);
	

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 22; j++) {
			visited[i][j] = false;
		}
	}

	Status temp(x, y, -1, 0), top;
	qu.emplace(temp);
	st.emplace(temp);

	//visited[x][y] = true;

	while (!qu.empty()) {
		top = qu.front(); //弹出队首元素
		qu.pop();

		for (int i = 0; i < 4; i++) {
			if (top.dire == -1 || top.dire == i)
				temp.changeInfo(top.x + Next[i][0], top.y + Next[i][1], i, top.step);
			else
				temp.changeInfo(top.x + Next[i][0], top.y + Next[i][1], i, top.step + 1);

			if (!visited[temp.x][temp.y] && temp.x >= 0 && temp.x <= 11 && temp.y >= 0 && temp.y <= 21 && map[temp.x][temp.y]==-1&& temp.step <= 2) {

				qu.emplace(temp);
				st.emplace(temp);
				//visited[temp.x][temp.y] = true;
			}

			if (temp.x == x2 && temp.y == y2 && temp.step <=2){
	
				map[x][y] = map[x2][y2] = -1;
				putimage(60 * (y-1) + 30, 60 * (x-1) + 30, &img);
				putimage(60 * (y2-1) + 30, 60 * (x2-1) + 30, &img);
				return true;
			}
		}
	}

	return false;
}


bool Link::IsLink(int x1, int y_1, int x2, int y2) {
	if (x1 < 1 || x1>11 || x2 < 1 || x2>11)return false;
	if (y_1 < 1 || y_1>21 || y2 < 1 || y2>21)return false;
	if (map[x1][y_1] != map[x2][y2]) return false;
	if (x1 == x2 && y_1 == y2) return false;
	if (BFS(x1, y_1, x2, y2))return true;
	return false;
}


void Link::playGame() {
	createRandomMap();     //随机初始化地图

	readMap();      //从文件中读取初始地图信息

	initgraph(1260, 660); //图框大小

	ExMessage m1,m2;  //鼠标信息

	for (int i = -1; i < 11; i++) {
		for (int j = -1; j < 21; j++) {
			IMAGE img;
			loadImageFromPhoto(img, map[i+1][j+1]);
			putimage(60 * j + 30, 60 * i + 30, &img);
		}
	}
	int sum = 0, x1, y_1, x2, y2;

	while (sum != 200) {
		while (1) {
			m1 = getmessage(EM_MOUSE);
			if (m1.message == WM_LBUTTONDOWN && m1.x >= 30 && m1.x <= 1230 && m1.y >= 30 && m1.y <= 630) break;
		}

		while (1) {
			m2 = getmessage(EM_MOUSE);
			if (m2.message == WM_LBUTTONDOWN && m2.x >= 30 && m2.x <= 1230 && m2.y >= 30 && m2.y <= 630) break;
		}
		x1 = (m1.x - 30) / 60 + 1;
		y_1 = (m1.y - 30) / 60 + 1;
		x2 = (m2.x - 30) / 60 + 1;
		y2 = (m2.y - 30) / 60 + 1;
		if (IsLink(y_1, x1, y2, x2)) {
			sum += 2;
		}
	}

	closegraph();

	system("pause");
}
