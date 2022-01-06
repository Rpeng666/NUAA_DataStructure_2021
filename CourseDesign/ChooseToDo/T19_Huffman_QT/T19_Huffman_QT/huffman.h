#pragma once
#ifndef HUFFMAN_H
#include<string>
#include<map>
#include<vector>
using namespace std;
//Huffman���Ľڵ�
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
	//��������ÿ���ַ����ֵĴ���
	bool statics(string filename);

	//����Huffman��
	void huffman_First();
	Node* huffman(vector<Node*>& nodelist);

	//��Huffman���ı������д��Huffman.txt
	void writeHuffmanTxt(Node* root, vector<int>& huffmancode, fstream& file);
	void writeHuffmanTxtFirst();

	//�������Ķ���������д��code.txt
	void writeCodeTxt();

	//�������Ķ���������д��code.dat
	void writeCodeDat();

	//�������Ķ������������½����0/1��txt�ĵ�
	void recodeFromDat(string filename);

	//��������0/1�ĵ���ͨ��Huffman��������ַ���д��recode.txt
	void writeRecodeTxt();

	//����Huffman������ֹ�ڴ�й©
	void destoryHuffman(Node* root); 

	~Huffman() {
		destoryHuffman(root);
	}

};

#endif // !HUFFMAN_H
