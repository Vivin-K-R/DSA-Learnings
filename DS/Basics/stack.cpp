#include<iostream>
#include<cstdlib>
int max=3;
int *arr = (int*)malloc(max*sizeof(int));
int top=-1;
void push(int x){
    if(top == max){
        arr = (int*)realloc(arr,2*max*sizeof(int));
    }
    arr[++top]=x;
}
void pop(){
    if(top == -1){
        std::cout<<"no element to pop\n";
        return;
    }
    std::cout<<"popped : "<<arr[top--]<<"\n";
}
bool isempty(){
    return top == -1 ? 1 : 0;
}
void rettop(){
    std::cout<<"stack top is : "<<arr[top]<<"\n";

}
int main(){
    push(3);
    rettop();
    push(45);
    push(36);
    rettop();
    pop();
    rettop();
    push(66);
    rettop();
    push(77);
    rettop();
    

}
