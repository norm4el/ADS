#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int main () {
    int n;
    cin >> n;
    Node* head= new Node();
    cin >> head->data;
    head->next=nullptr;
    Node* tail=head;
    for(int i=1;i<n;i++) {
        Node* NewNode = new Node();
        cin >> NewNode-> data;
        NewNode->next=nullptr;
        tail->next=NewNode;
        tail=NewNode;

    }
    Node* prev=nullptr;
    Node* curr=head;
    while(curr!=nullptr) {
        Node* next_temp =curr->next;
        curr->next=prev;
        prev=curr;
        curr=next_temp;
    }
    head=prev;
    curr=head;
    while(curr!=nullptr) {
        cout << curr->data << " ";
        curr=curr->next;
    }



    return 0;
}