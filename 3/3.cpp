#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll=long long;

int main () {
    int n, m;
    cin >> n >> m;
    vector<ll> p(n);
    ll cur_sum=0;
    for(int i=0;i<n;i++) {
        ll a;
        cin >> a;
        cur_sum+=a;
        p[i]=cur_sum;
    }
    for (int i=0;i<m;i++) {
        ll b;
        cin >> b;
        int block_id=lower_bound(p.begin(), p.end(), b)-p.begin();
        cout << block_id+1 << "\n";
    }



    return 0;
}