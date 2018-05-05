//Remove duplicates in an unsorted LL

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
void removeDupUnsortedLL(struct Node *head);



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
  
    removeDupUnsortedLL(head);
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

void removeDupUnsortedLL(struct Node *head)
{
    if(head==NULL)
        return;
    char table[ASCII_SIZE]={0};
    struct Node* current=head;
    while(current->next!=NULL){
        if(table[current->next->data]==0){
            table[current->next->data]++;
            current=current->next;
        }
        else{
            struct Node * temp=current->next;
            current->next=temp->next;
            free(temp);
        }
            
        
    }
    
    
}
