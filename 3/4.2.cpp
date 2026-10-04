#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    vector<int> pref(n+1, 0);
    for (int i=0;i<n;i++) {
        pref[i+1]=pref[i]+[i];
    } 
    int p;
    cin >> p;
    while(p--) {
        int m;
        cin >> m;
        int cnt=upper_bound(a.begin(), a.end(), m)-a.begin();
        cout << cnt << pref[cnt];
    }
}