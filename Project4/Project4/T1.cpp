#include<iostream>
#include<fstream>
#include<algorithm>
#include<time.h>
#include<Windows.h>
using namespace std;


struct ThreeNum {
	int num;
	int x;
	int y;
};

struct Matrix {
	ThreeNum* data;
	int row;
	int col;
	int count;
};

void Display(Matrix matrix) {
	int count = 0;

	for (int i = 0; i <= matrix.row - 1; i++) {
		for (int j = 0; j <= matrix.col - 1; j++) {
			if (matrix.data[count].x ==  i && matrix.data[count].y == j) {
				cout << matrix.data[count].num << ' ';
				count++;
			}
			else cout << 0 << ' ';
		}
		cout << endl;
	}
}


void TransposeMatrix(Matrix &matrixA, Matrix &matrixB) {
	matrixB.row = matrixA.col;
	matrixB.col = matrixA.row;
	matrixB.count = matrixA.count;
	matrixB.data = new ThreeNum[matrixB.count];
	int count = 0;
	
	for (int k = 0; k < matrixA.col; k++) {
		for (int p = 0; p < matrixA.count; p++) {
			if (matrixA.data[p].y == k) {
				matrixB.data[count].num = matrixA.data[p].num;
				matrixB.data[count].x = matrixA.data[p].y;
				matrixB.data[count].y = matrixA.data[p].x;
				count++;
			}
		}
	}

}

void FastTransposeMatrix(Matrix &matrixA, Matrix &matrixC) {
	matrixC.row = matrixA.col;
	matrixC.col = matrixA.row;
	matrixC.count = matrixA.count;
	matrixC.data = new ThreeNum[matrixC.count];
	int rowNum[100], rowStart[100],q;

	memset(rowNum, 0, sizeof(rowNum));
	
	for (int p = 0; p < matrixA.count; p++) rowNum[matrixA.data[p].y]++;

	rowStart[0] = 0;

	for (int k = 1; k < matrixA.col; k++) {
		rowStart[k] = rowStart[k - 1] + rowNum[k - 1];
	}

	for (int p = 0; p < matrixA.count; p++) {
		q = rowStart[matrixA.data[p].y];
		matrixC.data[q].x = matrixA.data[p].y;
		matrixC.data[q].y = matrixA.data[p].x;
		matrixC.data[q].num = matrixA.data[p].num;
		rowStart[matrixA.data[p].y] ++;
	}
}


int main() {
	fstream file("T1.txt", ios::in);
	int count =0, temp;
	Matrix A,B,C;
	A.data = new ThreeNum[100];

	cout << "��ʼ��T1.txt��ȡԪ��" << endl << endl;
	file >> A.row >> A.col;

	for (int i = 0; i < A.row; i++) {
		for (int j = 0; j < A.col; j++) {
			file >> temp;

			if (temp != 0) {
				A.data[count].num = temp;
				A.data[count].x = i;
				A.data[count].y = j;
				count++;
			}
		}
	}
	A.count = count;
	file.close();

	cout << "���ݻ�ȡ���,�������£�" << endl;
	Display(A);

	time_t start, end;

	start = clock();
	cout << endl << "��ʼ�����������ת�÷�" << endl;
	TransposeMatrix(A, B);
	cout << "������ɣ��������£�" << endl;
	Display(B);
	end = clock();
	cout << "��ʱ" << start - end << endl;


	start = clock();
	cout << endl << "��ʼ���п���ת�÷�" << endl;
	FastTransposeMatrix(A, C);
	cout << "������ɣ��������£�" << endl;
	Display(C);
	end = clock();
	cout << "��ʱ" << start - end << endl;

	return 0;
}