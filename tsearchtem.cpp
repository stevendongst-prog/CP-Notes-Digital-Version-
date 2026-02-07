int n;
cin >> n;
vector<int> array(n);
for (int i = 0; i < n; i++) cin >> array[i];
int low = 0, high = n - 1;
while (high - low > 2){
    int mid1 = low + (high - low) / 3;
    int mid2 = high - (high - low) / 3;
    if (array[mid1] < array[mid2]){
        // Peak is in the range [mid1 + 1, high].
        low = mid1 + 1;
    } else {
        // Peak is in the range [low, mid2 - 1].
        high = mid2 - 1;
    }
}

// Final brute-force over remaining few elements.
int peak = low;
for (int i = low + 1; i <= high; i++){
    if (array[i] > array[peak]) peak = i;
}

cout << peak;
