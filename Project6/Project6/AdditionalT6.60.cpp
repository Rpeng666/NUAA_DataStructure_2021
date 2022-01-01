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



void travelByPrio(BiNode* root) {
	if (root == NULL) return;
	cout << root->data << ' ';
	travelByPrio(root->firstChild);
	travelByPrio(root->nextbrother);
}

//遍历，只要遇到左节点为空的节点，那么它就是原树的叶节点
void getAllLeaf(BiNode* root) {
	if (root == NULL)return;
	if (root->firstChild == NULL) {
		cout << root->data << ' ';
	}
	getAllLeaf(root->firstChild);
	getAllLeaf(root->nextbrother);
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

	cout << "开始寻找所有的叶节点: " << endl;
	getAllLeaf(root);
	cout << endl << "查找完毕" << endl << endl;

	cout << "开始销毁树" << endl;
	destroyTree(root);
	cout << "销毁完毕！" << endl;

	return 0;
}