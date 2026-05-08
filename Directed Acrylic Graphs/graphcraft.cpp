vector<int> dp, state;
bool possible = true;

// state[node] -> 0: unvisited, 1: visiting, 2: visited
long long dfs(int node, vector<pair<int,int>> V[]){
    if (node == 0) return 1; // Base case
    if (state[node] == 2) return dp[node];

    // Detect cycles.
    if (state[node] == 1){
        possible = false;
        return 0;
    }

    state[node] = 1;
    long long result = 0;

    for (auto &edge : V[node]){
        int v = edge.first;
        int w = edge.second;

        long long sub = dfs(v, V);
        if (possible == false) return 0;

        result = (result + w * sub) % 1000000007;
    }

    state[node] = 2;
    dp[node] = result;
    return result;
}

int graphcraft(int n, int c, vector<pair<int,int>> V[]){
    dp.assign(n, 0);
    state.assign(n, 0);
    long long answer = dfs(c, V);
    if (possible == false) return -1;
    return (int)(answer % 1000000007);
