//Selection Bubble & Insertion Sort

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL -1
#define SUCCESS 1
#define INT_BITS 16
 
int8_t* SelectionSort(int8_t arr[],uint8_t n);
int8_t* BubbleSort(int8_t arr[],uint8_t n);
int8_t* InsertionSort(int8_t arr[],uint8_t n);
void swap(int8_t *a,int8_t *b);
/* Driver program to test above functions*/
int main()
{
    int8_t arr[9]={8,76,63,34,59,-2,0,-11,4};
    int8_t size=sizeof(arr)/sizeof(arr[0]);
    int8_t *arr1=SelectionSort(arr,size);
    int8_t *arr2=BubbleSort(arr,size);
    int8_t *arr3=InsertionSort(arr,size);
    int8_t i;
    printf("Selection Sort\n");
    for(i=0;i<size;i++)
        printf("arr1[%d]:%d ",i,arr1[i]);
    printf("\nBubble Sort\n");
    for(i=0;i<size;i++)
        printf("arr2[%d]:%d ",i,arr2[i]);
    printf("\nInsertion Sort\n");
    for(i=0;i<size;i++)
        printf("arr3[%d]:%d ",i,arr3[i]);
    return 0;
}

void swap(int8_t *a,int8_t *b)
{
    int8_t temp=*a;
    *a=*b;
    *b=temp;
}

int8_t* SelectionSort(int8_t arr[],uint8_t n)
{   
    uint8_t i,j,minIndex;
    for(i=0;i<n-1;i++){
        minIndex=i;
        for(j=i+1;j<n;j++)
            if(arr[minIndex]>arr[j])
                minIndex=j;
        swap(&arr[i],&arr[minIndex]);
    }
    return arr;
}


int8_t * BubbleSort(int8_t arr[],uint8_t n)
{
    uint8_t i,j;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
                
    return arr;
}

int8_t* InsertionSort(int8_t arr[],uint8_t n)
{
    uint8_t i,key;
    int8_t j;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    return arr;
}


