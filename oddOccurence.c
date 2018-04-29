//Find the odd occuring element in an integer array

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define ASCII_SIZE 10

int8_t findOddOccEle(uint8_t arr[],uint8_t arr_size);

int main() {
    char s1[]="abc";
    char s2[]="loh";
    uint8_t arr[]={6,4,4,9,1,3,3,6,9,9,9};
    //scanf("%d",&arr[0]);
    uint8_t size=sizeof(arr)/sizeof(arr[0]);
    
    printf("Result:%d",findOddOccEle(arr,size));
    return 0;
    
}

int8_t findOddOccEle(uint8_t arr[],uint8_t arr_size)
{
    int8_t res=0,i;
    for(i=0;i<arr_size;i++)
        res^=arr[i];
    return res;
}
