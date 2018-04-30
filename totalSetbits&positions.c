//Return total count of set bits and all positions of set bits in an array

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1
#define ASCII_SIZE 10

 
uint8_t* posOfallSetBits(int16_t num,uint8_t *count);
 
int main()
{
    uint16_t n=65535;
    uint8_t count=0,i;
    uint8_t *pos=posOfallSetBits(n,&count);
    printf("Total Set Bits:%d\n",count);
    for(i=0;i<count;i++)
        printf("PosArray[%d]:%d\n",i,pos[i]);
    
    return 0;
    
}

uint8_t* posOfallSetBits(int16_t num,uint8_t *count)
{
    uint8_t pos=0,i=0;
    uint8_t* setBitArray=(uint8_t *)malloc(sizeof(uint8_t)*sizeof(int16_t)*8);
    
    while(num){
        (*count)++;
        pos=log2(num & -num) + 1;
        setBitArray[i++]=pos;
        num&=~(1<<(pos-1));
    }
    
    return setBitArray;
}

