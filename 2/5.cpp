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
        cin >> NewNode->data;
        NewNode->next=nullptr;
        tail->next=NewNode;
        tail=NewNode;
    }
    int tar=(n/2)-1;
    Node* curr = head;
    for (int i=0;i<tar;i++) {
        curr=curr->next;
    }
    Node* to_delete=curr->next;
    curr->next=curr->next->next;
    delete to_delete;
    curr=head;

    while(curr !=nullptr) {
        cout << curr->data<< " ";
        curr=curr->next;
    }


    return 0;
}