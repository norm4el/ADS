#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    int n,k;
    cin >>n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i=0;i<k;i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1>l2) {
            swap(l1, l2);
            swap(r1, r2);
        }
        if(r1>=l2) {
            int r_max=max(r1, r2);
            int cnt=upper_bound(a.begin(), a.end(), r_max)-lower_bound(a.begin(), a.end(), l1);
            cout << cnt << "\n";
        } else {
            int cnt1=upper_bound(a.begin(), a.end(), r1) - lower_bound(a.begin(), a.end(), l1);
            int cnt2= upper_bound(a.begin(), a.end(), r2) - lower_bound(a.begin(), a.end(), l2);
            cout << cnt1+cnt2 << "\n";        }
    }
}