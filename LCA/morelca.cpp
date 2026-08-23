vector<int> euler, euler_depth, first, log_2_table;
vector<vector<int>> sparse_table, children;

// Euler Tour: Preorder + End Order
void dfs(int v, int d){
    first[v] = euler.size();
    euler.push_back(v);
    euler_depth.push_back(d);
    for (int u : children[v]){
        dfs(u, d + 1);
        euler.push_back(v);
        euler_depth.push_back(d);
    }
}

void initialisation(int n, vector<int> parent){
    children.assign(n, {});
    for (int i = 1; i < n; i++) if (parent[i] != -1) children[parent[i]].push_back(i);
    
    euler.clear();
    euler_depth.clear();
    first.assign(n, -1);

    dfs(0, 0);

    int m = euler.size();
    log_2_table.assign(m + 1, 0);
    for (int i = 2; i <= m; i++) log_2_table[i] = log_2_table[i / 2] + 1;
    sparse_table.assign(log_2_table[m] + 1, vector<int>(m));
    for (int i = 0; i < m; i++) sparse_table[0][i] = i;
    for (int k = 1; (1 << k) <= m; k++){
        for (int i = 0; i + (1 << k) <= m; i++){
            int x = sparse_table[k - 1][i];
            int y = sparse_table[k - 1][i + (1 << (k - 1))];
            sparse_table[k][i] = (euler_depth[x] < euler_depth[y] ? x : y);
        }
    }
}

int lca(int u, int v){
    int l = first[u], r = first[v];
    if (l > r) swap(l, r);
    int k = log_2_table[r - l + 1];
    int x = sparse_table[k][l];
    int y = sparse_table[k][r - (1 << k) + 1];
    return euler_depth[x] < euler_depth[y] ? euler[x] : euler[y];
}

int more_lca(int k, vector<int> v){
    int result = v[0];
    for (int i = 1; i < k; i++) result = lca(result, v[i]);
    return result;
}
