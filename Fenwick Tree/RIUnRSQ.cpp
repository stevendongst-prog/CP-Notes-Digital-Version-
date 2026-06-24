#include <bits/stdc++.h>
#define int long long
using namespace std;

// For 1-indexed array

struct Fenwick_Tree{
    int n;
    vector<int> tree1, tree2;
    Fenwick_Tree(int n) : n(n){
        tree1.resize(n + 1);
        tree2.resize(n + 1);
    }

    void add(vector<int> &tree, int i, int delta){
        for (; i <= n; i += i & -i) tree[i] += delta;
    }

    int sum(vector<int> &tree, int i) const{
        int result = 0;
        for (; i > 0; i -= i & -i) result += tree[i];
        return result;
    }

    void range_update(int l, int r, int value){
        add(tree1, l, value);
        add(tree1, r + 1, -value);
        add(tree2, l, value * (l - 1));
        add(tree2, r + 1, -value * r);
    }

    int prefix_sum(int i) const{
        return sum(tree1, i) * i - sum(tree2, i);
    }

    int query(int l, int r) const{
        if (l > r) return 0;
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};
