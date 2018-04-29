//Write a general C function which could reverse an integer array or string

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define ASCII_SIZE 256

void *Rev(void *arr, int n,uint8_t code);

int main() {
    char s1[]="hello";
    char s2[]="loh";
    int arr[]={10,11,12,13};
    uint8_t size=sizeof(arr)/sizeof(arr[0]);
    uint8_t strLength=strlen(s1);
    
    //printf("%d",arr[0]);
    //char *s=s2;
    char *s3=(char *)Rev(s1,strLength,0);
    int *array=(int *)Rev(arr,size,1);
    printf("In Main\n");
    int i;
    for(i=0;i<size;i++)
            printf("%d:%d\n",i,array[i]);
    printf("%s:\n",s3);
    return 0;
}

void * Rev(void *arr,int n,uint8_t code){
    if(code==1){
        int *array=(int *)malloc(sizeof(int)*n);
        array=(int *)arr;
        //printf("%d\n",arr[0]);
        int temp;
        uint8_t start=0;
        uint8_t end=n-1;
        while(start<end){
            temp=array[start];
            array[start]=array[end];
            array[end]=temp;
            end--;
            start++;
        }
        int i;
        for(i=0;i<n;i++)
            printf("%d:%d\n",i,array[i]);
        return arr;
    }
    else{
        char *array=(char *)malloc(sizeof(char)*n);
        array=(char *)arr;
        //printf("%s\n",arr);
        char temp;
        uint8_t start=0;
        uint8_t end=n-1;
        while(start<end){
            temp=array[start];
            array[start]=array[end];
            array[end]=temp;
            end--;
            start++;
        }
        printf("%s:\n",array);
        return arr;
    }
    
    
}


