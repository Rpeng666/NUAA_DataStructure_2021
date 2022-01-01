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

//������ֻҪ������ڵ�Ϊ�յĽڵ㣬��ô������ԭ����Ҷ�ڵ�
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

	cout << "��ʼ��T3.txt�ж�ȡԪ�ع��������" << endl << endl;
	BiNode* root = CreateByPrio(file);
	file.close();

	cout << "��ʼѰ�����е�Ҷ�ڵ�: " << endl;
	getAllLeaf(root);
	cout << endl << "�������" << endl << endl;

	cout << "��ʼ������" << endl;
	destroyTree(root);
	cout << "������ϣ�" << endl;

	return 0;
}