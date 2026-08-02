#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;


/**
 * Have initial distance d = min(x - y mod 7, y - x mod 7)
 * Will take at least d moves to reach
 * k of those moves will be negated
 * So takes d + k moves to reach
 * This is true so long as the escapee is not trapped from the get go
 * otherwise it only takes 1 move
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n, x, y, k;
    while(t--){
        cin >> n >> x >> y >> k;

        x--, y--;
        
        int d1 = (max(x,y) - min(x,y)) % n;
        int d2 = n - d1;

        if((d1 <= 1 && d2 <= 2) ||  (d1 <= 2 && d2 <= 1)){
            cout << 1 << endl;
        }else{
            cout << min(d1,d2) + k << endl;
        }
    }

    return 0;
}