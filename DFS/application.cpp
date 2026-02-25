void dfs(int node, vector<vector<int>> &adjlist, vector<bool> &visited){
    visited[node] = true;
    for (int neighbour : adjlist[node]){
        if (!visited[neighbour]){
            dfs(neighbour, adjlist, visited);
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjlist(n);
    
    for (int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    int components = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            components += 1;
            dfs(i, adjlist, visited);
        }
    }
    cout << components;

    return 0;
}
