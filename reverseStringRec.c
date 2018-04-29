//Write a recursive C function to print reverse of a given string.

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define ASCII_SIZE 256

void RevRec(char *str);

int main() {
    char s1[]="hello";
    char s2[]="loh";
    //char *s=s2;
    RevRec(s1);
    return 0;
}

void RevRec(char *str){
    if(*str=='\0')
        return;
    //str++;
    RevRec(str+1);
    printf("%c",*str);
}
