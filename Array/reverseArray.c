#include<stdio.h>
#include<stdlib.h>
int main(){
    int *a,n,i,j,temp;
    printf("Enter the size of Array:\n");
    scanf("%d",&n);
    a=calloc(sizeof(int),n);
    printf("Enter the element of the Array %d:\n");
    for(i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for(i=0,j=n-1;i<j;i++,j--){
        temp=*(a+i);
        *(a+i)=*(a+j);
        *(a+j)=temp;
    }
    printf("After revering the Array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",*(a+i));
    }
    return 0;
}