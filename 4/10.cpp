#include <iostreaam>
#include <vector>
using namespace std;
struct Node {
    int val;
    Node* left=nullptr;
    Node* right=nullptr;
    Node(int x) : val(x) {}
};
int cnt=0;
int ans=-1;
void Small(Node* node, int k) {
    if(node==nullptr||cnt>=k) {
        return;
    }
    small(node->left, k);
    cnt++;
    if(cnt==k) {
        ans=node->val;
        return;
    }
    small(node->right, k);
}
int main () {
    int n;
    cin >> n
    return 0;
}