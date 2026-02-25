int n, k;
cin >> n >> k;

struct Interval{int l, r, v;};
vector<Interval> A(n);
for (int i = 0; i < n; i++) cin >> A[i].l >> A[i].r >> A[i].v;
int max_single = 0;
for (auto &x : A) max_single = max(max_single, x.v);

if (max_single >= k){cout << 1000000000; return 0;}

sort(A.begin(), A.end(), [](auto &x, auto &y){
    return x.r < y.r;
});

vector<int> ends(n);
for (int i = 0; i < n; i++) ends[i] = A[i].r;

auto feasible = [&](int g){
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++){
        int take = A[i].v;
        int need = A[i].l - g;
        int j = upper_bound(ends.begin(), ends.begin() + i, need) - ends.begin() - 1;
        if (j >= 0) take += dp[j];
        dp[i] = max((i ? dp[i - 1] : 0LL), take);
    }
    return dp[n - 1] >= k;
};

if (!feasible(0)){
    cout << -1;
    return 0;
}

int low = 0, high = 0, result = 0;
for (auto &x : A) high = max(high, x.l);
for (auto &x : A) high = max(high, x.r);
while (low <= high){
    int mid = (low + high) / 2;
    if (feasible(mid)){
        result = mid;
        low = mid + 1;
    } else {
        high = mid - 1;
    }
}

cout << result;
