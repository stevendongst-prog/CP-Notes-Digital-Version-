struct Node{
    int max1, max2, min1, min2;
    Node(){max1 = max2 = LLONG_MIN; min1 = min2 = LLONG_MAX;}
    Node(int x){
        max1 = x; max2 = LLONG_MIN;
        min1 = x; min2 = LLONG_MAX;
    }
};

Node merge(const Node &a, const Node &b){
    Node result;
    vector<int> maxs = {a.max1, a.max2, b.max1, b.max2};
    sort(maxs.begin(), maxs.end(), greater<int>());
    result.max1 = maxs[0]; result.max2 = maxs[1];
    vector<int> mins = {a.min1, a.min2, b.min1, b.min2};
    sort(mins.begin(), mins.end());
    result.min1 = mins[0]; result.min2 = mins[1];
    return result;
}

struct Segment_Tree{
    vector<Node> tree;
    Segment_Tree(int size){
        tree.assign(size * 4, 0);
    }
    
    void build(vector<int> &array, int node, int start, int end){
        if (start == end){
            tree[node] = Node(array[start]);
        } else {
            int mid = (start + end) / 2;
            build(array, 2 * node + 1, start, mid);
            build(array, 2 * node + 2, mid + 1, end);
            tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void point_update(int node, int start, int end, int index, int value){
        if (start == end){
            tree[node] = Node(value);
        } else {
            int mid = (start + end) / 2;
            if (index <= mid) point_update(2 * node + 1, start, mid, index, value);
            else point_update(2 * node + 2, mid + 1, end, index, value);
            tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    Node query_node(int node, int start, int end, int l, int r){
        if (r < start || end < l) return Node();
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return merge(
            query_node(2 * node + 1, start, mid, l, r), 
            query_node(2 * node + 2, mid + 1, end, l, r)
        );
    }

    int query(int n, int l, int r){
        Node result = query_node(1, 1, n, l, r);
        return max(result.max1 * result.max2, result.min1 * result.min2);
    }
};
