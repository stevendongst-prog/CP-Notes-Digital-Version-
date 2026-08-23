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
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    void point_update(int node, int start, int end, int index, int value){
        if (start == end){
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (index <= mid) point_update(2 * node + 1, start, mid, index, value);
            else point_update(2 * node + 2, mid + 1, end, index, value);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int query(int node, int start, int end, int l, int r){
        if (r < start || end < l) return LLONG_MAX; // completely outside
        if (l <= start && end <= r) return tree[node]; // completely inside
        int mid = (start + end) / 2;
        return min(
            query(2 * node + 1, start, mid, l, r), 
            query(2 * node + 2, mid + 1, end, l, r)
        );
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> array(n); // 0-indexed array
    Segment_Tree segment(n);
    segment.build(array, 0, 0, n - 1);

    while (q--){
        int operation, x, y;
        cin >> operation >> x >> y;
        if (operation == 1){
            segment.point_update(0, 0, n - 1, x, y);
        } else if (operation == 2){
            cout << segment.query(0, 0, n - 1, x, y) << '\n';
        }
    }
    
    return 0;
}
