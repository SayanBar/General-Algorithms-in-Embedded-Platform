//If a number is power of 2

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define SUCCESS 1
#define ASCII_SIZE 10


 
uint8_t isPowerof2(uint16_t n);
 
/* Driver program to test above function */
int main()
{
    uint16_t n = 15;
    if(isPowerof2(n)==SUCCESS)
        printf("True\n");
    else
        printf("False\n");
    return 0;
}

uint8_t isPowerof2(uint16_t n){
	
	return (n && (!(n & (n-1))));
}
