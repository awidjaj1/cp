#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;


/**
 * WLOG a <= b
 * 
 * either a + 1 
 * or b / x
 * 
 * we never care for adding then dividing (the same number) because
 * adding at most causes your round down to not apply (so +1 to the end result) which 
 * is the same result as dividing first and then adding if necessary
 * 
 * so addition is always the last operation
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int a, b, x;
    while(t--){
        cin >> a >> b >> x;

        int divisions = 0;
        int res = 1e9;
        while(a || b){
            if(a > b){
                swap(a,b);
            }
            res = min(res, divisions + b - a);
            b /= x;
            divisions++;
        }
        res = min(res, divisions);

        cout << res << endl;
    }

    return 0;
}