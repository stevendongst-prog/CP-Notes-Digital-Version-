struct Segment_Tree{
    vector<int> tree;
    Segment_Tree(int size){
        tree.assign(size * 4, 0);
    }
    
    void build(vector<int> &frequency, int node, int start, int end){
        if (start == end){
            tree[node] = frequency[start];
        } else {
            int mid = (start + end) / 2;
            build(frequency, 2 * node + 1, start, mid);
            build(frequency, 2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    // Insert range maximum query function here.
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> array(n), left(n), right(n), frequency(n);
    Segment_Tree segment(n);
    for (int i = 0; i < n; i++) cin >> array[i];

    for (int i = 0; i < n; i++){
        if (i == 0 || array[i] != array[i - 1]) left[i] = i;
        else left[i] = left[i - 1];
    }

    for (int i = n - 1; i >= 0; i--){
        if (i == n - 1 || array[i] != array[i + 1]) right[i] = i;
        else right[i] = right[i + 1];
    }

    for (int i = 0; i < n; i++) frequency[i] = right[i] - left[i] + 1;
    segment.build(frequency, 1, 0, n - 1);

    while (q--){
        int l, r;
        cin >> l >> r;
        if (array[l] == array[r]){
            cout << r - l + 1 << "\n";
            continue;
        }
        int lp = right[l] - l + 1;
        int rp = r - left[r] + 1;

        int mid_max = 0;
        if (right[l] + 1 <= left[r] - 1){
            mid_max = segment.query(1, 0, n - 1, right[l] + 1, left[r] - 1);
        }
        cout << max({lp, rp, mid_max}) << "\n";
    }

    return 0;
}
