#include<iostream>
struct Node{
    int data;
    Node* prev;
    Node* next;
};
Node* head;
void InsertAtHead(int val){
    Node *node = new Node;
    node->data = val;
    node->prev = nullptr;
    node->next = nullptr;
    if(head == nullptr){
        head = node;
        return;
    }
    node->next = head;
    head = node;
}
void InsertAtTail(int val){
    Node *node = new Node;
    node->data = val;
    node->prev = nullptr;
    node->next = nullptr;

    if(head == nullptr){
        head = node;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp=temp->next;
    }
    temp->next = node;
    node->prev = temp;
}
void print(){
    Node* temp = head;
    while(temp != nullptr){
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<"\n";
}
int main(){
    head = nullptr;
    InsertAtTail(2);
    InsertAtTail(3);
    InsertAtTail(4);
    InsertAtHead(1);
    print();
}
