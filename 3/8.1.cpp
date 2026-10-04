#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    int cur_sum=0;
    int min_len=n+1;
    int l=0;
    for(int r=0;r<n;r++) {
    cur_sum+=a[r];
    while(cur_sum>=k) {
        cur_sum-=a[l];
        min_len=min(min_len, r-l+1);
        l++;
    }
    }
    cout << min_len;
}
