#include <iostream>
#include <string>
using namespace std;
struct Node{
    int val;
    Node* left=nullptr;
    Node* right=nullptr;
    Node(int x): val(x) {}
};
int main () {
    int n, m;
    cin >> n >> m;
    Node* root=nullptr;
    for(int i=0;i<n;i++) {
        int val;
        cin >> val;
        Node* curr=root;
        Node* par=nullptr;
        while(curr!=nullptr) {
            if (val<=curr->val) {
                curr=curr->left;
            } else {
                curr=curr->right;
            }
        }
        Node* newNode=new Node(val);
        if(par==nullptr) {
            root=newNode;
        } else if (val<=par->val) {
            par->left=newNode;
        } else {
            par->right=newNode;
        }
    }
    for (int i=0;i<m;i++) {
        string path;
        cin >> path;
        Node* curr=root;
        for (char step:path) {
            if (curr==nullptr) break;
            curr = (step=='L')? curr=curr->left:curr=curr->right;
        }
    }



    return 0;
}