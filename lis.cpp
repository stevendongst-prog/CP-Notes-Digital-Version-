int n;
cin >> n;
vector<int> array(n);

for (int i = 0; i < n; i++) cin >> array[i];
vector<int> LIS;

for (int i = 0; i < n; i++){
    auto it = lower_bound(LIS.begin(), LIS.end(), array[i]);
    if (it == LIS.end()) LIS.push_back(array[i]);
    else *it = array[i];
}

cout << LIS.size();
