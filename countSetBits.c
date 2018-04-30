//Count number of set bits

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define SUCCESS 1
#define ASCII_SIZE 10

 
uint8_t countSetBits(int16_t num);
 
int main()
{
     uint16_t n=255;
 
     printf("Set Bits:%d", countSetBits(n));

     return 0;
    
}

uint8_t countSetBits(int16_t num)
{
    uint8_t count=0;
    while(num){
        count+=num&1;
        num>>=1;
    }
    return count;
}

