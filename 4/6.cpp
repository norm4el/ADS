#include <iostream>
using namespace std;
struct Node {
    int val;
    Node* left=nullptr;
    Node* right=nullptr;
    Node(int x) : val(x) {}
};
int Tri(Node* node) {
    if (node==nullptr) return 0;
    int tr=0;
    if(node->left!=nullptr&&node->right!=nullptr) {
        tr=1;
    }
    return tr + Tri(node->left)+ Tri(node->right);
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
    int c= Tri(curr);
    cout << c;
    return 0;
}