//Quick Sort
#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL -1
#define SUCCESS 1
#define INT_BITS 16
#define ASCII_SIZE 256
 
int8_t Partition(int8_t arr[], int8_t start, int8_t end);
void QuickSort(int8_t arr[], int8_t start, int8_t end);
void swap(int8_t *a, int8_t *b);

int main()
{
    int8_t arr[]={2,4,5,1,0,67,34,12};
    uint8_t size=sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,size-1);
    int8_t i;
    for(i=0;i<size;i++)
        printf("arr[%d]:%d  ",i,arr[i]);
    return 0;
}

int8_t Partition(int8_t arr[], int8_t start, int8_t end)
{
    int8_t pivot=arr[end];
    int8_t partIndex=start-1;
    int8_t i;
    for(i=start;i<end;i++){
        if(arr[i]<=pivot){
            partIndex++;
            swap(&arr[partIndex],&arr[i]);
        }
    }
    swap(&arr[partIndex+1],&arr[end]);
    return partIndex+1;
    
}
void QuickSort(int8_t arr[], int8_t start, int8_t end)
{
    if(start<end){
        int8_t partIndex=Partition(arr,start,end);
        QuickSort(arr,start,partIndex-1);
        QuickSort(arr,partIndex+1,end);
    }
}

void swap(int8_t *a, int8_t *b)
{
    int8_t temp=*a;
    *a=*b;
    *b=temp;
}
