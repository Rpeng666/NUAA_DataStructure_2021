#include<iostream>
#include<fstream>
#include<map>
#include<stack>

#define inf 21474836
#define maxn 510

using namespace std;

long long min(long long a, long long b) {
	return (a > b) ? b : a;
}

class Edge {
public:
	long long Avenue;     //大路
	long long Path;       //小路

	Edge();
	void Change(long long a, bool IsPath);
};

Edge::Edge() {
	Avenue = inf;
	Path = inf;
}

void Edge::Change(long long dis, bool IsPath) {
	if (IsPath) {      //IsPath 传入1的时候为True ，此时判断为小路
		Path = Path > dis ? dis : Path;
	}
	else {
		Avenue = Avenue > dis ? dis : Avenue;
	}
}

Edge Graph[maxn][maxn];
long long m, n;          //n个路口，m条道路
long long path_Path[maxn][maxn];

void GetData(string filename = "data.txt") {

	fstream file(filename.c_str(), ios::in);
	if (file.fail()) {
		cout << "打开文件失败！" << endl;
		return;
	}
	file >> n >> m;
	long long t, a, b, c;

	for (long long i = 1;i <= m;++i) {
		file >> t >> a >> b >> c;
		Graph[a][b].Change(c, t);     //双向道路
		Graph[b][a].Change(c, t);
	}
	file.close();
}

void Path_Floyd(){
	//i路口到j路口必须经过j路口，j路口到j路口的路径长度为0
	for (long long i = 1; i <= n; i++)
		for (long long j = 1; j <= n; j++)
			path_Path[i][j] = j, Graph[j][j].Path = 0;    

	for (long long k = 1; k <= n; ++k)
		for (long long i = 1; i <= n; ++i)
			for (long long j = 1; j <= n; ++j)
				if (Graph[i][k].Path + Graph[k][j].Path < Graph[i][j].Path ) {
					Graph[i][j].Path = Graph[i][k].Path + Graph[k][j].Path;
					path_Path[i][j] = path_Path[i][k];
				}

	for (long long k = 1; k <= n; k++)
		Graph[k][k].Path = inf;
}

class Cost {
public:
	long long Sum_Cost;    //总的疲劳值
	bool Is_Avenue_Now;   //是否是大路

	Cost();
	Cost(bool flag);
};

Cost::Cost() {
	Sum_Cost = inf;
	Is_Avenue_Now = 0;
}

Cost::Cost(bool flag) {
	Sum_Cost = inf;
	Is_Avenue_Now = flag;
}

class Node_Cost {
public:
	Cost Avenue_Now;
	Cost Path_Now;

	Node_Cost();
	long long Min_Cost();
};

Node_Cost::Node_Cost() {
	Avenue_Now = true;
	Path_Now = false;
}

long long Node_Cost::Min_Cost() {
	return min(Avenue_Now.Sum_Cost, Path_Now.Sum_Cost);
}

Node_Cost dis[maxn];
bool Is_Visited[maxn];
long long path[maxn];


void Dijkstra(long long s = 1){

	long long i, v, u;
	for (i = 1; i <= n; ++i)
	{
		Is_Visited[i] = false;
		dis[i].Avenue_Now = Graph[s][i].Avenue;
		dis[i].Path_Now = Graph[s][i].Path;
	}

	Is_Visited[s] = true;
	dis[s].Avenue_Now.Sum_Cost = 0;
	dis[s].Path_Now.Sum_Cost = 0;

	v = s;

	for (u = 1; u <= n; ++u) {
		dis[u].Avenue_Now.Sum_Cost = min(dis[u].Avenue_Now.Sum_Cost, dis[v].Avenue_Now.Sum_Cost + Graph[v][u].Avenue);
		dis[u].Avenue_Now.Sum_Cost = min(dis[u].Avenue_Now.Sum_Cost, dis[v].Path_Now.Sum_Cost + Graph[v][u].Avenue);

		long long temp;
		temp = dis[v].Avenue_Now.Sum_Cost + Graph[v][u].Path * Graph[v][u].Path;

		if (dis[u].Path_Now.Sum_Cost > temp) {
			dis[u].Path_Now.Sum_Cost = temp;
		}
		if (dis[u].Min_Cost() < inf)
			path[u] = s;
		else
			path[u] = -1;
	}

	while (true)
	{
		v = -1;
		for (u = 1; u <= n; ++u) {
			if (!Is_Visited[u] && (v == -1 || dis[u].Min_Cost() < dis[v].Min_Cost())) {
				v = u;
			}
		}

		if (v != -1) {
			Is_Visited[v] = true;

			for (u = 1; u <= n; ++u) {
				if (dis[u].Avenue_Now.Sum_Cost > dis[v].Avenue_Now.Sum_Cost + Graph[v][u].Avenue) {
					dis[u].Avenue_Now.Sum_Cost = dis[v].Avenue_Now.Sum_Cost + Graph[v][u].Avenue;
					path[u] = v;
				}
				if (dis[u].Avenue_Now.Sum_Cost > dis[v].Path_Now.Sum_Cost + Graph[v][u].Avenue) {
					dis[u].Avenue_Now.Sum_Cost = dis[v].Path_Now.Sum_Cost + Graph[v][u].Avenue;
					path[u] = v;
					int t = path[v];
					path[u] = path_Path[u][v];
					int w = v;
					while (w != t) {
						path[w] = path_Path[w][t];
						w = path_Path[w][t];
					}
				}
				long long temp;
				temp = dis[v].Avenue_Now.Sum_Cost + Graph[v][u].Path * Graph[v][u].Path;

				if (dis[u].Path_Now.Sum_Cost > temp) {
					dis[u].Path_Now.Sum_Cost = temp;
					path[u] = v;
				}
			}
		}
		else
			break;
	}
}


int main() {
	GetData();
	Path_Floyd();
	Dijkstra();

	//单源最短路
	cout << "各点的疲劳值：";
	for (long long i = 1; i <= n; ++i)
		cout << dis[i].Min_Cost() << " ";
	cout << endl << endl;

	cout << "总的最小疲劳值:" << dis[n].Min_Cost() << endl;

	//路径
	stack<long long>backpath;
	long long current = n;

	while (current != 1) {
		backpath.push(current);
		current = path[current];
	}

	cout << endl << "最优路劲：1";
	while (!backpath.empty()) {
		cout << " -> " << backpath.top();
		backpath.pop();
	}
	cout << endl;

	return 0;
}
