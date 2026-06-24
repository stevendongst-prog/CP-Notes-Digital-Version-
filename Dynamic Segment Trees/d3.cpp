#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node{
    int sum = 0, lazy = 0;
    Node *left = nullptr, *right = nullptr;
};

class Segment_Tree{
public:
    Node* root;
    Segment_Tree(int size){
        root = new Node();
    }

    void apply(Node* node, int start, int end, int value){
        node -> sum += (end - start + 1) * value;
        node -> lazy += value;
    }

    void push(Node* node, int start, int end){
        if (node -> lazy == 0 || start == end) return;
        int mid = (start + end) / 2;
        if (!node -> left) node -> left = new Node();
        if (!node -> right) node -> right = new Node();
        apply(node -> left, start, mid, node -> lazy);
        apply(node -> right, mid + 1, end, node -> lazy);
        node -> lazy = 0;
    }

    void range_update(Node* node, int start, int end, int l, int r, int value){
        if (r < start || end < l) return;
        if (l <= start && end <= r){
            apply(node, start, end, value);
            return;
        }
        push(node, start, end);
        int mid = (start + end) / 2;
        if (!node -> left) node -> left = new Node();
        if (!node -> right) node -> right = new Node();
        range_update(node -> left, start, mid, l, r, value);
        range_update(node -> right, mid + 1, end, l, r, value);
        node -> sum = node -> left -> sum + node -> right -> sum;
    }

    int query(Node* node, int start, int end, int l, int r){
        if (!node || r < start || end < l) return 0;
        if (l <= start && end <= r) return node -> sum;
        push(node, start, end);
        int mid = (start + end) / 2;
        return query(node -> left, start, mid, l, r) + 
               query(node -> right, mid + 1, end, l, r);
    }
};
