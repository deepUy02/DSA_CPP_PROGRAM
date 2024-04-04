#include<bits/stdc++.h>
using namespace std;

    // int arr[3][4];
    bool isPresent(int arr[][3],int target ,int row, int col){
        for(int row=0;row<3;row++){
            for(int col=0;col<3;col++){
                if(arr[row][col]==target){
                    return 1;
                }
            }
        }
    return 0;
    }
    int largestrowSum(int arr[][3],int row,int col){
        int maxi= INT_MIN;
        int rowIndex=-1;
        for(int row=0;row<3;row++){
            int sum=0;
            for(int col=0;col<3;col++){
                sum+=arr[row][col];
            }
            if(sum>maxi){
                maxi=sum;
                rowIndex=row;
            }
        }
        cout<<"The maximum sum is "<<maxi<<endl;
        return rowIndex;
    }
    //to print col wise sum
    void printcolSum(int arr[][3],int row, int col){
        cout<<"Printing the sum os columns:-"<<endl;
        for(int col=0;col<3;col++){
            int sum=0;
            for(int row=0;row<3;row++){
                sum+=arr[row][col];
            }
            cout<<sum<<" "; 
        }
        cout<<endl;
    }
    //to print row wise sum
    void printrowSum(int arr[][3],int row, int col){
        cout<<"Printing the sum of rows:-"<<endl;
        for(int row=0;row<3;row++){
            int sum=0;
            for(int col=0;col<3;col++){
                sum+=arr[row][col];
            }
            cout<<sum<<" "; 
        }
        cout<<endl;
    }
    /*
    taking row wise input
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cin>>arr[row][col];
        }
    }
    */
   //taking column wise input
   int main(){
    int arr[3][3];
    cout<<"Enter the element:-"<<endl;
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
        cin>>arr[row][col];
    }
   }
   cout<<"Printing the array"<<endl;

    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    // cout<<"Enter the element to search"<<endl;
    // int target;
    // cin>>target;
    // if(isPresent(arr,target,3,3)){
    //     cout<<"Element found"<<endl;
    // }
    // else{
    //     cout<<"Element Not found"<<endl;
    // }
    // printcolSum(arr,3,3);
    // printrowSum(arr,3,3);
    cout<<"Maximum row index "<<largestrowSum(arr,3,3)<<endl;
    return 0;
   }