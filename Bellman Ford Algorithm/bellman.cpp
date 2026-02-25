#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> Bellman_Ford_Algorithm(int s, int n, vector<vector<pair<int,int>>> &adjlist){
    vector<int> distance(n, LLONG_MAX);
    distance[s] = 0;

    for (int i = 1; i < n; i++){
        for (int j = 0; j < n; u++){
            if (distance[j] == LLONG_MAX) continue;
            for (int k = 0; k < adjlist[j].size(); k++){
                int v = adjlist[j][k].first;
                int w = adjlist[j][k].second;
                if (distance[j] + w < distance[v]){
                    distance[v] = distance[j] + w;
                }
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
    
    vector<int> distance = Bellman_Ford_Algorithm(s, n, adjlist);
    cout << distance[t]; // Outputs shortest distance.

    return 0;
}
