#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;


// WLOG assume x = 1
// require 2 flips per group of zeros
// 1 to flip the left/right most zero(s)
// 1 to restore any 1s in the process
// can split this process into 2: the left side, and the right side
// each process will take a multiple of 2 flips (hence we know the special index is restored)
// the minimum operations runs each process in parallel
// so it will be the maximum of both proccesses
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n, k, i;
    while(t--){
        cin >> n;
        //in this version of the problem k := 1
        cin >> k;
        
        vi a(n);
        for(auto &x: a){
            cin >> x;
        }

        // get the 1 special index
        cin >> i;
        i--; // make it 0-index'd

        int left = 0, right = 0;
        for(int j = 0; j < i; j++){
            if(a[j] ^ a[i] && (j == 0 || a[j] ^ a[j-1])){
                //this value is a new group that differs from the special index
                left += 2;
            }
        }
        for(int j = i + 1; j < n; j++){
            if(a[j] ^ a[i] && (j == i+1 || a[j] ^ a[j-1])){
                //this value is a new group that differs from the special index
                right += 2;
            }
        }

        cout << max(left, right) << endl;
        
    }

    return 0;
}