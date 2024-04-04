#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int>s;

    s.push(10);
    s.push(20);
    s.push(50);

    cout<<"Printing the size of the stack: "<<s.size()<<endl;
    cout<<"printing the top element of the stack: "<<s.top()<<endl;
    s.pop();
    cout<<"printing the top element of the stack: "<<s.top()<<endl;
    cout<<"Printing the size of the stack again after pop: "<<s.size()<<endl;
    if(s.empty()){
        cout<<"Stack if empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
}