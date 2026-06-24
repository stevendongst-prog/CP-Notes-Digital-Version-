#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Segment_Tree{
    vector<int> tree, lazy;
    Segment_Tree(int size){
        tree.assign(size * 4, 0);
        lazy.assign(size * 4, 0);
    }

    void build(vector<int> &array, int node, int start, int end){
        if (start == end){
            tree[node] = array[start];
        } else {
            int mid = (start + end) / 2;
            build(array, 2 * node + 1, start, mid);
            build(array, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void push(int node, int start, int end){
        if (lazy[node] != 0){
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end){
                lazy[node * 2 + 1] += lazy[node];
                lazy[node * 2 + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void range_update(int node, int start, int end, int l, int r, int value){
        push(node, start, end);
        if (r < start || end < l) return;
        if (l <= start && end <= r){
            lazy[node] += value;
            push(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        range_update(2 * node + 1, start, mid, l, r, value);
        range_update(2 * node + 2, mid + 1, end, l, r, value);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int node, int start, int end, int l, int r){
        push(node, start, end);
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(node * 2 + 1, start, mid, l, r) + 
               query(node * 2 + 2, mid + 1, end, l, r);
    }
};
