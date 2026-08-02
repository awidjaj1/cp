#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

/**
 * Going left to right, top to bottom you have the following moves:
 * 
 * 1. take a column as a pair and advance once to the right
 * 2. take a row as a par, and by consequences take the below row as a pair as well and advance twice to the right
 * 
 * Solve using dp:
 * dp[0] = min(option 1 + dp[1], option 2 + dp[2])
 * 
 * work backwards
 * 
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n;
    while(t--){
        cin >> n;

        vector<char> board[2];

        board[0] = vector<char>(n);
        board[1] = vector<char>(n);


        for(auto &x: board[0]){
            cin >> x;
        }
        for(auto &x: board[1]){
            cin >> x;
        }

        int dp2, dp1;

        dp2 = 0;
        dp1 = board[0][n-1] != board[1][n-1];

        // cout << board[0][n-1] << " " << board[1][n-1] << endl;

        for(int i = n-2; i >= 0; i--){
            int temp = dp1;
            dp1 = min((board[0][i] != board[1][i]) + dp1, (board[0][i] != board[0][i+1]) + (board[1][i] != board[1][i+1]) + dp2);
            dp2 = temp;
        }

        cout << dp1 << endl;
    }

    return 0;
}