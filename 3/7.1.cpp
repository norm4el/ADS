#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main () {
    int n , m;
    cin >> n >> m;
    vector<double> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    double l=0, r=1e9;
    for(int i=0;i<100;i++) {
        int cnt=0.0;
        double mid=l+(r-l)/2.0;
        for (int i=0;i<n;i++) {
            cnt+=(int)(a[i]/mid);
        }
        if (cnt>=m) {
            l=mid;
        } else {
            r=mid;
        }
    }
    cout << fixed << setprecision(9) << l;
}