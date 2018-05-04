//Reverse a linklist with and without recursion

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
int8_t reverseLL(struct Node **head_ref);
void reverseRecLL(struct Node **head_ref);
void recursiveReverse(struct Node** head_ref);
void print(struct Node *head);

int main()
{
    struct Node *head=NULL;
    Push(&head,4);
    Push(&head,10);
    Push(&head,5);
    Push(&head,7);
    Push(&head,19);
    Push(&head,34);
    Push(&head,2);
    print(head);
    // if(reverseLL(&head)==FAIL)
    //     printf("Failed\n");
    // else
    //     printf("Success\n");
    reverseRecLL(&head);
    //recursiveReverse(&head);
    print(head);
    return 0;
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
    struct Node *temp=head;
    printf("Head:%d\n",head->data);
    while(temp){
        printf("%d  ",temp->data);
        temp=temp->link;
    }
}

int8_t reverseLL(struct Node **head_ref)
{
    struct Node *temp=*head_ref;
    if(temp==NULL)
        return FAIL;
    struct Node *current=temp,*prev=NULL,*next;
    while(current!=NULL){
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    temp=prev;
    *head_ref=temp;
    return SUCCESS;
}

void reverseRecLL(struct Node **head_ref)
{
    if(*head_ref==NULL)
        return;
    struct Node *first=*head_ref;
    struct Node *second=first->link;
    if(second==NULL)
        return;
    reverseRecLL(&second);
    first->link->link=first;
    first->link=NULL;
    *head_ref=second;
}

void recursiveReverse(struct Node** head_ref)
{
    struct Node* first;
    struct Node* rest;
    if (*head_ref == NULL)
       return;   
    first = *head_ref;  
    rest  = first->link;
    if (rest == NULL)
       return;   
    recursiveReverse(&rest);
    first->link->link  = first; 
    first->link  = NULL;
    *head_ref = rest;              
}
