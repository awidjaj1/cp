#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;


int getMex(int l, int r, const vi &a){
    int n = a.size() / 2;
    vector<bool> mex(n, false);
    while(l >= 0 && r < 2*n && a[l] == a[r]){
        mex[a[l]] = true;

        l--, r++;
    }

    for(int i = 0; i < n; i++){
        if(!mex[i]) return i;
    }

    return n;
}

/**
 * 0 is in the palindrome otherwise mex = 0
 * 
 * so we either have 1 or 2 0s.
 * 
 * If 1, then 0 must be the center,
 * If 2, the 0's must straddle the center.
 * 
 * So find both zeros, expand both as the center and then once as a straddle.
 * This is O(n) total where n <= 2*10^5
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n;
    while(t--){
        cin >> n;
        vi a(2*n);
        for(auto &x: a){
            cin >> x;
        }
        int l = 2*n, r = -1;
        for(int i = 0; i < 2*n; i++){
            if(a[i] == 0){
                l = min(i, l);
                r = max(i, r);
            }
        }

        cout << max(max(getMex(l,l,a), getMex(r,r,a)), getMex((l+r)/2, (l+r+1)/2, a)) << endl;        
    }

    return 0;
}