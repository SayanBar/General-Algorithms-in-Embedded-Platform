//Search a number linearly and by recursion in an array

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define ASCII_SIZE 256

uint8_t search(int arr[],uint8_t n,uint8_t ele);
uint8_t SearchRec(int arr[], int l, int r, int x);
int8_t SearchRec1(int arr[], int n, int x);

int main() {
    char s1[]="abc";
    char s2[]="loh";
    int arr[]={117,2,3,4,5,6,7,7,9};
    //scanf("%d",&arr[0]);
    uint8_t size=sizeof(arr)/sizeof(arr[0]);
    if(search(arr,size,117)==1)
        printf("Element found");
    else
        printf("Element not found");
    
    uint8_t index;
    if((index=SearchRec(arr,0,size-1,9))==-1)
        printf("Element not found");
    else
        printf("Element found at %d",index);
    return 0;
    
}

uint8_t SearchRec(int arr[], int l, int r, int x)
{
     if (r < l)
        return -1;
     if (arr[l] == x)
        return l;
     return SearchRec(arr, l+1, r, x);
}


int8_t SearchRec1(int arr[], int n, int x)
{
     if (n==0)
        return -1;
     if (arr[0] == x)
        return 1;
     return SearchRec(arr+1, n, x);
}

uint8_t search(int arr[],uint8_t n,uint8_t ele)
{
    int i;
    for(i=0;i<n;i++)
        if(arr[i]==ele)
            return 1;
    return 0;
}
