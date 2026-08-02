#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;


/**
 * use prime factorization with just powers of 2 decreasing?
 * 
 * 2^(10^4) >> 10^18 so this doesnt work
 * 
 * need 10k unique prime factorizations?
 * 
 * can achieve with p1*p2, p2*p3, p3*p4, p4*p5,....,p10,000 * p10,001 which is valid since its only around 10^5 * 10^5 = 10^10 (< 10^18)
 * 
 * Proof without searching up:
 * # of primes up to n: C(n) = n / ln(n)
 * 10^4 = n / ln(n)
 * 10^4 * ln(n) = n
 * 
 * => n is around 10^4 to 10^5
 * 
 * So we can use a sieve one time
 * 
 * https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int MAX_N = 1e6;
    vector<bool> sieve(MAX_N, true);
    sieve[0] = sieve[1] = false;

    for(ll i = 2; i < sieve.size(); i++){
        if(sieve[i]){
            //can start at i*i instead of i+i 
            //since any multiple of i < i*i would 
            //necessarily be x * i where x < i
            //and x * i wouldve been filtered out by prime factors of x (notice x * x is smaller than x * i)
            for(ll j = i*i; j < sieve.size(); j += i){
                sieve[j] = false;
            }
        }
    }

    vll primes;
    for(ll i = 0; i < sieve.size(); i++){
        if(sieve[i]){
            primes.push_back(i);
        }
    }

    int n;
    while(t--){
        cin >> n;
        while(n--){
            cout << primes[n+1] * primes[n] << " ";
        }

        cout << endl;
        
    }

    return 0;
}