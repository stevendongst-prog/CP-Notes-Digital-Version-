vector<vector<pair<int,int>>> adjlist;
vector<vector<int>> twok;
vector<int> depth;
vector<long long> dist;

void dfs(int v, int parent){
    twok[v][0] = parent;

    for (int k = 0; k < 19; k++){
        if (twok[v][k] == -1) break;
        twok[v][k + 1] = twok[twok[v][k]][k];
    }

    for (auto [it, weight] : adjlist[v]){
        if (it == parent) continue;
        depth[it] = depth[v] + 1;
        dist[it] = dist[v] + weight;
        twok[it][0] = v;
        dfs(it, v);
    }
}

void initialisation(int n){
    twok.assign(n, vector<int>(20, -1));
    depth.assign(n, 0);
    dist.assign(n, 0);
    dfs(0, -1); // fixed root = 0
    for (int k = 0; k < 19; k++){
        for (int v = 0; v < n; v++){
            if (twok[v][k] != -1) twok[v][k + 1] = twok[twok[v][k]][k];
        }
    }
}

int lca(int x, int y){
    if (depth[x] < depth[y]) swap(x, y);

    // Lift x to same depth as y
    int difference = depth[x] - depth[y];
    for (int k = 0; k < 20; k++){
        if (difference & (1 << k)) x = twok[x][k];
    }

    if (x == y) return x;

    // Lift both until ancestors differ.
    for (int k = 19; k >= 0; k--){
        if (twok[x][k] != -1 && twok[x][k] != twok[y][k]){
            x = twok[x][k];
            y = twok[y][k];
        }
    }

    return twok[x][0];
}

long long distance(int x, int y){
    int a = lca(x, y);
    return dist[x] + dist[y] - 2LL * dist[a];
}
