#include <iostream>

using namespace std;
using ll=long long;

int main () {
    ll a;
    cin >> a;
    if (a<2) {
        cout << "NO";
        return 0;
    }
    for (int i=2;i*i<a;i++) {
        while(a%i==0) {
            a/i;
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}