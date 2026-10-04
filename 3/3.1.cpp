#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    int cur_sum=0;
    for (int i=0;i<n;i++) {
        int b;
        cin >> b;
        cur_sum+=b;
        p[i]=cur_sum;
    }
    for (int i=0;i<m;i++) {
        int b;
        cin >> b;
        int block_id=lower_bound(p.begin(), p.end(), b) -p.begin();
        cout << block_id+1 << " ";
    }
return 0;
}