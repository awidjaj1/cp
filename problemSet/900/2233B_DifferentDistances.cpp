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
    int threeIndices[3][4] = {{0,1,3,6},{2,4,8,9},{5,7,10,11}};
    int twoIndices[2][4] = {{0,3,5,6}, {1,2,4,7}};
    // can do any n by using disjont groups of 2's and 3's
    while(t--){
        cin >> n;
        vi res(4*n);
        int ind = 0;

        if(n & 1){
            for(int i = 0; i < 3; i++, n--){
                for(int j = 0; j < 4; j++){
                    res[threeIndices[i][j]] = n;
                }
            }
            ind = 12;
        }


        while(n){
            for(int i = 0; i < 2; i++, n--){
                for(int j = 0; j < 4; j++){
                    res[ind + twoIndices[i][j]] = n;
                }
            }
            ind += 8;
        }

        for(int x: res){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}