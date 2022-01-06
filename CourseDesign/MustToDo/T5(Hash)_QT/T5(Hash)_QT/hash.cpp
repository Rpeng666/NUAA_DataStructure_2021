#include"hash.h"


void Hash::readData_1() {
	fstream file("data.txt", ios::in);
	string ssn, name, date, flight;
	int asciisum = 0,hashpos,dis,i=0,j=1,tempPos;

	while (!file.eof()) {
		file >> ssn >> name >> date >> flight >> dis;
		asciisum = 0;
		this->distance[ssn] += dis;
		this->frequence[ssn] ++;
		for (int i = 0; i < ssn.size(); i++)
			asciisum += (ssn[i] - '0');

		tempPos = hashpos = asciisum % p;
		i = 1;

		while (hashMap[tempPos].ssn != " ") {
			
			tempPos = (hashpos + i * i * j) % N;
			i++, j = j * (-1);
			tempPos = (tempPos < 0) ? (N + tempPos) : tempPos;
		}

		hashMap[tempPos].changeInfo(ssn, name, date, flight, dis, i-1);

		if (file.fail())break;
	}
	file.close();
}

void Hash::readData_2() {
	fstream file("data.txt", ios::in);
	string ssn, name, date, flight;
	Node *q;
	int asciisum = 0, hashpos, dis, i = 0;

	for (int i = 0; i < N; i++)nodemap[i] = NULL;
	while (!file.eof()) {
		file >> ssn >> name >> date >> flight >> dis;
		asciisum = 0;

		for (int i = 0; i < ssn.size(); i++)
			asciisum += (ssn[i] - '0');

		hashpos = asciisum % p;
		q = nodemap[hashpos];

		i = 0;
		if (q == NULL)
			nodemap[hashpos] = new Node(ssn, name, date, flight, dis, NULL, i);
		
		else {
			while (q->next != NULL) {
				q = q->next;
				i++;
			}
			q->next = new Node(ssn, name, date, flight, dis, NULL, i);
		}
		if (file.fail())break;
	}

	file.close();
}

Person* Hash::getHashMap() {
	return this->hashMap;
}

Node** Hash::getNodeMap() {
	return this->nodemap;
}

map<string, int> Hash::getFrequence() {
	return this->frequence;
}

map<string, int> Hash::getDistance() {
	return this->distance;
}