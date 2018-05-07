//Stack Implementation with Linked List

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1

typedef struct Stack{
    int8_t data;
    struct Stack *next;
}StackNode;

uint8_t Push(StackNode **,int8_t data);
uint8_t Pop(StackNode **);
void Top(StackNode *);


int main()
{
    StackNode *head=NULL;
    Push(&head,-5);
    Pop(&head);
    Push(&head,7);
    Push(&head,0);
    Push(&head,9);
    Push(&head,80);
    Pop(&head);
    Pop(&head);
    Pop(&head);
    Top(head);
    return 0;
}


uint8_t Push(StackNode **head_ref,int8_t data)
{
    StackNode *newNode=(StackNode *)malloc(sizeof(StackNode));
    if(!newNode)
        return FAIL;
    newNode->data=data;
    newNode->next=NULL;
    if(!(*head_ref))
        *head_ref=newNode;
    else{
        newNode->next=*head_ref;
        *head_ref=newNode;
    }    
    return SUCCESS;
}


uint8_t Pop(StackNode **head_ref)
{
    if(!(*head_ref)){
        printf("Buffer Underflow\n");
        return FAIL;
    }
        
    StackNode *temp=*head_ref;
    *head_ref=temp->next;
    free(temp);temp=NULL;
    return SUCCESS;
}


void Top(StackNode *head_ref)
{
    if(!head_ref){
        printf("Buffer Empty\n");
        return;
    }
    else
        printf("Top:%d",head_ref->data);
}
