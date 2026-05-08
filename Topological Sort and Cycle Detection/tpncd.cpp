// Topological Sort
vector<int> order;
void dfs(int node, vector<vector<int>> &adjlist, vector<bool> &visited){
    visited[node] = true;
    for (int neighbour : adjlist[node]){
        if (!visited[neighbour]){
            dfs(neighbour, adjlist, visited);
        }
    }
    order.push_back(node);
}

// Cycle Detection
bool cycle = false;
vector<bool> in_stack(n, false);
void dfs(int node, vector<vector<int>> &adjlist, vector<bool> &visited){
    visited[node] = in_stack[node] = true;
    for (int neighbour : adjlist[node]){
        if (in_stack[neighbour]) cycle = true;
        if (!visited[neighbour]){
            dfs(neighbour, adjlist, visited);
        }
    }
    in_stack[node] = false;
}

// Main Function
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjlist(n);
    vector<bool> visited(n, false);
    vector<bool> in_stack(n, false);
    
    for (int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
    }

    for (int i = 0; i < n; i++) if (!visited[i]) dfs(i, adjlist, visited, in_stack);

    return 0;
}
