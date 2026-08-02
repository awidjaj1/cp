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
    // each positive region requires 2 flips to completely negate without changing the rest of the array (1 if at the start)
    // want to show we have enough flipts to negate all positive regions
    // suppose we have array of size 1: [1] or [-1]
    // takes 1 flip max
    // now suppose we have array of size 2: [1, -1] or [-1, 1] or [1, 1] or [-1, -1]
    // takes 2 flips max
    // now suppose we have array of size k which we have enough flips to completely negate
    // for k+1 either we dont split a positive region in which case the #flips needed to completely negate the array doesn't change
    // or we split a positive region in which case we need 2 more flips
    // we got 1 flip from the negative we just inserted, and we know we have an extra flip because we split a positive region which means we added a positive number next to another positive (i.e. guaranteed to have an extra flip to pay for this split)
    while(t--){
        cin >> n;
        
        vll a(n);
        for(auto &x: a){
            cin >> x;
        }
        
        vi flips;
        int lastNegIndex = -1;
        for(int i=0; i <= n; i++){
           if(i == n || a[i] < 0){
                if(lastNegIndex != i - 1){
                    //want to flip i - 1 and then lastNegIndex
                    flips.push_back(i - 1);
                    if(lastNegIndex != -1) flips.push_back(lastNegIndex);
                }
                lastNegIndex = i;
            }
        }

        cout << flips.size() << endl;
        for(auto x: flips){
            cout << x + 1 << " ";
        }
        cout << endl;

    }

    return 0;
}