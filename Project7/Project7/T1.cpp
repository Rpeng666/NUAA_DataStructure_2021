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
	int type = 0;     //type = 0��������ͼ type=1��������ͼ
	int n;     //������
	int vetex[100][100];     //���������Ӿ������洢Ԫ��
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
		char ch, ch2;
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

	void DFSTraverse(int v) {

		visited[v] = 1;
		trace.emplace_back(v);

		bool flag = true;

		for (int i = 0; i < n; i++) {
			if (vetex[v][i] != 0 && visited[i] == 0) {
				flag = false;
				DFSTraverse(i);
			}
		}
		if (flag) {
			cout << "DFS��·����";
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

	void clear() {
		for (int i = 0; i < n; i++) {
			visited[i] = 0;
		}
		trace.clear();
	}

};


int main() {
	ADT_Graph graph;

	cout << "��ʼ��T1.txt�ж���㼯�ͱ༭����������ͼ" << endl;
	graph.CreateGraph(0);
	cout << "�������" << endl << endl;


	cout << "��ʼ����DFSTraverse()�ֲ�չʾDFS�Ĺ���" << endl;
	graph.DFSTraverse(0);
	cout << endl;


	cout << "��ʼ����BFSTraverse()" << endl;
	graph.clear();
	graph.BFSTraverse();
	cout << endl << endl;


	//�ֶ��ָ���
	cout << "-----------------------------------------------" << endl;

	cout << "��ʼ��T1.txt�ж���㼯�ͱ༭����������ͼ" << endl;
	graph.CreateGraph(1);
	cout << "�������" << endl << endl;


	cout << "��ʼ����DFSTraverse()�ֲ�չʾDFS�Ĺ���" << endl;
	graph.DFSTraverse(0);
	cout << endl;


	cout << "��ʼ����BFSTraverse()" << endl;
	graph.clear();
	graph.BFSTraverse();
	cout << endl << endl;

	return 0;
}