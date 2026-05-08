#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>> &adjlist, vector<int> &dp){
    if (dp[node] != -1) return dp[node];
    int best = 0;
    for (int neighbour : adjlist[node]){
        best = max(best, 1 + dfs(neighbour, adjlist, dp));
    }
    return dp[node] = best;
}

int longest_path(int n, vector<vector<int>> &adjlist){
    vector<int> dp(n, -1);
    int answer = 0;
    for (int i = 0; i < n; i++){
        answer = max(answer, dfs(i, adjlist, dp));
    }
    return answer;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjlist(n);
    vector<bool> visited(n, false);
    
    for (int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adjlist[a].push_back(b);
    }

    cout << longest_path(n, adjlist);

    return 0;
}
