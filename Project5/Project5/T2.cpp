#include<iostream>
#include<fstream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef char elemType;


struct BiNode {
	elemType data;
	BiNode*lChild, *rChild;
	bool left = false;
	bool right = false;
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

//先序遍历（递归版本）
void PreOrderTraverse_1(BiNode* root) {
	if (root == NULL)return;
	cout << root->data << ' ';
	PreOrderTraverse_1(root->lChild);
	PreOrderTraverse_1(root->rChild);
}

//先序遍历（非递归版本）
void PreOrderTraverse_2(BiNode* root) {
	stack<BiNode*>ST;
	ST.emplace(root);
	BiNode* topNode;

	while (ST.size() != 0) {
		if(ST.top()->left == false &&ST.top()->right == false)
			cout << ST.top()->data << ' ';

		if (ST.top()->lChild != NULL && ST.top()->left == false) {
			topNode = ST.top();
			ST.pop();
			topNode->left = true;
			ST.emplace(topNode);
			ST.emplace(ST.top()->lChild);
		}
		
		else if (ST.top()->rChild != NULL && ST.top()->right == false) {
			topNode = ST.top();
			ST.pop();
			topNode->right = true;
			ST.emplace(topNode);
			ST.emplace(ST.top()->rChild);
		}

		else {
			ST.pop();
		}
	}
}




//中序遍历（递归版本）
void InOrderTraverse_1(BiNode* root) {
	if (root == NULL)return;
	InOrderTraverse_1(root->lChild);
	cout << root->data << ' ';
	InOrderTraverse_1(root->rChild);
}

//中序遍历（非递归版本）
void InOrderTraverse_2(BiNode* root) {
	stack<BiNode*>ST;
	ST.emplace(root);
	BiNode* topNode;

	while (ST.size() != 0) {

		if (ST.top()->lChild != NULL && ST.top()->left == false) {
			topNode = ST.top();
			ST.pop();
			topNode->left = true;
			ST.emplace(topNode);
			ST.emplace(ST.top()->lChild);
			continue;
		}
		
		if(ST.top()->left == false || ST.top()->right == false)
		cout << ST.top()->data << ' ';
		
		if (ST.top()->rChild != NULL && ST.top()->right == false) {
			topNode = ST.top();
			ST.pop();
			topNode->right = true;
			ST.emplace(topNode);
			ST.emplace(ST.top()->rChild);
			continue;
		}

		ST.pop();
	}
}



//后序遍历（递归版本）
void PostOrderTraverse_1(BiNode* root) {
	if (root == NULL)return;
	PostOrderTraverse_1(root->lChild);
	PostOrderTraverse_1(root->rChild);
	cout << root->data << ' ';
}

//后序遍历（非递归版本）
void PostOrderTraverse_2(BiNode* root) {
	stack<BiNode*>ST;
	ST.emplace(root);
	BiNode* topNode;

	while (ST.size() != 0) {

		if (ST.top()->lChild != NULL && ST.top()->left == false) {
			topNode = ST.top();
			ST.pop();
			topNode->left = true;
			ST.emplace(topNode);
			ST.emplace(ST.top()->lChild);
			continue;
		}

		if (ST.top()->rChild != NULL && ST.top()->right == false) {
			topNode = ST.top();
			ST.pop();
			topNode->right = true;
			ST.emplace(topNode);
			ST.emplace(ST.top()->rChild);
			continue;
		}
		cout << ST.top()->data << ' ';

		ST.pop();
	}
}



//层次遍历
void LevelOrderTraverse(BiNode* root) {
	queue<BiNode*> QB;
	int num = 1, temp = 0;
	QB.emplace(root);

	while (QB.size() != 0) {
		temp = 0;
		while (num--) {
			cout << QB.front()->data << ' ';

			if (QB.front()->lChild != NULL) {
				QB.emplace(QB.front()->lChild);
				temp++;
			}
			if (QB.front()->rChild != NULL) {
				QB.emplace(QB.front()->rChild);
				temp++;
			}
			QB.pop();
		}
		num = temp;
	}
}


void Destroy(BiNode* root) {
	if (root == NULL)return;
	Destroy(root->lChild);
	Destroy(root->rChild);
	delete root;
}


int main() {
	cout << "开始从T1.txt中读取元素建树" << endl;
	fstream file("T1.txt", ios::in);
	BiNode* tree = CreateByPrio(file);
	file.close();
	cout << "读取完毕" << endl;

	cout << "先序遍历（递归版本）" << endl;
	PreOrderTraverse_1(tree);
	cout << endl << endl;

	cout << "先序遍历（非递归版本）" << endl;
	PreOrderTraverse_2(tree);
	cout << endl << endl;

	Destroy(tree);


	file.open("T1.txt", ios::in);
	tree = CreateByPrio(file);
	file.close();

	cout << "中序遍历（递归版本）" << endl;
	InOrderTraverse_1(tree);
	cout << endl << endl;

	cout << "中序遍历（非递归版本）" << endl;
	InOrderTraverse_2(tree);
	cout << endl << endl;

	Destroy(tree);


	file.open("T1.txt", ios::in);
	tree = CreateByPrio(file);
	file.close();

	cout << "后序遍历（递归版本）" << endl;
	PostOrderTraverse_1(tree);
	cout << endl << endl;

	cout << "后序遍历（非递归版本）" << endl;
	PostOrderTraverse_2(tree);
	cout << endl << endl;

	Destroy(tree);


	file.open("T1.txt", ios::in);
	tree = CreateByPrio(file);
	file.close();
	cout << "层次遍历" << endl;
	LevelOrderTraverse(tree);
	cout << endl << endl;

	Destroy(tree);

	return 0;
}