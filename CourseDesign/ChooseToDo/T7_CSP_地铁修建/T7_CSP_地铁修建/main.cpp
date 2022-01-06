#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cctype>
using namespace std;

const int inf = 2147483647;
const int maxn = 100000 + 10;

map<int, map<int, int> > pic;

int fa[maxn];
bool vis[maxn];
int d[maxn];

int n, m;

vector<int> path;

int dijkstra(){

    for (int i = 1; i <= n; i++)d[i] = inf;

    d[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push(make_pair(0, 1));

    while (!q.empty()){
        int u = q.top().second;
        q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (map<int, int>::iterator iter = pic[u].begin(); iter != pic[u].end(); iter++)
        {
            if (!vis[iter->first] && iter->second < d[iter->first])
            {
                d[iter->first] = iter->second;
                fa[iter->first] = u;
                q.push(make_pair(d[iter->first], iter->first));
            }
        }
    }
    int u = n;
    int ans = -1;
    while (u != 1)
    {
        ans = max(ans, pic[u][fa[u]]);
        u = fa[u];
    }
    return ans;
}

int main(){
    cin >> n >> m;
    int a, b, w;

    for (int i = 0; i < m; i++){
        cin >> a >> b >> w;
        pic[a][b] = pic[b][a] = w;
    }

    cout << dijkstra() << endl;
    return 0;
}