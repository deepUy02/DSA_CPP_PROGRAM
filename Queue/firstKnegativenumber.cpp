#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int size,int k){
    deque<int>q;

    //process the  first window of size k
    for(int i=0;i<size;i++){
        if(arr[i]<0){
            q.push_back(i);
        }
    }
    //process the remaining window  
    for(int i=k;i<size;i++){
        //answer de do purani window ki 
        if(q.empty()){
            cout<<0<<" ";
        }
        else{
            cout<<arr[q.front()]<<" ";  
        }
        //out of window element ko remove kr do
        while((!q.empty()) && (i-q.front()>=k)){
            q.pop_front();
        }

        //check current element  for insertion
        if(arr[i]<0){
            q.push_back(i); 
        }
    }
    //answer ko print kr do 
    if(q.empty()){
        cout<<0<<" ";
    }
    else{
        cout<<arr[q.front()]<<" "; 
    }
}
int main(){
    int arr[]={12,-1,-7,8,-15,30,16,28};
    int size=8;
    int k=3;

    solve(arr,size,k);
    return 0;
}