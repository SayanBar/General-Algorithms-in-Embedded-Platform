//Queue Implementation with Linked List

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1

typedef struct Queue{
    int8_t data;
    struct Queue *next;
}QueueNode;

uint8_t Enqueue(QueueNode **,int8_t data);
uint8_t Dequeue(QueueNode **);
void Top(QueueNode *);


int main()
{
    QueueNode *head=NULL;
    Enqueue(&head,-5);
    Dequeue(&head);
    Enqueue(&head,7);
    Enqueue(&head,0);
    Enqueue(&head,9);
    Enqueue(&head,-80);
    Dequeue(&head);
    Dequeue(&head);
    Dequeue(&head);
    // Dequeue(&head);
    // Dequeue(&head);
    Top(head);
    return 0;
}


uint8_t Enqueue(QueueNode **head_ref,int8_t data)
{
    QueueNode *newNode=(QueueNode *)malloc(sizeof(QueueNode));
    if(!newNode)
        return FAIL;
    newNode->data=data;
    newNode->next=NULL;
    if(!(*head_ref))
        *head_ref=newNode;
    else{
        QueueNode *temp=*head_ref;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=newNode;
    }    
    return SUCCESS;
}


uint8_t Dequeue(QueueNode **head_ref)
{
    if(!(*head_ref)){
        printf("Buffer Underflow\n");
        return FAIL;
    }
        
    QueueNode *temp=*head_ref;
    *head_ref=temp->next;
    free(temp);
    temp=NULL;
    return SUCCESS;
}


void Top(QueueNode *head_ref)
{
    if(!head_ref){
        printf("Buffer Empty\n");
        return;
    }
    else
        printf("Top:%d",head_ref->data);
}
