#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

typedef struct {
    int items[SIZE];
    int front;
    int rear;
} Queue;

Queue* root;

void initialize_queue(Queue** q){
    *q = malloc(sizeof(Queue));
    
    for(int i = 0; i < SIZE; i++){
        (*q)->items[i] = -1;
    }
    (*q)->front = -1;
    (*q)->rear = -1;
}

bool isFull(Queue* q){
    if(q->front == -1 || q->rear == -1){
        return false;
    }

    if((q->rear + 1) % SIZE == q->front){
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty(Queue* q){
    if(q->front == -1 || q->rear == -1){
        return true;
    }
    return false;
}

void enqueue(Queue* q, int item){
    if(isFull(q)){
        printf("Error: Queue is full!\n");
    }
    else if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
        q->items[0] = item;
    }
    else{
        q->rear = (q->rear + 1) % SIZE;
        q->items[q->rear] = item;
    }
}

void dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Error: Queue is empty!\n");
    }
    else if(q->front == q->rear){
        q->items[q->front] = -1;
        q->front = -1;
        q->rear = -1;
    }
    else{
        q->items[q->front] = -1;
        q->front = (q->front + 1) % SIZE;
    }
}

void display_queue(Queue* q){
    printf("Queue: ");
    for(int i = 0; i < SIZE; i++){
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main (int argc, char** argv){
    initialize_queue(&root);
    enqueue(root, 1);
    enqueue(root, 2);
    enqueue(root, 3);
    enqueue(root, 4);
    enqueue(root, 5);
    dequeue(root);
    enqueue(root, 6);
    dequeue(root);
    enqueue(root, 7);
    dequeue(root);
    enqueue(root, 8);
    dequeue(root);

    display_queue(root);
    return 0;
}