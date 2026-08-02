#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;


/**
 * even indices stay even after operation (same for odd)
 * 
 * any even index can move to any even index via the operation (same for odd)
 * 
 * hence we can greedily mark the highest positive values, so long as we have matching parity operations
 * and we can greedily mark the highest non-positive value (only 1) if need be
 * 
 * nlogn to build and destroy the heaps
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n, m;
    while(t--){
        cin >> n >> m;

        priority_queue<ll> maxHeapEven, maxHeapOdd;
        int oddOps = 0, evenOps = 0;
        
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;

            if(i % 2){
                maxHeapOdd.push(x);
            }else{
                maxHeapEven.push(x);
            }
            
        }

        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            //reverse since they use 1 based indexing
            if(x % 2){
                evenOps++;
            }else{
                oddOps++;
            }
        }

        if(evenOps && maxHeapEven.size() && maxHeapEven.top() <= 0){
            // you must use all ops on this non-positive
            evenOps = 0;
            maxHeapEven.pop();
        }

        if(oddOps && maxHeapOdd.size() && maxHeapOdd.top() <= 0){
            // you must use all ops on this non-positive
            oddOps = 0;
            maxHeapOdd.pop();
        }

        while(evenOps && maxHeapEven.size() && maxHeapEven.top() > 0){
            // dont use any ops on non-positive
            evenOps--;
            maxHeapEven.pop();
        }

        while(oddOps && maxHeapOdd.size() && maxHeapOdd.top() > 0){
            // dont use any ops on non-positive
            oddOps--;
            maxHeapOdd.pop();
        }

        ll sum = 0;
        while(maxHeapEven.size()){
            sum += maxHeapEven.top();
            maxHeapEven.pop();
        }
        while(maxHeapOdd.size()){
            sum += maxHeapOdd.top();
            maxHeapOdd.pop();
        }
        cout << sum << endl;
        
    }

    return 0;
}