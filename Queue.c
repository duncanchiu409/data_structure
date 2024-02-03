#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct Queue{
    int a[MAX];
    int front;
    int rear;
} Queue;

Queue* root;

void initialQueue(Queue* q){
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue* q){
    if((q->rear + 1) % MAX == q->front){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(Queue* q){
    if(q->front == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(Queue* q, int a){
    if(isFull(q)){
        printf("Queue overflow\n");
        return;
    }
    else if(isEmpty(q)){
        q->front = q->rear = 0;
    }
    else{
        q->rear = (q->rear + 1) % MAX;
        q->a[q->rear] = a;
    }
}

void dequeue(Queue* q, int a){
    if(){
        
    }
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("Empty Queue\n");
    }
    else{
        
    }
}