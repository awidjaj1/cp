#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

ll GCD(ll a, ll b){
    if(a > b){
        swap(a, b);
    }
    // a <= b
    if(a == 0) return b;
    return GCD(a, b % a);
}

ll LCM(ll a, ll b){
    return abs(a * b)/GCD(a,b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    ll a, b, c, m;
    while(t--){
        cin >> a >> b >> c >> m;

        ll lcmAB = LCM(a,b);
        ll lcmAC = LCM(a,c);
        ll lcmBC = LCM(b,c);
        ll lcmABC = LCM(lcmAB, c);
 
        ll aTotal = (m/lcmAB) + (m/lcmAC);
        ll a3 = m / lcmABC;
        ll a2 = aTotal - 2*a3;
        ll aRes = (m/a)*6 - a3*4 - a2*3;

        ll bTotal = (m/lcmAB) + (m/lcmBC);
        ll b3 = a3;
        ll b2 = bTotal - 2 * b3;
        ll bRes = (m/b)*6 - b3*4 - b2*3;

        ll cTotal = (m/lcmAC) + (m/lcmBC);
        ll c3 = a3;
        ll c2 = cTotal - 2 * c3;
        ll cRes = (m/c)*6 - c3*4 - c2*3;

        cout << aRes << " " << bRes << " " << cRes << endl;
    }

    return 0;
}