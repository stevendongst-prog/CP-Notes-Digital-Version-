int n, k;
cin >> n >> k;
vector<int> array(n);
for (int i = 0; i < n; i++) cin >> array[i];
int left = 0, right = 0, sum = 0, max_length = 0;
while (right < n){
    sum += array[right];
    while (sum > k){
        sum -= array[left];
        left++;
    }
    max_length = max(max_length, right - left + 1);
    right++;
}
