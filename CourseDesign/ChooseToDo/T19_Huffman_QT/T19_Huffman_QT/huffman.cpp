#include"huffman.h"
#include<iostream>
#include<fstream>
#include<algorithm>
#include<stack>
#include<math.h>

using namespace std;


//********************************************************************
//用来计算每个字符出现的次数
bool Huffman::statics(string filename) {
	this->sourcefile = filename;
	sta.clear();

	fstream file(filename.c_str(), ios::in);

	if (file.fail()) {
		return false;
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
	return true;
}

//********************************************************************
//用来比较不同node的大小，供algorithm里的sort函数使用
bool cmp(Node* a, Node* b) {
	return a->num > b->num;
}

//********************************************************************
//建立Huffman树
Node* Huffman::huffman(vector<Node*> &nodelist) {
	if (nodelist.size() == 1)return nodelist[0];

	if (nodelist.size() == 0) cout << "无字符，错误" << endl;

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

void Huffman::huffman_First() {
	vector<Node*> nodelist;   //存储Huffman树的节点
	Node* temp;

	for (auto i = sta.begin(); i != sta.end(); i++) {
		temp = new Node;
		temp->ch = i->first;
		temp->num = i->second;
		temp->left = temp->right = NULL;

		nodelist.emplace_back(temp);
	}

	this->root = huffman(nodelist);    //建立Huffman树
}


//********************************************************************
//将Huffman树的编码情况写入Huffman.txt
void Huffman::writeHuffmanTxt(Node*root, vector<int> &huffmancode,fstream & file) {
	
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

void Huffman::writeHuffmanTxtFirst() {
	fstream file("Huffman.txt", ios::out);

	if (file.fail()) {
		cout << "Huffman.txt打开失败" << endl;
		return;
	}

	vector<int> huffmancode;

	writeHuffmanTxt(root, huffmancode, file);    //写入每个字符的编码信息

	file.close();
}

//********************************************************************
//将编码后的二进制文章写入code.txt
void Huffman::writeCodeTxt() {
	map<char, string> codeInfo;
	fstream file("Huffman.txt", ios::in);

	if (file.fail()) {
		cout << "Huffman.txt打开失败" << endl;
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
		cout << "code.dat打开失败" << endl;
		return;
	}

	fstream file1("source.txt", ios::in);

	if (file.fail()) {
		cout << "source.txt打开失败" << endl;
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
//将编码后的二进制文章写入code.dat
void Huffman::writeCodeDat() {
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
//将编码后的二进制文章重新解码成0/1的txt文档
void Huffman::recodeFromDat(string filename) {
	fstream file(filename.c_str(), ios::in | ios::binary);
	fstream fout("recodeFromDat.txt", ios::out);

	stack<int> binary_num;

	unsigned char ch = '\0';
	int ch_ascii = 0;
	
	file.read((char*)&ch, sizeof(ch));

	while (!file.eof()) {

		while (!binary_num.empty()) binary_num.pop();    // 将存储0/1的栈清空

		ch_ascii = ch;    //字符的ASCII码

		while (ch_ascii != 0) {
			binary_num.emplace(ch_ascii % 2);
			ch_ascii /= 2;
		}

		file.read((char*)&ch, sizeof(ch));

		if (file.fail()) {
			while (!binary_num.empty()) {   //末尾字符不用补0
				fout << binary_num.top();
				binary_num.pop();
			}

			break;
		}

		while (binary_num.size() != 8)binary_num.emplace(0);  //不是末尾的字符，那么不足8位就补0

		while (!binary_num.empty()) {
			fout << binary_num.top();
			binary_num.pop();
		}
	}

	file.close();
	fout.close();
}


//********************************************************************
//将解码后的0/1文档再通过Huffman树编码成字符，写入recode.txt
void Huffman::writeRecodeTxt() {
	fstream file1("recodeFromDat.txt", ios::in);
	fstream file2("recode.txt", ios::out);

	Node* temp = this->root;

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
//销毁Huffman树，防止内存泄漏
void Huffman::destoryHuffman(Node* root) {
	if (root == NULL)return;

	destoryHuffman(root->left);
	destoryHuffman(root->right);
	delete root;
}
