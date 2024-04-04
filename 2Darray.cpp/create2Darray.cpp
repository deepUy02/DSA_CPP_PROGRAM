#include<iostream>
#include<limits.h>
using namespace std;

bool isPresent(int arr[][4], int target ,int row, int col){
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            if(arr[row][col]==target){
                return true;
            }
        }
    }
    return false;
}
//printing col wise sum
void printcolSum(int arr[][4],int row ,int col){
    cout<<"Printing sum-:"<<endl;
    for(int col=0;col<4;col++){
        int sum=0;
        for(int row=0;row<3;row++){
            sum+=arr[row][col];
        }
        cout<<sum<<" ";
    }
    cout<<endl;

}
//printing row wise sum
void printSum(int arr[][4],int row ,int col){
    cout<<"Printing Sum-:"<<endl;
    for(int row=0;row<3;row++){
        int sum=0;
        for(int col=0;col<4;col++){
            sum+=arr[row][col];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}
int largestrowSum(int arr[][4],int row ,int col){
    int maxi= INT_MIN;
    int rowIndex=-1;
    for(int row=0;row<3;row++){
        int sum=0;
        for(int col=0;col<4;col++){
            sum+=arr[row][col];
        }
        if(sum>maxi){
            maxi=sum;
            rowIndex=row;
        }
    }    
    cout<<"The maxximum sum is-:"<<maxi<<endl;
    return rowIndex;
}
int main(){
    
    int arr[3][4];

    //taking input row wise
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cin>>arr[row][col];
        }
    }
    
    //taking input column wise
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<3;j++){
    //         cin>>arr[j][i];
    //     }
    // }.
    //print
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter the element to search"<<endl;
    int target;
    cin>>target;
    
    if(isPresent(arr,target,3 ,4)){
        cout<<"Element Found"<<endl;
    }
    else{
        cout<<"Element Not Found"<<endl;
    }
    printSum(arr,3,4);
    printcolSum(arr,3,4);
    cout<<"Maximum row is at Index-:"<<largestrowSum(arr,3,4)<<endl;
    return 0;
}