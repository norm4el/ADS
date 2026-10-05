int curr;
void trans(Node* noode, int sum) {
    if (node==nullptr) return ;
    trans(node->right);
    curr+=node->val;
    node->val=curr;
    cout << node->val;
    trans(node->left);
}