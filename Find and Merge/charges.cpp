#include <bits/stdc++.h>
using namespace std;

vector<int> parent, parity;

int find(int x){
    if (parent[x] != x){
        int original_parent = parent[x];
        parent[x] = find(parent[x]);
        parity[x] ^= parity[original_parent];
    }
    return parent[x];
}

void merge(int a, int b, int relation){
    int rep_a = find(a);
    int rep_b = find(b);
    int parity_a = parity[a];
    int parity_b = parity[b];
    parent[rep_b] = rep_a;
    parity[rep_b] = parity_a ^ parity_b ^ relation;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    parity.resize(n + 1);
    
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        parity[i] = 0;
    }
    
    for (int i = 0; i < q; i++){
        char event_type;
        int a, b;
        cin >> event_type >> a >> b;
        if (event_type == 'A') merge(a, b, 1);
        else if (event_type == 'R') merge(a, b, 0);
        else {
            int rep_a = find(a);
            int rep_b = find(b);
            if (rep_a != rep_b) cout << "?" << "\n";
            else {
                int answer = parity[a] ^ parity[b];
                if (answer == 0) cout << "R" << "\n";
                else cout << "A" << "\n";
            }
        }
    }
    
    return 0;
}
