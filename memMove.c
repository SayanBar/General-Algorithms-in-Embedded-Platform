//My Memmove
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
 
void *my_memmove(void *dest, const void *src, size_t n);

int main()
{
    char string[100];
    char *src="Hi there";
    my_memmove(string,src,strlen(src));
    printf("String:%s",string);
    return 0;
}

void *my_memmove(void *dest, const void *src, size_t n)
{
    if(!src || !n){
        printf("Bye");
        return NULL;
    }
    char *str1=(char *)dest;
    char *str2=(char *)src;
    uint8_t strSize=strlen(src);
    char temp[strSize];
    uint8_t i;
    for(i=0;i<strSize;i++)
        temp[i]=str2[i];
    for(i=0;i<strSize;i++)
        str1[i]=temp[i];
    return dest;
}
    
    

