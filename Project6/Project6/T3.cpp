#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

struct BiNode {
	char data;
	BiNode* lChild;
	BiNode* rChild;
};


BiNode* CreateByPrio(fstream &file) {
	char temp;
	file >> temp;
	if (temp == '#')return NULL;
	BiNode* newNode = new BiNode;

	newNode->data = temp;
	newNode->lChild = CreateByPrio(file);
	newNode->rChild = CreateByPrio(file);

	return newNode;
}


void travelByPrio(BiNode* root) {
	if (root == NULL) return;
	cout << root->data << ' ';
	travelByPrio(root->lChild);
	travelByPrio(root->rChild);
}


int getWidth(BiNode* root) {
	int max = -99999, sum = 0,temp =0;
	queue<BiNode*> qu;
	qu.emplace(root);

	sum = 1;

	while (!qu.empty()) {
		temp = 0;
		for (int i = 0; i < sum; i++) {
			if (qu.front()->lChild != NULL) {
				qu.emplace(qu.front()->lChild);
				temp++;
			}
			if (qu.front()->rChild != NULL) {
				qu.emplace(qu.front()->rChild);
				temp++;
			}
			qu.pop();
		}
		sum = temp;
		max = max > sum ? max : sum;
	}

	return max;
}


int main() {

	fstream file("T3.txt", ios::in);

	cout << "��ʼ��T3.txt�ж�ȡԪ�ع��������" << endl;
	BiNode* root = CreateByPrio(file);
	file.close();

	cout << endl << "������ϣ����������:" << endl;
	travelByPrio(root);
	cout << endl << endl;


	cout << "��ζ������Ŀ��Ϊ��" << getWidth(root) << endl;
}