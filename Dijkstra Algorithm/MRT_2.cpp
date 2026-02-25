int n, m;
cin >> n >> m;

vector<int> t(n + 1);
for (int i = 1; i <= n; i++) cin >> t[i];
t[1] = 0; t[n] = 0;
vector<int> central(n + 1);
for (int i = 1; i <= n; i++) central[i] = i;
vector<vector<int>> nodes(n + 1);  
vector<tuple<int,int,int>> edges; 
int next_node = n + 1;
vector<vector<int>> platforms; // Stores sequences of stations visited for each MRT line.

for (int i = 0; i < m; i++){
    int s; 
    cin >> s;
    vector<int> stations(s), durations(s - 1);
    for (int j = 0; j < s; j++) cin >> stations[j];
    for (int j = 0; j < s - 1; j++) cin >> durations[j];
    vector<int> current_platforms(s);
    
    for (int j = 0; j < s; j++){
        int station = stations[j];
        int node = next_node++;
        nodes[station].push_back(node);
        current_platforms[j] = node;
    }
    platforms.push_back(current_platforms);
    
    // Constructing edges for every consecutive platform node
    for (int j = 0; j < s - 1; j++){
        edges.push_back({current_platforms[j], current_platforms[j + 1], durations[j]});
        edges.push_back({current_platforms[j + 1], current_platforms[j], durations[j]});
    }
}

// Connecting platform nodes to central node for every station
for (int i = 1; i <= n; i++){
    for (int p : nodes[i]){
        edges.push_back({p, central[i], 0});
        edges.push_back({central[i], p, t[i]});
    }
}

// Building final adjacency list
int total = next_node - 1;
vector<vector<pair<int,int>>> adjlist(total + 1);
for (auto &e : edges){
    int u, v, w;
    tie(u, v, w) = e;
    adjlist[u].push_back(make_pair(v, w));
}

vector<int> distance = Dijkstra_Algorithm(1, adjlist.size(),  adjlist);
if (distance[central[n]] == LLONG_MAX) cout << -1;
else cout << distance[central[n]];
