#include <iostream>
#include <string>

using namespace std;

int main () {
    string a;
    cin >> a;
    string st;
    for (char c:a) {
        if (st!=""&&st.back()==c) {
            st.pop_back();
        } else {
            st.push_back(c);
        }
    }
    if (st.empty()) {
        cout << "YEs";

    } else {
        cout << "NO";
    }




    return 0;
}