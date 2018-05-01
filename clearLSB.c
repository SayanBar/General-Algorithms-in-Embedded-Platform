//Clear rightmost bit

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1

 
int16_t clearRightmostSetBit(int16_t num);
 

int main()
{
    int16_t num=8;
    printf("%d",clearRightmostSetBit(num));
    return 0;
    
}

int16_t clearRightmostSetBit(int16_t num)
{
    uint8_t pos=log2(num & -num)+1;
    int16_t result=0;
    result=num & (~(1<<(pos-1)));
    return result;
}
