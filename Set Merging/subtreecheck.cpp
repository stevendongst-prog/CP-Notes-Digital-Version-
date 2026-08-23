vector<int> value;
vector<unordered_set<int>*> s;

// Call using dfs(1, 0); -> root = 1, parent = 0.
void dfs(int u, int parent, int n, vector<vector<int>> &adjlist){
    value.resize(n); s.resize(n);

    // Create a new set for this vertex.
    s[u] = new unordered_set<int>();
    s[u] -> insert(value[u]);
    for (int v : adjlist[u]){
        if (v == parent) continue;
        dfs(v, u, n, adjlist);

        // Small-to-large merge
        if (s[v] -> size() > s[u] -> size()) swap(s[u], s[v]);
        for (int x : *s[v]) s[u] -> insert(x);
        delete s[v]; // Optional: Reduce memory
    }
}

bool query(int x, int y){return s[y] -> count(x);}
