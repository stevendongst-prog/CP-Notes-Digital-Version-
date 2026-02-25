#include <bits/stdc++.h>
#define int long long
using namespace std;

int INF = LLONG_MAX / 4;
// Change the LLONG_MAX in the Floyd_Warshall_Algorithm function to INF.

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l, n;
    cin >> l >> n;
    string s;
    cin >> s;
    vector<char> first, second;
    
    for (int i = 0; i < l / 2; i++){
        first.push_back(s[i]);
        second.push_back(s[l - 1 - i]);
    }
    
    vector<vector<pair<int,int>>> adjlist(26);
    for (int i = 0; i < n; i++){
        char a, b;
        int c;
        cin >> a >> b >> c;
        adjlist[a - 'a'].push_back(make_pair(b - 'a', c));
    }
    
    vector<vector<int>> distance = Floyd_Warshall_Algorithm(adjlist);
    int cost = 0;
    for (int i = 0; i < l / 2; i++){
        if (first[i] != second[i]){
            int dist = INF;
            for (int j = 0; j < 25; j++){
                dist = 
                    min(dist, distance[first[i] - 'a'][j] + distance[second[i] - 'a'][j]);
            }
            if (dist == INF){
                cout << -1;
                return 0;
            } else {
                cost += dist;
            }
        }
    }
    
    cout << cost;

    return 0;
}
