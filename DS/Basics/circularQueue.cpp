#include<iostream>
const int max=3;
int arr[max];
int front=-1,rear=-1;
bool isEmpty(){
    if(front == -1 && rear == -1) return true;
    return false;
}

bool isFull(){
    if((rear+1)%max == front){
        return true;
    }
    return false; 
}

void Enqueue(int x){

    if(isFull()){                         // moved full check first
        std::cout<<"Queue is full!!\n";
        return;
    }

    if(isEmpty()){
        front = rear = 0;                 // changed from front++ rear++
    }
    else{
        rear = (rear+1)%max;
    }

    arr[rear]=x;
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
        front = (front + 1)%max;
        return;
    }

}

int main(){
    Enqueue(1);
    Enqueue(1);
    Enqueue(1);
    Dequeue();
}
