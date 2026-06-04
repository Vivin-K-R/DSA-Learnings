#include<iostream>
struct Node{
    int data;
    Node* next;
};
Node* head = nullptr;
Node* tail = nullptr;
void Enqueue(int val){
    Node* node = new Node;
    node->data = val;
    node->next = nullptr;
    if(head == nullptr && tail == nullptr){
        head = tail = node;
        return;
    }
    tail->next = node;
    tail = node;
}
void Dequeue(){
     Node* temp=head;
    if(head == nullptr && tail == nullptr){
        std::cout<<"No element to Dequeue\n";
        return;
    }
    else if(head == tail){
        head=nullptr;
        tail=nullptr;
    }
    else{
        head = temp->next;
    }
    delete temp;
}
void print(){
    Node* temp = head;
    while(temp != nullptr){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<"\n";
}

int main(){
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    print();
    Dequeue();
    print();
}
