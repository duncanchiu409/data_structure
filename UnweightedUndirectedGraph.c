#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100

typedef struct EdgeNode{
    int y;
    EdgeNode* next;
} EdgeNode;

typedef struct Graph{
    EdgeNode* vertices[SIZE];
    int degree[SIZE];
    int nvertices;
    int nedges;
} Graph;

Graph* root;

void initialise_graph(Graph** g){
    *g = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < SIZE; i++){
        (*g)->vertices[i] = NULL;
        (*g)->degree[i] = 0;
    }
    (*g)->nvertices = 0;
    (*g)->nedges = 0;
}

void add_edge(Graph* g, int x, int y){
    g->vertices[x] = (EdgeNode*)malloc(sizeof(EdgeNode));
    g->vertices[x]->y = y;
    g->vertices[x]->next = ;
    g->degree[x]++;
    
    g->nedges++;

    g->vertices[y] = (EdgeNode*)malloc(sizeof(EdgeNode));
    g->vertices[y]->y = x;
    g->vertices[y]->next = NULL;
    g->degree[y]++;
}

void display_graph(Graph* g){
    for(int i = 0; i < SIZE; i++){
        if(g->vertices[i]!=NULL){
            printf("Vertix %d : ", i);
            EdgeNode* tmp = g->vertices[i];
            while(tmp != NULL){
                printf("%d ", tmp->y);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
}

int initialise_search(Graph* g){
        int i;

        for(i=1; i<=g->nvertices; i++){
            processed[i] = discovered[i] = false;
            parent[i] = -1;
        }
};

void breath_first_search(Graph* g){
    bool processed[SIZE+1];
    bool discovered[SIZE+1];
    int parent[SIZE+1];

    
}

int main(){
    initialise_graph(&root);
    add_edge(root, 0, 1);
    display_graph(root);

    return 1;
}