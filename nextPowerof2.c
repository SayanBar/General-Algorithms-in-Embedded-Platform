//Next power of 2

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL -1
#define SUCCESS 1
#define INT_BITS 16
 
uint16_t nextPowerof2(uint16_t);
uint16_t nextPowerof2Second(uint16_t num);
/* Driver program to test above functions*/
int main()
{
    printf("Next power of 2:%u\n",nextPowerof2(16));
    printf("Second Implementation:%u", nextPowerof2Second(15));
    return 0;
}

uint16_t nextPowerof2(uint16_t n)
{
    if(n && (!(n & (n-1))))
        return n;
    uint16_t p=1;
    while(p<n)
        p=p<<1;
    return p;
}

uint16_t nextPowerof2Second(uint16_t num)
{
    if(num && (!(num & (num-1))))
        return num;
    uint8_t count=0;
    while(num!=0){
        num>>=1;
        count++;
    }
    return 1<<count;
}
