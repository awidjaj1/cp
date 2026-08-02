#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int GCD(int a, int b){
    if(a > b){
        swap(a, b);
    }

    if(a == 0){
        return b;
    }

    // b >= a
    return GCD(a, b % a);
}


/**
 * For any array a, let g denote the gcd of all the elements in the array a. 
 * Note that every element in a is a multiple of g.
  Let the maximum element be equal to M⋅g and the minimum element be equal to m⋅g.

  If array a is good, the given condition simplifies to M−m=1. This implies that a
 must contain exactly two distinct elements, and they should be of the form m⋅g
 and (m+1)⋅g.
    
Note that you are given a permutation rather than any array. Since all the elements in a permutation are distinct, any subarray that has length not equal to 2
 is guaranteed to be not good. Thus, we only need to check those subarrays that have a length equal to 2.

This is trivial. For every i, check whether the array [pi,pi+1]
satisfies the given condition.

Time Complexity: O(n)

https://codeforces.com/blog/entry/153150?mobile=false
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

        int maxi, mini, gcd;
        int res = 0;
        for(int i = 0; i+1 < n; i++){
            maxi = max(a[i], a[i+1]);
            mini = min(a[i], a[i+1]);
            gcd = GCD(a[i], a[i+1]);

            if(maxi - mini == gcd){
                res++;
            }

        }

        cout << res << endl;
        
    }

    return 0;
}
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     int n;
//     while(t--){
//         cin >> n;

//         vi a(n);
//         for(auto &x: a){
//             cin >> x;
//         }

//         int maxi, mini, gcd;
//         int found;
//         int res = 0;
//         for(int i = 0, j; i < n; i++){
//             found = 0;
//             maxi = mini = gcd = a[i];
//             for(j = i+1; j < n; j++){
//                 maxi = max(a[j], maxi);
//                 mini = min(a[j], mini);
//                 gcd = GCD(gcd, a[j]);

//                 if(maxi - mini == gcd && !found){
//                     found = j;
//                 }else if(maxi - mini > gcd){
//                     break;
//                 }
//             }
//             if(found) res += j - found;
//         }

//         cout << res << endl;
        
//     }

//     return 0;
// }