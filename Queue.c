#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct Queue{
    int a[MAX];
    int front;
    int rear;
} Queue;

void initialQueue(Queue** q){
    *q = malloc(sizeof(Queue));
    (*q)->front = -1;
    (*q)->rear = -1;
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
    }
    else if(isEmpty(q)){
        q->front = q->rear = 0;
        q->a[q->rear] = a;
    }
    else{
        q->rear = (q->rear + 1) % MAX;
        q->a[q->rear] = a;
    }
}

void dequeue(Queue* q, int a){
    
}

void display(Queue* q){
    if(isEmpty(q) == 1){
        printf("Empty Queue\n");
    }
    else{
        printf("Front: %d\n", q->a[q->front]);
        printf("Rear: %d\n", q->a[q->rear]);

        printf("Queue: ");
        int i = q->front;
        while(i != q->rear){
            printf("%d ", q->a[i]);
            i = i + 1 == MAX ? 0 : i + 1;
        }
        printf("%d\n", q->a[q->rear]);
    }
}

int main(){
    Queue** root;
    initialQueue(root);

    //enqueue(root, 1);
    //enqueue(root, 2);

    display(*root);

    return 1;
}