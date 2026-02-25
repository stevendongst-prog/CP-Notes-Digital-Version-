int n, v;
cin >> n >> v;
vector<int> values(n);
for (int i = 0; i < n; i++) cin >> values[i];
sort(values.begin(), values.end());
vector<int> dp(v + 1, INT_MAX);
dp[0] = 0;

for (int x : values){
    for (int i = x; i <= v; i++){
        dp[i] = min(dp[i], dp[i - x] + 1);
    }
}

if (dp[v] == INT_MAX) cout << -1;
else cout << dp[v];
