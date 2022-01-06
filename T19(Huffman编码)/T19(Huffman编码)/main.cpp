#include<iostream>
#include<map>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<math.h>

using namespace std;

//Huffman���Ľڵ�
struct Node {
	char ch;
	int num;
	Node* left;
	Node* right;
};


//********************************************************************
//��������ÿ���ַ����ֵĴ���
void statics(map<char,int> &sta) {
	fstream file("source.txt", ios::in);

	if (file.fail()) {
		cout << "source.txt��ʧ��" << endl;
		return;
	}

	char ch = '\0';

	while (!file.eof()) {
		file.get(ch);

		if (file.fail())break;

		if (sta.find(ch) == sta.end()) {
			sta[ch] = 1;
		}
		else {
			sta[ch]++;
		}
	}

	file.close();
}

//********************************************************************
//�����Ƚϲ�ͬnode�Ĵ�С����algorithm���sort����ʹ��
bool cmp(Node* a, Node* b) {
	return a->num > b->num;
}

//********************************************************************
//����Huffman��
Node* huffman(vector<Node*> &nodelist) {
	if (nodelist.size() == 1)return nodelist[0];

	if (nodelist.size() == 0) cout << "���ַ�������" << endl;

	sort(nodelist.begin(), nodelist.end(), cmp);
	
	Node* temp = new Node;
	temp->ch = ' ';
	temp->left = nodelist[nodelist.size() - 1];
	temp->right = nodelist[nodelist.size() - 2];
	temp->num = temp->left->num + temp->right->num;
	nodelist.pop_back();
	nodelist.pop_back();
	nodelist.emplace_back(temp);
	
	return huffman(nodelist);
}

//********************************************************************
//��Huffman���ı������д��Huffman.txt
void writeHuffmanTxt(Node*root, vector<int> &huffmancode,fstream & file) {
	
	if (root->left == NULL && root->right == NULL) {

		file << root->ch << ' ' << root->num << ' ';

		for (int i = 0; i < huffmancode.size(); i++) file << huffmancode[i];

		file << endl;
		return;
	}

	huffmancode.emplace_back(0);
	writeHuffmanTxt(root->left, huffmancode, file);
	huffmancode.pop_back();

	huffmancode.emplace_back(1);
	writeHuffmanTxt(root->right, huffmancode, file);
	huffmancode.pop_back();
}


//********************************************************************
//�������Ķ���������д��code.txt
void writeCodeTxt() {
	map<char, string> codeInfo;
	fstream file("Huffman.txt", ios::in);

	if (file.fail()) {
		cout << "Huffman.txt��ʧ��" << endl;
		return;
	}

	char ch, ch1;
	int temp;
	string code;

	while (!file.eof()) {
		file.get(ch);
		file >> temp;
		file.get(ch1);
		getline(file, code);

		codeInfo[ch] = code;

		if (file.fail())break;
	}

	file.close();

	file.open("code.txt", ios::out);

	if (file.fail()) {
		cout << "code.dat��ʧ��" << endl;
		return;
	}

	fstream file1("source.txt", ios::in);

	if (file.fail()) {
		cout << "source.txt��ʧ��" << endl;
		return;
	}

	while (!file1.eof()) {
		file1.get(ch);

		if (file1.fail())break;

		code = codeInfo[ch];
		for (int i = 0; i < code.size(); i++) {
			if (code[i] == '0') file << 0;
			else file << 1;
		}
	}

	file.close();
	file1.close();
}


//********************************************************************
//�������Ķ���������д��code.dat
void writeCodeDat() {
	fstream file("code.txt", ios::in);
	fstream file2("code.dat", ios::out|ios::binary);
	
	unsigned char ch = '\0';
	char temp[8]{};

	while (!file.eof()) {
		for (int i = 7; i >= 0; i--) {
			file.get(temp[i]);

			if (file.fail()) {
				ch = '\0';
				for (int j = i + 1; j < 8; j++) {
					if (temp[j] == '1') ch += pow(2, j - i - 1);
				}
				break;
			}
			if (temp[i] == '1') ch += pow(2,i);
		}

		file2.write((char*)&ch, sizeof(ch));

		if (file.fail())break;
		ch = '\0';
	}

	file.close();
	file2.close();
}


//********************************************************************
//�������Ķ������������½����0/1��txt�ĵ�
void recodeFromDat() {
	fstream file("code.dat", ios::in | ios::binary);
	fstream fout("recodeFromDat.txt", ios::out);

	stack<int> binary_num;

	unsigned char ch = '\0';
	int ch_ascii = 0;
	
	file.read((char*)&ch, sizeof(ch));

	while (!file.eof()) {

		while (!binary_num.empty()) binary_num.pop();    // ���洢0/1��ջ���

		ch_ascii = ch;    //�ַ���ASCII��

		while (ch_ascii != 0) {
			binary_num.emplace(ch_ascii % 2);
			ch_ascii /= 2;
		}

		file.read((char*)&ch, sizeof(ch));

		if (file.fail()) {
			while (!binary_num.empty()) {   //ĩβ�ַ����ò�0
				fout << binary_num.top();
				binary_num.pop();
			}

			break;
		}

		while (binary_num.size() != 8)binary_num.emplace(0);  //����ĩβ���ַ�����ô����8λ�Ͳ�0

		while (!binary_num.empty()) {
			fout << binary_num.top();
			binary_num.pop();
		}
	}

	file.close();
	fout.close();
}


//********************************************************************
//��������0/1�ĵ���ͨ��Huffman��������ַ���д��recode.txt
void writeRecodeTxt(Node* root) {
	fstream file1("recodeFromDat.txt", ios::in);
	fstream file2("recode.txt", ios::out);

	Node* temp = root;

	char num;

	while (!file1.eof()) {
		file1.get(num);

		if (temp->left ==NULL && temp->right == NULL) {
			file2 << temp->ch;
			temp = root;
		}		

		if (file1.fail())break;

		if (num == '0')temp = temp->left;
		else temp = temp->right;
	}

	file1.close();
	file2.close();
}


//********************************************************************
//����Huffman������ֹ�ڴ�й©
void destoryHuffman(Node* root) {
	if (root == NULL)return;

	destoryHuffman(root->left);
	destoryHuffman(root->right);
	delete root;
}


//********************************************************************
//������
int main() {
	map<char, int >sta;   //�洢�ַ���Ƶ��
	statics(sta);

	vector<Node*> nodelist;   //�洢Huffman���Ľڵ�
	Node* temp;

	for (auto i = sta.begin(); i != sta.end(); i++) {
		temp = new Node;
		temp->ch = i->first;
		temp->num = i->second;
		temp->left = temp->right = NULL;

		nodelist.emplace_back(temp);
	}

	Node* root = huffman(nodelist);    //����Huffman��

	fstream file("Huffman.txt", ios::out); 

	if (file.fail()) {
		cout << "Huffman.txt��ʧ��" << endl;
		return 0;
	}

	vector<int> huffmancode;

	writeHuffmanTxt(root, huffmancode, file);    //д��ÿ���ַ��ı�����Ϣ

	file.close();

	writeCodeTxt();    //д��code.txt,����һ����0/1���м��ļ�

	writeCodeDat();    //д�����������

	recodeFromDat();   //д�������0/1�ַ���recodeFromDat.txt

	writeRecodeTxt(root);

	destoryHuffman(root);

	return 0;
}