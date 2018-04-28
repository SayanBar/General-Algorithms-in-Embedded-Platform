#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define ASCII_SIZE 256

char * printDup(char *str);

int main(void) {
	char str[]="xyyyyyyyyyyzzzzzzzzzzzzzzz3245813543wwwwqwqweeccee%%###**";
	char *str1=printDup(str);
	printf("%s",str1);
	return 0;
}

char* printDup(char *str){
    uint8_t count[ASCII_SIZE]={0};
    printf("String length:%d\n",strlen(str));
    //char *finalStr=malloc(sizeof(char)*strlen(str));
    uint8_t counter=0;
    uint8_t finalCount=0;
    while(counter<strlen(str)){
        count[str[counter]]++;
        if(count[str[counter]]==2)
            str[finalCount++]=str[counter];
        counter++;
            
    }
    
    str[finalCount]='\0';
    return str;
}
