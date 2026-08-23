vector<vector<int>> adjlist;
vector<vector<int>> twok; // twok[x][k] is the 2^k-th ancestor of x.
vector<int> depth;

void dfs(int v, int parent){
    twok[v][0] = parent;

    for (int k = 0; k < 19; k++){
        if (twok[v][k] == -1) break;
        twok[v][k + 1] = twok[twok[v][k]][k];
    }

    for (int it : adjlist[v]){
        if (it == parent) continue;
        depth[it] = depth[v] + 1;
        dfs(it, v);
    }
}

void initialisation(int n, vector<vector<int>> adjacency_list){
    adjlist = adjacency_list;
    twok.assign(n, vector<int>(20, -1)); // Enough for n <= 10^6 since 2^20 > 1e6.
    depth.assign(n, 0);
    dfs(0, -1); // fixed root = 0
}

int kth_ancestor(int x, int k){
    for (int j = 0; j < 20; j++){
        if (k & (1 << j)){
            x = twok[x][j];
            if (x == -1) return -1;
        }
    }
  
    return x;
}
