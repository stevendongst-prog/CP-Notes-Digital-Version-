#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int parent, vector<vector<int>> &adjlist, vector<vector<int>> &dp){
    dp[0][u] = 0;
    dp[1][u] = 1;
    
    for (int i = 0; i < adjlist[u].size(); i++){
        if (adjlist[u][i] == parent) continue;
        dfs(adjlist[u][i], u, adjlist, dp);
        dp[0][u] += max(dp[0][adjlist[u][i]], dp[1][adjlist[u][i]]);
        dp[1][u] += dp[0][adjlist[u][i]];
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adjlist(n + 1);
    
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    
    vector<vector<int>> dp(2, vector<int>(n + 1));
    dfs(1, -1, adjlist, dp);
    cout << max(dp[0][1], dp[1][1]);

    return 0;
}
