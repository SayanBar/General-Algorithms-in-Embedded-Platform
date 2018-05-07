//Insert in a sorted Linked List

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
void insertSortedLL(struct Node **head, int8_t num);
void print(struct Node *head);



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
    insertSortedLL(&head,79);
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
    struct Node *temp=head;
    printf("Head:%d\n",head->data);
    while(temp){
        printf("%d  ",temp->data);
        temp=temp->link;
    }
}

void insertSortedLL(struct Node **head, int8_t num)
{
    struct Node *newNode=(struct Node *) malloc(sizeof(struct Node));
    if(newNode==NULL)
        return;
    newNode->data=num;
    newNode->link=NULL;
   
    if(*head==NULL || (*head)->data>=num){
        newNode->link=(*head)->link;
        *head=newNode;
    }
    else{
        struct Node *temp=*head;
        while((temp->link) && (temp->link->data<=num))
            temp=temp->link;
        newNode->link=temp->link;
        temp->link=newNode;
    }
}
