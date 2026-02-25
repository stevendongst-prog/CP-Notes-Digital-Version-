void bfs(int start, vector<vector<int>> &adjlist, vector<bool> &visited){
    queue<int> q; // q stores the order of nodes to be visited.
    visited[start] = true;
    q.push(start);
    while (!q.empty()){
        int node = q.front(); q.pop();
        // Process the node here.

        for (int neighbour : adjlist[node]){
            if (!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
