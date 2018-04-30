//Find whether it is a multiple of 3

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define SUCCESS 1
#define ASCII_SIZE 10

uint8_t multipleOf3(int16_t);

int main() {
    char s1[]="abc";
    char s2[]="loh";
    
    if(multipleOf3(31)==SUCCESS)
        printf("True");
    else
        printf("False");
    return 0;
    
}

uint8_t multipleOf3(int16_t n)
{
    if(n<0) 
        n=-n;
    if(n==0)
        return SUCCESS;
    if(n==1)
        return FAIL;
    uint8_t oddCount=0,evenCount=0;
    
    while(n){
        if(n&1)
            oddCount++;
        n>>=1;
        if(n&1)
            evenCount++;
        n>>=1;
    }
    return multipleOf3(abs(oddCount-evenCount));
    
}
