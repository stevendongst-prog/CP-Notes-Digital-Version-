vector<int> parent;

bool merge(int x, int y, vector<int> &sizes, int &total){
    x = find(x);
    y = find(y);
    if (x == y) return false;
    total -= sizes[x] * (sizes[x] - 1) / 2;
    total -= sizes[y] * (sizes[y] - 1) / 2;
    if (sizes[x] <= sizes[y]) swap(x, y);
    parent[y] = x;
    sizes[x] += sizes[y];
    total += sizes[x] * (sizes[x] - 1) / 2;
    return true;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, e;
    cin >> n >> e;
    parent.resize(n);
    vector<int> sizes(n, 1);
    vector<pair<int,int>> edges(e);
    for (int i = 0; i < n; i++) parent[i] = i;
    for (int i = 0; i < e; i++) cin >> edges[i].first >> edges[i].second;
    int total = 0;
    for (int i = 0; i < e; i++){
        merge(edges[i].first, edges[i].second, sizes, total);
        cout << total << "\n";
    }
    
    return 0;
}
