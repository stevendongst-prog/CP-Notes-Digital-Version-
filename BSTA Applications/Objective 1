int n, k;
cin >> n >> k;
vector<int> array(n);
for (int i = 0; i < n; i++) cin >> array[i]; // Array in non-decreasing order
auto valid = [&](int mid){return array[mid] > k;};
int low = 0, high = n - 1, answer = -1;

while (low <= high){
    int mid = low + (high - low) / 2;
    if (valid(mid)){
        answer = mid;
        high = mid - 1;
    } else {
        low = mid + 1;
    }
}

if (answer == -1) cout << -1;
else cout << answer << " " << array[answer];
