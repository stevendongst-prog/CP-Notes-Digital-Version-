int n, w;
cin >> n >> w;
vector<int> dp(w + 1, 0);

for (int i = 0; i < n; i++){
    int value, weight, copies;
    cin >> value >> weight >> copies;
    if (copies * weight >= w){ 
        // Unbounded case
        for (int j = weight; j <= w; j++){
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    } else { 
        // Bounded case
        int c = 1;
        while (copies > 0){
            int take = min(c, copies);
            for (int j = w; j >= weight * take; j--){
                dp[j] = max(dp[j], dp[j - weight * take] + value * take);
            }
            copies -= take;
            c <<= 1;
        }
    }
}

cout << dp[w];
