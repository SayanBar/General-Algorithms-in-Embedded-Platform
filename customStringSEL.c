/*Program to create a custom string
Example:Input string:<hello> world/
Output String: /<hello/> world//   
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIMIT 500
#define FRONT_SLASH '/'
#define GREATER_THAN '>'
#define LESSER_THAN '<'

char * CustomString(const char *str);

int main(void) {
	
	char stringInput[MAX_LIMIT]="<><><>/hello<><>/ world/";
	char *str=CustomString(stringInput);
	printf("%s",str);
	
	return 0;
}

//Function to return the Custom String
char * CustomString(const char *str){
    if(!str)
        return NULL;
    int i=0,count=0,charCount=0;
    //Counting the number of escape characters and total characters in the string in order to allocate space for malloc function
    while(str[i]){
        if((str[i]==FRONT_SLASH) || (str[i]==GREATER_THAN) || (str[i]==LESSER_THAN))
            count++;
        charCount++;
		i++;
    }
  
    char *final=(char *)malloc(charCount+count+1);
    int j=0;
    i=0;
    //Traversing through the string to create final customed string
    while(str[i]){
        if((str[i]==FRONT_SLASH) || (str[i]==GREATER_THAN) || (str[i]==LESSER_THAN)){
            final[j++]=FRONT_SLASH;
            final[j++]=str[i++];
        }
        else
            final[j++]=str[i++];
        
    }
    //Adding NULL to terminate string
    final[j]='\0';
    return final;
}

