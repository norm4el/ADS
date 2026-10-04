#include <iostream>
#include <vector>
#include <algortihm>
using namespace std;
int main () {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i]=max(x2, y2);
    }
    sort(a.begin(), a.end());
    cout << a[k-1];
    return 0;
}