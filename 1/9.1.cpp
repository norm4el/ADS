#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main () {
    int t;
    cin >> t;
    while(t--) {
        int a;
        cin >> a;
        queue<int> q;
        vector<int> ans(a);
        for (int i=0;i<a;i++) {
            q.push(i);
        }
        for (int i=1;i<=a;i++){
            for (int j=0;j<i;j++) {
                q.push(q.front());
                q.pop();
            }
            ans[q.front()]=i;
            q.pop();
        }
        for (int x:ans) cout << x<< " ";
        cout << "\n";
 
    }


    return 0;
}