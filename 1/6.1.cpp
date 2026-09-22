#include <iostream>
#include <string>

using namespace std;

string AA(string a) {
    string a1;
    for(char c:a) {
        if (c!='#') {
            a1+=c;
        } else if (!a1.empty()) {
            a1.pop_back();
        }
    }
    return a1;
}

int main () {
    string a, b;
    cin >> a >> b;
    string a1=AA(a);
    string b1=AA(b);
if (a1==b1) {
    cout << "Yes";
} else {
    cout << "No";
}
return 0;
}