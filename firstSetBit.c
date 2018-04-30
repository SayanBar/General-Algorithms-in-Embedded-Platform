//Position of first set bit from the right

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define SUCCESS 1
#define ASCII_SIZE 10


 
uint16_t getFirstSetBitPos(int16_t n)
{
   return (log2(n&-n)+1);
}
 
int main()
{
    int16_t n = -10;
    printf("%u", getFirstSetBitPos(n));
    return 0;
}

