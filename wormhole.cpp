int n; // Number of nodes
int w; // Number of wormholes
cin >> n >> w;
map<int, vector<int>> teleportation;

for (int i = 0; i < w; i++){
    int x, y;
    cin >> x >> y;
    teleportation[y].push_back(x);
}

vector<int> dp(n, LLONG_MAX);
dp[0] = 0;
for (int i = 1; i < n; i++){
    dp[i] = dp[i - 1] + 1;
    if (teleportation.count(i) != 0){
        for (int x : teleportation[i]){
            if (x >= 0 && x < n) dp[i] = min(dp[i], dp[x] + 1);
        }
    }
}

cout << dp[n - 1]; // Outputs the minimum time taken from node 0 to node n - 1.
