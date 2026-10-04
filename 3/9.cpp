#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll=long long;

int main () {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll l=0, r=0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(a[i]>l) {
            l=a[i];
        }
        r+=a[i];
    }
    while(l<=r) {
        ll sum=0;
        ll mid=l+(r-l)/2;
        ll blocks=1;
        for(ll ghouls:a) {
            if(ghouls+sum>mid) {
                blocks++;
                sum=ghouls;
            } else {
                sum+=ghouls;
            }
        }
        if (blocks<=k) {
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    cout << l;


    return 0;
}