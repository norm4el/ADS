#include <iostream>
#include <string>

struct Node {
    string data;
    Node* prev;
    Node* next;
};

int main () {
    in n;
    cin >> n;
    Node* head=nullptr;
    Node* tail=nullptr;
    string command;
    while(cin >> command) {
        if(command=="add_front") {
            string tittle;
            cin >> tittle;
            Node* NewNode= new Node{tittle, head, nullptr};
            if(head!=nullptr) {
                head->prev=NewNode;
            }
            head=NewNode;
            if(tail==nullptr) {
                tail=NewNode;
            }
            cout << "ok\n";
        } else if (command=="add_back") {
            string tittle;
            cin >> tittle;
            Node* NewNode = new Node{tittle, nullptr, tail};
            if(tail!=nullptr) {
                tail->next= NewNode;
            }
            tail=NewNode;
            if(head==nullptr) {
                head=NewNode;
            }
            cout << "ok\n";

        } else if(command=="front") {
            if(head!=nullptr) {
                cout << head->data << "\n";
            } else {
                cout << "error\n";
            }
        } else if (command == "back") {
            if(tail!=nullptr) {
                cout << tail->data<< "\n";
            } else {
                cout << "error\n";
            }
        } else if(command=="erase_front") {
            if(head==nullptr) {
                cout << "error\n";
            } else {
                cout << head->data << "\n";
                Node* temp=head;
                head=head->next;
                if(head!=nullptr) {
                    head->prev=nullptr;
                } else {
                    tail=nullptr;
                }
                delete temp;
            }
        } else if(command=="erase_back") {
            if(tail==nullptr) {
                cout << "error\n";
            } else {
                Node* temp=tail;
                tail=tail->prev;
                if(tail!=nulllptr) {
                    tail->next=nullptr;
                } else {
                    head=nullptr;
                }
                delete temp;
            }
        }else if (command=="clear") {
            while(head!=nullptr) {
                Node* temp=head;
                head=head->next;
                delete temp;
            }
            tail=nullptr;
            cout << "ok\n";
        } else if (command=="exit") {
            cout << "goodbye\n";
            break;
        }
    }




    return 0;
}