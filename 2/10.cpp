#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    int c, x, y;
    
    // Читаем команду c. Если ввели 0, цикл сам прервется.
    while (cin >> c && c) {
        if (c == 1 && cin >> x >> y) 
            v.insert(v.begin() + y, x);
            
        else if (c == 2 && cin >> x) 
            v.erase(v.begin() + x);
            
        else if (c == 3) {
            if (v.empty()) cout << -1;
            for (int i : v) cout << i << " ";
            cout << "\n";
        }
        
        else if (c == 4 && cin >> x >> y) {
            int t = v[x]; 
            v.erase(v.begin() + x); 
            v.insert(v.begin() + y, t);
        }
        
        else if (c == 5) 
            reverse(v.begin(), v.end());
            
        else if (c == 6 && cin >> x && v.size()) 
            rotate(v.begin(), v.begin() + x % v.size(), v.end());
            
        else if (c == 7 && cin >> x && v.size()) 
            rotate(v.rbegin(), v.rbegin() + x % v.size(), v.rend());
    }
}