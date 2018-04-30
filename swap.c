//Swao two numbers using XOR

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1
#define ASCII_SIZE 10

 

 

int main()
{
  int8_t x = -10, y = -5;
 
  // Code to swap 'x' (1010) and 'y' (0101)
  x = x ^ y;  // x now becomes 15 (1111)
  y = x ^ y;  // y becomes 10 (1010)
  x = x ^ y;  // x becomes 5 (0101)
 
  printf("After Swapping: x = %d, y = %d", x, y);
 
    
    return 0;
    
}


