#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIMIT 500
#define FRONT_SLASH '/'
#define GREATER_THAN '>'
#define LESSER_THAN '<'

char * CustomString(char *str);

int main(void) {
	
	char stringInput[MAX_LIMIT]="<><><>/hello<><>/ world/";
	char *str=CustomString(stringInput);
	printf("%s",str);
	
	return 0;
}

char * CustomString(char *str){
    if(!str)
        return NULL;
    int i=0,count=0;
    while(str[i]){
        if((str[i]==FRONT_SLASH) || (str[i]==GREATER_THAN) || (str[i]==LESSER_THAN))
            count++;
        i++;
    }
  
    char *final=(char *)malloc(strlen(str)+count+1);
    int j=0;
    i=0;
    while(str[i]){
        if((str[i]==FRONT_SLASH) || (str[i]==GREATER_THAN) || (str[i]==LESSER_THAN)){
            final[j++]='/';
            final[j++]=str[i++];
        }
        else
            final[j++]=str[i++];
        
    }
    final[j]='\0';
    return final;
}

