struct Sparse_Table{
    vector<int> log_2_table;
    vector<vector<int>> sparse_table;

    Sparse_Table(const vector<int> &A){
        int n = A.size();
        log_2_table.resize(n + 1);
        log_2_table[1] = 0;
        for (int i = 2; i <= n; i++) log_2_table[i] = log_2_table[i / 2] + 1;
        int k = log_2_table[n];
        sparse_table.resize(k + 1, vector<int>(n));
        for (int i = 0; i < n; i++) sparse_table[0][i] = A[i];
        for (int j = 1; j <= k; j++){
            for (int i = 0; i + (1 << j) <= n; i++){
                sparse_table[j][i] = 
                    min(sparse_table[j - 1][i], sparse_table[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int query(int l, int r){
        int length = log_2_table[r - l + 1];
        return min(sparse_table[length][l], sparse_table[length][r - (1 << length) + 1]);
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    Sparse_Table sparse(A);
    while (q--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << sparse.query(l, r) << "\n";
    }

    return 0;
}
