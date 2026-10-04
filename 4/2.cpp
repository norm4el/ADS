#include <iostream>
#include <string>
using namespace std;
struct Node {
    int val;
    Node* left=nullptr;
    Node* right=nullptr;
    Node(int x): val(x) {}
};
int gs3(Node* node) {
    if (node==nullptr) {
        return 0;
    }
    return 1+ gs3(node->left)+gs3(node->right);
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
        while(curr!=nullptr){
            par=curr;
            if(val<curr->val) {
                curr=curr->left;
            } else {
                curr=curr->right;
            }
        }
        Node* newNode= new Node(val);
        if(par==nullptr) {
            root=newNode;
        } else if(val<par->val) {
            par->left=newNode;
        } else {
            par->right=newNode;
        }
    }
    int tar;
    cin >> tar;
    Node* curr=root;
    while(curr!=nullptr&&curr->val!=tar) {
        if(tar<curr->val) {
            curr=curr->left;
        } else {
            curr=curr->right;
        }
    }
    cout << gs3(curr);



    return 0;
}