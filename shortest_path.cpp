int H, W; // Dimensions of the grid
int n; // Number of blocked nodes
cin >> H >> W >> n;

vector<vector<int>> dp(H, vector<int>(W, 0));
dp[0][0] = 1;

for (int i = 0; i < n; i++){
    int x, y;
    cin >> x >> y; // Coordinates of blocked nodes
    dp[x][y] = -1;
}

for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
        if (dp[i][j] == -1){
            dp[i][j] = 0;
            continue;
        }
        if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % 1000000007;
        if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % 1000000007;
    }
}

cout << dp[H - 1][W - 1];
