#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main () {
    int n;
    cin >> n;
    queue<string> q;
    string name;
    for(int i=0;i<n;i++) {
        cin >> name;
        if (q.empty()||q.back()!=name) {
            q.push(name);
        }
    }
    cout <<q.size();
    while(!q.empty()) {
        cout << q.front()<< "\n";
        q.pop();
    }

    return 0;
}

