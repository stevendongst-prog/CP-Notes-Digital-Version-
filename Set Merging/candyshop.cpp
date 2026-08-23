#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> adjlist;
vector<int> cnt;
vector<set<int, greater<int>>> s;
int result;

void dfs(int v, int parent){
    for (int it : adjlist[v]){
        if (it == parent) continue;
        dfs(it, v);
        if (s[it].size() > s[v].size()) swap(s[it], s[v]);
        s[v].insert(s[it].begin(), s[it].end());
    }
    
    for (int i = 0;i < cnt[v]; i++) if (!s[v].empty()){
        result += *s[v].begin();
        s[v].erase(s[v].begin());
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++){
        int N, M, A, B;
        cin >> N >> M >> A >> B;
        adjlist.assign(N, {});
        cnt.assign(N, 0);
        s.resize(N);
        for (int i = 0; i < M; i++) cnt[(A * i + B) % N]++;

        for (int i = 1; i < N; i++){
            int p; cin >> p;
            adjlist[p].push_back(i);
        }

        result = 0;
        for (int i = 0; i < N; i++) s[i] = {i};
        dfs(0, -1);
        cout << result << "\n";
    }

    return 0;
}
