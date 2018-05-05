//My Memcopy
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
 
void *my_memcopy(void *dest, const void *src, size_t n);

int main()
{
    char string[100];
    char *src="Hi there";
    my_memcopy(string,src,strlen(src));
    printf("String:%s",string);
    return 0;
}

void *my_memcopy(void *dest, const void *src, size_t n)
{
    if(!src || !n){
        printf("Bye");
        return NULL;
    }
    char *str1=(char *)dest;
    char *str2=(char *)src;
    
    uint8_t i;
    for(i=0;i<strlen(str2);i++)
        str1[i]=str2[i];
    return dest;
}
    
    

