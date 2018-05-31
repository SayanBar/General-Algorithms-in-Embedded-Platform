#include <stdio.h>

int main(void) {
	// your code goes here
	int a[2][3]={1,2,3,4,5,6};
	int (*ptr)[3]=a;
	printf("%d %d %d",(*ptr)[0],(*ptr)[1],(*ptr)[2]);
	ptr++;
	printf(" / %d",**ptr);
	printf(" / %d %d %d",(*ptr)[0],(*ptr)[1],(*ptr)[2]);
	return 0;
}
