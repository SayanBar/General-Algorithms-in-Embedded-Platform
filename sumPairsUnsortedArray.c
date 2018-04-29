//Find pairs that sum to a number in an unsorted array

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define ASCII_SIZE 256

void findSumPair(int arr[],uint8_t arr_size,uint8_t sum);

int main() {
    char s1[]="abc";
    char s2[]="loh";
    int arr[]={1,4,7,9,2,8,3,6};
    //scanf("%d",&arr[0]);
    uint8_t size=sizeof(arr)/sizeof(arr[0]);
    findSumPair(arr,size,10);
    
    
    return 0;
    
}

void findSumPair(int arr[],uint8_t arr_size,uint8_t sum)
{
    int i,j,temp;
    for(i=0;i<arr_size;i++)
    {
        for(j=0;j<i+1;j++){
            if(arr[i]<arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(i=0;i<arr_size;i++)
        printf("%d:%d\n",i,arr[i]);
    for(i=0,j=arr_size-1;i<j;){
        if((arr[i]+arr[j])==sum)
            printf("%d + %d\n",arr[i++],arr[j--]);
        else if(arr[i]+arr[j]<sum)
            i++;
        else
            j--;
    }
    
}

