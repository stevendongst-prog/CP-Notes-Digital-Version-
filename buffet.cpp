int n; // Number of dishes on each table
int k; // Decrease in value when switching tables
cin >> n >> k;
vector<int> table1(n, 0)
vector<int> table2(n, 0);
for (int i = 0; i < n; i++) cin >> table1[i];
for (int i = 0; i < n; i++) cin >> table2[i];
vector<int> option1(n), option2(n);
option1[0] = table1[0];
option2[0] = table2[0];

for (int i = 1; i < n; i++){
    option1[i] = max(option1[i - 1], option2[i - 1] - k) + table1[i];
    option2[i] = max(option2[i - 1], option1[i - 1] - k) + table2[i];
}

cout << max(option1[n - 1], option2[n - 1]);
