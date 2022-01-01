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


void allElemOnLevel(BiNode* root, int level, int i) {
	if (root == NULL) return;
	if (level == i) {
		cout << root->data << ' ';
	}

	allElemOnLevel(root->firstChild, level + 1, i);
	allElemOnLevel(root->nextbrother, level, i);
}

void destroyTree(BiNode* root) {
	if (root == NULL) return;
	destroyTree(root->firstChild);
	destroyTree(root->nextbrother);
	delete root;
}

int main() {
	fstream file("T3.txt", ios::in);

	cout << "开始从T3.txt中读取元素构造二叉树" << endl << endl;
	BiNode* root = CreateByPrio(file);
	file.close();

	int depth = getDepth(root, 1);
	cout << "原多叉树(非二叉树)的深度为：" << depth << endl << endl;

	for (int i = 1; i <= depth; i++) {
		cout << "第" << i << "层的元素分别为：";
		allElemOnLevel(root, 1, i);
		cout << endl;
	}

	cout << "开始销毁树" << endl;
	destroyTree(root);
	cout << "销毁完毕！" << endl;

	return 0;
}