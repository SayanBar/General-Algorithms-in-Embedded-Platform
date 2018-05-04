//Detect and remove Loop in a Linklist

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
int8_t detectLoop(struct Node *head);
void print(struct Node *head);
void removeLoop(struct Node *head,struct Node *loopNode);


int main()
{
    struct Node *head=NULL;
    Push(&head,4);
    Push(&head,10);
    Push(&head,5);
    Push(&head,7);
    Push(&head,19);
    Push(&head,3);
    Push(&head,16);
    Push(&head,23);
    Push(&head,78);
    print(head);
    head->link->link->link->link->link = head->link->link;
    if(detectLoop(head)==SUCCESS)
        printf("\nFound loop and removed\n");
    else    
        printf("\nNo loop\n");
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

int8_t detectLoop(struct Node *head)
{
    struct Node *slow=head,*fast=head;
    while(slow && fast && fast->link)
    {
        slow=slow->link;
        fast=fast->link->link;
        if(slow==fast){
            printf("\nLoop at %d\n",slow->data);
            removeLoop(head,slow);
            return SUCCESS;
        }
    }
    return FAIL;
}

void removeLoop(struct Node *head,struct Node *loopNode)
{
    struct Node *ref1,*ref2;
    ref1=head;
    
    while(1){
        ref2=loopNode;
        while(ref2->link!=loopNode && ref2->link!=ref1)
            ref2=ref2->link;
        if(ref2->link==ref1)
            break;

        ref1=ref1->link;
    }
    ref2->link=NULL;
    
}


