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
	//构造一棵空二叉树
	void InitBiTree() {
		tree = NULL;
	}

	//销毁二叉树，采用后序遍历
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


	//创造二叉树,这里采用先序创建
	void CreateBiTree() {
		fstream file("T1.txt", ios::in);
		tree = CreateByPrio(file);
		file.close();
	}

	//清空二叉树
	void ClearBiTree(BiNode* root) {
		if (root == NULL)return;
		root->data = ' ';
		PreOrderTraverse(root->lChild);
		PreOrderTraverse(root->rChild);
	}

	//判断二叉树是否为空
	bool BiTreeEmpty() {
		if (tree == NULL)return true;
		return false;
	}

	//返回二叉树的深度
	int BiTreeDepth(BiNode * root) {
		if (root == NULL) return 0;
		return max(BiTreeDepth(root->lChild), BiTreeDepth(root->rChild))+1;
	}

	//返回二叉树根节点的值
	elemType Root() {
		if (tree != NULL) {
			return tree->data;
		}
	}

	//返回某个指针指向的节点的值e
	elemType Value(BiNode* p) {
		if (p != NULL)
			return p->data;
		else
			cout << "错误！" << endl;
	}

	//返回双亲指针(这里采用先序遍历)
	BiNode* Parent(BiNode* p, BiNode* root) {
		if (root == NULL) return NULL;
		if (p == root->lChild || p == root->rChild)return root;
		BiNode* p1 = Parent(p, root->lChild);
		BiNode* p2 = Parent(p, root->rChild);

		if (p1 != NULL)return p1;
		if (p2 != NULL) return p2;
		return NULL;
	}

	//返回leftChild
	BiNode* LeftChild(BiNode* p) {
		return p->lChild == NULL ? NULL : p->lChild;
	}

	//返回rightChild
	BiNode* RightChild(BiNode* p) {
		return p->rChild == NULL ? NULL : p->rChild;
	}
	//返回LeftBrother
	BiNode* LeftBrother(BiNode* p) {
		BiNode*parent = Parent(p, tree);
		if (parent->lChild == p || parent->lChild == NULL) return NULL;
		return parent->lChild;
	}

	//返回rightBrother
	BiNode* RightBrother(BiNode* p) {
		BiNode*parent = Parent(p, tree);
		if (parent->rChild == p || parent->rChild == NULL) return NULL;
		return parent->rChild;
	}


	//先序遍历
	void PreOrderTraverse(BiNode* root) {
		if (root == NULL)return;
		cout << root->data << ' ';
		PreOrderTraverse(root->lChild);
		PreOrderTraverse(root->rChild);
	}

	//中序遍历
	void InOrderTraverse(BiNode* root) {
		if (root == NULL)return;
		InOrderTraverse(root->lChild);
		cout << root->data << ' ';
		InOrderTraverse(root->rChild);
	}

	//后序遍历
	void PostOrderTraverse(BiNode* root) {
		if (root == NULL)return;
		PostOrderTraverse(root->lChild);
		PostOrderTraverse(root->rChild);
		cout << root->data << ' ';
	}
	//层次遍历
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


	//加工型操作
	void Assign(BiNode* p, elemType value) {
		if (p != NULL) {
			p->data = value;
		}
	}

	void InsertChild(BiNode* p, int LR, BiNode* c) {
		if (c == NULL || c->rChild != NULL) {
			cout << "子树错误！" << endl;
			return;
		}

		if (p == NULL) {
			cout << "节点不存在！" << endl;
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
			cout << "节点不存在！" << endl;
			return;
		}
		if (LR == 0) {
			if (p->lChild == NULL) {
				cout << "左子树不存在" << endl;
				return;
			}
			DestroyBiTree(p->lChild);
			p->lChild = NULL;
		}

		if (LR == 1) {
			if (p->rChild == NULL) {
				cout << "左子树不存在" << endl;
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
	cout << "开始测试InitBiTree()" << endl;
	biTree.InitBiTree();
	cout << "空的二叉树构造成功" << endl << endl;


	cout << "开始从T1.txt中读取数据，通过先序遍历构造二叉树" << endl;
	biTree.CreateBiTree();
	cout << "构造成功" << endl << endl;

	
	cout << "开始测试先序遍历" << endl;
	biTree.PreOrderTraverse(biTree.GetRoot());
	cout << endl << endl;


	cout << "开始测试中序遍历" << endl;
	biTree.InOrderTraverse(biTree.GetRoot());
	cout << endl << endl;


	cout << "开始测试后序遍历" << endl;
	biTree.PostOrderTraverse(biTree.GetRoot());
	cout << endl << endl;


	cout << "开始测试层次遍历" << endl;
	biTree.LevelOrderTraverse();
	cout << endl << endl;


	cout << "树的深度：" << endl;
	cout << biTree.BiTreeDepth(biTree.GetRoot()) << endl << endl;

	cout << "树的根节点的值：" << endl;
	cout << biTree.Root() << endl << endl;

	
	BiNode * p = biTree.GetPointer();

	cout << "开始测试查找节点E的值" << endl;
	cout << biTree.Value(p) << endl << endl;

	cout << "开始测试查找节点E的双亲" << endl;
	cout << biTree.Parent(p, biTree.GetRoot())->data << endl << endl;


	cout << "开始测试查找节点E的左child" << endl;
	if (biTree.LeftChild(p) != NULL)cout << biTree.LeftChild(p)->data << endl << endl;
	else cout << "无" << endl << endl;

	cout << "开始测试查找节点E的右child" << endl;
	if (biTree.RightChild(p) != NULL)cout << biTree.RightChild(p)->data << endl << endl;
	else cout << "无" << endl << endl;

	cout << "开始测试查找节点E的左brother" << endl;
	if (biTree.LeftBrother(p) != NULL)cout << biTree.LeftBrother(p)->data << endl << endl;
	else cout << "无" << endl << endl;

	cout << "开始测试查找节点E的右brother" << endl;
	if (biTree.RightBrother(p) != NULL)cout << biTree.RightBrother(p)->data << endl << endl;
	else cout << "无" << endl << endl;


	BiNode* temp = new BiNode;
	temp->data = 'K';
	temp->rChild = NULL;
	temp->lChild = new BiNode;
	temp->lChild->data = 'O';
	temp->lChild->rChild = NULL;
	temp->lChild->lChild = new BiNode;
	temp->lChild->lChild->data = 'P';
	temp->lChild->lChild->lChild = temp->lChild->lChild->rChild = NULL;


	cout << "开始测试更改节点的值" << endl;
	biTree.Assign(p, 'Z');
	cout << "更改完毕，开始遍历" << endl;
	biTree.PreOrderTraverse(biTree.GetRoot());
	cout << endl << endl;

	cout << "开始测试添加子树" << endl;
	biTree.InsertChild(p, 0, temp);
	cout << endl;
	cout << "更改完毕，开始先序遍历" << endl;
	biTree.PreOrderTraverse(biTree.GetRoot());
	cout << endl << endl;


	cout << "开始测试删除子树" << endl;
	biTree.DeleteChild(p, 0);
	cout << endl;
	cout << "更改完毕，开始先序遍历" << endl;
	biTree.PreOrderTraverse(biTree.GetRoot());
	cout << endl << endl;
}