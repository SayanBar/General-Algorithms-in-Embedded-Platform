//Multiply a number by 7

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define ASCII_SIZE 10

 
int16_t multiplyBySeven(int16_t n)
{  
    uint8_t negFlag=0;
    if(n<0){
        n=-n;
        negFlag=1;
    }
    /* Note the inner bracket here. This is needed 
       because precedence of '-' operator is higher 
       than '<<' */
    int16_t res=((n<<3) - n);
    if(negFlag==1)
        return (-res);
    else
        return res;
}
 
/* Driver program to test above function */
int main()
{
    int16_t n = 5;
    printf("%d", multiplyBySeven(n));
    return 0;
}

