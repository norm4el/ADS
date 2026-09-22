#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll=long long;

int main () {
    int n , k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    ll cur_sum;
    ll min_len=n+1;
    ll left=0;
    for (int r=0;r<n;r++) {
        cur_sum+=a[r];
        while(cur_sum>=k) {
            min_len=min(min_len, right-left+1);
            cr_sum-=a[left];
            left++;
        }
    }
    cout << min_len;

    return 0;
}