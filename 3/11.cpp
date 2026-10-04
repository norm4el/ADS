#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int t;
    cin >> t;
    vector<int> q(t);
    for (int i=0;i<t;i++) {
        cin >> q[i];
    }
    int n, m;
    cin >> n >> m;
    vector<int> a(n*m);
    for(int r=0;r<n;r++) {
        for (int c=0;c<m;c++) {
            int val;
            cin >> val;
            int idx;
            if (r%2==0) {
                idx=r*m + c;
            } else {
                idx=r*m +m-1-c;
            }
            a[idx]=val;
        }
    }
    for (int i=0;i<t;i++) {
        int id;
        int tar=q[i];
        auto it=lower_bound(a.begin(), a.end(), tar, greater<int>());
        if (it!=a.end()&&*it==tar) {
            int id=it-a.begin();
            int res=id/m;
            int resc;
            if(res%2==0) {
                resc=id%m;
            } else {
                resc=m-1-id%m;
            }
            cout << res << " " << resc << "\n";
        } else {
            cout << "-1\n";
        }
    }



    return 0;
}
