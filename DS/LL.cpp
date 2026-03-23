#include<iostream>
struct Node{
    int data;
    Node* next;
};
Node* head;

void InsertAtHead(int val){
    Node* node = new Node;
    node->data = val;
    node->next = head;
    head = node;
}

void InsertAtTail(int val){
    Node* node = new Node;
    node->data = val;
    node->next = nullptr;
    Node* temp = head;
    while(temp->next != nullptr){
        temp=temp->next;
    }
    temp->next = node;
}

void InsertAtPos(int val,int pos){
    if(pos==1){
        InsertAtHead(val);
        return;
    }
    Node* node = new Node;
    node->data = val;
    node->next = nullptr;

    Node* temp = head;
    for(int i=0;i<pos-2;i++){
        temp = temp->next;
    }

    node->next = temp->next;
    temp->next = node;
    
}

void Delete(int target){
    if(head == nullptr) std::cout<<"List is empty\n";
    Node* prev;
    Node* temp = head;
    if(head->data == target){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    while(temp->next != nullptr){
        if(temp->next->data == target){
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            return;
        }
        temp = temp->next;
    }
    std::cout<<"Target not found\n";
}
void print(){
    Node* temp = head;
    while(temp != nullptr){
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout <<"\n";
}

void reverse(){
    Node *prev,*cur,*next;
    prev = nullptr;
    cur = head;
    while(cur != nullptr){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}
int main(){
    head = nullptr;
    InsertAtHead(5);
    InsertAtHead(6);
    InsertAtHead(7);
    InsertAtHead(8);
    InsertAtTail(8);
    print();
    InsertAtPos(9,3);
    print();
    Delete(9);
    print();
    reverse();
    print();
}
