#include <iostream>
#include <algorithm>

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
        Node* NewNode=new Node();
        cin >> NewNode->data;
        NewNode->next=nullptr;
        tail->next=NewNode;
        tail=NewNode;
    }
    int max_sum=head->data;
    int cur_sum=head->data;
    Node* curr=head->next;
    for(;curr!=nullptr;) {
        cur_sum=max(curr->data,curr->data+cur_sum);
        max_sum=max(cur_sum, max_sum);
        curr=curr->next;
    }
    cout << max_sum;




    return 0;
}