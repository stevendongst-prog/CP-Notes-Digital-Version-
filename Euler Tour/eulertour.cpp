// Entry & Exit Time
int timer = 0;
vector<int> entrytime, exittime;

void dfs(int v, int parent){
    entrytime[v] = ++timer;
    for (int neighbour : adjlist[v]){
        if (neighbour == parent) continue;
        dfs(neighbour, v);
    }
    exittime[v] = timer;
}

// Full Tour
vector<int> euler, depth, first;

void dfs(int v, int parent, int d){
    depth[v] = d;
    first[v] = euler.size();
    euler.push_back(v);
    for (int neighbour : adjlist[v]){
        if (neighbour == parent) continue;
        dfs(neighbour, v, d + 1);
        euler.push_back(v);
    }
}

// Flattened Tree
int timer = 0;
vector<int> entrytime, exittime, flat;

void dfs(int v, int parent){
    entrytime[v] = timer;
    flat[timer++] = v;
    for (int neighbour : adjlist[v]){
        if (neighbour == parent) continue;
        dfs(neighbour, v);
    }
    exittime[v] = timer - 1;
}
