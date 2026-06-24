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

vector<int> f_centers(int n, vector<vector<pair<int,int>>> &adjlist){
    // 1. Find one endpoint of the diameter.
    vector<int> distance1(n);
    vector<int> parent1(n);
    dfs(0, -1, 0, adjlist, distance1, parent1);

    int A = max_element(distance1.begin(), distance1.end()) - distance1.begin();

    // 2. Find the other endpoint and store parents.
    vector<int> distance2(n);
    vector<int> parent2(n);
    dfs(A, -1, 0, adjlist, distance2, parent2);
    int B = max_element(distance2.begin(), distance2.end()) - distance2.begin();
    int diameter = distance2[B];

    // 3. Reconstruct diameter path A -> B.
    vector<int> path;
    for (int v = B; v != -1; v = parent2[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    // 4. Find center(s).
    vector<int> centers;
    int current = 0;
    for (int i = 0; i + 1 < path.size(); i++){
        int u = path[i], v = path[i + 1];
        int w = 0;
        for (auto [x, weight] : adjlist[u]){
            if (x == v){w = weight; break;}
        }
        if (current + w == diameter / 2){
            // midpoint exactly at node v
            centers.push_back(v);
            return centers;
        }
        if (current < diameter / 2 && current + w > diameter / 2){
            // midpoint lies between u and v
            centers.push_back(u);
            centers.push_back(v);
            return centers;
        }
        current += w;
    }
    centers.push_back(path[path.size() / 2]);
    return centers;
}
