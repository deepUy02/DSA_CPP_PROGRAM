#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a[]={1,3,2,5,4};
    int target=7;
    if(a[0]==target) cout<<"0, 0"<<endl;
    else
    {
        int i=0, j=1;
        while(j<5)
        {
            if((i==j) && (a[i]==target))
            {
                cout<<i<<", "<<j<<endl;
                break;
            }
            if((a[i]+a[j])==target) 
            {
                cout<<i<<", "<<j<<endl;
                break;
            }
            else if((a[i]+a[j]) < target) j++;
            else i++;
        }
    }
}