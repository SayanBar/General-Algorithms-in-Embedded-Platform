//Multiply a number with 3.5


#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL -1
#define SUCCESS 1
#define INT_BITS 16
 
int16_t multiply3point5First(int16_t);
int16_t multiply3point5Second(int16_t num);

/* Driver program to test above functions*/
int main()
{
    printf("Value * 3.5 with first implementation:%d\n",multiply3point5First(9362));
    printf("Value * 3.5 with second implementation:%d",multiply3point5Second(-5));
    return 0;
}

int16_t multiply3point5First(int16_t num)
{
    
    uint8_t negFlag=0;
    if(num<0){
        num=-num;
        negFlag=1;
    }
    int16_t result = ((num<<1)+num+(num>>1));
    if(negFlag==1)
        return -result;
    else
        return result;
}

int16_t multiply3point5Second(int16_t num)
{
    uint8_t negFlag=0;
    if(num<0){
        num=-num;
        negFlag=1;
    }
    int16_t result = ((num<<3)-num)>>1;
    if(negFlag==1)
        return -result;
    else
        return result;
}

