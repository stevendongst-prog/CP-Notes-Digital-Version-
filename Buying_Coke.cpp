int C, a, b, c;
cin >> C >> a >> b >> c;
int total = a + 5 * b + 10 * c;
vector<vector<vector<int>>> 
    dp(C + 1, vector<vector<int>>(b + C + 1, vector<int>(c + 1, INT_MAX)));

dp[0][b][c] = 0;
for (int k = 0; k < C; k++){
    for (int i = 0; i <= b + C; i++){
        for (int j = 0; j <= c; j++){
            int current = dp[k][i][j];
            if (current == INT_MAX) continue;
            int ones = total - 8 * k - 5 * i - 10 * j;
            if (ones < 0) continue;
            if (ones >= 8) dp[k+1][i][j] = min(dp[k+1][i][j], current + 8);
            if (i >= 1 && ones >= 3) dp[k+1][i-1][j] = min(dp[k+1][i-1][j], current + 4);
            if (j >= 1) dp[k+1][i][j-1] = min(dp[k+1][i][j-1], current + 1);
            if (i >= 2) dp[k+1][i-2][j] = min(dp[k+1][i-2][j], current + 2);
            if (j >= 1 && ones >= 3) 
                dp[k+1][i+1][j-1] = min(dp[k+1][i+1][j-1], current + 4);
        }
    }
}

int result = INT_MAX;
for (int i = 0; i <= b + C; i++){
    for (int j = 0; j <= c; j++){
        result = min(result, dp[C][i][j]);
    }
}

cout << result << "\n";
