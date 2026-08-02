#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;


/**
 * F(F(x)) = F(x) 
 * Let F(x) = y
 * => F(y) = y
 * 
 * There are 2 cases x = y and x != y.
 * 
 * If x == y, then F(x) = x and x < 10 becasue otherwise F(x) < 10
 * If x != y, then it must hold that the sum of x's digits == y where y < 10 by the logic above
 * 
 * So plan of action, replace the largest digits with 0 until the sum of the digits is < 10
 * Replace the first digit (we call f) with 1 iff f-1 is the max digit
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    string s;
    while(t--){
        cin >> s;

        int digits[9] = {0};
        int sum = 0;
        for(int i = 1; i < s.length(); i++){
            if(s[i] == '0') continue;
            sum += s[i] - '0'; 
            digits[s[i] - '1']++;
        }
        sum += s[0] - '0'; 
        if(s[0] != '1') digits[s[0] - '2']++;

        int res = 0;

        for(int i = 9; i > 0, sum >= 10; i--){
            int c = digits[i-1];
            int n = ceil((sum - 9.0) / i);

            int use = min(c, n);
            sum -= use * i;
            res += use;
            
        }

        cout << res << endl;
        
    }

    return 0;
}