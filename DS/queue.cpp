#include<iostream>
const int max=3;
int arr[max];
int front=-1,rear=-1;
bool isEmpty(){
    if(front == -1 && rear == -1) return true;
    return false;
}

bool isFull(){
    if(rear == max-1){
        return true;
    }
    return false; 
}

void Enqueue(int x){
    if(isEmpty()){
        front++;
        rear++;
        arr[rear] = x;
        return;
    }
    else if(!isFull()){
        rear++;
        arr[rear]=x;
        return;
    }
    std::cout<<"Queue is full!!\n";
}
void Dequeue(){
    if(isEmpty()){
        std::cout<<"No elements to dequeue!!\n";
        return;
    }
    else if(front == rear){
        std::cout<<"Dequeued : "<<arr[front]<<"\n";
        front = rear = -1;
        return;
    }
    else{
        std::cout<<"Dequeued : "<<arr[front]<<"\n";
        front++;
        return;
    }

}

int main(){
    Enqueue(1);
    Enqueue(1);
    Enqueue(1);
    Dequeue();
}
