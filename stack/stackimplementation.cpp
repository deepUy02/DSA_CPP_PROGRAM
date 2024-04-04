#include<bits/stdc++.h>
#include<stack>
using namespace std;

class Stack{
    public:
    //properties
        int *arr;
        int top;
        int size;
    //behaviour
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int element){
        if(size-top>1)
            top++;
            arr[top]=element;
    }
    void pop(){
        if(top>=0)
            top--;
        else
            cout<<"Stack underflow"<<endl;
    }
    int peek(){
        if(top>=0)
            return arr[top];
        else    
            cout<<"Stack is Empty"<<endl;
            return -1;
    }
    bool isEmpty(){
        if(top==-1)
            return true;
        else    
            return false;
    }
};

int main(){
    Stack s(5);

    s.push(22);
    s.push(25);
    s.push(30);
    cout << s.peek() << endl;

    s.pop();
    cout<<"Print the top of the stack:"<<s.peek();
    s.pop();
    cout<<"Print the top of the stack: "<<s.peek();
    s.pop();
    cout<<"Print the top of the stack: "<<s.peek();
     s.pop();
    cout<<"Print the top of the stack: "<<s.peek();
    if(s.isEmpty()){
        cout<<"stack is empty "<<endl;
    } 
    else
        cout<<"Stack is not empty"<<endl;
    return 0;
}