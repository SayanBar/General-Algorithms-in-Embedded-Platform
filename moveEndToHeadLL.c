//Move last element to front of a given Linked List

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL -1
#define SUCCESS 1
#define INT_BITS 16
 
struct Node{
    int8_t data;
    struct Node* next;
};


int8_t Push(struct Node **head_ref,int8_t);
void print(struct Node *head);
void moveEndToHead(struct Node **head_ref);



int main()
{
    struct Node *head=NULL;
    Push(&head,4);
    Push(&head,10);
    Push(&head,15);
    Push(&head,17);
    Push(&head,17);
    Push(&head,17);
    Push(&head,26);
    Push(&head,26);
    Push(&head,78);
    print(head);
  
    moveEndToHead(&head);
    printf("\n");
    print(head);
}

int8_t Push(struct Node **head_ref,int8_t data)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
        return FAIL;
    newNode->data=data;
    newNode->next=NULL;
    if(*head_ref==NULL)
        *head_ref=newNode;
    else{
        struct Node *temp=*head_ref;
        while(temp->next!=NULL)
          temp=temp->next;
        temp->next=newNode;
    }    
    return SUCCESS;
}

void print(struct Node *head)
{
    if(head==NULL){
        printf("List Empty\n");
        return;}
    struct Node *temp=head;
    printf("Head:%d\n",head->data);
    while(temp){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}

void moveEndToHead(struct Node **head_ref)
{
    if(*head_ref==NULL)
        return;
    struct Node *temp=*head_ref;
    while(temp->next->next)
        temp=temp->next;
    struct Node *newHead=temp->next;
    temp->next=NULL;
    newHead->next=(*head_ref);
    *head_ref=newHead;
}
