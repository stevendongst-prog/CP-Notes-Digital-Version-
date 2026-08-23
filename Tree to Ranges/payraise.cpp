int timer = 0;
void dfs(int node, vector<vector<int>> &adjlist, vector<int> &preord, vector<int> &endord){
    preord[node] = timer++;
    for (int neighbour : adjlist[node]) dfs(neighbour, adjlist, preord, endord);
    endord[node] = timer - 1;
}

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
    
    int query(int node, int start, int end, int index){
        push(node, start, end);
        if (start == end) return tree[node];
        int mid = (start + end) / 2;
        if (index <= mid) return query(node * 2 + 1, start, mid, index);
        else return query(node * 2 + 2, mid + 1, end, index);
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<int> P(N), S(N);
    for (int i = 0; i < N; i++) cin >> P[i] >> S[i];
    vector<vector<int>> children(N);
    for (int i = 1; i < N; i++) children[P[i]].push_back(i);
    vector<int> preord(N), endord(N);
    dfs(0, children, preord, endord);
    vector<int> flat(N);
    for (int i = 0; i < N; i++) flat[preord[i]] = S[i];
    Segment_Tree segment(N);
    segment.build(flat, 0, 0, N - 1);

    while (Q--){
        int operation, x, d;
        cin >> operation >> x;
        if (operation == 0){
            cin >> d;
            segment.range_update(0, 0, N - 1, preord[x], endord[x], d);
        } else if (operation == 1){
            cout << segment.query(0, 0, N - 1, preord[x]) << "\n";
        }
    }
    
    return 0;
}
