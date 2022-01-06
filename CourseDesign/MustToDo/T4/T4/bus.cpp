#include"bus.h"
#define INF 9999999
#include<math.h>

vector<string> Bus::split(const string& str, const string& pattern) {
    vector<string> res;
    if (str == "")
        return res;
    //在字符串末尾也加入分隔符，方便截取最后一段
    string strs = str + pattern;
    size_t pos = strs.find(pattern);

    while (pos != strs.npos) {

        string temp = strs.substr(0, pos);
        res.push_back(temp);
        //去掉已分割的字符串,在剩下的字符串中进行分割
        strs = strs.substr(pos + 1, strs.size());
        pos = strs.find(pattern);
    }

    return res;
}

void Bus::createGraph() {
    fstream file("南京公交线路.txt", ios::in);
    string line, stops;

    vector<string> vecStop, vecline;

    while (!file.eof()) {
        file >> line;
        getline(file, stops);
        if (file.fail())break;

        vecStop = split(stops.substr(3), ",");
        //存入每条线路的站点信息
        allLines.emplace(make_pair(line, vecStop));

        for (int i = 0; i < vecStop.size(); i++) {
            lineTostop.emplace(make_pair(line, vecStop[i]));
            lineIsFind.emplace(make_pair(line, false));

            stopToline.emplace(make_pair(vecStop[i], line));
            stopIsFind.emplace(make_pair(vecStop[i], false));
        }
    }
    file.close();
}

void Bus::clearStopIsFind() {
    for (auto i = stopIsFind.begin(); i != stopIsFind.end(); i++) {
        i->second = false;
    }
}

void Bus::clearlineIsFind() {
    for (auto i = lineIsFind.begin(); i != lineIsFind.end(); i++) {
        i->second = false;
    }
}
//dijkstra算法
vector<string> Bus::minTransfer(string pos1, string pos2) {
    clearStopIsFind();
    clearlineIsFind();
    map<string, int> dij;
    string min_stop;
    int min_transfer = INF;
    vector<string> result;
    map<string, string> path;

    for (auto i = stopToline.begin(); i != stopToline.end(); i++) {
        dij[i->first] = INF;  //初始状态到每个站点都是无穷
        path[i->first] = " "; //到所有站点都没有需要经过的站点
    }

    dij[pos1] = 0; //自己到自己只需转0站
    stopIsFind[pos1] = true;

    for (auto i = stopToline.lower_bound(pos1); i != stopToline.upper_bound(pos1); i++) {
 
        for (auto j = lineTostop.lower_bound(i->second); j != lineTostop.upper_bound(i->second); j++) {
            dij[j->second] = 0;
            path[j->second] = pos1;//到这些站点都要经过pos1
        }
    }
    path[pos1] = " ";

    for (int k = 0; k < dij.size() - 1; k++) {
        /*if(k %100 ==0)
            cout << "进度：" << k << endl;*/

        min_transfer = INF;
        for (auto i = dij.begin(); i != dij.end(); i++) {
            if (i->second < min_transfer && !stopIsFind[i->first]) {
                min_transfer = i->second;
                min_stop = i->first;
            }
        }

        stopIsFind[min_stop] = true;

        for (auto i = stopToline.lower_bound(min_stop); i != stopToline.upper_bound(min_stop); i++) {

            for (auto j = lineTostop.lower_bound(i->second); j != lineTostop.upper_bound(i->second); j++) {

                int dis1 = dij[j->second];
                int dis2 = dij[i->first];
                bool flag_1 = stopIsFind[j->second];

                if (!stopIsFind[j->second] && dij[j->second] > dij[i->first] + 1) {
                    dij[j->second] = dij[i->first] + 1;
                    path[j->second] = i->first;
                }
            }
        }
    }
    result.emplace_back(pos2);
    while (path[pos2] != " ") {
        result.emplace_back(findComLine(pos2, path[pos2]));
        result.emplace_back(path[pos2]);
        pos2 = path[pos2];
    }
    return result;
}

string Bus::findComLine(string pos1,string pos2) {
    string commonLine;
    for (auto i = stopToline.lower_bound(pos1); i != stopToline.upper_bound(pos1); i++) {
        for (auto j = lineTostop.lower_bound(i->second); j != lineTostop.upper_bound(i->second); j++) {
            if (j->second == pos2) {
                commonLine.append(j->first + "  ");
            }
        }
    }
    return commonLine;
}

//dijkstra算法
vector<string> Bus::minPassStop(string pos1, string pos2) {
    vector<string> temp;
    vector<string> result;
    map<string, int> dij;
    map<string, string> path;
    int pos_num;
    int min_pass = INF;
    string min_stop;

    for (auto i = stopToline.begin(); i != stopToline.end(); i++) {
        dij[i->first] = INF;  //初始状态到每个站点都是无穷
        path[i->first] = " "; //到所有站点都没有需要经过的站点
    }

    dij[pos1] = 0; //自己到自己只需经过0站
    stopIsFind[pos1] = true;

    //经过pos1站点的所有线路
    for (auto i = stopToline.lower_bound(pos1); i != stopToline.upper_bound(pos1); i++) {

        temp = allLines[i->second];
        //找到pos1在线路中的位置
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == pos1) {
                pos_num = j;
                break;
            }
        }

        for (int j = 0; j < temp.size(); j++)
        {   //pos1到其他站点需要经过的站点个数
            dij[temp[j]] = abs(j - pos_num);
        }
    }

    path[pos1] = " ";

    for (int k = 0; k < dij.size() - 1; k++) {
      /*  if (k % 100 == 0)
            cout << "进度：" << k << endl;*/

        min_pass = INF;
        for (auto i = dij.begin(); i != dij.end(); i++) {
            if (i->second < min_pass && !stopIsFind[i->first]) {
                min_pass = i->second;
                min_stop = i->first;
            }
        }

        stopIsFind[min_stop] = true;

        for (auto i = stopToline.lower_bound(min_stop); i != stopToline.upper_bound(min_stop); i++) {
            //目前选中的这个站点所能乘坐的线路
            temp = allLines[i->second];

            for (int j = 0; j < temp.size(); j++) {
                if (temp[j] == min_stop) {
                    pos_num = j;
                    break;
                }
            }

            for (int j = 0; j < temp.size(); j++) {
                if (dij[temp[j]] > dij[min_stop] + abs(j - pos_num)) {
                    dij[temp[j]] = dij[min_stop] + abs(j - pos_num);
                    path[temp[j]] = min_stop;
                }
            }
        }
    }

    result.emplace_back("(一共"+std::to_string(dij[pos2])+"站)");
    result.emplace_back(pos2);

    while (path[pos2] != " ") {
        result.emplace_back(findMinComLine(pos2, path[pos2]));
        result.emplace_back(path[pos2]);
        pos2 = path[pos2];
    }
    return result;
}


string Bus::findMinComLine(string pos1, string pos2) {
    int min_pass = INF;
    string min_line;
    int pos_num;
    vector<string> temp;
    string commonLine;

    for (auto i = stopToline.lower_bound(pos1); i != stopToline.upper_bound(pos1); i++) {

        temp = allLines[i->second];

        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == pos1) {
                pos_num = j;
                break;
            }
        }

        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == pos2) {
                if (abs(j - pos_num) < min_pass) {

                    min_pass = abs(j - pos_num);
                    min_line = i->second;
                    commonLine.append(min_line + " ");
                }
            }
        }
    }
    return commonLine;
}