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

    int n;
    while(t--){
        cin >> n;
        
        vll heights(n);
        for(auto &x: heights){
            cin >> x;
        }

        ll prev = 1e10;
        ll cumSum = 0;
        for(int i = 0; i < n; i++){
            cumSum += heights[i];
            if(heights[i] < prev){
                prev = min(prev, cumSum / (i + 1));
            }
            cout << prev << " ";
        }

        cout << endl;
    }

    return 0;
}