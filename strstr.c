// My Strstr
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
 
char * my_strstr(const char *haystack,const char *needle);

int main()
{
    const char haystack[100]="Hello there hi are you?";
    const char needle[50]="hi";
    printf("String:%s",my_strstr(haystack,needle));
    return 0;
}

char * my_strstr(const char *haystack,const char *needle)
{
    if(!haystack || !needle)
        return NULL;
    
    char *q=(char *)malloc(sizeof(char)*(strlen(haystack)+1));
    char *p=haystack;
    char *target=needle;
    uint8_t i=1;
    while(*p){
        target=needle;
        q=p;
        while(*p && *target && *target==*p){
            p++;
            target++;
        }
        if(!*target)
            return q;
        else
            p++;
    }
    
}
