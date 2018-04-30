//Reverse bits

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define SUCCESS 1
#define ASCII_SIZE 10

 
uint16_t reverseBits(uint16_t num);
 
int main()
{
     uint16_t n=1;
 
     printf("%d", reverseBits(n));

     return 0;
    
}

uint16_t reverseBits(uint16_t num)
{
    uint8_t noBits=sizeof(uint16_t)*8;
    uint16_t reverse=0,i;
    
    for(i=0;i<noBits;i++)
    {
        if(num & (1<<i))
            reverse |= 1<<((noBits-1)-i);
    }
    return reverse;
}

