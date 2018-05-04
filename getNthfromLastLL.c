//Return get N index from last

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
int8_t getNthFromLast(struct Node *head,uint8_t n);
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
    printf("\n");
    int8_t temp=getNthFromLast(head,5);
    if(temp==FAIL)
        printf("Index out of bound");
    else
        printf("Data from last:%d",temp);
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

int8_t getNthFromLast(struct Node *head,uint8_t n)
{
    uint8_t count=1;
    struct Node *ref=head;
    struct Node *main_ptr=head;
    if(head==NULL)
        return FAIL;
    else
    {
        while(count<=n){
            if(ref==NULL)
                return FAIL;
            ref=ref->link;
            count++;
        }
    }
    while(ref!=NULL){
        ref=ref->link;
        main_ptr=main_ptr->link;
    }
    return main_ptr->data;
}

