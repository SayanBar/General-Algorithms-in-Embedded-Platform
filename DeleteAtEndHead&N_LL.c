//Insert Node at End,Head and position and Delete at Head, End & position

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL -1
#define SUCCESS 1
#define INT_BITS 16
 
typedef struct Node{
    int8_t data;
    struct Node* next;
}Node;

int8_t PushAtHead(Node **head,int8_t data);
int8_t PushAtEnd(Node **head_ref,int8_t);
int8_t PushAtN(Node **head,int8_t data, uint8_t pos);
int8_t DeleteAtN(Node **head_ref,uint8_t pos);
int8_t DeleteAtHead(Node **head_ref);
int8_t DeleteAtEnd(Node **head_ref);
void print(Node *head);

int main()
{
    Node *head=NULL;
    PushAtEnd(&head,4);
    PushAtEnd(&head,10);
    PushAtHead(&head,5);
    PushAtHead(&head,7);
    DeleteAtEnd(&head);
    PushAtEnd(&head,34);
    if(PushAtN(&head,19,5)==FAIL)
        printf("Fail\n");
    DeleteAtHead(&head);
    PushAtEnd(&head,2);
    
    print(head);
    
   
    return 0;
}

int8_t PushAtEnd(Node **head_ref,int8_t data)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    if(!newNode)
        return FAIL;
    newNode->data=data;
    newNode->next=NULL;
    if(*head_ref==NULL)
        *head_ref=newNode;
    else{
        Node *temp=*head_ref;
        while(temp->next!=NULL)
          temp=temp->next;
        temp->next=newNode;
    }    
    return SUCCESS;
}

int8_t PushAtHead(Node **head,int8_t data)
{
    Node *newNode=(Node *)malloc(sizeof(Node));
    if(!newNode)
        return FAIL;
    newNode->data=data;
    newNode->next=NULL;
    if(!(*head))
        *head=newNode;
    else{
        newNode->next=*head;
        *head=newNode;
    }
    return SUCCESS;    
}

int8_t PushAtN(Node **head,int8_t data, uint8_t pos)
{
    Node *newNode=(Node *)malloc(sizeof(Node));
    if(!newNode)
        return FAIL;
    newNode->data=data;
    newNode->next=NULL;
    if((pos==1)||!(*head)){
        newNode->next=*head;
        *head=newNode;
    }
    else{
        uint8_t i=0;
        Node * temp=*head;
        while(i<pos-2){
            temp=temp->next;
            i++;
            if(temp->next==NULL && i!=(pos-2)){
                printf("i:%d",i);
                return FAIL;}
        }
        printf("i:%d",i);
        newNode->next=temp->next;
        temp->next=newNode;
    }
    return SUCCESS;
}

int8_t DeleteAtHead(Node **head_ref)
{
    if(!(*head_ref))
        return FAIL;
    Node *temp=*head_ref;
    *head_ref=temp->next;
    free(temp);
    temp=NULL;
    return SUCCESS;
}

int8_t DeleteAtEnd(Node **head_ref)
{
    if(!(*head_ref))
        return FAIL;
    Node *temp=*head_ref;
    if(!temp->next){
        *head_ref=NULL;
        free(temp); temp=NULL;
    }
    else{
        while(temp->next->next)
            temp=temp->next;
        Node *temp1=temp->next;
        temp->next=NULL;
        free(temp1); temp1=NULL;
    }
    return SUCCESS;
}

int8_t DeleteAtN(Node **head_ref,uint8_t pos)
{
    if(!(*head_ref))
        return FAIL;
    Node *temp=*head_ref;
    if(pos==1){
        *head_ref=NULL;
        free(temp); temp=NULL;
    }
    else{
        uint8_t i=0;
        while(i<pos-2){
            temp=temp->next;
            i++;
            if(!temp->next->next && i!=pos-2)
                return FAIL;
        }
        Node *temp1=temp->next;
        temp->next=temp1->next;
        free(temp1);
        temp1=NULL;    
    }
    return SUCCESS;
    
}

void print(Node *head)
{
    if(!head)
        return;
    Node *temp=head;
    printf("Head:%d\n",head->data);
    while(temp){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}


