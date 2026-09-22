#include <iostream>

using namespace std;
using ll = long long;

int main () {
    ll a;
    cin >> a;
    if(a<2) {
        cout << "Yes";
        return 0;
    }
    for (int i=2;i*i<=a;i++) {
        if (a%i==0) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    


    return 0;
}
