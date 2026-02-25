#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<double> A(n); // Length of each individual log
    for (int i = 0; i < n; i++) cin >> A[i];
    double low = 0, high = *(max_element(A.begin(), A.end()));
	
    auto valid = [&](double mid){
        int cuts = 0;
        for (double a : A){
            cuts += ceil(a / mid) - 1;
            if (cuts > k) return false;
        }
        return cuts <= k;
    };

    // BSTA with high precision
    for (int i = 0; i < 100; i++){
        double mid = (low + high) / 2.0;
        if (valid(mid)) high = mid;
        else low = mid;
    }
	
    cout << (long long)ceil(high);

    return 0;
}
