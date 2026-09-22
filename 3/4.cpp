#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll=long long;

int main () {
    int n;
    cin >>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> pref(n+1, 0);
    for(int i=0;i<n+1;i++) {
        pref[i+1]=pref[i]+a[i];
    }
    int p;
    cin >> p;
    while(p--) {
        ll m;
        cin >> m;
        int count =upper_bound(a.begin(), a.end(), m)-a.begin();
        cout << count << " " << pref[count] << "\n";
    }


    return 0;
}