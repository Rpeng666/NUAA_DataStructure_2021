#ifndef LINK_H
#include<iostream>
#include<fstream>
#include<ctime>
#include<algorithm>
#include<graphics.h>
#include<vector>
#include<tchar.h>
#include<queue>
#include<stack>

using namespace std;


class Link {
private:
	int map[12][22];
	bool visited[12][22];
	int Next[4][2] = {
		{-1,0}, //上走
		{1,0}, //下走
		{0,-1}, //左走
		{0,1}  //右走
	};

public:
	void createRandomMap();
	//从文件中读取初始地图信息
	void readMap();

	void loadImageFromPhoto(IMAGE& img, int num);

	void playGame();

	bool IsLink(int x1, int y_1, int x2, int y2);

	bool BFS(int x1, int y_1, int x2, int y2);
};
#endif // !LINK_H
