//Compute modulus division by a power-of-2-number

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL -1
#define SUCCESS 1
#define INT_BITS 16
 
int8_t modulus(uint16_t, uint16_t);

/* Driver program to test above functions*/
int main()
{
    printf("Modulus:%d",modulus(71,8));
    return 0;
}

int8_t modulus(uint16_t num, uint16_t d)
{
    if((d && (d & (d-1))))
        return FAIL;
    return ((num) & (d-1));
}
