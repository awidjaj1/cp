#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    ll n, a, b;
    // a + b = n
    // so b = n - a
    // so n - a = 0 mod 12
    // so a = n mod 12
    while(t--){
        cin >> n;
        a = n % 12;

        if(a == 10){
            if(n < 22){
                cout << -1 << endl;
            }else{
                // 22 is the next palindrome after 10
                cout << 22 << " " << n - 22 << endl;
            }
        }else{
            cout << a << " " << n - a << endl;
        }
    }

    return 0;
}