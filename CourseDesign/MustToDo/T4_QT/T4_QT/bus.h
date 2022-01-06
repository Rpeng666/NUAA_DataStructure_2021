#ifndef BUS_H

#include<iostream>
#include<fstream>
#include<set>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;


class Bus {
private:
	multimap<string, string> lineTostop;
	multimap<string, string> stopToline;
	map<string, bool> stopIsFind;
	map<string, bool> lineIsFind;
	

public:
	vector<string> split(const string& str, const string& pattern);
	void createGraph();
	void clearStopIsFind();
	void clearlineIsFind();
	string findComLine(string pos1, string pos2);
	vector<string> minTransfer(string pos1, string pos2);

	//vector<string> minPassStop(string pos1, string pos2);

};
#endif // !BUS_H
