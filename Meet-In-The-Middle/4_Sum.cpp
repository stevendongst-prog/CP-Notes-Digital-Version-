int a, b, c, d;
cin >> a >> b >> c >> d;
vector<int> A(a), B(b), C(c), D(d);
for (int i = 0; i < a; i++) cin >> A[i];
for (int i = 0; i < b; i++) cin >> B[i];
for (int i = 0; i < c; i++) cin >> C[i];
for (int i = 0; i < d; i++) cin >> D[i];
int AB = 1LL * a * b;
int CD = 1LL * c * d;

if (AB <= CD){
    // Store A + B, Search C + D
    unordered_map<int, pair<int,int>> m;
    m.reserve(AB * 2);
    
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++) m[A[i] + B[j]] = make_pair(i, j);
    }
    
    for (int k = 0; k < c; k++){
        for (int l = 0; l < d; l++){
            int target = -(C[k] + D[l]);
            if (m.count(target)){
                auto [i, j] = m[target];
                cout << A[i] << " " << B[j] << " " << C[k] << " " << D[l];
                return 0;
            }
        }
    }
} else {
    // Store C + D, Search A + B
    unordered_map<int, pair<int,int>> m;
    m.reserve(CD * 2);
    
    for (int k = 0; k < c; k++){
        for (int l = 0; l < d; l++) m[C[k] + D[l]] = make_pair(k, l);
    }
    
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            int target = -(A[i] + B[j]);
            if (m.count(target)){
                auto [k, l] = m[target];
                cout << A[i] << " " << B[j] << " " << C[k] << " " << D[l];
                return 0;
            }
        }
    }
}
