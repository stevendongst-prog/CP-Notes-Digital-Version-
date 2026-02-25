int n, v;
cin >> n >> v;
vector<int> values(n);
for (int i = 0; i < n; i++) cin >> values[i];
sort(values.begin(), values.end());
vector<int> dp(v + 1, 0);
dp[0] = 1;

for (int x : values){
    for (int i = x; i <= v; i++){
        dp[i] = (dp[i] + dp[i - x]) % 1000000007;
    }
}

cout << dp[v] % 1000000007;
