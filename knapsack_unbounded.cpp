int n, w;
cin >> n >> w;
vector<int> weights(n);
vector<int> values(n);
for (int i = 0; i < n; i++) cin >> weights[i] >> values[i];
vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

for (int i = 1; i < n + 1; i++){
    for (int j = 0; j < w + 1; j++){
        dp[i][j] = dp[i - 1][j];
        if (weights[i - 1] <= j){
            dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
        }
    }
}

cout << dp[n][w];
