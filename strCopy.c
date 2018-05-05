//My string copy
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
 
void my_strcpy(char *dest,const char *src);

int main()
{
    char dest[100];
    char * src="Hello";
    //char * dest=
    my_strcpy(dest,src);
    printf("String:%s",dest);
    return 0;
}

void my_strcpy(char *dest,const char *src)
{
    if(!src)
        return NULL;
    //char * dest=(char * ) malloc(sizeof(char) * (strlen(src)+1));
    char *string=dest;
    while( * (string++) = * (src++));
    printf("Dest:%s\n",dest);
    //return dest;
    
}
