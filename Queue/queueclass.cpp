#include<bits/stdc++.h>
using namespace std;

class Queue{
    int* arr;
    int size;
    int front;
    int rear;
public:
    Queue(int size){
        this->size=size;
        arr=new int[size];
        front=0;
        rear=0;
    }
    void push(int data){
        if(rear==size){
            cout<<"Queue is FULL"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }
    void pop(){
        if(front==rear){
            cout<<"Queue if Empty"<<endl;
        }
        else{
            arr[front]=-1;
            front++;
            if(front==rear){
                front=0;
                rear=0;
            }
        }
    }
    int getFront(){
        if(front==rear){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }
    int isEmpty(){
        if(front==rear){
            return true;
        }
        else{
            return false;
        }
    }
    int getsize(){
        return rear-front;
    }
};
int main(){
    Queue q(10);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<"Size of queue is "<<q.getsize()<<endl;
    cout<<"Check Queue is empty or not ? "<<q.isEmpty()<<endl;
    cout<<"Fornt element is : "<<q.getFront()<<endl;
    return 0;
}