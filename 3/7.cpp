#include <iostream>
#include <vector>
#include <iomanip>

using namespace sts;
using ll=long long;

int main () {
    int n , k;
    cin >> n >> k;
    vector<double> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    double l=0.0;
    double r=1e9;
    for(int i=0;i<100;i++) {
        double mid= l+(r-l)/2.0;
        ll cnt=0;
        for(int i=0;i<n;i++) {
            cnt+=(ll)(a[i]/mid)
        }
        id(cnt>=k) {
            l=mid;
        } else{
            r=mid;
        }
    }
    couut << fixed<< setprecision(9) << l;


    return 0;
}