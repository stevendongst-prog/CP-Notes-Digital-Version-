void dfs(
    int u,
    int parent,
    int dist,
    vector<vector<pair<int,int>>> &adjlist,
    vector<int> &distances,
    vector<int> &parents
){
    distances[u] = dist;
    parents[u] = parent;
    for (auto [v, w] : adjlist[u]){
        if (v == parent) continue;
        dfs(v, u, dist + w, adjlist, distances, parents);
    }
}

tuple<int,int,int,vector<int>> f_diameter(int n, vector<vector<pair<int,int>>> &adjlist){
    // 1. First DFS from an arbitrary node (0)
    vector<int> distance1(n);
    vector<int> parent1(n);
    dfs(0, -1, 0, adjlist, distance1, parent1);

    int A = max_element(distance1.begin(), distance1.end()) - distance1.begin();

    // 2. Second DFS from A
    vector<int> distance2(n);
    vector<int> parent2(n);
    dfs(A, -1, 0, adjlist, distance2, parent2);

    int B = max_element(distance2.begin(), distance2.end()) - distance2.begin();
    int diameter = distance2[B];

    // 3. Reconstruct path A -> B.
    vector<int> path;
    for (int v = B; v != -1; v = parent2[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    return {diameter, A, B, path};
}
