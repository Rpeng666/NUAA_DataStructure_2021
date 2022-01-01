#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

struct Matrix {
	int mat[100][100];
	int row;
	int col;
};

struct Point {
	int data;
	int row;
	int col;
};

void Display(Matrix matrix) {
	int count = 0;

	for (int i = 0; i <= matrix.row - 1; i++) {
		for (int j = 0; j <= matrix.col - 1; j++) {
			cout << matrix.mat[i][j] << ' ';
		}
		cout << endl;
	}
}

void FindPoint(Matrix matrix) {
	Point* minPoint = new Point[matrix.col];
	Point* maxPoint = new Point[matrix.row];

	for (int i = 0; i < matrix.col; i++) {
		maxPoint[i].data = matrix.mat[0][i];
		maxPoint[i].row = 0;
		maxPoint[i].col = i;
	}

	for (int i = 0; i < matrix.row; i++) {
		minPoint[i].data = matrix.mat[i][0];
		minPoint[i].col = 0;
		minPoint[i].row = i;

		for (int j = 0; j < matrix.col; j++) {
			if (minPoint[i].data > matrix.mat[i][j]) {
				minPoint[i].data = matrix.mat[i][j];
				minPoint[i].col = j;
			}
			if (maxPoint[j].data < matrix.mat[i][j]) {
				maxPoint[j].data = matrix.mat[i][j];
				maxPoint[j].row = i;
			}
		}
	}

	for (int i = 0; i < matrix.row; i++) {
		if (maxPoint[i].col == minPoint[maxPoint[i].row].col) {
			cout << "�ҵ�һ�����㣺(" << maxPoint[i].row << ", " << maxPoint[i].col << ")" << endl;
		}
	}
}


int main() {
	fstream file("T2.txt", ios::in);
	int count = 0, temp;
	Matrix A;

	cout << "��ʼ��T2.txt��ȡԪ��" << endl << endl;
	file >> A.row >> A.col;

	for (int i = 0; i < A.row; i++) {
		for (int j = 0; j < A.col; j++) {
			file >> A.mat[i][j];
		}
	}
	file.close();

	cout << "���ݻ�ȡ���,�������£�" << endl;
	Display(A);


	cout << endl << "��ʼ�Ҿ�������㣺" << endl;
	FindPoint(A);

	return 0;
}