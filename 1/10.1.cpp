#include <iostream>
#include <queue>

using namespace std;

int main () {
    queue<int> Boris, Nursik;
    int card;
    for (int i=0;i<5;i++) {
        cin >> card;
        Boris.push(card);
   
    }
    for (int i=0;i<5;i++) {
        cin >> card;
        Nursik.push(card);
    }
    while(!Nursik.empty()&&!Boris.empty()) {
        int c1=Boris.front();
        int c2=Nursik.front();
        Boris.pop();
        Nursik.pop();
        bool B=false;
        if(c1==0&&c2==9) {
            B=true;
        } else if(c1==9&&c2==0) {
            B=false;
        } else if(c1>c2) {
            B=true;
        }

        if(B) {
            Boris.push(c1);
            Boris.push(c2);
        } else {
            Nursik.push(c1);
            Nursik.push(c2);
        }
    }
    if (Nursik.empty()) {
        cout << "Boris" << 5;

    } else {
        cout << "Nursik" << 5;
    }


    return 0;
}