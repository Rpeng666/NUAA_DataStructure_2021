#include"Links.h"

//插入节点
void Links::insertNode(string str) {
	if (!isValid(str)) {
		cout << "字符串“"<<str<<"”无效" << endl << endl;
		return;
	}

	Node* newNode = new Node;
	storeInfo(newNode, tail, str);
	
	cout << "字符串“" << str << "”插入成功：" << endl;
	displayOneNode(tail);
}

//展示一个节点的信息
void Links::displayOneNode(Node* target) {
	cout << "------------------------------------------" << endl;
	cout << "|" << "内容：" << setw(10) << setiosflags(ios::left) << target->str
		<< "|" << "编号：" << setw(4) << setiosflags(ios::left) << target->tag
		<< "|" << "校验码：" << setw(4) << setiosflags(ios::left) << target->check << "|" << endl;
	cout << "------------------------------------------" << endl;
}

//往节点里注入信息
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

//string中ASCII码之和
int Links::sumOfAscii(string str) {
	int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		sum += int(str[i]);
	}
	return sum;
}


//检查一个string是否合乎要求
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
		cout << "字符串"<<newstr<<"无效" << endl << endl;
		return;
	}
	if (tag + 1 > size || tag <0) {
		cout << "编号 "<<tag<<" 无效" << endl << endl;
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
	cout << "成功修改为"<<newstr<< endl << endl;
}


void Links::travelAllInfo() {
	Node* temp = this->head;
	cout << "#################链表遍历#################" << endl;
	while (temp != NULL) {
		displayOneNode(temp);
		temp = temp->next;
	}
}


void  Links::linkIsValid(Node* head) {
	if (head == NULL) {
		cout << "链表为空，无效" << endl;
		return;
	}
	if (head->tag != 0 || head->check != sumOfAscii(head->str)%113) {
		cout << "首个无效节点编号：" << 0 << endl;
		return;
	}
	if (head->next != NULL) {
		Node* pre = head;
		head = head->next;
		while (head != NULL) {
			if (head->tag != pre->tag + 1 || head->check != (pre->check + head->tag + sumOfAscii(head->str)) % 113) {
				cout << "首个无效节点编号：" << pre->tag + 1 << endl;
				return;
			}
			pre = head;
			head = head->next;
		}
	}
}