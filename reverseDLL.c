//Reverse a Double LL

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
 
typedef struct Node{
    int8_t data;
    struct Node* next;
    struct Node* prev;
}NodeDLL;


int8_t Push(NodeDLL **head_ref,int8_t);
void print(NodeDLL *head);

void ReverseDLL(NodeDLL **head_ref);


int main()
{
    NodeDLL *head=NULL;
    Push(&head,-4);
    Push(&head,10);
    Push(&head,15);
    Push(&head,19);
    Push(&head,14);
    Push(&head,19);
    Push(&head,-4);
    Push(&head,-2);
    Push(&head,2);
    print(head);
  
    
    ReverseDLL(&head);
    printf("\n");
    print(head);
}

int8_t Push(NodeDLL **head_ref,int8_t data)
{
    NodeDLL *newNode=(NodeDLL *)malloc(sizeof(NodeDLL));
    if(newNode==NULL)
        return FAIL;
    newNode->data=data;
    newNode->next=newNode->prev=NULL;
    
    if(*head_ref==NULL)
        *head_ref=newNode;
    else{
        NodeDLL *temp=*head_ref;
        while(temp->next!=NULL)
          temp=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
    }    
    return SUCCESS;
}

void print(NodeDLL *head)
{
    if(head==NULL){
        printf("List Empty\n");
        return;}
    NodeDLL *temp=head;
    printf("Head:%d\n",head->data);
    while(temp){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}


void ReverseDLL(NodeDLL **head_ref)
{
    NodeDLL *current=*head_ref,*temp;
    while(current!=NULL){
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    if(temp)
        *head_ref=temp->prev;
}

