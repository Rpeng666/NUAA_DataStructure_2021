#include<iostream>

using namespace std;



int main() {
	int n,temp; 
	int arr[20][5];  //�ö�ά����ģ�⳵�� 
	int index[20] = { 0 };//��¼ÿ���Ѿ������˼��� 
	cin >> n;
	

	for (int i = 0; i < n; i++) {
		cin >> temp;
		bool flag = true;
		for (int j = 0; j < 20; j++) {
			if (5 - index[j] >= temp) {   //�����ǰ��λ�ô�����������Ϊ������
				for (int k = 0; k < temp; k++) {
					arr[j][index[j]++] = i + 1;
				}
				flag = false;
				break;
			}
		}
		//�����ǰ��λ�ò�������������Ϊ������
		if (flag) {
			for (int j = 0; j < 20; j++) {
				if (index[j] < 5) {
					for (int k = index[j]; k < 5; k++) {
						arr[j][index[j]++] = i + 1;
						temp--;
					}
					if (temp == 0)break;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 20; j++) {
			for (int k = 0; k < index[j]; k++) {
				if (arr[j][k] == i + 1)cout << j * 5 + (k + 1) << " ";
			}
		}
		cout << endl;
	}

	return 0;
}