#include <stdio.h>
#include <stdbool.h>
#include <Queue.c>
#include <UnweightedUndirectedGraph.c>
#define SIZE 100

bool processed[SIZE+1];
bool discovered[SIZE+1];
int parent[SIZE+1];

void initialise_search(){
    for(int i = 0; i < SIZE+1; i++){
        processed[i] = false;
        discovered[i] = false;
        parent[i] = -1;
    }
}

void process_vertex_early(int v){

}

void process_edge(int v, int y){

}

void find_shortest_paths(int start, int end, int parent[]){
    if(start == end || end == -1){
        printf("\n%d", start);
    }
    else{
        find_shortest_paths(start, parent[end], parent);
        printf(" %d", end);
    }
}

void breath_first_search(Graph* g, int start){
    Queue* q;
    int v;
    int y;
    EdgeNode* p;

    initialQueue(&q);
    enqueue(q, start);
    discovered[start] = true;

    while(isEmpty(q) == 0){
        v = dequeue(q);
        process_vertex_early(v);
        p = g->vertices[v];
        while(p != NULL){
            y = p->y;
            if(processed[y] == false || g->directed){
                process_edge(v, y); 
            }
            if(discovered[y] == false){
                enqueue(q, y);
                discovered[y] = true;
                parent[y] = v;
            }
            p = p->next;
        }
        process_vertex_late(v);
    }
}