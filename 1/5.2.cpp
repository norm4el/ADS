#include <iostream>

using namespace std;
using ll=long long;

int main () {
    ll a;
    cin >> a;
    if(a<2) {
        cout << a;
        return 0;
    }
    for (int i=2;i*i<=a;i++) {
        while(a%i==0) {
            cout << i << " ";
            a/=i;
        }
    }
    if(a!=0) {
        cout << a << " ";
    }
    

    return 0;
}