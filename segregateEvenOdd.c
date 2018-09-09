#include <stdio.h>
#include <stdlib.h>

int * segregateEvenOdd(int arr[],int n){
    int *final=(int *)malloc(sizeof(int)*n);
    //int i;
    // for(i=0;i<n;i++)
    //     printf("%d",arr[i]);
    int i=0,j=0;
    while(i<n){
        if(!(arr[i]&1))
            final[j++]=arr[i++];
        else
            i++;
    }
    i=0;
    while(i<n){
        if((arr[i])&1)
            final[j++]=arr[i++];
        else
            i++;
    }
    // for(i=0;i<n;i++)
    //     printf("%d\t",final[i]);
    return final;
}

int main(void) {
	int p[6]={10,15,24,4,7,8};
	int *q=segregateEvenOdd(p,6);
	int i;
	for(i=0;i<6;i++)
	    printf("%d\t",q[i]);
	return 0;
}


