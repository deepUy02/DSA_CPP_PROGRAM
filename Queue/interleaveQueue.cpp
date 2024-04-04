#include<bits/stdc++.h>
using namespace std;

void interleaveQueue(queue<int>&q){
    //step 1:seperate the queue
    int n = q.size();
    while(q.empty()){
        return;
    }
    int k=n/2;
    int count=0;
    queue<int>q2;

    while(!q.empty()){
        int temp=q.front();
        q.pop();
        q2.push(temp);
        count++;
        if(count==k){
            break;
        }
    }
    //step2:interleave start kro 
    while(!q.empty() && !q2.empty()){
        int temp1=q2.front();
        q2.pop();

        q.push(temp1);
        int temp2=q.front();
        q.pop();
        q.push(temp2);
    }
    //odd case
    if(n&1){
        int element=q.front();
        q.pop();
        q.push(element);
    }
}
int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    // cout<<"Printing the original Queue"<<endl;  
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }

    interleaveQueue(q);
    cout<<"\nPrinting the interleaveQueue"<<endl;
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}