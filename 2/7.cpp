#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

int main () {
    int n , k;
    cin >> n >> k;
    Node* head=new Node();
    cin >> head->data;
    head->next=nullptr;
    Node* tail=head;
    for(int i=1;i<n;i++) {
        Node* NewNode= new Node();
        cin >> NewNode->data;
        NewNode->next=nullptr;
        tail->next=NewNode;
        tail=NewNode;
    }
    tail->next=head;
    Node* new_tail=head;
    for (int i=1;i<k;i++) {
        new_tail=new_tail->next;
    }
    Node* new_head=new_tail->next;
    new_tail->next=nullptr;
    Node* curr=new_head;
    for(;curr!=nullptr;)   {
        cout << curr->data << " ";
        curr=curr->next;
    }


    return 0;
}
