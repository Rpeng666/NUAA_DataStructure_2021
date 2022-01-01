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

//����������ݹ�汾��
void PreOrderTraverse_1(BiNode* root) {
	if (root == NULL)return;
	cout << root->data << ' ';
	PreOrderTraverse_1(root->lChild);
	PreOrderTraverse_1(root->rChild);
}

//����������ǵݹ�汾��
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




//����������ݹ�汾��
void InOrderTraverse_1(BiNode* root) {
	if (root == NULL)return;
	InOrderTraverse_1(root->lChild);
	cout << root->data << ' ';
	InOrderTraverse_1(root->rChild);
}

//����������ǵݹ�汾��
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



//����������ݹ�汾��
void PostOrderTraverse_1(BiNode* root) {
	if (root == NULL)return;
	PostOrderTraverse_1(root->lChild);
	PostOrderTraverse_1(root->rChild);
	cout << root->data << ' ';
}

//����������ǵݹ�汾��
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



//��α���
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
	cout << "��ʼ��T1.txt�ж�ȡԪ�ؽ���" << endl;
	fstream file("T1.txt", ios::in);
	BiNode* tree = CreateByPrio(file);
	file.close();
	cout << "��ȡ���" << endl;

	cout << "����������ݹ�汾��" << endl;
	PreOrderTraverse_1(tree);
	cout << endl << endl;

	cout << "����������ǵݹ�汾��" << endl;
	PreOrderTraverse_2(tree);
	cout << endl << endl;

	Destroy(tree);


	file.open("T1.txt", ios::in);
	tree = CreateByPrio(file);
	file.close();

	cout << "����������ݹ�汾��" << endl;
	InOrderTraverse_1(tree);
	cout << endl << endl;

	cout << "����������ǵݹ�汾��" << endl;
	InOrderTraverse_2(tree);
	cout << endl << endl;

	Destroy(tree);


	file.open("T1.txt", ios::in);
	tree = CreateByPrio(file);
	file.close();

	cout << "����������ݹ�汾��" << endl;
	PostOrderTraverse_1(tree);
	cout << endl << endl;

	cout << "����������ǵݹ�汾��" << endl;
	PostOrderTraverse_2(tree);
	cout << endl << endl;

	Destroy(tree);


	file.open("T1.txt", ios::in);
	tree = CreateByPrio(file);
	file.close();
	cout << "��α���" << endl;
	LevelOrderTraverse(tree);
	cout << endl << endl;

	Destroy(tree);

	return 0;
}