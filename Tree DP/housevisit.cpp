#include <bits/stdc++.h>
using namespace std;

vector<int> subsize;
vector<vector<long long>> dp;

void dfs(int u, int parent, vector<vector<pair<int,int>>> &adjlist){
    dp[u] = vector<long long>(adjlist.size() + 1, LLONG_MAX);
    dp[u][1] = 0; // Visiting only u
    subsize[u] = 1;

    for (auto [v, w] : adjlist[u]){
        if (v == parent) continue;
        dfs(v, u, adjlist);
        vector<long long> new_dp(adjlist.size() + 1, LLONG_MAX);

        for (int i = 0; i <= subsize[u]; i++){
            if (dp[u][i] == LLONG_MAX) continue;
            new_dp[i] = min(new_dp[i], dp[u][i]); // Option 1: Take nothing from child v.
            for (int ci = 1; ci <= subsize[v]; ci++){ // Option 2: Take ci > 0 from child v.
                if (dp[v][ci] == LLONG_MAX) continue;
                new_dp[i + ci] = min(new_dp[i + ci], dp[u][i] + dp[v][ci] + w);
            }
        }

        subsize[u] += subsize[v];
        dp[u].swap(new_dp);
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> adjlist(n);

    for (int i = 0; i < n - 1; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adjlist[a - 1].push_back(make_pair(b - 1, w));
        adjlist[b - 1].push_back(make_pair(a - 1, w));
    }

    subsize.resize(n); dp.resize(n);
    dfs(0, -1, adjlist);
    for (int X = 1; X <= n - 1; X++) cout << dp[0][X + 1] * 2 << "\n";

    return 0;
}
