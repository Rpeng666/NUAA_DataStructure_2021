#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

struct BiNode {
	int data;
	BiNode* lChild = NULL;
	BiNode* rChild = NULL;
};

bool cmp(BiNode* a, BiNode* b) {
	return a->data > b->data;
}

BiNode* Huffman(vector<BiNode*> L) {
	
	BiNode* temp = new BiNode;
	sort(L.begin(), L.end(), cmp);
	
	temp->data = L[L.size() -1]->data + L[L.size() - 2]->data;
	temp->lChild = L[L.size() - 1];
	temp->rChild = L[L.size() - 2];

	if (L.size() == 2) {
		return temp;
	}

	L.pop_back();
	L.pop_back();
	L.emplace_back(temp);

	return Huffman(L);
}

void deleteTree(BiNode* root) {
	if (root == NULL)return;
	deleteTree(root->lChild);
	deleteTree(root->rChild);

	cout << "���ٽڵ�" << root->data << endl;
	delete root;
}

void travelByPrio(BiNode* root) {
	if (root == NULL) return;
	cout << root->data << ' ';
	travelByPrio(root->lChild);
	travelByPrio(root->rChild);
}


int main() {
	int n, temp;
	BiNode* bn,*result;
	vector<BiNode*>vec;

	cout << "��T2.txt�ж�ȡԪ�ع���Huffman��" << endl;
	fstream file("T2.txt", ios::in);

	file >> n;
	for (int i = 0; i < n; i++) {
		file >> temp;

		bn = new BiNode;
		bn->data = temp;
		bn->lChild = bn->rChild = NULL;

		vec.emplace_back(bn);
	}
	
	result = Huffman(vec);
	cout << "�������" << endl << endl;

	cout << "��ʼ�������Huffman��:" << endl;
	travelByPrio(result);
	cout << endl << endl;

	cout << "��ʼ����Huffman��" << endl;
	deleteTree(result);

	cout << "�������" << endl;
	/*int n, temp,min1,min2;
	vector<int> vec;

	fstream file("T2.txt", ios::in);
	
	file >> n;
	for (int i = 0; i < n; i++) {
		file >> temp;
		vec.emplace_back(temp);
	}
	file.close();

	while (vec.size() >= 2) {
		sort(vec.begin(), vec.end(), cmp);

		min1 = vec[vec.size() - 1];
		min2 = vec[vec.size() - 2];
		
		BiNode* node1 = new BiNode;
		BiNode* node2 = new BiNode;
		BiNode* node3 = new BiNode;

		node1->data = min1;
		node2->data = min2;
		node1->lChild = node1->rChild = node2->lChild = node2->rChild = NULL;
		node3->data = min1 + min2;
		node3->lChild = node1;
		node3->rChild = node2;

		vec.pop_back();
		vec.pop_back();
		vec.emplace_back(min1 + min2);
	}*/
	

}