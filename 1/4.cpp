#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> sieve(ll limit) {
    vector<bool> isPrime(limit+1,true);
    vector<ll> primes;
    isPrime[0]=isPrime[1]=false;
    for (int i=2; i*i<=limit;i++) {
        if(isPrime[i]) {
            for (int j=i*i;j<=limit;j+=i) {
                isPrime[j]=false;
            }
        }
    }
    for (int i=2;i<=limit;i++) {
        if(isPrime[i]) primes.push_back(i);
    }
    return primes;
}

int main () {
    ll a, limit;
    cin >> a;
    limit = 8000;
    vector<ll> pr = sieve(limit);
    cout << pr[a];


    return 0;
}