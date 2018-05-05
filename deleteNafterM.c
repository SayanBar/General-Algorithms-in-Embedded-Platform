//Delete M nodes after N nodes in a LL

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL -1
#define SUCCESS 1
#define INT_BITS 16
#define ASCII_SIZE 256
 
struct Node{
    int8_t data;
    struct Node* next;
};


int8_t Push(struct Node **head_ref,int8_t);
void print(struct Node *head);
void deleteNafterM(struct Node *head,uint8_t m, uint8_t n);



int main()
{
    struct Node *head=NULL;
    Push(&head,-4);
    Push(&head,10);
    Push(&head,15);
    Push(&head,19);
    Push(&head,19);
    Push(&head,19);
    Push(&head,-4);
    Push(&head,-2);
    Push(&head,2);
    print(head);
  
    deleteNafterM(head,4,3);
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

void deleteNafterM(struct Node *head,uint8_t m, uint8_t n)
{
    if(head==NULL)
        return;
    struct Node *temp=head;
    uint8_t count=1;
    while(count<n){
        if(temp==NULL)
            return;
        temp=temp->next;
        count++;
    }
    struct Node *join=temp;
    temp=temp->next;
    struct Node *next;count=1;
    while(temp){
        if(count>m)
            break;
        next=temp->next;
        if(next==NULL)
            return;
        free(temp);
        temp=next;
        count++;
    }
    join->next=temp;
}
