#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> Floyd_Warshall_Algorithm(int n, vector<vector<pair<int,int>>> &adjlist){
    vector<vector<int>> distance(n, vector<int>(n, LLONG_MAX));
    
    for (int i = 0; i < n; i++){
        for (auto neighbour : adjlist[i]){
            distance[i][neighbour.first] = 
                min(distance[i][neighbour.first], neighbour.second);
        }
        distance[i][i] = 0;
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (distance[j][i] + distance[i][k] < distance[j][k]){
                    distance[j][k] = distance[j][i] + distance[i][k];
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
    vector<vector<pair<int,int>>> adjlist(n);
    
    for (int i = 0; i < e; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adjlist[x].push_back(make_pair(y, w));
        adjlist[y].push_back(make_pair(x, w));
    }
    
    vector<vector<int>> distance = Floyd_Warshall_Algorithm(n, adjlist);
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << distance[i][j] << " "; // Shortest distance from node i to node j
        }
        cout << "\n";
    }

    return 0;
}
