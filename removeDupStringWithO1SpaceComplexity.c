#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define ASCII_SIZE 256

char * removDup(char *str);

int main(void) {
	char str[]="xxxxxyyyyyyyyyyzzzzzzzzzzzzzzz32453543wwwwqwqweeccee%%###**";
	char *str1=removDup(str);
	printf("%s",str1);
	return 0;
}

char* removDup(char *str){
    uint8_t count[ASCII_SIZE]={0};
    printf("String length:%d\n",strlen(str));
    //char *finalStr=malloc(sizeof(char)*strlen(str));
    uint8_t counter=0;
    uint8_t finalCount=0;
    while(counter<strlen(str)){
        //printf("Counter:%d\n",counter);
        if(count[str[counter]]==0){
            count[str[counter]]++;
            str[finalCount++]=str[counter];
            
        }
        counter++;
            
    }
    
    str[finalCount]='\0';
    return str;
}
