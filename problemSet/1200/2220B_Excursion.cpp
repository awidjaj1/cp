#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

bool solve(int n, int m){
    int prev = -1, x, count = 0;
    vi a(n);
    for(auto &x: a){
        cin >> x;
    }
    for(auto &x: a){
        if(x == prev){
            count++;
            if(count == m){
                return false;
            }
        }else{
            count = 1;
            prev = x;
        }
    }

    return true;
}

/**
 * if you have < m blocks in a row you can pass because you wait for timer to go to m-1 and then cross those blocks, it will be 0 right as you pass over it and the new block you land on will not be 0
 * the block you're waiting at might hit 0 at some point, but you can simply move forward (then move back if necessary)
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n, m;
    while(t--){
        cin >> n >> m;

        cout << (solve(n, m)? "YES": "NO") << endl;
        
    }

    return 0;
}