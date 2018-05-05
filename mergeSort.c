//Merge Sort
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
 
void MergeSort(int8_t arr[],uint8_t start,uint8_t end);
void Merge(int8_t arr[],uint8_t start, uint8_t end, uint8_t mid);

int main()
{
    int8_t arr[]={2,-4,5,1,0,67,34,-12};
    uint8_t size=sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,0,size-1);
    uint8_t i;
    for(i=0;i<size;i++)
        printf("arr[%d]:%d  ",i,arr[i]);
    return 0;
}

void MergeSort(int8_t arr[],uint8_t start,uint8_t end)
{
    if(start<end){
        uint8_t mid=start+(end-start)/2;
        
        MergeSort(arr,start,mid);
        MergeSort(arr,mid+1,end);
        
        Merge(arr,start,end,mid);
    }
}
void Merge(int8_t arr[],uint8_t start, uint8_t end, uint8_t mid)
{
    uint8_t size_a=mid-start+1;
    uint8_t size_b=end-mid;
    
    int8_t left[size_a],right[size_b];
    uint8_t i,j,k;
    for(i=0;i<size_a;i++)
        left[i]=arr[start+i];
    for(j=0;j<size_b;j++)
        right[j]=arr[j+mid+1];
    i=0,j=0,k=start;
    while(i<size_a && j<size_b){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    
    while(i<size_a){
        arr[k]=left[i];
        i++;k++;
    }
    while(j<size_b){
        arr[k]=right[j];
        j++;k++;
    }
}
