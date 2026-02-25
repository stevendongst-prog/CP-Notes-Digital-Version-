int N, K;
cin >> N >> K;
vector<int> choices(N + 1);

for (int i = 1; i <= N; i++){
    char c;
    cin >> c;
    if (c == 'R') choices[i] = 0;
    else if (c == 'P') choices[i] = 1;
    else choices[i] = 2;
}

vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(K + 1, vector<int>(3, 0)));
for (int i = 0; i <= K; i++){
    for (int j = 0; j < 3; j++) dp[0][i][j] = 0;
}

for (int i = 1; i <= N; i++){
    for (int j = 0; j <= K; j++){
        for (int k = 0; k < 3; k++){
            int W = 0;
            int opponent = choices[i];
            if (k == 0) {if (opponent == 2) W = 1;}
            else if (k == 1) {if (opponent == 0) W = 1;}
            else {if (opponent == 1) W = 1;}
            int best = dp[i-1][j][k];
            if (j != 0) 
                best = max({best, dp[i-1][j-1][0], dp[i-1][j-1][1], dp[i-1][j-1][2]});
            dp[i][j][k] = 0;
            if (j != 0) dp[i][j][k] = dp[i][j-1][k];
            dp[i][j][k] = max(dp[i][j][k], best + W);
        }
    }
}

cout << max({dp[N][K][0], dp[N][K][1], dp[N][K][2]});
