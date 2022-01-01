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


//�������
void PostOrderTraverse(BiNode* root) {
	if (root == NULL)return;
	PostOrderTraverse(root->lChild);
	PostOrderTraverse(root->rChild);
	cout << root->data << ' ';
}


//���ٶ����������ú������
void DelBTree(BiNode* root) {
	if (root == NULL)return;
	DelBTree(root->lChild);
	DelBTree(root->rChild);

	delete root;
}


BiNode* DelChildTree(BiNode* root, elemType x) {
	if (root != NULL) {
		if (root->data == x) {
			DelBTree(root);
			return NULL;
		}
		else {
			root->lChild = DelChildTree(root->lChild, x);
			root->rChild = DelChildTree(root->rChild, x);
		}
	}
	return root;
}

int main() {
	cout << "��ʼ��T3.txt�ж�ȡԪ�ؽ���" << endl;
	fstream file("T3.txt", ios::in);
	BiNode* tree = CreateByPrio(file);
	file.close();
	cout << "��ȡ���,��ʼ���������" << endl;

	PreOrderTraverse_1(tree);

	elemType x;
	cout << endl << endl << "�����ַ�x��" << endl;
	cin >> x;

	tree  = DelChildTree(tree, x);
	cout << endl;

	cout << "ɾ����ϣ���ʼ���������" << endl;
	if (tree == NULL)cout << "��" << endl;
	else PreOrderTraverse_1(tree);

	return 0;
}
