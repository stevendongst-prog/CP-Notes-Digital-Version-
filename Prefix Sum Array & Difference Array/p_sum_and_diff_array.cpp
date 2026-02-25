int n;
cin >> n;
vector<int> array(n);

for (int i = 0; i < n; i++) cin >> array[i];

vector<int> prefix(n + 1);  // prefix[0] = 0
for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + array[i];

vector<int> difference;
for (int i = 1; i < n; i++) difference.push_back(array[i] - array[i - 1]);
