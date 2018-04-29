//Find the missing number in a consecutive number array

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define ASCII_SIZE 10

int8_t findMissing(uint8_t arr[],uint8_t arr_size);

int main() {
    char s1[]="abc";
    char s2[]="loh";
    uint8_t arr[]={1,2,4,5,6,7,8,9,10};
    //scanf("%d",&arr[0]);
    uint8_t size=sizeof(arr)/sizeof(arr[0]);
    
    printf("Result:%d",findMissing(arr,size));
    return 0;
    
}

int8_t findMissing(uint8_t arr[],uint8_t arr_size)
{
    int8_t x1=0,x2=0,i;
    for(i=0;i<arr_size;i++)
        x2^=arr[i];
    for(i=1;i<=arr_size+1;i++)
        x1^=i;
    return (x1^x2);
}
