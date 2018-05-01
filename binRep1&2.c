//Binary representation of a number in 2 different algorithms

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1

 
void binaryRep1(int32_t);
void binaryRep2(int32_t); 
/* Driver program to test above functions*/
int main()
{
    //printf("%d\n",-1>>3);
    printf("binaryRep1:");
    binaryRep1(-1);
    printf("binaryRep2:");
    //-1 won't work for recursion coz this compiler does arithmetic right shift 
    //preserving the sign bit so an input of -1 continues to be -1 and goes into infinite recursion
    binaryRep2(12);
    return 0;
}

void binaryRep1(int32_t num)
{
    uint32_t i=0;
    for(i=(1<<31);i>0;i=i/2)
        num & i? printf("1"):printf("0");
    printf("\n");
}


void binaryRep2(int32_t num)
{
    if(num==0)
        return;
    binaryRep2(num>>1);
    num & 1? printf("1"):printf("0");
}
