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
		return map_to_char.find(v) != map_to_char.end() ? map_to_char.find(v)->second : '��';
	}

	char FirstAdjVex(char v) {
		int i = 0;
		for (; i < n; i++) {
			if (vetex[map_to_int.find(v)->second][i] != 0) {
				break;
			}
		}

		if (i == n) {
			cout << "��";
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
		cout << "��";
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

	cout << "��ʼ��T1.txt�ж���㼯�ͱ༭����������ͼ" << endl;
	graph.CreateGraph(0);
	cout << "�������" << endl << endl;
	

	cout << "��ʼ����GetVex()" << endl;
	cout << "���Ϊ0��Ԫ��Ϊ��"<< graph.GetVex(0) << endl;
	cout << "���Ϊ1��Ԫ��Ϊ��" << graph.GetVex(1) << endl;
	cout << "���Ϊ2��Ԫ��Ϊ��" << graph.GetVex(2) << endl;
	cout << "���Ϊ3��Ԫ��Ϊ��" << graph.GetVex(3) << endl;
	cout << "���Ϊ4��Ԫ��Ϊ��" << graph.GetVex(4) << endl;
	cout << "���Ϊ5��Ԫ��Ϊ��" << graph.GetVex(5) << endl;
	cout << "���Ϊ6��Ԫ��Ϊ��" << graph.GetVex(6) << endl;
	cout << "���Ϊ7��Ԫ��Ϊ��" << graph.GetVex(7) << endl << endl;


	cout << "��ʼ����FirstAdjVex()" << endl;
	cout << "��A�ĵ�һ���ڽӵ�" << graph.FirstAdjVex('A') << endl;
	cout << "��H�ĵ�һ���ڽӵ�" << graph.FirstAdjVex('H') << endl;
	cout << "��E�ĵ�һ���ڽӵ�" << graph.FirstAdjVex('E') << endl << endl;


	cout << "��ʼ����NextAdjVex()" << endl;
	cout << "��A��Ե�B����һ���ڽӵ�" << graph.NextAdjVex('A','B') << endl;
	cout << "��H��Ե�E����һ���ڽӵ�" << graph.NextAdjVex('H', 'E') << endl;
	cout << "��D��Ե�A����һ���ڽӵ�" << graph.NextAdjVex('D', 'A') << endl << endl;

	
	cout << "��ʼ����DFSTraverse()�ֲ�չʾDFS�Ĺ���" << endl;
	graph.DFSTraverse(0);
	cout << endl;


	cout << "��ʼ����BFSTraverse()" << endl;
	graph.clear();
	graph.BFSTraverse();
	cout << endl << endl;


	cout << "��ʼ����InsertVex()" << endl;
	cout << "��ӵ�I��J" << endl;
	graph.InsertVex('I');
	graph.InsertVex('J');
	cout << "�����ϣ���ʼ����ͼ�����еĵ�:" << endl;
	graph.GetAllVex();
	cout << endl << endl;

	cout << "��ʼ����InsertArc()" << endl;
	cout << "��ӱ�(I,J)��(E,I)" << endl;
	graph.InsertArc('I','J');
	graph.InsertArc('E','I');
	cout << "�����ϣ���ʼ�������ѣ�" << endl;
	graph.clear();
	graph.DFSTraverse(0);
	cout << endl << endl;


	cout << "��ʼ����DeleteVex()" << endl;
	cout << "ɾ����(J,I)��(E,I)" << endl;
	graph.DeleteVex('J', 'I');
	graph.DeleteVex('E', 'I');
	cout << "�����ϣ���ʼ�������ѣ�" << endl;
	graph.clear();
	graph.DFSTraverse(0);
	cout << endl << endl;


	//�ֶ��ָ���
	cout << "-----------------------------------------------" << endl;

	cout << "��ʼ��T1.txt�ж���㼯�ͱ༭����������ͼ" << endl;
	graph.CreateGraph(1);
	cout << "�������" << endl << endl;


	cout << "��ʼ����GetVex()" << endl;
	cout << "���Ϊ0��Ԫ��Ϊ��" << graph.GetVex(0) << endl;
	cout << "���Ϊ1��Ԫ��Ϊ��" << graph.GetVex(1) << endl;
	cout << "���Ϊ2��Ԫ��Ϊ��" << graph.GetVex(2) << endl;
	cout << "���Ϊ3��Ԫ��Ϊ��" << graph.GetVex(3) << endl;
	cout << "���Ϊ4��Ԫ��Ϊ��" << graph.GetVex(4) << endl;
	cout << "���Ϊ5��Ԫ��Ϊ��" << graph.GetVex(5) << endl;
	cout << "���Ϊ6��Ԫ��Ϊ��" << graph.GetVex(6) << endl;
	cout << "���Ϊ7��Ԫ��Ϊ��" << graph.GetVex(7) << endl << endl;


	cout << "��ʼ����FirstAdjVex()" << endl;
	cout << "��A�ĵ�һ���ڽӵ�" << graph.FirstAdjVex('A') << endl;
	cout << "��H�ĵ�һ���ڽӵ�" << graph.FirstAdjVex('H') << endl;
	cout << "��E�ĵ�һ���ڽӵ�" << graph.FirstAdjVex('E') << endl << endl;


	cout << "��ʼ����NextAdjVex()" << endl;
	cout << "��A��Ե�B����һ���ڽӵ�" << graph.NextAdjVex('A', 'B') << endl;
	cout << "��H��Ե�E����һ���ڽӵ�" << graph.NextAdjVex('H', 'E') << endl;
	cout << "��D��Ե�A����һ���ڽӵ�" << graph.NextAdjVex('D', 'A') << endl << endl;


	cout << "��ʼ����DFSTraverse()�ֲ�չʾDFS�Ĺ���" << endl;
	graph.DFSTraverse(0);
	cout << endl;


	cout << "��ʼ����BFSTraverse()" << endl;
	graph.clear();
	graph.BFSTraverse();
	cout << endl << endl;


	cout << "��ʼ����InsertVex()" << endl;
	cout << "��ӵ�I��J" << endl;
	graph.InsertVex('I');
	graph.InsertVex('J');
	cout << "�����ϣ���ʼ����ͼ�����еĵ�:" << endl;
	graph.GetAllVex();
	cout << endl << endl;

	cout << "��ʼ����InsertArc()" << endl;
	cout << "��ӱ�(J,I)��(E,I)" << endl;
	graph.InsertArc('J', 'I');
	graph.InsertArc('E', 'I');
	cout << "�����ϣ���ʼ�������ѣ�" << endl;
	graph.clear();
	graph.DFSTraverse(0);
	cout << endl << endl;


	cout << "��ʼ����DeleteVex()" << endl;
	cout << "ɾ����(I,J)��(E,I)" << endl;
	graph.DeleteVex('I', 'J');
	graph.DeleteVex('E', 'I');
	cout << "�����ϣ���ʼ�������ѣ�" << endl;
	graph.clear();
	graph.DFSTraverse(0);
}