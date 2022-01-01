#include<iostream>
#include<fstream>
#include<algorithm>
#include<iomanip>
using namespace std;
#define MAX_LIMIT 999999999

int MGraph[100][100];
int* dist, *path, *flag;
int N;


void Dijkstra(int start) {
	dist = new int[N];
	path = new int[N];
	flag = new int[N];
	int min_dis,min_elem;

	for (int i = 0; i < N; i++) {
		flag[i] = 0;
		dist[i] = MGraph[start][i];
		if (dist[i] < MAX_LIMIT)path[i] = start;
		else path[i] = -1;
	}

	flag[start] = 1;

	for (int i = 0; i < N - 1; i++) {
		min_dis = MAX_LIMIT;

		for (int j = 0; j < N; j++) {
			if (flag[j] == 0 && dist[j] < min_dis) {
				min_dis = dist[j];
				min_elem = j;
			}
		}

		flag[min_elem] = 1;

		if (min_dis < MAX_LIMIT) {
			for (int j = 0; j < N; j++) {
				if (flag[j] == 0 && dist[j] > min_dis + MGraph[min_elem][j]) {
					dist[j] = min_dis + MGraph[min_elem][j];
					path[j] = min_elem;
				}
			}
		}
	}

}


void CreateGraph(fstream & file) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			MGraph[i][j] = MAX_LIMIT;
		}
	}

	int m;
	int from, to, value;
	file >> m;

	while (m--) {
		file >> from >> to >> value;
		MGraph[from][to] = value;
	}
}


int main() {
	
	fstream file("T2.txt", ios::in);
	file >> N;
	
	cout << "开始从T2.txt中读取元素构造(有向图的)邻接矩阵" << endl;
	CreateGraph(file);

	file.close();
	cout << "构造完成" << endl << endl;

	cout << "展示邻接矩阵" << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MGraph[i][j] == MAX_LIMIT) {
				cout << setw(5) << -1;
			}
			else {
				cout << setw(5) << MGraph[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;

	cout << "开始调用Dijkstra()" << endl;
	Dijkstra(0);

	cout << "调用完成" << endl << endl;
	cout << MAX_LIMIT << " 代表正无穷" << endl << endl;

	int temp;
	for (int i = 0; i < N; i++) {
		temp = i;
		cout << " 0 号节点到 " << i << " 号节点的最短长度为: " << setw(10) <<setiosflags(ios::left)<< dist[i];

		cout << "路径为：" << temp << ' ';
		while (path[temp] != -1) {
			cout << path[temp] << ' ';
			temp = path[temp];
		}
		cout << endl;
	}



	delete dist;
	delete path;
	delete flag;
	
	return 0;
}