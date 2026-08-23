vector<vector<pair<int, int>>> adjlist;
vector<pair<int, int>> offset; // 1st: net shift of weight, 2nd: net shift of edge count
vector<map<int, int>> m; // m[v][w] = minimum edges in a downward path from v with weight w
int result = INT_MAX;

void dfs(int v, int parent, int k){
    m[v][0] = 0;
    for (auto [it, weight] : adjlist[v]){
        if (it == parent) continue;
        dfs(it, v, k);
        offset[it].first += weight;
        offset[it].second++;

        if (m[it].size() > m[v].size()){
            swap(m[it], m[v]);
            swap(offset[it], offset[v]);
        }

        for (auto x : m[it]){
            int t = k - x.first - offset[v].first - offset[it].first;
            if (m[v].count(t)) 
            result = min(result, m[v][t] + offset[v].second + x.second + offset[it].second);
        }

        for (auto x : m[it]){
            int t = x.first + offset[it].first - offset[v].first;
            if (m[v].count(t)) 
            m[v][t] = min(m[v][t], x.second + offset[it].second - offset[v].second);
            else m[v][t] = x.second + offset[it].second - offset[v].second;
        }
    }
}

int best_path(int n, int k, vector<vector<pair<int, int>>> adjacency_list){
    adjlist = adjacency_list; offset.resize(n); m.resize(n);
    dfs(0, -1, k);
    if (result == INT_MAX) return -1;
    else return result;
}
