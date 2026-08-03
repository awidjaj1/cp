#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

/**
 * No matter what order you pick the last element will always be a_i ^ a_j
 * where i != j. so the problem reduces to finding the largest pairwise xor
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

        for(auto &x: a){
            cin >> x;
        }

        int ret = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                ret = max(ret, a[i] ^ a[j]);
            }
        }

        cout << ret << endl;

    }

    return 0;
}