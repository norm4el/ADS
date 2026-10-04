#include <iostream>
#include <vector>
#include <algortihm>
#include <functional>
using namespace std;
int main () {
    int t;
    cin >> t;
    vector<int> q(t);
    for (int i=0;i<n;i++) {
        cin >> q[i];
    }
    int n, m;
    cin >>n >> m ;
    vector a(n*m);
    for (int r=0;r<n;r++) {
        for(int c=0;c<m;c++) {
            int val;
            cin >> val;
            int idx;
            if(r%2==0) {
                idx=r*m+c;
            } else {
                idx=r*m+m-c-1;
            }
            a[idx]=val;
        }
    }
    for (i=0;i<t;i++) {
        int id;
        int tar=q[i];
        auto it= upper_bound(a.begin(), a.end(), tar, greater<int>());
        if(it!=a.end&& *it==tar) {
            id=it-a.begin();
            int rec=id/m;
            if (res%2==0) {
                resc=id%m;
            } else {
                resc=m-1-id%m;
            }
        }
    }
}