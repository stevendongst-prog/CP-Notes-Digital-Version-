int n, k;
vector<vector<int>> adjlist;
vector<bool> removed; // Assign n elements all set to false.
vector<int> subtree; // Assign n elements all set to 0.

// Compute subtree sizes.
void dfs_size(int u, int p){
    subtree[u] = 1;
    for (int v : adjlist[u]){
        if (v == p || removed[v]) continue;
        dfs_size(v, u);
        subtree[u] += subtree[v];
    }
}

// Find centroid.
int dfs_centroid(int u, int p, int total){
    for (int v : adjlist[u]){
        if (v == p || removed[v]) continue;
        if (subtree[v] > total / 2)
            return dfs_centroid(v, u, total);
    }
    return u;
}

// Collect distances from centroid.
void dfs_distance(int u, int p, int d, vector<int> &distance){
    if (d > k) return;
    distance.push_back(d);
    for (int v : adjlist[u]){
        if (v == p || removed[v]) continue;
        dfs_distance(v, u, d + 1, distance);
    }
}

// Centroid decomposition
void decompose(int entry, int &answer){
    dfs_size(entry, -1);
    int c = dfs_centroid(entry, -1, subtree[entry]);
    removed[c] = true;

    unordered_map<int, int> count;
    count[0] = 1;  // distance(G, G) = 0

    for (int v : adjlist[c]){
        if (removed[v]) continue;
        vector<int> distance;
        dfs_distance(v, c, 1, distance);

        // Count valid paths.
        for (int d : distance) if (k - d >= 0 && count.count(k - d)) answer += count[k - d];

        // Add distances to map.
        for (int d : distance) count[d]++;
    }

    // Recurse on subtrees.
    for (int v : adjlist[c]) if (!removed[v]) decompose(v, answer);
}
