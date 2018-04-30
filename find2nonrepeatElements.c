//Find two non-repeating elements in a set with XOR

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1

 
int16_t* get2nonrepeatingelements(int16_t *, uint8_t);
 

int main()
{
    int16_t arr[]={2,3,4,3,5,6,2,5,8,9,8,9,0,0}; uint8_t i;
    uint8_t size=sizeof(arr)/sizeof(arr[0]);
    int16_t *ptr=get2nonrepeatingelements(arr,size);
    for(i=0;i<2;i++)
        printf("%d\n",ptr[i]);
    return 0;
    
}

int16_t* get2nonrepeatingelements(int16_t arr[], uint8_t size)
{
    uint8_t i;int16_t res=0;
    int16_t *ptr=(int16_t*)calloc(sizeof(int16_t),2);
    for(i=0;i<size;i++)
        res^=arr[i];
    res&=-res;
    for(i=0;i<size;i++){
        if(arr[i] & res)
            ptr[0]^=arr[i];
        else
            ptr[1]^=arr[i];
            
    }
    return ptr;
}
