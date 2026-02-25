int n, target;
cin >> n >> target;
vector<int> array(n);
for (int i = 0; i < n; i++) cin >> array[i];
int low = 0, high = n - 1, result = -1;
while (low <= high){
    int mid = low + (high - low) / 2;
    if (array[mid] == target){
        result = mid; // Target found.
        break;
    } else if (array[mid] < target){
        low = mid + 1; // Search right half.
    } else {
        high = mid - 1; // Search left half.
    }
}
    
cout << result; // Returns -1 if target not found.
