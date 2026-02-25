#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> Dijkstra_Algorithm(int s, int n, vector<vector<pair<int,int>>> &adjlist){
    vector<int> distance(n, LLONG_MAX);
    distance[s] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, s});
    
    while (!q.empty()){
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        if (d > distance[u]) continue;
        for (int i = 0; i < adjlist[u].size(); i++){
            int v = adjlist[u][i].first;
            int w = adjlist[u][i].second;
            if (distance[u] + w < distance[v]){
                distance[v] = distance[u] + w;
                q.push({distance[v], v});
            }
        }
    }

    return distance;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, e;
    cin >> n >> e;
    int s, t; // Starting node and ending node
    cin >> s >> t;
    vector<vector<pair<int,int>>> adjlist(n);
    
    for (int i = 0; i < e; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adjlist[x].push_back(make_pair(y, w));
        adjlist[y].push_back(make_pair(x, w));
    }
    
    vector<int> distance = Dijkstra_Algorithm(s, n, adjlist);
    cout << distance[t]; // Outputs shortest distance.

    return 0;
}
