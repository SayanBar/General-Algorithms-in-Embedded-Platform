//Delete at Head End & Position in a DLL

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


int8_t PushAtEnd(NodeDLL **head_ref,int8_t);
int8_t PushAtHead(NodeDLL **head_ref,int8_t);
int8_t PushAtN(NodeDLL **head_ref,int8_t,uint8_t);
int8_t DeleteAtHead(NodeDLL **head_ref);
int8_t DeleteAtN(NodeDLL **head_ref, uint8_t pos);
int8_t DeleteAtEnd(NodeDLL **head_ref);

NodeDLL * getNode(int8_t);
void print(NodeDLL *head);

void ReverseDLL(NodeDLL **head_ref);


int main()
{
    NodeDLL *head=NULL;
    PushAtHead(&head,-4);
    PushAtHead(&head,10);
    PushAtEnd(&head,15);
    PushAtN(&head,29,2);
    PushAtEnd(&head,14);
    PushAtEnd(&head,19);
    PushAtHead(&head,-2);
    PushAtN(&head,-8,4);
    PushAtEnd(&head,6);
    print(head);
    DeleteAtEnd(&head);
    DeleteAtHead(&head);
    DeleteAtN(&head,7);
    printf("\n");
    print(head);
    return 0;
}

int8_t PushAtEnd(NodeDLL **head_ref,int8_t data)
{
    NodeDLL *newNode=getNode(data);
    if(!newNode)
        return FAIL;
    if(!(*head_ref))
        *head_ref=newNode;
    else{
        NodeDLL *temp=*head_ref;
        while(temp->next)
          temp=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
    }    
    return SUCCESS;
}


int8_t PushAtHead(NodeDLL **head_ref,int8_t data)
{
    NodeDLL *newNode=getNode(data);
    if(!newNode)
        return FAIL;
    if(!(*head_ref))
        *head_ref=newNode;
    else{
        newNode->next=*head_ref;
        newNode->next->prev=newNode;
        *head_ref=newNode;
    }
    return SUCCESS;
}


int8_t PushAtN(NodeDLL **head_ref,int8_t data,uint8_t pos)
{
    NodeDLL *newNode=getNode(data);
    if(!newNode)
        return FAIL;
    if(pos==1 || !*head_ref){
        newNode->next=*head_ref;
        newNode->next->prev=newNode;
        *head_ref=newNode;
    }
    else{
        uint8_t i=0;
        NodeDLL *temp=*head_ref;
        while(i<pos-2){
            temp=temp->next;
            i++;
            if(!temp->next && i!=(pos-2))
                return FAIL;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
        newNode->next->prev=newNode;
    }
    return SUCCESS;
        
}

int8_t DeleteAtHead(NodeDLL **head_ref)
{
    if(!(*head_ref))
        return FAIL;
    NodeDLL *temp=*head_ref;
    *head_ref=temp->next;
    (*head_ref)->prev=NULL;
    free(temp);
    temp=NULL;
    return SUCCESS;
    
}


int8_t DeleteAtEnd(NodeDLL **head_ref)
{
    if(!(*head_ref))
        return FAIL;
    NodeDLL * temp=*head_ref;
    if(!temp->next){
        *head_ref=NULL;
        free(temp);
    }
    else{
        while(temp->next)
            temp=temp->next;
        temp->prev->next=NULL;
        free(temp);
        temp=NULL;
    }
    return SUCCESS;
}


int8_t DeleteAtN(NodeDLL **head_ref, uint8_t pos)
{
    if(!(*head_ref))
        return FAIL;
    NodeDLL *temp=*head_ref;
    if(pos==1){
        if(temp->next)
            temp->next->prev=NULL;
        *head_ref=temp->next;
        free(temp); temp=NULL;
    }
    else{
        uint8_t i=0;
        while(i<pos-2){
            temp=temp->next;i++;
            if(!(temp->next) && i!=pos-2)
                return FAIL;
        }
        NodeDLL *delNode=temp->next;
        temp->next=delNode->next;
        if(delNode->next)
            delNode->next->prev=temp;
        free(delNode);
        delNode=NULL;
    }
    return SUCCESS;
}



NodeDLL * getNode(int8_t data)
{
    NodeDLL * newNode=(NodeDLL *)malloc(sizeof(NodeDLL));
    if(!newNode)
        return NULL;
    newNode->data=data;
    newNode->next=newNode->prev=NULL;
    return newNode;
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



