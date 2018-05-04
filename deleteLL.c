//Delete a Linklist

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
    struct Node* link;
};


int8_t Push(struct Node **head_ref,int8_t);

void print(struct Node *head);
void deleteLL(struct Node **head_ref);



int main()
{
    struct Node *head=NULL;
    Push(&head,4);
    Push(&head,10);
    Push(&head,15);
    Push(&head,17);
    Push(&head,19);
    Push(&head,23);
    Push(&head,26);
    Push(&head,29);
    Push(&head,78);
    print(head);
  
    printf("\n");

    deleteLL(&head);
    print(head);
}

int8_t Push(struct Node **head_ref,int8_t data)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
        return FAIL;
    newNode->data=data;
    newNode->link=NULL;
    if(*head_ref==NULL)
        *head_ref=newNode;
    else{
        struct Node *temp=*head_ref;
        while(temp->link!=NULL)
          temp=temp->link;
        temp->link=newNode;
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
        temp=temp->link;
    }
}

void deleteLL(struct Node **head_ref)
{
    struct Node *temp=*head_ref;
    struct Node *next;
    while(temp){
        next=temp->link;
        free(temp);
        temp=NULL;
        temp=next;
    }
    *head_ref=NULL;
}
