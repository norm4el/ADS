#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i =0;i<n;i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while(q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1>l2) {
            swap(l1,l2);
            swap(r1,r2);
        }
        int ans=0;
        
            if(l2<=r1) {
                int r_max=max(r1,r2);
                ans=upper_bound(a.begin(), a.end(), r_max)-lower_bound(a.begin(), a.end(), l1);

            } else {
                int count1=upper_bound(a.begin(), a.end(), r1)-lower_bound(a.begin(), a.end(), l1);
                int count2=upper_bound(a.begin(), a.end(), r2)-lower_bound(a.begin(), a.end(), l2);
                ans=count1+count2;
            }
        
        cout << ans << "\n";
    }


    return 0;
}