#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int val;
    Node* left=nullptr;
    Node* right=nullptr;
    Node(int x) : val(x) {}
};
int cntl(Node* node) {
    if (node==nullptr) return 0;
    if(node->left==nullptr&&node->right==nullptr) {
        return 1;
    }
    return cntl(node->left) + cntl(node->right)
}

int main () {



    return 0;
}