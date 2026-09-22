#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* merge(Node* a, Node* b) {
    Node* head=nullptr;
    
    if(a==nullptr) return b;
    if(b==nullptr) return a;
    if(a->data<=b->data) {
        head=a;
        a=a->next;
    } else {
        head=b;
        b=b->next;
    }
    Node* tail=head;
    while(a!=nullptr&&b!=nullptr) {
        if(a->data<=b->data) {
            tail->next=a;
            a=a->next;
        } else {
            tail->next=b;
            b=b->next;
        }
        tail=tail->next;
    }
    if(a!=nullptr) {
        tail->next=a;
    }
    if(b!=nullptr) {
        tail->next=b;
    }
    return head;
}

int main () {
    int n;
    cin >> n;
    Node* headA=new Node();
    cin >> headA->data;
    headA->next=nullptr;
    Node* tailA=headA;
    for(int i=1;i<n;i++) {
        Node* NewNode=new Node();
        cin >> NewNode->data;
        NewNode->next=nullptr;
        tailA->next=NewNode;
        tailA=NewNode;
    }
    int k;
    cin >> k;
    Node* headB=new Node();
    cin >> headB->data;
    headB->next=nullptr;
    Node* tailB=headB;
    for(int i=1;i<k;i++) {
        Node* NewNode=new Node();
        cin >> NewNode->data;
        NewNode->next=nullptr;
        tailB->next=NewNode;
        tailB=NewNode;
    }
    Node* res=merge(headA, headB);
    while(res!=nullptr) {
        cout << res->data << " ";
        res=res->next;
    }

    return 0;
}