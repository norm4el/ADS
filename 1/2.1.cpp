#include <iostream>

using namespace std;
using ll= long long;

ll BinPw(ll a, ll b, ll c) {
    if (b==0) {
        return 1%c;
    }
    if(b%2==0) {
        ll half= BinPw(a,  b/2,  c);
        return half*half;
    } else {
        return (a%c)*BinPw( a,  b-1,c )%c;
    }
}

int main () {
    ll a, b, c, d;
    cin >> a >> b >> c;
    d= BinPw(a, b, c);
    cout << d;

}