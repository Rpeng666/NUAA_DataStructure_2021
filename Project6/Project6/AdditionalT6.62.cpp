#include<iostream>
#include<fstream>
using namespace std;


struct BiNode {
	char data;
	BiNode* firstChild;
	BiNode* nextbrother;
};


BiNode* CreateByPrio(fstream &file) {
	char temp;
	file >> temp;
	if (temp == '#')return NULL;
	BiNode* newNode = new BiNode;

	newNode->data = temp;
	newNode->firstChild = CreateByPrio(file);
	newNode->nextbrother = CreateByPrio(file);

	return newNode;
}

int getDepth(BiNode * root, int level) {

	if (root == NULL) return level - 1;
	int level_1 = getDepth(root->firstChild, level + 1);
	int level_2 = getDepth(root->nextbrother, level);

	return level_1 > level_2 ? level_1 : level_2;
}


void travelByPrio(BiNode* root) {
	if (root == NULL) return;
	cout << root->data << ' ';
	travelByPrio(root->firstChild);
	travelByPrio(root->nextbrother);
}



void destroyTree(BiNode* root) {
	if (root == NULL) return;
	destroyTree(root->firstChild);
	destroyTree(root->nextbrother);
	delete root;
}

int main() {
	fstream file("T3.txt", ios::in);

	cout << "��ʼ��T3.txt�ж�ȡԪ�ع��������" << endl << endl;
	BiNode* root = CreateByPrio(file);
	file.close();

	int depth = getDepth(root, 1);
	cout << "ԭ�����(�Ƕ�����)�����Ϊ��" << depth << endl << endl;


	cout << "��ʼ������" << endl;
	destroyTree(root);
	cout << "������ϣ�" << endl;

	return 0;
}