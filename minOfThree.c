//Compute minimum of three integers

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL -1
#define SUCCESS 1
#define INT_BITS 16
 
int16_t minofThree(int16_t a,int16_t b,int16_t c);
int16_t minofTwo(int16_t a, int16_t b);

/* Driver program to test above functions*/
int main()
{
    printf("Smallest:%d",minofThree(10,-1,8));
    return 0;
}


int16_t minofThree(int16_t a,int16_t b,int16_t c)
{
    return minofTwo(a,minofTwo(b,c));
}

int16_t minofTwo(int16_t a, int16_t b)
{
    return b^((a^b) & ((a-b)>>(INT_BITS-1)));
}
