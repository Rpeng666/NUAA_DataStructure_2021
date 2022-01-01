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

//�ж�һ�����Ƿ�����ȫ������
bool TreeComplete(BiNode* root) {
	if (root->lChild != NULL && root->rChild == NULL)return false;
	if (root->lChild == NULL && root->rChild != NULL) return false;
	if (root->lChild == NULL && root->rChild == NULL) return true;
	
	return  TreeComplete(root->lChild) && TreeComplete(root->rChild);
}


int main() {
	cout << "��ʼ��T3.txt�ж�ȡԪ�ؽ���" << endl;
	fstream file("T3.txt", ios::in);
	BiNode* tree = CreateByPrio(file);
	file.close();
	cout << "��ȡ���,��ʼ���������" << endl;

	PreOrderTraverse_1(tree);
	cout << endl << endl;

	if (TreeComplete(tree))cout << "����һ����ȫ������" << endl;
	else cout << "�ⲻ��һ����ȫ������" << endl;

	return 0;
}

