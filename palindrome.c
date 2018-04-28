#include <stdio.h>
#include <inttypes.h>
#include <string.h>
void palindrome(char *str);
int main(void) {
	// your code goes here
	//uint64_t x=10000;
	//printf("%" PRIu64 "\n",x);
	char *s="HelleH";
	palindrome(s);
	return 0;
}

void palindrome(char *str)
{
    if(str==NULL)
        printf("NULL STRING\n");
    uint8_t charCount;
    uint8_t strLength=strlen(str);
    uint8_t backCount;
    for(charCount=0,backCount=strLength-1;charCount<backCount;charCount++,backCount--){
        if(str[charCount]!=str[backCount]){
            printf("Not Palindrome:%d %d\n",charCount,backCount);
            
            return;}
    }
    printf("Palindrome\n");
}

