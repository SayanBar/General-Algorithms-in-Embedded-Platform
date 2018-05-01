//Minimum and maximum between 2 integers with XOR and AND

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1

 
int16_t findMinAnd(int16_t a,int16_t b);
int16_t findMaxAnd(int16_t a,int16_t b);

int16_t findMinXor(int16_t a,int16_t b);
int16_t findMaxXor(int16_t a,int16_t b);

int main()
{
    int16_t a=-8,b=-10;
    printf("%d\n",findMaxXor(a,b));
    printf("%d\n",findMinXor(a,b));
    printf("%d\n",findMaxAnd(a,b));
    printf("%d\n",findMinAnd(a,b));
    return 0;
    
}

int16_t findMinAnd(int16_t a,int16_t b){
    uint8_t size=sizeof(int16_t)*8;
    return (b+((a-b) & ((a-b)>>(size-1))));
    
}
int16_t findMaxAnd(int16_t a,int16_t b)
{
    uint8_t size=sizeof(int16_t)*8;
    return (a-((a-b) & ((a-b)>>(size-1))));
}

int16_t findMinXor(int16_t a,int16_t b)
{
    return b^((a^b) & -(a<b));
}
int16_t findMaxXor(int16_t a,int16_t b)
{
    return a^((a^b) & -(a<b));
}

