//Given a string s1 and a string s2, write a snippet to say whether 
//s2 is a rotation of s1 using only one call to strstr routine


#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define ASCII_SIZE 256

uint8_t isRotationEqual(char *str1,char *str2);

int main() {
    char s1[]="hello";
    char s2[]="loh";
    char *s=s2;
    if(isRotationEqual(s1,s2)==1)
        printf("Success\n");
    else
        printf("Failure\n");
    return 0;
}

uint8_t isRotationEqual(char *str1,char *str2)
{
    uint8_t table[ASCII_SIZE]={0};
    //char *temp=*str2;
    strcat(str1,str1);
    //printf("String1:%s\n",str1);
    if(strstr(str1,str2)==NULL)
        return 0;
    else
        return 1;
}
  
