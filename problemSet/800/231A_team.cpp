#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int p, v, t;
    int res = 0;
    while(n--){
        cin >> p >> v >> t;
        res += p + v + t > 1;
    }
    cout << res;

    return 0;
}