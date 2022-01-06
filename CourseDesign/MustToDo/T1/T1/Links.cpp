#include"Links.h"

//����ڵ�
void Links::insertNode(string str) {
	if (!isValid(str)) {
		cout << "�ַ�����"<<str<<"����Ч" << endl << endl;
		return;
	}

	Node* newNode = new Node;
	storeInfo(newNode, tail, str);
	
	cout << "�ַ�����" << str << "������ɹ���" << endl;
	displayOneNode(tail);
}

//չʾһ���ڵ����Ϣ
void Links::displayOneNode(Node* target) {
	cout << "------------------------------------------" << endl;
	cout << "|" << "���ݣ�" << setw(10) << setiosflags(ios::left) << target->str
		<< "|" << "��ţ�" << setw(4) << setiosflags(ios::left) << target->tag
		<< "|" << "У���룺" << setw(4) << setiosflags(ios::left) << target->check << "|" << endl;
	cout << "------------------------------------------" << endl;
}

//���ڵ���ע����Ϣ
void Links::storeInfo(Node* &newNode, Node* &tail,string str) {
	if (tail != NULL) {
		tail->next = newNode;
		newNode->str = str;
		newNode->tag = tail->tag + 1;
		newNode->check = (tail->check + newNode->tag + sumOfAscii(str)) % 113;
		newNode->next = NULL;
		tail = tail->next;
	}
	else {
		head = tail = new Node;
		head->str = str;
		head->tag = 0;
		head->check = sumOfAscii(str)%113;
		head->next = NULL;
	}
	size++;
}

//string��ASCII��֮��
int Links::sumOfAscii(string str) {
	int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		sum += int(str[i]);
	}
	return sum;
}


//���һ��string�Ƿ�Ϻ�Ҫ��
bool Links::isValid(string str) {
	if (str.size() == 0) return false;
	
	for (int i = 0; i < str.size(); i++) {
		if (str[i] > 127 || str[i] < 0) {
			return false;
		}
	}
	return true;
}


void Links::changeInfo(int tag, string newstr) {
	if (!isValid(newstr)) {
		cout << "�ַ���"<<newstr<<"��Ч" << endl << endl;
		return;
	}
	if (tag + 1 > size || tag <0) {
		cout << "��� "<<tag<<" ��Ч" << endl << endl;
		return;
	}
	Node* temp = this->head;
	Node* pre = NULL;
	for (int i = 0; i < size && i!= tag; i++) {
		pre = temp;
		temp = temp->next;
	}

	if (pre == NULL) {
		temp->str = newstr;
		temp->check = sumOfAscii(newstr) % 113;
	}
	else {
		temp->str = newstr;
		temp->check = (pre->check + temp->tag + sumOfAscii(newstr)) % 113;
	}

	pre = temp;
	temp = temp->next;
	while (temp != NULL) {
		temp->check = (pre->check + temp->tag + sumOfAscii(newstr)) % 113;
		pre = temp;
		temp = temp->next;
	}
	cout << "�ɹ��޸�Ϊ"<<newstr<< endl << endl;
}


void Links::travelAllInfo() {
	Node* temp = this->head;
	cout << "#################�������#################" << endl;
	while (temp != NULL) {
		displayOneNode(temp);
		temp = temp->next;
	}
}


void  Links::linkIsValid(Node* head) {
	if (head == NULL) {
		cout << "����Ϊ�գ���Ч" << endl;
		return;
	}
	if (head->tag != 0 || head->check != sumOfAscii(head->str)%113) {
		cout << "�׸���Ч�ڵ��ţ�" << 0 << endl;
		return;
	}
	if (head->next != NULL) {
		Node* pre = head;
		head = head->next;
		while (head != NULL) {
			if (head->tag != pre->tag + 1 || head->check != (pre->check + head->tag + sumOfAscii(head->str)) % 113) {
				cout << "�׸���Ч�ڵ��ţ�" << pre->tag + 1 << endl;
				return;
			}
			pre = head;
			head = head->next;
		}
	}
}