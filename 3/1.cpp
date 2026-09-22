#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    int l=0, r=a.size()-1;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    while(l<=r) {
        int mid=l+(r-l)/2;
        
        if(a[mid]==x) {
            cout << "YES";
            return 0;
        } else if(a[mid>x]) {
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    cout << "NO";

    return 0;
}