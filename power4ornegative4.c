//Power of 4 or -4

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1
#define ASCII_SIZE 10

 
uint8_t powerOf4ornegative4(int16_t);
 

int main()
{
    int16_t x = -256;// y = -5;
    if(powerOf4ornegative4(x)==1)
        printf("Power of 4 or -4\n");
    else
        printf("Not a Power of 4 or -4\n");
 
    
    return 0;
    
}

uint8_t powerOf4ornegative4(int16_t num)
{
    uint8_t negFlag=0;
    if(num<0){
        negFlag=1;
        num=-num;
    }
        
    if(num && (!(num & (num-1) ))){
        int16_t res=((int)(log2(num & -num)));
        if((res % 2==0) && negFlag==1 && (((res/2)%2)!=0) )
            return 1;
        if((res % 2==0) && negFlag==0)
            return 1;
    }
    return 0;
}
