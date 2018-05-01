//Adding 1 to an integer

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1

 
int16_t addOne(int16_t x)
{
   return (-(~x));
}
 
/* Driver program to test above functions*/
int main()
{
  printf("%d\n", addOne(-13));
  printf("%d", addOne(13));
  return 0;
}
