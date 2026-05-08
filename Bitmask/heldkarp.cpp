int Held_Karp_Algorithm(int n, vector<vector<pair<int,int>>> &adjlist){
    int FULL = 1 << n;
    vector<vector<int>> dp(n, vector<int>(FULL, INT_MAX));

    for (int i = 0; i < n; i++) dp[i][1 << i] = 0; // Base case

    // Iterate over all masks.
    for (int mask = 1; mask < FULL; mask++){
        for (int j = 0; j < n; j++){
            if (!(mask & (1 << j))) continue;
            if (dp[j][mask] == INT_MAX) continue;

            // Try extending path from j to its neighbors.
            for (auto [i, w] : adjlist[j]){
                if (mask & (1 << i)) continue;  // Already visited
                int next_mask = mask | (1 << i);
                dp[i][next_mask] = min(dp[i][next_mask], dp[j][mask] + w);
            }
        }
    }

    int answer = INT_MAX;
    for (int i = 0; i < n; i++) answer = min(answer, dp[i][FULL - 1]);

    return answer;
}
