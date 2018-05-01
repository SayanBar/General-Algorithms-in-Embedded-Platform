//Absolute value of a number

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1

 
void myabs(int16_t*);
/* Driver program to test above functions*/
int main()
{
    int16_t num=0;
    myabs(&num);
    printf("Absolute value:%d",num);
    return 0;
}

void myabs(int16_t *num)
{
    if(*num>=0)
        return;
    
        
    uint16_t i;
    for(i=(1<<((sizeof(int16_t)*8)-1));i>0;i=i/2)
       *num^=i;
        
    *num+=1;
        
}
