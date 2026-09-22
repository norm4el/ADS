#include <iostream>
#include <queue>

using namespace std;

int main () {
    queue<int> boris, nursik;
    int card;
    for (int i=0;i<5;i++) {
        cin >> card;
        boris.push(card);
    }
    for (int i=0;i<5;i++) {
        cin >> card;
        nursik.push(card);
    }

    int move=0;
    while(!boris.empty()&&!nursik.empty()) {
        int c1=boris.front();
        int c2=nursik.front();
        boris.pop();
        nursik.pop();
        bool boris_wins=false;
        if(c1==0&&c2==9) {
            boris_wins=true;
        } else if(c1==9&&c2==0) {
            boris_wins=false;
        } else if(c1>c2) {
            boris_wins=true;
        } else {
            boris_wins=false;
        }
        if(boris_wins) {
            boris.push(c1);
            boris.push(c2);
        } else {
            nursik.push(c1);
            nursik.push(c2);
        }
        move++;
    }

    if(nursik.empty()) {
        cout << "Boris" << move;
    } else {
        cout << "Nursik" << move;
    }


    return 0;
}