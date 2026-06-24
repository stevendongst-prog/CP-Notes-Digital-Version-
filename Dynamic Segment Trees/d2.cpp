#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node{
    int sum = 0;
    Node *left = nullptr, *right = nullptr;
};

class Segment_Tree{
public:
    Node* root;
    Segment_Tree(int size){
        root = new Node();
    }

    void point_update(Node* node, int start, int end, int index, int value){
        if (start == end){
            node -> sum += value;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid){
            if (!node -> left) node -> left = new Node();
            point_update(node -> left, start, mid, index, value);
        } else {
            if (!node -> right) node -> right = new Node();
            point_update(node -> right, mid + 1, end, index, value);
        }
        node -> sum = node -> left ? node -> left -> sum : LLONG_MAX + 
        node -> right ? node -> right -> sum : LLONG_MAX;
    }

    int query(Node* node, int start, int end, int l, int r){
        if (!node || start > r || end < l) return 0;
        if (start >= l && end <= r) return node -> sum;
        int mid = (start + end) / 2;
        return query(node -> left, start, mid, l, r) + 
               query(node -> right, mid + 1, end, l, r);
    }
};
