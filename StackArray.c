//Stack Implementation with Array

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1
#define MAX_BUFF 4

typedef struct Stack{
    int8_t top;
    int8_t arr[MAX_BUFF];
}Stack;

uint8_t Push(Stack *,int8_t data);
uint8_t Pop(Stack *);
void Top(Stack *);


int main()
{
    Stack s;
    s.top=0;

    Push(&s,5);
    Push(&s,86);
    Push(&s,76);
    Push(&s,23);
    // Pop(&s);
    // Pop(&s);
    // Pop(&s);
    //Pop(&s);
    //Pop(&s);
    Top(&s);
    return 0;
}


uint8_t Push(Stack *s,int8_t data)
{

    int8_t *p=s->arr;
    if(s->top==MAX_BUFF){
        printf("Buffer Overflow\n");
        return FAIL;
    }
    else{
        s->top+=1;
        p[s->top]=data;
        return SUCCESS;
    }
    
}


uint8_t Pop(Stack *s)
{
    int8_t *p=s->arr;
    if(s->top==0){
        printf("Buffer Underflow\n");
        return FAIL;
    }
    else{
        p[s->top]=0;
        s->top-=1;
        return SUCCESS;
    }
}


void Top(Stack *s)
{
    if((s->top)>0)
        printf("Top:%d",s->arr[s->top]);
    else
        printf("Buffer Empty\n");
}
