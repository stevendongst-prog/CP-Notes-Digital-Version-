#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> subsize;
vector<int> dp;
int total = 0;


void dfs(int u, int parent, int depth, vector<vector<int>> &adjlist){
    subsize[u] = 1;
    dp[0] += depth;
    
    for (int neighbour : adjlist[u]){
        if (neighbour == parent) continue;
        dfs(neighbour, u, depth + 1, adjlist);
        subsize[u] += subsize[neighbour];
    }
}

void rerooting(int u, int parent, int sum, int n, vector<vector<int>> &adjlist){
    total += sum;
    for (int neighbour : adjlist[u]){
        if (neighbour == parent) continue;
        int csum = sum - subsize[neighbour] + (n - subsize[neighbour]);
        rerooting(neighbour, u, csum, n, adjlist);
    }
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adjlist(n);
    
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adjlist[a - 1].push_back(b - 1);
        adjlist[b - 1].push_back(a - 1);
    }
    
    subsize.resize(n); dp.resize(n);
    dfs(0, -1, 0, adjlist);
    rerooting(0, -1, dp[0], n, adjlist);
    cout << total;

    return 0;
}
