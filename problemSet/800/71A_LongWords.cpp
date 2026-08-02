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

    string w;
    while(t--){
        cin >> w;
        if(w.length() > 10){
            cout << w[0] << w.length() - 2 << w[w.length() - 1] << endl;
        }else{
            cout << w << endl;
        }
    }

    return 0;
}