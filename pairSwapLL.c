//Pairwise swap of elements in LL

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
void pairSwap(struct Node **head_ref);



int main()
{
    struct Node *head=NULL;
    Push(&head,4);
    Push(&head,10);
    Push(&head,15);
    Push(&head,17);
    Push(&head,19);
    Push(&head,21);
    Push(&head,26);
    Push(&head,2);
    Push(&head,78);
    print(head);
  
    pairSwap(&head);
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

void pairSwap(struct Node **head_ref)
{
    if(*head_ref==NULL || (*head_ref)->next==NULL)
        return;
    struct Node *current=(*head_ref)->next;
    struct Node *next;//=(*head_ref)->next;
    struct Node *prev=*head_ref;
    *head_ref=current;
    while(1){
        next=current->next;
        current->next=prev;
        
        
        if(next==NULL || next->next==NULL){
            prev->next=next;
            break;
        }
        prev->next=next->next;
        prev=next;
        current=prev->next;
        
    }
    
    
    
    
    
    
    
}
