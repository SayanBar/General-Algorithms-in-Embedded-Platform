//Left and right bit rotation

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1
#define INT_BITS 16
 
void right_rotation(uint16_t*,uint8_t shifts);
uint16_t leftRotate(uint16_t n, uint8_t d);
uint16_t rightRotate(uint16_t n, uint8_t d);


/* Driver program to test above functions*/
int main()
{
    uint16_t num=1;
    right_rotation(&num,1);
    printf("left Rotated Value:%d\n",leftRotate(1,1));
    printf("right Rotated Value:%d\n",rightRotate(1,1));
    printf("My right Rotated value:%d",num);
    return 0;
}

void right_rotation(uint16_t *num,uint8_t shifts)
{
    uint8_t count=0;
    uint16_t i=1<<((sizeof(int16_t)*8)-1);
    uint16_t j=1;
    while(count++<shifts){
        if(*num&j){
            *num>>=1;
            *num |=i;
        }
        else
            *num>>1;
        i/=2;
        j*=2;
    }  
}


 
/*Function to left rotate n by d bits*/
uint16_t leftRotate(uint16_t n, uint8_t d)
{
   /* In n<<d, last d bits are 0. To put first 3 bits of n at 
     last, do bitwise or of n<<d with n >>(INT_BITS - d) */
    return (n<<d)|(n>>(INT_BITS - d));
}
 
/*Function to right rotate n by d bits*/
uint16_t rightRotate(uint16_t n, uint8_t d)
{
   /* In n>>d, first d bits are 0. To put last 3 bits of at 
     first, do bitwise or of n>>d with n <<(INT_BITS - d) */
    return (n>>d)| (n<<(INT_BITS-d));
}
