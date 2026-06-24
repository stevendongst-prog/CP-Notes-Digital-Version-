struct Segment_Tree{
    int H, W;
    vector<vector<int>> tree;
    Segment_Tree(int h, int w) : H(h), W(w){
        tree.assign(4 * H, vector<int>(4 * W, 0));
    }

    void build_y(vector<vector<int>> &matrix, int node_x, int start_x, int end_x,
                 int node_y, int start_y, int end_y){
        if (start_y == end_y){
            if (start_x == end_x) tree[node_x][node_y] = matrix[start_x][start_y];
            else tree[node_x][node_y] = tree[node_x*2+1][node_y] + tree[node_x*2+2][node_y];
        } else {
            int mid_y = (start_y + end_y) / 2;
            build_y(matrix, node_x, start_x, end_x, node_y*2+1, start_y, mid_y);
            build_y(matrix, node_x, start_x, end_x, node_y*2+2, mid_y+1, end_y);
            tree[node_x][node_y] = tree[node_x][node_y*2+1] + tree[node_x][node_y*2+2];
        }
    }
    
    void build_x(vector<vector<int>> &matrix, int node_x, int start_x, int end_x){
        if (start_x != end_x){
            int mid_x = (start_x + end_x) / 2;
            build_x(matrix, node_x*2+1, start_x, mid_x);
            build_x(matrix, node_x*2+2, mid_x+1, end_x);
        }
        build_y(matrix, node_x, start_x, end_x, 0, 0, W - 1);
    }

    void point_update_y(int node_x, int start_x, int end_x,
                        int node_y, int start_y, int end_y,
                        int x, int y, int value){
        if (start_y == end_y){
            if (start_x == end_x) tree[node_x][node_y] += value;
            else tree[node_x][node_y] = tree[node_x*2+1][node_y] + tree[node_x*2+2][node_y];
        } else {
            int mid_y = (start_y + end_y) / 2;
            if (y <= mid_y) 
                point_update_y(node_x, start_x, end_x, node_y*2+1, start_y, mid_y, x, y, value);
            else 
                point_update_y(node_x, start_x, end_x, node_y*2+2, mid_y+1, end_y, x, y, value);
            tree[node_x][node_y] = tree[node_x][node_y*2+1] + tree[node_x][node_y*2+2];
        }
    }
    
    void point_update_x(int node_x, int start_x, int end_x, int x, int y, int value){
        if (start_x != end_x){
            int mid_x = (start_x + end_x) / 2;
            if (x <= mid_x) point_update_x(node_x*2+1, start_x, mid_x, x, y, value);
            else point_update_x(node_x*2+2, mid_x+1, end_x, x, y, value);
            point_update_y(node_x, start_x, end_x, 0, 0, W - 1, x, y, value);
        }
    }

    int query_y(int node_x, int node_y, int start_y, int end_y, int l_y, int r_y){
        if (r_y < start_y || end_y < l_y) return 0;
        if (l_y <= start_y && end_y <= r_y) return tree[node_x][node_y];
        int mid_y = (start_y + end_y) / 2;
        return query_y(node_x, node_y*2+1, start_y, mid_y, l_y, r_y)
             + query_y(node_x, node_y*2+2, mid_y+1, end_y, l_y, r_y);
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
            int x, y, value;
            cin >> x >> y >> value;
            segment.point_update_x(0, 0, H - 1, x, y, value);
        } else if (operation == 2){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << segment.query_x(0, 0, H - 1, x1, x2, y1, y2) << "\n";
        }
    }
    
    return 0;
}
