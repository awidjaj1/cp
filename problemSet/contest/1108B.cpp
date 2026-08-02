#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << 1 << "\n";
        } else if (n == 2) {
            cout << -1 << "\n";
        } else {
            // a1=1, a2=2, a3=3, a_k = 3 * 2^(k-3) for k >= 3
            cout << 1 << ' ' << 2 << ' ' << 3;
            ll cur = 3;
            for (int i = 4; i <= n; i++) {
                cur *= 2;
                cout << ' ' << cur;
            }
            cout << "\n";
        }
    }

    return 0;
}