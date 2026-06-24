struct Segment_Tree{
    int H, W;
    vector<vector<int>> tree, lazy;
    Segment_Tree(int h, int w) : H(h), W(w){
        tree.assign(4 * H, vector<int>(4 * W, 0));
        lazy.assign(4 * H, vector<int>(4 * W, 0));
    }

    void push_y(int node_x, int node_y, int start_y, int end_y){
        if (lazy[node_x][node_y] != 0){
            tree[node_x][node_y] += (end_y - start_y + 1) * lazy[node_x][node_y];
            if (start_y != end_y){
                lazy[node_x][2*node_y+1] += lazy[node_x][node_y];
                lazy[node_x][2*node_y+2] += lazy[node_x][node_y];
            }
            lazy[node_x][node_y] = 0;
        }
    }
    
    void pull_y(int node_x, int node_y){
        tree[node_x][node_y] = tree[node_x][2*node_y+1] + tree[node_x][2*node_y+2];
    }
    
    void range_update_y(int node_x, int node_y, int start_y, int end_y, 
                        int l_y, int r_y, int value){
        push_y(node_x, node_y, start_y, end_y);
        if (r_y < start_y || end_y < l_y) return;
        if (l_y <= start_y && end_y <= r_y){
            lazy[node_x][node_y] += value;
            push_y(node_x, node_y, start_y, end_y);
            return;
        }
        int mid_y = (start_y + end_y) / 2;
        range_update_y(node_x, 2*node_y+1, start_y, mid_y, l_y, r_y, value);
        range_update_y(node_x, 2*node_y+2, mid_y+1, end_y, l_y, r_y, value);
        pull_y(node_x, node_y);
    }

    int query_y(int node_x, int node_y, int start_y, int end_y, int l_y, int r_y){
        if (r_y < start_y || end_y < l_y) return 0;
        if (l_y <= start_y && end_y <= r_y) return tree[node_x][node_y];
        int mid_y = (start_y + end_y) / 2;
        return query_y(node_x, node_y*2+1, start_y, mid_y, l_y, r_y)
             + query_y(node_x, node_y*2+2, mid_y+1, end_y, l_y, r_y);
    }
    
    void range_update_x(int node_x, int start_x, int end_x, 
                        int l_x, int r_x, int l_y, int r_y, int value){
        if (r_x < start_x || end_x < l_x) return;
        if (l_x <= start_x && end_x <= r_x){
            range_update_y(node_x, 0, 0, W - 1, l_y, r_y, value);
            return;
        }
        int mid_x = (start_x + end_x) / 2;
        range_update_x(2*node_x+1, start_x, mid_x, l_x, r_x, l_y, r_y, value);
        range_update_x(2*node_x+2, mid_x+1, end_x, l_x, r_x, l_y, r_y, value);
        for (int node_y = 0; node_y < 4 * W; node_y++){
            tree[node_x][node_y] = tree[2*node_x+1][node_y] + tree[2*node_x+2][node_y];
        }
    }
    
    int query_x(int node_x, int start_x, int end_x, int l_x, int r_x, int l_y, int r_y){
        if (r_x < start_x || end_x < l_x) return 0;
        if (l_x <= start_x && end_x <= r_x) return query_y(node_x, 0, 0, W - 1, l_y, r_y);
        int mid_x = (start_x + end_x) / 2;
        return query_x(node_x*2+1, start_x, mid_x, l_x, r_x, l_y, r_y)
             + query_x(node_x*2+2, mid_x+1, end_x, l_x, r_x, l_y, r_y);
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int H, W, q;
    cin >> H >> W >> q;
    vector<vector<int>> matrix(H, vector<int>(W));
    Segment_Tree segment(H, W);
    segment.build_x(matrix, 0, 0, H - 1);
    while (q--){
        int operation;
        cin >> operation;
        if (operation == 1){
            int x1, y1, x2, y2, value;
            cin >> x1 >> y1 >> x2 >> y2 >> value;
            segment.range_update_x(0, 0, H - 1, x1, x2, y1, y2, value);
        } else if (operation == 2){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << segment.query_x(0, 0, H - 1, x1, x2, y1, y2) << "\n";
        }
    }
    
    return 0;
}
