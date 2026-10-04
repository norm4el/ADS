#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int val;
    Node* left=nullptr;
    Node* right=nullptr;
    Node(int x) : val(x) {}
};
int maxx;
int calc(Node* node) {
    if(node==nullptr) return 0;




     lh=calc(node->left);
    int rh=calc(node->right);
    int cur=lh+rh+1;
    maxx=max(maxx, cur);
    return max(lh, rh)+1;
}
int main () {
    int n;
    cin >> n;
    Node* root=nullptr;
    for(int i=0;i<n;i++) {
        int val;
        cin >> val;
        Node* curr=root;
        Node* par=nullptr;
        while(curr!=nullptr) {
            par=curr;
            if(val<curr->val) {
                curr=curr->left;
            } else {
                curr=curr->right;
            }
        }
        Node* newNode=new Node(val);
        if(par==nullptr) {
            root=newNode;
        } else if(val<par->val) {
            par->left=newNode;
        } else {
            par->right=newNode;
        }
    }
    Node* curr=root;
    int c=calc(curr);
    cout << maxx;

    return 0;
}