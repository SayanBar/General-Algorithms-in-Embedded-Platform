//Find the largest number in an array

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define ASCII_SIZE 256

uint8_t largest(int arr[],uint8_t n);

int main() {
    char s1[]="abc";
    char s2[]="loh";
    int arr[]={117,2,3,4,5,6,7,7,9};
    //scanf("%d",&arr[0]);
    uint8_t size=sizeof(arr)/sizeof(arr[0]);
    printf("Largest of the array:%d",largest(arr,size));
    return 0;
}

uint8_t largest(int arr[],uint8_t n)
{
    int i;
    uint8_t max=arr[0];
    for(i=0;i<n;i++)
        if(arr[i]>max)
            max=arr[i];
    return max;
}
