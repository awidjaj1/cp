#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;


int main() { 
    cin.tie(nullptr);

    int t;
    cin >> t;

    //operations can solve up to 2 conflicts
    //WLOG:
    //no flip + reverse solves b [b ... a] a
    //flip + reverse solves b [b ... b] b
    while(t--){
        string w;
        cin >> w;

        int conflicts = 0;
        for(int i = 0; i+1 < w.length(); i++){
            if(w[i] == w[i + 1]) conflicts++;
            if(conflicts > 2) break;
        }

        if(conflicts > 2) cout << "NO";
        else cout << "YES";
        cout << endl;
    }

    return 0;
}