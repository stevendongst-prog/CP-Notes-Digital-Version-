#include <bits/stdc++.h>
#define int long long
using namespace std;

// For 1-indexed array

struct Fenwick_Tree{
    int n;
    vector<int> tree, array;
    Fenwick_Tree(int n) : n(n){
        tree.resize(n + 1);
        array.resize(n + 1);
    }

    void add(int i, int delta){
        for (; i <= n; i += i & -i) tree[i] += delta;
    }

    void point_update(int index, int value){
        int delta = value - array[index];
        array[index] = value;
        add(index, delta);
    }

    int prefix_sum(int i) const{
        int result = 0;
        for (; i > 0; i -= i & -i) result += tree[i];
        return result;
    }

    int query(int l, int r) const{
        if (l > r) return 0;
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};
