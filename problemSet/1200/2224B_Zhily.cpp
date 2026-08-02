#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

/**
 * max and mex are monotonically increasing
 * 
 * for mex you want the array "sorted" aggressively upfront
 * for max you can move the last element to the front
 * 
 * for max moving the last element to the front gives you +x * n 
 * which reduces mex by 1 at most in each subq step so total -(n-1) or -1 * (n-1)
 * 
 * so moving max to the front is always a net positive 
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n;
    while(t--){
        cin >> n;

        vll a(n);

        ll mx = 0;
        unordered_set<ll> seen;
        for(auto &x: a){
            cin >> x;
            mx = max(mx, x);
            seen.insert(x);
        }

        ll res = mx * n;
        ll mex = 0;
        for(int i = 0; i < n; i++){
            if(i == 0){
                mex += mx == mex;
            }else{
                mex += seen.count(mex);
                // couldve increased to mx
                mex += mx == mex;
            }

            res += mex;
        }

        cout << res << endl;
        
    }

    return 0;
}