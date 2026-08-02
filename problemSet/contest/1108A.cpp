#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

/**
 * 1 is odd
 * 
 * put all evens on odd indices, put all odds on even indices
 * 
 * every element in S_i is even
 * 
 * the sum of evens is even so its not 1
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n;
    while(t--){
        cin >> n;

        for(int i = 1; i <= n; i += 2){
            cout << i + 1 << " " << i << " ";
        }

        cout << endl;
        
    }

    return 0;
}