//Array of function pointers enqueued and dequeued in a FIFO

#include <stdio.h>
#define MAX 3
typedef void (*fptr)(int,int);
int rear=-1,front=-1;
fptr Queue[MAX];
//rear=front=-1;

void add(int a,int b){
    int sum=a+b;
    printf("Sum:%d\n",sum);
}

void subtract(int a,int b){
    int diff=a-b;
    printf("Difference:%d\n",diff);
}

void multiply(int a,int b){
    int mul=a*b;
    printf("Multiply:%d\n",mul);
}

int isQueueEmpty(){
    if(front==-1 && rear==-1)
        return 1;
    else
        return 0;
}

int Enqueue(fptr f){
    if(rear==MAX-1){
        printf("Queue Full");
        return -1;
    }
    else if(isQueueEmpty())
        front=rear=0;
    else{
        rear++;
        //printf("Reaar:%d\n",rear);
    }
    Queue[rear]=f;
    return 1;
}

int Dequeue(int a,int b){
    if(isQueueEmpty()){
        printf("Queue Empty\n");
        return -1;
    }
    else if(front==rear){
        Queue[front](a,b);
        front=rear=-1;
    }
    else
        (Queue[front++])(a,b);
        //printf("Element popped:Front=%d\n",front);
    return 1;
}



int main(void) {
	int c=2,d=5,i;
	//fptr fp[3]={add,subtract,multiply};
//  	for(i=0;i<3;i++)
//  	    (fp[i])(c,d);
    Dequeue(c,d);
    Enqueue(add);
    Enqueue(subtract);
    Enqueue(multiply);
    //Dequeue();
    // Queue[0](c,d);
    // Queue[1](c,d);
    // Queue[2](c,d);
  	Dequeue(c,d);
  	Dequeue(c,d);
  	Dequeue(c,d);
  	Dequeue(c,d);
//   	Queue[0](c,d);
//   	Queue[1](c,d);
  	//Dequeue();
// 	(fptr[0])(c,d);
// 	(fptr[1])(c,d);
// 	(fptr[2])(c,d);
	return 0;
}


