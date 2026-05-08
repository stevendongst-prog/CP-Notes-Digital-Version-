vector<int> parent; // Contains n elements, where n is the number of nodes

int find(int x){
    // Find representative.
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

bool merge(int x, int y, vector<int> &sizes){
    x = find(x); // Find the representative of x.
    y = find(y); // Find the representative of y.
    if (x == y) return false;
    if (sizes[x] <= sizes[y]) swap(x, y);
    parent[y] = x;
    sizes[x] += sizes[y];
    return true;
}
