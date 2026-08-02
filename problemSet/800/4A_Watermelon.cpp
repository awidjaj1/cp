#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int kilos;
    cin >> kilos;

    if(kilos & 1 || kilos < 4) cout << "NO";
    else cout << "YES";

    return 0;
}