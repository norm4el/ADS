#include <iostream>
#include <vector>
using namespace std;
using ll= long long;
struct Node {
    int val;
    Node* left = nullptr;
    Node* right= nullptr;
    Node(int x) : val(x) {}
};
void Lvls(Node* node, int lvl, vector<ll>& sums) {
    if(node==nullptr) {
        return;
    }
    if (lvl==sums.size()) {
        sums.push_back(0);
    }
    sums[lvl]+=node->val;
    Lvls(node->left, lvl+1, sums);
    Lvls(node->right, lvl+1, sums);
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
        Node* newNode= new Node(val);
        if (par==nullptr) {
            root=newNode;
        } else if(val<par->val) {
            par->left=newNode;
        } else {
            par->right=newNode;
        }
    }
    vector<ll> nums;
    Node* curr=root;
    Lvls(curr, 0, nums);
    cout << nums.size()<< "\n";
    for (int i=0;i<nums.size(); i++) {
        cout << nums[i];
    }
    return 0;
}