int n, k;
cin >> n >> k;
vector<int> array(n);

for (int i = 0; i < n; i++) cin >> array[i];

int current_sum = 0;
for (int i = 0; i < k; i++) current_sum += array[i];  // Initial sum of first k elements

int max_sum = current_sum;

// Slide the window from index k to n - 1.
for (int i = k; i < n; i++){
    current_sum += array[i] - array[i - k];
    max_sum = max(max_sum, current_sum);
}
