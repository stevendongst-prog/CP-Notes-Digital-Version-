int dp[20][2][2];
string s;

int digit_dp(int position, int previous_1, int tight){
    if (position == s.size()) return 1;
    int &result = dp[position][previous_1][tight];
    if (result != -1) return result;
    result = 0;
    int limit = tight ? s[position] - '0' : 9;
    for (int d = 0; d <= limit; d++){
        if (d == 4) continue;
        if (previous_1 && d == 3) continue;
        int next_previous_1 = (d == 1);
        int next_tight = (tight && d == limit);
        result += digit_dp(position + 1, next_previous_1, next_tight);
    }
    return result;
}

bool valid(int x){
    string S = to_string(x);
    for (int i = 0; i < S.size(); i++){
        if (S[i] == '4') return false;
        if (i > 0 && S[i - 1] == '1' && S[i] == '3') return false;
    }
    return true;
}

int valid_numbers(int x){
    if (x <= 0) return 0;
    s = to_string(x);
    memset(dp, -1, sizeof(dp)); // Set all elements to -1.
    return digit_dp(0, 0, 1) - 1; // Omit the number 0.
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    while (N--){
        int query, x;
        cin >> query >> x;
        if (query == 1){
            if (!valid(x)) cout << -1 << "\n";
            else cout << valid_numbers(x) << "\n";
        } else if (query == 2){
            int low = 1, high = 1e17, answer = -1;
            while (low <= high){
                int mid = low + (high - low) / 2;
                if (valid_numbers(mid) >= x){
                    answer = mid;
                    high = mid - 1;
                } else low = mid + 1;
            }
            cout << answer << "\n";
        }
    }

    return 0;
}
