//Find Index of given element and find element at given index
//Insert at end and print the linklist

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

int8_t GetN(struct Node *head, int8_t index);
int8_t Push(struct Node **head_ref,int8_t);
uint8_t GetIndex(struct Node*,int8_t data);
void print(struct Node *head);

int main()
{
    struct Node *head=NULL;
    Push(&head,4);
    Push(&head,10);
    Push(&head,5);
    Push(&head,7);
    Push(&head,19);
    print(head);
    printf("\n");
    printf("Data:%d\n",GetN(head,5));
    printf("Index:%d",GetIndex(head,19));
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

int8_t GetN(struct Node *head,int8_t index)
{
    struct Node *temp=head;
    uint8_t count=1;
    while(temp){
        if(count==index)
            return temp->data;
        temp=temp->link;
        count++;
    }
    return -1;
}

uint8_t GetIndex(struct Node* head,int8_t data)
{
    static count=1;
    if(head==NULL)
        return 0;
    if(head->data==data)
        return count;
    count++;
    return GetIndex(head->link,data);
}
