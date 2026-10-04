#include <iostream>
#include <vector>
#include <algortihm>
int main () {
    int n, h, k_max=0;
    cin >> n >> h;
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
        if(a[i]>k_max) {
            k_max=a[i];
        }
    }
    int l=0, r=k_max;
    while(l<=r) {
        int mid=l+(r-l)/2;
        int hours=0;
        for(int bars:a) {
            hours=(bars+mid-1)/mid;
        }
        if (hours<=h) {
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    cout << l;
}