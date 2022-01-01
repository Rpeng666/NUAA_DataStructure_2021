#include<iostream>
#include<random>
using namespace std;
#define N 10


struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
};


int * CreateRandomInt(int* rand_int, int n) {
	default_random_engine e;

	for (int i = 0; i < n; i++) {
		rand_int[i] = e() % 100;
	}
	return rand_int;
}


void display(int *rand_int) {
	for (int i = 0; i < N; i++) {
		cout << rand_int[i] << ' ';
		if (i % 20 == 0 && i != 0) {
			cout << endl;
		}
	}
}


BSTNode* BSTsearch(BSTNode*root, int target) {
	if (root == NULL)return NULL;
	if (root->data == target)return root;
	else if (root->data > target) return BSTsearch(root->left, target);
	else return BSTsearch(root->right, target);
}


BSTNode* BSTinsert(BSTNode*root, int data) {
	if (root == NULL) {
		root = new BSTNode;
		root->data = data;
		root->left = root->right = NULL;
		cout << "Ԫ�ء�" << data << "������ɹ�" << endl;
		return root;
	}
	else if (root->data == data) {
		cout << "Ԫ�ء�"<<data<<"���Ѿ����ڣ�����洢" << endl;
	}

	else if (root->data > data) {
		if (root->left != NULL) {
			BSTinsert(root->left, data);
		}
		else {
			root->left = new BSTNode;
			root->left->data = data;
			root->left->left = root->left->right = NULL;
			cout << "Ԫ�ء�" << data << "������ɹ�" << endl;
		}
	}
	else {
		if (root->right != NULL) {
			BSTinsert(root->right, data);
		}
		else {
			root->right = new BSTNode;
			root->right->data = data;
			root->right->left = root->right->right = NULL;
			cout << "Ԫ�ء�" << data << "������ɹ�" << endl;
		}
	}
}


BSTNode* CreateBST(int *List) {
	BSTNode* root = NULL;

	for (int i = 0; i < N; i++) {
		if(i == 0)root = BSTinsert(root, List[i]);
		else BSTinsert(root, List[i]);
		
	}
	return root;
}


void TravelByInorder(BSTNode* root) {
	if (root == NULL) return;
	TravelByInorder(root->left);
	cout << root->data << ' ';
	TravelByInorder(root->right);
}

void destroyTree(BSTNode* root) {
	if (root == NULL) return;
	destroyTree(root->left);
	destroyTree(root->right);
	delete root;
}

void deleteNode(BSTNode* root, BSTNode* parent, int data) {
	if (root == NULL) return;

	if (root->data == data) {
		if (!root->left && !root->right) {
			if (!parent) {
				if (parent->left == root)parent->left = NULL;
				else parent->right = NULL;
				delete root;
			}
			else {
				delete root;
			}
		}

		else if (root->left && root->right) {

			BSTNode* temp = root->right;
			BSTNode* par = root->right;
			while (temp->left) {
				par = temp;
				temp = temp->left;
			}
			root->data = temp->data;
			if (par != root->right)par->left = temp->right;
			else root->right = temp->right;
			delete temp;
			
		}

		else {
			if (root->left) {
				if (parent->left == root)parent->left = root->left;
				else parent->right = root->left;

				delete root;
			}
			else {
				if (parent->left == root)parent->left = root->right;
				else parent->right = root->right;

				delete root;
			}
		}
	}

	else if (data > root->data) deleteNode(root->right, root, data);
	else deleteNode(root->left, root, data);
}


int main() {

	int* rand_int = new int[N];

	cout << "�������" << N << "����0," << N << "���ڵ�����" << endl;
	rand_int = CreateRandomInt(rand_int, N);

	cout << endl << "չʾ��" << N << "��������֣�" << endl;
	display(rand_int);
	
	cout << endl << endl << "��ʼ��������������" << endl;
	BSTNode* root = CreateBST(rand_int);
	cout << "�����ɹ�" << endl << endl;

	cout << "�������: ";
	TravelByInorder(root);
	cout << endl << endl;

	
	cout << "ɾ��Ԫ�ء�34��" << endl;
	deleteNode(root, NULL, 34);
	cout << "���������";
	TravelByInorder(root);
	cout << endl << endl;


	cout << "ɾ��Ԫ�ء�85��" << endl;
	deleteNode(root, NULL, 85);
	cout << "���������";
	TravelByInorder(root);
	cout << endl << endl;


	cout << "���ٶ���������" << endl;
	destroyTree(root);
	cout << "���ٳɹ���" << endl;

	return 0;
}
