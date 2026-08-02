#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;


/**
 * valid possible multiples of 4 are:
 * 4,
 * 12,
 * 24,
 * 32
 * 
 * any other mutliples of 4 greather than these (only using digits 1-4) will have to by definition include those numbers above in the tens place
 *  
 * so plan of action:
 * if any 4s remove all,
 * so now 24 is no longer an issue
 * only need to worry about 1 followed by 2 or 3 followed by 2
 * so 3 and 1 can be treated the same say X
 * hence we could have X, X, 2, 2, 2, X, 2
 * any X followed by a 2 is problematic
 * for each X you can decide to keep it and remove all 2s after
 * or remove it (+1 operation) and continue on with the rest (dp?)
 * 
 * dp[i] = min(#2s after i, 1+dp[i+1])
 * dp[i] = #operations needed to make it beautiful at index i to the end
 * can do this in the reverse to make it easier
 * 
 * summary: 
 * must remove all 4s,
 * then use dp
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int res = 0;
        int dpRes = 0;

        int num2 = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == '2') num2++;
            else if(s[i] == '4') res++;
            else dpRes = min(num2, 1 + dpRes);
        }

        cout << res + dpRes << endl;
        
    }

    return 0;
}