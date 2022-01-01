#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
using namespace std;
typedef char elemType;


struct BiNode {
	elemType data;
	BiNode*lChild, *rChild;
};

class BinaryTree {
private:
	BiNode* tree;

public:
	//����һ�ÿն�����
	void InitBiTree() {
		tree = NULL;
	}

	//���ٶ����������ú������
	void DestroyBiTree(BiNode* root) {
		if (root == NULL)return;
		DestroyBiTree(root->lChild);
		DestroyBiTree(root->rChild);
		delete root;
	}

	
	BiNode* CreateByPrio(fstream &file){
		elemType temp;
		file >> temp;
		if (temp == '#')return NULL;
		BiNode* newNode = new BiNode;

		newNode->data = temp;
		newNode->lChild = CreateByPrio(file);
		newNode->rChild = CreateByPrio(file);

		return newNode;
	}


	//���������,����������򴴽�
	void CreateBiTree() {
		fstream file("T1.txt", ios::in);
		tree = CreateByPrio(file);
		file.close();
	}

	//��ն�����
	void ClearBiTree(BiNode* root) {
		if (root == NULL)return;
		root->data = ' ';
		PreOrderTraverse(root->lChild);
		PreOrderTraverse(root->rChild);
	}

	//�ж϶������Ƿ�Ϊ��
	bool BiTreeEmpty() {
		if (tree == NULL)return true;
		return false;
	}

	//���ض����������
	int BiTreeDepth(BiNode * root) {
		if (root == NULL) return 0;
		return max(BiTreeDepth(root->lChild), BiTreeDepth(root->rChild))+1;
	}

	//���ض��������ڵ��ֵ
	elemType Root() {
		if (tree != NULL) {
			return tree->data;
		}
	}

	//����ĳ��ָ��ָ��Ľڵ��ֵe
	elemType Value(BiNode* p) {
		if (p != NULL)
			return p->data;
		else
			cout << "����" << endl;
	}

	//����˫��ָ��(��������������)
	BiNode* Parent(BiNode* p, BiNode* root) {
		if (root == NULL) return NULL;
		if (p == root->lChild || p == root->rChild)return root;
		BiNode* p1 = Parent(p, root->lChild);
		BiNode* p2 = Parent(p, root->rChild);

		if (p1 != NULL)return p1;
		if (p2 != NULL) return p2;
		return NULL;
	}

	//����leftChild
	BiNode* LeftChild(BiNode* p) {
		return p->lChild == NULL ? NULL : p->lChild;
	}

	//����rightChild
	BiNode* RightChild(BiNode* p) {
		return p->rChild == NULL ? NULL : p->rChild;
	}
	//����LeftBrother
	BiNode* LeftBrother(BiNode* p) {
		BiNode*parent = Parent(p, tree);
		if (parent->lChild == p || parent->lChild == NULL) return NULL;
		return parent->lChild;
	}

	//����rightBrother
	BiNode* RightBrother(BiNode* p) {
		BiNode*parent = Parent(p, tree);
		if (parent->rChild == p || parent->rChild == NULL) return NULL;
		return parent->rChild;
	}


	//�������
	void PreOrderTraverse(BiNode* root) {
		if (root == NULL)return;
		cout << root->data << ' ';
		PreOrderTraverse(root->lChild);
		PreOrderTraverse(root->rChild);
	}

	//�������
	void InOrderTraverse(BiNode* root) {
		if (root == NULL)return;
		InOrderTraverse(root->lChild);
		cout << root->data << ' ';
		InOrderTraverse(root->rChild);
	}

	//�������
	void PostOrderTraverse(BiNode* root) {
		if (root == NULL)return;
		PostOrderTraverse(root->lChild);
		PostOrderTraverse(root->rChild);
		cout << root->data << ' ';
	}
	//��α���
	void LevelOrderTraverse() {
		queue<BiNode*> QB;
		int num = 1,temp = 0;
		QB.emplace(tree);

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


	//�ӹ��Ͳ���
	void Assign(BiNode* p, elemType value) {
		if (p != NULL) {
			p->data = value;
		}
	}

	void InsertChild(BiNode* p, int LR, BiNode* c) {
		if (c == NULL || c->rChild != NULL) {
			cout << "��������" << endl;
			return;
		}

		if (p == NULL) {
			cout << "�ڵ㲻���ڣ�" << endl;
			return;
		}

		if (LR == 0) {
			if (p->lChild != NULL)c->rChild = p->lChild;
			p->lChild = c;
		}
		else if (LR == 1) {
			if (p->rChild != NULL)c->rChild = p->rChild;
			p->rChild = c;
		}
	}
	
	void DeleteChild(BiNode* p, int LR) {
		if (p == NULL) {
			cout << "�ڵ㲻���ڣ�" << endl;
			return;
		}
		if (LR == 0) {
			if (p->lChild == NULL) {
				cout << "������������" << endl;
				return;
			}
			DestroyBiTree(p->lChild);
			p->lChild = NULL;
		}

		if (LR == 1) {
			if (p->rChild == NULL) {
				cout << "������������" << endl;
				return;
			}
			DestroyBiTree(p->rChild);
			p->rChild = NULL;
		}
	}


	BiNode* GetRoot() {
		return tree;
	}


	BiNode* GetPointer() {
		return tree->lChild->rChild;
	}

};




int main() {
	BinaryTree biTree;
	cout << "��ʼ����InitBiTree()" << endl;
	biTree.InitBiTree();
	cout << "�յĶ���������ɹ�" << endl << endl;


	cout << "��ʼ��T1.txt�ж�ȡ���ݣ�ͨ������������������" << endl;
	biTree.CreateBiTree();
	cout << "����ɹ�" << endl << endl;

	
	cout << "��ʼ�����������" << endl;
	biTree.PreOrderTraverse(biTree.GetRoot());
	cout << endl << endl;


	cout << "��ʼ�����������" << endl;
	biTree.InOrderTraverse(biTree.GetRoot());
	cout << endl << endl;


	cout << "��ʼ���Ժ������" << endl;
	biTree.PostOrderTraverse(biTree.GetRoot());
	cout << endl << endl;


	cout << "��ʼ���Բ�α���" << endl;
	biTree.LevelOrderTraverse();
	cout << endl << endl;


	cout << "������ȣ�" << endl;
	cout << biTree.BiTreeDepth(biTree.GetRoot()) << endl << endl;

	cout << "���ĸ��ڵ��ֵ��" << endl;
	cout << biTree.Root() << endl << endl;

	
	BiNode * p = biTree.GetPointer();

	cout << "��ʼ���Բ��ҽڵ�E��ֵ" << endl;
	cout << biTree.Value(p) << endl << endl;

	cout << "��ʼ���Բ��ҽڵ�E��˫��" << endl;
	cout << biTree.Parent(p, biTree.GetRoot())->data << endl << endl;


	cout << "��ʼ���Բ��ҽڵ�E����child" << endl;
	if (biTree.LeftChild(p) != NULL)cout << biTree.LeftChild(p)->data << endl << endl;
	else cout << "��" << endl << endl;

	cout << "��ʼ���Բ��ҽڵ�E����child" << endl;
	if (biTree.RightChild(p) != NULL)cout << biTree.RightChild(p)->data << endl << endl;
	else cout << "��" << endl << endl;

	cout << "��ʼ���Բ��ҽڵ�E����brother" << endl;
	if (biTree.LeftBrother(p) != NULL)cout << biTree.LeftBrother(p)->data << endl << endl;
	else cout << "��" << endl << endl;

	cout << "��ʼ���Բ��ҽڵ�E����brother" << endl;
	if (biTree.RightBrother(p) != NULL)cout << biTree.RightBrother(p)->data << endl << endl;
	else cout << "��" << endl << endl;


	BiNode* temp = new BiNode;
	temp->data = 'K';
	temp->rChild = NULL;
	temp->lChild = new BiNode;
	temp->lChild->data = 'O';
	temp->lChild->rChild = NULL;
	temp->lChild->lChild = new BiNode;
	temp->lChild->lChild->data = 'P';
	temp->lChild->lChild->lChild = temp->lChild->lChild->rChild = NULL;


	cout << "��ʼ���Ը��Ľڵ��ֵ" << endl;
	biTree.Assign(p, 'Z');
	cout << "������ϣ���ʼ����" << endl;
	biTree.PreOrderTraverse(biTree.GetRoot());
	cout << endl << endl;

	cout << "��ʼ�����������" << endl;
	biTree.InsertChild(p, 0, temp);
	cout << endl;
	cout << "������ϣ���ʼ�������" << endl;
	biTree.PreOrderTraverse(biTree.GetRoot());
	cout << endl << endl;


	cout << "��ʼ����ɾ������" << endl;
	biTree.DeleteChild(p, 0);
	cout << endl;
	cout << "������ϣ���ʼ�������" << endl;
	biTree.PreOrderTraverse(biTree.GetRoot());
	cout << endl << endl;
}