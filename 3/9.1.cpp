#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int l=0,r=0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        if(a[i]>l) {
            l=a[i];
        } 
        r+=a[i];
    }
    while(l<=r) {
        int sum=0;
        int blocks=1;
        int mid=l+(r-l)/2;
        for(int ghouls:a) {
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
}