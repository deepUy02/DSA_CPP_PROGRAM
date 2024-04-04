#include<bits/stdc++.h>
#include<queue>
using namespace std;
int main(){

    queue<int>q;
    //insertion
    q.push(5);
    q.push(10);
    q.push(20);
    q.push(25);
    while(!q.empty())
    {
        cout<<q.front()<<" "<<endl;
        q.pop();
    }
    cout<<"Size of the Queue:"<<q.size()<<endl;
    q.pop();
    cout<<"Size of the Queue:"<<q.size()<<endl;

}