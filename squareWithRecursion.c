//Quick Sort
#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL -1
#define SUCCESS 1
#define INT_BITS 16
#define ASCII_SIZE 256
 
uint16_t square(int8_t num);

int main()
{
    //int8_t arr[]={2,4,5,1,0,67,34,12};
    //uint8_t size=sizeof(arr)/sizeof(arr[0]);
    //QuickSort(arr,0,size-1);
    // int8_t i;
    // for(i=0;i<size;i++)
    //     printf("arr[%d]:%d  ",i,arr[i]);
    
    printf("Square:%d",square(8));
    return 0;
}

uint16_t square(int8_t num)
{
    if(num==0)
        return 0;
    if(num<0)
        num=-num;
    int8_t x=num>>1;
    if(num%2==0)
        return (4*square(x));
    else
        return (4*square(x)+(4*x)+1);
    
}
