#include<iostream>
#include<fstream>
#include<map>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
typedef char elemType;


class ADT_Graph {
private:
	int type = 0;     //type = 0代表无向图 type=1代表有向图
	int n;     //顶点数
	int vetex[100][100];     //这里采用领接矩阵来存储元素
	map<int, char> map_to_char;
	map<char, int> map_to_int;
	int* visited;
	vector<int> trace;

public:
	void CreateGraph(int type) {
		
		this->type = type;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				vetex[i][j] = 0;
			}
		}

		fstream file("T1.txt", ios::in);
		int m;
		char ch,ch2;
		file >> n >> m;
		
		for (int i = 0; i < n; i++) {
			file >> ch;
			map_to_char[i] = ch;
			map_to_int.insert(pair<char, int>(ch, i));
		}

		for (int i = 0; i < m; i++) {
			file >> ch >> ch2;
			if (type == 0) {
				vetex[map_to_int.find(ch)->second][map_to_int.find(ch2)->second] = 1;
				vetex[map_to_int.find(ch2)->second][map_to_int.find(ch)->second] = 1;
			}
			else if (type == 1) {
				vetex[map_to_int.find(ch)->second][map_to_int.find(ch2)->second] = 1;
			}
		}

		visited = new int[n];

		for (int i = 0; i < n; i++)visited[i] = 0;

		file.close();
	}

	void DestroyGraph() {
		delete visited;
	}

	char GetVex(int v) {
		return map_to_char.find(v) != map_to_char.end() ? map_to_char.find(v)->second : '无';
	}

	char FirstAdjVex(char v) {
		int i = 0;
		for (; i < n; i++) {
			if (vetex[map_to_int.find(v)->second][i] != 0) {
				break;
			}
		}

		if (i == n) {
			cout << "无";
			return NULL;
		}
		return map_to_char.find(i)->second;
	}

	char NextAdjVex(char v,char w) {
		int v1 = map_to_int.find(v)->second;
		int v2 = map_to_int.find(w)->second;

		for (int i = v2 + 1; i < n; i++) {
			if (vetex[v1][i] == 1) {
				return map_to_char.find(i)->second;
			}
		}
		cout << "无";
	}

	void DFSTraverse(int v) {

		visited[v] = 1;
		trace.emplace_back(v);

		bool flag = true;

		for (int i = 0; i < n; i++) {
			if (vetex[v][i] != 0 && visited[i]==0) {
				flag = false;
				DFSTraverse(i);
			}
		}
		if (flag) {
			cout << "DFS的路径：";
			for (int i = 0; i < trace.size(); i++) {
				cout << map_to_char.find(trace[i])->second << ' ';
			}
			cout << endl;
		}

		trace.pop_back();
		visited[v] = 0;
	}

	void BFSTraverse() {
		queue<int> qu;
		qu.emplace(0);

		for (int i = 0; i < n; i++) {
			visited[i] = 0;
		}
		visited[0] = 1;

		while (qu.size() != 0) {
			cout << map_to_char[qu.front()] << ' ';
			for (int i = 0; i < n; i++) {
				if (vetex[qu.front()][i] == 1 && visited[i] == 0) {
					qu.emplace(i);
					visited[i] = 1;
				}
			}
			qu.pop();
		}
	}

	void InsertVex(char V) {
		n++;
		map_to_char.insert(pair<int, char>(n - 1, V));
		map_to_int.insert(pair<char, int>(V, n - 1));
	}

	void InsertArc(char V, char W) {
		int v = map_to_int.find(V)->second;
		int w = map_to_int.find(W)->second;

		if (type == 0) {
			vetex[v][w] = vetex[w][v] = 1;
		}
		else if (type == 1) {
			vetex[v][w] = 1;
		}
	}

	void DeleteVex(char V, char W) {
		int v = map_to_int.find(V)->second;
		int w = map_to_int.find(W)->second;
		if (type == 0) {
			vetex[v][w] = vetex[w][v] = 0;
		}
		else if (type == 1) {
			vetex[v][w] = 0;
		}
	}

	void GetAllVex() {
		for (int i = 0; i < n; i++) {
			cout << map_to_char.find(i)->second << ' ';
		}
	}

	void clear() {
		for (int i = 0; i < n; i++) {
			visited[i] = 0;
		}
		trace.clear();
	}

};


int main() {
	ADT_Graph graph;

	cout << "开始从T1.txt中读入点集和编辑来构造无向图" << endl;
	graph.CreateGraph(0);
	cout << "构造完成" << endl << endl;
	

	cout << "开始测试GetVex()" << endl;
	cout << "编号为0的元素为："<< graph.GetVex(0) << endl;
	cout << "编号为1的元素为：" << graph.GetVex(1) << endl;
	cout << "编号为2的元素为：" << graph.GetVex(2) << endl;
	cout << "编号为3的元素为：" << graph.GetVex(3) << endl;
	cout << "编号为4的元素为：" << graph.GetVex(4) << endl;
	cout << "编号为5的元素为：" << graph.GetVex(5) << endl;
	cout << "编号为6的元素为：" << graph.GetVex(6) << endl;
	cout << "编号为7的元素为：" << graph.GetVex(7) << endl << endl;


	cout << "开始测试FirstAdjVex()" << endl;
	cout << "点A的第一个邻接点" << graph.FirstAdjVex('A') << endl;
	cout << "点H的第一个邻接点" << graph.FirstAdjVex('H') << endl;
	cout << "点E的第一个邻接点" << graph.FirstAdjVex('E') << endl << endl;


	cout << "开始测试NextAdjVex()" << endl;
	cout << "点A相对点B的下一个邻接点" << graph.NextAdjVex('A','B') << endl;
	cout << "点H相对点E的下一个邻接点" << graph.NextAdjVex('H', 'E') << endl;
	cout << "点D相对点A的下一个邻接点" << graph.NextAdjVex('D', 'A') << endl << endl;

	
	cout << "开始测试DFSTraverse()分步展示DFS的过程" << endl;
	graph.DFSTraverse(0);
	cout << endl;


	cout << "开始测试BFSTraverse()" << endl;
	graph.clear();
	graph.BFSTraverse();
	cout << endl << endl;


	cout << "开始测试InsertVex()" << endl;
	cout << "添加点I和J" << endl;
	graph.InsertVex('I');
	graph.InsertVex('J');
	cout << "添加完毕，开始遍历图中所有的点:" << endl;
	graph.GetAllVex();
	cout << endl << endl;

	cout << "开始测试InsertArc()" << endl;
	cout << "添加边(I,J)和(E,I)" << endl;
	graph.InsertArc('I','J');
	graph.InsertArc('E','I');
	cout << "添加完毕，开始进行深搜：" << endl;
	graph.clear();
	graph.DFSTraverse(0);
	cout << endl << endl;


	cout << "开始测试DeleteVex()" << endl;
	cout << "删除边(J,I)和(E,I)" << endl;
	graph.DeleteVex('J', 'I');
	graph.DeleteVex('E', 'I');
	cout << "添加完毕，开始进行深搜：" << endl;
	graph.clear();
	graph.DFSTraverse(0);
	cout << endl << endl;


	//手动分割线
	cout << "-----------------------------------------------" << endl;

	cout << "开始从T1.txt中读入点集和编辑来构造有向图" << endl;
	graph.CreateGraph(1);
	cout << "构造完成" << endl << endl;


	cout << "开始测试GetVex()" << endl;
	cout << "编号为0的元素为：" << graph.GetVex(0) << endl;
	cout << "编号为1的元素为：" << graph.GetVex(1) << endl;
	cout << "编号为2的元素为：" << graph.GetVex(2) << endl;
	cout << "编号为3的元素为：" << graph.GetVex(3) << endl;
	cout << "编号为4的元素为：" << graph.GetVex(4) << endl;
	cout << "编号为5的元素为：" << graph.GetVex(5) << endl;
	cout << "编号为6的元素为：" << graph.GetVex(6) << endl;
	cout << "编号为7的元素为：" << graph.GetVex(7) << endl << endl;


	cout << "开始测试FirstAdjVex()" << endl;
	cout << "点A的第一个邻接点" << graph.FirstAdjVex('A') << endl;
	cout << "点H的第一个邻接点" << graph.FirstAdjVex('H') << endl;
	cout << "点E的第一个邻接点" << graph.FirstAdjVex('E') << endl << endl;


	cout << "开始测试NextAdjVex()" << endl;
	cout << "点A相对点B的下一个邻接点" << graph.NextAdjVex('A', 'B') << endl;
	cout << "点H相对点E的下一个邻接点" << graph.NextAdjVex('H', 'E') << endl;
	cout << "点D相对点A的下一个邻接点" << graph.NextAdjVex('D', 'A') << endl << endl;


	cout << "开始测试DFSTraverse()分步展示DFS的过程" << endl;
	graph.DFSTraverse(0);
	cout << endl;


	cout << "开始测试BFSTraverse()" << endl;
	graph.clear();
	graph.BFSTraverse();
	cout << endl << endl;


	cout << "开始测试InsertVex()" << endl;
	cout << "添加点I和J" << endl;
	graph.InsertVex('I');
	graph.InsertVex('J');
	cout << "添加完毕，开始遍历图中所有的点:" << endl;
	graph.GetAllVex();
	cout << endl << endl;

	cout << "开始测试InsertArc()" << endl;
	cout << "添加边(J,I)和(E,I)" << endl;
	graph.InsertArc('J', 'I');
	graph.InsertArc('E', 'I');
	cout << "添加完毕，开始进行深搜：" << endl;
	graph.clear();
	graph.DFSTraverse(0);
	cout << endl << endl;


	cout << "开始测试DeleteVex()" << endl;
	cout << "删除边(I,J)和(E,I)" << endl;
	graph.DeleteVex('I', 'J');
	graph.DeleteVex('E', 'I');
	cout << "添加完毕，开始进行深搜：" << endl;
	graph.clear();
	graph.DFSTraverse(0);
}