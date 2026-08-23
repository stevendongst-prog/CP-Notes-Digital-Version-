// Preorder
int timer = 0;
void dfs(int node, int parent, vector<vector<int>> &adjlist, vector<int> &preorder){
    preorder[node] = timer++;
    for (int neighbour : adjlist[node]){
        if (neighbour == parent) continue; 
        dfs(neighbour, node, adjlist, preorder); // Continue only for children.
    }
}

// End Order
int timer = 0;
void dfs(int node, int parent, vector<vector<int>> &adjlist, vector<int> &endorder){
    timer++;
    for (int neighbour : adjlist[node]){
        if (neighbour == parent) continue; 
        dfs(neighbour, node, adjlist, endorder); // Continue only for children.
    }
    endorder[node] = timer - 1;
}
