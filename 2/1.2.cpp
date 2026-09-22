#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main () {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> freq(256, 0);
        queue<char> q;
        for(int i=0;i<n;i++) {
            char c;
            cin >> c;
            freq[c]++;
            q.push(c);
            while(!q.empty()&&freq[q.front()]>1) {
                q.pop();
            }
            if(q.empty()) {
                cout << "-1 ";
            } else {
                cout << q.front();
            }
        }
    }



    return 0;
}