#include <iostream>
#include <string>

using namespace std;


string AA(string a) {
    string a1;
    for (char c:a) {
        if (c!='#') {
            a1.push_back(c);
        } else if (!a1.empty()) {
            a1.pop_back();
        }
    }
    return a1;
}
int main () {
    string a, b, a1, b1;
    cin >> a >> b;
    a1=AA(a);
    b1=AA(b);
    if (a1==b1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}