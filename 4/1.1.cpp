#include <iostream>
struct Node {
    int val;
    Node* left=nullptr;
    Node* right=nullptr;
    Node(int x): val(x) {}
}
int main () {
    int n, k;
    Node* root=nullptr;
    for (int i=0;i<n;i++) {
        int val;
        cin >> val;
        Node* curr=root;
        Node* par=nullptr;
        while(curr!=nullptr) {
            par=curr;
            if (val<curr->val) {
                curr=curr->left;
            } else {
                curr=curr->right;
            }
        }
        Node* newNode= new Node(val);
        if (par==nullptr) {
            root=newNode;
        } else if(val<par->val) {
            par->lefft=newNOde;
        } else {
            par->right=newNOde;
        }
    }
    Node* curr=root;
    while(k--) {
        string path;
        cin >> path;

        for(char c:path) {
            if (curr==nullptr) break;
            curr=(c=='L')? curr=curr->left: curr=curr->right;
        }
        if(curr==nullptr) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }




    return 0;
}