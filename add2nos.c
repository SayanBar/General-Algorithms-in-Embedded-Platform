//Addition of 2 integers

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL -1
#define SUCCESS 1
#define INT_BITS 16
 
int16_t add(int16_t a, int16_t b);
int16_t Add(int16_t x, int16_t y);

/* Driver program to test above functions*/
int main()
{
    printf("Addition:%d\n",add(-10,-8));
    printf("Addition with recursion:%d",Add(-4,2));
    return 0;
}

int16_t add(int16_t a, int16_t b)
{
    while(b!=0){
        int16_t carry = a & b;
        a=a^b;
        b=carry<<1;
    }
    return a;
}

int16_t Add(int16_t x, int16_t y)
{
	if(y==0)
		return x;
	else
		return Add(x^y,(x&y)<<1);
}
