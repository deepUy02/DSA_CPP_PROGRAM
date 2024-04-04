#include <stdio.h>
#include <stdlib.h>
int main(void){
	int n,i,*a,sum=0;

	printf("Enter size of array:");
	scanf("%d",&n);

	a=calloc(sizeof(int),n);
	printf("Enter %d Elements:",n);
	for(i=0;i<n;i++)	{
		scanf("%d",a+i);
	}
	for(i=0;i<n;i++){
		sum=sum+*(a+i);
	}
	printf("The sum of Array is: %d",sum);	
	return 0;
}