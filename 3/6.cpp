#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll=long long;

int main () {
    int n , h , k_max=0;
    cin >> n >> h;
    vector<ll> a( n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
        if(a[i]>k_max) {
            k_max=a[i];
        }
    }
    ll l = 1, r=k_max;
    while(l<=r) {
        ll mid=l+(r-l)/2;
        ll hours=0;
        for(ll bars:a) {
            hours+=(bars+mid-1)/mid;
        }
        if(hours<=h) {
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    cout << l;


    return 0;
}