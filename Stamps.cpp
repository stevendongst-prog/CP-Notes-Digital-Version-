int p, n;
cin >> p >> n;
vector<int> a(n + 1);
for (int i = 1; i <= n; i++) cin >> a[i];
vector<vector<pair<int,int>>> dp(n + 1, vector<pair<int,int>>(p + 1, {LLONG_MAX, 0}));
for (int i = 0; i <= n; i++) dp[i][0] = {0, 1};

for (int i = 1; i <= n; i++){
    for (int j = 1; j <= p; j++){
        // Option 1: Don't use stamp i
        dp[i][j] = dp[i - 1][j];

        // Option 2: Use stamp i
        if (j >= a[i] && dp[i][j - a[i]].first != LLONG_MAX){
            pair<int,int> take = {dp[i][j - a[i]].first + 1, dp[i][j - a[i]].second};
            if (take.first < dp[i][j].first){
                dp[i][j] = take;
            } else if (take.first == dp[i][j].first){
                dp[i][j].second += take.second;
            }
        }
    }
}

if (dp[n][p].first == LLONG_MAX){
    cout << -1 << "\n";
} else {
    cout << dp[n][p].first << "\n"; // Minimum number of stamps
    cout << dp[n][p].second; // Number of ways
}
