struct Segment_Tree{
    vector<int> tree;
    Segment_Tree(int size){
        tree.assign(size * 4, 0);
    }
    
    void build(vector<int> &divisor_sieve, int node, int start, int end){
        if (start == end){
            tree[node] = divisor_sieve[start];
        } else {
            int mid = (start + end) / 2;
            build(divisor_sieve, 2 * node + 1, start, mid);
            build(divisor_sieve, 2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int node, int start, int end, int l, int r){
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return max(
            query(2 * node + 1, start, mid, l, r), 
            query(2 * node + 2, mid + 1, end, l, r)
        );
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<pair<int,int>> queries(q);
    Segment_Tree segment(n);
    for (int i = 0; i < q; i++) cin >> queries[i].first >> queries[i].second;
    vector<int> divisor_sieve(n);

    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j += i) divisor_sieve[j]++;
    }

    segment.build(divisor_sieve, 1, 1, n);

    for (auto &[l, r] : queries){
        cout << segment.actual_query(1, 1, n, l, r) << "\n";
    }

    return 0;
}
