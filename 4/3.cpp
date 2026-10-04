#include <iostream>
using namespace std;
struct Node {
    int val;
    Node* left=nullptr;
    Node* right=nullptr;
    Node(int x): val(x) {}
};
void Obhod(Node* node) {
    if (node==nullptr) {
        return;
    }
    cout << node->val << " ";
    Obhod(node->left);
    Obhod(node->right);
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
                curr =curr->right;
            }
        }
        Node* newNode= new Node(val);
        if (par==nullptr) {
            root=newNode;
        } else if(val<par->val) {
            par->left=newNode;
        } else {
            par->right=newNode;
        }
    }
        int k;
        cin >> k;
        Node* curr=root;
        while(curr!=nullptr&&curr->val!=k) {
            if (k<curr->val) {
                curr=curr->left;
            } else {
                curr=curr->right;
            }
        }
        Obhod(curr);
        

    



    return 0;
}