//Given two strings s1 & s2, remove those characters 
//from first string which are present in second string. 
//Both the strings are different and contain only lowercase characters.

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define ASCII_SIZE 256

void remDupChar(char *str1,char **str2);

int main() {
    char s1[]="Hello";
    char s2[]="Hellothere";
    char *s=s2;
    remDupChar(s1,&s);
    printf("%s",s2);
	return 0;
}

void remDupChar(char *str1,char **str2)
{
    uint8_t table[ASCII_SIZE]={0};
    char *temp=*str2;
    //printf("%c\n",temp[0]);
    //temp[0]='j';
    uint8_t charCount=0;
    
    while(charCount<strlen(str1)){
        table[str1[charCount]]++;
        charCount++;
    }
    
    charCount=0;
    uint8_t finalCount=0;
    while(temp[charCount]){
        if(table[temp[charCount]]==0)
            temp[finalCount++]=temp[charCount];
        charCount++;
    }
    temp[finalCount]='\0';
    
}
