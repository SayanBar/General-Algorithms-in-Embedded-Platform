#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define FAIL 0
#define ASCII_SIZE 256

char maxOcc(char *str, uint8_t *occ);

int main(void) {
    uint8_t occ;//=malloc(sizeof(int));
	char *str="hahahahaaaaa";
	char character=maxOcc(str,&occ);
	printf("Mac character:%c occurred %" PRIu8 " times\n",character,occ);
	return 0;
}
char maxOcc(char *str, uint8_t *occ){
    if(str==NULL)
        return FAIL;
        
    uint8_t count[ASCII_SIZE]={0};
    
    uint8_t charCount=0;
    
    while(str[charCount++])
        count[str[charCount]]++;
    
    uint8_t max=0;
    char maxOccchar;
    int i;
    for(i=0;i<strlen(str);i++){
        if(max<count[str[i]]){
            max=count[str[i]];
            maxOccchar=str[i];}
        
        }
        *occ=max;
        printf("Max:%d\n",*occ);
        
        return maxOccchar;
}


