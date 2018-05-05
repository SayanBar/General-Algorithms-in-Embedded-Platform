//My strcmp
#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL -1
#define SUCCESS 0
#define INT_BITS 16
#define ASCII_SIZE 256
 
int8_t my_strcmp(const char *str1, const char * str2);

int main()
{
    const char *str1="Hellothere";
    const char *str2="Hello";
    
    printf("String Compare:%d",my_strcmp(str1,str2));
    return 0;
}

int8_t my_strcmp(const char *str1, const char * str2)
{
    if(!str1 || !str2)
        return FAIL;
    while(*str1 && *str2 && *(str1++)==*(str2++));
    if(!*str1 && !*str2)
        return SUCCESS;
    else
        return *str1-*str2;
}
    

