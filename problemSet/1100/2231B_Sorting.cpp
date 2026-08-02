#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

/**
 *  So let's suppose there is a solution i.e. a sequence {b_i} and a k
 * 
 * We know that if a_i > a_i+1 then a_i+1 must be in the sequence and k >= a_i - a_i+1
 * From this we know that k >= max(a_i - a_i+1) for all i
 * 
 * Now if both a_i and a_i+1 are in the seq then decreasing k maintains their order.
 * 
 * If a_i is in the seq and a_i+1 is not then decrasing k maintains their order
 * 
 * If a_i is not in the seq but a_i+1 is then decreasing k maintains their order iff k > a_i - a_i+1
 * 
 * Hence a valid k should be k = max(a_i - a_i+1) for all i (if there is a solution)
 * We can attempt this k greedily and it should work if there's a solution
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n;
    while(t--){
        cin >> n;

        vi a(n);
        for(auto& x: a){
            cin >> x;
        }

        int k = 0;
        for(int i = 1; i < n; i++){
            k = max(k, a[i-1] - a[i]);
        }

        for(int i = 1; i < n; i++){
            if(a[i] < a[i-1]){
                a[i] += k;
            }
        }

        bool sorted = true;
        for(int i = 1; i < n; i++){
            if(a[i] < a[i-1]){
                sorted = false;
                break;
            }
        }

        cout << (sorted? "YES": "NO") << endl;

    }
    return 0;
}