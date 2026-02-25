int n, e; // Number of nodes and edges respectively
cin >> n >> e;
vector<vector<int>> adjlist(n);

for (int i = 0; i < e; i++){
    int a, b;
    cin >> a >> b;
    adjlist[a - 1].push_back(b - 1); // a, b are 1-indexed
    adjlist[b - 1].push_back(a - 1);
}

for (int i = 0; i < n; i++){
    for (int j = 0; j < adjlist[i].size(); j++){
        cout << adjlist[i][j] + 1 << " ";
    }
    cout << "\n";
}
