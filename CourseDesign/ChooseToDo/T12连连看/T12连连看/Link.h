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
		{-1,0}, //����
		{1,0}, //����
		{0,-1}, //����
		{0,1}  //����
	};

public:
	void createRandomMap();
	//���ļ��ж�ȡ��ʼ��ͼ��Ϣ
	void readMap();

	void loadImageFromPhoto(IMAGE& img, int num);

	void playGame();

	bool IsLink(int x1, int y_1, int x2, int y2);

	bool BFS(int x1, int y_1, int x2, int y2);
};
#endif // !LINK_H
