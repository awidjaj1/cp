#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;


int mod(int a, int n){
    return ((a % n) + n) %  n;
}
/**
 * Suppose we have w_i.
 * 
 * If w_i > h_i then w_i+1 =  w_i
 * 
 * If w_i <= h_i then w_i+1 <= h_i
 * 
 * In this case:
 * If we choose w_i+1 small such that w_i+1 <= h_i+1, then w_i+2 can be at most h_i+1
 * If we choose w_i+1 large such taht w_i+1 > h_i+1, then w_i+2 must be w_i+1
 * 
 * Hence it makese sense that no matter what, we choose w_i+1 as large as possible
 * 
 * However the w_last is bound by h_last as well so take that into account... last one cannot be larger than h_last
 * because then its w_last = w_initial but w_initial = 0
 * 
 * Hence w_last <= h_last which is not a problem unless w_last-1 > h_last-1 > h_last
 * In which case we have to fix it going backwards
 * 
 * When fixing backwards, either you force it to the boundary OR to be equal to the next (so take the max obviously)
 * 
 * O(n^2) so if n = 3*10^3 we get 10^7 < 1 sec
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n;
    while(t--){
        cin >> n;
        vi a(n);
        for(auto &x: a){
            cin >> x;
        }

        for(int i = 0; i < n; i++){
            vi b(n);
            b[i] = 0;

            // take greedily
            for(int j = 0; j < n-1; j++){
                b[(i+j+1) % n] = max(b[(i+j) % n], a[(i+j)%n]);
            }

            // fix backwards
            for(int j = n-1; j >= 0; j--){
                if(b[(i+j) % n] > a[(i+j) % n] && b[(i+j) % n] != b[(i+j+1) % n]){
                    b[(i+j) % n] = max(a[(i+j) % n], b[(i+j+1) % n]);
                }else{
                    // no issue left
                    break;
                }
            }

            ll sum = 0;
            for(auto x: b){
                sum += x;
            }

            cout << sum << " ";
        }
        cout << endl;
    }

    return 0;
}