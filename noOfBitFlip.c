//Count number of bits to be flipped to convert A to B

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1
#define ASCII_SIZE 10

 
uint8_t flipCount(int16_t a,int16_t b);
uint8_t countSetBits(int16_t num);
 
int main()
{
    int16_t a=-1,b=65534;
    printf("Number of bit flips:%d",flipCount(a,b));
    
    return 0;
    
}

uint8_t flipCount(int16_t a,int16_t b)
{
    if(a==b)
        return 0;
    int16_t res=a^b;
    return countSetBits(res);
}

uint8_t countSetBits(int16_t num){
    uint8_t count=0;
    while(num){
        count+=(num&1);
        num>>=1;
    }
    return count;
}
