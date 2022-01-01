#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
typedef char elemType;


struct BiNode {
	elemType data;
	BiNode*lChild, *rChild;
};

BiNode* CreateByPrio(fstream &file) {
	elemType temp;
	file >> temp;
	if (temp == '#')return NULL;

	BiNode* newNode = new BiNode;

	newNode->data = temp;
	newNode->lChild = CreateByPrio(file);
	newNode->rChild = CreateByPrio(file);

	return newNode;
}


void PreOrderTraverse_1(BiNode* root) {
	if (root == NULL)return;
	cout << root->data << ' ';
	PreOrderTraverse_1(root->lChild);
	PreOrderTraverse_1(root->rChild);
}

//判断一棵树是否是完全二叉树
bool TreeComplete(BiNode* root) {
	if (root->lChild != NULL && root->rChild == NULL)return false;
	if (root->lChild == NULL && root->rChild != NULL) return false;
	if (root->lChild == NULL && root->rChild == NULL) return true;
	
	return  TreeComplete(root->lChild) && TreeComplete(root->rChild);
}


int main() {
	cout << "开始从T3.txt中读取元素建树" << endl;
	fstream file("T3.txt", ios::in);
	BiNode* tree = CreateByPrio(file);
	file.close();
	cout << "读取完毕,开始先序遍历：" << endl;

	PreOrderTraverse_1(tree);
	cout << endl << endl;

	if (TreeComplete(tree))cout << "这是一棵完全二叉树" << endl;
	else cout << "这不是一棵完全二叉树" << endl;

	return 0;
}

