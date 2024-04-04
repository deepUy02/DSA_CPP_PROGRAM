#include<bits/stdc++.h>
using namespace std;

class CirQueue{

    public:
    int* arr;
    int front;
    int rear;
    int size;

    CirQueue(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    }
    void push(int data){
        if( front==0 && rear==size-1){
            cout<< "Queue is Full,cannot insert:"<<endl;
        }
        else if(front==-1){
            front=rear=0;
            arr[rear]=data;
        }
        else if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=data;
        }
        else{
            rear++;
            arr[rear]=data;
        }
    }
    void pop(){
        //check empty 
        //single element
        //circular nature 
        //normal flow
        if(front == -1){
            cout<<"Cannot pop, Queue is empty"<<endl;
        }
        else if(front==rear){
            arr[front]=-1;
            front =-1;
            rear=-1;
        }
        else if( front ==size-1){
            front=0;
        }
        else{
            front++;
        }
    } 
};

int main(){

    return 0;
}