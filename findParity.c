//Find even or odd parity

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define ASCII_SIZE 10

uint8_t parity(int8_t n);

int main() {
    char s1[]="abc";
    char s2[]="loh";
    
    if(parity(12)==1)
        printf("Odd Parity");
    else
        printf("Even Parity");
    
    return 0;
    
}

uint8_t parity(int8_t n)
{   uint8_t parity=0;
    while(n){
        parity=!parity;
        n= n & (n-1);
    }
    return parity;
}
