int lca(int x, int y){
    if (depth[x] < depth[y]) swap(x, y);
    x = kth_ancestor(x, depth[x] - depth[y]);
    if (x == y) return x; // Edge case: y is an ancestor of x.
    
    for (int k = 19; k >= 0; k--){
        if (twok[x][k] != twok[y][k]){
            x = twok[x][k];
            y = twok[y][k];
        }
    }
    
    return twok[x][0];
}

int lca_rooted(int r, int x, int y){
    int a = lca(x, y), b = lca(x, r), c = lca(y, r);
    if (a == b) return c;
    if (a == c) return b;
    return a;
}
