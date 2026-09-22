#include <iostream>
using namespace std;

struct Node {
    int data;
    Node*next;
};

int main () {
    int n;
    cin >> n;
    Node* head= new Node();
    cin >> head->data;
    head->next=nullptr;
    Node* tail=head;
    for(int i=1;i<n;i++) {
        Node* NewNode=new Node();
        cin >> NewNode->data;
        NewNode->next=nullptr;
        tail->next=NewNode;
        tail=NewNode;
    }
    Node* curr=head;
    while(curr!=nullptr&&curr->next!=nullptr) {
        Node* to_delete=curr->next;
        curr->next=curr->next->next;
        delete to_delete;
        curr=curr->next;
    }
    curr =head;
    while(curr!=nullptr) {
        cout << curr->data << " ";
        curr=curr->next;
    }


    return 0;
}