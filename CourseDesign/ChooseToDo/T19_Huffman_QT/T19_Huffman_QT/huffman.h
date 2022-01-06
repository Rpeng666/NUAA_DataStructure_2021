#pragma once
#ifndef HUFFMAN_H
#include<string>
#include<map>
#include<vector>
using namespace std;
//Huffman树的节点
struct Node {
	char ch;
	int num;
	Node* left;
	Node* right;
};


class Huffman {
private:
	Node* root;
	map<char, int> sta;
	string sourcefile;

public:
	//用来计算每个字符出现的次数
	bool statics(string filename);

	//建立Huffman树
	void huffman_First();
	Node* huffman(vector<Node*>& nodelist);

	//将Huffman树的编码情况写入Huffman.txt
	void writeHuffmanTxt(Node* root, vector<int>& huffmancode, fstream& file);
	void writeHuffmanTxtFirst();

	//将编码后的二进制文章写入code.txt
	void writeCodeTxt();

	//将编码后的二进制文章写入code.dat
	void writeCodeDat();

	//将编码后的二进制文章重新解码成0/1的txt文档
	void recodeFromDat(string filename);

	//将解码后的0/1文档再通过Huffman树编码成字符，写入recode.txt
	void writeRecodeTxt();

	//销毁Huffman树，防止内存泄漏
	void destoryHuffman(Node* root); 

	~Huffman() {
		destoryHuffman(root);
	}

};

#endif // !HUFFMAN_H
