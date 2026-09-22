#include <string>
#include <iostream>

using namespace std;

int main () {
    string a;
    cin >> a;
    string st;
    for (char c:a) {
        if(st.size()!=0&&st.back()==c) {
            st.pop_back();
        } else {
            st.push_back(c);
        }
    }
    if(st.empty()) {
        cout << "YES";
    } else {
        cout << "NO";
    }



    return 0;
}