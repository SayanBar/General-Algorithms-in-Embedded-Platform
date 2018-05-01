//Find only Set bit

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1

 
uint8_t findOnlySetBit(int16_t num);
uint8_t Powerof2(int16_t x);
 
/* Driver program to test above functions*/
int main()
{
    uint8_t ret;
    if((ret=findOnlySetBit(8))==FAIL)
        printf("More than 1 set bit");
    else
        printf("Positiom:%d\n",ret);
  return 0;
}

uint8_t findOnlySetBit(int16_t num)
{
    if(!Powerof2(num))
        return FAIL;
    else
        return (log2(num & -num)+1);
}

uint8_t Powerof2(int16_t x)
{
    return (x && (!(x & (x-1))));
}
