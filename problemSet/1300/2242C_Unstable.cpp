#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

/**
 * Note dupe -> delete is an inverse operation
 * delete -> dupe is an inverse only if no elements were completely removed
 * 
 * Hence our strategy involves doing all deletes first and then dupes (since we dont need to delete after dupe)
 * 
 * dupe incr by # unique elements
 * delete decr by # unique elements
 * 
 * Lets call U_i
 * 
 * so we have 
 *  k = (|a_0| - U_0) + U_1 * c_1
 *  k = ((|a_0| - U_0) - U_1) + U_2 * c_2
 *  k = (((|a_0| - U_0) - U_1) - U_2) + U_3 * c_3 and so on
 * 
 * we only care about changing the unique # elements so U_i != U_j to get a different array
 * so we count the # unique elements with count 1,...,n
 * and we keep track of the current size
 * 
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n, k;
    while(t--){
        cin >> n >> k;

        vi a(n);
        vi count(n+1, 0);

        int res = 0, unique = 0;
        for(auto &x: a){
            cin >> x;
            count[x]++;
        }
        vi elementsWithCount(n+1, 0);
        for(auto &c: count){
            if(!c){
                continue;
            }
            unique++;
            elementsWithCount[c]++;   
        }


        int countOffset = 0;
        for(int i = 0; i < elementsWithCount.size(); i++){
            int elements = elementsWithCount[i];

            if(!elements){
                continue;
            }

            // counts are no longer i after doing some delete operations
            int count = i - countOffset;

            n -= unique * (count-1);
            //delete until the boundary, then add infinitely
            if(((k - n) % unique) == 0 && (k - n)/unique >= 0){
                res++;
            }

            n -= unique;
            unique -= elements; 

            countOffset += count;

        }

        cout << res << endl;
        
    }

    return 0;
}