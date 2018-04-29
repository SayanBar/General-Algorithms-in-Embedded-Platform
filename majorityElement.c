//Find majority element in an array(if no of occurences of the element is greater than size/2)

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define ASCII_SIZE 10

int8_t majority(uint8_t arr[],uint8_t arr_size);

int main() {
    char s1[]="abc";
    char s2[]="loh";
    uint8_t arr[]={1,4,7,9,2,8,3,6,9,9,9,9,9,9,9};
    //scanf("%d",&arr[0]);
    uint8_t size=sizeof(arr)/sizeof(arr[0]);
    int8_t element=majority(arr,size);
    if(element!=-1)
        printf("Majority element:%d\n",element);
    else
        printf("No majority element found\n");
    
    return 0;
    
}

int8_t majority(uint8_t arr[],uint8_t arr_size)
{
    uint8_t i;
    uint8_t cutoff=arr_size/2;
    printf("Cutoff:%d\n",cutoff);
    uint8_t table[ASCII_SIZE]={0};
    for(i=0;i<arr_size;i++){
        table[arr[i]]++;
    }
    for(i=0;i<10;i++)
        printf("%d:%d\n",i,table[i]);
    for(i=0;i<arr_size;i++){
        if(table[arr[i]]>cutoff)
            return arr[i];

    }
    return -1;    
}
