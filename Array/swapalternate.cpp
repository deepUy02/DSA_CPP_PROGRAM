#include<iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void swapAlternate(int arr[],int size)
{
    for(int i=0;i<size;i+=2){
        if(i+1<size)
        {
            swap(arr[i],arr[i+1]);
        }
    }
}
int main(){
    int even[8]={5,6,3,2,7,8,9,1};
    int odd[10]={7,8,25,54,3,69,90,0,4,1};

    swapAlternate(even,8);
    printArray(even,8);
    swapAlternate(odd,10);
    printArray(odd,10);
    

    return 0;
}