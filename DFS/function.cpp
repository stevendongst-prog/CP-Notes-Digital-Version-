void dfs(int node, vector<vector<int>> &adjlist, vector<bool> &visited){
    visited[node] = true;
    // Process the node here.
    
    for (int neighbour : adjlist[node]){
        if (!visited[neighbour]){
            dfs(neighbour, adjlist, visited);
        }
    }
}
