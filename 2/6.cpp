#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* merge(Node* a, Node* b) {
    if(a==nullptr) return b;
    if(b==nullptr) return a;
    Node* head=nullptr;
    if(a->data<=b->data) {
        head=a;
        a=a->next;
    } else {
        head=b;
        b=b->next;
    }
    Node* tail=head;
    for(;a!=nullptr&&b!=nullptr;) {
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
    } else {
        tail->next=b;
    }
    return head;
}

int main () {
    int a;
    cin >> a;
    Node* headA=nullptr;
    Node* tailA=headA;
    for (int i=0;i<a;i++) {
        Node* NewNode = new Node();
        cin >> NewNode->data;
        NewNode->next=nullptr;
        if(headA==nullptr) {
            headA=NewNode;
            tailA=headA;
        } else {
            tailA->next=NewNode;
            tailA=NewNode;
        }
    }
    int k;
    cin >> k;
    Node* headB=nullptr;
    Node* tailB=nullptr;
    for (int i=0;i<k;i++) {
        Node* NewNode = new Node();
        cin >> NewNode->data;
        NewNode->next=nullptr;
        if(headB==nullptr) {
            headB=NewNode;
            tailB=headB;
        } else {
            tailB->next=NewNode;
            tailB=NewNode;
        }
    }
    Node* res=merge(headA, headB);
    for(;res!=nullptr;) {
        cout << res->data << " ";
        res=res->next;
    }


    return 0;
}