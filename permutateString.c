//Print all permutations of a string

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define ASCII_SIZE 256

void permutation(char *str,uint8_t start,uint8_t end);
void swap(char *a,char *b);

int main() {
    char s1[]="abc";
    char s2[]="loh";
    uint8_t strLen=strlen(s1);
    permutation(s1,0,strLen-1);
    return 0;
}

void swap(char *a, char *b)
{
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void permutation(char *str,uint8_t start,uint8_t end)
{
    static uint8_t x=0;
    if(start==end)
        printf("%d:%s\n",++x,str);
    else{
        int i;
        for(i=start;i<=end;i++){
            swap(str+start,str+i);
            permutation(str,start+1,end);
            swap(str+start,str+i);
        }
    }    
}

