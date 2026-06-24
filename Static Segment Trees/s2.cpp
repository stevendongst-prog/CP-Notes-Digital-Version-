#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Segment_Tree{
    vector<int> tree;
    Segment_Tree(int size){
        tree.assign(size * 4, 0);
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
    
    void point_update(int node, int start, int end, int index, int value){
        if (start == end){
            tree[node] += value;
        } else {
            int mid = (start + end) / 2;
            if (index <= mid) point_update(2 * node + 1, start, mid, index, value);
            else point_update(2 * node + 2, mid + 1, end, index, value);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    
    int query(int node, int start, int end, int l, int r){
        if (r < start || end < l) return 0; // completely outside
        if (l <= start && end <= r) return tree[node]; // completely inside
        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, l, r) + 
               query(2 * node + 2, mid + 1, end, l, r);
    }
};
