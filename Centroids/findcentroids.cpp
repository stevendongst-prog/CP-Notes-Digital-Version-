void dfs(
    int u,
    int parent,
    vector<vector<int>> &adjlist,
    vector<int> &subtree,
    int n,
    vector<int> &centroids
){
    subtree[u] = 1;
    bool is_centroid = true;

    for (int v : adjlist[u]){
        if (v == parent) continue;
        dfs(v, u, adjlist, subtree, n, centroids);
        subtree[u] += subtree[v];

        // If removing u leaves a component larger than n / 2
        if (subtree[v] > n / 2) is_centroid = false;
    }

    // Check the "rest of the tree" component.
    if (n - subtree[u] > n / 2) is_centroid = false;

    if (is_centroid) centroids.push_back(u);
}

vector<int> f_centroids(int n, vector<vector<int>> &adjlist){
    vector<int> subtree(n, 0);
    vector<int> centroids;
    dfs(0, -1, adjlist, subtree, n, centroids);
    return centroids;
}
