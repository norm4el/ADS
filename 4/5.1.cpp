#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int left=0;
    int right=0;
};
void Dfs(int node_id, int lvl, vector<Node>& trees, vector<int>& cnt) {
    if (node_id==0) return;
    if (lvl==cnt.size()) {
        cnt.push_back(0);
    }
    cnt[lvl]++;
    Dfs(trees[node_id].left, lvl+1, trees, cnt);
    Dfs(trees[node_id].right, lvl+1, trees, cnt);

}
int main () {
    int n;
    cin >> n;
    vector<Node> tree(n+1);
    for (int i=0;i<n;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if(z==0) {
            tree[x].left=y;
        } else {
            tree[x].right=y;
        }
    }
    vector<int> cnt;
    Dfs(1, 0, tree, cnt);
    int maxx=0;
    for (int cn:cnt) {
        if(cn>maxx) {
            maxx=cn;
        }
    }
    cout << maxx;

}