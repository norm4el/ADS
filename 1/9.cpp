#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main () {
    int a;
    cin >> a;
    while(a--) {
        int n;
        cin >> n;
        vector<int> ans(n);
        queue<int> q;
        for (int i=0;i<n;i++) {
            q.push(i);
        }
        for (int i=1;i<=n;i++) {
            for (int j=0; j<i; j++) {
                q.push(q.front());
                q.pop();
            }
            ans[q.front()]=i;
            q.pop();
        }
        for (int c: ans) cout << c << " ";
        cout << endl; 
    }



    return 0;
}