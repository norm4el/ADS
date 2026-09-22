#include <iostream>
#include <string>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main () {
    string command;
    Node* head= nullptr;
    Node* tail=head;
    while (cin >> command) {
        if(command=="add_front") {
            string tittle;
            cin >> tittle;
            Node* NewNode=new Node{tittle, head, nullptr};
            if(head!=nullptr) {
                head->prev=NewNode;
            }
            head=NewNode;
            if(tail==nullptr) {
                tail=NewNode;
            }
        } else if(command=="add_back") {
            string tittle;
            cin >> tittle;
            Node* NewNode= new Node{tittle, nullptr, tail};
            if(tail!=nullptr) {
                tail->next=NewNode;
            }
            tail=NewNode;
            if(head==nullptr) {
                head=NewNode;
            }
        } else if(command=="erase_front") {
            
        } else if(command=="erase_back") {

        } else if(command=="front") {

        } else if(command=="back") {

        } else if(command=="clear") {

        } else if(command=="exit") {

        }
    }
}