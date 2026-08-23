#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Segment_Tree{
    vector<int> tree, lazy;
    Segment_Tree(int size){
        tree.assign(size * 4, 0);
        lazy.assign(size * 4, 0);
    }

    void build(vector<int> &array, int node, int start, int end){
        if (start == end){
            tree[node] = array[start];
        } else {
            int mid = (start + end) / 2;
            build(array, 2 * node + 1, start, mid);
            build(array, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void push(int node, int start, int end){
        if (lazy[node] != 0){
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end){
                lazy[node * 2 + 1] += lazy[node];
                lazy[node * 2 + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void range_update(int node, int start, int end, int l, int r, int value){
        push(node, start, end);
        if (r < start || end < l) return;
        if (l <= start && end <= r){
            lazy[node] += value;
            push(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        range_update(2 * node + 1, start, mid, l, r, value);
        range_update(2 * node + 2, mid + 1, end, l, r, value);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int node, int start, int end, int l, int r){
        push(node, start, end);
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(node * 2 + 1, start, mid, l, r) + query(node * 2 + 2, mid + 1, end, l, r);
    }
};

int dfs1(int u, int parent, vector<vector<int>> &adjlist,
         vector<int> &parents, vector<int> &depth,
         vector<int> &heavy, vector<int> &sizes){

    parents[u] = parent;
    sizes[u] = 1;
    int max_subtree_size = 0;

    for (int v : adjlist[u]) {
        if (v == parent) continue;
        depth[v] = depth[u] + 1;
        int subtree_size = dfs1(v, u, adjlist, parents, depth, heavy, sizes);
        sizes[u] += subtree_size;
        if (subtree_size > max_subtree_size){
            max_subtree_size = subtree_size;
            heavy[u] = v;
        }
    }
  
    return sizes[u];
}

int current_position = 0;

void dfs2(int u, int h, vector<vector<int>> &adjlist,
          vector<int> &parents, vector<int> &heavy,
          vector<int> &head, vector<int> &positions){

    head[u] = h;
    positions[u] = current_position++;

    if (heavy[u] != -1){
        dfs2(heavy[u], h, adjlist, parents, heavy, head, positions);
    }

    for (int neighbour : adjlist[u]){
        if (neighbour == parents[u] || neighbour == heavy[u]) continue;
        dfs2(neighbour, neighbour, adjlist, parents, heavy, head, positions);
    }
}

void node_update(int x, int y, int z,
                 Segment_Tree &segment,
                 vector<int> &head,
                 vector<int> &positions,
                 vector<int> &parents,
                 vector<int> &depth){

    while (head[x] != head[y]){
        if (depth[head[x]] < depth[head[y]]) swap(x, y);

        segment.range_update(0, 0, segment.tree.size()/4 - 1, positions[head[x]], positions[x], z);

        x = parents[head[x]];
    }

    if (depth[x] > depth[y]) swap(x, y);

    // INCLUDE LCA
    segment.range_update(0, 0, segment.tree.size()/4 - 1,positions[x], positions[y], z);
}


int node_query(int x, int y,
               Segment_Tree &segment,
               vector<int> &head,
               vector<int> &positions,
               vector<int> &parents,
               vector<int> &depth){

    int result = 0;

    while (head[x] != head[y]){
        if (depth[head[x]] < depth[head[y]]) swap(x, y);

        result += segment.query(
            0, 0, segment.tree.size()/4 - 1, positions[head[x]], positions[x]
        );

        x = parents[head[x]];
    }

    if (depth[x] > depth[y]) swap(x, y);

    // INCLUDE LCA
    result += segment.query(
        0, 0, segment.tree.size()/4 - 1, positions[x], positions[y]
    );

    return result;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adjlist(n + 1);
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    vector<int> parents(n + 1), depth(n + 1), heavy(n + 1, -1), head(n + 1), positions(n + 1), sizes(n + 1);

    dfs1(1, 0, adjlist, parents, depth, heavy, sizes);
    dfs2(1, 1, adjlist, parents, heavy, head, positions);

    Segment_Tree segment(n);

    int q;
    cin >> q;
    while (q--){
        int operation, x, y, z;
        cin >> operation >> x >> y;
        if (operation == 1){
            cin >> z;
            node_update(x, y, z, segment, head, positions, parents, depth);
        } else if (operation == 2){
            cout << node_query(x, y, segment, head, positions, parents, depth) << "\n";
        }
    }

    return 0;
}
