//Queue Implementation with Array

#include <stdio.h>
#include <inttypes.h>
#include<limits.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define FAIL 0
#define SUCCESS 1
#define MAXBUFFER 5



uint8_t Enqueue(int8_t arr[],int8_t data);
void Dequeue(int8_t arr[]);
uint8_t isEmpty();

int8_t front=-1, rear=-1;
int main()
{
    int8_t arr[100];
    Enqueue(arr,-5);
    Dequeue(arr);
    Enqueue(arr,7);
    Enqueue(arr,0);
    Enqueue(arr,9);
    Enqueue(arr,-80);
    Dequeue(arr);
    Dequeue(arr);
    Dequeue(arr);
   
    
    return 0;
}


uint8_t Enqueue(int8_t arr[],int8_t data)
{
    if(rear==MAXBUFFER-1){
        printf("Queue Full\n");
        return FAIL;
    }
    else if(isEmpty())
        front=rear=0;
    else
        rear++;
    printf("\n%d Enqueued\n",data);
    arr[rear]=data;
    return SUCCESS;
}


void Dequeue(int8_t arr[])
{
    if(isEmpty()){
        printf("Buffer Underflow");
    }
    else if(front==rear){
        printf("\n%d Dequeued\n ",arr[front]);
        front=rear=-1;
    }
    else
        printf("\n%d Dequeued\n ",arr[front++]);
    
      
}

uint8_t isEmpty()
{
    if(front==-1 && rear==-1)
        return SUCCESS;
    else 
        return FAIL;
}


