int bfs(int s, int t, vector<vector<int>> &adjlist, vector<bool> &visited, vector<int> &distance){
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty()){
        int node = q.front(); q.pop();
        if (node == t) return distance[node];
        for (int neighbour : adjlist[node]){
            if (!visited[neighbour]){
                visited[neighbour] = true;
                distance[neighbour] = distance[node] + 1;
                q.push(neighbour);
            }
        }
    }
    return -1; // If the 2 nodes are in different components
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, e, s, t;
    cin >> n >> e >> s >> t;
    vector<vector<int>> adjlist(n);
    
    for (int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    
    vector<bool> visited(n, false);
    vector<int> distance(n, -1);
    distance[s] = 0;
    cout << bfs(s, t, adjlist, visited, distance);

    return 0;
}
